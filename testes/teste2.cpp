// https://moodle.sj.ifsc.edu.br/mod/vpl/view.php?id=5812
#include <stdlib.h>
#include <string>
#include <prglib.h>

using namespace std;
using prglib::fila;


int main() {

  fila<string> q(1000);


  while (true) {
    string cmd;
    cout << "Digite o comando: "; // prompt
    getline(cin, cmd);
    if (cmd.empty()) {
      break;
    }
    q.enfileira(cmd);
  }

  while (! q.vazia()) {
    string cmd = q.desenfileira();
    system(cmd.c_str());
  }
}
