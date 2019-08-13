//Teste 1 - 08/08/2019
/*
Escreva um programa que leia um nome completo de uma pessoa do teclado, e mostre na tela suas iniciais. Ex:

João José Manuel Silva: JJMS
Maria de Medeiros: MM
Juquinha da Silva Luz Paes: JSLP
Manoel: M
Se o nome não for informado (i.e. string vazia), então apenas uma linha em branco deve ser apresentada.
*/
#include <string>
#include <iostream>
#include <ctype.h>

using namespace std;

int main() {
  string name;

  getline(cin, name);

  // Testa se a string está vazia.
  if (name.empty() == true) {
    cout << endl;
    exit(0);
  }

  // Se o nome não começa com um espaço E não começa com uma letra minúscula, imprime a primeira letra.
  if (name[0] != ' ' && islower(name[0]) == 0) {
    cout << name[0];
  }

  // Para o restante da string: Quando ocorre um espaço seguido de caractere maiúsculo, imprime na tela.
	for (int i = 0; (i < (name.size()-1)); i++) {
		if (name[i] == ' ' && name[i+1] != ' ') {
      if (islower(name[i+1]) == 0) {
		    cout << name[i+1];
		  }
    }
  }
}
