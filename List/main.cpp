#include "List.h"
#include <iostream>
using namespace std;

int main()
{ List l;
	int a = 3, b = 1;
	
	l.insert(1,3);
	l.insert(2,1);
	l.insert(3,8);
	l.insert(4,5);
	l.insert(5,2);

	cout << "Lista: " << l.toString() << endl;
	
	while(a != 0){
		cout << "Escolha A: ";
		cin >> a;
		cout << "Escolha B: ";
		cin >> b;
		cout << "Antes swap" << endl;
		cout << "Lista: " << l.toString() << endl;
		cout << "Nos..: " << l.toStringAddr() << endl;
		cout << "Funcionou: " << l.swap(a,b) << endl;
		cout << "Apos swap" << endl;
		cout << "Lista: " << l.toString() << endl;
		cout << "Nos..: " << l.toStringAddr() << endl;
	}
  return 0;    
}
