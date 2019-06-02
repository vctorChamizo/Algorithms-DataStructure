// NOMBRE Y APELLIDOS -> VICTOR CHAMIZO RODRIGUEZ

#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>

#include <list>
#include <set>
#include <map>
#include <unordered_map>

/*
	El coste de la solucion es -> O(log(n)) siendo n el numero de elementos del mapa ordenado.
*/

using nombre_pelicula = std::string;
using nombre_actor = std::string;
using minutos = int;
using emisiones = int;

struct info_pelicula {

	emisiones n_emisiones; // Numero de emisiones de la pelicula.

	/*
		KEY: Nombre del actor que actua en la pelicula.
		VALUE: Minutos en los que aparece en la pelicula.

		Es un unordered_map porque no es necesario tener ordenadas las claves.
	*/
	std::unordered_map<nombre_actor, minutos> actores_actuan;
};

bool resuelveCaso() {

   int N;
   std::cin >> N;

   if (N == 0) return false;

   /*
		KEY: Nombre de la pelicula.
		VALUE: Informacion de la pelicula que está especificada en la estructura "info_pelicula"

		Es un unordered_map porque no es necesario tener ordenadas las claves.
   */
   std::unordered_map<nombre_pelicula, info_pelicula> peliculas;

   nombre_pelicula p;
   nombre_actor a;
   minutos m;
   int n;

   // Almacenamos los datos de entrada en el mapa.
   for (int i = 0; i < N; ++i) {

	   std::cin >> p >> n;

	   for (int j = 0; j < n; ++j) {

		   std::cin >> a >> m;

		   peliculas[p].actores_actuan[a] = m;
	   }
   }

   // Una vez almacenados, comenzamos a procesarlos.

   emisiones numero_maximo_emisiones = 0;
   nombre_pelicula pelicula_mas_emitida;

   /*
		KEY: minutos totales en los que aparece un actor o varios actores;
		VALUE: conjunto de actores que aparecen dicho minutos en pantall.

		Es un map debido a que ordenamos de mayor a menor los tiempos que actuan los actores en pantalla para poder obtener el ranking.
   */
   std::map<minutos, std::set<nombre_actor>, std::greater<int>> ranking_actores;

   /*
		KEY: nomre del actor.
		VALUE: suma de los minutos que aparece en pantalla.

		Es un unordered_map porque no es necesario tener ordenadas las claves.
   */
   std::unordered_map<nombre_actor, minutos> actores;

   /*
		KEY: numero de emisiones de las peliculas
		VALUE: lista de peliculas que tienen dichas emisiones.

		Es un unordered_map porque no es necesario tener ordenadas las claves.
   */
   std::unordered_map<emisiones, std::list<nombre_pelicula>> numero_emisiones;

   emisiones e;
   std::cin >> e;

   // Procesamos cual es la peliculas mas emitida y cuales son su número de emisiones.
   for (int k = 0; k < e; ++k) {

	   std::cin >> p;
	   ++peliculas[p].n_emisiones;

	   if (peliculas[p].n_emisiones >= numero_maximo_emisiones) {

		   auto it_p = peliculas.find(p);

		   numero_maximo_emisiones = it_p->second.n_emisiones;
		   pelicula_mas_emitida = it_p->first;
	   }
   }

   std::cout << numero_maximo_emisiones << ' ' << pelicula_mas_emitida << std::endl;

   // Recorremos todas las peliculas.
   for (auto const & ps : peliculas) {

	   // Si la pelicula ha sido emitida mas de una vez -> actualizamos el tiempo en pantalla de los actores en dicha pelicula.
	   if (ps.second.n_emisiones > 0) {

		   // Recorremos los actores que han particiado en la pelicula para actualizar su tiempo.
		   for (auto const & as : ps.second.actores_actuan) {

			   actores[as.first] += as.second * ps.second.n_emisiones;

			   ranking_actores[actores[as.first]].insert(as.first); // Actualizamos el ranking de tiempos.
		   }
	   }
   }

   // Obtenemos el mayor tiempo de emisión dentro del ranking
   auto tiempo_maximo_en_pantalla = ranking_actores.begin();

   // Mostramos el tiempo mayor que obstenta dicho ranking y los actores que lo conforman.

   std::cout << tiempo_maximo_en_pantalla->first;

   for (auto it_s = tiempo_maximo_en_pantalla->second.begin(); it_s != tiempo_maximo_en_pantalla->second.end(); ++it_s) std::cout << ' ' << *it_s;

   std::cout << std::endl;

   return true;
}

int main() {
   // ajustes para que cin extraiga directamente de un fichero
#ifndef DOMJUDGE
   std::ifstream in("casos3.txt");
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
