struct lista2{
	struct lista2 *ant;
	int info;
	struct lista2 *prox;
};
typedef struct lista2 Lista2;

Lista2* inicializaDE();
Lista2* inserirIDE(Lista2 *l, int v);
void imprime_recDE(Lista2* l);
Lista2* inserirFDE(Lista2 *l, int v);
Lista2* buscarDE(Lista2 *l, int v);
Lista2* excluirDE(Lista2 *l, int v);
Lista2* separaDE(Lista2 *l, int n);
Lista2* concatenaDE(Lista2* l1, Lista2* l2);
Lista2* constroiDE (int n, int* v);

