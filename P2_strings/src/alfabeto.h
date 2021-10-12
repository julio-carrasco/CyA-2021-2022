#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Alfabeto {
 private:
  std::vector<std::string> alfabeto_;

 public:
  Alfabeto(std::string);
  std::string get_a(int) const;
  int get_size() const;
};