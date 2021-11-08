// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es
// El programa se encarga de simular un DFA e indica si las cadenas
// administradas son aceptadas o no

#include "dfa.h"

// Constructor del DFA, recibe la cantidad de estados, el estado inicial y en un
// vector la informacion sobre los nodos
Dfa::Dfa(const int number_states, const int initial_state,
         const std::vector<std::string> &delta) {
  correct_construct_ = true;
  start_state_ = initial_state;
  int size = delta.size();
  std::string aux;
  int trans_number{0};
  int counter;
  int aux_length;
  int q_state;
  int min_size;
  std::string sigma_construct;
  std::string place;
  int place2;
  start_state_ = initial_state;
  std::smatch matches;
  // Se utiliza regex para obtener el identificador del nodo, si es un nodo de
  // aceptacion,
  // la cantidad de transiciones que tiene y a donde transita y con que simbolo
  std::regex exp("^([0-9]).([0-9]).([0-9]).([a-zA-Z]+.+[0-9]+)+");
  for (int i = 0; i < size; i++) {
    aux = delta[i];
    if (regex_search(aux, matches, exp)) {
      counter = 0;
      for (auto match : matches) {
        switch (counter) {
          case 1:
            q_state = stoi(match);
            break;
          case 2:
            if (match == "1") {
              final_states_.emplace_back(q_state);
            }
            break;

          case 3:
            trans_number = stoi(match);
            break;

          case 4:
            std::map<std::string, int> placeholder;
            aux = match;
            aux.erase(remove_if(aux.begin(), aux.end(), isspace), aux.end());
            aux_length = aux.size();
            // Se crea un objeto tipo map temporal para guardar las transiciones
            // de un estado que luego sera introducido en el map general que
            // representa la tabla de transicones
            for (int j = 0; j < aux_length; j++) {
              if (j % 2 == 0) {
                place = aux[j];
                sigma_construct = sigma_construct + aux[j];
              }
              if (j % 2 != 0) {
                place2 = aux[j] - '0';
                placeholder.emplace(place, place2);
              }
            }
            states_.emplace(q_state, placeholder);
            if (trans_number != placeholder.size()) {
              correct_construct_ = false;
            }
            if (aux_length / 2 != trans_number) {
              correct_construct_ = false;
            }
            break;
        }
        counter++;
      }
    }
  }
  if (number_states != states_.size()) {
    correct_construct_ = false;
  }
  sigma_.insert(sigma_construct);
  min_size = sigma_.get_size() - 1;
  // Se comprueba si el DFA tiene las transicones necesarias dependiendo de su
  // alfabeto, es decir si tiene un alfabeto compuesto por 0 y 1
  // cada estado debera tener 2 transiciones
  for (auto const &it : states_) {
    if (it.second.size() != min_size) {
      correct_construct_ = false;
    }
  }
}

// Funcion que realiza la transicion de estados segun el DFA para cada cadena
// que le llega, itera elemento por elemento de la cadena y utiliza la funcion
// find de la clase map para ello
// guarda si la cadena es aceptada o no en un vector booleano
void Dfa::Transition(const std::string &line) {
  bool accepted = false;
  const int size = line.size();
  std::string aux;
  actual_state_ = start_state_;
  for (int i = 0; i < size; i++) {
    aux = line[i];
    actual_state_ = states_.find(actual_state_)->second.find(aux)->second;
  }
  const int length = final_states_.size();
  for (int j = 0; j < length; j++) {
    if (actual_state_ == final_states_[j]) {
      accepted = true;
    }
  }
  if (accepted) {
    accepted_.emplace_back(true);
  } else {
    accepted_.emplace_back(false);
  }
}

// Funcion imprime informacion sobre el DFA, el map y vector de aceptacion
// ademas del alfabeto y si se ha construido correctamente
void Dfa::Print_Info() {
  std::cout << "correct: " << correct_construct_ << std::endl;
  for (int k = 0; k < sigma_.get_size(); k++) {
    std::cout << sigma_.get_a(k);
  }
  std::cout << std::endl;
  for (auto const &it : states_) {
    std::cout << it.first << ": (";
    for (auto const &x : it.second) {
      std::cout << x.first << ": " << x.second;
    }
    std::cout << ")" << std::endl;
  }
  for (int i = 0; i < accepted_.size(); i++) {
    std::cout << accepted_[i] << " ";
  }
  std::cout << std::endl;
}

// Funcion comprueba si el DFA se ha construido correctamente
bool Dfa::Is_Correct() { return correct_construct_; }

// Funcion se encarga de escribir en el fichero de salida si la cadena ha sido
// aceptada o no
std::string Dfa::Output(const std::string &line, const int counter) {
  const int size = accepted_.size();
  std::string accept = " -- Accepted\n";
  std::string reject = " -- Rejected\n";
  std::string out;
  bool condition = false;
  if (accepted_[counter]) {
    condition = true;
  }
  if (condition) {
    out = line + accept;
  } else {
    out = line + reject;
  }
  return out;
}