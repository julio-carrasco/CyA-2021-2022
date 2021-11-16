// Julio Ivan Carrasco Armas
// 2º Ingenieria Informatica
// Universidad de La Laguna
// Computabilidad y Algoritmia
// alu0101110639@ull.edu.es
// El programa se encarga de simular un NFA e indica si las cadenas
// administradas son aceptadas o no

#include "nfa.h"

// Constructor del DFA, recibe la cantidad de estados, el estado inicial y en un
// vector la informacion sobre los nodos
Nfa::Nfa(const int number_states, const int initial_state,
         const std::vector<std::string> &delta) {
  correct_construct_ = true;
  start_state_ = initial_state;
  int size = delta.size();
  int trans_number{0};
  int counter;
  int aux_length;
  int q_state;
  int min_size;
  int next_state;
  const int number_states_case{1};
  const int initial_state_case{2};
  const int trans_number_case{3};
  const int trans_func_case{4};
  std::string sigma_construct;
  std::string symbol;
  std::string aux;
  std::smatch matches;
  const std::string accepted = "1";
  start_state_ = initial_state;
  // Se utiliza regex para obtener el identificador del nodo, si es un nodo de
  // aceptacion,
  // la cantidad de transiciones que tiene y a donde transita y con que simbolo
  std::regex exp("^([0-9]).([0-9]).([0-9])\\s*(.+[0-9]+)*");
  for (int i = 0; i < size; i++) {
    aux = delta[i];
    if (regex_search(aux, matches, exp)) {
      counter = 0;
      for (auto match : matches) {
        switch (counter) {
          case number_states_case:
            q_state = stoi(match);
            break;

          case initial_state_case:
            if (match == accepted) {
              final_states_.emplace_back(q_state);
            }
            break;

          case trans_number_case:
            trans_number = stoi(match);
            break;

          case trans_func_case:
            std::multimap<std::string, int> aux_map;
            aux = match;
            aux.erase(remove_if(aux.begin(), aux.end(), isspace), aux.end());
            aux_length = aux.size();
            // Se crea un objeto temporal para guardar las transiciones
            // de un estado que luego sera introducido en el map general que
            // representa la tabla de transicones
            for (int j = 0; j < aux_length; j++) {
              if (j % 2 == 0) {
                symbol = aux[j];
                sigma_construct = sigma_construct + aux[j];
              }
              if (j % 2 != 0) {
                next_state = aux[j] - '0';
                aux_map.insert(make_pair(symbol, next_state));
              }
            }
            states_.emplace(q_state, aux_map);
            if (trans_number != aux_map.size()) {
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
  sigma_.insert(sigma_construct);
  min_size = number_states ^ sigma_.get_size();
  actual_state_ = start_state_;
}

// Funcion realiza la transicion de estados del nfa
// va guardando en un set todos los posibles estados
// y al final comprueba si se encuentra uno de los estados finales
std::string Nfa::Transition(const std::string &line) {
  std::set<int> trans_states;
  std::set<int> prev_states;
  trans_states.insert(start_state_);
  std::string aux;
  std::string out;
  const std::string accepted = " --Accepted";
  const std::string rejected = " --Rejected";
  const std::string epsilon = "&";
  const std::string end = "\n";
  const int size = line.size();
  int counter{0};
  // Bucle para recorrer toda la cadena, tiene en cuenta epsilon transiciones
  while ((trans_states.size() != prev_states.size()) || (counter < size + 1)) {
    prev_states = trans_states;
    std::set<int> next_states;
    if (counter < size) {
      aux = line[counter];
    } else {
      aux = epsilon;
    }
    // Bucle recorre los elementos del set de estados por los que hemos podido
    // pasar
    for (auto elem : trans_states) {
      typedef std::multimap<std::string, int>::iterator states_iterator;
      std::pair<states_iterator, states_iterator> range =
          states_.find(elem)->second.equal_range(aux);
      // Bucle recorre todos los posibles estados a los que podemos ir
      for (states_iterator it = range.first; it != range.second; it++) {
        next_states.insert(it->second);
        next_states.insert(elem);
      }
    }
    for (auto all : next_states) {
      trans_states.insert(all);
    }
    counter++;
  }
  bool is_there = false;
  for (int i = 0; i < final_states_.size(); i++) {
    if (trans_states.count(final_states_[i]) != 0) {
      is_there = true;
    }
  }
  out = line;
  if (is_there) {
    out = out + accepted + end;
  } else {
    out = out + rejected + end;
  }
  return out;
}

// Funcion imprime informacion sobre el DFA, el map y vector de aceptacion
// ademas del alfabeto y si se ha construido correctamente
void Nfa::Print_Info() {
  std::cout << "correct: " << correct_construct_ << std::endl;
  for (int k = 0; k < sigma_.get_size(); k++) {
    std::cout << sigma_.get_a(k);
  }
  std::cout << std::endl;
  std::cout << "Final states: ";
  for (int i = 0; i < final_states_.size(); i++) {
    std::cout << final_states_[i] << " ";
  }
  int counter{0};
  std::cout << std::endl;
  std::cout << std::endl;
  for (auto const &it : states_) {
    std::cout << "counter: " << counter << std::endl;
    std::cout << it.first << ": (";
    for (auto const &x : it.second) {
      counter++;
      std::cout << x.first << ": " << x.second << " ";
    }
    std::cout << ")" << std::endl;
  }
  std::cout << std::endl;
}

// Funcion comprueba si el DFA se ha construido correctamente
bool Nfa::Is_Correct() { return correct_construct_; }
