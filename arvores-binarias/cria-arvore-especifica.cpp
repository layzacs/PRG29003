#include <prglib.h>
#include <string>

using prglib::arvore;
using namespace std;

arvore<string> * cria_arvore() {

    // mar é o valor da raiz, ele é passado primeiramente. A árvore nunca fica vazia
    // é importante que a raiz seja um valor mediano, no caso, a letra m está perto do centro do alfabeto.
    arvore<string> * a = new arvore<string>("mar");

    // todo valor que é acrescentado procura automaticamente o lugar certo para estar, mas deve-se adicionar os dados
    // com cuidado para que as ramificações sejam equilibradas
    // Na ordem abaixo, ferias e praia ficarão conectados diretamente a mar, no primeiro nível
    a->adiciona("ferias");
    a->adiciona("praia");
    a->adiciona("areia");
    a->adiciona("luz");
    a->adiciona("onda");
    a->adiciona("sol");

    return a;

}
