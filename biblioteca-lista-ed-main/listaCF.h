struct listaCF{
    float info;
    struct listaCF *prox;
};
typedef struct listaCF ListaCF;

ListaCF* inicializaCF();
ListaCF *inserirIF(ListaCF *l, int v);
void imprimirCF(ListaCF* L);
ListaCF* retira_prefixoC (ListaCF *L1, int n);
