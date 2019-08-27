# Listas

Uma lista encadeada é uma estrutura de dados em que os dados são armazenados dinamicamente em memória, de forma a se organizarem em uma sequência. Qualquer dado em uma lista pode ser acessado, independente de sua posição, assim como pode ser adicionados ou removidos de uma posição qualquer. Além disso, a ordem dos dados em uma lista pode ser modificada de diferentes maneiras (ordenamento, embaralhamento, inversão, ...). Tudo isso graças à forma com que uma lista encadeia os dados, em que cada dado armazenado possui referências tanto a seu sucessor quanto seu antecessor. Pode-se fazer um paralelo com listas reais, que aparecem em diversas situações do dia-a-dia, como playlists, listas de afazeres, etc.

Do ponto de vista computacional, podem-se citar estas aplicações de listas:

- Armazenar um conjunto de dados cuja quantidade não pode ser conhecida de antemão. Exemplos são resultados de consultas a bancos de dados, listagens de arquivos de um diretório, resultados de separação de string em substrings.
- Armazenar dados cuja ordem em memória é modificada frequentemente. Exemplos são listas de processos em execução mantidas por sistemas operacionais, listas de mensagens a serem transmitidas cuja ordem depende de suas prioridades, listas de tarefas a serem realizadas por um simulador, listas de reprodução em tocadores de músicas.

## A Lista do PRGLIB

![Diagrama de lista PRGLIB](https://wiki.sj.ifsc.edu.br/wiki/images/4/42/Prg2-2016-2-Lista1.jpg)
Uma lista possui algumas características:

- Os dados são armazenados dinamicamente, por isso a quantidade total de memória usada para a lista depende da quantidade de dados nela armazenados (compare isso com um vetor ou matriz).
- A lista não precisa ocupar uma área de memória contígua: como dados são armazenados dinamicamente, eles podem ocupar áreas de memória arbitrárias, e não há nenhuma relação entre a localização dos dados em memória e sua ordem na lista (novamente compare isso com um vetor ou matriz).
- Não é possível indexar os dados, por isso para acessar um dado deve-se obrigatoriamente procurá-lo a partir do início ou fim da lista, seguindo cada sucessor ou antecessor até chegar àquele procurado.
Para adicionar um dado, basta modificar a referência ao sucessor do dado que deve antecedê-lo na lista. Assim, não é necessário "empurrar" os dados seguintes para frente (como seria o caso de um vetor).
- Para remover um dado é a mesma coisa: basta modificar a referência de seu antecessor. Assim, não é necessário "deslocar pra trás" os dados seguintes (como seria o caso de um vetor).

## Operações Elementares

As operações elementares de uma lista definem como dados podem ser adicionados, obtidos e removidos da lista, e também que informações sobre a lista podem ser obtidas. São elas:

- anexa: adiciona um dado ao final da lista
- insere: adiciona um dado em uma determinada posição da lista
- remove: remove um dado de uma determinada posição da lista
- obtem: obtém um dado de uma determinada posição da lista
- comprimento: obtém o comprimento da lista
- esvazia: esvazia a lista (remove todos os dados)
