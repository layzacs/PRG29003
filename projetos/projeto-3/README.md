# Projeto de Estatísticas sobre atores e filmes II

No Projeto 2 escreveu-se um programa que sumariza algumas informações sobre atores e filmes, a partir da leitura de um arquivo de texto contendo uma base de dados sobre filmes e atores. No projeto 3, deve-se reescrever esse programa usando tabela hash. Mais especificamente, o novo programa deve informar o seguinte:

- Os filmes em que um ator atuou
- Os atores que atuaram em todos os filmes de um certo conjunto de filmes
- Os atores que trabalharam com um dado ator
- A listagem ordenada de atores, de acordo com suas popularidades (a popularidade é dada pela quantidade de atores com que um dado ator trabalhou)
- A listagem ordenada de atores, de acordo com a quantidade de filmes em que atuaram
- O programa deve extrair e processar os dados contidos na base de dados de atores e filmes. Esses dados estão contidos em um arquivo de texto, em que cada linha tem este formato:
 
 ```
nome do filme;ano;ator 1,ator 2,ator 3,...,ator N
```

Exemplo:

```
Actrius;1997;Núria Espert,Rosa Maria Sardà,Anna Lizaran,Mercè Pons
```

Seu programa deve apresentar uma interface de usuário orientada a menu. Essa interface deve possibilitar que o usuário selecione uma operação por vez para cada ator sobre o qual deseja obter informações. O usuário deve poder executar mais de uma operação a cada execução do programa. O menu deve possibilitar que o usuário termine o programa.

OBS:

- O processamento das listagens de atores e filmes deve ser feito por meio de tabelas hash. Listas encadeadas podem ser usadas de forma complementar.
- Cada operação deve ser implementada em uma função específica (ou método de uma classe)
- A interface de usuário deve estar desacoplada da funcionalidade de processamento da base de atores e filmes. Isso tem por objetivo modularizar o programa, de forma que a interface de usuário possa ser substituída com mínimas alterações no programa (ex: substituída por uma interface gráfica). Isso significa que:
o código-fonte que implementa a interface de usuário deve estar em um arquivo separado, e as funcionalidades do processamento dos dados de filmes e atores devem estar em outro(s)
deve existir um arquivo com extensão .h que declare as funções (ou classes) que implementam as funcionalidades de processamento de dados de atores e filmes: a interface de usuário deve incluir esse arquivo .h e usar as funções ali declaradas.

## Usando o programa

O programa foi escrito usando a IDE CLion. Não foi criado um executável do mesmo. Para rodá-lo, baixe a pasta contendo o projeto e abra-o com o CLion.
