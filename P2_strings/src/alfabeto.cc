#include "alfabeto.h"

// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia

// Constructor de Alfabeto a partir de la linea que se obtiene del txt
// Se almacenan los simbolos en un vector de strings llamado alfabeto_
Alfabeto::Alfabeto(std::string chain) {
  int pos_ini = 0;
  int pos_fin = 0;
  int size = chain.size();
  bool space = false;
  std::string aux;

  for (int i = 0; i <= size; i++) {
    if (chain[i] == ' ') {
      pos_fin = i;
      int counter = 0;
      if (pos_ini < pos_fin) {
        aux = chain.substr(pos_ini, (pos_fin - pos_ini));
        alfabeto_.push_back(aux);
        space = true;
      }
      while (chain[i + counter] == ' ') {
        counter++;
      }
      pos_ini = pos_fin + counter;
    }
  }

  // Casos en los cuales solo se proporcione una palabra
  // Cada simbolo del alfabeto equivale a una letra

  if (space == false) {
    bool condition = false;
    for (int k = 0; k < size; k++) {
      aux = chain[k];
      for (int j = 0; j < get_size(); j++) {
        if (aux == get_a(j)) {
          condition = true;
        }
      }
      if (!condition) {
        alfabeto_.push_back(aux);
      }

      condition = false;
    }
  }
}

// Getter de alfabeto_
std::string Alfabeto::get_a(int pos) const { return alfabeto_[pos]; }

int Alfabeto::get_size() const { return alfabeto_.size(); }