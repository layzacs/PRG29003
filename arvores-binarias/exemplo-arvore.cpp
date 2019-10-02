template <typename T> class arvore : private BasicTree{
 public:
  arvore();
  //arvore(const arvore<T> & outra);
  arvore(const T & dado);
  virtual ~arvore();

  // adiciona um dado à árvore
  void adiciona(const T& algo);

  // obtém um dado da árvore
  // se dado existir na arvore, retorna referencia ao dado
  const T& obtem(const T & algo) const;

  // obtém o valor da raiz da árvore
  const T& obtem() const ;

  // enumera os dados in-order, pre-order, post-order e breadth-first
  void listeInOrder(lista<T> & result);
  void listePreOrder(lista<T> & result);
  void listePostOrder(lista<T> & result);
  void listeEmLargura(lista<T> & result);

  // retorna a quantidade de dados na árvore
  unsigned int tamanho() const;

  // retorna a subárvore esquerda
  // apenas endereço, não uma cópia
  arvore<T> * esquerda();

  // retorna a subárvore direita
  // retorna endereço
  arvore<T> * direita();

  // itera a árvore
  void inicia();
  bool fim();
  T& proximo();

  // itera a árvore de forma reversa
  // sempre do mais a direita possivel
  void iniciaPeloFim();
  bool inicio();
  T& anterior();

  // remove um dado
  T remove(const T & algo);

  // retorna o menor dado
  T & obtemMenor() const;

  // retorna o maior dado
  T & obtemMaior() const;

  // copia na lista "result" os dados menores que "algo"
  void obtemMenoresQue(lista<T> & result, const T & algo);

  // copia na lista "result" os dados maiores que "algo"
  void obtemMaioresQue(lista<T> & result, const T & algo);

  // obtém todos valores entre "start" e "end" (inclusive)
  void obtemIntervalo(lista<T> & result, const T & start, const T & end);

  // retorna a altura da folha mais distante da raiz
  unsigned int altura() ;

  // retorna o fator de balanceamento
  int fatorB() ;

  // balanceia a árvore
  arvore<T> * balanceia();

  // balanceia a árvore repetidamente, até que a altura não mais se reduza
  // ex: arvore.balanceia(true);
  arvore<T> * balanceia(bool otimo);
};
