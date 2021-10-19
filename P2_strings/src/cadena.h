#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

#include "alfabeto.h"

class Cadena {
 private:
  std::string cadena_;
  std::vector<std::pair<std::string, int>> order_;
  std::string get_chain();
  bool Is_Correct();
  bool Check(const std::string &, const int &);

 public:
  Cadena(std::string, const Alfabeto &);
  int Longitud();
  std::string Inversa();
  std::string Prefijos();
  std::string Sufijos();
  std::string Subcadenas();

  void print_o();
};