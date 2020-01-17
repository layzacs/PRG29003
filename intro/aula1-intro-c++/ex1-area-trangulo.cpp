//
// Created by layzacs on 01/08/2019.
//

// 1. Escreva um programa que calcula a área de um triângulo, apresentando o resultado na tela. Qualquer valor que o programa precisar para o cálculo deve ser obtido pelo teclado.

#include <iostream>

using namespace std;

int main() {
    int b, h, area;

    cout << "Insira a altura do triângulo: " << endl;
    cin >> h;

    cout << "Insira o tamanho da base do triângulo: ";
    cin >> b;

    area = (b*h)/2;

    cout << "A área do triângulo é de " << area << endl;
    return 0;
}
