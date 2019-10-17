#include "lista-palavras.h"

int conta_palavras(string nome_arquivo) {

    ifstream arq(nome_arquivo);
    string word;
    thash<int> tab(1000);

    if (! arq.is_open()) {
        return -1;
    }

    while (arq >> word) {
        tab.adiciona(word, 1);
    }


    if (tab.tamanho() > 0) {
        return tab.tamanho();
    } else {
        return 0;
    }

}
