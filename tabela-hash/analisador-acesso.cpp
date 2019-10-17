#include <iostream>
#include <prglib.h>
#include <fstream>
#include <stdlib.h>     /* atoi */


using namespace std;
using namespace prglib;

int main() {
    thash<lista<int>> users(10000);

    ifstream arq("usuarios.txt");

    if (! arq.is_open()) {
        cout << "erro ao abrir arquivo" << endl;
    }

    string usuario_final;

    getline (cin, usuario_final);

    string linha;

    while (getline(arq, linha)) {

        string user;
        string stempo;
        int tempo;
        int acessos = 1;
        lista<int> aux;
        int found = linha.find(' ');

        user = linha.substr(0, found);

        found = linha.find_last_of(' ');

        stempo = linha.substr (found);

        tempo = stoi(stempo);

        if (users.existe(user)) {
            aux = users[user];
            aux[1]++;
            aux[0] = aux[0] + tempo;
            users.adiciona(user, aux);
        } else {
            aux.insere(1);
            aux.insere(tempo);
            users.adiciona(user, aux);
        }

    }

    if (usuario_final.empty()) {
        auto chaves = users.chaves();
        chaves->ordena();
        chaves->inicia();

        while (!chaves->fim()) {
            string user = chaves->proximo();
            lista<int> w = users[user];
            cout << user << " " << w[1] << " " << w[0] << endl;
        }
    } else if (users.existe(usuario_final)) {
        lista<int> x = users[usuario_final];
        cout << usuario_final << " " << x[1] << " " << x[0];
    } else {
        cout << "usuario invalido";
    }

}
