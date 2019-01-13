// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 1 <==========================//

/*COSTE:
 
 - El coste en tiempo es O(n) siendo n el numero de elementos del vector, ya que hay que hay que recorrerlo entero.
 
 - El coste en espacio adicional es O(m) siendo m el numero de elementos del vector auxiliar.
 
 */

// función que resuelve el problema
void resolver(std::vector<int>const& v_numeros, bool& esEscalera) {
    
    int cont_secuencia_actual = 1;
    std::vector<int> v_aux(v_numeros.size());
    
    int indice_numero = 0;
    
    
    for(int i = 0; i < v_numeros.size(); ++i){
    
        if(i == 0){
            v_aux[indice_numero] = cont_secuencia_actual;
        }else{
        
            if(v_numeros[i] == v_numeros[i-1]){
                ++cont_secuencia_actual;
                 v_aux[indice_numero] = cont_secuencia_actual;
            
            }else{
                cont_secuencia_actual = 1;
                v_aux[++indice_numero] = cont_secuencia_actual;
                
            }
        }

    }
    
    for(int i = 1; i < v_aux.size() && v_aux[i] != 0; ++i){
        if(v_aux[i] < v_aux[i-1])
            esEscalera = false;
    }
    
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    std::vector<int> v_numeros;
    int numero;
    
    std::cin >> numero;
    
    if (numero == -2)
        return false;
    
    
    while(numero != -1){
         v_numeros.push_back(numero);
         std::cin >> numero;
    }
   
    bool esEscalera = true;
    resolver(v_numeros, esEscalera);
    
    // escribir sol
    if(esEscalera)
        std::cout << "SI" << std::endl;
    else
        std::cout << "NO" << std::endl;
        
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/ex_feb18_sesion3_ej1.txt");
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
