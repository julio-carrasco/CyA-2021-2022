// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia

#include "lenguaje.h"

Lenguaje::Lenguaje() { lenguaje_.reserve(1); }

void Lenguaje::print_l() {
  int size = lenguaje_.size();
  for (int i = 0; i < size; i++) {
    std::cout << lenguaje_[i] << " ";
  }
  std::cout << std::endl;
}

void Lenguaje::insert(const std::string &chain) {
  lenguaje_.emplace_back(chain);
}

int Lenguaje::size() { return lenguaje_.size(); }

std::string Lenguaje::get_l(const int pos) { return lenguaje_[pos]; }

std::ostream &operator<<(std::ostream &out, const Lenguaje &lenguaje) {
  int size = lenguaje.lenguaje_.size();
  std::string aux;
  std::string error = "Cadena no valida";
  if (lenguaje.lenguaje_[0] == error) {
    out << error;
    return out;
  }
  out << "{";
  for (int i = 0; i < size; i++) {
    aux = lenguaje.lenguaje_[i];
    if (i + 1 != size) {
      out << lenguaje.lenguaje_[i] << ", ";
    } else {
      out << lenguaje.lenguaje_[i];
    }
  }
  out << "}";
  return out;
}