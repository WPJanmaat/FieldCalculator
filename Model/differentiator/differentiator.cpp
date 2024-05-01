#include <iostream>
struct ValueAndPartial { float value, partial; };
struct Variable;
struct Expression {
   virtual ValueAndPartial evaluateAndDerive(Variable *variable) = 0;
};
struct Variable: public Expression {
   float value;
   Variable(float value): value(value) {}
   ValueAndPartial evaluateAndDerive(Variable *variable) {
      float partial = (this == variable) ? 1.0f : 0.0f;
      return {value, partial};
   }
};
struct Plus: public Expression {
   Expression *a, *b;
   Plus(Expression *a, Expression *b): a(a), b(b) {}
   ValueAndPartial evaluateAndDerive(Variable *variable) {
      auto [valueA, partialA] = a->evaluateAndDerive(variable);
      auto [valueB, partialB] = b->evaluateAndDerive(variable);
      return {valueA + valueB, partialA + partialB};
   }
};
struct Multiply: public Expression {
   Expression *a, *b;
   Multiply(Expression *a, Expression *b): a(a), b(b) {}
   ValueAndPartial evaluateAndDerive(Variable *variable) {
      auto [valueA, partialA] = a->evaluateAndDerive(variable);
      auto [valueB, partialB] = b->evaluateAndDerive(variable);
      return {valueA * valueB, valueB * partialA + valueA * partialB};
   }
};
int main () {
   // Example: Finding the partials of z = x * (x + y) + y * y at (x, y) = (2, 3)
   Variable x(2), y(3);
   Plus p1(&x, &y); Multiply m1(&x, &p1); Multiply m2(&y, &y); Plus z(&m1, &m2);
   float xPartial = z.evaluateAndDerive(&x).partial;
   float yPartial = z.evaluateAndDerive(&y).partial;
   std::cout << "∂z/∂x = " << xPartial << ", "
             << "∂z/∂y = " << yPartial << std::endl;
   // Output: ∂z/∂x = 7, ∂z/∂y = 8
   return 0;
}