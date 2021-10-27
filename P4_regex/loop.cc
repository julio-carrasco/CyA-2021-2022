// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

#include "loop.h"

// Constructor de clase Loop
Loops::Loops() {
    l_numl_.reserve(1);
    l_type_.reserve(1);
    l_var_.reserve(1);
    l_counterl_ = 1;
    f_quantity_ = 0;
    w_quantity_ = 0;
}

// Funcion que busca mediante exoresiones regulares las declaraciones de bucless
void Loops::search(const std::string &line) {
    int first = 1;
    int second = 2;
    std::string type = "LOOP: ";
    std::smatch f_matches;
    std::smatch w_matches;
    int counter = 1;
    std::regex exp1("(for).*\\(");
    std::regex exp2("(while).*\\(");
    if(regex_search(line, f_matches, exp1)) {
        counter = 1;
        for(auto match: f_matches) {
            if(counter == first) {
            l_numl_.emplace_back(l_counterl_);
            l_type_.emplace_back(type);
            }
            if(counter == second) {
            l_var_.emplace_back(match);
            }
            counter++;
        }
        f_quantity_++;
    }
    if(regex_search(line, w_matches, exp2)) {
        counter = 1;
        for(auto match2: w_matches) {
            if(counter == first) {
            l_numl_.emplace_back(l_counterl_);
            l_type_.emplace_back(type);
            }
            if(counter == second) {
            l_var_.emplace_back(match2);
            }
            counter++;
        }
        w_quantity_++;
    }
    l_counterl_++;
}

// Funcion que escribe el tipo de bucle y en que linea se declara
std::string Loops::print_loop() {
    std::string out;
    std::string title = "STATEMENTS: ";
    std::string line_s = "[Line ";
    std::string line_e = "] ";
    std::string end = "\n";
    std::string aux;
    out = title + end;
    int size = l_var_.size();
    for(int i = 0; i < size; i++) {
        aux = std::to_string(l_numl_[i]);
        out = out + line_s + aux + line_e;
        out = out + l_type_[i];
        out = out + l_var_[i] + end;
    }
    out = out + end;
    return out;
}
