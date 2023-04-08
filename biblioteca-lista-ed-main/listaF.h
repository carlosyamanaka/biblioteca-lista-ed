//Declaracao do tipo lista float
struct listaf{
	float info;
	struct listaf *prox;
};
typedef struct listaf Listaf;

Listaf* retira_prefixo(Listaf* l, int n);
void imprimirf(Listaf* L);
Listaf* inserirComecof(Listaf *L, float num);
