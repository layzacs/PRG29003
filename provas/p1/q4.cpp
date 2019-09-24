/*
Seja um arquivo com listagem de filmes e respectivos atores.  Cada linha do arquivo contém o nome do filme, o ano em que foi realizado, e a lista de atores separados vírgulas. Um exemplo de uma linha do arquivo é mostrada a seguir:

Actrius;1997;Núria Espert,Rosa Maria Sardà,Anna Lizaran,Mercè Pons

Escreva uma função que gere uma lista contendo todos os filmes em que um determinado ator atuou.
*/


#include "questao.h"

// Função da lista de exercícios, sendo reutilizada aqui com o objetivo de criar a lista de atores de um filme.
lista<string> separa(const string & texto, const string & sep) {

    int found = 0;
    lista<string> l;
    string inicial = texto;

    while (found != -1 && (! inicial.empty())) {
        found = inicial.find(sep);
        l.anexa(inicial.substr(0, found));
        inicial = inicial.substr (found + sep.size());

    }
    return l;
}

lista<string> lista_filmes(const string & nome_arquivo, const string & nome_ator){

    ifstream arq(nome_arquivo);

    if (! arq.is_open()) throw -1;

    string linha;
    lista<filmes> v;


    // Início do processo de extração e organização dos dados do arquivo. Os dados são salvos no formato da struct disponível no questao.h
    while (getline(arq, linha)) {
        int found = linha.find_first_of(';');
        string a_filme = linha.substr(0, found);
        int found2 = linha.find_last_of(';');

        string b_filme = linha.substr(found+1, 4);
        string aux = linha.substr(found2+1);
        lista<string> c_filme = separa(aux, ",");
        struct filmes a = {a_filme, b_filme, c_filme};
        v.anexa(a);
    }


    // Início da busca pelos filmes do ator passado. É criado uma lista nova que contém os filmes em que o ator participou.
    lista<string> filmes_ator;
    struct filmes x;
    v.inicia();
    while(!v.fim()) {
        x = v.proximo();
        x.atores.inicia();
        while (!x.atores.fim()) {
            if (x.atores.proximo() == nome_ator) {
                filmes_ator.anexa(x.filme);
            }
        }

    }
    return filmes_ator;
}
