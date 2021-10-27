// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

#include "info.h"

Info::Info(const std::string &program) {
    name_ = program;
    i_main_ = false;
    comments_.reserve(1);
    c_numl_.reserve(1);
    counterl_ = 1;
    inside_ = false;
    description_ = false;
}

void Info::search(const std::string &line) {
    std::regex multi_comment("\\/\\*+|\\*+\\/");
    std::regex single_comment("[^\\S]\\/\\/.*");
    std::smatch c_matches;
    std::string empty = "";
    
   
    
    if(regex_search(line, c_matches, multi_comment)) {
        inside_ = !inside_;
        for(auto match: c_matches) {
            comments_.emplace_back(match);
        }
        c_numl_.emplace_back(counterl_);
        
        if(inside_) {
            type_.emplace_back(true);
        }
    } else if(inside_) {
            comments_.emplace_back(line);
        }

    
    if(regex_search(line, c_matches, single_comment)) {
        for(auto match2: c_matches) {
            comments_.emplace_back(match2);
            c_numl_.emplace_back(counterl_);
            type_.emplace_back(false);
        }
    }
    
    std::regex main("int main.*\\(.*\\).*");
    if(regex_match(line, main)){ 
        i_main_ = true;
    }
    
    counterl_++;
}

std::string Info::print_info() {
    std::string out;
    std::string program = "PROGRAM: ";
    std::string description = "DESCRIPTION: ";
    std::string no_descript = "Program does not have a description";
    std::string end = "\n";
    int size = comments_.size();
    int first = 0;
    int second = 1;
    out = program + name_ + end;
    out = out + description + end;
    if(c_numl_[first] != second) {
        out = out + no_descript;
    } else {
        for(int i = 0; i < size && i < c_numl_[second]; i++) {
            out = out + comments_[i] + end;
        }
        description_ = true;
    }
    out = out + end;
    return out;
}

std::string Info::print_comments() {
    std::string out;
    std::string imain = "MAIN: ";
    std::string case1 = "True";
    std::string case2 = "False";
    std::string comment = "COMMENTS: ";
    std::string end = "\n";
    std::string line_s = "[Line ";
    std::string line_e = "] ";
    std::string descript = "DESCRIPTION";
    std::string barra = " - ";
    int beginning = 0;
    int last = 0;
    int count = 0;
    int it = 0;
    out = imain + end;
    
    if(i_main_) {
        out = out + case1 + end;
    } else {
        out = out + case2 + end;
    }
    
    int size = type_.size();
    out = out + end + comment + end;
    for(int i = 0; i < size; i++) {
        if(type_[i]){
            beginning = c_numl_[count];
            last = c_numl_[count + 1];
            out = out + line_s + std::to_string(beginning) + barra + std::to_string(last) + line_e;
            if(beginning == 1 && description_) {
                out = out + descript + end;
                it = last;
            } else {
                out = out + end;
                while(beginning <= last) {
                    out = out + comments_[it] + end;
                    it++;
                    beginning++;
                }
            }
            
            count = count + 2;
        } else {
            out = out + line_s + std::to_string(c_numl_[count]) + line_e;
            out = out + comments_[it] + end;
            it++;
            count++;
        }
    }

    out = out + end;
    return out;
}

void Info::print() {
    int size = comments_.size();
    for(int i = 0; i < size; i++) {
        std::cout << comments_[i] << std::endl;
    }
}