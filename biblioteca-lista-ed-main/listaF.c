#include<stdio.h>
#include<stdlib.h>
#include "listaF.h"
#include "lista.h"

//Funcao para retirar um numero n de elementos
Listaf* retira_prefixo (Listaf *L1, int n){
    Listaf *L2 = inicializa();
    Listaf *p = L1;
    int cont=0;
    //Verifica se a lista é nula
    if(p==NULL){
        printf("Lista nula");
        return 0;
    }
    //Enquanto o nó da lista nao for nulo e o numero de execucoes for menor que o numero pedido
    while (p != NULL && cont<n) {
        L2 = p->prox; // ele salva o proximo elemento de p em L2
        p = L2; //e faz p receber o proximo elemento dele mesmo
        cont++;
    }
    if(p==NULL && cont==n){
        printf("numero de elementos para retirar maior que numero de elementos da lista");
        return 0;
	}
    return L2;
}

Listaf* inserirComecof(Listaf *L, float num){
	Listaf *novo;
	novo = (Listaf*) malloc(sizeof(Listaf));
	novo->info = num;
	novo->prox = L;
	return(novo);
}

void imprimirf(Listaf* L){
	Listaf *p=L;

	while (p!=NULL){
		printf("%.2f\n",p->info);
		p = p->prox;
	}
}
