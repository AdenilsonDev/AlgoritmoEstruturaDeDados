#include <stdio.h>
#include <stdlib.h>
#include "bst_B_avl.h"


void inicializar(arvore *raiz){
	*raiz = NULL;
}

arvore inserirAvl(int valor, arvore raiz, int *cresceu){
	if(raiz == NULL){
		arvore novo =  (arvore) malloc(sizeof(struct no));
		novo->valor=valor;
		novo->dir = NULL;
		novo->esq = NULL;
		novo->fb = 0;
		*cresceu = 1;
		return novo;
	}
	if(valor > raiz->valor){
		raiz->dir = inserirAvl(valor, raiz->dir, cresceu);
		//verificar crescimento da sub arvore
		if(*cresceu){
			switch (raiz->fb){
				case 0:{
					raiz->fb = 1;
					break;				
				}
				case -1:{
					raiz->fb = 0;
					*cresceu = 0;
					break;
				}
				case 1:{
					*cresceu = 0;
					return rotacionar(raiz);//Right
					break;
				}
			}
		}
	}else if(valor <= raiz->valor){
		raiz->esq = inserirAvl(valor, raiz->esq, cresceu);
		if(*cresceu){
			switch(raiz->fb){
				case 0:{
					raiz->fb = -1;
					break;
				}
				case -1:{
					*cresceu = -1;
					return rotacionar(raiz);//Left
					break;
				}
				case 1:{
					raiz->fb = 0;
					*cresceu = 0;
					break;
				}

			}
		}
	}
	return raiz;
}


arvore rotacionar(arvore raiz){
    if(raiz->fb > 0){
        switch (raiz->dir->fb){
			case 0:
			case 1:
				return rotacao_simples_esquerda(raiz);
			case -1:
				return rotacao_dupla_esquerda(raiz);
        }
    }else{
        switch (raiz->esq->fb){

			case 0:
			case 1:
				return rotacao_dupla_direita(raiz);
			case -1:
				return rotacao_simples_direita(raiz);
        }
    }

}



arvore rotacao_simples_esquerda(arvore raiz){
    arvore p, u, t2;
    p = raiz;
    u = raiz->dir;

    p->esq = u->dir;
	u->dir = p;
	p->fb = 0;
	u->fb = 0;
	return u;
}

arvore rotacao_dupla_esquerda(arvore raiz){
	arvore p, u, v, t2, t3;
	//passo 1
	p = raiz;
	u = raiz->dir;
	v = u->esq;
	//passo 2
	u->esq = v->dir;
	v->dir = u;
	p->dir = v->esq;
	v->esq = p;
	//passo 3
	if(v->fb == 1){
		p->fb = -1;
	}else{ 
		p->fb = 0;
	}
	if(v->fb == -1){
	u->fb = 1;
	}else{
	 u->fb = 0;
	}
	v->fb = 0;
	
	return v;
}
arvore rotacao_simples_direita(arvore raiz){
    arvore p, u, t2;
    // passo 1
    p = raiz;
    u = raiz->esq;
	
	p->dir = u->esq;
	u->esq = p;

	p->fb = 0;
	u->fb = 0;

	return u;
	
}
arvore rotacao_dupla_direita(arvore raiz){
	arvore p, u, v,t1, t2, t3, t4;
    //passo 1: inicializar ponteiros
    p = raiz;
    u = raiz->dir;
	v = u->esq;
	u->esq = v->dir;
	v->dir = u;
	p->dir = v->esq;
	v->esq = p;

	if(v->fb == 1){
	 p->fb = -1;
	}else{
	 p->fb = 0;
	}
	if(v->fb == -1){
	 u->fb = 1;
	}else{
	 u->fb = 0;
	} 
	v->fb = 0;

	return v;
}


arvore inserir(arvore raiz, int valor){
	if(raiz == NULL){
		arvore novo = (arvore) malloc(sizeof(struct no)); 
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



void imprimir(arvore raiz){
    printf("(");
    if(raiz != NULL){
        imprimir_elemento(raiz);
        imprimir(raiz->esq);
        imprimir(raiz->dir);
    }
    printf(")");
}
//auxiliar imprimir
void imprimir_elemento(arvore raiz){
    printf("%d [%d]", raiz->valor, raiz->fb);
}
void preorder(arvore raiz){
	
	if(raiz == NULL){
	}else{
		printf("[%d]", raiz->valor);
		preorder(raiz->esq);
		preorder(raiz->dir);
	}
}

void inorder(arvore raiz){
	if(raiz == NULL){

	}else{
		inorder(raiz->esq);
		printf("[%d]", raiz->valor);
		inorder(raiz->dir);
	}
}
void posorder(arvore raiz){
	if(raiz == NULL){

	}else{
		posorder(raiz->esq);
		posorder(raiz->dir);
		printf("[%d]", raiz->valor);
	}
}
void reverse(arvore raiz){
	if(raiz == NULL){
	}else{
		
		reverse(raiz->dir);
		printf("[%d]", raiz->valor);
		reverse(raiz->esq);
	}
}
int qtdPar(arvore raiz){
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
void quadrado(arvore raiz){
	if(raiz == NULL){
			
	}else{
		raiz->valor *= raiz->valor;
		quadrado(raiz->esq);
		quadrado(raiz->dir);

	}
}
int existe(arvore raiz, int chave){
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

arvore remover (int valor, arvore raiz) {
	if(raiz == NULL) 
		return NULL;
	
	if(raiz->valor == valor) {		
		if(raiz->esq == NULL) {
			return raiz->dir;
		}
		if(raiz->dir == NULL) {
			return raiz->esq;
		}
		raiz->valor = maior_elemento(raiz->esq);
		raiz->esq = remover(raiz->valor, raiz->esq);
		return raiz;
	}	
	if(valor > raiz->valor) {
			raiz->dir = remover(valor, raiz->dir);
       //     verifica se a árvore diminuiu e ajusta os fatores de fbanço
	} else {
			raiz->esq = remover(valor, raiz->esq);
        //
	}
	return raiz;

}
int maior_elemento(arvore raiz) {
	if(raiz == NULL)
			return -1;
	if(raiz->dir == NULL)
		return raiz->valor;
	else
		return maior_elemento(raiz->dir);
}

int menor_elemento(arvore raiz) {
	if(raiz == NULL)
			return -1;
	if(raiz->esq == NULL)
		return raiz->valor;
	else
		return maior_elemento(raiz->esq);
}