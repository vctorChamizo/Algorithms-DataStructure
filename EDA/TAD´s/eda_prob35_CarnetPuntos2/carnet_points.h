// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#ifndef CARNET_POINTS
#define CARNET_POINTS

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <list>

const int MAX_POINTS = 15;

using cp_dni = std::string;
using cp_points = int;

struct tPoints {

	cp_points points; // Puntos que tienen los DNI de la lista
	std::list<cp_dni>::iterator it; // Lista de punteros a los DNI del mapa carnets.
};

class carnet_points {

	/*
		Key: DNI del nuevo condcutor registrado en la DGT
		Value: puntos que posee el carnet
	*/
	std::unordered_map<cp_dni, tPoints> carnets;

	/*
		Key: Puntos con los que cuentan los carnets
		Value: conjunto de DNI que tienen ese número de puntos
	*/
	std::unordered_map<cp_points, std::list<cp_dni>> points;

public:

	carnet_points() {}

	void new_carnet(std::string dni) { new_carnet_private(dni); }

	void rest_points(std::string dni, int points) { rest_points_private(dni, points); }

	void recover_points(std::string dni, int points) { recover_points_private(dni, points); }

	int consult(std::string dni) { return consult_private(dni); }

	int how_many_points(int points) { return how_many_points_private(points); }

	std::list<cp_dni>  list_to_points(int points) { return list_to_points_private(points); }

private:

	// COST: n(1)
	void new_carnet_private(std::string dni) {

		if (carnets.count(dni) != 0) throw std::domain_error("Conductor duplicado");
		else {

			this->points[MAX_POINTS].push_front(dni);
			this->carnets[dni] = { MAX_POINTS, points[MAX_POINTS].begin() };
		}
	}

	// COST: n(1)
	void rest_points_private(std::string dni, int p) {

		if (this->carnets.count(dni) == 0) throw std::domain_error("Conductor inexistente");
		else {

			// Si ya tiene 0 puntos no se le pueden restar mas, por tanto no hay que actualizar la lista.
			if (this->carnets.at(dni).points > 0) {

				int n_points = this->carnets.at(dni).points - p; // Numero de punto que posee actualmente.
				this->points[this->carnets[dni].points].erase(this->carnets[dni].it); // Borramos del registro de punto que poseia anteriormente.

				// El minimo de puntos que se pueden obtener es 0, por tanto, si el resultado es menor, se queda con 0.
				if (n_points < 0) { 

					this->points[0].push_front(dni);
					this->carnets[dni] = { 0, points[0].begin() };
				}
				else {

					this->points[n_points].push_front(dni);
					this->carnets[dni] = { n_points, points[n_points].begin() };
				}
			}
		}
	}

	// COST: n(1)
	void recover_points_private(std::string dni, int p) {

		if (this->carnets.count(dni) == 0) throw std::domain_error("Conductor inexistente");
		else {

			if (this->carnets.at(dni).points < 15) {

				int n_points = this->carnets.at(dni).points + p;
				this->points[this->carnets[dni].points].erase(this->carnets[dni].it);

				if (n_points > MAX_POINTS) {

					this->points[MAX_POINTS].push_front(dni);
					this->carnets[dni] = { MAX_POINTS, points[MAX_POINTS].begin() };
				}
				else {

					this->points[n_points].push_front(dni);
					this->carnets[dni] = { n_points, points[n_points].begin() };
				}
			}
		}
	}

	// COST: n(1)
	int consult_private(std::string dni) {

		if (this->carnets.count(dni) == 0) throw std::domain_error("Conductor inexistente");
		else return this->carnets[dni].points;
	}

	// COST: n(1)
	int how_many_points_private(int p) {

		if (0 > p || MAX_POINTS < p) throw std::domain_error("Puntos no validos");
		else if (this->points.count(p) == 0) return 0;
		else return this->points[p].size();
	}

	// COST: n(1)
	std::list<cp_dni> list_to_points_private(int p) {

		if (0 > p || MAX_POINTS < p) throw std::domain_error("Puntos no validos");
		else return points[p];
	}
};

#endif
