// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia

#pragma once

#include <iostream>
#include <vector>
#include <regex>

class Variable {
    private:
    std::vector<int> v_numl_;
    std::vector<std::string> v_type_;
    std::vector<std::string> v_var_;
    std::vector<std::string> v_value_;
    int v_counterl_;
    int i_quantity_;
    int d_quantity_;

    public:
    Variable();
    void search(const std::string &);
    std::string print_var();

};