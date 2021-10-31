// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <algorithm>

#include "alfabeto.h"
#include "lenguaje.h"

// Clase que define un DFA, en esta clase se almacenan los estados del DFA con
// sus transiciones
// El alfabeto y la cadena del DFA estan las clases Alfabeto y Cadena
// respectivamente
// En el constructor se inicializa la tabla de transiciones y los estados de
// aceptacion
// Este DFA reconoce si la cadena pertenece al lenguaje representado por A
// (A|T|G|C)* A | T (A|T|G|C)* T
class Dfa {
 private:
  int actual_state_;
  std::array<std::array<int, 4>, 6> states_;
  std::vector<int> final_states_;
  std::vector<std::string> accepted_;

 public:
  Dfa();
  void Transition(Lenguaje);
  std::string print_accepted();
};