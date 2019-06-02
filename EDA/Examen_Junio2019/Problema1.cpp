// NOMBRE Y APELLIDOS -> VICTOR CHAMIZO RODRIGUEZ
/*
	El coste de la solucion es -> O(n) siendo n el numero de elementos de la pila
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

#include <stack>

struct tAccidente {

	std::string f = "";
	int v = 0;

	tAccidente() {};
	tAccidente(std::string _f, int _v) : f(_f), v(_v) {};
};

bool resuelveCaso() {

   int N;
   std::cin >> N;
   
   if (!std::cin) return false;

   std::stack<tAccidente> pila;
   std::string fecha;
   int victimas;

   for (int i = 0; i < N; ++i) {

	   std::cin >> fecha >> victimas;

	   if (pila.empty())std::cout << "NO HAY" << std::endl;
	   else if (victimas >= pila.top().v) {

		   while (!pila.empty() && victimas >= pila.top().v) pila.pop();

		   if (pila.empty()) std::cout << "NO HAY" << std::endl;
		   else std::cout << pila.top().f << std::endl;
	   }
	   else std::cout << pila.top().f << std::endl;

	   pila.push({ fecha , victimas });
   }
   
   std::cout << "---" << std::endl;

   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos1.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif
   
   while (resuelveCaso());

   // para dejar todo como estaba al principio
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif
   return 0;
}
