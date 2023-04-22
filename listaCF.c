#include<stdio.h>
#include<stdlib.h>
#include "listaC.h"
#include "listaCF.h"

ListaCF* inicializaCF(){
	return NULL;
}

ListaCF *inserirIF(ListaCF *l, int v){
	ListaCF *novo, *p=l;
	novo = (ListaCF*)malloc(sizeof(ListaCF));
	novo->info = v;
	if(l!=NULL)
		novo->prox = l;
	else{
		novo->prox = novo;
		return novo;
	}
	while(p->prox!=l){
		p = p->prox;
	}
	p->prox = novo;

	return novo;
}

void imprimirCF(ListaCF* L){
	ListaCF *p=L;
	if (p!=NULL){
        do {
            printf("[%.2f] -> ",p->info);
            p = p->prox;
        } while(p!= L);
	}
	else{
        printf("\nLISTA VAZIA!!");
	}
    printf("\n");
}

//Funcao para retirar um numero n de elementos
ListaCF* retira_prefixoC (ListaCF *L1, int n){
    ListaCF *p = L1, *retorno = inicializaCF();
    int cont=0;
    //Verifica se a lista é nula
    if(p==NULL){
        printf("Lista nula");
        return NULL;
    }else if(n>=1){
        do {
            p = p->prox;
            cont++;
        } while(p->prox != L1 && cont<n);
    } else{
        printf("N menor que 1, funcao nao executada\n");
        return L1;
    }

    if(p->prox==L1 && cont<=n){
        printf("numero de elementos para retirar maior/igual que numero de elementos da lista");
        return NULL;
	}
    retorno = p;
    do {
        p = p->prox;
    } while(p->prox!=L1);
    p->prox = retorno;
    return retorno;
}
