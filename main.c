#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "listaC.h"
#include "listaF.h"
#include "listaCF.h"
int main(){
    printf("Exercicio 1:\n");
	ListaC *L1, *L2;
	L1 = inicializaC();
	L1 = inserirI(L1,9);
	L1 = inserirI(L1,8);
	L1 = inserirI(L1,7);
	L1 = inserirI(L1,6);
	L1 = inserirI(L1,5);
	L1 = inserirI(L1,4);
	L1 = inserirI(L1,3);
	L1 = inserirI(L1,2);
	L1 = inserirI(L1,1);
	L2 = separaC(L1,9);
	imprimirC(L1);
	imprimirC(L2);


    printf("\n\nExercicio 2: \n");
    ListaC *Ex2L1, *Ex2L2, *Ex2L3;
    Ex2L1 = inicializaC();
    Ex2L1 = inserirI(Ex2L1, 3);
    Ex2L1 = inserirI(Ex2L1, 2);
    Ex2L1 = inserirI(Ex2L1, 1);

    Ex2L2 = inicializaC();
    Ex2L2 = inserirI(Ex2L2, 6);
    Ex2L2 = inserirI(Ex2L2, 5);
    Ex2L2 = inserirI(Ex2L2, 4);

    Ex2L3 = inicializaC();
    Ex2L3 = concatenaC(Ex2L1, Ex2L2);
    imprimirC(Ex2L3);

    printf("\n\nExercicio 3:\n");
    ListaC *Ex3L1;
    int *v, tam = 5;
    Ex3L1 = inicializaC();
	v = malloc(tam*sizeof(int));
    v[0] = 5;
    v[1] = 3;
    v[2] = 1;
    v[3] = 2;
    v[4] = -1;
    Ex3L1 = constroiC(5, v);
    imprimirC(Ex3L1);

    printf("\nExercicio 4:\n");
    ListaCF *Ex4L1 = NULL;
    int n = 2;
    Ex4L1 = inserirIF(Ex4L1, 4);
    Ex4L1 = inserirIF(Ex4L1, 3);
    Ex4L1 = inserirIF(Ex4L1, 2);
    Ex4L1 = inserirIF(Ex4L1, 1);
    Ex4L1 = retira_prefixoC(Ex4L1, n);
    imprimirCF(Ex4L1);
}
