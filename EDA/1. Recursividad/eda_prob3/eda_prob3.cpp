// Nombre del alumno Víctor Chamizo Rodríguez
// Usuario del Juez E12

/*
El problema se resulve aplicando recursividad no final, de tal modo que por cada 
llamada a la funcion se descompone el numero en una cifra menos guardando junto a el 
la posición que le corresponde al invertirlo en forma de potencia de 10.
*/

#include <iostream>
#include <iomanip>
#include <fstream>


struct tInverso {

	int numero;
	int pot;
};


tInverso invertir(int n) {

	tInverso inv;

	if (n / 10 == 0) {

		inv.numero = n;
		inv.pot = 10;
		
		return inv;
	}
	else {

		int aux = n % 10;

		inv = invertir(n / 10);

		inv.numero = (aux * inv.pot) + inv.numero;
		inv.pot = inv.pot * 10;

		return inv;
	}
}


bool resuelveCaso() {

	int numero;

	std::cin >> numero;

	if (!std::cin) return false;

	tInverso invertido = invertir(numero);

	std::cout << invertido.numero << std::endl;

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