template <typename T> class thash {
 public:
  // cria uma tabela hash com num_linhas linhas
  // OBS: idealmente num_linhas deve ser um número primo !
  thash(int num_linhas);

  thash(const thash &outra); // construtor de copia

  // destrutor
  ~thash();

  // adiciona um dado à tabela. Se já existir na tabela um par contendo a chave
  // "chave", o dado desse par deve ser substituído por "algo". Caso contrário,
  // um novo par deve ser adicionado à tabela.
  void adiciona(const string& chave, const T& algo);

  // remove a chave "chave" e o dado a ela associado.
  T remove(const string& chave);

  // retorna o dado associado a "chave"
  T& operator[](const string& chave);
  T& obtem(const string& chave);

  // retorna uma lista com as chaves existentes na tabela
  shared_ptr<lista<string>> chaves() const;

  // retorna uma lista com os dados existentes na tabela
  shared_ptr<lista<T>> valores() const;

  // retorna verdadeiro se "chave" existe na tabela
  bool existe(const string& chave) const;

  // esvazia a tabela
  void esvazia();

  // retorna a quantidade de dados (ou chaves) existentes na tabela
  unsigned int tamanho() const;

};
