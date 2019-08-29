void adiciona_aleatorios(lista<int> & umaLista, int N) {
    lista<int> l;

    srand (time(NULL));

    for (int i=0; i < N; i++) {
        int num = 1 + (rand() % 10);
        if (i=0) {
            umaLista.anexa(num);
        }
        if (i>0 && num > umaLista.obtem(i)) {
          umaLista.anexa(num);
        }
        if (i>0 && num < umaLista.obtem(i)) {
          umaLista.insere(i-1);
        }
    }

}
