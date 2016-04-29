/* listaord.c
 * Implementação das operações realizadas sobre o TAD lista ordenada representado de forma encadeada */

#include "listaord.h"
#include <stdio.h>
#include <stdlib.h>

void lst_init(lst_ptr * l)
{
    *l = NULL;
}

int lst_tamanho(lst_ptr l)
{
    int tam = 0;
    while (l != NULL) {
        tam++;
        l = l->prox;
    }
    return tam;
}

void lst_inserir(lst_ptr * l, lst_info x)
{
    lst_ptr n;
    if ((n = (lst_ptr) malloc(sizeof(struct lst_no))) == NULL) {
        fprintf(stderr, "Lista ordenada cheia!\n");
        exit(1);
    }
    n->dado = x;
    if (*l == NULL || x < (*l)->dado) { // 1º e 2º casos
        n->prox = *l;
        *l = n;
    }
    else { // 3º e 4º casos
        lst_ptr p = *l;
        while (p->prox != NULL && p->prox->dado < x) {
            p = p->prox;
        }
        n->prox = p->prox;
        p->prox = n;
    }
}

bool lst_remover(lst_ptr * l, lst_info x)
{
    if (*l == NULL || x < (*l)->dado) {
        return false;
    }
    else {
        lst_ptr p = *l;
        if (x == (*l)->dado) {
            *l = (*l)->prox;
            free(p);
            return true;
        }
        else {
            while (p->prox != NULL && p->prox->dado < x) {
                p = p->prox;
            }
            if (p->prox != NULL && p->prox->dado == x) {
                lst_ptr n = p->prox;
                p->prox = n->prox;
                free(n);
                return true;
            }
            return false;
        }
    }
}

lst_ptr lst_procurar(lst_ptr l , lst_info x)
{
    while (l != NULL && l->dado != x) {
        l = l->prox;
    }
    return l;
}

void lst_imprimir(lst_ptr l)
{
    printf("[ ");
    while (l != NULL) {
        printf("%d,", l->dado);
        l = l->prox;
    }
    printf("\b ]\n");
}

void lst_kill(lst_ptr * l)
{
    lst_ptr n;
    while (*l != NULL) {
        n = *l;
        *l = n->prox;
        free(n);
    }
}
