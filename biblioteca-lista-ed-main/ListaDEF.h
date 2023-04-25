struct lista2F{
	struct lista2F *ant;
	float info;
	struct lista2F *prox;
};
typedef struct lista2F Lista2F;

void imprime_recDEF(Lista2F* l);
Lista2F* inserirIDEF(Lista2F *l, float v);
Lista2F* retira_prefixoDE (Lista2F *L1, int n);
