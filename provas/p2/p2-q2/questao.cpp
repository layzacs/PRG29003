#include "questao.h"


lista<string> filmes_em_comum(const string & arq, const string & ator1, const string & ator2) {

    // abrimos o arquivo
    ifstream arquivo(arq);

    thash<lista<string>> atores(5000000);
    lista<string> final;

    string ator, filme;

    string linha;

    // pegamos cada linha por vez
    while (getline(arquivo, linha)) {

        // é feita a separação da string em filme e ator
        int found = linha.find(';');
        filme = linha.substr(0, found);
        ator = linha.substr(found+1);

        if (atores.existe(ator)) {
            lista<string> aux = atores[ator];
            aux.anexa(filme);
            atores.adiciona(ator, aux);
        } else {
            lista<string> a;
            a.anexa(filme);
            atores.adiciona(ator, a);
        }

    }

    if (atores.existe(ator1) && atores.existe(ator2)) {
        lista<string> filmes1 = atores[ator1];
        lista<string> filmes2 = atores[ator2];

        filmes1.inicia();

        while (!filmes1.fim()) {
            filme = filmes1.proximo();
            try {
                string aux1 = filmes2.procura(filme);
                final.anexa(aux1);

            } catch (...) {

            }
        }
    } else {
        return final;
    }
    return final;
}
