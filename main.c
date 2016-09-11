#include <stdio.h>
#include "binaria-busca.h"

int main(int argc, char *argv[]){
	no* raiz;
	cria_arvore(argv[1], &raiz);
	pre_ordem(raiz);

}