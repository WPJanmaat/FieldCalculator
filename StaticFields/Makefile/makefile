#T.T

#Filepath possibilities.
vpath %.c ./../src/Model
vpath %.c ./../src/Control
vpath %.c ./../Tests 
vpath %.h ./../headers/Model
vpath %.h ./../headers/Control
vpath %.h ./../Tests
vpath %.c ./../

vpath %.o ./../obj

#Compiler specifications
#CC := gcc
CC := x86_64-w64-mingw32-gcc

OBJPATH = .\..\obj


MyTest : Vector.o Field.o Particle.o FieldParser.o ParticlePlacer.o Simulator.o Interpolate.o Results.o FieldModulate.o Tests.o TestMain.o
	gcc -O2 -o ./../bin/ParseTest.exe $^ 

Vector.o : Vector.c Vector.h
	$(CC) -c $^ 

Field.o : Field.c Field.h 
	$(CC) -c $^

Particle.o : Particle.h Particle.c
	$(CC) -c $^

FieldParser.o : FieldParser.c FieldParser.h FieldProperties.h 
	$(CC) -c $^

ParticlePlacer.o : ParticlePlacer.c ParticlePlacer.h
	$(CC) -c $^

Simulator.o : Simulator.c Simulator.h
	$(CC) -c $^

Interpolate.o : Interpolate.c Interpolate.h
	$(CC) -c $^

Results.o : Results.c Results.h
	$(CC) -c $^

FieldModulate.o : FieldModulate.c FieldModulate.h
	$(CC) -c $^

Tests.o : tests.c tests.h
	$(CC) -c $^

TestMain.o : testMain.c
	$(CC) -c $^

