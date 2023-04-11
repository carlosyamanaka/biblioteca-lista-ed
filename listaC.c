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
    ListaC *aux1=l, *aux2 = NULL, *aux3 = NULL;
    //aux 1 = ponteiro para encontrar o local de separacao
    //aux 2 = ponteiro para armazenar o proximo nó a partir da separação
    //aux 3 = ponteiro para percorrer e encontrar o ultimo nó da lista separada

    if(aux1->info == n){//Caso n for o primeiro elemento da lista
        aux2 = aux1->prox; //recebe o primeiro elemento após a quebra
        aux1->prox = aux1; //aux1 aponta pra ele mesmo
        aux3 = aux2;
        while(aux3->prox!=l){ //aux 3 encontrando o final
            aux3 = aux3->prox;
        }
        aux3->prox = aux2; //faço o ultimo elemento da lista separada apontar para o inicio da lista separada
        return aux2;
    } else{ //Caso n não for igual o primeiro nó
        do{
            aux1 = aux1->prox;
        }while(aux1!=l && aux1->info!=n);
        //aux1->info = n

        if(aux1!=l){ //Encontrou n
                if(aux1->prox!=l){ //Verificacao se o nó encontrado não é o ultimo nó da lista
                    aux2 = aux1->prox; //primeiro da segunda lista
                    aux1->prox = l; //faz o final da primeira lista apontar para o começo
                    aux3 = aux2; //inicializa o ponteiro aux3 com a informacao de
                    //aux2 (inicio da segunda lista)
                    //para encontrar o final da segunda lista à fim de resolver a circularidade

                    while(aux3->prox!=l){ //encontrar o final da segunda parte da lista separada
                        aux3 = aux3->prox;
                    }
                    aux3->prox = aux2; //após encontrar o final da lista
                    //fazer com que o ultimo nó aponte para o primeiro nó da segunda lista separada

                    return aux2; // Retorna a segunda parte da lista separada
                    //pois a primeira parte está referenciada por l1 na main

                }else{ //Caso o nó para separação for o ultimo da lista
                    printf("\n\nE o ultimo elemento, nao e possivel separar\n\n");
                    return NULL;
                }
        }else{ //Nao encontrou n
            printf("Nao foi possivel separar");
            return 0;
        }
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
