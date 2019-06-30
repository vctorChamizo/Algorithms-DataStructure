// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

#ifndef age_filter_h
#define age_filter_h

#include "Person.h"

class age_filter {

	int min_age, max_age;

public:

	age_filter() {}
	age_filter(int min_age, int max_age) : min_age(min_age), max_age(max_age) {}

	bool operator () (Person const & p) const { return p.get_age() >= min_age && p.get_age() <= max_age; };
};

#endif
