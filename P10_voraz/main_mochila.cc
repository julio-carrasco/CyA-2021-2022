#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "mochila.h"
#include "item.h"

void Helper(int, char**);

int main(int argc, char* argv[]) {
  Helper(argc, argv);
  std::string input;
  float size;
  // Asigna los valores correctamente de peso de mochila y nombre de lista de
  // items cuando se añade opcion -u
  if (argc == 3) {
    input = argv[2];
    size = atof(argv[1]);
  } else {
    input = argv[3];
    size = atof(argv[2]);
  }

  Mochila mochila(size);
  Item items(input);
  // Se meten los elementos en la mochila de la forma correspondiente que viene
  // dictado por opcion -u
  if (argc == 3) {
    mochila.Insert_items(items);
  } else {
    mochila.Insert_unbounded(items);
  }

  mochila.Print_solution();
  return 0;
}

// Funcion contiene informacion sobre el programa
void Helper(int argc, char* argv[]) {
  std::string help = "--help";
  int max_size;
  const std::string kconfig_file = ".cfg";
  std::string file;
  if (argc == 2 && (argv[1] == help)) {
    std::cerr << "El programa se encarga de simular el problema de la mochila"
              << std::endl
              << std::endl;
    std::cerr << "Los objetos son unicos y solo puede haber uno de cada en la "
                 "mochila, pero se pueden fraccionar, el objetivo es maximizar "
                 "el beneficio de los objetos que se introducen en la mochila"
              << std::endl;
    std::cerr << "La estructura es la siguiente: ./ejecutable [-u] [peso_max] "
                 "[archivo.cfg]"
              << std::endl
              << std::endl;
    std::cerr
        << "La opcion -u corresponde a resolver el problema de forma unbounded"
        << std::endl;
    std::cerr << "Con la opcion -u los objetos se vuelven infinitos pero ya no "
                 "se pueden fraccionar"
              << std::endl;
    exit(1);
  }
  if (argc < 3 || argc > 4) {
    std::cerr << "No se han introducido correctamente los argumentos"
              << std::endl;
    std::cerr << "La estructura es la siguiente: ./ejecutable [-u] [peso_max] "
                 "[archivo.cfg]"
              << std::endl;
    std::cerr << "Para mas informacion ejecutar con parametro --help"
              << std::endl;
    exit(1);
  }
  if (argc == 3) {
    max_size = atoi(argv[1]);
    if (max_size <= 0) {
      std::cout << max_size << std::endl;
      std::cerr
          << "El segundo parametro debe ser un numero que indicara el peso "
             "maximo de la mochila"
          << std::endl;
      exit(1);
    }
    file = argv[2];
    std::size_t found = file.find(kconfig_file);
    if (found == std::string::npos) {
      std::cerr << "El segundo parametro debe ser un archivo .cfg que contenga "
                   "la lista de objetos a trabajar"
                << std::endl;
      exit(1);
    }
  } else {
    max_size = atoi(argv[2]);
    if (max_size <= 0) {
      std::cout << max_size << std::endl;
      std::cerr
          << "El segundo parametro debe ser un numero que indicara el peso "
             "maximo de la mochila"
          << std::endl;
      exit(1);
    }
    file = argv[3];
    std::size_t found = file.find(kconfig_file);
    if (found == std::string::npos) {
      std::cerr << "El segundo parametro debe ser un archivo .cfg que contenga "
                   "la lista de objetos a trabajar"
                << std::endl;
      exit(1);
    }
  }
}