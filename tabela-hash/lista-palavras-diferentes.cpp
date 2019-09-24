#include "lista3.h"

void lista_palavras_unicas(lista<string> & resultado, string nome_arquivo) {
        thash<int> tab(100);

    ifstream arquivo(nome_arquivo);
    string word;

    while (arquivo >> word) {
        if (!tab.existe(word)) {
            tab.adiciona(word, 1);
            resultado.anexa(word);


         }
    }
}
