// Nombre del alumno: Víctor Chamizo Rodríguez 
// Usuario del Juez:

#include <iostream>
#include <iomanip>
#include <fstream>

bool resuelveCaso() {
    
    if () return false;

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