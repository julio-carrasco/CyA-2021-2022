// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia

#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Lenguaje {
 private:
  std::vector<std::string> lenguaje_;

 public:
  Lenguaje();
  void print_l();
  void insert(const std::string &);
  int size();
  std::string get_l(const int);
  friend std::ostream &operator<<(std::ostream &, const Lenguaje &);
};
