#include <iostream>
#include <string>
#include <prglib.h>

using namespace std;
using prglib::arvore;

int main() {
    string w[7] = {"graviola","caju","sapoti","acai", "banana","morango","laranja"};

    // Uma árvore deve ser criada dinamicamente ... isso facilita
    // sua implementação.
    arvore<string> * arv = new arvore<string>(w[0]);

    for (int n=1; n < 6; n++) arv->adiciona(w[n]);

    for (int n=0; n < 7; n++) {
        try {
            cout << "arv[" << w[n] << "] = " << arv->obtem(w[n]) << endl;
        } catch (...) {
            cout << "Ops: " << w[n] << " não está na árvore !" << endl;
        }
    }

    delete arv;

    return 0;
}