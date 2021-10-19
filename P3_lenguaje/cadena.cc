// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia

#include "cadena.h"

#define EMPTY "&"
#define SPACER " "
// Constructor de la clase Cadena, crea 2 elementos, cadena_ y order_
// cadena_ almacena la cadena introducida
// order_ es un vector de pares que almacena el simbolo y su posicion en la
// cadena

Cadena::Cadena(std::string chain, Alfabeto const& sigma) {
  // Se crea cadena_
  int position = 0;
  int size = chain.size();
  for (int i = 0; i <= size; i++) {
    if (chain[i] == ' ') {
      position = i + 1;
    }
  }
  cadena_ = chain.substr(position);

  // Se construye el vector de pares order_ a partir del alfabeto
  const int length = sigma.get_size();
  for (int i = 0; i < length; i++) {
    size_t pos = get_chain().find(sigma.get_a(i), 0);
    while (pos != std::string::npos) {
      order_.push_back(std::make_pair(sigma.get_a(i), pos));
      pos = get_chain().find(sigma.get_a(i), pos + 1);
    }
  }
  // Caso de cadena vacia
  if (cadena_ == EMPTY) {
    order_.push_back(std::make_pair(EMPTY, 0));
  }
}

// Funcion devuelve longitud de la cadena basandose en su cantidad de simbolos
int Cadena::Longitud() {
  if (!Is_Correct()) {
    return -1;
  }
  int size = 0;
  int length = order_.size();
  for (int i = 0; i < length; i++) {
    if (order_[i].first != EMPTY) {
      size++;
    }
  }
  return size;
}

// Funcion ordena al reves los simbolos de la cadena introducida
std::string Cadena::Inversa() {
  if (!Is_Correct()) {
    return "Cadena no valida";
  }
  std::string out;
  int size = order_.size();

  std::sort(order_.begin(), order_.end(),
            [](auto& left, auto& right) { return left.second > right.second; });

  for (int i = 0; i < size; i++) {
    out = out + order_[i].first;
  }
  return out;
}

// Funcion devuelve todos los prefijos de la cadena introducida
Lenguaje Cadena::Prefijos() {
  Lenguaje lenguaje;
  if (!Is_Correct()) {
    std::string error = "Cadena no valida";
    lenguaje.insert(error);
    return lenguaje;
  }
  std::string aux = EMPTY;
  int size = cadena_.size();
  if (cadena_ != EMPTY) {
    lenguaje.insert(aux);
  }

  for (int i = 0; i < size; i++) {
    aux = "";
    for (int k = 0; k <= i; k++) {
      aux = aux + cadena_[k];
    }
    lenguaje.insert(aux);
  }
  return lenguaje;
}

// Funcion devuelve todos los sufijos de la cadena introducida
Lenguaje Cadena::Sufijos() {
  Lenguaje lenguaje;
  if (!Is_Correct()) {
    std::string error = "Cadena no valida";
    lenguaje.insert(error);
    return lenguaje;
  }
  std::string aux = EMPTY;
  int size = cadena_.size();
  if (cadena_ != EMPTY) {
    lenguaje.insert(aux);
  }
  for (int i = 1; i <= size; i++) {
    aux = "";
    for (int k = size - i; k < size; k++) {
      aux = aux + cadena_[k];
    }
    lenguaje.insert(aux);
  }
  return lenguaje;
}

// Funcion devuelve todas las subcadenas de la cadena introducida
Lenguaje Cadena::Subcadenas() {
  Lenguaje lenguaje;
  if (!Is_Correct()) {
    std::string error = "Cadena no valida";
    lenguaje.insert(error);
    return lenguaje;
  }
  std::string out = EMPTY;
  if (cadena_ != EMPTY) {
    lenguaje.insert(out);
  }
  int size = cadena_.size();
  for (int i = 1; i <= size; i++) {
    for (int k = 0; k <= size - i; k++) {
      int aux = k + i - 1;
      out = "";
      for (int j = k; j <= aux; j++) {
        out = out + cadena_[j];
      }
      lenguaje.insert(out);
    }
  }
  return lenguaje;
}

// Getter de cadena_
std::string Cadena::get_chain() const { return cadena_; }

// Imprime en pantalla el vector de pares
void Cadena::print_o() {
  int size = order_.size();
  std::cout << "size: " << size << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << order_[i].first << " " << order_[i].second << std::endl;
  }
}

// Funcion comprueba si la cadena introducida se puede formar
// Compara la cadena con el alfabeto que se ha proporcionado
bool Cadena::Is_Correct() {
  bool condition = false;
  int contador = 0;
  int size = order_.size();
  int chain = cadena_.size();
  for (int i = 0; i < size; i++) {
    contador = contador + order_[i].first.size();
  }
  if (contador == chain || cadena_ == EMPTY) {
    condition = true;
  }
  return condition;
}

// Funcion compara la cadena introducida por el fichero de texto con la
// introducida por teclado
// Devolvera cadena operador_logico teclado dependiendo de la relacion entre las
// dos
std::string Cadena::Comparacion(std::string aux) {
  if (!Is_Correct()) {
    return "Cadena no valida";
  }
  Alfabeto sigma(aux);
  Cadena aux_chain(aux, sigma);

  std::string equal = " == ";
  std::string not_equal = " != ";
  std::string small = " < ";
  std::string big = " > ";
  std::string out = get_chain();
  if (*this == aux_chain) {
    return out + equal + aux;
  }
  if (*this > aux_chain) {
    return out + big + aux;
  }
  if (*this < aux_chain) {
    return out + small + aux;
  }
  return out + not_equal + aux;
}

// Funcion devuelve la concatenacion de la cadena del txt con la introducida por
// le teclado
std::string Cadena::Concatenacion(std::string aux) {
  if (!Is_Correct()) {
    return "Cadena no valida";
  }
  std::string out;
  out = get_chain() + aux;
  return out;
}

// Funcion devuelve la potencia de la cadena del txt
std::string Cadena::Potencia(const int num) {
  if (!Is_Correct()) {
    return "Cadena no valida";
  }
  std::string out = get_chain();
  if (num == 0) {
    out = EMPTY;
    return out;
  }
  for (int i = 1; i < num; i++) {
    out = out + out;
  }
  return out;
}

// Sobrecarga operador ==, comprueba si cadenas son iguales
bool operator==(const Cadena& chain1, const Cadena& chain2) {
  bool condition = false;
  size_t pos = chain1.get_chain().find(chain2.get_chain());
  int size = chain1.get_chain().size();
  int aux_size = chain2.get_chain().size();
  if (pos != std::string::npos && size == aux_size) {
    condition = true;
  }
  return condition;
}

// Sobrecarga operador <, comprueba si la cadena del txt es subcadena de la
// introducida por teclado
bool operator<(const Cadena& chain1, const Cadena& chain2) {
  bool condition = false;
  size_t pos = chain2.get_chain().find(chain1.get_chain());
  int size = chain1.get_chain().size();
  int aux_size = chain2.get_chain().size();
  if (pos != std::string::npos && size < aux_size) {
    condition = true;
  }
  return condition;
}

// Sobrecarga operador >, comprueba si cadena introducida por teclado es
// subcadena de la del txt
bool operator>(const Cadena& chain1, const Cadena& chain2) {
  bool condition = false;
  size_t pos = chain1.get_chain().find(chain2.get_chain());
  int size = chain1.get_chain().size();
  int aux_size = chain2.get_chain().size();
  if (pos != std::string::npos && size > aux_size) {
    condition = true;
  }
  return condition;
}