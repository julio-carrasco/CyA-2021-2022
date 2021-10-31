// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

#pragma once

#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

#include "alfabeto.h"
#include "lenguaje.h"

// Clase almacena la cadena introducida por teclado
class Cadena {
 private:
  std::string cadena_;
  std::vector<std::pair<std::string, int>> order_;
  bool Is_Correct();

 public:
  Cadena(std::string, const Alfabeto &);
  int Longitud();
  std::string Inversa();
  Lenguaje Prefijos();
  Lenguaje Sufijos();
  Lenguaje Subcadenas();
  std::string Comparacion(std::string);
  std::string Concatenacion(std::string);
  std::string Potencia(const int);
  std::string get_chain() const;

  void print_o();

  friend bool operator==(const Cadena &, const Cadena &);
  friend bool operator<(const Cadena &, const Cadena &);
  friend bool operator>(const Cadena &, const Cadena &);
};
