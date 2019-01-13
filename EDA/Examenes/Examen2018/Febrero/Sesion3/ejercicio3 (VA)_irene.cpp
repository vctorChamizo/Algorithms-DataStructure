// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 3 <==========================//

/*COSTE:
 
 
 */

bool esValida(std::vector<int>const& v_sol_numeros, int k_numeros, int indice_numero, std::vector<int>const& v_ancho_escalon){
   
    if(v_sol_numeros[0] != 1)
        return false;
    
    
    if(k_numeros > 0){
        if(abs(v_sol_numeros[k_numeros] - v_sol_numeros[k_numeros - 1]) > 1)
            return false;
 
        if(v_sol_numeros[k_numeros] < v_sol_numeros[k_numeros - 1])
            return false;
    
        if(v_ancho_escalon[indice_numero] < v_ancho_escalon[indice_numero - 1])
            return false;
    }
    return true;
    
}


// función que resuelve el problema
void resolver(std::vector<int>const& v_numeros, std::vector<int>& v_sol_numeros, int k_posicion_v_sol, int tamVector, std::vector<int>& v_ancho_escalon) {
    
    for(int indice_numero = 1; indice_numero <= tamVector; ++indice_numero){
        v_sol_numeros[k_posicion_v_sol] = indice_numero;
        ++v_ancho_escalon[indice_numero];
        
        if(esValida(v_sol_numeros, k_posicion_v_sol, indice_numero, v_ancho_escalon)){
            if(k_posicion_v_sol == v_sol_numeros.size()-1){
                
                for(int i = 0; i < v_sol_numeros.size(); ++i){
                    std::cout << v_sol_numeros[i] << ' ';
                }
                std::cout << std::endl;
            }else{
                resolver(v_numeros, v_sol_numeros, k_posicion_v_sol + 1, tamVector, v_ancho_escalon);
            }
        }
        
        --v_ancho_escalon[indice_numero];
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int tamVector;
    std:: cin >> tamVector;
    
    
    if (tamVector == 0)
        return false;
    
    
    std::vector<int>v_numeros(tamVector);
    
    int k_posicion_v_sol= 0;
    std::vector<int> v_sol_numeros(tamVector );
    
    std::vector<int> v_ancho_escalon(tamVector + 1);
    
    resolver(v_numeros, v_sol_numeros, k_posicion_v_sol, tamVector, v_ancho_escalon );
    
    // escribir sol
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/ex_feb18_sesion3_ej3.txt");
    auto cinbuf = std::cin.rdbuf(in.rdbuf()); //save old buf and redirect std::cin to casos.txt
#endif
    
    
    while (resuelveCaso())
        ;
    
    
    // Para restablecer entrada. Comentar para acepta el reto
#ifndef DOMJUDGE // para dejar todo como estaba al principio
    std::cin.rdbuf(cinbuf);
    system("PAUSE");
#endif
    
    return 0;
}
