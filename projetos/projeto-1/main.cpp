#include <iostream>
#include "Mapa.h"
#include <prglib.h>
#include <string>

using namespace std;
using namespace prglib;


//Variáveis globais

Mapa dados("../data/dados.txt");

struct dados_atores {
    string ator;
    string caminho;
    int distancia_bacon;
};

int busca_bfs() {
    string ator_procurado;
    string kevin_bacon = "Kevin Bacon";

    cout << "Digite o nome do ator:";

    getline(cin, ator_procurado);

    cout << "O ator a ser procurado é: " << ator_procurado << endl;


    fila<struct dados_atores> todos_atores(1000000);
    fila<string> filmes_bacon(100);

    filmes_bacon = dados.obtem_filmes("Kevin Bacon");

    while(! filmes_bacon.vazia()) {
        string filme_pai = filmes_bacon.desenfileira();

        fila<string> atores_pai = dados.obtem_atores(filme_pai);

        while(! atores_pai.vazia()) {
            string ator_pai = atores_pai.desenfileira();

            struct dados_atores id_pai;
            id_pai.ator = ator_pai;
            id_pai.caminho = kevin_bacon + " / " + filme_pai + " / " + ator_pai;
            id_pai.distancia_bacon = 1;

            todos_atores.enfileira(id_pai);

            if (ator_pai == ator_procurado) {
                cout << "O ator " << ator_pai << " foi encontrado!" << endl;
                cout << "Sua distância de Bacon é: " << id_pai.distancia_bacon << endl;
                cout << id_pai.caminho << endl;
            }
        }
    }

    while (! todos_atores.vazia()) {
        struct dados_atores id_filho = todos_atores.desenfileira();
        string ator_filho = id_filho.ator;

        fila<string> filmes_filho = dados.obtem_filmes(ator_filho);

        while(! filmes_filho.vazia()) {
            string filme_filho = filmes_filho.desenfileira();
            fila<string> atores_neto = dados.obtem_atores(filme_filho);

            while(! atores_neto.vazia()) {

                string ator_neto = atores_neto.desenfileira();

                struct dados_atores id_neto;
                id_neto.ator = ator_neto;
                id_neto.caminho = id_filho.caminho + " / " + filme_filho + " / " + ator_neto;
                id_neto.distancia_bacon = id_filho.distancia_bacon + 1;

                if (ator_neto == ator_procurado) {
                    cout << "O ator " << ator_neto << " foi encontrado!" << endl;
                    cout << "Sua distância de Bacon é: " << id_neto.distancia_bacon << endl;
                    cout << "Caminho feito: " << id_neto.caminho << endl;

                }

                todos_atores.enfileira(id_neto);
            }
        }

    }

    return 1;
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