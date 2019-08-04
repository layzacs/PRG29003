//
// Created by layzacs on 01/08/2019.
//
// 4. Escreva um programa que fatore um número inteiro. Esse programa deve mostrar todos os números primos que dividem o número a ser fatorado.

#include <iostream>

using namespace std;

void primos(int fatores[50], int j) {
  int i, k;

  for (k = 0; k < j; k++) {
    // O loop abaixo divide o fator por todos os números inteiros menores que ele. Quando o resto é diferente de 0 e o número não é 2, ele percebe que é um número primo.
    for (i = 2; (i < fatores[k]); i++) {
      if (((fatores[k] % i) == 0) || (fatores[k] == 2)) {
        break;
      }
    }

    if (fatores[k] != 2) {
      cout << "O número " << fatores[k] << " é um fator primo." << endl;
    }
  }
}

int fatora(int num, int i, int fatores[50], int j) {

  cout << num << " = ";

  // O loop abaixo divide o número de input pelo menor fator. Depois, o fator é salvo no vetor fatores e a var. j é acrescentada.
  for (i=2;i<=num;i++) {
    while ((num % i) == 0) {

      if (num != i) {
        cout << i << "x";
        fatores[j] = i;
        j++;
      }
      else {
        cout << i << endl << "Fim da fatoração." << endl;
        fatores[j] = i;
        j++;
      }
      num = (num / i);
    }
  }
  return j;
}


int main() {

  int num, i = 0, j = 0;
  int fatores[50]; // Vetor de inteiros que guardará os fatores do número digitado

  // Input do número a ser fatorado
  cout << "Digite o número a ser fatorado:" << endl;
  cin >> num;

  // Função fatora é a responsável por fatorar o número. Ela recebe como parâmetros o número do input, duas variáveis de controle e o vetor de fatores. A função retorna o número total de fatores.
  j = fatora(num, i, fatores, j);

  // A função primos varre o vetor de fatores e diz quais fatores são primos.
  primos(fatores, j);
}
