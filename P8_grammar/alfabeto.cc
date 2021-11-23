// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

// Programa simula una gramatica

#include "alfabeto.h"

// Constructor de Alfabeto a partir de la linea que se obtiene por teclado
// Se almacenan los simbolos en un vector de strings llamado alfabeto_
Alfabeto::Alfabeto() {
}

// Funcion permite la insercion de caracteres unicos en el alfabeto, acepta una
// string
void Alfabeto::insert(std::string chain) {
  int size = chain.size();
  std::string aux;
  const std::string empty = " ";
  for (int i = 0; i < size; i++) {
    aux = chain[i];
    if(aux != empty) {
      alfabeto_.insert(aux);
    }
    
  }
}

// Getter de alfabeto_
std::string Alfabeto::get_a(const int pos) const {
  std::set<std::string>::iterator it = alfabeto_.begin();
  int counter = 0;
  while (it != alfabeto_.end() && counter < pos) {
    counter++;
    it++;
  }
  return *it;
}

// Geter del tamaño del set de alfabeto
int Alfabeto::get_size() const { return alfabeto_.size(); }
