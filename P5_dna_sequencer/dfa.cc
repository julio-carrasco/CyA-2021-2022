// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

#include "dfa.h"

#define A 0
#define T 1
#define G 2
#define C 3

// Constructor del DFA, inicializa la tabla transiciones
Dfa::Dfa() {
  // Se incializa tabla de transiciones del DFA
  // Tiene 6 estados y 4 posibles valores de entrada
  // 2 estados son de aceptacion
  //            A  T  G  C
  states_[0] = {1, 3, 4, 4};
  states_[1] = {2, 1, 1, 1};
  states_[2] = {2, 1, 1, 1};
  states_[3] = {3, 5, 3, 3};
  states_[4] = {4, 4, 4, 4};
  states_[5] = {3, 5, 3, 3};

  actual_state_ = 0;
  // Estados de aceptacion
  final_states_ = {2, 5};
}

// Funcion que realiza la transicion de estados segun el DFA para cada cadena
// que le llega
// Funcion recibe un vector de strings que contiene todas las subacenas de lo
// introducido por teclado
// Utiliza un switch para hacer la transicion segun le llega A T G C que
// corresponde con una posicion en la array de transiciones
// Guarda las strings que terminan en un estado de aceptacion en un vector
void Dfa::Transition(Lenguaje line) {
  int size = line.size();
  int length;
  int final_size = final_states_.size();
  std::string aux;
  int input;
  std::string error = "Cadena no valida";
  const char kFirst = 'A';
  const char kSecond = 'T';
  const char kThird = 'G';
  const char kFourth = 'C';
  // Itera el vector de entrada para ir string por string
  for (int i = 0; i < size; i++) {
    aux = line.get_l(i);
    length = aux.size();
    actual_state_ = 0;
    // Itera cada elemento de la string y realiza la transicion al proximo
    // estado
    for (int j = 0; j < length; j++) {
      switch (aux[j]) {
        case kFirst:
          input = A;
          break;

        case kSecond:
          input = T;
          break;

        case kThird:
          input = G;
          break;

        case kFourth:
          input = C;
          break;
      }
      actual_state_ = states_[actual_state_][input];
    }
    // Iterar en el vector de estados aceptados para comprobar
    // que estado actual corresponde a estado de aceptacion
    for (int k = 0; k < final_size; k++) {
      if (actual_state_ == final_states_[k]) {
        accepted_.emplace_back(aux);
      }
    }
    if (aux == error) {
      accepted_.emplace_back(error);
    }
  }
  // Elimina elementos duplicados del vector
  auto end = accepted_.end();
  for (auto it = accepted_.begin(); it != end; ++it) {
    end = std::remove(it + 1, end, *it);
  }
  accepted_.erase(end, accepted_.end());
}

// Funcion se encarga de imprimir los valores del vector accepted_
// En ese vector se encuentran las cadenas aceptadas
std::string Dfa::print_accepted() {
  std::string out = "";
  std::string endl = "\n";
  int size = accepted_.size();
  for (int i = 0; i < size; i++) {
    out = out + accepted_[i] + endl;
  }
  return out;
}
