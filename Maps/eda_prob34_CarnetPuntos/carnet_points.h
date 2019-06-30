// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#ifndef CARNET_POINTS
#define CARNET_POINTS

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <set>

/*
	Para resolver este problema se utilizan dos diccionarios no ordenados. En uno de ellos se almacena cada uno de los 
	nuevos conductores que se registran en el DGT, mientras que en el otro diccionario se almacena como clave los puntos y como 
	valor el conjunto de conductores cuyos carnets poseen discho puntos.

	De este forma, todas las operaciones que nos plantea el problema pueden reaizarse con un coste constante.
*/

const int MAX_POINTS = 15;

using cp_dni = std::string;
using cp_points = int;

class carnet_points {
	
	/* 
		Key: DNI del nuevo condcutor registrado en la DGT
		Value: puntos que posee el carnet
	*/
	std::unordered_map<cp_dni, cp_points> carnets;

	/*
		Key: Puntos con los que cuentan los carnets
		Value: conjunto de DNI que tienen ese número de puntos
	*/
	std::unordered_map<cp_points, std::set<cp_dni>> points;

public:

	carnet_points() {}

	void new_carnet(std::string dni) { new_carnet_private(dni); }

	void rest_points(std::string dni, int points) { rest_points_private(dni, points); }

	int consult(std::string dni) { return consult_private(dni); }

	int how_many_points(int points) { return how_many_points_private(points); }

private:

	// COST: n(1)
	void new_carnet_private(std::string dni) {

		if (this->carnets.count(dni) != 0) throw std::domain_error("Conductor duplicado");
		else {

			this->carnets[dni] = MAX_POINTS;
			this->points[MAX_POINTS].insert(dni);
		}
	}

	// COST: n(1)
	void rest_points_private(std::string dni, int p) {

		if (this->carnets.count(dni) == 0) throw std::domain_error("Conductor inexistente");
		else {

			int n_points = this->carnets.at(dni) - p;

			this->points[this->carnets.at(dni)].erase(dni);
			
			if (n_points < 0) {

				this->carnets[dni] = 0;
				this->points[0].insert(dni);
			}
			else {

				this->carnets[dni] = n_points;
				this->points[n_points].insert(dni);
			}
		}
	}

	// COST: n(1)
	int consult_private(std::string dni) {

		if (this->carnets.count(dni) == 0) throw std::domain_error("Conductor inexistente");
		else return this->carnets.at(dni);
	}

	// COST: n(1)
	int how_many_points_private(int p) {

		if (0 > p || MAX_POINTS < p) throw std::domain_error("Puntos no validos");
		else if (this->points.count(p) == 0) return 0;
		else return this->points.at(p).size();
	}
};

#endif
