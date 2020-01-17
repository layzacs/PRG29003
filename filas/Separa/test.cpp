//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <prglib.h>
#include "fila_substrings.h"
#include "gtest/gtest.h"

using std::string;
using std::to_string;
using prglib::fila;

static const char SEP[] = ",.;:/|-&%$+=*?";

class TesteEnfileira: public ::testing::Test {
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

    char gen_string(string & s, fila<string> & q) {
        char sep = rand_char();
        string w;

        int j = 2+(rand()%20); // qtde de substrings
        while (j-- > 1) {
            w = gen_word();
            q.enfileira(w);
            s += w;
            s += sep;
        }
        w = gen_word();
        q.enfileira(w);
        s += w;

        return sep;
    }

    bool compara_filas(fila<string> & q1, fila<string> & q2) {
        int n = q1.comprimento();
        if (n != q2.comprimento()) return false;
        while (n-- > 0) {
            string s1 = q1.desenfileira();
            string s2 = q2.desenfileira();
            if (s1 != s2) return false;
            q1.enfileira(s1);
            q2.enfileira(s2);
        }
        return true;
    }

    string fila2str(fila<string> & q) {
        string r;

        while (! q.vazia()) {
            r += q.desenfileira() + ' ';
        }
        return r;
    }

};

/*::testing::AssertionResult AssertSubstitui(const char* texto_expr,
                                               const char* sub_expr,
                                               const char* outra_expr,
                                               const char* correto_expr,
                                               const string & texto,
                                               const string & sub,
                                               const string & outra,
                                               const string & correto) {
    string res = substitui(texto, sub, outra);
    if (res == correto) return ::testing::AssertionSuccess();

    return ::testing::AssertionFailure() << "texto=" << texto << ", " << sub_expr << "=" << sub << ", " << outra_expr << "=" << outra << ": "
                                         << " resultado deveria ser: " << correto
                                         << ", mas sua função retornou: " << res;
}
*/

TEST_F(TesteEnfileira, Vazia) {
    try {
        fila<string> q(10);
        separa("", rand_char(), q);

        if (q.comprimento() > 0) {
            FAIL() << "fila tem tamanho maior que 0 após enfileirar caracteres de uma string vazia";
        }

    } catch (...) {
        FAIL() << "ocorreu uma exceção";
    }

}

TEST_F(TesteEnfileira, Simples) {
    for (int i=0; i < 10; i++) {
        try {
            fila<string> q(10);
            string w = gen_word();
            char sep = rand_char();
            separa(w, sep, q);

            if (q.comprimento() != 1) {
                FAIL() << "fila tem tamanho " << to_string(q.comprimento()) << ", mas deveria ter comprimento 1";
                return;
            }

        } catch (...) {
            FAIL() << "ocorreu uma exceção";
        }
    }
}

TEST_F(TesteEnfileira, Normal) {
    string s;
    char sep;

    try {
        for (int n=0; n < 10; n++) {
            fila<string> q1(100), q2(100);
            s = "";
            sep = gen_string(s, q1);
            separa(s, sep, q2);

            if (not compara_filas(q1, q2)) {
                FAIL() << "string="+s+" separador="+sep
                       << ", fila esperada: " << fila2str(q1)
                       << ", fila obtida: " << fila2str(q2);
                return;
            }
        }
    } catch (...) {
        string c;
        c += sep;
        FAIL() << "ocorreu uma exceção: string="+s << ">>> sep="+c;
    }
}
