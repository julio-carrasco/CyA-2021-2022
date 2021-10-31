// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

#pragma once

#include <iostream>
#include <string>
#include <set>

// Clase almacena el alfabeto del DFA
class Alfabeto {
 private:
  std::set<std::string> alfabeto_;

 public:
  Alfabeto(std::string);
  std::string get_a(const int) const;
  int get_size() const;
};