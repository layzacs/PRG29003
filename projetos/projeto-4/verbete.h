#ifndef VERBETE_H
#define	VERBETE_H

#include <string>
#include "prglib.h"
#include <iostream>
#include <fstream>

using std::ifstream;
using std::endl;
using std::string;
using std::cout;
using std::cin;
using prglib::lista;
using prglib::arvore;

struct Verbete {
    string palavra;
    string classe_gramatical;
    lista<string> significados;

};

// Função prepara dicionário (pega todos os verbetes do arquivo
//

// Função cria verbete
Verbete cria_verbete(ifstream & arq);

#endif	/* LEMBRETE_H */
