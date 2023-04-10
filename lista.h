//Declaracao do tipo lista int
struct lista{
	int info;
	struct lista *prox;
};
typedef struct lista Lista;

//Colocando as declaracoes das funcoes
Lista* inicializa();
Lista* constroi (int n, int* v);
Lista* concatena(Lista* l1, Lista* l2);
Lista* separa(Lista *l, int n);
Lista *inserirFim(Lista *L, int v);
Lista* inserirComeco(Lista *L, int num);
void imprimir(Lista* L);
Lista* retira(Lista* L, int num);
Lista* libera (Lista* L);
