#include <stdio.h>
#include "bst.h"

int main (int argc, char*argv[]){
	no *raiz = NULL;

	int flag = 1;
	int option;

	while(flag != -1){
		scanf("%d", &option);

		switch (option){
			case 1:{
				int valor;
				scanf("%d", &valor);
				raiz = inserir(raiz, valor);
				break;
			}
			case 2:{
				preorder(raiz);
				printf("\n");
				break;
			}case 3:{
				inorder(raiz);
				printf("\n");
				break;
			}case 4:{
				posorder(raiz);
				printf("\n");
				break;
			}case 5:{
				reverse(raiz);
				printf("\n");
				break;
			}case 6:{
				int par = qtdPar(raiz);
				printf("%d\n", par);
			
				break;
			}case 7:{
				quadrado(raiz);
				break;
			}case 8:{
				int chaveExiste = 0, chave = 0;
				scanf("%d", &chave);
				chaveExiste = existe(raiz, chave);
				printf("%d\n", chaveExiste);
				break;
			}
			case 9:{
				int elemento = 0;
				scanf("%d", &elemento);
				remover(raiz, elemento);
				break;
			}case 99:{
				flag = -1;
				break;
			}
			
		}
	}
	
	return (0);
}
