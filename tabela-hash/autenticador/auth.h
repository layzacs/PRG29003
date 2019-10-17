#ifndef AUTH_H
#define AUTH_H

#include <fstream>
#include <prglib.h>
#include <string>

using namespace std;
using namespace prglib;

class Autenticadora {
    
 private:

  thash<string> users(1000);

 public:

   // construtor da classe
   Autenticadora(string nome_arquivo);

   bool verifica_credencial(string usuario, string senha);
};

#endif
