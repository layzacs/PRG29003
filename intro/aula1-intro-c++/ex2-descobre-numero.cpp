//
// Created by layzacs on 01/08/2019.
//
// 2. Escreva um programa capaz de descobrir o valor de um número que você tenha imaginado. O programa deve interagir sucessivamente com você, até descobrir o número. Ao final, ele deve informar quantas tentativas precisou para descobrir o número. OBS: o número deve ser um inteiro entre 0 e 100.
// Dica: é possível descobrir o número em no máximo 7 tentativas se for usada uma busca binária.
// Pesquisa Binária: https://pt.wikipedia.org/wiki/Pesquisa_bin%C3%A1ria

#include <iostream>
#include <string>

using namespace std;

int main() {
  int top = 100, bot = 0, mid = 50;
  int tries;
  string answer;

    for(tries = 1;((mid - 1) != bot);tries++) {
      //cout << "top= " << top << " bot=" << bot << " mid=" << mid << endl; --- linha pra debug
      cout << "O número é maior que " << mid << "? y/n" << endl;
      cin >> answer;

      if (answer == "y") {                                     // Compara strings
        bot = mid;                                          // Se o número é maior que o da var. meio, o menor número possível é o valor da var. meio
        mid = (bot + (top - bot)/2);                    // O meio passa a ser a soma do menor número possível com a metade da diferença entre o maior e o menor.
      }
      else if (answer == "n") {
        top = (mid + 1);
        mid = (bot + (top - bot)/2);
      }
      else {
        cout << "Argumento inválido. Responda com y ou n." << endl;
      }
    }

  cout << "O número que você imaginou é " << mid << ". Número de tentativas: " << tries << endl;
  return 0;
}
