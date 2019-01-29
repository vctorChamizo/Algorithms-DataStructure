#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <algorithm>

/*
	ESPECIFICACIÓN: 

		predicate consecutivos (s : seq<int>, ini : int, fin : int)
			requires |s| != []
			requires 0 <= ini < |s|
			requires 0 <= fin < |s|
			{
				forall k :: ini <= k < fin ==> s[k] + 1 == s[..][k + 1]
			}

		predicate secuenciaMax (s : seq<int>, l : int)
			requires |s| != []
			requires 1 <= l <= |s|
			{
				forall k, w :: 0 <= k < w < |s| && consecutivos(s, k, w) ==> k - (w + 1) <= l
				exists k, w :: 0 <= k < w < |s| && consecutivos(s, k, w) && k - (w + 1) == l
			}
			
		method secuenciaCrecienteMax(v : array<int>) return (ini : int, size : int)
			requires v != null && v.Length > 0
			ensures 0 <= ini < v.Length
			ensures 1 <= size < v.Length
			ensures ini + size < v.Length
			ensures consecutivos(v[..], ini, ini + (fin - 1)
			ensures secuenciaMax(v[..], size)
			{
				var max := 1;
				var anterior := v[0];
				var i := 1;
				
				ini := 0;
				size := 0;
				
				while (i < v.Length)
					invariant 1 <= i < v.Length
					invariant 1 <= size <= i
					invariant 1 <= max < size
					invariant consecutivos(v[..], ini, ini + (fin - 1)
					invariant secuenciaMax(v[..], size)
					decreases (v.Length - i)
					{
						if (anterior + 1 == v[i]) {
							
							max := max + 1;
							anterior := v[i];
			
							if (max > size) {

								ini := i - max + 1;
								size := max;
							}
						}
						
						i := i + 1;
					}
			}

			
	COSTE:

		O(n) --> siendo n el numero de elemetnos del vector.
		
		Este orden de complejidad se da ya que recorremos el vector una sola vez independientemente del tamaño
		de los datos de entrada.
*/

void secuenciaCrecienteMax(std::vector<int> const & v, int & ini, int & size) {

	int max = 1;
	int anterior = v[0];

	for (int i = 1; i < v.size(); ++i) {

		if (anterior + 1 == v[i]) {

			max++;
			anterior = v[i];
			
			if (max > size) {

				ini = i - max + 1;
				size = max;
			}
		}
		else max = 1;
	}
}


bool resuelveCaso() {

	int n;
	std::cin >> n;

	if (n == 0) return false;

	std::vector<int> v(n);
	int inicio = 0, size = 0;

	for (int & k : v) std::cin >> k;

	secuenciaCrecienteMax(v, inicio, size);

	std::cout << inicio << " " << size << std::endl;

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