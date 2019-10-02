#ifndef prj2_PROC_H
#define prj2_PROC_H

#include <string>
#include <prglib.h>
#include <iostream>
#include <fstream>

using std::ifstream;
using std::endl;
using std::string;
using std::cout;
using std::cin;
using prglib::lista;
using prglib::thash;

struct ator {
    string nome;
    int num;
};

// Função separa uma string em substrings, dado um delimitador
lista<string> separa(const string & texto, const string & sep);

// Recupera cada linha do arquivo e cria uma tabela hash com filmes e listas de atores
thash<lista<string>> obtem_dados(const string & path);

// Obtém filmes de um dado ator
lista<string> obtem_filmes(const string & ator, thash<lista<string>> & todos_filmes);

// Obtém uma lista de atores que trabalharam em todos os filmes dados
lista<string> obtem_atores_filmes(lista<string> filmes, thash<lista<string>> & todos_filmes);

// Obtém atores que trabalharam com um dado ator
shared_ptr<lista<string>> obtem_colegas(const string & ator, thash<lista<string>> & todos_filmes);

// Ordena atores de acordo com a popularidade (quantidade de colegas)
void ordena_atores_colegas(thash<lista<string>> & todos_filmes, int limite);

// Ordena atores de acordo com a quantidade de filmes feitos
void ordena_atores(thash<lista<string>> todos_filmes, int limite);

#endif //prj2_PROC_H