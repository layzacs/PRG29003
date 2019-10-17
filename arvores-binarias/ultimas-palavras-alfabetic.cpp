#include <iostream>
#include <fstream>
#include <prglib.h>

using namespace std;
using namespace prglib;

int main() {
    string nome_arquivo;
    cin >> nome_arquivo;

    ifstream arq(nome_arquivo);
    string word;

    arq >> word;


    arvore<string> * a = new arvore<string>(word);

    while(arq >> word) {
        a->adiciona(word);
    }

    lista<string> final;

    a->listeInOrder(final);

    int tam = final.comprimento();


    int i = 5;

    if (final.comprimento() >=5) {
        while (i>0) {

            cout << final.obtem(tam-i) << endl;
            i--;
        }
    } else {
        final.escrevaSe(cout, " ");
    }


}
