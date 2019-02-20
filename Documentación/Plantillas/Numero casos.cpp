// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez:


#include <iostream>
#include <iomanip>
#include <fstream>


TipoSolucion resolver(TipoDatos datos) {
    
    
}


void resuelveCaso() {

    TipoSolucion sol = resolver(datos);

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