//
// Created by sobral on 27/07/19.
//
#include <limits.h>
#include <time.h>
#include <string>
#include <algorithm>
#include <ostream>
#include <sstream>
#include <prglib.h>
#include "copia_lista.h"
#include "gtest/gtest.h"

using namespace std;
using prglib::lista;

static const char SEP[] = ",.;:/|-&%$+=*?";

class TesteCopia: public ::testing::Test {
protected:
    virtual void SetUp() {
        srand(clock());
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

TEST_F(TesteCopia, Vazia) {
    lista<string> orig, nova;

    try {
        copia_lista(orig, nova);
        if (nova.comprimento() > 0) {
            FAIL() <<"após copiar lista vazia, nova lista ficou com "+to_string(nova.comprimento())+" dados, mas deveria ter 0";
            return;
        }
    } catch (...) {
        FAIL() <<"exceção inesperada ao copiar lista";
    }
}

TEST_F(TesteCopia, Copiar) {
    lista<string> orig, nova;

    nova.anexa("um");
    nova.anexa("dois");
    nova.anexa("tres");
    nova.anexa("quatro");
    lista<string> aux = nova;

    orig.anexa("peniche");
    orig.anexa("matadeiro");
    orig.anexa("tourinho");
    try {
        copia_lista(orig, nova);
        if (nova.comprimento() != aux.comprimento() + orig.comprimento()) {
            FAIL() <<"após cópia lista nova tem comprimento "+to_string(nova.comprimento())+", mas o esperado é "+to_string(aux.comprimento() + orig.comprimento())+", porque lista original tem comprimento "+to_string(orig.comprimento())+" e antes da cópia lista nova tinha comprimento "+to_string(nova.comprimento());
            return;
        }
        nova.iniciaPeloFim();
        orig.iniciaPeloFim();
        while (not orig.inicio()) {
            if (orig.anterior() != nova.anterior()) {
                FAIL() <<"dados copiados para a lista nova não estão na mesma sequência que estavam na lista original";
                return;
            }
        }
    } catch (...) {
        FAIL() <<"exceção inesperada ao copiar lista";
    }
}

TEST_F(TesteCopia, Preservar)        {
    lista<string> orig, nova;

    nova.anexa("um");
    nova.anexa("dois");
    nova.anexa("tres");
    nova.anexa("quatro");

    orig.anexa("peniche");
    orig.anexa("matadeiro");
    orig.anexa("tourinho");
    lista<string> aux = orig;
    try {
        copia_lista(orig, nova);
        if (orig.comprimento() != aux.comprimento()) {
            FAIL() <<"após cópia lista original tem comprimento "+to_string(orig.comprimento())+", mas o esperado é "+to_string(aux.comprimento() + orig.comprimento())+", porque lista original tem comprimento "+to_string(orig.comprimento())+" mas não deveria ter se modificado .. antes tinha "+to_string(aux.comprimento());
            return;
        }
        aux.inicia();
        orig.inicia();
        while (not orig.fim()) {
            if (orig.proximo() != aux.proximo()) {
                FAIL() <<"após cópia lista original foi modificada ... ao menos um de seus dados foi alterado";
                return;
            }
        }
    } catch (...) {
        FAIL() <<"exceção inesperada ao copiar lista";
    }
}

