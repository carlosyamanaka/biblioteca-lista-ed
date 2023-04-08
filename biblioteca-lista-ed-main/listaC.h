struct listaC{
    int info;
    struct listaC *prox;
};
typedef struct listaC ListaC;

ListaC* inicializaC();
ListaC *inserirI(ListaC *l, int v);
ListaC *inserirF(ListaC *l, int v);
ListaC* excluir(ListaC *l, int v);
ListaC* eliminar(ListaC *l);
void imprimirC(ListaC* L);
ListaC* separaC(ListaC *l, int n);
ListaC* concatenaC(ListaC* l1, ListaC* l2);
ListaC* constroiC(int n, int* v);
