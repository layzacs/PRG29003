#include "proc.h"

int procura_ator(string colega, lista<string>colegas) {
    colegas.inicia();
    int cont=0;
    while(!colegas.fim()) {
        string aux = colegas.proximo();
        if (aux == colega) {
            cont++;
        }
    }
    return cont;
}

lista<string> separa(const string & texto, const string & sep) {

    int found = 0;
    lista<string> l;
    string inicial = texto;

    while (found != -1 && (! inicial.empty())) {
        found = inicial.find(sep);
        l.anexa(inicial.substr(0, found));
        inicial = inicial.substr (found + sep.size());

    }
    return l;
}

lista<filmes> obtem_dados(const string & path) {

    ifstream arq(path);

    if (! arq.is_open()) throw -1;

    string x;
    lista<filmes> v;

    while (getline(arq, x)) {
        int found = x.find_first_of(';');
        string a_filme = x.substr(0, found);
        int found2 = x.find_last_of(';');

        string b_filme = x.substr(found+1, 4);
        string aux = x.substr(found2+1);
        lista<string> c_filme = separa(aux, ",");
        struct filmes a = {a_filme, b_filme, c_filme};
        v.anexa(a);

    }
    return v;
}

lista<string> obtem_atores(const string & filme, lista<filmes> todos_filmes) {
    todos_filmes.inicia();
    while(!todos_filmes.fim()) {
        filmes x = todos_filmes.proximo();
        if (x.filme == filme) {
            return x.atores;
        }
    }

}

lista<string> obtem_filmes(const string & ator, lista<filmes> todos_filmes) {
    lista<string> filmes_ator;
    struct filmes x;
    todos_filmes.inicia();
    while(!todos_filmes.fim()) {
        x = todos_filmes.proximo();
        x.atores.inicia();
        while (!x.atores.fim()) {
            if (x.atores.proximo() == ator) {
                filmes_ator.anexa(x.filme);
            }
        }

    }
    return filmes_ator;
}

lista<string> obtem_colegas(const string & ator, lista<filmes> todos_filmes) {
    lista<string> colegas;
    lista<string> filmes_ator;

    struct filmes x;

    todos_filmes.inicia();

    while(!todos_filmes.fim()) {
        x = todos_filmes.proximo();
        lista<string> aux = x.atores;
        x.atores.inicia();
        while (!x.atores.fim()) {
            if (x.atores.proximo() == ator) {
                aux.inicia();

                while (!aux.fim()) {
                    string colega = aux.proximo();

                    int repetido = procura_ator(colega, colegas);

                    if (repetido == 0 && colega != ator) {
                        colegas.anexa(colega);
                    }
                }
                break;
            }
        }

    }
    return colegas;
}
/*
lista<string> ordena_atores(lista<filmes> todos_filmes) {
    todos_filmes.inicia();
    lista<string> todos_atores();
    while (!todos_filmes.fim()) {
        struct filmes aux = todos_filmes.proximo();
        aux.atores.inicia();
        while(!aux.atores.fim()) {
            string ator = aux.atores.proximo();

            int repetido = procura_ator(colega, ator, colegas);

        }

    }
*/