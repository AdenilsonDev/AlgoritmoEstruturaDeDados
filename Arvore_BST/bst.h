#ifndef _BST_H
#define _BST_H

//Construção do da arvore BST
typedef struct no {
	//temos a criação dos structs que apontam para os ponteiros direitos e esquerdos
	struct no *esq, *dir;
	//valor do nó
	int valor;
}no;    

//assinatura da função inserir na arvore

//para podermos inserir em uma arvore precisamos de uma função que precisa retornar a arvore modificada e recebe como parametros uma arvore que é ponteiro para o no e o valor a ser inserido.
no* inserir (no* raiz, int valor);
no* remover(no* raiz, int valor);
//função imprimir 
void preorder(no* raiz);
void inorder(no* raiz);
void posorder(no* raiz);
void reverse(no* raiz);
int qtdPar(no* raiz);
void quadrado(no* raiz);
int existe(no* raiz, int chave);
void buscaElementoEsq(no* raiz1, no* raiz2);
#endif
