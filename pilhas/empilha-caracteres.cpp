#include <string>
#include <iostream>
#include <prglib.h>

using namespace std;
using namespace prglib;

int main(int argc, char * argv[]) {
	string auxiliar;
	auxiliar = argv[1];

	pilha<char> arg(100);
	pilha<char> aux(100);

	for (int i=0; i < auxiliar.size();i++) {
		arg.push(auxiliar[i]);
	}

	while (! arg.vazia()) {
		cout << arg.top();
		aux.push(arg.pop());
	}
	cout << endl;

	while (! aux.vazia()) {
	  cout << aux.top();
	  aux.pop();
	}
	return 0;
}
