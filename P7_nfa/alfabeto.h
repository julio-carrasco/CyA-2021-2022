// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es
// El programa se encarga de simular un DFA e indica si las cadenas
// administradas son aceptadas o no

#pragma once

#include <iostream>
#include <string>
#include <set>

// Clase almacena el alfabeto del DFA
class Alfabeto {
 private:
  // Un set de strings que se encarga de almacenar los simbolos del dfa
  std::set<std::string> alfabeto_;

 public:
  // Constructor de Alfabeto a partir de la linea que se obtiene por teclado
  // Se almacenan los simbolos en un vector de strings llamado alfabeto_
  Alfabeto();

  // Funcion permite la insercion de caracteres unicos en el alfabeto, acepta
  // una
  // string
  void insert(std::string);

  // Getter de alfabeto_
  std::string get_a(const int) const;

  // Geter del tamaño del set de alfabeto
  int get_size() const;
};