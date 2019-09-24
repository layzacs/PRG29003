#include "lista3.h"

void lista_palavras_unicas(lista<string> & resultado, string nome_arquivo) {
        thash<int> tab(100);

    ifstream arquivo(nome_arquivo);
    string word;

    while (arquivo >> word) {
        if (tab.existe(word)) {
            //retorna areferencia ao valor associado a chave
            tab[word]++;

        } else {
            tab.adiciona(word, 1);

        }

    }
}
