#include <iostream>
#include <prglib.h>

using namespace std;
using prglib::thash;
using prglib::lista;

/*
 *
 */
int main(int argc, char** argv) {
    // cria uma tabela com 5 buckets
    thash<long> tab(5);

    // adiciona dados à tabela: primeiro parâmetro é a chave, e segundo é
    // o valor a ela associado
    tab.adiciona("um", 1);
    tab.adiciona("dois", 2);
    tab.adiciona("tres",3);

    // mostra os valores armazenados
    cout << tab["um"] << endl;
    cout << tab["dois"] << endl;
    cout << tab["tres"] << endl;

    // obtém uma lista com as chaves contidas na tabela.
    // o resultado do método "chaves" é um ponteiro para uma lista<string>
    auto chaves = tab.chaves();
    cout << "Chaves: ";
    chaves->escrevaSe(cout, ", ");
    cout << endl;

    // Obtém uma lista com os valores contidos na tabela
    // o resultado do método "valores" é um ponteiro para uma lista<long>
    // (pois a tabela armazena long)
    auto valores = tab.valores();
    cout << "Valores: ";
    valores->escrevaSe(cout, ", ");

    cout << endl;

    // Testa se uma determinada chave existe na tabela
    if (tab.existe("dois")) cout << "Tabela contém a chave: dois" << endl;
    else cout << "Tabela NÃO contém a chave: dois" << endl;

    // remove uma chave da tabela e, por consequência, o valor a ela associado
    long dado = tab.remove("dois");
    cout << "Removeu a chave: dois, e o dado que lá havia era: " << dado << endl;

    // Testa se a chave removida ainda existe na tabela
    if (tab.existe("dois")) cout << "Tabela contém a chave: dois" << endl;
    else cout << "Tabela NÃO contém a chave: dois" << endl;

    return 0;
}
