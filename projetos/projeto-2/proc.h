//
// Created by msobral on 22/08/2019.
//

#ifndef prj2_PROC_H
#define prj2_PROC_H

#include <string>
#include <prglib.h>

using std::string;
using prglib::lista;

struct filmes {
    string filme;
    string ano;
    lista<string> atores;
};

// Recupera cada linha do arquivo e cria uma lista com elas.
lista<filmes> obtem_dados(const string & path);

// Obtém filmes de um ator passado
lista<string> obtem_filmes(const string & ator, lista<filmes> todos_filmes);

lista<string> obtem_atores(const string & filme, lista<filmes> todos_filmes);

#endif //prj2_PROC_H