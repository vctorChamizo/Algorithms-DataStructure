// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#ifndef LIBRARY
#define LIBRARY

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <unordered_map>
#include <map>
#include <list>

using name_book = std::string;
using purchased_books = int;
using book_list = std::list<name_book>;
using it_book = std::list<name_book>::iterator;

struct info_book {

	int n_books; // Numero de ejemplares de los que dispone la libreria.
	int n_books_purchased = 0; // Numero de ejemplares que se han vendido;
	it_book book_position; // Posición que ocupa el libro en el top de ventas;
};

class library {

	const int TOP_TEN = 10;

	/*
		KEY: nombre del libro.
		VALUE: información del libro -> referenciado en la estructura 'info_book'.
	*/
	std::unordered_map<name_book, info_book> books;

	/*
		KEY: número de ventas que obstentan los libros;
		VALUE: lista de nombre de los libros que obstenta ese numero de ventas
	*/
	std::map<int, std::list<name_book>, std::greater<int>> top_sales; // Manejamos el orden del mapa de mayor a menor;

public:

	library() {}

	// COSTE: O(1).
	void new_book (int n, name_book b) {

		// Si n == 0 -> el libro ya está registrado en el sistema pero no tiene ejemplares disponibles.
		if (n == 0) this->books[b].n_books = 0;

		// Si el libro no está registrado en el sistema -> se registra.
		else if (this->books.count(b) == 0) this->books[b].n_books = n;

		// Si el libro ya está registrado en el sistema -> se actualizan sus ejemplares.
		else this->books[b].n_books = this->books[b].n_books + n;
	}
	
	// COSTE: O(log(n)) -> siendo n el número de elementos del mapa 'top_sales'.
	void buy_book (name_book b) {

		auto book = this->books.find(b);

		if (this->books.end() == book) throw std::invalid_argument("Libro no existente");
		else if (book->second.n_books == 0) throw std::out_of_range("No hay ejemplares");
		else {

			// Si el libro ya ha sido vendido -> se elimina la antigua posición que obstentaba en el top_sales.
			if (book->second.n_books_purchased > 0) this->top_sales[book->second.n_books_purchased].erase(book->second.book_position);

			int n_sales = ++book->second.n_books_purchased; // Actualizamos el numero de ventas que posee el libro;
			book->second.n_books--; // Actualizamos el numero de ejemplares que posee la libreria.

			// Actualizamos la posición del libro en el top_sales.
			this->top_sales[n_sales].push_front(b);
			this->books[b].book_position = this->top_sales[n_sales].begin();
		}
	}
	
	// COSTE: O(1).
	bool has_book (name_book b) { return this->books.end() != this->books.find(b); }

	// COSTE: O(log(n)) -> siendo n el número de elementos del mapa 'top_sales'.
	void delete_book (name_book b) {

		auto book = this->books.find(b);

		// Si el libro se encuentra registrado en el sistema
		if (this->books.end() != book) {

			// Si se ha vendido alguna ejemplpar del libro -> eliminamos de la top_sales.
			if (book->second.n_books_purchased > 0) this->top_sales[book->second.n_books_purchased].erase(book->second.book_position);
			
			this->books.erase(b); // Eliminamos el libro del sistema.
		}
	}

	// COSTE: O(n).
	int copies_book (name_book b) {

		if (this->books.count(b) == 0) throw std::invalid_argument("Libro no existente");
		else return this->books[b].n_books;
	}

	// COSTE: O(1) -> para todos los casos el número máximo de elementos consultado es 10 (= TOP_TEN).
	book_list get_top_ten () {

		book_list list;
		auto it_top_sales = this->top_sales.begin();

		// Iteramos sobre el mapa de top_sales en los diferentes numeros de ventas.
		while (it_top_sales != this->top_sales.end() && list.size() < TOP_TEN) {

			auto it_book_sales = it_top_sales->second.begin();

			// Iteramos por cada uno de los libros que possen esos números de ventas.
			while (it_book_sales != it_top_sales->second.end() && list.size() < TOP_TEN) {

				list.push_back(*it_book_sales);
				++it_book_sales;
			}

			++it_top_sales;
		}

		return list;
	}
};

#endif
