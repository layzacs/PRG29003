//
// Created by msobral on 22/08/2019.
//

#include "proc.h"
#include <fstream>
#include <iostream>
#include <prglib.h>

using std::ifstream;
using std::string;
using std::cout;
using prglib::lista;




/*
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
*/

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
