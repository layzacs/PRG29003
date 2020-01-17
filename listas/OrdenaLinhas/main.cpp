#include <fstream>
#include <iostream>
#include <prglib.h>
using prglib::lista;

using namespace std;

// Este novo tipo de dados foi criado para possibilitar comparar
// strings pelos seus comprimentos.
// Note que o tipo Linha apenas encapsula uma string (campo string s),
// e define o operador <

struct Linha {
    // a string encapsulada
    string s;

    Linha() {}
    Linha(const string & algo) {
        s = algo;
    }
};

// o operador < compara as strings s1 e s2 (s1 < s2)
// a comparação é feita pelos comprimentos das strings encapsuladas
bool operator<(const Linha & s1, const Linha & s2) {
    struct Linha a1, b1;

    a1 = s1;
    b1 = s2;

    return a1.s[2] < b1.s[2];


}

int main(int argc, char * argv[]) {
    // implemente aqui seu programa
    ifstream arq(argv[1]);

    // Cria uma lista de Linha, para ser possível ordenar pelo comprimento de string
    lista<Linha> l;

    string x;

    // para cada linha lida e guardada na variável "x"
    while (getline(arq, x)) l.anexa(x);

    cout << x << endl;
    // ordena a lista: a comparação entre os valores armazenados será feita usando o
    // operador < do tipo Linha
    l.ordena();

    // Usa iteração para apresentar o conteúdo da lista na tela
    l.inicia();
    while (! l.fim()) {
        Linha & linha = l.proximo();

        cout << linha.s << endl;
    }

    return 0;
}