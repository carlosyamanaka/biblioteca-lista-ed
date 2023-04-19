#include<stdio.h>
#include<stdlib.h>
#include "listaDEF.h"

void imprime_recDEF(Lista2F* l){
	if (l==NULL)
		return;
	printf("%x - [%x | %.2f | %x] ->\n", l, l->ant, l->info, l->prox);
	imprime_recDEF(l->prox);
}

Lista2F* inserirIDEF(Lista2F *l, float v){
	Lista2F *novo;
	novo = (Lista2F*)malloc(sizeof(Lista2F));
	novo->info = v;
	novo->ant = NULL;
	novo->prox = l;
	if(l!=NULL)
		l->ant = novo;
	return novo;
}

Lista2F* retira_prefixoDE (Lista2F *L1, int n){
    Lista2F *p = L1;
    int cont=0;
    //Verifica se a lista é nula
    if(p==NULL){
        printf("Lista nula");
        return 0;
    }
    //Enquanto o nó da lista nao for nulo e o numero de execucoes for menor que o numero pedido
    while (p != NULL && cont<n) {
        p = p->prox;
        cont++;
    }
    if(p==NULL && cont==n){
        printf("numero de elementos para retirar maior/igual numero de elementos da lista");
        return  NULL;
	} else{
	    p->ant = NULL;
        free(L1);
        return p;
	}
}
