#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

/*
	APARTADO 1: 

		predicate consecutivos (s : seq<int>, ini : int, fin : int)
			requires 0 <= ini < fin < |s|
			{forall k :: 0 <= ini <= k < fin < |s| ==> s[k] + 1 == s[k + 1]}


	APARTADO 4:

		O(n) --> siendo n el numero de elemetnos del vector.
*/

void secuenciaCrecienteMax(std::vector<int> const & v, int & ini, int & size) {

	int max_aux = 1;
	int anterior = v[0];

	for (int i = 1; i < v.size(); ++i) {

		if (anterior + 1 == v[i]) {

			max_aux++;

			if (max_aux > size) {

				ini = i - max_aux + 1;
				size = max_aux;
			}
		}
		else max_aux = 1;
		
		anterior = v[i];
	}
}


bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector<int> v(n);
	int inicio = 0, size = 0;

	for (int & k : v) std::cin >> k;

	secuenciaCrecienteMax(v, inicio, size);

	std::cout << inicio << " " << size << std::endl;

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