// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <vector>
#include <stack>
#include <deque>

void primerCifrado(std::string const & m, std::deque<char> & m1, std::deque<char> & m2) {

	for (int i = 0; i < m.size(); ++i) {

		if (i % 2 == 0) m1.push_back(m[i]);
		else m2.push_front(m[i]);
	}
}

void segundoCifrado(std::deque<char> & m1, std::deque<char> & m2, std::vector<char> & v) {

	while (!m1.empty()) {

		v.push_back(m1.front());
		m1.pop_front();
	}

	while (!m2.empty()) {

		v.push_back(m2.front());
		m2.pop_front();
	}
}

void descifrar(std::vector<char> const & v) {

	std::stack<char> p;

	for (int i = 0; i < v.size(); ++i) {

		if (v[i] == 'a' || v[i] == 'e' || v[i] == 'i' || v[i] == 'o' || v[i] == 'u'
			|| v[i] == 'A' || v[i] == 'E' || v[i] == 'I' || v[i] == 'O' || v[i] == 'U') {

			while (!p.empty()) {

				std::cout << p.top();
				p.pop();
			}

			std::cout << v[i];
		}
		else p.push(v[i]);
	}

	while (!p.empty()) {

		std::cout << p.top();
		p.pop();
	}
}

bool resuelveCaso() {

	std::string mensaje_cifrado;
	getline(std::cin, mensaje_cifrado);

	if (!std::cin) return false;

	std::deque<char> m1_prima, m2_prima;
	std::vector<char> vector_cifrado;
	
	primerCifrado(mensaje_cifrado, m1_prima, m2_prima);
	segundoCifrado(m1_prima, m2_prima, vector_cifrado);
	descifrar(vector_cifrado);

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