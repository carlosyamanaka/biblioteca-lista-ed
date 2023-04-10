#include<stdio.h>
#include<stdlib.h>
#include "listaC.h"

ListaC* inicializaC(){
	return NULL;
}

ListaC *inserirI(ListaC *l, int v){
	ListaC *novo, *p=l;
	novo = (ListaC*)malloc(sizeof(ListaC));
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

ListaC *inserirF(ListaC *l, int v){
    ListaC *novo, *p=l;
    novo = (ListaC*)malloc(sizeof(ListaC));
    novo->info = v;
    if(l!=NULL){
        novo->prox = l;
        while(p->prox!=l){
            p = p->prox;
        }
        p->prox = novo;
        return l;
    }
    else{
        novo->prox = novo;
        return novo;
    }
}
void imprimirC(ListaC* L){
	ListaC *p=L;
	if (p!=NULL){
        do {
            printf("[%d] -> ",p->info);
            p = p->prox;
        } while(p!= L);
	}
	else{
        printf("\nLISTA VAZIA!!");
	}
    printf("\n");
}

ListaC* excluir(ListaC *l, int v){
    ListaC *ant=NULL, *p=l, *px, *aux = l;
    if(p!=NULL){
        do{
            ant = p;
            p = p->prox;
        } while(p!=l && p->info!=v);
        if(p==l){ //primeiro elemento, para excluir devemos procurar o ultimo elemento e depois retornar p->prox
            px = p->prox;
            if(px == l){
                free(px);
                return NULL;
            } else{
                while(aux->prox!=l){
                    aux = aux->prox;
                    aux->prox = p->prox;
                    free(p);
                    return aux->prox;
                }
            }
        } else{  //elemento do meio
                ant->prox = p->prox;
                free(p);
                return l;
        }
    } else{
        printf("Lista vazia, não é possivel excluir!");
    }
    return NULL;
}

ListaC* eliminar(ListaC *l){
    ListaC *aux, *p=l;

    if(p!=NULL){
        do{
            aux = p;
            p = p->prox;
            free(aux);

        } while(p!=l);
        return NULL;
    }
    else{
        printf("\nLista vazia!!!");
        return NULL;
    }
}

ListaC* separaC(ListaC *l, int n){
	ListaC *p = l;
	ListaC *nova = NULL;
	//Verificação se a lista tiver somente 1 elemento
	if (p->prox == l){
        printf("Lista de 1 elemento só");
        return l;
    }
	//Verificação se a lista é nula
    if(p != NULL) {
        do {
            p = p->prox;
        } while(p->prox!=l && p->info!=n);
        nova = p->prox;
        p->prox = l;
//        if(p != NULL) {
//        do {
//            ant = p;
//            p = p->prox;
//        } while(p!=l && p->info!=n);
//        nova = p;
//        p = l;

        //Excecoes, primeiro, ultimo, penultimo elemento.
        ListaC *comeconova = nova;
        if(nova->prox == l){
            nova = nova->prox;
            return nova;
        }
        if(nova->prox == comeconova){
            nova = nova->prox;
            return nova;
        }

        //Bloco que faz o ultimo nó do nova apontar pro primeiro nó dele
        do {
            nova = nova->prox;
        } while (nova->prox!=l);
        nova->prox = comeconova;
        return comeconova;
    } else {
        printf("Lista nula");
        return l;
    }
}

ListaC* concatenaC(ListaC* l1, ListaC* l2){
	ListaC *p1 = l1, *p2 = l2;
	if(l1==NULL){
		return l2;
	}
	if(p1!=NULL){
        do{
            p1 = p1->prox;
        } while (p1->prox!=l1);
	}
	p1->prox = l2;
	if(p2!=NULL){
        do{
            p2 = p2->prox;
        } while (p2->prox!=l2);
	}
	p2->prox = l1;
	return l1;
}

//Funcao para construir uma lista a partir de um vetor
ListaC* constroiC(int n, int* v){
    ListaC *L = inicializaC();
    int i;
    if (v == NULL){
        return L;
    }
    //Percorre o vetor e vai inserindo na lista os elementos
    for(i=0; i < n; i++){
        L = inserirF(L, v[i]);
    }
    return L;
}
