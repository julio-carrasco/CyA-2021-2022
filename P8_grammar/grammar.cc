// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

// Programa simula una gramatica

#include "grammar.h"

// Constructor de la clase Grammar
Grammar::Grammar(const std::string name) {
  std::ifstream infile(name);
  const int terminal_case{0};
  const int non_terminal_case{1};
  int counter{0};
  bool new_transition = false;
  std::string line;
  std::string actual;
  std::string prev_node = "";
  std::string aux_prod = "";
  int size;
  const int prod_start{5};
  std::vector<std::string> aux_vec;

  // Recorre linea por linea el fichero .cfg
  while (std::getline(infile, line)) {
    switch (counter) {
      case terminal_case:
        terminal_.insert(line);
        counter++;
        break;

      case non_terminal_case:
        start_symbol = line[0];
        non_terminal_.insert(line);
        counter++;
        break;

      default:
        actual = line[0];
        if (prev_node != actual) {
          productions.insert(make_pair(prev_node, aux_vec));
          aux_vec.clear();
          prev_node = actual;
        }
        size = line.size();
        for (int i = prod_start; i < size; i++) {
          aux_prod = aux_prod + line[i];
        }
        aux_vec.emplace_back(aux_prod);
        aux_prod = "";
        break;
    }
  }
  productions.insert(make_pair(prev_node, aux_vec));
  infile.close();
}

// Funcion que se encarga de realizar las derivaciones especificadas por el
// fichero .drv y devuelve el proceso en una string
std::string Grammar::Transition(const std::string instructions) {
  std::ifstream infile(instructions);
  std::string line;
  std::string actual;
  std::string product = start_symbol;
  std::string aux;
  std::string copy;
  std::string out = start_symbol;
  const std::string arrow = " => ";
  const std::string jump = "\n";
  int size;
  int key = 0;
  const int non_terminal_pos{0};
  const int key_pos{3};
  bool sustituted = false;
  // Se recorre el fichero .drv
  while (std::getline(infile, line)) {
    sustituted = false;
    size = product.size();
    actual = line[non_terminal_pos];
    key = line[key_pos] - '0';
    key = key - 1;
    // Se recorre la produccion para encontrar el primer simbolo no terminal
    for (int i = 0; i < size; i++) {
      // Se recorre el set de simbolos no terminales para compararlos con lo que
      // tengamos en la produccion
      for (int j = 0; j < non_terminal_.get_size(); j++) {
        aux = non_terminal_.get_a(j);
        copy = product[i];
        // Si encontramos que coincide reemplazamos el primer elemento no
        // terminal encontrado por su correspondiente produccion
        if (copy == aux) {
          product.replace(i, 1, productions.find(actual)->second[key]);
          sustituted = true;
          break;
        }
      }
      if (sustituted) {
        break;
      }
    }
    out = out + arrow + product + arrow + jump + product;
  }
  infile.close();
  return out;
}

// Funcion que imprime por pantalla informacion sobre el objeto Grammar
void Grammar::print_info() {
  std::cout << "start :" << start_symbol << std::endl;
  for (int i = 0; i < terminal_.get_size(); i++) {
    std::cout << terminal_.get_a(i) << " ";
  }
  std::cout << std::endl;
  for (int j = 0; j < non_terminal_.get_size(); j++) {
    std::cout << non_terminal_.get_a(j) << " ";
  }
  std::cout << std::endl;
  for (auto const &it : productions) {
    std::cout << it.first << ":" << std::endl;
    for (int k = 0; k < it.second.size(); k++) {
      std::cout << it.second[k] << " ";
    }
    std::cout << std::endl;
  }
}