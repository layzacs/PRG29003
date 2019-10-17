#include "verbete.h"

Verbete cria_verbete(ifstream & arq) {
    Verbete novo;
    string palavra_nova;
    string classe;
    string linha;
    lista<string> significados;

    while (getline(arq, linha)) {

        cout << "Entrou no while" << endl;
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