# Pilhas

https://wiki.sj.ifsc.edu.br/wiki/index.php/PRG29003:_Introdu%C3%A7%C3%A3o_a_Pilhas

Pilhas são estruturas de dados lineares, em que os dados são retirados em ordem inversa a que foram inseridos. Esse comportamento é denominado LIFO (Last In First Out - último a entrar, primeiro a sair).


Pilhas apresentam três operações típicas:
* Push: empilha um novo dado (acrescenta-o ao topo da pilha).
* Pop: desempilha um dado (retira-o do topo da pilha)
* Top: acessa o dado do topo da pilha (sem retirá-lo)

![Pilhas](https://wiki.sj.ifsc.edu.br/wiki/images/9/9b/Prg-pilha.jpg)


Algumas aplicações de pilhas são:

* Cálculo de expressões em diferentes representações (infix, postfix, prefix)
* Balanceamento de símbolos em expressões, tais como parênteses, chaves e outros.
* Operações como refazer ou desfazer em editores e outros programas
Avançar e recuar entre páginas visitadas em navegadores web
* Usada em muitos algoritmos, tais como travessias de árvores (usada, por exemplo, em procura de arquivos em diretórios), resolução de labirintos, resolvedor de sudoku, problema do período de preços de ações

A declaração da Pilha na biblioteca Prglib é esta:

```
template <typename T> class pilha {
 public:
  // construtor: deve-se informar a capacidade da pilha
  pilha(unsigned int umaCapacidade);

  // construtor de cópia: cria uma pilha que é cópia de outra
  pilha(const pilha<T>& outra);

  // destrutor da pilha
  ~pilha();

  // operador de atribuição: torna esta pilha uma cópia de outra pilha
  pilha<T> & operator=(const pilha<T> & outra);

  // operações da pilha

  virtual void push(const T & dado); // empilha um dado

  T pop(); // desempilha um dado

  virtual const T& top() const; // retorna o dado do topo da pilha, sem retirá-lo

  bool vazia() const;
  bool cheia() const;
  unsigned int comprimento() const;
  void esvazia();
  unsigned int capacidade() const;

 private:
  unsigned int N;
};
```
