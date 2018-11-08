#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

/*
El coste de la funcion esValida es O(n) siendo el n numero de abrigos.
Hay que obtener el maximo para aplicar la formula dada por el enunciado.
*/

bool esSolucion(int max, int k) { return k == max; }


bool esValida(std::vector<int> const & vSol, std::vector<int> const & vL, std::vector<int> const & vCA, 
			  std::vector<int> const & vCont, int k, int abrigo) {

	int maximo = 0;
	for (auto i = 0; i < vCont.size(); ++i)
		maximo = std::max(vCont[i], maximo);
	
	if (vCont[abrigo] == maximo && maximo > (2 + k / 3)) return false;
	if (vCA[abrigo] < vL[k]) return false;
	if (k > 0 && vSol[k] == vSol[k - 1]) return false;
	if (k == (vL.size() - 1) && vSol[0] == vSol[vL.size() - 1]) return false;

	return true;
}

void resolver(std::vector<int> & vSol, std::vector<int> const & vL, std::vector<int> const & vCA,
			  std::vector<int> & vCont, int k, int & nSol) {

	for (int i = 0; i < vCA.size(); ++i) {

		vSol[k] = i;
		vCont[i]++;

		if (esValida(vSol, vL, vCA, vCont, k, i)) {

			if (!esSolucion(vL.size() - 1, k)) resolver(vSol, vL, vCA, vCont, k + 1, nSol);
			else nSol++;
		}

		vCont[i]--;
	}
}


bool resuelveCaso() {

	int numDias, numAbrigos;
	
	std::cin >> numDias;
	
	if (numDias == 0) return false;
	
	std::cin >> numAbrigos;

	std::vector<int> vectorLLuvia(numDias);

	for (auto i = 0; i < numDias; ++i)
		std::cin >> vectorLLuvia[i];
	
	std::vector<int> vectorCapacidadAbrigo(numAbrigos);

	for (auto i = 0; i < numAbrigos; ++i)
		std::cin >> vectorCapacidadAbrigo[i];

	std::vector<int> vectorSolcuion(numDias);
	std::vector<int> vectorContador(numAbrigos);
	int numSoluciones = 0;

	resolver(vectorSolcuion, vectorLLuvia, vectorCapacidadAbrigo, vectorContador, 0, numSoluciones);

	if (numSoluciones == 0) std::cout << "Lo puedes comprar\n";
	else std::cout << numSoluciones << '\n';

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