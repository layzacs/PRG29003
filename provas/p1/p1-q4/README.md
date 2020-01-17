# Questão 4

Seja um arquivo com listagem de filmes e respectivos atores.  Cada linha do arquivo contém o nome do filme, o ano em que foi realizado, e a lista de atores separados vírgulas. Um exemplo de uma linha do arquivo é mostrada a seguir:

Actrius;1997;Núria Espert,Rosa Maria Sardà,Anna Lizaran,Mercè Pons
Escreva uma função que gere uma lista contendo todos os filmes em que um determinado ator atuou.


lista<string> lista_filmes(const string & nome_arquivo, const string & nome_ator);

O nome do arquivo de filmes é "filmes.txt" (mas na versão pro CLion o caminho desse arquivo é "../data/filmes.txt").
