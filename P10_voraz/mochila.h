#pragma once

#include <iostream>

#include "item.h"

class Mochila {
 public:
  Mochila(float);
  void Insert_items(Item&);
  void Insert_unbounded(Item&);
  void Print_solution();


 private:
  float max_weight_;
  float actual_weight_;
  float benefit_;
  std::vector<std::pair<int, float>> insert_order_;

  float Remaning_space();
};