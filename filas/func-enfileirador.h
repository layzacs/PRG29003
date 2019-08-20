#ifndef ENFILEIRA_H
#define ENFILEIRA_H

#include <prglib.h>
#include <string>

using std::string;

using prglib::fila;

// & abaixo significa que o parametro está sendo passado como referência, então as alterações são vistas fora da função.
void enfileira_chars(string algo, fila<char> & q) {

	for (int i = 0; i < algo.size(); i++) {
		q.enfileira(algo[i]);
	}

}
#endif
