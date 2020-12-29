//Biblioteca padrão de entrada e saida 
#include <stdio.h>
#include <stdlib.h>
//biblioteca em construção na pasta do projeto caso fosse em uma sub-pasta utilizariamos "diretorio/bst.h"
#include "bst.h"

//Aqui é o local onde implementamos as funções que foram declaradas no bst.h

//Função inserir
// para fazer a função temos que ter um ponteiro apontando para o NULL, assim quando atribuimos um elemento iremos verificar se a arvore está vazia, então iremos comparar o valor que esta sendo inserido com o valor da raiz relativa(Sub-arvore que sera inserida o elemento)
//Na comparação iremos verificar se o valor que sera inserido é maior ou menor ou menor do que a raiz da arvore, para decidir se sera armazenado na direita ou na esquerda
//após a verificação o valor iremos chamar a função inserir sendo passado como raiz relativa o ponteiro que vai indicar(direita ou esquerda) e entramos em uma nova chamada do inserir
//Devemos observar atentamente a ligação entre as sub-arvores para não ficar com sem encaminhamento das raizes

//iremos utilizar a forma mais básica de implementação recursiva de uma arvore BST que é a maneira mais simples de se implementar 
//Para isso precisamos pensar em duas coisas: 1- qual o caso base de uma função recusica?(qual instancia mais simples para resolver o problema). 2- quais os casos recursivos?(quais casos indutivos?).
//casp base - Iremos inserir em uma arvore vazia, ou temos uma sub-arvore vázia
//1 - Para começar a inserir precisamos inicializar o no com espaço para os ponteiros e para o valor então "precisamos alocar memoria"
//2 - Feito a alocação de espaço agora precisamos definir os valores onde apontamos os ponteiros para "NULL" e inserimos o "valor" assim iremos "preencher os valores"
//3 - com isso, para finalizar iremos, precisar atualizar os ponteiros quando formos adicionar o valor seja para uma arvore vazia, ou uma sub-arvore vazia podendo ser filho direito ou esquerdo
no* inserir(no* raiz, int valor){
	//caso base recursivo
	if(raiz == NULL){
		//posso 1 - alocação de memoria
		no *novo = (no *) malloc(sizeof(no));
		//passo 2 - inicialização dos valores
		//atribuição do valor a raiz
		novo->valor = valor;
		//Criando sub-arvores com raiz relativa apontando para NULL na esquerda e direita
		novo->esq = NULL;
		novo->dir = NULL;
		//passo 3 - para essa função base só precisamos retornar o novo
		return novo;
	}else{
		//caso recursivos -  verificar se o valor vai para a direita ou para a esquerda
		if(valor > raiz->valor){
			raiz->dir = inserir(raiz->dir, valor);//atribuição do valor na sub-arvore direita 
		}else{
			raiz->esq = inserir(raiz->esq, valor);//atribuição do valor na sub-arvore esquerda
			//utilizamo o "raiz->esq ou raiz->dir" para fazer a ligação das sub-arvore esquerda e direita com a raiz principal da arvaore, ou a raiz relativa
		}
	}
	
	return raiz;
	
}

//Função imprimir - aqui iremos imprimiro o valor da raiz, e seguiremos percorrendo toda a sub-arvore a esquerda e depois a sub-arvore a direita 
//Caso base - temos uma arvore vazia
//caso recursia - temos o pré-order, in-order e o pós-order
//pré-order
//RED(R-raiz,E-esquerda,D-direita)
//no pre-order iremos imprimir a raiz antes de entrarmos de irmos para as raizes relativas 

void preorder(no* raiz){
	//nosso caso base é a possibilidade da raiz ser NULL
	if(raiz == NULL){
		//assim não fazemos nada quando ela é vazia
	}else{
		//Seguindo o modelo de pre-order iremos imprimir primeiro o valor da raiz
		printf("[%d]", raiz->valor);
		//depois iremos para a sub-arvore esquerda da raiz imprimindo a mesma
		preorder(raiz->esq);
		//seguindo então para sub-arvore direita da raiz imprimindo a mesma
		preorder(raiz->dir);
	}
}
//in-order 
//ERD(E-esquerda, R-raiz, D- direita)
//no in-order iremos imprimir quando estivermos entre duas raizes relativas 
void inorder(no* raiz){
	//nosso caso base é a possibilidade da raiz ser NULL
	if(raiz == NULL){

	}else{
		inorder(raiz->esq);
		printf("[%d]", raiz->valor);
		inorder(raiz->dir);
	}
}
//pos-order
//EDR(E-esquerda, D-direita, R- raiz)
//no pós-order iremos imprimir o valor quando passarmos pela raiz relativa direita
void posorder(no* raiz){
	if(raiz == NULL){

	}else{
		posorder(raiz->esq);
		posorder(raiz->dir);
		printf("[%d]", raiz->valor);
	}
}
//reverso 
//Foi pensado em utilizar o modelo inverso do in-order pois podemos perceber que se invertermos a ordem de busca de esquerda para direita 
//e utilizarmos a busca da direita para esquerda iremos obter sempre o maior numero
void reverse(no* raiz){
	if(raiz == NULL){
	}else{
		
		reverse(raiz->dir);
		printf("[%d]", raiz->valor);
		reverse(raiz->esq);
	}
}
//Quantidade de raizes pares
//Considerando que podemos utilizar as formas de buscas independente do modelo ao inves de imprimir podemos utilizar um contador e o sistema condicional
//para verificar o resto de divisão do valor caso seja par incrementamos em 1 e por fim retornamos a quantidade
int qtdPar(no* raiz){
	//contador
	int par =0;
	//caso base
	if(raiz == NULL){
		return par;
		
	}else{
		//pesquisa in-order
		par += qtdPar(raiz->esq);
		//verificação se o valor da raiz é par
		if((raiz->valor%2)==0 ){
			par++;	
		}
		par +=qtdPar(raiz->dir);

	}
	return par;
	
}
//Elevando raizes ao quadrado
//Consideramos a busca e alteração dos valores multiplicando por si mesmo
void quadrado(no* raiz){
	if(raiz == NULL){
			
	}else{
		//para não utilizar a função da biblioteca math, utilizamos a multiplicação da raiz por ela mesma.
		raiz->valor *= raiz->valor;
		quadrado(raiz->esq);
		quadrado(raiz->dir);

	}
}
//Procura a existencia de uma chave
//Como iremos procurar uma um valor podemos fazer comparação já que sabemos que os numeros maiores que a raiz ficam a direita e os menores a esquerda
int existe(no* raiz, int chave){
	int chaveExiste = 0;
	if(raiz == NULL){
	}else{
		if(chave == raiz->valor){//compara o valor da chave
			chaveExiste = 1;
		}else if(chave > raiz->valor){//transforma a sub-arvore em arvore principal para se aproximar do valor da chave caso maior que a raiz
			chaveExiste = existe(raiz->dir, chave);
		}else if(chave < raiz ->valor){//transforma a sub-arvore em arvore principal para se aproximar do valor da chave caso menor que a raiz
			chaveExiste = existe(raiz->esq, chave);
		}
	}
	return chaveExiste;
}



//Remover elemento - para isso temos 3 possiveis casos são eles
//caso 1: não temos nenhum filho/raiz relativa
no* remover(no* raiz, int valor){
	//Caso base
	//Quando obtemos o NULL como retorno nos temos então uma sub-arvore vázia ou o elemento procurado não existe
	if(raiz == NULL){
		return NULL;
	}
	//caso base recursivo
	if(raiz->valor == valor){
		//caso 1 - sem raiz relativa
		if(raiz->esq == NULL && raiz->dir == NULL){
			free(raiz);
			return NULL;
		}	
		//caso 2a - com uma raiz relativa direita
		if(raiz->esq == NULL && raiz->dir != NULL){
			//como não podemos limpar diretamenta a memoria da raiz, utilizamos um ponteiro para armazenar a raiz do lado direito 
			no* raizDireita = raiz->dir;//ponteiro auxiliar
			free(raiz);//devida o ponteiro auxiliar podemos limpar nossa raiz sem perder o endereço da raiz relativa direita
			return raizDireita;//utilizamos o retorno para atualizar o ponteiro
		}else if(raiz->dir ==NULL && raiz->esq != NULL){//caso 2b - com uma raiz relativa esquerda
			no* raizEsquerda = raiz->esq;
			free(raiz);
			return raizEsquerda;
		}else{
			no* aux = raiz->esq;
			while(aux ->dir != NULL){
				aux = aux->dir;
			}
			raiz->valor = aux->valor;
			aux->valor = valor;
			raiz->esq = remover(raiz->esq, valor);
		}
		
            
	}else{
		//caso recursivos -  verificar se o valor vai para a direita ou para a esquerda
		if(valor > raiz->valor){
			raiz->dir = remover(raiz->dir, valor);//atribuição do valor na sub-arvore direita 
		}else{
			raiz->esq = remover(raiz->esq, valor);//atribuição do valor na sub-arvore esquerda
			//utilizamo o "raiz->esq ou raiz->dir" para fazer a ligação das sub-arvore esquerda e direita com a raiz principal da arvaore, ou a raiz relativa
		}
	}
	
	return raiz;
	
}
