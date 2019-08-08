#include <string>
#include <iostream>

using namespace std;

// Faz o teste se a letra já foi chutada, se não tiver sido, adiciona ela a string que contém todas as letras chutadas.
int validate_letter(string **tries, char letter) {
  int i;
  int found_letter;
  string aux;
  aux = **tries;
  found_letter = aux.find(letter);

  if (found_letter < 0) {
    aux.append(1, letter);
    cout << "A letra " << letter << " foi adicionada às letras tentadas." << endl;
  }
  else {
    cout << "Você já chutou esta letra!" << endl;
  }
   **tries = aux;
   return 0;
}


string check_letter(string word, string secret, string *tries, char letter) {
  int found, success;
  cout << "A string tries antes: " << *tries << endl;
  validate_letter(&tries, letter);
  cout << "A string tries depois: " << *tries << endl;

  for (success=0;;) {

    found = word.find(letter);
    cout << found << endl;

    if ((found == -1) && (success==0)) {
      //letter_fail();
      break;
    }
    else if (found > -1 && success == 0) {
      cout << "A letra " << letter << " está correta!" << endl;
      success++;
    }
    else if (found > -1 && success >= 0) {
      secret.replace(found, 1, 1, letter);
      word.replace(found, 1, 1, '-');
      cout << word << endl;
      cout << word << endl;
    }
    else if (found == -1 && success > 0) {
      break;
    }
  }
  cout << secret << endl;
  return secret;
}

/*
int checa_letra(string palavra, string letra) {
  int found=0, acertos;
  for (;found < 0;) {
    if (found=0) {
      found = palavra.find(letra);
    }
    if (found>0) {
      found = palavra.find(letra, found+1);
    }

  }
}
*/

string choose_word(string word, string secret) {
  int length, i;
  string temp;

  length = word.length();
  cout << length << endl;

  for (i=0; i<length; i++) {
    secret.replace(i, 1, 1, '-');
  }
  cout << secret << endl;
  return secret;
}




int main(void) {

  string word;             // A string palavra vai ser escolhida aleatóriamente por meio de uma função
  string secret;           // É uma string auxiliar que mostra pro user quais as letras que já foram descobertas.
  string tries;
  char letter;

  cout << "---------- Jogo da forca ------------" << endl;

  cout << "entre com a palavra:" << endl;
  cin >> word;
  secret = choose_word(word, secret);
  cout << secret << endl;

  for (;;) {
    cout << "Escolha a letra:" << endl;
    cin >> letter;
    secret = check_letter(word, secret, &tries, letter);
    cout << secret << endl;
    //check_letter(word, letter, secret);
  }
}
