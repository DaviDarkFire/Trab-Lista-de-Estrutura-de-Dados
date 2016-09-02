#include <stdio.h>
#include <stdlib.h>
typedef struct no{
	int chave;
	struct no *esq;
	struct no *dir;
}no;

int busca(int, no**, no*);
int insere(int, no**);
int remover(int, no**);
void cria_arvore(no**, char*);
int imprime(no**);
no* cria_no(int);
no* maior(no*);
no* menor(no*);
void cria_raiz(no**, int);
