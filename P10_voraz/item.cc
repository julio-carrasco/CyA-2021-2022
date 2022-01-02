#include "item.h"

// Constructor de clase Item, guarda en una lista varios vectores que contienen
// distintos datos de cada objeto
Item::Item(const std::string& input) {
  std::string line;
  std::ifstream input_list(input);
  int counter = 0;
  float utility = 0;
  float weight = 0;
  float value = 0;
  float used = 0;
  std::smatch matches;
  std::regex exp("([0-9]+) ([0-9]+)");

  while (std::getline(input_list, line)) {
    switch (counter) {
      case 0:
        amount_ = stoi(line);
        break;
      default:
        if (regex_search(line, matches, exp)) {
          int iteracion = 0;
          for (auto match : matches) {
            switch (iteracion) {
              case 1:
                weight = stoi(match);
                break;
              case 2:
                value = stoi(match);

                break;
            }
            iteracion++;
          }
        }
        break;
    }
    // Elementos del vector representan atributos de cada objeto, en orden
    // siendo peso, valor, utilidad y un valor auxiliar
    if (counter > 0) {
      std::vector<float> aux;
      aux.emplace_back(weight);
      aux.emplace_back(value);
      utility = value / weight;
      aux.emplace_back(utility);
      aux.emplace_back(used);
      item_list_.emplace_back(aux);
    }
    counter++;
  }
  input_list.close();
  if (amount_ != item_list_.size()) {
    std::cerr << "Ha habido un error, la cantidad de items indicada no "
                 "coincide con los declarados"
              << std::endl;
    exit(1);
  }
}

// Devuelve tamaño de lista
int Item::Size() const { return amount_; }

// Devuelve iterador al comienzo de la lista
std::list<std::vector<float>>::iterator Item::Begin() {
  return item_list_.begin();
}

// Devuelve iterador al final de la lista
std::list<std::vector<float>>::iterator Item::End() { return item_list_.end(); }
