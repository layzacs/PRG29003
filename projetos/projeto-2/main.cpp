//**********************************************************************************************************************;
// Project           :
//
// Author            : layzacs
//
//
// Date created      : 06082019
//
// Purpose           : Programa para calcular a distância de um ator até Kevin Bacon, mostrando o caminho usado na
//                     pesquisa.
//
//                     Funcionalidades
//
//
//
// Revision History  :
//
// Date          Author      Ref    Revision (Date in YYYYMMDD format)
// 04082019      layzacs     1      Reformulada a função busca_bfs.
// 06082019      layzacs     1      Criada a função busca_dfs.
// 06082019      layzacs     1      Modificado nome de variáveis para denotar parentesco.
//**********************************************************************************************************************;

#include "proc.h"


int main() {
    int i;
    cout << " " << endl;

    cout << "Escolha entre as opções: \n1 - Lista filmes.\n2 - Lista atores.\n3 - Os atores que trabalharam com um dado ator.\n 4 - Lista ordenada de atores de acordo com a quantidade de filme em que atuaram" << endl;
    cin >> i;
    cin.ignore();

    switch (i) {
        case 1:

            while (true) {
                string ator_procurado;

                lista<filmes> todos_filmes;
                todos_filmes = obtem_dados("../data/dados.txt");

                cout << "Digite o nome do ator pra listar seus filmes: ";
                getline(cin, ator_procurado);

                if (ator_procurado.empty()) {
                    exit(0);
                }
                lista<string> filmes_ator = obtem_filmes(ator_procurado, todos_filmes);
                cout << "Filmes do ator " << ator_procurado << ":" << endl;
                filmes_ator.escrevaSe(cout, ", ");
                cout << endl;

            }

        case 2:

            while (true) {
                string filme_procurado;

                lista<filmes> todos_filmes;
                todos_filmes = obtem_dados("../data/dados.txt");

                cout << "Digite o nome do filme para listar seus atores: ";
                getline(cin, filme_procurado);

                if (filme_procurado.empty()) {
                    exit(0);
                }

                lista<string> filmes_ator = obtem_atores(filme_procurado, todos_filmes);
                cout << "Atores do filme " << filme_procurado << ":" << endl;
                filmes_ator.escrevaSe(cout, ", ");

            }
        case 3:
            while (true) {
                string ator_procurado;

                lista<filmes> todos_filmes;
                todos_filmes = obtem_dados("../data/dados.txt");

                cout << "Digite o nome do ator para listar os atores: ";
                getline(cin, ator_procurado);

                if (ator_procurado.empty()) {
                    exit(0);
                }
                lista<string> colegas = obtem_colegas(ator_procurado, todos_filmes);
                cout << "Os atores que trabalharam diretamente com " << ator_procurado << "são: " << endl;
                colegas.escrevaSe(cout, ", ");
                cout << endl;
            }
/*
        case 4:
            lista<filmes> todos_filmes;
            todos_filmes = obtem_dados("../data/dados.txt");
            lista<string> atores_ordenados = ordena_atores(todos_filmes);
            cout << "Os primeiros 20 atores em ordem são: " << endl;
            atores_ordenados.escrevaSe(cout, ", ");
            exit(0);
*/

    }
}