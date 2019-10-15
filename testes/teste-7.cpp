#include <string>
#include <prglib.h>
#include <fstream>
#include <iostream>

using namespace std;
using namespace prglib;

int main(int argc, char * argv[]) {
    ifstream arq(argv[1]);
    string word;
    lista<string> l;
    arq >> word;
    arvore<string> * a = new arvore<string>(word);

    while (arq >> word) {
        a->adiciona(word);
    }

    a->listeInOrder(l);

    l.escrevaSe(cout, "\n");

    return 0;
}
