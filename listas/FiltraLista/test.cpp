//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <vector>
#include <ostream>
#include <sstream>
#include <fstream>
#include <prglib.h>
#include "questao.h"
#include "gtest/gtest.h"

using namespace std;
using prglib::lista;

const string hexdigits = "0123456789abcdef";

class TesteQuestao: public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
    }

    int gen_lista(lista<int> & q, int min, int max) {
        int n, maior = 0;

        n = 5 + (rand() % 10);
        while (n-- > 0) {
            int x = min + (rand() % (max - min));
            if (x > maior) maior = x;
            q.anexa(x);
        }
        return maior;
    }

    void meu_filtra(lista<int> & q, lista<int> & orig, int limiar) {
        orig.inicia();

        while (not orig.fim()) {
            int x = orig.proximo();
            if (x > limiar) q.anexa(x);
        }
    }

    string ltos(lista<int> & l) {
        ostringstream os;

        l.escrevaSe(os, ",");
        return os.str();
    }
};

TEST_F(TesteQuestao, Vazia)
{
    try {
        lista<int> q, dest;

        filtra(dest, q, 1+(rand()%20));

        if (dest.comprimento() > 0) {
            FAIL() << "lista estava vazia, mas filtra copiou alguma coisa ... "
                   << "lista destino ficou assim: "+ltos(dest);
            return;
        }
    } catch (...) {
        FAIL() << "ocorreu uma exceção";
    }
}

TEST_F(TesteQuestao, Normal)
{
    try {
        lista<int> q, dest, aux;

        int maior, limiar;
        maior = gen_lista(q, 0, 50);

        while (true) {
            limiar = rand() % maior;
            meu_filtra(aux, q, limiar);
            if (aux.comprimento() < q.comprimento()) break;
            aux.esvazia();
        }

        filtra(dest, q, limiar);

        if (dest.comprimento() != aux.comprimento()) {
            FAIL() << "lista filtrada tem "+to_string(dest.comprimento())+" números, mas deveria ter "+to_string(aux.comprimento())
             << ", limiar: "+to_string(limiar)
             << ", lista original: "+ltos(q)
             << ", lista obtida com filtragem: "+ltos(dest)
             << ", lista esperada: "+ltos(aux);
            return;
        }

        if (not (dest == aux)) {
            FAIL() << "lista filtrada diferente do esperado"
             << ", limiar: "+to_string(limiar)
             << ", lista original: "+ltos(q)
             << ", lista obtida com filtragem: "+ltos(dest)
             << ", lista esperada: "+ltos(aux);
            return;

        }
    } catch (...) {
        FAIL() << "ocorreu uma exceção";
    }
}

TEST_F(TesteQuestao, Nenhum) {
    try {
        lista<int> q, dest;

        int maior = gen_lista(q, 0, 30);
        int limiar = 30 + (rand()% 20);
        filtra(dest, q, limiar);

        if (dest.comprimento() > 0) {
            FAIL() << "lista filtrada deveria estar vazia, mas tem "+to_string(dest.comprimento())+" números"
             << "limiar: "+to_string(limiar)
             << "lista original: "+ltos(q);
            return;
        }
    } catch (...) {
        FAIL() << "ocorreu uma exceção";
    }
}

TEST_F(TesteQuestao, Todos) {
    try {
        lista<int> q, dest;

        int maior = gen_lista(q, 15, 55);
        int limiar = 11;
        filtra(dest, q, limiar);

        if (not (dest == q)) {
            FAIL() << "lista filtrada deveria ser idêntica à lista original"
            << "limiar: "+to_string(limiar)
            << "lista original: "+ltos(q)
            << "lista obtida com filtragem: "+ltos(dest);
            return;
        }
    } catch (...) {
        FAIL() << "ocorreu uma exceção";
    }
}