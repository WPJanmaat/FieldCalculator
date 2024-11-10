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


MyTest : Vector.o Field.o Particle.o FieldParser.o ParticlePlacer.o Simulator.o Interpolate.o Results.o ResultWriter.o FieldModulate.o Tests.o TestMain.o
	$(CC) -O3 -Wall -pedantic -o ./../bin/ParseTest.exe $^ 

Vector.o : Vector.c Vector.h
	$(CC) -c -Wall -pedantic $^ 

Field.o : Field.c Field.h 
	$(CC) -c -Wall -pedantic $^

Particle.o : Particle.h Particle.c
	$(CC) -c -Wall -pedantic $^

FieldParser.o : FieldParser.c FieldParser.h FieldProperties.h 
	$(CC) -c -Wall -pedantic $^

ParticlePlacer.o : ParticlePlacer.c ParticlePlacer.h
	$(CC) -c -Wall -pedantic $^

Simulator.o : Simulator.c Simulator.h
	$(CC) -c -Wall -pedantic $^

Interpolate.o : Interpolate.c Interpolate.h
	$(CC) -c -Wall -pedantic $^

ResultWriter.o : ResultWriter.c ResultWriter.h
	$(CC) -c -Wall -pedantic $^

Results.o : Results.c Results.h
	$(CC) -c -Wall -pedantic $^

FieldModulate.o : FieldModulate.c FieldModulate.h
	$(CC) -c -Wall -pedantic $^

Tests.o : tests.c tests.h
	$(CC) -c -Wall -pedantic $^

TestMain.o : testMain.c
	$(CC) -c -Wall -pedantic $^


