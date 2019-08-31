#include <iostream>
#include "Mapa.h"
#include <prglib.h>
#include <string>

using namespace std;
using namespace prglib;


// A string filmes é passada como parâmetro porque dentro da função serão adicionados novos filmes à ela.
int busca_por_autor(string filme, string ator, fila<string> &filmes) {

    // Fila de atores é reiniciada toda vez que a função é chamada.
    fila<string> atores(1000);

    // Fila temp serve apenas para armazenar os valores a serem enfileirados na string filmes.
    fila<string> temp(1000);

    // Obtém os atores do filme passado como parâmetro.
    Mapa dados("../data/dados.txt");
    atores = dados.obtem_atores(filme);

    while(! atores.vazia()) {
        string str = atores.desenfileira();
        //cout << "Ator a ser testado: " << str << endl;

        if (str.compare(ator) == 0) {
            return 1;
        }
        // Adiciona os filmes em que o ator x trabalho ao final da lista filmes


        else {
            Mapa dados("../data/dados.txt");
            temp = dados.obtem_filmes(str);
            string x;
            while (! temp.vazia()) {
                string x = temp.desenfileira();
                cout << "O filme " << x << " foi adicionado a fila." << endl;
                filmes.enfileira(x);
            }
        }

    }
    return 0;
}

int busca_bfs() {

    string ator;
    string filme;
    int n_filmes;
    int i = 0;
    fila<string> filmes(10000);

    cout << "Digite o nome do ator: ";

    getline(cin, ator);

    cout << "O ator a ser procurado é: " << ator << endl;


    Mapa dados("../data/dados.txt");
    filmes = dados.obtem_filmes("Kevin Bacon");

    n_filmes = filmes.comprimento();

    while(i < n_filmes) {

        string filme = filmes.desenfileira();
        cout << "Filme a ser varrido:" << filme << endl;
        if (busca_por_autor(filme, ator, filmes) == 1) {
            cout << "O ator " << ator << " foi encontrado!" << endl;
            cout << "Número de buscas realizadas: " << i << endl;
            exit(0);
        }
        i++;
    }

    /*
    while (! filmes.vazia()) {
        string umFilme = filmes.desenfileira();
        cout << "Filme: " << umFilme << endl;
    }
    */


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