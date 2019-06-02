// NOMBRE Y APELLIDOS -> VÍCTOR CHAMIZO RODRIGUEZ

#include <iostream>
#include <fstream>
#include <algorithm>

#include "bintree_eda.h"

void caminoPares(bintree<int> const & t, int & c_maximo, int & c_actual) {

	if (t.empty()) c_actual = 0;
	else if (t.right().empty() && t.left().empty()) {

		if (t.root() % 2 == 0) {

			c_actual = 1;
			c_maximo = std::max(c_maximo, c_actual);
		}
		else c_actual = 0;
	}
	else {

		int c_left, c_right;
		caminoPares(t.left(), c_maximo, c_left);
		caminoPares(t.right(), c_maximo, c_right);

		if (t.root() % 2 == 0) {

			c_maximo = std::max(c_maximo, c_left + c_right + 1);
			c_actual = std::max(c_left, c_right) + 1;
		}
		else {

			c_maximo = std::max(c_maximo, std::max(c_left, c_right));
			c_actual = 0;
		}
	}
}

void resuelveCaso() {

   auto arbol = leerArbol(-1);

   int camino, camino_maximo = 0;

   caminoPares(arbol, camino_maximo, camino);

   std::cout << camino_maximo << std::endl;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos2.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   int numCasos;
   std::cin >> numCasos;
   for (int i = 0; i < numCasos; ++i)
      resuelveCaso();

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
