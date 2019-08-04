//
// Created by layzacs on 01/08/2019.
//
// 3. Escreva um programa que teste se um número é primo. Ao final, seu programa deve informar se o número é primo ou não.

#include <iostream>
#include <string>

using namespace std;

int main() {
  int num, i = 0;
  cout << "======== Checagem de Número primo =========" << endl;
  cout << "Entre com o número:";
  cin >> num;

  for (i=2;i<num;i++) {
    if ((num % i) == 0) {
      cout << "O número " << num << " não é primo." << endl;
      exit(0);
    }
  }

  if (num == 2) {
    cout << "O número " << num << " não é primo." << endl;
  }
  else {
      cout << "O número " << num << " é primo." << endl;
      return 0;
  }
}
