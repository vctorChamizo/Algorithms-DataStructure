// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

#define INF 1000000000

bool esSolucion(std::vector<std::vector<int>>const& matriz, int indiceNumTrabajo) {
	if (matriz.size() - 1 == indiceNumTrabajo) {
		return true;
	}
	else return false;
}

// funcio´n que resuelve el problema
void resolver(std::vector<std::vector<int>>const& matriz, 
	std::vector<bool>& vector_marcas_funcionariosOcupados, 
	int& tiempoMinimo, 
	int indiceNumTrabajo, 
	int tiempoAcumulado) {

	for (int indiceFuncionario = 0; indiceFuncionario < matriz.size(); ++indiceFuncionario) {

		if (!vector_marcas_funcionariosOcupados[indiceFuncionario]) {
			tiempoAcumulado += matriz[indiceFuncionario][indiceNumTrabajo];
			vector_marcas_funcionariosOcupados[indiceFuncionario] = true;

			if (esSolucion(matriz, indiceNumTrabajo) && tiempoAcumulado < tiempoMinimo) tiempoMinimo = tiempoAcumulado;
			else resolver(matriz, vector_marcas_funcionariosOcupados, tiempoMinimo, indiceNumTrabajo + 1, tiempoAcumulado);
		
			vector_marcas_funcionariosOcupados[indiceFuncionario] = false;
			tiempoAcumulado -= matriz[indiceFuncionario][indiceNumTrabajo];
		}

	}
}

bool resuelveCaso() {

	int numFuncionariosYtrabajos;
	std::cin >> numFuncionariosYtrabajos;

	if (numFuncionariosYtrabajos == 0)return false;

	int funcionarioFilas = numFuncionariosYtrabajos;
	int trabajosColumnas = numFuncionariosYtrabajos;

	std::vector<std::vector<int>> matriz(funcionarioFilas, std::vector<int>(trabajosColumnas, 0));

	for (int i = 0; i < numFuncionariosYtrabajos; ++i)
		for (int j = 0; j < numFuncionariosYtrabajos; ++j) 
			std::cin >> matriz[i][j];
		
	std::vector<bool> vector_marcas_funcionariosOcupados(numFuncionariosYtrabajos, false);
	int tiempoMinimo = INF;
	int tiempoAcumulado = 0;
	int indiceNumTrabajo = 0; //k

	resolver(matriz, vector_marcas_funcionariosOcupados, tiempoMinimo, indiceNumTrabajo, tiempoAcumulado);

	std::cout << tiempoMinimo << std::endl;

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