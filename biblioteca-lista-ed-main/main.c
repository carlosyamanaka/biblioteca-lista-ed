#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#include "listaC.h"
#include "listaF.h"
#include "listaCF.h"
#include "listaDE.h"
#include "listaDEF.h"
int main(){
    printf("Exercicio 1:\n");
	Lista2 *L1, *L2;
	L1 = inicializaDE();
	L1 = inserirIDE(L1,5);
	L1 = inserirIDE(L1,4);
	L1 = inserirIDE(L1,3);
	L1 = inserirIDE(L1,2);
	L1 = inserirIDE(L1,1);
	L2 = separaDE(L1,5);
	imprime_recDE(L1);
	printf("\n");
	imprime_recDE(L2);


    printf("\n\nExercicio 2: \n");
    Lista2 *Ex2L1, *Ex2L2, *Ex2L3;
    Ex2L1 = inicializaDE();
    Ex2L1 = inserirIDE(Ex2L1, 3);
    Ex2L1 = inserirIDE(Ex2L1, 2);
    Ex2L1 = inserirIDE(Ex2L1, 1);

    Ex2L2 = inicializaDE();
    Ex2L2 = inserirIDE(Ex2L2, 6);
    Ex2L2 = inserirIDE(Ex2L2, 5);
    Ex2L2 = inserirIDE(Ex2L2, 4);

    Ex2L3 = inicializaDE();
    Ex2L3 = concatenaDE(Ex2L1, Ex2L2);
    imprime_recDE(Ex2L3);

    printf("\n\nExercicio 3:\n");
    Lista2 *Ex3L1;
    int *v, tam = 5;
    Ex3L1 = inicializaDE();
	v = malloc(tam*sizeof(int));
    v[0] = 5;
    v[1] = 3;
    v[2] = 1;
    v[3] = 2;
    v[4] = -1;
    Ex3L1 = constroiDE(5, v);
    imprime_recDE(Ex3L1);

    printf("\nExercicio 4:\n");
    ListaCF *Ex4L1 = NULL;
    int n = 0;
    Ex4L1 = inserirIF(Ex4L1, 4);
    Ex4L1 = inserirIF(Ex4L1, 3);
    Ex4L1 = inserirIF(Ex4L1, 2);
    Ex4L1 = inserirIF(Ex4L1, 1);
    Ex4L1 = retira_prefixoC(Ex4L1, n);
    imprimirCF(Ex4L1);

    printf("Digite o numero da posicao que deseja mover para o fim:\n");
    int numeroparafim;
    scanf("%d", &numeroparafim);
    ListaC *EX3 = NULL;
    EX3 = inserirI(EX3, 4);
    EX3 = inserirI(EX3, 3);
    EX3 = inserirI(EX3, 2);
    EX3 = inserirI(EX3, 1);
    EX3 = colocanofimC(EX3, numeroparafim);
    imprimirC(EX3);
}
