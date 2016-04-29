/* listaord.h
 * Defini��o do TAD lista ordenada representado de forma encadeada e prot�tipo de suas opera�oes */

#ifndef _LISTAORD_H
#define _LISTAORD_H

#include <stdbool.h>

typedef int lst_info;
typedef struct lst_no * lst_ptr;
struct lst_no {
    lst_info dado;
    lst_ptr prox;
};

/* inicializa a lista */
void lst_init(lst_ptr *);

/* insere um novo n� na lista ordenada */
void lst_inserir(lst_ptr *, lst_info);

/* remove o n� que cont�m um o valor da lista */
bool lst_remover(lst_ptr *, lst_info);

/* devolve o tamanho da lista */
int lst_tamanho(lst_ptr);

/* devolve o ponteiro para o n� que cont�m o valor procurado ou NULL */
lst_ptr lst_procurar(lst_ptr, lst_info);

/* imprime a lista */
void lst_imprimir(lst_ptr);

/* destroi a lista */
void lst_kill(lst_ptr *);

#endif // _LISTAORD_H
