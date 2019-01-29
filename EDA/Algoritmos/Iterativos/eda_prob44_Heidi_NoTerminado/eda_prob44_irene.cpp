// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>

//==========================>   EJERCICIO 44 <==========================//

/*COSTE:
    O(n) siendo n el numero de elementos del vector
 
 */

// función que resuelve el problema
int resolver(std::vector<int>const& v_numeros, int tamSecuenciaMin,  std::vector<int>& v_datos_construir) {
    
    int numMaximo = v_numeros[v_numeros.size() -1];
    
    int indiceLongMaxSecuencia = -1;
    int longSecuencia = 0, longMaxSecuencia = 0;
    
    for(int i = v_numeros.size() - 1 ; i >= 0; --i){
        
        
        if(v_numeros[i] >= numMaximo){
            
            if(v_numeros[i] > numMaximo){
                longSecuencia = 1;
                numMaximo = v_numeros[i];
                
            }else{      //en caso de que sea igual al numero maximo
                
                ++longSecuencia;
                
                if(longSecuencia >= tamSecuenciaMin){
                    if(longSecuencia == tamSecuenciaMin){
                        ++indiceLongMaxSecuencia;
                        v_datos_construir[indiceLongMaxSecuencia] = i + (longSecuencia - 1);
                    }
                    
                    if(longSecuencia > longMaxSecuencia){
                        longMaxSecuencia = longSecuencia;
                    }
                }
            }
        }else{
            longSecuencia = 0;
        }
    }
    return longMaxSecuencia;
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numElementos , tamSecuenciaMin;
    std::cin >> numElementos >> tamSecuenciaMin;
    
    if (! std::cin)
        return false;
    
    std::vector<int> v_numeros(numElementos);
    int num;
    
    for(int i = 0; i < numElementos; ++i ){
        std::cin >> num;
        v_numeros[i] = num;
    }
    
    std::vector<int> v_datos_construir(numElementos, -1);
    int longMaxSecuencia = 0;
    int sol = resolver(v_numeros, tamSecuenciaMin, v_datos_construir);
    
    // escribir sol
    
    
    
    int numLLanos = 0;
    for(int i = 0; i < v_datos_construir.size() - 1 && v_datos_construir[i] != -1; ++i){
        ++numLLanos;
    }
    
    if(sol == 0){
        std::cout << 0 << ' ' << 0 << ' ' << std::endl;
        
    }else{
        std::cout << sol << ' ' << numLLanos << ' ' ;
        for(int i = 0; i < v_datos_construir.size() - 1 && v_datos_construir[i] != -1; ++i){
            std::cout << v_datos_construir[i] << ' ';
        }
        
        std::cout << std::endl;
    }
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda44.txt");
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
