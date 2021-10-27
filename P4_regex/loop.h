// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia

#pragma once

#include <iostream>
#include <vector>
#include <regex>

class Loops {
    private:
    std::vector<int> l_numl_;
    std::vector<std::string> l_type_;
    std::vector<std::string> l_var_;
    int l_counterl_;
    int f_quantity_;
    int w_quantity_;

    public:
    Loops();
    void search(const std::string &);
    std::string print_loop();
};