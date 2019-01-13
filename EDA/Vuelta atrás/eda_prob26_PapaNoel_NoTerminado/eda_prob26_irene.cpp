// Nombre del alumno: Irene Martin Berlanga
// Usuario del Juez: EDA35


#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <string>
bool esValida(std::vector<int>& vectorSolucion, std::vector<int>& unidadesJuguete,std::vector<std::string>const& tipoJuguete, int numJuguetesTotal, int k, int& contadorSatisfaccion, int minimoSatisfaccion, int i){

    
    if(k % 2 == 1){
        if(vectorSolucion[k] < vectorSolucion[k - 1]){
                return false;
        }
            if(tipoJuguete[vectorSolucion[k]] == tipoJuguete[vectorSolucion[k - 1]]){
                return false;
            }
    }
    
    if(k % 2 == 1){
        if(contadorSatisfaccion < minimoSatisfaccion)
            return false;
    }
    
    if(unidadesJuguete[i] < 0)
        return false;
    
    return true;
}


bool esSolucion(std::vector<int>& vectorSolucion , int k){
    if(k == vectorSolucion.size() - 1)
        return true;
    else
        return false;
}

// función que resuelve el problema
void resolver( std::vector<int>& vectorSolucion, std::vector<int>& unidadesJuguete,std::vector<std::string>const& tipoJuguete, std::vector<std::vector <int>>const& matrizSatisfaccionPorJuguete, int numJuguetesTotal, int k, int contadorSatisfaccion , int minimoSatisfaccion, bool& terminado){
    for(int i = 0; i < numJuguetesTotal; ++i){
        vectorSolucion[k] = i;
        unidadesJuguete[i]--;
       
        if(k == 0 || k ==  1){
            contadorSatisfaccion += matrizSatisfaccionPorJuguete[0][i];
        }
        else{
            if(k % 2 == 0)
                contadorSatisfaccion = 0;
            
            contadorSatisfaccion += matrizSatisfaccionPorJuguete[k/2][i];
        }
        
        if(esValida(vectorSolucion, unidadesJuguete, tipoJuguete, numJuguetesTotal, k, contadorSatisfaccion, minimoSatisfaccion, i)){
            
            if(esSolucion(vectorSolucion, k)){
                terminado = true;
                for(int i = 0; i < vectorSolucion.size(); ++i){
                    std::cout << vectorSolucion[i] << ' ';
                }
                std::cout << std::endl;
            }
            else{
                resolver(vectorSolucion, unidadesJuguete, tipoJuguete, matrizSatisfaccionPorJuguete, numJuguetesTotal, k + 1, contadorSatisfaccion, minimoSatisfaccion, terminado);
            }
        }
        
        unidadesJuguete[i]++;
        if(k == 0 || k ==  1){
            contadorSatisfaccion -= matrizSatisfaccionPorJuguete[0][i];
        }
        else{
            contadorSatisfaccion -= matrizSatisfaccionPorJuguete[k / 2][i];
        }
       
    }
}

// Resuelve un caso de prueba, leyendo de la entrada la
// configuración, y escribiendo la respuesta
bool resuelveCaso() {
    // leer los datos de la entrada
    int numJuguetesTotal, numNinios, minSatisfaccion;
    std::cin >> numJuguetesTotal >> numNinios >> minSatisfaccion;
    if (! std::cin)
        return false;
    
    std::vector<int> vectorSolucion(numNinios * 2);
    std::vector<int> unidadesJuguete(numJuguetesTotal);
    std::vector<std::string> tipoJuguete(numJuguetesTotal);
    //std::vector<int> contadorSatisfaccion(numNinios);
    std::string tipoDeJuguete;
    std::vector<std::vector <int>> matrizSatisfaccionPorJuguete (numNinios, std::vector<int>(numJuguetesTotal) );
    int contadorSatisfaccion = 0;
    bool terminado = false;
    for(int i = 0; i < numJuguetesTotal; ++i){
        std::cin >> unidadesJuguete[i];
    }
    
    for(int j = 0; j < numJuguetesTotal; ++j){
        std::cin >> tipoDeJuguete;
        tipoJuguete[j] = tipoDeJuguete;
    }
    for(int i = 0; i < numNinios; ++i){
        for(int j = 0; j < numJuguetesTotal; ++j){
            std::cin >> matrizSatisfaccionPorJuguete[i][j];
        }
    }
    

    resolver(vectorSolucion, unidadesJuguete, tipoJuguete, matrizSatisfaccionPorJuguete, numJuguetesTotal, contadorSatisfaccion, contadorSatisfaccion, minSatisfaccion, terminado);
    
    if(!terminado)
        std::cout << "SIN SOLUCION" << std::endl;
    
    
    std::cout << std::endl;
    // escribir sol
    
    
    return true;
    
}

int main() {
    // Para la entrada por fichero.
    // Comentar para acepta el reto
#ifndef DOMJUDGE
    std::ifstream in("/Users/IRENE/Desktop/EDA Y TAIS/txt/eda26.txt");
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
