#include<stdio.h>
#include<stdlib.h>
#include "listaDE.h"

Lista2* inicializaDE(){
	return NULL;
}

Lista2* inserirIDE(Lista2 *l, int v){
	Lista2 *novo;
	novo = (Lista2*)malloc(sizeof(Lista2));
	novo->info = v;
	novo->ant = NULL;
	novo->prox = l;
	if(l!=NULL)
		l->ant = novo;
	return novo;
}

void imprime_recDE(Lista2* l)
{
	if (l==NULL)
		return;
	printf("%x - [%x | %d | %x] ->\n", l, l->ant, l->info, l->prox);
	imprime_recDE(l->prox);
}

Lista2* inserirFDE(Lista2 *l, int v){
	Lista2 *novo, *p=l;
	novo = (Lista2*)malloc(sizeof(Lista2));
	novo->info = v;
	novo->prox = NULL;
	if(l==NULL){
		novo->ant = NULL;
		return novo;
	}
	else{
		while(p->prox!=NULL)
			p = p->prox;

		p->prox = novo;
		novo->ant = p;
		return l;
	}
}

Lista2* buscarDE(Lista2 *l, int v){
	Lista2 *p = l;

	while(p!=NULL && p->info!=v)
		p = p->prox;

	if(p==NULL)
		return NULL;
	else
		return p;
}

Lista2* excluirDE(Lista2 *l, int v){
	Lista2 *p, *aux;
	p = buscarDE(l,v);

	if(p==NULL){
		printf("\n\nO valor %d nao foi encontrado para exclusao!", v);
		return l;
	}
	else{
		if(p==l){
			if(p->prox!=NULL){
				p->prox->ant = NULL;
				aux = p->prox;
				return aux;
			}
			else{
				return NULL;
			}
			free(p);
		}
		else{
			p->ant->prox = p->prox;
			if(p->prox!=NULL)
				p->prox->ant = p->ant;
			return l;
		}
	}
}

//Ele recebe uma lista e um numero inteiro, se ele encontrar aquele valor na lista ele separa a lista em 2 partes
//fazendo a primeira parte nao apontar mais para nada e retorna a segunda parte
Lista2* separaDE(Lista2 *l, int n){
	Lista2 *p = l;
	Lista2 *nova;
	while(p!=NULL && p->info!=n){
		p = p->prox;
	}

	if (p==NULL){
		printf("Numero nao encontrado\n");
		return 0;
	} else{
	    if(p->prox == NULL){
            printf("Nao eh possivel separar, o numero encontrado eh o ultimo da lista\n");
            return 0;
	    }
        nova = p->prox;
        nova->ant = NULL;
        p->prox = NULL;
        return nova;
	}
}

Lista2* concatenaDE(Lista2* l1, Lista2* l2){
	Lista2 *p = l1;
	if(l1==NULL){
		return l2;
	}
	while(p->prox!=NULL){
		p = p->prox;
	}
	p->prox = l2;
	p->prox->ant = p;
	return l1;
}

//Funcao para construir uma lista a partir de um vetor
Lista2* constroiDE (int n, int* v){
    Lista2 *L = inicializaDE();
    int i;
    if (v == NULL){
        return L;
    }
    //Percorre o vetor e vai inserindo na lista os elementos
    for(i=0; i < n; i++){
        L = inserirFDE(L, v[i]);
    }
    return L;
}
