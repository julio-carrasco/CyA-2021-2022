// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es

#include <iostream>
#include <fstream>
#include <string>

#include "variable.h"
#include "loop.h"
#include "info.h"


void Help(int, char**);

using namespace std;

int main(int argc, char* argv[]) {
    Help(argc, argv);
    string input = argv[1];
    string output = argv[2];
    string line;
    ifstream infile(input);
    ofstream outfile(output);
    Variable variables;
    Loops loops;
    Info info(argv[1]);
    if(infile.is_open()) {
        while(getline(infile, line)) {
            info.search(line);
            variables.search(line);
            loops.search(line);

        }
        infile.close();
    }
    outfile << info.print_info();
    outfile << variables.print_var();
    outfile << loops.print_loop();
    outfile << info.print_comments();


    return 0;
}

void Help(int argc, char* argv[]) {

    string help = "--help";
    if (argc == 2 && (argv[1] == help)) {
        cerr << "Se debe introducir como primer argumento el nombre de un fichero de codigo de C++." << endl;
        cerr << "A continuacion se debe introducir el nombre de un fichero de texto como salida." << endl;
        cerr << "El programa escribira en el fichero de salida unas estadisticas obtenidas del fichero de codigo" << endl;
        exit(1);
    }
    if (argc != 3) {
        cerr << "Se debe introducir input.cc output.txt" << endl;
        cerr << "Escriba --help para mas informacion" << endl;
        exit(1);
    }
}