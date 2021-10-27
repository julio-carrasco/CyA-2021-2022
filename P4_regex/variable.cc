// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

#include "variable.h"

// Constructor de clase Variable
Variable::Variable() {
    v_numl_.reserve(1);
    v_type_.reserve(1);
    v_var_.reserve(1);
    v_value_.reserve(1);
    v_counterl_ = 1;
    i_quantity_ = 0;
    d_quantity_ = 0;
}

// Funcion que se encarga de buscar mediante expresiones regulares las declaraciones de variables
void Variable::search(const std::string &line) {
    int first = 1;
    int second = 2;
    int third = 3;
    int fourth = 4;
    std::smatch i_matches;
    std::smatch d_matches;
    std::string aux = "";
    int counter = 1;
    std::regex exp0("[^\\S](int) ([a-z]+).*\\D([0-9]+)");
    std::regex exp1("[^\\S](int) ([a-z]+);");
    std::regex exp2("[^\\S](double) ([a-z]+)\\D*([0-9]+\\.?[0-9]*)");
    std::regex exp3("[^\\S](double) ([a-z]+);");
    if(regex_search(line, i_matches, exp0)) {
        counter = 1;

        for(auto match: i_matches) {
            if(counter == first) {
                v_numl_.emplace_back(v_counterl_);
            }
            if(counter == second) {
                v_type_.emplace_back(match);
            }
            if(counter == third) {
                v_var_.emplace_back(match);
            }
            if(counter == fourth) {
                v_value_.emplace_back(match);
            }
            counter++;
        }
        i_quantity_++;
    }

    if(regex_search(line, i_matches, exp1)) {
        counter = 1;

        for(auto match: i_matches) {
            if(counter == first) {
                v_numl_.emplace_back(v_counterl_);
            }
            if(counter == second) {
                v_type_.emplace_back(match);
            }
            if(counter == third) {
                v_var_.emplace_back(match);
                v_value_.emplace_back(aux);
            }
            counter++;
        }
        i_quantity_++;
    }
    
    if(regex_search(line, d_matches, exp2)) {
        counter = 1;
        for(auto match2: d_matches) {
            
            if(counter == first) {
                v_numl_.emplace_back(v_counterl_);
            }
            if(counter == second) {
                v_type_.emplace_back(match2);
            }
            if(counter == third) {
                v_var_.emplace_back(match2);
            }
            if(counter == fourth) {
                v_value_.emplace_back(match2);
            }
            counter++;
        }
        d_quantity_++;
    }

    if(regex_search(line, d_matches, exp3)) {
        counter = 1;
        for(auto match2: d_matches) {
           
            if(counter == first) {
                v_numl_.emplace_back(v_counterl_);
            }
            if(counter == second) {
                v_type_.emplace_back(match2);
            }
            if(counter == third) {
                v_var_.emplace_back(match2);
                v_value_.emplace_back(aux);
            }
            counter++;
        }
        d_quantity_++;
    }
    
    v_counterl_++;
}


// Funcion que se encarga de escribir los nombres y tipos de las variables ademas de sus valores si lo tienen
std::string Variable::print_var() {
    std::string out;
    std::string title = "VARIABLES: ";
    std::string empty = "";
    std::string line_s = "[Line ";
    std::string line_e = "] ";
    std::string space = " ";
    std::string result = " = ";
    std::string type1 = "INT:";
    std::string type2 = "DOUBLE:";
    std::string comp1 = "int";
    std::string end = "\n";
    std::string aux;
    out = title + end;
    int size = v_var_.size();
    for(int i = 0; i < size; i++) {
        aux = std::to_string(v_numl_[i]);
        out = out + line_s + aux + line_e;
        if(v_type_[i] == comp1) {
            out = out + type1 + space;
        } else {
            out = out + type2 + space;
        }
        
        out = out + v_var_[i];
        if(v_value_[i] != empty) {
            out = out + result +  v_value_[i];
        }
        out = out + end;
    }
    out = out + end;
    return out;
}