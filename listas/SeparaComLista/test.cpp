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

const char SEP[] = ",.;:/|-&%$+=*?";

class TesteQuestao: public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
    }
    string gen_word() {
        string s;
        int n;

        n = 2 + (rand() % 32);
        while (n-- > 0) s += (char)('a'+(rand() % 26));
        return s;

    }

    char rand_char() {
        return SEP[rand()%(sizeof(SEP)-1)];
    }

    string gen_sep(int lensep) {
        string sep;
        while (lensep > 0) {
            char c = rand_char();
            if (sep.find(c) == string::npos) {
                sep += c;
                lensep--;
            }
        }
        return sep;
    }

    string gen_string(string & s, lista<string> & q, int lensep) {
        string sep = gen_sep(lensep);
        string w;

        int j = 2+(rand()%20); // qtde de substrings
        while (j-- > 1) {
            w = gen_word();
            q.anexa(w);
            s += w;
            s += sep;
        }
        w = gen_word();
        q.anexa(w);
        s += w;

        return sep;
    }

    bool compara_listas(lista<string> & q1, lista<string> & q2) {
        int n = q1.comprimento();
        if (n != q2.comprimento()) return false;
        q1.inicia();
        q2.inicia();
        while (not q1.fim()) {
            if (q1.proximo() != q2.proximo()) return false;
        }
        return true;
    }

    void teste(int lensep)
    {
        string s;
        string sep;

        try {
            for (int n=0; n < 10; n++) {
                lista<string> q1, q2;
                s = "";
                sep = gen_string(s, q1, lensep);
                q2 = separa(s, sep);

                if (not compara_listas(q1, q2)) {
                    ostringstream o1, o2;

                    q1.escrevaSe(o1, ", ");
                    q2.escrevaSe(o2, ", ");
                    FAIL() << "Após separar: string="+s+" separador="+sep
                    << "Obteve resultado: "+o2.str()
                    << "Esperado: "+o1.str();
                    return;
                }
            }
        } catch (...) {
            FAIL() << "ocorreu uma exceção: string="+s
            << ">>> sep="+sep;
        }
    }

};

TEST_F(TesteQuestao, Vazia)
{
    for (int i=0; i < 10; i++) {
        try {
            lista<string> q;
            q = separa("", gen_sep(4));

            if (q.comprimento() > 0) {
                FAIL() << "lista tem tamanho maior que 0 após enfileirar substrings de uma string vazia";
                return;
            }

        } catch (...) {
            FAIL() << "ocorreu uma exceção";
        }
    }
}

TEST_F(TesteQuestao, Simples)
{
    for (int i=0; i < 10; i++) {
        try {
            lista<string> q;
            string w = gen_word();
            string sep = gen_sep(4);
            q = separa(w, sep);

            if (q.comprimento() != 1) {
                FAIL() << "lista tem tamanho "+to_string(q.comprimento())+", mas deveria ter comprimento 1: string="+w+" separador="+sep;
                return;
            }

        } catch (...) {
            FAIL() << "ocorreu uma exceção";
        }
    }
}

TEST_F(TesteQuestao, Normal) {
    teste(1);
}

TEST_F(TesteQuestao, Multiplo)
{
    teste(2+(rand() % 3));
}

