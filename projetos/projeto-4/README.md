Fazer uma struct para salvar os verbetes

struct verbete {
  string palavra
  string classe_gramatical
  lista<string> significado
}

função:
// o arquivo é aberto e passado como parâmetro

ifstream arq("verbete.txt");


// a função ifstream já começa a partir do ponto em que o arquivo deixou de ser lido, então ela funcionaria para todo o arquivo
verbete cria_verbete(ifstream &arq) {
  string verbete novo;
  ...

  (se não conseguir nenhum verbete gera exceção);
  return novo;
}

while (true) {
  try {
  verbete verb  = cria_verbete(arq);
  } catch (...) {
    break;
  }
