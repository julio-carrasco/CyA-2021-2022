// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

// El programa se encarga de simular un DFA e indica si las cadenas
// administradas son aceptadas o no
// Se le deben pasar 3 argumentos el primero siendo la definicion del NFA, luego
// un fichero con las cadenas de entrada y un fichero donde almacenar la salida

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "alfabeto.h"
#include "nfa.h"

void Help(int, char**);

int main(int argc, char* argv[]) {
  Help(argc, argv);
  std::string in_nfa = argv[1];
  std::string input = argv[2];
  std::string output = argv[3];
  std::ifstream input_nfa(in_nfa);
  int number_states;
  int initial_state;
  int counter{0};
  const int number_states_case{0};
  const int initil_state_case{1};
  std::vector<std::string> states;
  std::string line;

  while (std::getline(input_nfa, line)) {
    switch (counter) {
      case number_states_case:
        number_states = stoi(line);
        break;
      case initil_state_case:
        initial_state = stoi(line);
        break;
      default:
        states.emplace_back(line);
        break;
    }
    counter++;
  }
  Nfa nfa(number_states, initial_state, states);
  input_nfa.close();
  if (!nfa.Is_Correct()) {
    std::cerr << "El NFA introducido no es correcto" << std::endl;
    exit(1);
  }
  std::ifstream infile(input);
  std::ofstream outfile(output);
  while (std::getline(infile, line)) {
    outfile << nfa.Transition(line);
  }
  infile.close();
  outfile.close();
  return 0;
}

// Funcion escribe por pantalla como es el uso correcto del programa
void Help(int argc, char* argv[]) {
  std::string help = "--help";
  if (argc == 2 && (argv[1] == help)) {
    std::cerr << "El programa se encarga de simular un nfa introducido en un "
                 "fichero de texto que debe ser el primer argumento"
              << std::endl;
    std::cerr << "Como segundo argumento se debe introducir un fichero de "
                 "texto que contenga las cadenas a evaluar"
              << std::endl;
    std::cerr << "Como tercer argumento se debe introducir el nombre del "
                 "fichero de texto de salida en el cual se escribiran las "
                 "cadenas y si han sido aceptadas o no"
              << std::endl;
    exit(1);
  }

  if (argc != 4) {
    std::cerr << "Modo de empleo: ./main [input.nfa] [input file.txt] [output "
                 "file.txt]"
              << std::endl;
    std::cerr << "Escriba --help para mas informacion" << std::endl;
    exit(1);
  }
}