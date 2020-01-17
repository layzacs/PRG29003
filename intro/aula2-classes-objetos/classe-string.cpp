// Classe String;
//Nesse exemplo, as variáveis nome, sobrenome e nome_completo são da classe string, e por isso são chamadas de objetos.
//Cada classe possui atributos, que representam valores internos, e operações que podem ser realizadas.
//Isso é mais fácil de entender observando o que se pode fazer com objetos string. Em um objeto, os atributos da classe string (os quais não precisamos saber quais são !) armazenam a cadeia de caracteres contida nesse objeto.
//As operações, por outro lado, devem ser conhecidas para que possam ser utilizadas.
// https://wiki.sj.ifsc.edu.br/wiki/index.php/PRG29003:_Introdu%C3%A7%C3%A3o_a_C%2B%2B
#include <string>
#include <iostream>

using namespace std;

int main() {
  string titulo = "The Shawshank Redemption";

  cout << "Filme: " << titulo << endl << endl;
  cout << "Nome do filme tem " << titulo.size() << " caracteres" << endl;
  cout << "Primeira letra do título é: " << titulo[0] << endl;

  while (true) {
    int pos = titulo.find(' ');
    cout << "Palavra do título: " << titulo.substr(0, pos) << endl;
    if (pos == string::npos) break;
    titulo.erase(0, pos+1);
  }

}
