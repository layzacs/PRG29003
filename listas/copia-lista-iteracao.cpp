#include "copiar.h"

void copia_lista(lista<string> & original, lista<string> & nova) {
  original.inicia();

  while (! original.fim()) {
      nova.anexa(original.proximo());
  }
}
