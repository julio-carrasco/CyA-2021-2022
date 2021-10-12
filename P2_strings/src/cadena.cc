#include "cadena.h"

// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia

// Constructor de la clase Cadena, crea 2 elementos, cadena_ y order
// cadena_ almacena la cadena introducida
// order es un vector de pares que almacena el simbolo y su posicion en la
// cadena

Cadena::Cadena(std::string chain, Alfabeto const &sigma) {
  // Se crea cadena_
  int position = 0;
  int size = chain.size();
  for (int i = 0; i <= size; i++) {
    if (chain[i] == ' ') {
      position = i + 1;
    }
  }
  cadena_ = chain.substr(position);

  // Se construye el vector de pares order a partir del alfabeto
  const int length = sigma.get_size();
  for (int i = 0; i < length; i++) {
    size_t pos = get_chain().find(sigma.get_a(i), 0);
    while (pos != std::string::npos) {
      order.push_back(std::make_pair(sigma.get_a(i), pos));
      pos = get_chain().find(sigma.get_a(i), pos + 1);
    }
  }

  // Caso de cadena vacia
  if (size == 0) {
    cadena_ = "&";
    order.push_back(std::make_pair("&", 0));
  }
}

// Funcion devuelve longitud de la cadena basandose en su cantidad de simbolos
int Cadena::Longitud() {
  if (!Is_Correct()) {
    return -1;
  }
  if (cadena_ == "&") {
    return 0;
  }
  return cadena_.size();
}

// Funcion ordena al reves los simbolos de la cadena introducida
std::string Cadena::Inversa() {
  if (!Is_Correct()) {
    return "Cadena no valida";
  }
  std::string out;
  int size = order.size();
  std::sort(order.begin(), order.end(),
            [](auto &left, auto &right) { return left.second > right.second; });
  for (int i = 0; i < size; i++) {
    out = out + order[i].first;
  }
  return out;
}

// Funcion devuelve todos los prefijos de la cadena introducida
std::string Cadena::Prefijos() {
  if (!Is_Correct()) {
    return "Cadena no valida";
  }
  std::string out = "& ";
  int size = cadena_.size();
  if (cadena_ == "&") {
    return out;
  }
  for (int i = 0; i < size; i++) {
    for (int k = 0; k <= i; k++) {
      out = out + cadena_[k];
    }
    out = out + " ";
  }
  return out;
}

// Funcion devuelve todos los sufijos de la cadena introducida
std::string Cadena::Sufijos() {
  if (!Is_Correct()) {
    return "Cadena no valida";
  }
  std::string out = "& ";
  int size = cadena_.size();
  if (cadena_ == "&") {
    return out;
  }
  for (int i = 0; i <= size; i++) {
    for (int k = size - i; k < size; k++) {
      out = out + cadena_[k];
    }
    out = out + " ";
  }
  return out;
}

// Funcion devuelve todas las subcadenas de la cadena introducida
std::string Cadena::Subcadenas() {
  if (!Is_Correct()) {
    return "Cadena no valida";
  }
  std::string out = "& ";
  if (cadena_ == "&") {
    return out;
  }
  int size = cadena_.size();
  for (int i = 1; i <= size; i++) {
    for (int k = 0; k <= size - i; k++) {
      int aux = k + i - 1;
      for (int j = k; j <= aux; j++) {
        out = out + cadena_[j];
      }
      out = out + " ";
    }
  }
  return out;
}

// Getter de cadena_
std::string Cadena::get_chain() { return cadena_; }

// Imprime en pantalla el vector de pares
void Cadena::print_o() {
  int size = order.size();
  std::cout << "size: " << size << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << order[i].first << " " << order[i].second << std::endl;
  }
}

// Funcion comprueba si la cadena introducida se puede formar
// Compara la cadena con el alfabeto que se ha proporcionado
bool Cadena::Is_Correct() {
  bool condition = false;
  int contador = 0;
  int size = order.size();
  int chain = cadena_.size();
  for (int i = 0; i < size; i++) {
    contador = contador + order[i].first.size();
  }
  if (contador == chain) {
    condition = true;
  }
  for(int j = 0; j < size; j++) {
    if("&" == order[j].first) {
      condition = false;
    }
  }
  return condition;
}