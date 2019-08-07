// 2. Escreva um programa que leia uma string do teclado e conte quantas palavras existem nessa string. Ao final, a contagem de palavras deve ser mostrada na tela. As palavras são delimitadas por espaços. (projeto CLion). Dica: use a função getline para ler uma linha completa do teclado, como neste exemplo
/*
string linha;

  // lê caracteres a partir de cin, e guarda-os na string "linha",
  // até encontrar um caractere newline (quebra-de-linha, ou \n)
  getline(cin, linha);
  cout << "Você digitou esta linha: " << linha << endl;
*/
#include <string>
#include <iostream>

using namespace std;

int main() {
	string v;
  int j=0;

	getline(cin, v);

	for ((int i = 0); (i <= v.size()-1); i++) {
		if (v[i] == ' ' && v[i+1] != 0) {
      j++;
    }
	}
	cout << endl;
}
