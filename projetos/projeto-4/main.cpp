
//**********************************************************************************************************************;
// Project           : Dicionário lingua portuguesa
//
// Author            : layzacs
//
//
// Date created      : 15102019
//
//**********************************************************************************************************************;

#include "dicionario.h"

int main() {
    int i=0;
    cout << "Dicionário da Lingua Portuguesa" << endl;
    auto arv = prepara_dicionario();

    while (true) {

        cout << "Escolha entre as opções: \n1 - Procurar um verbete.\n2 - Procurar um lote de verbetes.\n3 - Adicionar um verbete ao dicionário.\n4 - Procura todos os verbetes que começam com um prefixo.\n5 - Sair." << endl;

        cin >> i;
        cin.ignore();

        switch (i) {

            case 1: {
                cout << "Escreva a palavra a ser procurada: " << endl;
                string palavra;
                getline(cin, palavra);

                Verbete verb;
                if (!palavra.empty()) {
                    verb = procura_verbete(arv, palavra);
                } else {
                    cout << "Você não passou uma palavra válida." << endl;
                }

                if (verb.classe != "none") {
                    cout << verb.palavra << endl;
                    cout << verb.classe << endl;
                    verb.significados.inicia();
                    while (!verb.significados.fim()) {
                        cout << verb.significados.proximo() << endl;
                    }
                    cout << endl;
                }

                break;
            }

            case 2: {
                string palavra = "palavra";
                lista<string> palavras;
                lista<Verbete> verbetes;
                cout << "Escreva a primeira palavra a ser procurada e aperte enter:" << endl;

                getline(cin, palavra);

                // Pega todas as palavras e adiciona na lista até aparecer uma string vazia
                if (!palavra.empty()) {
                    do {
                        palavras.insere(palavra);
                        cout << "Escreva a próxima palavra a ser procurada: (para finalizar aperte enter)" << endl;
                        getline(cin, palavra);
                    } while (!palavra.empty());
                }

                verbetes = procura_todos_verbetes(arv, palavras);

                verbetes.inicia();

                // imprime os verbetes
                while (!verbetes.fim()) {
                    Verbete verb = verbetes.proximo();

                    cout << verb.palavra << endl;
                    cout << verb.classe << endl;
                    verb.significados.inicia();
                    while (!verb.significados.fim()) cout << verb.significados.proximo() << endl;
                    cout << endl;
                }
                break;
            }

            case 3: {
                Verbete verb;


                // cria um verbete pela inserção do usuário
                cout << "Insira a palavra:" << endl;
                getline(cin, verb.palavra);
                cout << endl;
                cout << "Insira a classe:" << endl;
                getline(cin, verb.classe);
                cout << endl;
                string significado;
                cout << "Adicione um significado:" << endl;
                getline (cin, significado);


                while (!significado.empty()) {
                    verb.significados.insere(significado);
                    cout << "Insira outro significado: (aperte enter para sair)" << endl;
                    getline (cin, significado);
                    cout << endl;
                }

                // Chama a função adiciona verbete, que retorna true ou false
                if (adiciona_verbete(arv, verb)) {
                    cout << "Verbete salvo com sucesso." << endl;
                } else {
                    cout << "Não foi possível salvar o verbete no dicionário." << endl;
                }
                break;
            }

            case 4: {

                cout << "Insira o prefixo:" << endl;
                string prefixo;
                getline(cin, prefixo);

                lista<Verbete> verbetes = procura_prefixo(arv, prefixo);

                verbetes.inicia();

                // imprime os verbetes encontrados
                while (!verbetes.fim()) {
                    Verbete verb = verbetes.proximo();

                    cout << verb.palavra << endl;
                    cout << verb.classe << endl;
                    verb.significados.inicia();
                    while (!verb.significados.fim()) cout << verb.significados.proximo() << endl;
                    cout << endl;
                }
                break;


            }

            case 5:
                delete arv;
                exit(0);

            default:
                cout << "Opção Inválida." << endl;
                break;
        }
    }

}