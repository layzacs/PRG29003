# Questão 4

Escreva uma função que testa se um dado talvez exista em uma árvore:

template <typename T> bool testa_se_existe(arvore<T> * raiz, const T & dado);

Se sua função retornar true, o dado talvez exista na árvore (mas pode não existir !). Se retornar false, o dado com certeza não está na árvore.
