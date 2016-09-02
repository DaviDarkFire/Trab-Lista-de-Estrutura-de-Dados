#include "binaria-busca.h"

no* cria_no(int x){
	no* no = malloc (sizeof(no));
	no->chave = x;
	no->esq = NULL;
	no->dir = NULL;
	return no;

}

void cria_raiz(no** raiz, int x){
	(*raiz) = (no *)malloc(sizeof(no));
	(*raiz)->chave = x;
	(*raiz)->esq = NULL;
	(*raiz)->dir = NULL;
}

no* maior(no* no){
	while(no->dir != NULL){
		no = no->dir;
	}
	return no;
}

no* menor(no* no){
	while(no->esq != NULL){
		no = no->esq;
	}
	return no;
}

int insere(int num, no** raiz){
	no* pai = malloc(sizeof(no));
	pai->esq = NULL;
	pai->dir = NULL;

	int aux;
	aux = busca(num, raiz, pai);
	if(aux == 1){
		printf("Chave ja existente, da pra inserir não jão\n");
		return 0;
	}
	if(aux == -1){
		pai->esq = cria_no(num);

	}
	if(aux == 0){
		pai->dir = cria_no(num);
	}

	return 1;


}

int remover(int x, no** raiz){
	no* pai = malloc(sizeof(no));
	pai->esq = NULL;
	pai->dir = NULL;
	int aux = busca(x, raiz, pai);
	if(aux == 1){
		if((*raiz)->dir == NULL && (*raiz)->esq == NULL){
			if((*raiz) == pai->esq){
				pai->esq = NULL;
			}else{
				pai->dir = NULL;
			}
		}

		if(pai->esq == (*raiz)){
			if((*raiz)->dir == NULL && (*raiz)->esq != NULL){
				pai->esq = (*raiz)->esq;

			}
			if((*raiz)->dir != NULL && (*raiz)->esq == NULL){
				pai->esq = (*raiz)->dir;
			}

			if((*raiz)->dir != NULL && (*raiz)->esq != NULL){
				pai->esq = menor((*raiz)->dir);

			}
		}

		if(pai->dir == (*raiz)){
			if((*raiz)->dir == NULL && (*raiz)->esq != NULL){
				pai->dir = (*raiz)->esq;

			}
			if((*raiz)->dir != NULL && (*raiz)->esq == NULL){
				pai->dir = (*raiz)->dir;
			}
			if((*raiz)->dir != NULL && (*raiz)->esq != NULL){
				pai->dir = menor((*raiz)->dir);
			}
		}

		free((*raiz));
		return 1;
	}else{
		printf("Impossível Remover, elemento inexistente jão\n");
		return 0;
	}
}
//retorna 0 se não encontrar e estiver pra direita, -1 se não encontrar e estiver pra esquerda e 1 se encontrar
int busca(int x, no** raiz, no* pai){
	int aux;
	while((*raiz) != NULL){
		if(x > (*raiz)->chave){
			aux = 0;
			pai = (*raiz);
			(*raiz) = (*raiz)->dir;
		}
		if(x < (*raiz)->chave){
			aux = -1;
			pai = (*raiz);
			(*raiz) = (*raiz)->esq;
		}
		if(x == (*raiz)->chave){
			return 1;
		}
	}
	if(aux == 0){
		return 0;
	}else{
		return -1;
	}

}

void cria_arvore(no** raiz, char* arq){
	FILE* arquivo = fopen(arq, "r");
	int num;
	int aux = 1;
	while(!feof(arquivo)){
        	fscanf(arquivo,"%d", &num);

        	if(aux == 1){
        		cria_raiz(raiz, num);
        		aux = 0;
        	}else{
        		insere(num, raiz);	
        	}
        	
    }	
}
