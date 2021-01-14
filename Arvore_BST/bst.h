#ifndef _BST_H
#define _BST_H

typedef struct no {
	struct no *esq, *dir;
	int valor;
}no;    


no* inserir (no* raiz, int valor);
void preorder(no* raiz);
void inorder(no* raiz);
void posorder(no* raiz);
void reverse(no* raiz);
int qtdPar(no* raiz);
void quadrado(no* raiz);
int existe(no* raiz, int chave);
no* remover(no* raiz, int valor);

#endif
