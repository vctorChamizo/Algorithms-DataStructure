// Nombre del alumno: Víctor Chamizo Rodríguez
// Usuario del Juez:

#include <iostream>
#include <iomanip>
#include <fstream>


TipoSolucion resolver(TipoDatos datos) {
    
    
}


bool resuelveCaso() {
    
    if (! std::cin)
        return false;
    
    TipoSolucion sol = resolver(datos);
   
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