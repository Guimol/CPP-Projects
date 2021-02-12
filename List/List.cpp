/*
 * List.cpp
 *
 *  Created on: 07/05/2020
 *      Author: Guilherme Martiniano de Oliveira, 11215765
 */
#include "List.h"
//---------------------------------------------------------------
List::List()
{
  head = NULL;
  count = 0;
}
//---------------------------------------------------------------
List::~List()
{
  clear();
}
//---------------------------------------------------------------
bool List::empty()
{
  return (head == NULL);
}
//---------------------------------------------------------------
bool List::full()
{
   return false;
}
//---------------------------------------------------------------
void List::clear()
{ ListPointer q;

  while (head != NULL)
  {  q = head;
     head = head->nextNode;
     delete q;
  }
  count = 0;
}
//---------------------------------------------------------------
long List::size()
{
   return count;
}
//---------------------------------------------------------------
void List::insert(long p, ListEntry x)
{ ListPointer newNode, current;

  if (p < 1 || p > count+1)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  newNode = new ListNode;
  newNode->entry = x;
  if(p == 1)
  {  newNode->nextNode = head;
     head = newNode;
  }
  else
  {  setPosition(p-1,current);
     newNode->nextNode = current->nextNode;
     current->nextNode = newNode;
  }
  count++;
}
//---------------------------------------------------------------
void List::remove(long p, ListEntry &x)
{ ListPointer node, current;

  if (p < 1 || p > count)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  if(p == 1)
  {  node = head;
     head = node->nextNode;
  }
  else
  {  setPosition(p-1,current);
     node = current->nextNode;
     current->nextNode = node->nextNode;
  }
  x = node->entry;
  delete node;
  count = count - 1;
}
//---------------------------------------------------------------
void List::retrieve(long p, ListEntry &x)
{ ListPointer current;

  setPosition(p,current);
  x = current->entry;
}
//---------------------------------------------------------------
long List::search(ListEntry x)
{ long p=1;
  ListPointer q=head;

  while (q != NULL && q->entry != x)
  {  q = q->nextNode;
     p++;
  }
  return (q == NULL ? 0 : p);
}
//---------------------------------------------------------------
string List::toString()
{ ListPointer q=head;
  string s;
  stringstream ss;

  while (q != NULL)
  {  ss << q->entry << ",";
     q = q->nextNode;
  }
  s = ss.str();
  return "[" + s.substr(0,s.length()-1) + "]";
}
//---------------------------------------------------------------
string List::toStringAddr()
{ ListPointer q=head;
  string s;
  stringstream ss;

  while (q != NULL)
  {  ss << q << ",";
     q = q->nextNode;
  }
  s = ss.str();
  return "[" + s.substr(0,s.length()-1) + "]";
}
//---------------------------------------------------------------
void List::setPosition(long p, ListPointer &current)
{ long i;

  if (p < 1 || p > count+1)
  { cout << "Posicao invalida" << endl;
    abort();
  }
  current = head;
  for(i=2; i<=p; i++)
      current = current->nextNode;
}
//---------------------------------------------------------------
long long List::getAddr(ListEntry x)
{ ListPointer current=NULL;
  long p = search(x);
  if(p != 0)
    setPosition(p, current);
  return (long long)current;
}
//---------------------------------------------------------------
bool List::swap(ListEntry a, ListEntry b)
{ // sua implementacao vem aqui
	
	//pre condicao: a lista deve ter sido inicializada
	
	//pos condicao: caso encontrado os dois elementos na lista tem suas posicoes trocadas, o resto da lista permanece inalterada, e eh retornado true. Outros casos a funcao retorna false;
	
	long i = 1;
	ListEntry troca;
	bool flag = false;
	ListPointer busca, anterior, anterior_ultimo, marcador_inicio, marcador_fim, aux;
	
	busca = head; //Inicio da lista para ponto de partida da busca;
	
	if(size() > 1 && a != b) //Verificar se a lista possui mais de um elemento e verificar se os dois elementos a serem pesquisados sao diferentes;
	{
		while(i <= count) //Limite da busca, para caso a busca fosse passar do tamanho da lista retorna false e a funcao acaba;
		{
			if(busca->entry == a) //Caso o primeiro elemento encontrado foi o elemento A desejado;
			{
				marcador_inicio = busca;
				break;
			}
			if(busca->entry == b) //Caso o primeiro elemento encontrado foi o elemento B;
			{
				marcador_inicio = busca;
				//Por B ter sido encontrado antes de A eles sao invertidos;
				troca = b;
				b = a;
				a = troca;
				break;
			}
			anterior = busca; //Eh guardado um ponteiro sempre no anterior do atual de busca para uso na troca dos ponteiros;
			busca = busca->nextNode; //Avanca o ponteiro de busca a cada iteracao do loop;
			i++;
		}
		if(i <= count) //Se i for maior que count significa que nenhum dos elementos foi encontrado na lista e a funcao termina;
		{
			if(marcador_inicio == head) //Verifica se o elemento A esta na head da lista;
			{	
				while(i <= count) //Busca pelo segundo elemento desejado, elemento B;
				{
					if(busca->entry == b)
					{
						marcador_fim = busca;
						break;
					}
					anterior = busca; //Eh guardado um ponteiro sempre no anterior do atual de busca para uso na troca dos ponteiros;
					busca = busca->nextNode; //Avanca o ponteiro de busca a cada iteracao do loop;
					i++;
				}
				if(i <= count) //Eh verificado se o segundo elemento foi encontrado dentro da lista;
				{
					if(head->nextNode == marcador_fim) //Verifica se sendo o A a head da lista se o elemento B esta adjacente desse;
					{
						//inverte inicio adjacente
						head = marcador_fim;
						marcador_inicio->nextNode = marcador_fim->nextNode;
						marcador_fim->nextNode = marcador_inicio;
						flag = true;
					}else
					{
						if(i == count) //Verifica se sendo o A a head da lista se o elemento B esta na ultima casa da lista;
						{
							//inverte inicio com ultimo
							marcador_fim->nextNode = marcador_inicio->nextNode;
							anterior->nextNode = marcador_inicio;
							marcador_inicio->nextNode = NULL;
							head = marcador_fim;
							flag = true;
						}else
						{
							//Verifica se sendo o A a head da lista se o elemento B esta na casa i da lista;
							//inverte inicio com i
							anterior->nextNode = head;
							aux = marcador_fim->nextNode;
							marcador_fim->nextNode = marcador_inicio->nextNode;
							marcador_inicio->nextNode = aux;
							head = marcador_fim;
							flag = true;
						}
					}
				}
			}else
			{
				marcador_inicio = busca;
				busca = busca->nextNode; //Passa o ponteiro de busca para frente pois o anterior eh o proprio elemento A;
				while(i <= count) //Busca pelo segundo elemento desejado, elemento B;
				{	
					i++;
					if(busca->entry == b)
					{
						marcador_fim = busca;
						break;
					}
					anterior_ultimo = busca; //Eh guardado um ponteiro sempre no anterior do atual de busca para uso na troca dos ponteiros;
					busca = busca->nextNode; //Avanca o ponteiro de busca a cada iteracao do loop;
				}
				if(i <= count) //Eh verificado se o segundo elemento foi encontrado dentro da lista;
				{
					if(marcador_inicio->nextNode == marcador_fim) //Verifica se o elemento B eh adjacente ao elemento A;
					{
						//inverte adjacente
						marcador_inicio->nextNode = marcador_fim->nextNode;
						anterior->nextNode = marcador_fim;
						marcador_fim->nextNode = marcador_inicio;
						flag = true;
					}else
					{
						if(i == count) //Verifica se o elemento B eh o ultimo da lista;
						{
							//inverte i com ultimo
							anterior->nextNode = marcador_fim;
							marcador_fim->nextNode = marcador_inicio->nextNode;
							anterior_ultimo->nextNode = marcador_inicio;
							marcador_inicio->nextNode = NULL;
							flag = true;
						}else
						{
							//Invercao entre dois elementos nao adjacentes da lista e com nenhum deles sendo o inicio ou fim da lista
							//inverte normal
							aux = marcador_fim->nextNode;
							marcador_fim->nextNode = marcador_inicio->nextNode;
							marcador_inicio->nextNode = aux;
							anterior_ultimo->nextNode = marcador_inicio;
							anterior->nextNode = marcador_fim;
							flag = true;
						}
					}
				}
			}
		}	
	}	
	
	return flag;
	
}
//---------------------------------------------------------------
