#include <iostream>
#include "Mapa.h"
#include <prglib.h>
#include <string>

using namespace std;
using namespace prglib;


//Variáveis globais
Mapa dados("../data/dados.txt");
fila<string> filmes(5000);


// A string filmes é passada como parâmetro porque dentro da função serão adicionados novos filmes à ela.
int busca_por_ator(string filme, string ator) {

    // Fila de atores é reiniciada toda vez que a função é chamada.
    fila<string> atores(1000);

    // Fila temp serve apenas para armazenar os valores a serem enfileirados na string filmes.
    fila<string> temp(1000);

    // Obtém os atores do filme passado como parâmetro.
    atores = dados.obtem_atores(filme);

    while(! atores.vazia()) {
        string str = atores.desenfileira();
        //cout << "Ator a ser testado: " << str << endl;

        if (str.compare(ator) == 0) {
            return 1;
        }

        // Adiciona os filmes em que o ator x trabalhou ao final da lista filmes
        else {
            temp = dados.obtem_filmes(str);
            int exp = temp.comprimento();
            // O tamanho da fila é expandido de acordo com o tamanho da fila temporária
            filmes.expande(exp);

            while (! temp.vazia()) {
                string x = temp.desenfileira();
                filmes.enfileira(x);
                //cout << "O filme " << x << " foi adicionado a fila." << endl;
                //cout << "Comprimento de filmes: " << filmes.comprimento() << endl;

            }
        }

    }
    return 0;
}

int busca_bfs() {

    string ator;
    string filme;
    int i = 0;

    cout << "Digite o nome do ator: ";

    getline(cin, ator);

    cout << "O ator a ser procurado é: " << ator << endl;

    filmes = dados.obtem_filmes("Kevin Bacon");

    while(filmes.comprimento() > 0) {

        string filme = filmes.desenfileira();
        cout << "Filme a ser varrido:" << filme << endl;
        if (busca_por_ator(filme, ator) == 1) {
            cout << "O ator " << ator << " foi encontrado!" << endl;
            cout << "Número de buscas realizadas: " << i << endl;
            exit(0);
        }
        i++;
    }
    cout << "O ator " << ator << " não foi encontrado." << endl;
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