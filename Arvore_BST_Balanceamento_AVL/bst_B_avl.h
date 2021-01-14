//Arvore BST com balanceamento AVL
#ifndef _BST_B_AVL_H
#define _BST_B_AVL_H

typedef int tipo_dado;

typedef struct no {//no arvore
	tipo_dado valor;
	int fb;
	struct no *esq, *dir;
}no;    

typedef no * arvore;

void inicializar(arvore *raiz);
arvore inserir (arvore raiz, int valor);
arvore inserirAvl(int valor, arvore raiz, int *cresceu);
void imprimir(arvore raiz);
void imprimir_elemento(arvore raiz);
void preorder(arvore raiz);
void inorder(arvore raiz);
void posorder(arvore raiz);
void reverse(arvore raiz);
int qtdPar(arvore raiz);
void quadrado(arvore raiz);
int existe(arvore raiz, int chave);
arvore remover (int valor, arvore raiz, int *cresceu);
int maior_elemento(arvore raiz);
int menor_elemento(arvore raiz);
arvore rotacionar(arvore raiz);
arvore rotacao_simples_esquerda(arvore raiz);
arvore rotacao_dupla_esquerda(arvore raiz);
arvore rotacao_simples_direita(arvore raiz);
arvore rotacao_dupla_direita(arvore raiz);

#endif
