#include <stdio.h>
#include "binaria-busca.h"


int insere(int num, no** raiz){

	while(*raiz != NULL){

		if((*raiz)->chave == num){
			
		}



	}


	return 1;


}

int cria_arvore(no** raiz, char* arq){
	FILE* arquivo = fopen(arq, "r");
	int num;
	while(!feof(arquivo)){  
        fscanf(arquivo,"%d", &num);
        insere(num, raiz);
    }	
	return 1;
}

