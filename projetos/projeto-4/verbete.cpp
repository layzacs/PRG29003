#include "verbete.h"

bool operator<(const Verbete & s1, const Verbete & s2) {
    return s1.palavra > s2.palavra;
}

bool operator==(const Verbete & s1, const Verbete & s2) {
    return s1.palavra > s2.palavra;
}


Verbete cria_verbete(ifstream & arq) {
    Verbete novo;
    string palavra_nova;
    string classe;
    string linha;
    lista<string> significados;

    while (getline(arq, linha)) {

        if (linha.empty()) {
            break;
        }
        if (linha[0] == '*') {
            novo.palavra = linha;
        }
        else if (linha[0] == '_') {
            novo.classe_gramatical = linha;
        }
        else if (linha[0] != '(') {
        significados.anexa(linha);

        }
    }

    novo.significados = significados;

    return novo;
}

arvore<Verbete> * prepara_dict(ifstream & arq) {

    Verbete verb;
    lista<Verbete> verbetes;

    try {
        verb = cria_verbete(arq);
    } catch (...) {
        cout << "Não foi possível ler o Dicionário." << endl;
        exit(-1);

    }

    verbetes.anexa(verb);

    while (true) {
        try {
            Verbete aux = cria_verbete(arq);
            verbetes.anexa(aux);
        } catch (...) {
            break;
        }

    }

    verbetes.inicia();
    verb = verbetes.proximo();
    auto arv = new arvore<Verbete>(verb);

    while (!verbetes.fim()) {
        verb = verbetes.proximo();
        arv->adiciona(verb);
    }

    return arv ;
}