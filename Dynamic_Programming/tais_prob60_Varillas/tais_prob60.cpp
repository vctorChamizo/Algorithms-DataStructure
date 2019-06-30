// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <algorithm>
#include <limits.h>

#include "Matriz.h"

struct tStick {

	int cost;
	int length;
};

/*
	PROBLEMA:

		¿Es posible obtener la varilla de longitud deseada soldadno alguna de las varillas dadas?


	FUNCIÓN:

		sticks(i, j) = es posible obtener la varilla de longitud j teniendo en cuenta las varilla de 1 a i.


	CASOS BASES:

		sticks(0, j) = FALSE -> si noy varillas no se puede obtener la varilla de longitud j.

		sticks(i, 0) = TRUE -> si la longitud de la varilla deseada es 0, se puede obtener con cualquier varilla.


	FUNCION RECURSIVA:

							sticks(i - 1, j)								si li > j
		sticks(i, j) = {
							sticks(i - 1, j) || sticks(i - 1, j - li)		si li <= j


			siendo li = longitud de la varilla actual


	COSTES:

		- Coste en espacio adicional : (N * L) -> siendo N el numero de varillas y L la longitud de varilla deseada.

		- Coste en tiempo: (N * L) + (N * L) -> siendo N el numero de varillas y L la longitud de varilla deseada.


	COSTE TOTAL:

		O(N * L) -> siendo N el numero de varillas y L la longitud de varilla deseada.
*/
bool problem_1(int N, int L, std::vector<tStick> const & v_s) {

	Matriz<bool> matrix(N + 1, L + 1, false);

	matrix[0][0] = true;

	for (int i = 1; i <= N; ++i) {

		matrix[i][0] = true;

		for (int j = 1; j <= L; ++j) {

			if (v_s[i].length > j) matrix[i][j] = matrix[i - 1][j];
			else matrix[i][j] = matrix[i - 1][j] || matrix[i - 1][j - v_s[i].length];
		}
	}

	return matrix[N][L];
}

/*
	PROBLEMA:

		Calcular el numero total de maneras de obtener la varilla deseada soldando algunas de las 
		varillas dadas, sin que importe el orden de soldadura.


	FUNCIÓN:

		sticks(i, j) = numero total de maneras de formar varillas de longitud j teniendo en cuenta las varilla de 1 a i.


	CASOS BASES:

		sticks(0, j) = 0 -> si noy hay varillas no se puede obtener ninguna varilla de longitud j.

		sticks(i, 0) = 1 -> si la longitud de la varilla deseada es 0 solo hay una forma de conseguir 
							dicha varilla (que la varilla tenga longitud 0).


	FUNCION RECURSIVA:

							sticks(i - 1, j)								si li > j
		sticks(i, j) = {
							sticks(i - 1, j) + sticks(i - 1, j - li)		si li <= j


			siendo li = longitud de la varilla actual


	COSTES:

		- Coste en espacio adicional : (N * L) -> siendo N el numero de varillas y L la longitud de varilla deseada.

		- Coste en tiempo: (N * L) + (N * L) -> siendo N el numero de varillas y L la longitud de varilla deseada.
*/
int problem_2(int N, int L, std::vector<tStick> const & v_s) {

	Matriz<int> matrix(N + 1, L + 1, 0);

	matrix[0][0] = 1;

	for (int i = 1; i <= N; ++i) {

		matrix[i][0] = 1;

		for (int j = 1; j <= L; ++j) {

			if (v_s[i].length > j) matrix[i][j] = matrix[i - 1][j];
			else matrix[i][j] = matrix[i - 1][j] + matrix[i - 1][j - v_s[i].length];
		}
	}

	return matrix[N][L];
}

/*
	PROBLEMA:

		Calcular el numero minimo de varillas necesarias para obtener la varilla deseada.


	FUNCIÓN:

		sticks(i, j) = minimo numoer de varillas que se tienen que utilizar oara obtener una varilla
					   de longitud j teniendo en cuenta las varilla de 1 a i.


	CASOS BASES:

		sticks(0, j) = INF -> si noy hay varillas se necesitan infinitas varillas para alcanzar la longitud.

		sticks(i, 0) = 1 -> si la longitud de la varilla deseada es 0, no se necesita ninguna varilla.


	FUNCION RECURSIVA:

							sticks(i - 1, j)									si li > j
		sticks(i, j) = {
							min(sticks(i - 1, j), sticks(i - 1, j - li)	+ 1)	si li <= j


			siendo li = longitud de la varilla actual


	COSTES:

		- Coste en espacio adicional : (N * L) -> siendo N el numero de varillas y L la longitud de varilla deseada.

		- Coste en tiempo: (N * L) + (N * L) -> siendo N el numero de varillas y L la longitud de varilla deseada.
*/
long long int problem_3(int N, int L, std::vector<tStick> const & v_s) {

	Matriz<long long int> matrix(N + 1, L + 1, INT_MAX);

	matrix[0][0] = 0;
	 
	for (int i = 1; i <= N; ++i) {

		matrix[i][0] = 0;

		for (int j = 1; j <= L; ++j) {

			if (v_s[i].length > j) matrix[i][j] = matrix[i - 1][j];
			else matrix[i][j] = std::min(matrix[i - 1][j], matrix[i - 1][j - v_s[i].length] + 1);
		}
	}

	return matrix[N][L];
}

/*
	PROBLEMA:

		Calcular el minimo coste posible necesario para obtener la varilla deseada.

		 
	FUNCIÓN:

		sticks(i, j) = minimo coste para formar la varilla de longitud j teniendo en cuenta las varilla de 1 a i.


	CASOS BASES:

		sticks(0, j) = INF -> si no hay varillas el coste para formar la varilla deseada es infinito.

		sticks(i, 0) = 0 -> si la longitud de la varilla deseada es 0, no hace falta ninguna varilla para conseguirla
							por tanto el coste minimo es 0.


	FUNCION RECURSIVA:

							sticks(i - 1, j)									si li > j
		sticks(i, j) = {
							min(sticks(i - 1, j), sticks(i - 1, j - li)	+ ci)	si li <= j


			siendo:
				li = longitud de la varilla actual.
				ci = coste de cada varilla.


	COSTES:

		- Coste en espacio adicional : (N * L) -> siendo N el numero de varillas y L la longitud de varilla deseada.

		- Coste en tiempo: (N * L) + (N * L) -> siendo N el numero de varillas y L la longitud de varilla deseada.
*/
long long int problem_4(int N, int L, std::vector<tStick> const & v_s) {

	Matriz<long long int> matrix(N + 1, L + 1, INT_MAX);

	matrix[0][0] = 0;

	for (int i = 1; i <= N; ++i) {

		matrix[i][0] = 0;

		for (int j = 1; j <= L; ++j) {

			if (v_s[i].length > j) matrix[i][j] = matrix[i - 1][j];
			else matrix[i][j] = std::min(matrix[i - 1][j], matrix[i - 1][j - v_s[i].length] + v_s[i].cost);
		}
	}

	return matrix[N][L];
}

bool resuelveCaso() {

	int N;
	std::cin >> N;

	if (!std::cin) return false;

	int L;
	std::cin >> L;

	std::vector<tStick> v_sticks(N + 1);

	for (int i = 1; i <= N; ++i) {

		std::cin >> v_sticks[i].length;
		std::cin >> v_sticks[i].cost;
	}

	if (problem_1(N, L, v_sticks)) std::cout << "SI" << ' ' << problem_2(N, L, v_sticks) << ' ' << problem_3(N, L, v_sticks) << ' ' << problem_4(N, L, v_sticks);
	else std::cout << "NO";

	std::cout << std::endl;

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