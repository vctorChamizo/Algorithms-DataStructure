// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez: TAIS58

#ifndef FREE_LOVE_H
#define FREE_LOVE_H

#include <iostream>
#include <iomanip>
#include <fstream>

#include <vector>
#include <queue>

#define PARED '#'
#define ENTRADA 'E'
#define SALIDA 'P'
#define CASILLA_VIGILADA '&'

struct Pixel {

	int fila;
	int columna;
};

const std::pair<int, int> direcciones[4] = { {0,1}, {-1,0}, {0, -1}, {1,0} };

class free_love {

	std::vector<std::vector<bool>> marked;
	std::vector<std::vector<size_t>> distTo;
	int filaEntrada;
	int columnaEntrada;
	int filaSalida;
	int columnaSalida;
	bool entradaVigilada;
	bool salidaVigilada;

public:

	free_love(std::vector<std::vector<char>> & imagen) : marked(imagen.size(), std::vector<bool>(imagen[0].size(), false)),
		distTo(imagen.size(), std::vector<size_t>(imagen[0].size(), 0)), entradaVigilada(false), salidaVigilada(false) {

		colocarCasillasVigiladasPorSensores(imagen);

		if (!entradaVigilada && !salidaVigilada) bfs(imagen, filaEntrada, columnaEntrada);
	}

	// ¿Hay camino de la entrada a la salida?
	bool hasPathToExit() const { return marked[filaSalida][columnaSalida]; }

	// Devuelve el numero minimo de casillas desde la entrada a la salida
	size_t distanceToExit() const { return distTo[filaSalida][columnaSalida]; }

private:

	bool esUnSensor(char const& pixel) const { return isdigit(pixel); }

	bool esValida(int fila, int columna, std::vector<std::vector<char>> const& imagen) const { return fila >= 0 && fila < imagen.size() && columna >= 0 && columna < imagen[0].size(); }

	bool noEsPared(char const& pixel) const { return pixel != PARED; }

	bool noEstaVigiladaPorSensores(char const& pixel) const { return pixel != CASILLA_VIGILADA; }

	void colocarCasillasVigiladasPorSensores(std::vector<std::vector<char>> & imagen) {

		int alcanceSensor;

		for (int fila = 0; fila < imagen.size(); ++fila) {

			for (int columna = 0; columna < imagen[0].size(); ++columna) {

				if (esUnSensor(imagen[fila][columna])) {

					alcanceSensor = imagen[fila][columna] - '0';
					imagen[fila][columna] = CASILLA_VIGILADA;
					colocarCasillasVigiladasPorSensor(fila, columna, imagen, alcanceSensor);
				}
				else if (imagen[fila][columna] == ENTRADA) {

					this->filaEntrada = fila;
					this->columnaEntrada = columna;
				}
				else if (imagen[fila][columna] == SALIDA) {

					this->filaSalida = fila;
					this->columnaSalida = columna;
				}
			}
		}
	}

	void colocarCasillasVigiladasPorSensor(int fila, int columna, std::vector<std::vector<char>> & imagen, int alcanceSensor) {

		int limiteInferiorFila = fila - alcanceSensor, limiteSuperiorFila = fila + alcanceSensor;
		int limiteInferiorColumna = columna - alcanceSensor, limiteSuperiorColumna = columna + alcanceSensor;

		for (auto const& direccion : direcciones) {

			int f = fila + direccion.first;
			int c = columna + direccion.second;

			while (esValida(f, c, imagen) && noEsPared(imagen[f][c]) && c >= limiteInferiorColumna && c <= limiteSuperiorColumna && f >= limiteInferiorFila && f <= limiteSuperiorFila) {
				
				if (imagen[f][c] == ENTRADA) entradaVigilada = true;
				else if (imagen[f][c] == SALIDA) salidaVigilada = true;
				else if (!esUnSensor(imagen[f][c])) imagen[f][c] = CASILLA_VIGILADA;

				c += direccion.second;
				f += direccion.first;
			}
		}
	}

	void bfs(std::vector<std::vector<char>> const& imagen, int filaOrigen, int columnaOrigen) {

		std::queue<Pixel> cola;

		marked[filaOrigen][columnaOrigen] = true;
		cola.push({ filaOrigen, columnaOrigen });

		while (!cola.empty() && !hasPathToExit()) {

			auto casillaActual = cola.front();
			cola.pop();

			for (auto direccion : direcciones) {

				int fila_ady = direccion.first + casillaActual.fila;
				int columna_ady = direccion.second + casillaActual.columna;

				if (esValida(fila_ady, columna_ady, imagen) && !marked[fila_ady][columna_ady] && noEstaVigiladaPorSensores(imagen[fila_ady][columna_ady]) && noEsPared(imagen[fila_ady][columna_ady])) {

					marked[fila_ady][columna_ady] = true;
					distTo[fila_ady][columna_ady] = distTo[casillaActual.fila][casillaActual.columna] + 1;
					cola.push({ fila_ady, columna_ady });
				}
			}
		}
	}
};

#endif
