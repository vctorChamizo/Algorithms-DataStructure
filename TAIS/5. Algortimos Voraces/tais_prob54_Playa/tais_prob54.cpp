// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: TAIS58


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

struct tEdificio {

	int ini;
	int fin;

	bool operator < (tEdificio const & e) const { return fin < e.fin || (fin == e.fin && ini < e.ini); }
};

int minimoPasadizos(std::vector<tEdificio> const & v) {

	int nTunel = 1;
	int finalTunel = v[0].fin;

	for (int i = 1; i < v.size(); ++i) {

		if (v[i].ini >= finalTunel) {

			finalTunel = v[i].fin;
			nTunel++;
		}
	}

	return nTunel;
}

bool resuelveCaso() {

	int nEdificios;
	std::cin >> nEdificios;

	if (nEdificios == 0) return false;

	std::vector<tEdificio> edificios(nEdificios);

	for (auto i = 0; i < nEdificios; ++i)
		std::cin >> edificios[i].ini >> edificios[i].fin;

	std::sort(edificios.begin(), edificios.end());

	std::cout << minimoPasadizos(edificios) << std::endl;

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