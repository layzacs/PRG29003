#include "questao.h"

lista<string> busca_por_prefixo(arvore<string> * raiz, const string & prefixo) {
    lista<string> palavras;
    lista<string> final;

    raiz->listeInOrder(palavras);

    palavras.inicia();

    while (!palavras.fim()) {
        string palavra = palavras.proximo();


        int size = prefixo.size();

        string aux = palavra.substr(0, size);

        if (aux == prefixo) {
            final.anexa(palavra);
        }

    }

    return final;

}
