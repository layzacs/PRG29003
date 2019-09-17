#ifndef CONCAT_H
#define CONCAT_H

#include <prglib.h>

using prglib::lista;

template <typename T> void concatena_listas(lista<T> & dest, lista<T> & q1, lista<T> & q2) {

    if (!q1.vazia()) {
      q1.inicia();

      while (!q1.fim()) {
          dest.anexa(q1.proximo());
      }
    }

    if (!q2.vazia()) {
      q2.inicia();

      while (!q2.fim()) {
          dest.anexa(q2.proximo());
      }

    }


}

#endif
