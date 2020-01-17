# Questão 5

Um mapa de municípios é implementado pela classe Mapa:

```
struct Municipio {
  string nome;
  int distancia;
};
class Mapa {
 public:
  Mapa(const string & arq_dados);

  // obtem municipios limitrofes com respectivas distâncias
  // se "nome_municipio" já foi pesquisado, retorna fila vazia
  fila<Municipio> obtem_vizinhos(const string & nome_municipio);

  // esquece pesquisas anteriores
  void limpa();

  // verifica se cidade é válida
  bool existe(const string & nome);
};

```

Escreva um programa que, usando essa classe Mapa, descubra a menor distância de um município a outro. Os nomes dos municípios são informados como argumentos.

A classe Mapa está declarada em Mapa.h.

O nome do arquivo de dados com as distâncias entre municípios, e que precisa ser  informado ao se usar a classe Mapa, é res.txt (no caso da versão para CLion, o caminho do arquivo é "../data/res.txt").


Dica: isso pode ser resolvido usando um dos dois algoritmos de busca estudados no projeto 1.
