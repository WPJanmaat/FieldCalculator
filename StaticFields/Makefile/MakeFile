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


MyTest : Vector.o Field.o FieldParser.o Tests.o TestMain.o
	gcc -O2 -o ./../bin/ParseTest.exe $^ 

Vector.o : Vector.c Vector.h
	$(CC) -c $^ 

Field.o : Field.c Field.h 
	$(CC) -c $^

Parse.o : FieldParser.c FieldParser.h FieldProperties.h 
	$(CC) -c $^

Tests.o : tests.c tests.h
	$(CC) -c $^

TestMain.o : testMain.c
	$(CC) -c $^

