#include <string>
#include <prglib.h>
#include <fstream>
#include <iostream>

using namespace std;
using namespace prglib;

int main(int argc, char * argv[]) {
    ifstream prices(argv[1]);
    ifstream quant(argv[2]);

    thash<int> tab(5);

    string word;
    float qtd;
    float price;

    while (quant >> word && quant >> qtd) {
        if (!tab.existe(word)) {
            tab.adiciona(word, qtd);
        } else {
            tab[word] = tab[word] + qtd;
        }
    }

    while(prices >> word && prices >> price) {
        if (tab.existe(word)) {
            tab[word] = tab[word]*price;
        }
    }

    auto chaves = tab.chaves();
    chaves->ordena();
    chaves->inicia();

    while(!chaves->fim()) {
        string chave = chaves->proximo();
        cout << chave << ' ' << tab[chave] << endl;

    }


}
