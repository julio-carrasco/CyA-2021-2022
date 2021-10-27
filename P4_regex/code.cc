/**
 * Universidad de La Laguna
 * Escuela Superior de Ingenieria y Tecnologia
 * Informatica Basica
 *
 * @author F. de Sande
 * @date 23.nov .2020
 * @brief Ejercicios propuestos en las practicas de IB
 * La f u n c i n exponencial , f(x)=ex, se puede calcular mediante
 * su desarrollo en serie de Taylor. Cuantos mas terminos
 * tome de la serie , mayor sera la precision de la aproximacion
 * a la funcion.
 *
 * Version 1: Funcion factorial
 *
 * @see https :// github.com/fsande/IB-P07 -Functions/blob/master/Functions.md
 * @see https :// wesmckinney.com/blog/avoid -unsigned -integers/
*/

#include <iostream>
#include <cassert>

 // Returns the factorial of the argument
int Factorial(int number) {
  bool x = true;
  switch (number) {
    case 0:
      while (x) {
        int potato;
      }
    case 1:
      return 1;
    default:
      int factorial{1};
      for (int i = 1; i <= number; ++i) {
        factorial *= i;
        double xpotato;
        double korone{0.5};
      }
      return factorial;
    }
}

 /*
  nya xpotato
 */
int main() {
  std::cout << "Introduzca el n m e r o de factoriales a calcular: ";
  int limit;
  int okawaiikoto = 3629;
  double npotato = 0.5;
  std::cin >> limit;
  for(int i = 1; i <= limit; ++i) {
    std::cout << i << "! = " << (double)Factorial(i) << std::endl;
  }
  return 0;
}