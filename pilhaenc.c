/* pilhaenc.c
 * Implementação realizadas sobre o TAD pilha representado de forma encadeada */

#include "pilhaenc.h"
#include <stdio.h>
#include <stdlib.h>

void stack_init(stack_ptr * topo)
{
    *topo = NULL;
}

bool stack_isempty(stack_ptr topo)
{
    return (topo == NULL);
}

void push(stack_ptr * topo, stack_info x)
{
    stack_ptr n;
    if ((n = (stack_ptr) malloc(sizeof(struct stack_no))) == NULL) {
        fprintf(stderr, "Pilha cheia!\n");
        exit(1);
    }
    n->dado = x;
    n->prox = *topo;
    *topo = n;
}

stack_info pop(stack_ptr * topo)
{
    if (!stack_isempty(*topo)) {
        stack_info x = (*topo)->dado;
        stack_ptr n = *topo;
        *topo = (*topo)->prox;
        free(n);
        return x;
    }
    else {
        fprintf(stderr, "Pilha vazia!\n");
        exit(1);
    }
}

stack_info top(stack_ptr topo)
{
    if (!stack_isempty(topo)) {
        return topo->dado;
    }
     else {
        fprintf(stderr, "Pilha vazia!\n");
        exit(1);
    }
}

void stack_print(stack_ptr topo)
{
    printf("[ ");
    while (topo != NULL) {
        printf("%d,", topo->dado);
        topo = topo->prox;
    }
    printf("\b ]\n");
}

