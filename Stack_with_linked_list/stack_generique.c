//
// Created by FLORIAN on 2/5/2021.
//

#include "stack_generique.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Stack createStack(){
    Stack stack = NULL;
    return stack;
};

struct Stack_t{
    char data;
    struct Stack_t* next;
};

int push(Stack * stack, char value){
//    check if the stack is empty
    if(stack != NULL){
        Stack new_stack = (Stack)malloc(sizeof(struct Stack_t));
        // check if the node is empty
        if(new_stack ==  NULL){
            printf("Stack overflow\n");
//            getchar();
            exit(0);
        }
        new_stack->data = value;
//    link the old list off the new node
        new_stack->next = *stack;
//    move the head pointer on the new node
        *stack = new_stack;
        return 1;
    } else{
        return -1;
    }
}

int pop(Stack * stack){
    Stack top;

//    if stack is empty then error
    if(is_empty(*stack)){
        return -1;
    } else{
        top = *stack;
        *stack = top->next;
        free(top);
        return 1;
    }
}

int is_empty(Stack stack){
    return stack == NULL;
}

int top(Stack stack, char *res){
    if(is_empty(stack)){
        return -1;
    } else{
        *res = stack->data;
//        printf("%c",res);
        return 1;
    }
}


void destroy(Stack * stack){
    while(!is_empty(*stack)){
        pop(stack);
    }
}
void display(Stack stack){
    while(!is_empty(stack)){
        printf("-> %c", stack->data);
        stack = stack->next;
    }
    printf("\n");
}



