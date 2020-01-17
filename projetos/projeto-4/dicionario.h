#ifndef VERBETE_H
#define	VERBETE_H

#include <string>
#include <prglib.h>
#include <iostream>
#include <fstream>

using std::ifstream;
using std::endl;
using std::string;
using std::cout;
using std::cin;
using std:: ofstream;
using prglib::lista;
using prglib::arvore;

struct Verbete {
    string palavra;
    string classe;    // classe gramatical
    lista<string> significados;

    bool operator<(const Verbete & termo1) const {
        return palavra < termo1.palavra;
    }
    bool operator>(const Verbete & termo1) const {
        return palavra > termo1.palavra;
    }
    bool operator==(const Verbete & termo1) const {
        return palavra == termo1.palavra;
    }

};

// Adiciona um verbete ao dicionario, adicionando-o a arvore e salvando no arquivo.
bool adiciona_verbete(arvore<Verbete> * arv, Verbete & verb);

// Procura e retorna todos os verbetes do dicionário que começam com o dado prefixo.
lista<Verbete> procura_prefixo(arvore<Verbete> * arv, string & prefixo);

// Procura um lote de verbetes.
lista<Verbete> procura_todos_verbetes(arvore<Verbete> * arv, lista<string> & palavras);

// procura verbete na arvore
Verbete procura_verbete(arvore<Verbete> * arv, string & palavra);

arvore<Verbete> * prepara_dicionario();

// Função prepara dicionário (pega todos os verbetes do arquivo caso o arquivo dicionario.txt não exista. Se existe, cria a arvore pelo arquivo dicionario.txt.
arvore<Verbete> * cria_arvore_lista();

// cria lista com verbetes
lista<Verbete> cria_lista_verbetes(string & path);

// Salva a árvore no arquivo dicionario.txt e retorna true se der tudo certo.
bool salva_arvore_arquivo(arvore<Verbete> * arv);

#endif	/* LEMBRETE_H */