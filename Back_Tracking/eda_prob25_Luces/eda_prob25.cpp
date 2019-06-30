// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>


bool esValida(std::vector<int> & vSol, std::vector<int> const & vCons, std::vector<int> & vCont, 
			  int bombilla, int conMax, int k, int contColores, int contCons){

	if (k > 1 && vSol[k] == vSol[k - 1] && vSol[k] == vSol[k - 2]) return false;
    if(vCont[bombilla] - (contColores - vCont[bombilla]) > 1) return false;
	if (contCons > conMax) return false;

    return true;
}


bool esSolucion(int longTira, int k){ return k == longTira - 1;}


void resolver(std::vector<int> & vSol, std::vector<int> const & vCons, std::vector<int> & vCont, 
			  int longTira, int conMax, int k, int contColores, int contCons, int & nPosibilidades){
    
	for (int i = 0; i < vCons.size(); ++i) {

		vSol[k] = i;
		vCont[i]++;
		contColores++;
		contCons += vCons[i];

		if (esValida(vSol, vCons, vCont, i, conMax, k, contColores, contCons)) {

			if (!esSolucion(longTira, k))
				resolver(vSol, vCons, vCont, longTira, conMax, k + 1, contColores, contCons, nPosibilidades);

			else nPosibilidades++;
		}

		vCont[i]--;
		contColores--;
		contCons -= vCons[i];
	}
}


bool resuelveCaso() {

	int longitudTira;

	std::cin >> longitudTira;

    if (! std::cin)
        return false;

	int nColores, consumoMaximo;

	std::cin >> nColores >> consumoMaximo;
    
	std::vector<int> vectorSolucion(longitudTira);
	std::vector<int> vectorConsumo(nColores);
    std::vector<int> vectorContador(nColores, 0);
    
    for(int i = 0; i < nColores; ++i)
		std::cin >> vectorConsumo[i];

	int nPosibilidades = 0;
    
    resolver(vectorSolucion, vectorConsumo, vectorContador, longitudTira, consumoMaximo, 0, 0, 0, nPosibilidades);
    
	std::cout << nPosibilidades << std::endl;

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