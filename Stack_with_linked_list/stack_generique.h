//
// Created by FLORIAN on 2/5/2021.
//

#ifndef STACK_WITH_LINKED_LIST_STACK_GENERIQUE_H
#define STACK_WITH_LINKED_LIST_STACK_GENERIQUE_H

typedef struct Stack_t *Stack;

//Initialise a stack to NULL pointer
Stack createStack();

//check if a stack is empty
int is_empty(Stack stack);

//insert a new node and append it to a non or an existing stack
int push(Stack * stack, char value);

//remove the higest node of the stack
int pop(Stack * stack);

//get the value of the first data in stack
int top(Stack stack, char *res);

//destroy a created stack after finishing with it
void destroy(Stack * stack);

//display the structure of a stack if needs
void display(Stack stack);



#endif //STACK_WITH_LINKED_LIST_STACK_GENERIQUE_H
