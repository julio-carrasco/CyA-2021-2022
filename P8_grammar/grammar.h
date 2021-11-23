// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

// Programa simula una gramatica

#pragma once

#include <iostream>
#include <map>
#include <vector>
#include <fstream>

#include "alfabeto.h"

// Clase almacena la gramatica, tiene 2 set de simbolos, terminales y no
// terminales, tiene simbolo de inicio y todas sus producciones
class Grammar {
 private:
  Alfabeto terminal_;
  Alfabeto non_terminal_;
  std::string start_symbol;
  std::map<std::string, std::vector<std::string>> productions;

 public:
  Grammar(const std::string);
  std::string Transition(const std::string);
  void print_info();
};