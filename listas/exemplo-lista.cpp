#ifndef LISTA_H
#define	LISTA_H

#include <cstddef>
#include <ostream>
#include <string>
#include <list>
#include <algorithm>
#include <random>

using std::shared_ptr;

namespace prglib {

template <typename T> class lista {

 public:
  //construtor: não precisa de parâmetros para criar uma nova lista
  lista();

  // construtor de cópia
  lista(const lista &outra);

  // destrutor
  virtual ~lista();

  // insere "algo" no inicio da lista
  void insere(const T & algo);

  // adiciona "algo" no final da lista
  void anexa(const T & algo);

  // insere "algo" em uma posição específica da lista
  void insere(const T & algo, int posicao);
  void insereOrdenado(const T & algo);

  // remove o dado que está na "posicao" na lista, e retorna
  // uma cópia desse dado
  virtual T remove(int posicao);

  // remove todos os dados que forem equivalentes a "algo"
  void retira(const T & algo);

  // estas duas operações são idênticas: retorna
  // uma referência ao dado que está na "posicao" na lista
  T& obtem(int posicao) const;
  T& operator[](int pos) const;

  // atribuição: torna esta lista idêntica à outra lista
  virtual lista& operator=(const lista<T> & outra);

  // compara duas listas: são iguais se tiverem mesmo comprimento
  // E todos os dados armazenados forem iguais e na mesma ordem
  bool operator==(const lista<T> & outra) const;

  // Retorna uma referência a um dado que seja equivalente a "algo"
  T& procura(const T &algo) const;

  // Procura todos os dados equivalentes a "algo", e os
  // anexa a "lista". Retorna uma referência a "lista".
  lista<T> & procuraMuitos(const T &algo, lista<T> & lista) const;

  // retorna a quantidade de dados armazenados na lista
  int comprimento() const;

  // retorna true se lista estiver vazia
  bool vazia() const;

  // Esvazia a lista
  void esvazia();

  // apresenta o conteúdo da lista no stream "out"
  void escrevaSe(std::ostream & out) const;
  void escrevaSe(std::ostream & out, const std::string & delim) const;

  // ordena a lista
  void ordena();

  // iteração do início pro fim
  void inicia();
  T & proximo();
  bool fim() const;

  // ... e do fim pro início
  void iniciaPeloFim();
  T & anterior();
  bool inicio() const;

  // inverte a ordem nos nodos na lista
  void inverte();

  // embaralha os dados de uma lista
  void embaralha();

  // obtém uma sublista
  lista<T> * sublista(unsigned int pos1, unsigned int pos2) const;
  lista<T> & sublista(unsigned int pos1, unsigned int pos2, lista<T> & outra) const;
};
