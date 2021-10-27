// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia

#pragma once

#include <iostream>
#include <regex>


class Info {
    private:
    bool i_main_;
    std::string name_;
    bool description_;
    std::vector<int> c_numl_;
    std::vector<std::string> comments_;
    std::vector<bool> type_;
    int counterl_;
    bool inside_;

    public:
    Info(const std::string &);
    void search(const std::string &);
    std::string print_info();
    std::string print_comments();
    void print();
};