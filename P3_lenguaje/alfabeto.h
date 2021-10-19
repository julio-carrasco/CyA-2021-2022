// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <set>

class Alfabeto {
 private:
  std::set<std::string> alfabeto_;

 public:
  Alfabeto(std::string);
  std::string get_a(const int) const;
  int get_size() const;
};