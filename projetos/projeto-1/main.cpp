#include <iostream>
#include "Mapa.h"
#include <prglib.h>
#include <string>

using namespace std;
using namespace prglib;

int busca_bfs() {

    string ator;
    string filme;

    //fila<string> atores(1000);
    //fila<string> filmes(1000);

    cout << "Digite o nome do ator: ";

    getline(cin, ator);

    cout << "O ator a ser procurado é: " << ator << endl;

    Mapa dados("../data/dados.txt");
    filmes = dados.obtem_filmes("Kevin Bacon");


    while (! filmes.vazia()) {
        string umFilme = filmes.desenfileira();
        cout << "Filme: " << umFilme << endl;
    }

    return 0;
}

int lista_filmes() {

    Mapa mapa("../data/dados.txt");

    fila<string> q = mapa.obtem_filmes(bacon);
    int n = q.comprimento();

    while (! q.vazia()) {
        cout << q.desenfileira() << endl;
    }

    cout << bacon << " atuou em " << n << " filmes" << endl;
    return 0;
}

int main() {

    int i;
    cout << "Distância de Bacon" << endl;

    cout << "Escolha entre as opções: \n1 - Calcular a distância de Bacon de um ator por meio do algoritmo de busca em largura.\n2 - Buscar a distância de Bacon de um ator por mei do algoritmo de busca em profundidade.\n3 - Listar filmes de Kevin Bacon." << endl;
    cin >> i;
    cin.ignore();

    switch (i) {
        case 1:
            busca_bfs();
            break;

        case 2:
            //busca_dfs();
            break;

        case 3:
            lista_filmes();
            break;

    }
    return 0;
}