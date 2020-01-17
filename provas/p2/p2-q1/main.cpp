#include <string>
#include <prglib.h>
#include <iostream>
#include <fstream>

using namespace std;
using namespace prglib;


// foi feita uma estrutura e modificado o operador, para poder comportar os dados e ordena-los.
struct a {
    string produto;
    int qtd=0;
};

bool operator<(const a & s1, const a & s2) {
    if (s1.qtd == s2.qtd) {
        return s1.produto > s2.produto;
    }
    return s1.qtd > s2.qtd;
}

int main(int argc, char * argv[]) {

    ifstream arq(argv[1]);
    string word;

    // testa se arquivo abriu
    if (! arq.is_open()) {
        cout << "Arquivo Invalido" << endl;
    }

    // criada a tabela hash de produtos
    thash<int> tab(200000);

    // as palavras são recuperadas. Se a palara já existe na tabela, o valor relacionado a ela é incrementado.
    while (getline(arq, word)) {
        if (tab.existe(word)) {
            //retorna areferencia ao valor associado a chave
            tab[word] = tab[word] + 1;

        } else {
            tab.adiciona(word, 1);
        }

    // criamos a lista das chaves para poder usar a iteração e salvar os valores relacionados na struct.
    auto chaves = tab.chaves();

    chaves->inicia();

    lista<a> prod_final;

    struct a aux;
    // cada chave será inserida na struct com sua quantidade de ocorrencias e elas serão salvas na lista prod_final
    while (!chaves->fim()) {
        string auxiliar = chaves->proximo();
        aux.produto = auxiliar;
        aux.qtd = tab[auxiliar];
        prod_final.anexa(aux);
    }

    // os produtos são ordenados de acordo com o numero na struct. As que possuem mesmo numero são ordenadas por ordem alfabetica
    prod_final.ordena();
    prod_final.inicia();

    // Inicia a iteração para imprimir a lista ordenada na tela.
    while (!prod_final.fim()) {
        aux = prod_final.proximo();
        cout << aux.produto << endl;
    }

}