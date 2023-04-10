#include<stdio.h>
#include<stdlib.h>
#include "lista.h"

//Funcao para inicializar lista
Lista* inicializa(){
	return NULL;
}

//Funcao para construir uma lista a partir de um vetor
Lista* constroi (int n, int* v){
    Lista *L = inicializa();
    int i;
    if (v == NULL){
        return L;
    }
    //Percorre o vetor e vai inserindo na lista os elementos
    for(i=0; i < n; i++){
        L = inserirFim(L, v[i]);
    }
    return L;
}

Lista* concatena(Lista* l1, Lista* l2){
	Lista *p = l1;
	if(l1==NULL){
		return l2;
	}
	while(p->prox!=NULL){
		p = p->prox;
	}
	p->prox = l2;
	return l1;
}

//Ele recebe uma lista e um numero inteiro, se ele encontrar aquele valor na lista ele separa a lista em 2 partes
//fazendo a primeira parte nao apontar mais para nada e retorna a segunda parte
Lista* separa(Lista *l, int n){
	Lista *p = l;
	Lista *nova;
	while(p!=NULL && p->info!=n){
		p = p->prox;
	}

	if (p==NULL){
		printf("Numero nao encontrado");
		return l;
	}
	else{
        nova = p->prox;
        p->prox = NULL;
        return nova;
	}

}

Lista* inserirComeco(Lista *L, int num){
	Lista *novo;
	novo = (Lista*) malloc(sizeof(Lista));
	novo->info = num;
	novo->prox = L;
	return(novo);
}

Lista *inserirFim(Lista *L, int v){
	Lista *novo, *aux=L;
	novo = (Lista*)malloc(sizeof(Lista));
	novo->info = v;
	novo->prox = NULL;

	if (L==NULL)
		return novo;
	else{
		while(aux->prox!=NULL){
			aux = aux->prox;
		}
		aux->prox = novo;
		return L;
	}
}

void imprimir(Lista* L){
	Lista* p=L;

	while (p!=NULL){
		printf("%d\n",p->info);
		p = p->prox;
	}
}

Lista* retira(Lista* L, int num){
	Lista *ant=NULL;
	Lista *p = L;

	while(p!=NULL && p->info!=num){
		ant = p;
		p = p->prox;
	}

	if (p==NULL){
		printf("Nao encontrou o elemento");
		return L;
	}

	if (ant==NULL)
		L = p->prox;
	else{
		ant->prox=p->prox;
	}

	free(p);

	return L;
}

Lista* libera (Lista* L)
//Ele libera todos, a partir da segunda posicao e no final libera a primeira posição
{
	Lista* p = L;
	while (p != NULL) {
		Lista* t = p->prox;
		free(p);
		p = t;
	}
	return NULL;
}


