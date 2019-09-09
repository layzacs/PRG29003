//**********************************************************************************************************************;
// Project           : Distância de Bacon
//
// Author            : layzacs
//                     participação de Luan dos Santos para criação do pseudo código
//
// Date created      : 06082019
//
// Purpose           : Programa para calcular a distância de um ator até Kevin Bacon, mostrando o caminho usado na
//                     pesquisa.
//
//                     Funcionalidades
//
//                     - Função busca_bfs: Calcula a distância de Bacon por meio do algoritmo BFS, que faz a busca por
//                       distância.
//                     - Função busca_dfs: Calcula a distância de Bacon por meio do algoritmo DFS, que faz a busca por
//                       profundidade.
//
//                     A classe Mapa foi criada pelo prof. Marcelo Sobral.
//                     Todas as informações são tiradas do arquivo dados.txt.
//
// Revision History  :
//
// Date          Author      Ref    Revision (Date in YYYYMMDD format)
// 04082019      layzacs     1      Reformulada a função busca_bfs.
// 06082019      layzacs     1      Criada a função busca_dfs.
// 06082019      layzacs     1      Modificado nome de variáveis para denotar parentesco.
//**********************************************************************************************************************;
#include <iostream>
#include "Mapa.h"
#include <prglib.h>
#include <string>

using namespace std;
using namespace prglib;


//Struct principal onde serão guardados o caminho e a distância atual de cada ator
struct dados_atores {
    string ator;
    string caminho;
    int distancia_bacon;
};

// Função busca_dfs: Recebe a string contendo o nome do ator a ser pesquisado. A pesquisa é feita por profundidade.
int busca_dfs(string ator_procurado) {

    Mapa dados("../data/dados.txt");                                        // Criada a variável dados e inserido o caminho até o arquivo contendo os dados de atores e filmes.
    string kevin_bacon = "Kevin Bacon";

    // Testa se a string ator_procurada remete ao próprio Kevin Bacon, evitando que filas e strings desnecessárias sejam criadas quando a igualdade é verdadeira.
    if (ator_procurado == kevin_bacon) {
        cout << "A distância entre Kevin Bacon e Kevin Bacon é zero! Por favor escolha um ator DIFERENTE de Kevin Bacon." << endl;
        return 0;
    }

    pilha<struct dados_atores> todos_atores(1000000);               // Cria pilha principal, que irá conter todos os atores. A pilha é formada de structs do tipo inicializado globalmente.
    fila<string> filmes_bacon(100);                                           // Cria fila inicial contendo cada um dos filmes em que Kevin Bacon participa.
    filmes_bacon = dados.obtem_filmes(kevin_bacon);

    // Início da varredura pelas informações contidas no arquivo.
    while(! filmes_bacon.vazia()) {
        string filme_pai = filmes_bacon.desenfileira();                           // Desenfileira um filme em que Kevin Bacon atuou.

        fila<string> atores_pai = dados.obtem_atores(filme_pai);                  // Criada a lista contendo todos os atores que atuaram em um filme x com Kevin Bacon.

        // Enquanto a lista de atores não estiver vazia, é criada uma struct para cada um deles, contendo nome, caminho feito até então (Kevin Bacon + filme x) e distância atual de Bacon.
        while(! atores_pai.vazia()) {
            string ator_pai = atores_pai.desenfileira();

            struct dados_atores id_pai;
            id_pai.ator = ator_pai;
            id_pai.caminho = kevin_bacon + " --> " + filme_pai + " --> " + ator_pai;
            id_pai.distancia_bacon = 1;

            // Checa se ator atual é igual ao ator procurado.
            if (ator_pai == ator_procurado) {
                cout << "O ator " << ator_pai << " foi encontrado!" << endl;
                cout << "Sua distância de Bacon é: " << id_pai.distancia_bacon << endl;
                cout << id_pai.caminho << endl;
                return 0;
            }

            todos_atores.push(id_pai);                                            // Após criar struct e chacar, a struct é empilhada.
        }
    }

    // Após salvar todos os atores que trabalharam diretamente com Kevin Bacon, é iniciada a pesquisa dos atores com distância (de Kevin Bacon) maior que 1
    // A pesquisa é feita por meio das estruturas criadas no bloco anterior.
    while (! todos_atores.vazia()) {
        struct dados_atores id_filho = todos_atores.pop();                        // Desempilha o próximo ator a ser buscado
        string ator_filho = id_filho.ator;                                        // Nome do ator salvo em sua estrutura

        fila<string> filmes_filho = dados.obtem_filmes(ator_filho);               // É criada a fila que contém os filmes do ator desempilhado

        while(! filmes_filho.vazia()) {
            string filme_filho = filmes_filho.desenfileira();
            fila<string> atores_neto = dados.obtem_atores(filme_filho);           // Cria fila de atores que trabalharam no filme_filho

            while (!atores_neto.vazia()) {

                string ator_neto = atores_neto.desenfileira();                    // Desenfileira o próximo ator a ser criada a struct e posteriormente adicionado a pilha todos_atores.

                struct dados_atores id_neto;
                id_neto.ator = ator_neto;
                id_neto.caminho = id_filho.caminho + " --> " + filme_filho + " --> " + ator_neto;
                id_neto.distancia_bacon = id_filho.distancia_bacon + 1;

                if (ator_neto == ator_procurado) {
                    cout << "O ator " << ator_neto << " foi encontrado!" << endl;
                    cout << "Sua distância de Bacon é: " << id_neto.distancia_bacon << endl;
                    cout << "Caminho feito: " << id_neto.caminho << endl;
                    return 0;
                }
                // Devido ao fato da distância ser calculada por profundidade, é necessário limitar a distância de Bacon,
                // caso contrário o programa encontraria uma conexão muito distante e esse não é o objetivo.
                // O número 10 foi escolhido por ser a maior distância "natural" que encontramos usando o algoritmo da função busca_bfs, que é o mais efetivo.
                if (id_neto.distancia_bacon < 10) {
                    todos_atores.push(id_neto);
                }

            }
        }
    }
    // Caso todos os atores tenham sido empilhados, desempilhados e nenhum tenha sido o ator procurado, o programa retorna que o ator não existe ou não possui conexão.
    // É possível tirar essa conclusão devido ao funcionamento da classe Mapa, que ao puxar os dados de filmes e atores, exclui automaticamente os nomes já puxados para não acontecer repetições.
    cout << "Este ator não existe ou não possui nenhuma conexão com o Kevin Bacon. :(" << endl;
    return 0;
}

int busca_bfs(string ator_procurado) {

    Mapa dados("../data/dados.txt");

    string kevin_bacon = "Kevin Bacon";
    if (ator_procurado == kevin_bacon) {
        cout << "A distância entre Kevin Bacon e Kevin Bacon é zero! Por favor escolha um ator DIFERENTE de Kevin Bacon." << endl;
        return 0;
    }

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
            id_pai.caminho = kevin_bacon + " --> " + filme_pai + " --> " + ator_pai;
            id_pai.distancia_bacon = 1;

            todos_atores.enfileira(id_pai);

            if (ator_pai == ator_procurado) {
                cout << "O ator " << ator_pai << " foi encontrado!" << endl;
                cout << "Sua distância de Bacon é: " << id_pai.distancia_bacon << endl;
                cout << id_pai.caminho << endl;
                return 0;
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
                id_neto.caminho = id_filho.caminho + " --> " + filme_filho + " --> " + ator_neto;
                id_neto.distancia_bacon = id_filho.distancia_bacon + 1;

                if (ator_neto == ator_procurado) {
                    cout << "O ator " << ator_neto << " foi encontrado!" << endl;
                    cout << "Sua distância de Bacon é: " << id_neto.distancia_bacon << endl;
                    cout << "Caminho feito: " << id_neto.caminho << endl;
                    return 0;
                }

                todos_atores.enfileira(id_neto);
            }
        }

    }
    cout << "Este ator não existe ou não possui nenhuma conexão com o Kevin Bacon. :(" << endl;
    return 0;
}

int main() {

    int i;
    cout << "Distância de Bacon" << endl;

    cout << "Escolha entre as opções: \n1 - Calcular a distância de Bacon de um ator por meio do algoritmo de busca em largura.\n2 - Calcular a distância de Bacon de um ator por mei do algoritmo de busca em profundidade.\n3 - Sair." << endl;
    cin >> i;
    cin.ignore();

    switch (i) {
        case 1:

            while(true) {
                string ator_procurado;
                cout << "Digite o nome do ator a ser procurado (para sair do programa, aperte enter): ";
                getline(cin, ator_procurado);
                if (ator_procurado.size() == 0) {
                    exit(0);
                }
                busca_bfs(ator_procurado);
            }

        case 2:

            while(true) {
                string ator_procurado;
                cout << "Digite o nome do ator a ser procurado (para sair do programa, aperte enter): ";
                getline(cin, ator_procurado);
                if (ator_procurado.size() == 0) {
                    exit(0);
                }
                busca_dfs(ator_procurado);
            }
    }
    return 0;
}