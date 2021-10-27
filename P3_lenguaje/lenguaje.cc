// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia

#include "lenguaje.h"

// Constructor lenguaje
Lenguaje::Lenguaje() { lenguaje_.reserve(1); }

// Muestra por pantalla el vector lenguaje
void Lenguaje::print_l() {
  int size = lenguaje_.size();
  for (int i = 0; i < size; i++) {
    std::cout << lenguaje_[i] << " ";
  }
  std::cout << std::endl;
}

// Funcion que inserta un elemento en el vector lenguaje
void Lenguaje::insert(const std::string &chain) {
  lenguaje_.emplace_back(chain);
}

// Funcion que devuelve el tamano del vector lenguaje
int Lenguaje::size() { return lenguaje_.size(); }

// Funcion que devuelve elemento [i] del vector lenguaje
std::string Lenguaje::get_l(const int pos) { return lenguaje_[pos]; }

// Sobrecarga operador salida
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