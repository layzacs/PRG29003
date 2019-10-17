#include "Autenticadora.h"

Autenticadora::Autenticadora(string nome_arquivo) {
  ifstream arq(nome_arquivo);

  if (!arq.is_open()) {
    throw -1;
  }

  string word;

  while (arq >> word) {
    string user;
    string senha;
    int sep = 0;
    sep = word.find(':');
    user = word.substr(0, sep);
    senha = word.substr(sep+1);
    users.adiciona(user, senha);
  }
}

bool Autenticadora::verifica_credencial(string usuario, string senha) {
    if (users.existe(usuario)) {
        if (users[usuario] == senha) {
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}
