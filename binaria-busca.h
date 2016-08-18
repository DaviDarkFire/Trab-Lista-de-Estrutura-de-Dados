typedef struct no{
	int chave;
	struct no *esq;
	struct no *dir;
}no;

int busca(int, no**, no*);
int insere(int, no**);
int remover(int, no**);
int cria_arvore(no**, char*);
int imprime(no**);