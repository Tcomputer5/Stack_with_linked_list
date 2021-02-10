//
// Created by FLORIAN on 2/10/2021.
//
// This file contains the generic implementation of the stack

// available types should be insert in this enumeration
typedef enum {INT, FLOAT, STACK} DataType;

//the data type of the struct element should get a type according to the entered type
struct Stack {
    void *data;
    DataType t;
    struct Stack* next;
};

// and inside our main function the entered value will not be just a caracter
