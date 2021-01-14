#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

no* inserir(no* raiz, int valor){
	if(raiz == NULL){
		no *novo = (no *) malloc(sizeof(no));
		novo->valor = valor;
		novo->esq = NULL;
		novo->dir = NULL;

		return novo;
	}else{

		if(valor > raiz->valor){
			raiz->dir = inserir(raiz->dir, valor);
		}else{
			raiz->esq = inserir(raiz->esq, valor);
		}
	}
	
	return raiz;
	
}

void preorder(no* raiz){
	if(raiz == NULL){
		return NULL;
	}else{
		printf("[%d]", raiz->valor);
		preorder(raiz->esq);
		preorder(raiz->dir);
	}
}

void inorder(no* raiz){
	if(raiz == NULL){
		return NULL;

	}else{
		inorder(raiz->esq);
		printf("[%d]", raiz->valor);
		inorder(raiz->dir);
	}
}
void posorder(no* raiz){
	if(raiz == NULL){

	}else{
		posorder(raiz->esq);
		posorder(raiz->dir);
		printf("[%d]", raiz->valor);
	}
}
void reverse(no* raiz){
	if(raiz == NULL){
	}else{
		
		reverse(raiz->dir);
		printf("[%d]", raiz->valor);
		reverse(raiz->esq);
	}
}
int qtdPar(no* raiz){
	int par =0;
	if(raiz == NULL){
		return par;
		
	}else{
		par += qtdPar(raiz->esq);
		if((raiz->valor%2)==0 ){
			par++;	
		}
		par +=qtdPar(raiz->dir);

	}
	return par;
	
}
void quadrado(no* raiz){
	if(raiz == NULL){
			
	}else{
		raiz->valor *= raiz->valor;
		quadrado(raiz->esq);
		quadrado(raiz->dir);

	}
}
int existe(no* raiz, int chave){
	int chaveExiste = 0;
	if(raiz == NULL){
	}else{
		if(chave == raiz->valor){
			chaveExiste = 1;
		}else if(chave > raiz->valor){
			chaveExiste = existe(raiz->dir, chave);
		}else if(chave < raiz ->valor){
			chaveExiste = existe(raiz->esq, chave);
		}
	}
	return chaveExiste;
}

no* remover(no* raiz, int valor){
	if(raiz == NULL){
		return NULL;
	}

	if(raiz->valor == valor){

		if(raiz->esq == NULL && raiz->dir == NULL){
			free(raiz);
			return NULL;
		}	

		if(raiz->esq == NULL && raiz->dir != NULL){
			no* raizDireita = raiz->dir;
			free(raiz);
			return raizDireita;
		}else if(raiz->dir ==NULL && raiz->esq != NULL){
			no* raizEsquerda = raiz->esq;
			free(raiz);
			return raizEsquerda;
		}

		no* raizP = raiz->esq;
		while(raizP->dir != NULL){
			raizP = raizP->dir;
		}
		raiz->valor = raizP->valor;
		raizP->valor = valor;
		raiz->esq = remover(raiz->esq, valor);
		return raizP;
		
            
	}else{
		if(valor > raiz->valor){
			raiz->dir = remover(raiz->dir, valor);
		}else{
			raiz->esq = remover(raiz->esq, valor);
		}
	}
	
	return raiz;
	
}
