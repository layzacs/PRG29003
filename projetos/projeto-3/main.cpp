//**********************************************************************************************************************;
// Project           : Pesquisa de dados cinematográficos
//
// Author            : layzacs
//
//
// Date created      : 02102019
//
//**********************************************************************************************************************;

#include "proc.h"


int main() {
    int i;
    cout << " " << endl;
    thash<lista<string>> todos_filmes(300007);
    todos_filmes = obtem_dados("../data/dados.txt");


    while(true) {

        cout << "Escolha entre as opções: \n1 - Listar filmes de um ator.\n2 - Listar atores que atuaram em todos os filmes de um certo conjunto de filmes.\n3 - Os atores que trabalharam com um dado ator.\n";
        cout << "4 - Listar ordenadamente atores de acordo com sua popularidade.\n5 - Listar ordenadamente atores que trabalharam em mais filmes.\n6 - Sair" << endl;
        cin >> i;
        cin.ignore();

        int limite;
        string ator;
        string filme_procurado;
        lista<string> filmes;
        lista<string> atores;
        lista<string> atores_ordenados;
        shared_ptr<lista<string>> colegas;


        switch (i) {

            case 1:

                cout << "Digite o nome do ator pra listar seus filmes: ";
                getline(cin, ator);

                if (ator.empty()) {
                    cout << "Não foi passado nenhum ator." << endl;
                    cout << endl;
                    cout << endl;
                    break;
                }

                filmes = obtem_filmes(ator, todos_filmes);
                if (filmes.vazia()) {
                    cout << "O ator não foi encontrado." << endl;
                } else {
                    filmes.escrevaSe(cout, "\n");
                }
                    cout << endl;
                    cout << endl;
                    break;

            case 2:

                cout << "Escreva um conjunto de filmes: (aperte enter para finalizar) ";
                do {
                    filmes.anexa(filme_procurado);
                    getline(cin, filme_procurado);
                } while (!filme_procurado.empty());
                filmes.remove(0);
                //atores_filme = obtem_atores(filme_procurado, todos_filmes);
                if (filmes.vazia()) {
                    cout << "Nenhum filme foi passado." << endl;
                } else {
                    atores = obtem_atores_filmes(filmes, todos_filmes);
                }

                atores.escrevaSe(cout, "\n");
                cout << endl;
                cout << endl;
                break;

            case 3: {

                cout << "Digite o nome do ator para listar os seus colegas: ";
                getline(cin, ator);

                if (ator.empty()) {
                    cout << "Não foi passado nenhum ator." << endl;
                    break;
                }

                colegas = obtem_colegas(ator, todos_filmes);

                if (colegas->vazia()) {
                    cout << "O ator dado não foi encontrado." << endl;
                } else {
                    cout << "Os atores que trabalharam diretamente com " << ator << " são: " << endl;
                    colegas->escrevaSe(cout, "\n");
                }


                cout << endl;
                cout << endl;
                break;
            }

            case 4:
                cout << "Lista ordenada de atores de acordo com a quantidade de atores com sua popularidade" << endl;
                cout << "Quantos atores devem ser listados? (digite um valor válido, espaços não são lidos)" << endl;
                cin >> limite;
                cin.ignore();
                cout << "O resultado pode demorar em torno de 30 segundos." << endl;

                ordena_atores_colegas(todos_filmes, limite);

                cout << endl;

                break;

            case 5:
                cout << "Quantos atores devem ser listados? (digite um valor válido, espaços não são lidos)" << endl;
                cin >> limite;
                cin.ignore();
                ordena_atores(todos_filmes, limite);

                cout << endl;
                break;

            case 6:
                exit(0);

            default:
                cout << "Opção Inválida" << endl;
        }
    }
}
