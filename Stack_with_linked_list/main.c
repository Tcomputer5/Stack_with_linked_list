#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack_generique.h"

#define MAX_LIGNE 64
/**
 * The current program use exactly the previous code spirit's
 * It uses stack (node which are linked_list ADT in order to implement it)
 * */


int estBienParenthese(const char *);

// print the enterred string
void sanitize(char *s){
    size_t len = strlen(s);
    if(*(s + len - 1)=='\n'){
        *(s + sizeof(char) * (len - 1)) = '\0';
    }
}

// Une chaine constitue des caractères (){}[] et dit si oui ou non la chaine est bien parenthèsée
// les autres caractères seront simplement ignorés
int main()
{
    printf("Entrer une chaine de caractere :");

    char *chaine = (char *) malloc(sizeof(char) * MAX_LIGNE);

    fgets(chaine, MAX_LIGNE, stdin);
    sanitize(chaine);
    printf("\n");
    if(estBienParenthese(chaine)){
        printf("\nLa chaine %s est bien parenthesee \n", chaine);
    }else{
        printf("\nLa chaine %s n'est pas bien parenthesee \n",chaine);
    }
    free(chaine);
    return 0;
}

/**
 * This function check a caracter before loading it in the stack  */
int estBienParenthese(const char *chaine){
    int result = 1;
    char tmp;
    Stack s = createStack();
    int i = 0;
    while((*(chaine + i) != '\0') && result){
        char c = *(chaine + i);
        printf("%c", c);
        switch(c){
            case '(':
                push(&s, c);
                break;
            case '{':
                push(&s, c);
                break;
            case '[':
                push(&s, c);
                break;
            case '}':
                result = result && (top(s, &tmp) > 0);
                result = result && (tmp == '{');
                pop(&s);
                break;
            case ')':
                result = result && (top(s, &tmp) > 0);
                result = result && (tmp == '(');
                pop(&s);
                break;
            case ']':
                result = result && (top(s, &tmp) > 0);
                result = result && (tmp == '[');
                pop(&s);
                break;
        }
        i++;
    }
    result = result && is_empty(s);
    destroy(&s);
    return result;
}                                                                                                                                                                     