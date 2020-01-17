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

class TesteQuestao: public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
    }
};

TEST_F(TesteQuestao, Vazia) {
    lista<int> l;
    try {
        adiciona_aleatorios(l, 0);
        if (! l.vazia()) {
            FAIL()<<"lista possui " << l.comprimento() << " números, mas deveria estar vazia";
            return;
        }
    } catch (...) {
        FAIL()<<"falha fatal ao adicionar números à lista";
    }
}

TEST_F(TesteQuestao, Simples) {
    lista<int> l;
    try {
        adiciona_aleatorios(l, 1);
        if (l.comprimento() != 1)  {
            FAIL()<<"lista possui " << l.comprimento() << " números, mas deveria ter somente um valor";
            return;
        }
    } catch (...) {
        FAIL()<<"falha fatal ao adicionar números à lista";
    }
}

TEST_F(TesteQuestao, Muitos)
{
    for (int j=10; j > 0; j++) {
        lista<int> l;
        int N = 3 + (rand() % 15);

        try {
            adiciona_aleatorios(l, N);
            if (l.comprimento() != N) {
                FAIL() << "lista possui " << l.comprimento() << " números, mas deveria ter " << N;
                return;
            }
            l.inicia();
            int last = l.proximo();
            while (not l.fim()) {
                int novo = l.proximo();
                if (novo < last) {
                    ostringstream out;

                    l.escrevaSe(out, ",");
                    FAIL() << "números não estão ordenados: " + out.str();
                    return;
                }
                last = novo;
            }
        } catch (...) {
            FAIL() << "falha fatal ao adicionar números à lista";
        }
    }
}