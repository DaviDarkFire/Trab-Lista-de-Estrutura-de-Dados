#include <stdio.h>
#include <stdlib.h>
typedef struct node{
	int chave;
	struct node *esq;
	struct node *dir;
}no;

int busca(int , no* , no**);
void pre_ordem(no*);
int inserir(int, no**);
void cria_arvore(char*, no**);
no* cria_no(int);
no* maior(no*);
no* menor(no*);

