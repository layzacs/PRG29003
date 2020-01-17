// 3. Escreva uma função que procure uma substring dentro de uma string, e a substitua por outra string (projeto CLion).
// Por exemplo, se a string for correr, e a substring a ser procurada for rre for subsituída por pia, o resultado deve ser copiar. Essa função deve ser declarada assim:
// Parâmetros:
//   texto: a string a ser modificada
//   sub: a substring a ser pcourada dentro de texto
//   outra: a string a substituir a outra string
// Resultado:
//  a função devolve como resultado o valor de "texto" com a substituição efetuada
//string substitui(string texto, string sub, string outra) {
  // implementação da função
//}
#include <string>
#include <iostream>

using namespace std;

string substitui(string texto, string sub, string outra) {
	int found;

	found = texto.find(sub);
	if (found != string::npos) { // return value, string::npos significa um valor válido da string. Usa-se para evitar erros devido a diferentes versões do c++ ou das bibliotecas.
    break;
	}
	texto.replace(found, sub.length(), outra);
	}
	return texto;

int main() {
	string texto, final, sub = "porta", outra = "mesa";

	getline(cin, texto);
  final = substitui(texto, sub, outra);
  cout << final << endl;
}
