#pragma once

#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include <list>

class Item {
 public:
  Item(const std::string&);
  int Size() const;
  std::list<std::vector<float>>::iterator Begin();
  std::list<std::vector<float>>::iterator End();
  void Delete(int);

 private:
  int amount_;
  std::list<std::vector<float>> item_list_;
};