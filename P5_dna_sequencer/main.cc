// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "alfabeto.h"
#include "cadena.h"
#include "dfa.h"

using namespace std;

void Help(int, char**);

int main(int argc, char* argv[]) {
  Help(argc, argv);
  string input = argv[1];
  string output = argv[2];
  ofstream outfile(output);
  Alfabeto sigma("ATCG");
  Cadena chain(input, sigma);
  Dfa dfa;
  if (outfile.is_open()) {
    dfa.Transition(chain.Subcadenas());
    outfile << dfa.print_accepted();
  }
  outfile.close();
  return 0;
}

void Help(int argc, char* argv[]) {
  string help = "--help";
  if (argc == 2 && (argv[1] == help)) {
    cerr << "Se debe introducir como primer argumento una cadena formada por A "
            "C T y G."
         << endl;
    cerr << "A continuacion se debe introducir el nombre de un fichero de "
            "texto como salida."
         << endl;
    cerr << "Un ejemplo sería ATGGCTG" << endl;
    cerr << "El programa escribirá en el fichero de salida las subcadenas que "
            "se conformen a la expresion regular:"
         << endl;
    cerr << "A (A|T|G|C)* A | T (A|T|G|C)* T" << endl;
    exit(1);
  }

  if (argc != 3) {
    cerr << "Modo de empleo: ./main [string] [output file]" << endl;
    cerr << "Escriba --help para mas informacion" << endl;
    exit(1);
  }
}