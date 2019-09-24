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
// Date          Author      Ref    Revision (Date in DDMMYYYY format)
// 13092019      layzacs     1      cria função obtem_dados
// 16092019      layzacs     2      cria funções obtem_filmes e obtem_atores
// 19092019      layzacs     3      cria função obtem_colegas
// 20092019      layzacs     4      cria função ordena_atores; cria nova struct ator; modifica função separa para não
//                                  incluir mais strings vazias na lista de atores; cria operador para struct ator;
//**********************************************************************************************************************;

#include "proc.h"


int main() {
    int i;
    cout << " " << endl;



    while(true) {

        cout << "Escolha entre as opções: \n1 - Lista filmes de um ator.\n2 - Lista atores que trabalharam em um filme.\n3 - Os atores que trabalharam com um dado ator.\n";
        cout << "4 - Lista ordenada de atores de acordo com a quantidade de filmes em que atuaram.\n5 - Listar os atores que mais trabalharam com um certo ator.\n6 - Sair" << endl;
        cin >> i;
        cin.ignore();

        int limite;
        int k;
        string ator;
        string filme_procurado;
        lista<string> filmes_ator;
        lista<string> atores_filme;
        lista<string> colegas;
        lista<string> atores_ordenados;
        lista<filmes> todos_filmes;
        todos_filmes = obtem_dados("../data/dados.txt");


        switch (i) {

            case 1:

                cout << "Digite o nome do ator pra listar seus filmes: ";
                getline(cin, ator);

                filmes_ator = obtem_filmes(ator, todos_filmes);
                if (filmes_ator.vazia()) {
                    cout << "O ator não foi encontrado." << endl;
                } else {
                    filmes_ator.escrevaSe(cout, "\n");
                }
                cout << endl;
                cout << endl;
                break;

            case 2:

                todos_filmes = obtem_dados("../data/dados.txt");

                cout << "Digite o nome do filme para listar seus atores: ";
                getline(cin, filme_procurado);


                atores_filme = obtem_atores(filme_procurado, todos_filmes);
                if (atores_filme.vazia()) {
                    cout << "O filme não foi encontrado." << endl;
                } else {
                    atores_filme.escrevaSe(cout, "\n");
                }
                cout << endl;
                cout << endl;
                break;

            case 3:

                todos_filmes = obtem_dados("../data/dados.txt");

                cout << "Digite o nome do ator para listar os atores: ";
                getline(cin, ator);


                colegas = obtem_colegas(ator, todos_filmes);

                if (colegas.vazia()) {
                    cout << "O ator dado não foi encontrado." << endl;
                } else {
                    cout << "Os atores que trabalharam diretamente com " << ator << " são: " << endl;
                    colegas.escrevaSe(cout, "\n");
                }
                cout << endl;
                cout << endl;
                break;

            case 4:
                cout << "Quantos atores devem ser listados? (digite um valor válido, espaços não são lidos)" << endl;
                cin >> limite;
                cin.ignore();

                ordena_atores(todos_filmes, limite);
                cout << endl;

                break;

            case 5:
                cout << "Digite o nome do ator pra listar seus filmes: ";
                getline(cin, ator);
                cout << "Quantos atores devem ser listados? (digite um valor válido, espaços não são lidos)" << endl;

                cin >> limite;
                cin.ignore();
                cout << "Esta função demora em torno de 20 segundos para retornar o resultado. Seja paciente." << endl;
                k = ordena_colegas(ator, todos_filmes, limite);

                if (k == 0) {
                    cout << "O ator dado não foi encontrado." << endl;
                }
                cout << endl;
                break;

            case 6:
                exit(0);

            default:
                cout << "Opção Inválida" << endl;
        }
    }
}