// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#define INF 1000000000


//==========================>   EJERCICIO 30 <==========================//



bool esSolucion(std::vector<std::vector<int>>const& matriz, int indiceNumTrabajo){
    if(matriz.size() - 1 == indiceNumTrabajo){
        return true;
    }else return false;
}

// función que resuelve el problema
void resolver( std::vector<std::vector<int>>const& matriz, std::vector<bool>& vector_marcas_funcionariosOcupados, int& tiempoMinimo, int indiceNumTrabajo, int tiempoAcumulado, std::vector<int>const& vector_estimacionMinima) {
    
    
    for(int indiceFuncionario = 0; indiceFuncionario < matriz.size(); ++indiceFuncionario){
       
        if(!vector_marcas_funcionariosOcupados[indiceFuncionario]){ //esValida ==> Si el funcionario no esta ocupado
            tiempoAcumulado += matriz[indiceFuncionario][indiceNumTrabajo];
            vector_marcas_funcionariosOcupados[indiceFuncionario] = true;
            
            if(esSolucion(matriz, indiceNumTrabajo)){
                if(tiempoAcumulado < tiempoMinimo){
                    tiempoMinimo = tiempoAcumulado;
                }
                
            }else{
                /* PODA */
                int tiempoEstimado = tiempoAcumulado + vector_estimacionMinima[indiceNumTrabajo + 1];
                
                if(tiempoEstimado < tiempoMinimo){
                    resolver(matriz, vector_marcas_funcionariosOcupados, tiempoMinimo, indiceNumTrabajo + 1, tiempoAcumulado, vector_estimacionMinima);
                }
                
            }
            
            vector_marcas_funcionariosOcupados[indiceFuncionario] = false;
            tiempoAcumulado -= matriz[indiceFuncionario][indiceNumTrabajo];
            
        }
            
        
    }
 
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numFuncionariosYtrabajos;
    std::cin >> numFuncionariosYtrabajos;
    if (numFuncionariosYtrabajos == 0)
        return false;
    
    
    int funcionarioFilas = numFuncionariosYtrabajos;
    int trabajosColumnas = numFuncionariosYtrabajos;
    
    std::vector<std::vector<int>> matriz(funcionarioFilas, std::vector<int> (trabajosColumnas                                                                      , 0));
    int tiempoPorCadaTrabajo = 0;
   


   
    for(int i = 0; i < numFuncionariosYtrabajos; ++i){
        for(int j = 0; j < numFuncionariosYtrabajos; ++j){
            std::cin >> tiempoPorCadaTrabajo;
            matriz[i][j] = tiempoPorCadaTrabajo;
        }
    }
    
    std::vector<bool> vector_marcas_funcionariosOcupados(numFuncionariosYtrabajos, false); //False implica que los funcionarios no tienen asignado ninguna tarea
    
    int tiempoMinimo = INF;
    int tiempoAcumulado = 0;
    int indiceNumTrabajo = 0; //k
    
    
    std::vector<int> vector_estimacionMinima(numFuncionariosYtrabajos);
    int minimoEsfuerzo;
   
    /*ESTIMACION:      Comprueba por cada columna cual es el trabajo que menos esfuerzo requiere y lo añade a un vector de estimacion min*/
    for(int j = 0; j < matriz.size(); ++j ){
        minimoEsfuerzo = matriz[0][j];;
        
        for(int i = 1; i < matriz.size(); ++i){
            if(matriz[i][j] < minimoEsfuerzo){
                minimoEsfuerzo = matriz[i][j];
            }
        }
        vector_estimacionMinima[j] = minimoEsfuerzo;
    }
    
    
    for(int i = vector_estimacionMinima.size() - 2; i >= 0; --i){
        vector_estimacionMinima[i] +=  vector_estimacionMinima[i + 1];
        
    }
    
   resolver(matriz, vector_marcas_funcionariosOcupados, tiempoMinimo, indiceNumTrabajo, tiempoAcumulado, vector_estimacionMinima);
    
    
    // escribir sol
    std::cout << tiempoMinimo << std::endl;
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA EXAMEN/txt/eda27.txt");
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
