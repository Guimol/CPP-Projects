/*
 * Deque.cpp
 *
 *  Created on: 19/05/2020
 *  Author: Guilherme Martiniano de Oliveira, 11215765
 */
#include "Deque.h"
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
typedef int DequeEntry;

// pre: nenhuma
// pos: Deque criado vazio (sem elementos)
// Pior caso O(constante) executa os tres comandos para inicializar um deque; 
Deque::Deque(){
	head = tail = NULL; //"Aterra" os ponteiros ao iniciar o deque;
	tamanho = 0; //Inicia o tamanho do deque como 0;
}

// pre: Deque criado
// pos: Deque eh destruido, liberando espaço ocupado pelos seus elementos
// Pior caso O(n) o deque tem elementos e portanto cada um eh descartado;
Deque::~Deque(){
	DequePointer lixo;
	
	while(head != NULL){ //Codigo que percorre o deque e vai excluindo cada elemento;
		lixo = head;
		head = head->nextNode;
		delete lixo;
	}
}

// pre: Deque criado
// pos: retorna true se o deque esta vazio; false caso contrario
// Pior caso O(constante) eh feita duas operacoes uma de verificacao e outra de retorno;
bool Deque::empty(){
	return (head == NULL); //Verifica se a cabeca esta vazia que portanto indica que a deque esta vazia;
}

// pre: Deque criado
// pos: retorna true se o deque esta cheio; false caso contrario
// Pior caso O(constante) uma unica operacao de retorno;
bool Deque::full(){
	return false; //Devido a ser um deque dinamico nao ha problemas do deque estar cheio;
}

// pre: Deque nao estah cheio
// pos: O item x eh armazenado no inicio do deque
// Pior caso O(constante) caso o deque esteja inicialmente vazio sao feitas nove operacoes para adicionar o primeiro elemento na estrutura;
void Deque::appendAtFront(DequeEntry x){
	DequePointer p;
	
	p = new DequeNode;
	
	if(p == NULL){
		//Caso haja algum erro ao criar o ponteiro e esse pointeiro apontar ao "vazio"/NULL a funcao nao ocorre; 
	}else{
		p->entry = x;
			
		if(empty()){ //No caso da insercao do primeiro elemento do deque, head e tail estarao apontando pro mesmo elemento p;
			head = tail = p; 
			p->nextNode = NULL;
		}else{ //Nos demais casos o elemento p entra apontando para o head, ou seja, antes desse e apos sua insercao p se torna o head do deque;
			p->nextNode = head;
			head = p;
		}
		tamanho++;	
	}
}

// pre: Deque nao estah cheio
// pos: O item x eh armazenado no final do deque
// Pior caso O(constante) caso a estrutura deque esteja vazia ou com elementos sao feitas nove operacoes para inserir o novo elemento;
void Deque::appendAtRear(DequeEntry x){
	DequePointer p;
	
	p = new DequeNode;
	
	if(p == NULL){
		//Caso haja algum erro ao criar o ponteiro e esse pointeiro apontar ao "vazio"/NULL a funcao nao ocorre; 
	}else{
		p->entry = x;
		
		if(empty()){ //No caso da insercao do primeiro elemento do deque, head e tail estarao apontando pro mesmo elemento p;
			head = tail = p;
		}else{ //Nos demais casos o elemento p entra apontando para o tail, ou seja, apos desse e depois de ser inserido p se torna o tail do deque;
			tail->nextNode = p;
			tail = p;
		}
		p->nextNode = NULL; //p no final desse metodo sempre apontara para NULL por ser o tail do deque;
		tamanho++;
	}
}

// pre: Deque nao vazio
// pos: O item do inicio do deque eh removido e seu valor eh retornado na variavel x
// Pior caso O(constante) caso o deque tenha um unico elemento ocorrerao nove operacoes para retirar esse elemento;
void Deque::serveAtFront(DequeEntry &x){
	DequePointer p;
	
	if(empty()){
		//Verifica se ha elementos no deque, caso nao tenha nenhum elemento o metodo nao modifica nada;
	}else{
		x = head->entry;
		p = head;
		head = head->nextNode;
		
		delete p;
		tamanho--;
	}
	if(head == NULL){ //No caso do elemento head ao final do serve se tornar NULL significa que o deque esta vazio entao tail tambem deve apontar para NULL para o deque voltar ao estado inicial da estrutura deque;
		tail = NULL;
	}
}

// pre: Deque nao vazio
// pos: O item do final do deque eh removido e seu valor eh retornado na variavel x
// Pior caso O(n) caso o elemento nao esteja na head a funcao percorrera todos os elementos para retirar o ultimo;
void Deque::serveAtRear(DequeEntry &x){
	DequePointer p, lixo;
	
	if(empty()){
		//Verifica se ha elementos no deque, caso nao tenha nenhum elemento o metodo nao modifica nada;
	}else{
		p = head;
		
		if(tamanho == 1){
			x = head->entry;
			head = tail = NULL; //No caso do elemento head ao final do serve se tornar NULL significa que o deque esta vazio entao tail tambem deve apontar para NULL para o deque voltar ao estado inicial da estrutura deque;
			
			tamanho--;
			delete p;
		}else{
			while(p->nextNode != tail){ //Para remocao de um elemento na tail do deque o metodo percorre a estrutura inteira ate o penultimo elemento para entao retirar o elemento da tail do deque;
				p = p->nextNode;
			}
			lixo = p->nextNode;
			x = lixo->entry;
			tail = p;
			p->nextNode = NULL;
			
			tamanho--;
			delete lixo;
		}
	}
	
}

// pre: Deque criado
// pos: Todos os itens do deque sao descartados e ele se torna um deque vazio
// Pior caso O(n) eh percorrido o deque inteiro para eliminar cada elemento;
void Deque::clear(){
	DequePointer lixo;
	
	if(empty()){
		//Verifica se ha elementos no deque, caso nao tenha nenhum elemento o metodo nao modifica nada;
	}else{
		while(head != NULL){ //Codigo que percorre o deque e vai excluindo cada elemento;
			lixo = head;
			head = head->nextNode;
			delete lixo;
		}
		tamanho = 0; //Torna o tamanho do deque 0 pois todos os elementos foram removidos da estrutura;
	}
}

// pre: deque nao estah vazio
// pos:  x recebe uma copia do item que se encontra no inicio do deque; o deque permanece inalterado
// Pior caso O(constante) faz a verificacao se o deque estah vazio utilizando do metodo empty() que por sua vez faz uma verificacao e caso nao esteja faz uma atribuicao, no total tres operacoes;
void Deque::front(DequeEntry &x){
	if(empty()){
		//Verifica se ha elementos no deque, caso nao tenha nenhum elemento o metodo nao modifica nada;
	}else{
		x = head->entry;
	}
}

// pre: deque nao estah vazia
// pos:  x recebe uma copia do item que se encontra no final do deque; o deque permanece inalterado
// Pior caso O(constante) faz a verificacao se o deque estah vazio utilizando do metodo empty() que por sua vez faz uma verificacao e caso nao esteja faz uma atribuicao, no total tres operacoes;
void Deque::rear(DequeEntry &x){
	if(empty()){
		//Verifica se ha elementos no deque, caso nao tenha nenhum elemento o metodo nao modifica nada;
	}else{
		x = tail->entry;
	}
}

// pre: Deque criado
// pos: retorna o numero de itens no deque
// Pior caso O(constante) retorna a variavel de tamanho, uma unica operacao;
int Deque::size(){
	return tamanho;
}

// pre: Deque criado
// pos: retorna o deque como string, um elemento apos o outro, iniciando pelo comeco do deque
//      Os elementos sao separados por um unico espaco e nao deve haver espacos adicionais no
//      inicio nem no final da string retornada
// Pior caso O(n) percorre o deque inteiro para imprimir todos elementos;
string Deque::toString(){
	DequePointer p;
	stringstream ss;
	
	p = head;
	while(p != NULL){ //Percorre todos os elementos do deque e vai os armazenando na estrutura stringstream para ser retornado pelo metodo;
		if(p == tail){
			ss << p->entry;
		}else{
			ss << p->entry;
			ss << " ";
		}
		p = p->nextNode;
	}
	
	delete p;
	return ss.str();
}