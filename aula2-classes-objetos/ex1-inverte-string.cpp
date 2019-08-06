// 1. Escreva um programa que leia uma string do teclado, e inverta a ordem de seus caracteres. Ao final, a string invertida deve ser apresentada na tela. Apenas uma variável string pode ser usada pelo seu programa. 
// Primeiro jeito
//
/*
#include <string>
#include <iostream>

using namespace std;

int main() {
  string v;

  getline(cin, v);
  int i = 0, j = v.size()-1;
  while (i<j) {
  char c - v[i];
  v[i] = v[j];
  v[j] = c;
  i++;
  j--;
}
*/

// Segundo jeito:
#include <string>
#include <iostream>

using namespace std;

int main() {
	string v;

	getline(cin, v);

	for (int i = v.size()-1; i >= 0; i--) {
		cout << v[i];
	}
	cout << endl;
}
