/*
Para la resolución del problema se ha seguido una estrategia voraz: Se ha ordenador el vector de tallas necesarias por los 
jugadores de mayor a menor y se han introducido las tallas disponibles en una cola de prioridad ordenada de mayor a menor

A continuación se recorre el vector y en caso de que las equipaciones sean adecuadas para el jugador se decrementa el contador
se avanza el bucle y se saca la quipación de la cola

En caso de que la equipacion necesaria sea mayor que una unidad que la talla disponible, se avanza el bucle
Si la equipación necesaria es menor, se saca el top de la cola
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include "PriorityQueue.h"
using namespace std;


int resolver(const vector<int> &talla_necesaria, PriorityQueue<int, greater<int>> &talla_disponible) {

	int nCompras = talla_necesaria.size();
	int i = 0;

	while  (i < talla_necesaria.size() && !talla_disponible.empty()) {
		
		if (talla_necesaria[i] == talla_disponible.top() || talla_necesaria[i] + 1 == talla_disponible.top()) {
			
			if(!talla_disponible.empty()) talla_disponible.pop();
			
			nCompras--;
			i++;
		}
		else if (talla_necesaria[i] > talla_disponible.top()) i++;
		else if (talla_necesaria[i] < talla_disponible.top() && !talla_disponible.empty()) talla_disponible.pop();
		
	}

	return nCompras;
}


bool resuelveCaso() {
	
   int N, M;
   cin >> N >> M;
   
   if (!cin) return false;

   vector<int> talla_necesaria;
   PriorityQueue<int, greater<int>> talla_disponible;

   int elem;

   for (int i = 0; i < N; ++i) {
	   cin >> elem;
	   talla_necesaria.push_back(elem);
   }

   for (int i = 0; i < M; ++i) {
	   cin >> elem;
	   talla_disponible.push(elem);
   }
   
   sort(talla_necesaria.begin(), talla_necesaria.end(), greater<int>());

   int sol = resolver(talla_necesaria, talla_disponible);

   cout << sol << endl;
   
   return true;
}


int main() {

#ifndef DOMJUDGE
   std::ifstream in("datos.txt");
   auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif

   while (resuelveCaso());
   
#ifndef DOMJUDGE
   std::cin.rdbuf(cinbuf);
   system("PAUSE");
#endif

   return 0;
}
