#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "alfabeto.h"
#include "cadena.h"
#include "lenguaje.h"

// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// Programa lee por un archivo de texto un alfabeto y una cadena y puede
// realizar ciertas operaciones

void Help(int, char**);
bool Num_check(int);

using namespace std;

int main(int argc, char* argv[]) {
  Help(argc, argv);
  int opcode = atoi(argv[3]);
  string input = argv[1];
  string output = argv[2];
  string line;
  ifstream infile(input);
  ofstream outfile(output);
  const int Longitud = 1;
  const int Inversa = 2;
  const int Prefijo = 3;
  const int Sufijo = 4;
  const int Subcadena = 5;
  const int Comparacion = 6;
  const int Concatenacion = 7;
  const int Potencia = 8;
  string aux;
  int num = -1;
  if (infile.is_open()) {
    while (getline(infile, line)) {
      Alfabeto sigma(line);
      Cadena chain(line, sigma);
      switch (opcode) {
        case Longitud:
          outfile << chain.Longitud() << "\n";
          break;

        case Inversa:
          outfile << chain.Inversa() << "\n";
          break;

        case Prefijo:
          outfile << chain.Prefijos() << "\n";
          break;

        case Sufijo:
          outfile << chain.Sufijos() << "\n";
          break;

        case Subcadena:
          outfile << chain.Subcadenas() << "\n";
          break;

        case Comparacion:
          cout << "Introduzca cadena a comparar con: " << chain.get_chain() << endl;
          cin >> aux;
          outfile << chain.Comparacion(aux) << "\n";
          break;

        case Concatenacion:
          cout << "Introduzca cadena a concatenar con:" << chain.get_chain() << endl;
          cin >> aux;
          outfile << chain.Concatenacion(aux) << "\n";
          break;

        case Potencia:
          while (!Num_check(num)) {
            cout << "Introduzca un numero mayor o igual a 0 para hacer la potencia de: " << chain.get_chain() << endl;
            cin >> num;
          }
          outfile << chain.Potencia(num) << "\n";
          break;
      }
    }
    infile.close();
  }
  return 0;
}

// Funcion que imprime por pantalla mensajes de ayuda
void Help(int argc, char* argv[]) {
  int opcode = stoi(argv[3]);
  string help = "--help";
  if (argc == 2 && (argv[1] == help) == 0) {
    cerr << "Debes introducir primero el archivo txt del cual se va a leer el "
            "alfabeto y cadena."
         << endl;
    cerr << "A continuacion el txt de salida donde saldra el resultado de la "
            "operacion"
         << endl;
    cerr << "En el opcode debes colocar un numero del 1 al 5" << endl;
    cerr << "1: Longitud de cadena" << endl;
    cerr << "2: Inversa de la cadena" << endl;
    cerr << "3: Prefijos de la cadena" << endl;
    cerr << "4: Sufijos de la cadena" << endl;
    cerr << "5: Subcadenas" << endl;
    cerr << "6: Comparacion de cadenas" << endl;
    cerr << "7: Concatenacion" << endl;
    cerr << "8: Potencia de cadenas" << endl;
    cerr << endl
         << "En caso de que la cadena introducida no se pueda formar con el "
            "alfabeto proporcioando se escribira: Cadena no valida o -1";
    exit(1);
  }

  if (argc != 4) {
    cerr << "Se debe introducir input.txt output.txt opcode" << endl;
    cerr << "Escriba --help para mas informacion" << endl;
    exit(1);
  }

  if (opcode < 1 || opcode > 8) {
    cerr << "En el opcode debes colocar un numero del 1 al 5" << endl;
    cerr << "1: Longitud de cadena" << endl;
    cerr << "2: Inversa de la cadena" << endl;
    cerr << "3: Prefijos de la cadena" << endl;
    cerr << "4: Sufijos de la cadena" << endl;
    cerr << "5: Subcadenas" << endl;
    cerr << "6: Comparacion de cadenas" << endl;
    cerr << "7: Concatenacion" << endl;
    cerr << "8: Potencia de cadenas" << endl;
    exit(1);
  }
}

bool Num_check(int num) {
  bool out = false;
  if (num >= 0) {
    out = true;
  }
  return out;
}