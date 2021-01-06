#include <stdio.h>
#include <stdlib.h>
#include "bst_B_avl.h"

int main (int argc, char*argv[]){
	arvore raiz;
	int option;
	int controleFB;
	inicializar(&raiz);
	int flag = 1;

	while(flag != -1){
		scanf("%d", &option);

		switch (option){
				int valor;
			case 1:{//inserir
				scanf("%d", &valor);
				raiz = inserirAvl(valor, raiz, &controleFB);
				//raiz = inserir(raiz, valor);
				break;
			}
			case 2:{//imrpimir no preorder
				//imprime com fator de balanço - verificação de rotação da raiz
				imprimir(raiz);
				printf("\n");
				//imprimir sem o fator de balanço 
				//preorder(raiz);
				//printf("\n");
				break;
			}case 3:{// imprimir no inorder
				inorder(raiz);
				printf("\n");
				break;
			}case 4:{//imprimir no posorder
				posorder(raiz);
				printf("\n");
				break;
			}case 5:{//imprime de forma decrescente
				reverse(raiz);
				printf("\n");
				break;
			}case 6:{//imprime a quantidade de numeros pares na arvore
				int par = qtdPar(raiz);
				printf("%d\n", par);
			
				break;
			}case 7:{//modifica o valor de todos os nós, elevando-os ao quadrado
				quadrado(raiz);
				break;
			}case 8:{//procura o valor dentro da arvore
				int chaveExiste = 0, chave = 0;
				scanf("%d", &chave);
				chaveExiste = existe(raiz, chave);
				printf("%d\n", chaveExiste);
				break;
			}
			case 9:{//remove um elemento OBS: falta implementar o fator de balanceamento após a remoção
				scanf("%d", &valor);
				raiz = remover(valor, raiz);
				
				break;
			}case 99:{
				flag = -1;
				break;
			}
		}
	}
	
	return (0);
}
