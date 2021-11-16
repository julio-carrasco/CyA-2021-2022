// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es
// El programa se encarga de simular un NFA e indica si las cadenas
// administradas son aceptadas o no

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <regex>

#include "alfabeto.h"

// Clase que define un NFA, en esta clase se almacenan los estados del NFA en un
// contenedor de clase map

class Nfa {
 private:
  int actual_state_;
  int start_state_;
  std::map<int, std::multimap<std::string, int>> states_;
  std::vector<int> final_states_;
  bool correct_construct_;
  Alfabeto sigma_;

 public:

  Nfa(const int, const int, const std::vector<std::string> &);
  std::string Transition(const std::string &);
  void Print_Info();
  bool Is_Correct();
  std::string Output(const std::string &, const int);
};