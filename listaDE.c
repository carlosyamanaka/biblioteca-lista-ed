#include<stdio.h>
#include<stdlib.h>

struct lista2{
	struct lista2 *ant;
	int info;
	struct lista2 *prox;
};
typedef struct lista2 Lista2;

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


