//Escreva um programa que verifica se duas palavras são anagramas.
//Se uma palavra ou expressão puder ser transformada em outra, mediante a mudança de posições de caracteres, então ambas são anagramas.
#include <string>
#include <prglib.h>
#include <fstream>
#include <iostream>

using namespace std;
using namespace prglib;

int main(int argc, char * argv[]) {
    int cont = 0;
    int i = 0, j=0;
    string palavra1 = argv[1];
    string palavra2 = argv[2];

    lista<char> letras1;

    lista<char> letras2;

    // Palavras ou frases de tamanhos diferentes não podem ser anagramas
    if(palavra1.size() != palavra2.size()) {
        cout << "FALSO" << endl;
        exit(0);
    }


    int tam = palavra1.size();

    // Cria lista contendo uma letra por espaço
    while (i < tam) {
        letras1.anexa(palavra1[i]);
        i++;
    }

    while (j < tam) {
        letras2.anexa(palavra2[i]);
        j++;
    }

    letras1.ordena();
    letras2.ordena();

    if (letras1 == letras2) {
      cout << "VERDADEIRO" << endl;
    } else {
      cout << "FALSO" << endl;
    }
}
