// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58

/*

	EXPLICACIÓN:

		Para resolver este problema se ha utilzado una cola de prioridad y una estrategia voraz que consiste
		en ordenar de menor a mayor las actividades segun su tiempo de finalización, de tal forma que se maximice
		el tiempo del que disponen los usuarios para asistir a las actividades.

		La cola de prioridad se usa para almacenar los tiempos de finalización de las actividades de los compañeros
		que están asistiendo a una de ellas, por tanto, en cada iteración se comprueba que si el tiempo de finalización
		del usuario que mas pronto acabará de ver su actividad es menor que dicha finalización, se necesitará como minimo
		otro compañero.


	COSTES:
		
		- Coste de top() -> O(1)
		- Coste de push() y pop() -> O(log(n)) siendo n el número de compañeros que hay asistiendo actividades.


	COSTE TOTAL:
		
		O(n * log(m)) -> siendo n el número de actividades y n el número de compañeros asistiendo a las actividades.
		
*/

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>

#include "PriorityQueue.h"

struct tActivity {

	int begin;
	int end;

	tActivity() {}

	tActivity(int b, int e) : begin(b), end(e) {}

	bool operator < (tActivity const & a) { return begin < a.begin; }
};

int min_partner(std::vector<tActivity> const & v) {

	int partners = 0;
	PriorityQueue<int> order_end;

	order_end.push(v[0].end);

	for (int i = 1; i < v.size(); ++i) {

		if (v[i].begin < order_end.top()) partners++;
		else order_end.pop();
		
		order_end.push(v[i].end);
	}

	return partners;
}

bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector<tActivity> v(n);
	int b, e;

	for (int i = 0; i < n; ++i) {

		std::cin >> b >> e;

		v[i] = { b, e };
	}

	std::sort(v.begin(), v.end());

	std::cout << min_partner(v) << std::endl;

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