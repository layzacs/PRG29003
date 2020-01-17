#include <iostream>
#include <prglib.h>
#include <fstream>

using namespace std;
using namespace prglib;

int main(int argc, char * argv[]) {
    ifstream arquivo(argv[1]);

    if (arquivo.is_open()) {
        cout << "arquivo invalido" << endl;
    }

    // Chave: palavra lida
    // Valor: contador (inteiro)

    // preferencialmente um número primo
    thash<int> tab(113);
    string aux;

    // varre todas as palavras do arquivo
    while(arquivo >> aux) {

        if (tab.existe(aux)) tab[aux]++;

        else tab.adiciona(aux, 1);
    }

    auto lk = tab.chaves();

    lk->ordena();
    lk->inicia();

    while(!lk->fim()) {
        string palavra = lk->proximo();
        cout << palavra << ':' << tab[palavra] << endl;
    }

}

