// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez: E12

# ifndef person_h
# define person_h

#include <iostream>
#include <stdexcept>
#include <iomanip>
#include <fstream>
#include <string>

class Person {

	int age;
	std::string name;

public:

	Person() {}
	Person(std::string name, int age) : name(name), age(age) {}

	std::string get_name() const { return name; }
	int get_age() const { return age; }
};

inline std::istream & operator >> (std::istream & in, Person & p) {

	int age;
	char space;
	std::string name;

	std::cin >> age >> space;
	getline(std::cin, name);

	std::string name_complete = space + name;

	p = Person(name_complete, age);

	return in;
}

#endif