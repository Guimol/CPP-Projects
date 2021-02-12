#include <iostream>
#include "Deque.h"

typedef int DequeEntry;
using namespace std;

void menu(){
	cout << endl << "Menu de Fila :" << endl << endl;
	cout << "1 - Finalize: Finalizar a Fila" << endl;
	cout << "2 - Empty: Verificar se a Fila estah vazia" << endl;
	cout << "3 - Full: Verificar se a Fila estah cheia" << endl;
	cout << "4 - Append At Front: Armazenar um elemento no topo da Fila" << endl;
	cout << "5 - Append At Rear: Armazenar um elemento no topo da Fila" << endl;
	cout << "6 - Serve At Front: Retirar o elemento do topo da Fila" << endl;
	cout << "7 - Serve At Rear: Retirar o elemento do topo da Fila" << endl;
	cout << "8 - Clear: Esvaziar a Fila" << endl;
	cout << "9 - Size: Verificar o tamanho da Fila" << endl;
	cout << "10 - Front: Verificar o elemento da frente da Fila" << endl;
	cout << "11 - Rear: Verificar o  elemento do final da Fila" << endl;
	cout << "12 - ToString: Imprimir a Fila" << endl << endl;
}

int main(){
	int opcao = 0;
	DequeEntry aux;
	Deque f;
	
	while(opcao != 1){
		menu();
		cout << "Opcao: ";
		cin >> opcao;
		cout << endl;
		
		switch(opcao){
			case 1: f.~Deque();
					cout << "Finalizando..." << endl;
					break;
					
			case 2: cout << "Fila Vazia: " << f.empty() << endl;
					break;
			
			case 3: cout << "Fila Cheia: " << f.full() << endl;
					break;
			
			case 4: cout << "Insira um elemento na fila: ";
					cin >> aux;
					cout << endl;
					f.appendAtFront(aux);
					cout << "(" << f.toString() << ")" << endl;
					break;
			
			case 5: cout << "Insira um elemento na fila: ";
					cin >> aux;
					cout << endl;
					f.appendAtRear(aux);
					cout << "(" << f.toString() << ")" << endl;
					break;
			
			case 6: f.serveAtFront(aux);
					cout << "Removi o elemento \"" << aux << "\" da fila" << endl;
					cout << "(" << f.toString() << ")" << endl;
					break;
					
			case 7: f.serveAtRear(aux);
					cout << "Removi o elemento \"" << aux << "\" da fila" << endl;
					cout << "(" << f.toString() << ")" << endl;
					break;
			
			case 8: f.clear();
					cout << "Fila esvaziada" << endl;
					break;
			
			case 9: cout << "Tamanho da fila: " << f.size() << endl;
					break;
			
			case 10: f.front(aux);
					cout << "Elemento do inicio da fila: " << aux << endl;
					break;
					
			case 11: f.rear(aux);
					cout << "Elemento do fim da fila: " << aux << endl;
					break;
			
			case 12: cout << "(" << f.toString() << ")" << endl;
					 break;
					
			default: cout << "Opcao invalida!" << endl;
		}
	}
	
	return 0;
}