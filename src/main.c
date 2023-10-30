#include "bintree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    int numInicial = 50;
    BinNode* root = makeNode(&numInicial);
	
	printf("Numeros sorteados:\n");
	int *numeroSorteado;
    for (int i = 0; i < 15; i++) {
        numeroSorteado = malloc(sizeof(int));
        *numeroSorteado = rand() % 100;
		printf("%d, ", *numeroSorteado);
		bstInsert(root, numeroSorteado);        
    }

	printf("\n");

	printTree(root);
	
    return 0;
}