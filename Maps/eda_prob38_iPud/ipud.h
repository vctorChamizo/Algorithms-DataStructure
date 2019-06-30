// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#ifndef IPUD
#define IPUD

#include <iostream>
#include <iomanip>
#include <stdexcept>
#include <string>
#include <list>
#include <unordered_map>

using song = std::string;
using artist = std::string;
using duration = int;
using it = std::list<song>::iterator;

struct info_song {

	artist art; // Artista de la cancion.
	duration dur; // Duracion de la cancion.

	bool is_in_playlist = false; // Indica si la cancion se encuentra en la playlist.
	bool is_in_playedlist = false; // Indica si la cancion se encuentra en la playedlist.

	it it_playlist; // Indica la posición de la cancion dentro de la playlist.
	it it_playedlist; // Indica la posición de la cancion dentro de la playedlist.

	info_song() {}

	info_song(artist a, duration d) : art(a), dur(d) {}
};

class ipud {

	/*
		KEY: nombre de la cancion.
		VALUE: información de la cancion representada por la estructura "info_song"
	*/
	std::unordered_map<song, info_song> songs;

	std::list<song> play_list; // Lista de reproduccion.
	std::list<song> played_list; // Lista de canciones que ya han sido reproducidas.

	int duration_playlist = 0; // Suma de las duraciones de las canciones contenidas en la playlist.

public:

	ipud() {}

	// COSTE: O(1);
	void addSong (song s, artist a, duration d) {

		// Si ya existe una cancion con el mismo nombre --> ERROR.
		if (this->songs.count(s) != 0) throw std::domain_error("addSong");
		else this->songs[s] = { a, d }; // Registramos una nueva cancion.
	}

	// COSTE: O(1);
	void addToPlaylist (song s) {

		auto it_song = this->songs.find(s);

		// Si la cancion no ha sido registrada --> ERROR.
		if (this->songs.end() == it_song) throw std::domain_error("addToPlaylist");

		// Si la cancion no se encuentra en la playlist.
		else if (!it_song->second.is_in_playlist) {

			auto position_playlist = this->play_list.insert(this->play_list.end(), s); // Añadimos la cancion al final de la playlist.

			it_song->second.is_in_playlist = true; // Actualizamos el estado de la cancion.
			it_song->second.it_playlist = position_playlist; // Registramos la posicion que la cancion ocupa en la playlist.

			this->duration_playlist += it_song->second.dur; // Actualizamos la duración total de la playist.
		}
	}

	// COSTE: O(1);
	song current () {

		if (this->play_list.size() == 0) throw std::domain_error("current");
		else return this->play_list.front(); // Se devuelve la primera cancion a reproducir en la playlist.
	}

	// COSTE: O(1);
	song play () {

		std::string name_song = "";

		if (!play_list.empty()) {

			name_song = this->play_list.front(); // Guardamos el nombre de la primera cancion a reproducir en la playlist.
			this->play_list.pop_front(); // Borramos la cancion de la playlist.

			auto it_song = this->songs.find(name_song); // Obtenemos el iterador de la canción para poder operar con el.

			it_song->second.is_in_playlist = false; // Actualizamos el estado la cancion.

			// Si la canción ya estaba en la played_list -> se borra.
			// Si no estaba en la played_list -> actualizamos su estado.
			if (it_song->second.is_in_playedlist) this->played_list.erase(it_song->second.it_playedlist); 
			else it_song->second.is_in_playedlist = true; 

			// Actualzimos la lista de canciones reproducidas introduciendo la nueva cancion.
			// Registramos la posicion de la cancion en la playedlist.
			auto position_playedlist = this->played_list.insert(this->played_list.begin(), name_song);
			it_song->second.it_playedlist = position_playedlist; 

			this->duration_playlist -= it_song->second.dur; // Actualizamos el tiempo de reproducción de la lista.
		}

		return name_song;
	}

	// COSTE: O(1);
	int totalTime () { return this->duration_playlist; }

	// COSTE: O(n) -> siendo n el numero de canciones mas recientes reproducidas.
	std::list<song> recent (int n) {

		std::list<song> list_songs_recent;
		auto it = this->played_list.begin();

		while (it != this->played_list.end() && list_songs_recent.size() < n) {

			list_songs_recent.push_back(*it);

			++it;
		}

		return list_songs_recent;
	}

	// COSTE: O(1);
	void deleteSong (song s) {

		auto it_song = this->songs.find(s);

		// Si está en la playlist --> eliminamos la cancion y actualizamos el tiempo de duracion de la playlist.
		if (it_song->second.is_in_playlist) {

			this->play_list.erase(it_song->second.it_playlist);
			this->duration_playlist -= it_song->second.dur;
		}

		// Si esta en la playedlist --> eliminamos la cancion.
		if (it_song->second.is_in_playedlist) this->played_list.erase(it_song->second.it_playedlist);

		//Eliminamos la cancion del registro de canciones.
		this->songs.erase(s);
	}
};

#endif
