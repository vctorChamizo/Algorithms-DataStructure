/* Hemos ordenado ambos vectores (tallas de los jugadores y tallas de las equipaciones) de menor a mayor debido que queremos
realizar un algortimo voraz comparando a los jugadores mas pequeños con las equipaciones mas pequeñas.

Por tanto recorremos ambos vectores desde el pricipio, teniendo en cuenta que si la ultima equipación no se ajusta con el jugador 
al cual estamos comparando, el resto de chicos tampoco encajarán en la talla, debido a que siempre serán mayores o iguales que él.

El coste del algortimo es: (N * log N) + (M * log M) + N + M, siendo N el numero de jugadores y M el numero de equipaciones.
	- Desglose:
		N * log N --> ordenacion del vector de tallas de los chicos.
		M * log M --> ordenacion del vector de tallas de las equipaciones.
		N --> recorrido del vector de las tallas de los chicos.
		M --> recorrido del vector de las tallas de las equipaciones.
*/


#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>


int minimoCompras(std::vector<int> const & tC, std::vector<int> const & tE) {

	int nCompras = 0;
	int i = 0;
	int j = 0;

	while (i < tC.size() && j < tE.size()) {

		if (tC[i] == tE[j] || tC[i] + 1 == tE[j]){
			++i;
			++j;
		}
		else if (tC[i] < tE[j]){
			nCompras++;
			++i;
		}
		else ++j;
	}
	
	return tC.size() - i + nCompras;
}


bool resuelveCaso() {

   int N, M;

   std::cin >> N >> M;
   
   if (!std::cin) return false;

   std::vector<int> tallasChicos(N);
   std::vector <int> tallasEquipaciones(M);

   for (auto i = 0; i < N; ++i)
	   std::cin >> tallasChicos[i];

   for (auto j = 0; j < M; ++j)
	   std::cin >> tallasEquipaciones[j];

   std::sort(tallasChicos.begin(), tallasChicos.end());
   std::sort(tallasEquipaciones.begin(), tallasEquipaciones.end());

   int minimo = minimoCompras(tallasChicos, tallasEquipaciones);

   std::cout << minimo << std::endl;
  
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
