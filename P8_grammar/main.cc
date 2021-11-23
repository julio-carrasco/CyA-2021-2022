// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

// Programa simula una gramatica
// Se le pasan 3 argumentos, la codificacion de la gramatica
// El proceso de derivacion y un fichero de salida
// El programa sigue el proceso de derivacion hasta producir una salida generada
// por la gramatica

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "alfabeto.h"
#include "grammar.h"

void Help(int, char**);

int main(int argc, char* argv[]) {
  Help(argc, argv);
  std::string input_grammar = argv[1];
  std::string input_derivations = argv[2];
  std::string output = argv[3];
  Grammar cfg(input_grammar);
  std::ofstream outfile(output);
  outfile << cfg.Transition(input_derivations);
  outfile.close();

  return 0;
}

// Funcion escribe por pantalla como es el uso correcto del programa
void Help(int argc, char* argv[]) {
  std::string help = "--help";
  std::string parameter;
  const std::string grammar = ".cfg";
  const std::string productions = ".drv";
  const std::string output = ".txt";
  if (argc == 2 && (argv[1] == help)) {
    std::cerr << "El programa se encarga de simular una gramatica y es capaz "
                 "de producir una cadena que pertenece al lenguaje definido "
                 "por esa gramatica"
              << std::endl;
    std::cerr << "El primer parametro debe ser un archivo .cfg que contenga la "
                 "codificacion de la gramatica"
              << std::endl;
    std::cerr << "Como segundo parametro se debe introducir un archivo .drv "
                 "que contenga las derivaciones necesarias para llegar a la "
                 "cadena final"
              << std::endl;
    std::cerr << "Como tercer parametro se debe introducir un fichero .txt que "
                 "contendra las derivaciones paso a paso hasta llegar al "
                 "momento en el que queden solo simbolos terminales"
              << std::endl;
    exit(1);
  }

  if (argc != 4) {
    std::cerr << "Modo de empleo: ./main [input.cfg] [input.drv] [output "
                 "file.txt]"
              << std::endl;
    std::cerr << "Escriba --help para mas informacion" << std::endl;
    exit(1);
  }
  parameter = argv[1];
  std::size_t found = parameter.find(grammar);
  if (found == std::string::npos) {
    std::cerr << "Primer parametro debe ser el archivo .cfg que contiene la "
                 "codificacion de la gramatica"
              << std::endl;
    exit(1);
  }
  parameter = argv[2];
  std::size_t found2 = parameter.find(productions);
  if (found2 == std::string::npos) {
    std::cerr << "Segundo parametro debe ser el archivo .drv que contiene el "
                 "proceso de derivacion"
              << std::endl;
    exit(1);
  }
  parameter = argv[3];
  std::size_t found3 = parameter.find(output);
  if (found3 == std::string::npos) {
    std::cerr << "Tercer parametro debe ser el archivo .txt que contendra la "
                 "salida de la derivacion"
              << std::endl;
    exit(1);
  }
}