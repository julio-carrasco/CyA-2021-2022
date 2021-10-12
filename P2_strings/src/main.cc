#include <iostream>
#include <fstream>

#include "alfabeto.h"
#include "cadena.h"

// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// Programa lee por un archivo de texto un alfabeto y una cadena y puede
// realizar ciertas operaciones

void Help(int, char**);

using namespace std;

int main(int argc, char* argv[]) {
  Help(argc, argv);
  int opcode = atoi(argv[3]);
  string input = argv[1];
  string output = argv[2];
  string line;
  ifstream infile(input);
  ofstream outfile(output);
  if (infile.is_open()) {
    while (getline(infile, line)) {
      Alfabeto sigma(line);
      Cadena chain(line, sigma);
      switch (opcode) {
        case 1:
          outfile << chain.Longitud() << "\n";
          break;

        case 2:
          outfile << chain.Inversa() << "\n";
          break;

        case 3:
          outfile << chain.Prefijos() << "\n";
          break;

        case 4:
          outfile << chain.Sufijos() << "\n";
          break;

        case 5:
          outfile << chain.Subcadenas() << "\n";
          break;
      }
    }
    infile.close();
  }
  return 0;
}

// Funcion que imprime por pantalla mensajes de ayuda
void Help(int argc, char* argv[]) {
  int opcode = atoi(argv[3]);
  string help = "--help";
  if (argc == 2 && (argv[1] == help) == 0) {
    cerr << "Debes introducir primero el archivo txt del cual se va a leer el "
            "alfabeto y cadena."
         << endl;
    cerr << "A continuacion el txt de salida donde saldra el resultado de la "
            "operacion"
         << endl;
    cerr << "En el opcode debes colocar un numero del 1 al 5" << endl;
    cerr << "1: Longitud de cadena" << endl;
    cerr << "2: Inversa de la cadena" << endl;
    cerr << "3: Prefijos de la cadena" << endl;
    cerr << "4: Sufijos de la cadena" << endl;
    cerr << "5: Subcadenas" << endl;
    cerr << endl
         << "En caso de que la cadena introducida no se pueda formar con el "
            "alfabeto proporcioando se escribira: Cadena no valida o -1";
    exit(1);
  }

  if (argc != 4) {
    cerr << "Se debe introducir input.txt output.txt opcode" << endl;
    cerr << "Escriba --help para mas informacion" << endl;
    exit(1);
  }

  if (opcode != (1 || 2 || 3 || 4 || 5)) {
    cerr << "En el opcode debes colocar un numero del 1 al 5" << endl;
    cerr << "1: Longitud de cadena" << endl;
    cerr << "2: Inversa de la cadena" << endl;
    cerr << "3: Prefijos de la cadena" << endl;
    cerr << "4: Sufijos de la cadena" << endl;
    cerr << "5: Subcadenas" << endl;
    exit(1);
  }
}