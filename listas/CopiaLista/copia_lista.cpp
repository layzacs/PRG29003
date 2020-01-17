#ifndef PROG_COPIA_LISTA_H
#define PROG_COPIA_LISTA_H
#include <string>
#include <prglib.h>

using prglib::lista;
using std::string;


void copia_lista(lista<string> & original, lista<string> & nova) {
    nova = original;

}
#endif //PROG_COPIA_LISTA_H
