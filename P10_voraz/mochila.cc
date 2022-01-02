#include "mochila.h"

// Constructor de clase Mochila
Mochila::Mochila(float weight) {
  max_weight_ = weight;
  actual_weight_ = 0;
  benefit_ = 0;
};

// Funcion que introduce objetos en la mochila, los objetos son unicos y se
// pueden introducir fracciones de ellos mismos
void Mochila::Insert_items(Item& item_list) {
  float max_utility = 0;
  float fraction = 0;
  int object_number = 1;
  auto pos = item_list.Begin();
  const int weight_index = 0;
  const int value_index = 1;
  const int utility_index = 2;
  const int used_index = 3;
  const float zero = 0;
  // Se repite mientras la mochila no este llena y queden objetos para seguir
  // metiendo
  while (actual_weight_ < max_weight_ &&
         insert_order_.size() < item_list.Size()) {
    int counter = 1;
    max_utility = 0;
    const int size = item_list.Size();
    // Se recorre lista para encontrar item con mayor utilidad sin repetir
    for (auto it = item_list.Begin(); it != item_list.End(); ++it) {
      if ((it->at(utility_index) > max_utility) &&
          (it->at(used_index) == zero)) {
        max_utility = it->at(utility_index);
        object_number = counter;
        pos = it;
      }
      counter++;
    }
    fraction = Remaning_space() / pos->at(weight_index);
    if (fraction > 1) {
      fraction = 1;
    }
    actual_weight_ = actual_weight_ + pos->at(weight_index) * fraction;
    benefit_ = benefit_ + pos->at(value_index) * fraction;
    insert_order_.emplace_back(std::make_pair(object_number, fraction));
    pos->at(used_index) = 1;
  }
}

// Funcion que introduce objetos en la mochila, los objetos son ilimitados pero
// no se pueden fraccionar
void Mochila::Insert_unbounded(Item& item_list) {
  float max_utility = 0;
  int fraction = 0;
  int object_number = 1;
  auto pos = item_list.Begin();
  const int weight_index = 0;
  const int value_index = 1;
  const int utility_index = 2;
  const float zero = 0;
  bool available = true;
  // Se repite mientras la mochila no este llena y exista algun objeto que pueda
  // ser introducido en la mochila
  while (actual_weight_ < max_weight_ && available) {
    int counter = 1;
    max_utility = 0;
    const int size = item_list.Size();
    available = false;
    // Se recorre lista para encontrar item con mayor utilidad que pueda entrar
    for (auto it = item_list.Begin(); it != item_list.End(); ++it) {
      if (it->at(utility_index) > max_utility &&
          it->at(weight_index) <= Remaning_space()) {
        max_utility = it->at(utility_index);
        object_number = counter;
        pos = it;
        available = true;
      }
      counter++;
    }
    fraction = Remaning_space() / pos->at(weight_index);
    if (fraction > 0) {
      actual_weight_ = actual_weight_ + pos->at(weight_index) * fraction;
      benefit_ = benefit_ + pos->at(value_index) * fraction;
      insert_order_.emplace_back(std::make_pair(object_number, fraction));
    }
  }
}

// Funcion devuelve cuanto queda por llenar en la mochila
float Mochila::Remaning_space() { return max_weight_ - actual_weight_; }

// Funcion escribe en pantalla la solucion a la que se ha llegado
void Mochila::Print_solution() {
  const int size = insert_order_.size();
  std::cout << "Beneficio: " << benefit_ << std::endl;
  std::cout << "Peso: " << actual_weight_ << std::endl;
  std::cout << "Solucion: " << std::endl;
  for (int i = 0; i < size; i++) {
    std::cout << insert_order_[i].first << ":" << insert_order_[i].second
              << " ";
  }
  std::cout << std::endl;
}