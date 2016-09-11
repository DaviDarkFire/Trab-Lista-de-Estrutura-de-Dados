#include "binaria-busca.h"

no* cria_no(int x){
	no* node;
	node = (no*) malloc (sizeof(no));
	node->chave = x;
	node->esq = NULL;
	node->dir = NULL;
	return node;

}

no* maior(no* node){
	while(node->dir != NULL){
		node = node->dir;
	}
	return node;
}

no* menor(no* node){
	while(node->esq != NULL){
		node= node->esq;
	}
	return node;
}

int busca(int x, no* pt, no** pai){
	if(pt == NULL){
		return 0;
		//não encontrou elemento
	}
	if(pt->chave == x){
		return 1;
		//tem gente cuzão
	}
	*pai = pt;
	if(pt->chave > x){
		busca(x, pt->esq, pai);

	}else{
		busca(x, pt->dir, pai);
	}
}

int inserir(int x, no **pt){
	no *pai = NULL;
	int aux = busca(x, *pt, &pai);

	no* node = cria_no(x);

	if(aux == 1){
		return 0;
	}

	if(aux == 0 && pai == NULL){
		(*pt) = node;
		return 1;
	}
	if(pai != NULL && aux == 0){
		if(pai->chave > x){
			pai->esq = node;
		}else{
			pai->dir = node;
		}
		return 1;
	}

}

void pre_ordem (no *pt) {
    if (pt != NULL) {
        printf("%d\n", pt->chave);
        pre_ordem (pt->esq);
        pre_ordem (pt->dir);
    }
}

void cria_arvore(char* arq, no** raiz){
	FILE* arquivo = fopen(arq, "r");
	int x;
	while(!feof(arquivo)){
        		fscanf(arquivo,"%d", &x);
        		//printf("%d\n",x);
        		inserir(x, raiz);
    	}
}
