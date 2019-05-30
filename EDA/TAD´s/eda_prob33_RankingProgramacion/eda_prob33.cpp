// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: E12

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <unordered_map>
#include <map>
#include <set>
#include <list>

const int PENALITATION = 20;

using name_team = std::string;
using name_problem = std::string;
using n_correct_problems = int;

struct data_solution {

	name_team team; // Nombre del equipo en solucionar el problema.
	int time; // Tiempo en resolver el problema.

	/*
		Se ordenan de menor a mayor en cuanto al tiempo de reolucion del problema.
		En caso de que el tiempo sea igual -> se ordenan alfabeticamente por el nombre de los equipos.
	*/
	bool operator < (data_solution const & ds) const { return time < ds.time || (time == ds.time && team < ds.team); }
};

struct data_problem {

	int time_to_correct; // Tiempo que ha tardado el equipo en sacarlo correcto.
	bool is_correct; // Indica si el problema ya ha sido resuelto o no
};

struct data_problems {

	/*
		KEY: nombre del problema
		VALUE: estrucutra con los datos del problema. Especificada en 'data_problem'.
	*/
	std::unordered_map<name_problem, data_problem> problems;
	n_correct_problems n_corrects; // Numero de problemas que han sido resueltos correctamente.
	int total_correct_time; //Tiempo total en resolver los problemas correctamente.
};

void resuelveCaso() {

	/*
		KEY: nombre del equipo.
		VALEU: datos de los problemas que ha resuelto cada uno de los equipos. Los datos de los problemas se encuentran especificados en la estructura 'data_problems'.
	
		** Se utiliza un mapa desordenado porque no es nesario tener ordeandas las clave **
	*/
	std::unordered_map<name_team, data_problems> teams;

	name_team nt;
	name_problem np;
	std::string c;
	int t;

	std::cin >> nt;

	while (nt != "FIN") {

		std::cin >> np >> t >> c;

		if (c != "AC") { // Si el problema NO ha sido calificado como correcto.

			auto it_team = teams.find(nt);

			if (it_team == teams.end()) { // Si el equipo aun no ha sido registrado -> se regitra el equipo y el problema fallido

				teams[nt]; // Se registra el equipo.
				auto it_new_team = teams.find(nt);

				it_new_team->second.n_corrects = 0; // El numero de problemas que ha resuelto correctamente es 0.
				it_new_team->second.problems[np].time_to_correct = PENALITATION; // Se añade el tiempo de penalización que se aplicará cuando lo solucione correctamente.
				it_new_team->second.problems[np].is_correct = false; // El estado del problema es incorrecto.
			}

			// Si ya estaba registrado pero todavia no ha resuelto el problema -> se actualiza el tiempo de penalización del problema.
			else if (!it_team->second.problems[np].is_correct) it_team->second.problems[np].time_to_correct += PENALITATION;
		}
		else { // Si el problema ha sido calificado como correcto

			auto it_team = teams.find(nt);

			if (it_team == teams.end()) { // Si el equipo aun no ha sido registrado -> se registra el equipo y el problema correcto

				teams[nt]; // Se registra el equipo.
				auto it_new_team = teams.find(nt);

				it_new_team->second.problems[np].time_to_correct = t; // Se registra el tiempo que han tardado en resolver el problema correctamente.
				it_new_team->second.problems[np].is_correct = true; // Se actualza el estado del problema a correcto.

				it_new_team->second.n_corrects = 1; // El numero de problemas que han resulto correctamente es 1.
				it_new_team->second.total_correct_time = t; // El tiempo total de problemas acertados es el mismo que han tardado en resolver el primer problema.
			}
			
			// Si ya estaba registrado pero todavia no ha resuelto el problema -> se actualizan los datos del problema
			else if (!it_team->second.problems[np].is_correct) {

				it_team->second.problems[np].time_to_correct += t; // Se actualiza el tiempo que ha tardado en resolver el problema correctamente + las posibles penlizaciones.
				it_team->second.problems[np].is_correct = true; // Se actualza el estado del problema a correcto.

				++it_team->second.n_corrects; // Se suma uno al número de problemas que lleva el equipo.
				it_team->second.total_correct_time += it_team->second.problems[np].time_to_correct; // Se actaliza el tiempo total que lleva empleado en la resolucion de problemas correctos.
			}
		}

		std::cin >> nt;
	}

	// Una vez que se han registrado y clasificado todos los problemas realizados por los equipos 
	// se ordenan en el ranking.

	/*
		KEY: numero de problemas resultos correctamente.
		VALEU: conjunto con los dato de dichos problemas. Los datos de las soluciones están especificados en la estructura 'data_solution'.

		** Ordenado de mayor -> menor **

		** Se utiliza un mapa para ordenar de mayor a menor el número de problemas y saber quien es el ganador **
	*/
	std::map<n_correct_problems, std::set<data_solution>, std::greater<int>> ranking;

	for (auto _it = teams.begin(); _it != teams.end(); ++_it)
		ranking[_it->second.n_corrects].insert({ _it->first, _it->second.total_correct_time });
	
	for (auto it_ranking = ranking.begin(); it_ranking != ranking.end(); ++it_ranking) {

		for (auto it_t = it_ranking->second.begin(); it_t != it_ranking->second.end(); ++it_t)
			std::cout << it_t->team << ' ' << it_ranking->first << ' ' << it_t->time << std::endl;
	}

	std::cout << "----" << std::endl;
}

int main() {

#ifndef DOMJUDGE
	std::ifstream in("datos.txt");
	auto cinbuf = std::cin.rdbuf(in.rdbuf());
#endif 

	int numCasos;
	std::cin >> numCasos;
	for (int i = 0; i < numCasos; ++i) resuelveCaso();

#ifndef DOMJUDGE
	std::cin.rdbuf(cinbuf);
	system("PAUSE");
#endif

	return 0;
}