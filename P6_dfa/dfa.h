// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es
// El programa se encarga de simular un DFA e indica si las cadenas
// administradas son aceptadas o no

#pragma once

#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
#include <regex>

#include "alfabeto.h"

// Clase que define un DFA, en esta clase se almacenan los estados del DFA en un
// contenedor de clase map
// La funcion de transicion almacena las cadenas aceptadas en un vector

class Dfa {
 private:
  // Indica el estado en el que se encuentra el dfa
  int actual_state_;

  // Indica el estado de inicio del dfa
  int start_state_;

  // Objeto tipo map para acceder a cada nodo, que a su vez da otro objeto tipo
  // map que contiene las transiciones de ese nodo en concreto
  std::map<int, std::map<std::string, int>> states_;

  // Vector que contiene los estados finales
  std::vector<int> final_states_;

  // Vector booleano que indica si las cadenas han sido aceptadas o no
  std::vector<bool> accepted_;

  // Variable booleana que nos indica si el dfa se ha construido correctamente o
  // no
  bool correct_construct_;

  // Objeto tipo Alfabeto que es un set que contiene los simbolos del alfabeto
  // del dfa
  Alfabeto sigma_;

 public:
  // Constructor del DFA, recibe la cantidad de estados, el estado inicial y en
  // un vector la informacion sobre los nodos
  Dfa(const int, const int, const std::vector<std::string> &);

  // Funcion que realiza la transicion de estados segun el DFA para cada cadena
  // que le llega, itera elemento por elemento de la cadena y utiliza la funcion
  // find de la clase map para ello
  // guarda si la cadena es aceptada o no en un vector booleano
  void Transition(const std::string &);

  // Funcion imprime informacion sobre el DFA, el map y vector de aceptacion
  // ademas del alfabeto y si se ha construido correctamente
  void Print_Info();

  // Funcion comprueba si el DFA se ha construido correctamente
  bool Is_Correct();

  // Funcion se encarga de escribir en el fichero de salida si la cadena ha sido
  // aceptada o no
  std::string Output(const std::string &, const int);
};