#include <string>
#include <iostream>
#include <prglib.h>
#include <fstream>

using namespace std;
using namespace prglib;

int main(int argc, char * argv[]) {
    ifstream arquivo(argv[1]);
    string linha;
    pilha<string> linhas(1000);

    std::fstream fs;


    if (! arquivo.is_open()) {
        cout << "arquivo invalido" << endl;
    }

    while (getline(arquivo, linha)) {
        linhas.push(linha);
    }


    while (!linhas.vazia()) {
        cout << linhas.pop() << endl;
    }

    return 0;
}