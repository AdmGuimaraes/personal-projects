/* pilhaenc.h
 * Definição do TAD pilha representado de forma encadeada e protótipo
 * de suas operações */

#ifndef _PILHAENC_H
#define _PILHAENC_H

#include <stdbool.h>

typedef int stack_info;
typedef struct stack_no * stack_ptr;
struct stack_no {
    stack_info dado;
    stack_ptr prox;
};

void stack_init(stack_ptr *);

bool stack_isempty(stack_ptr);

void push(stack_ptr *, stack_info);

stack_info pop(stack_ptr *);

stack_info top(stack_ptr);

void stack_print(stack_ptr);

#endif // _PILHAENC_H
