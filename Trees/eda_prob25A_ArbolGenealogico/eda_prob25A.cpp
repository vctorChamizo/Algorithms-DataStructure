#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <math.h>
#include <stdlib.h>
#include <stdexcept>
#include <cstddef>

#include "bintree_eda.h"

//El coste es O(n), siendo n el numero de elementos del conjunto

template<class T>
bool esArbolGenealogico(bintree<T> const& arbol, int & edadHijo, int & numGeneracionesDistintas){

    if(arbol.empty()) {
		
        numGeneracionesDistintas = 0;
        edadHijo = -18;
        return true;
    }
    else if(arbol.left().empty() && arbol.right().empty()) {
		
        numGeneracionesDistintas = 1;
        edadHijo = arbol.root();
        return true;
    }
    else {
		
        int edadHijoIzq, edadHijoDer;
        int numGeneracionesIzq, numGeneracionesDer;
		
        bool esGenealogicoIzq = esArbolGenealogico(arbol.left(), edadHijoIzq, numGeneracionesIzq);
        bool esGenealogicoDer = esArbolGenealogico(arbol.right(), edadHijoDer, numGeneracionesDer);
        
        bool condicionPadre = (arbol.root() - edadHijoIzq >= 18 ) && (arbol.root() - edadHijoDer >= 18);
        
        bool condicionHijos = edadHijoIzq - edadHijoDer >= 2;
        
        edadHijo = arbol.root();
        numGeneracionesDistintas = std::max(numGeneracionesIzq, numGeneracionesDer) + 1;
        
        return esGenealogicoIzq && esGenealogicoDer && condicionPadre && condicionHijos;    
    }
}


void resuelveCaso() {
	
    bintree<int> arbol = leerArbol(-1);
    int edadHijo, numGeneracionesDistintas;
    
    bool esGenealogico = esArbolGenealogico(arbol, edadHijo, numGeneracionesDistintas);
    
    if(esGenealogico) std::cout << "SI " << numGeneracionesDistintas;
    else std::cout << "NO";
    
    std::cout << std::endl;
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
#endif
    
    return 0;
}
