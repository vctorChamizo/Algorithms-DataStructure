// Grupo E16, PABLO GARCIA HERNANDEZ
// Comentario general sobre la solucion,
// explicando como se resuelve el problema
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
using namespace std;


// funcion que resuelve el problema
// comentario sobre el coste, O(f(N))
int resolver(vector <int> &v, int ini, int fin) {

	if (ini == fin)
		return 0;
	if (ini + 1 == fin) {
		if (v[ini] > v[ini + 1]) {
			swap(v[ini], v[ini + 1]);
			return 1;
		}
		else
			return 0;
		
	}
	else {
		int m = (ini + fin) / 2;
		int resIzq = resolver(v, ini, m);
		int resDer = resolver(v, m, fin);

		int inv = 0, i = ini, j = m;

		while (i < m && j < fin){ //comparar ambas mitades
			if (v[i] < v[j]) i++; //si estan ordenados avanzamos
			else{ //si no estan ordenados sumanos las inversiones
				inv += (m - i);
				j++;
			}

		}
		//vamos a ordenar.
		vector<int> aux(fin - ini);

		//Ordenar con la funcion merge de la libreria algorithm
		merge((v.begin() + ini), (v.begin() + m), (v.begin() + m), (v.begin() + fin), aux.begin());

		for (int i = 0; i < aux.size(); ++i)
			v[ini + i] = aux[i];

		return resIzq + resDer + inv;
	}


}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuracion, y escribiendo la respuesta
bool resuelveCaso() {
	// leer los datos de la entrada
	int n, aux;
	cin >> n;
	if (!std::cin)
		return false;
	vector<int> v;
	for (int i = 0; i < n; ++i) {
		cin >> aux;
		v.push_back(aux);
	}
	int sol = 0;
	if (n == 0)
		sol = 0;
	else {
		int ini = 0;
		int fin = v.size() - 1;
		sol = resolver(v, ini, fin);
	}
	

	// escribir sol
	cout << sol << endl;

	return true;

}

int main() {
	// Para la entrada por fichero.
	// Comentar para acepta el reto
#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif 


	while (resuelveCaso())
		;


	// Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
	std::cin.rdbuf(cinbuf);
	//system("PAUSE");
#endif

	return 0;
}