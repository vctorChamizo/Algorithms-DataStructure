/*
	Practica 4 - Dafny
	Autores:
		- Irene Martín Berlanga (E35)
		- Víctor Chamizo Rodríguez (E12)
 */

// Implementar un metodo que resuelva el problema 37 del juez.
// Probar que es correcto respecto a la especificacion
method problema3 (a : array<int>, p : int) returns (b : bool)
	requires a != null && a.Length > 0
	requires 0 <= p < a.Length
	ensures b == forall u, w :: 0 <= u <= p < w < a.Length ==> a[u] < a[w]
	
	{
		// Calculo del maximo de la parte izquierda
		var max := a[0];
		var i := 1;

		while (i <= p) 
			invariant 0 <= i <= p + 1
			invariant forall k :: 0 <= k < i ==> max >= a[k]
			invariant max in a[..]
			decreases (p - i)
			{
				if (a[i] > max) { max := a[i]; }  
				i := i + 1;
			}
 
		// probar que la variable max tiene el maximo de la parte izquierda
		assert forall k :: 0 <= k <= p ==> max >= a[k];
		assert max in a[..p+1];

		// Bucle para comprobar que el maximo de la parte izquierda es menor que 
		// todos los valores de la derecha
	

		while (i < a.Length && max < a[i]) 
			invariant p < i <= a.Length
			invariant forall w :: p < w < i ==> max < a[w]
			decreases (a.Length - i)
			{
				i := i + 1;
			}
		b := i == a.Length;
		// Posibles instrucciones de finalizacion
	}

/*******************************************************************************************************/

// Implementar un metodo que cuente el numero de valores de un vector que son mayores 
// que todos los valores a su derecha

// Definir un predicado que sea cierto todos los valores a la derecha de la posicion i
// son menores que el valor de la posicion i
predicate esMirador(s : seq<int>, i : int)
	requires 0 <= i < |s|
	
	{ forall k :: i < k < |s| ==> s[i] >= s[k] } 

// Definir una funcion que cuente el numero de miradores de una secuencia
function CountMiradores(s : seq<int>, i : int):nat
	requires 0 <= i < |s| && |s| > 0
	decreases |s| - i
	
	{
		if (i == |s| - 1) then 1
		else if (i < |s| - 1 && esMirador(s, i)) then 1 + CountMiradores(s, i + 1)
		else CountMiradores(s, i + 1)
	}

// Implementar un metodo que cuente el numero de miradores de un vector
method numMiradores(v : array<int>) returns (n : int)
	requires v != null && v.Length > 0
	ensures n == CountMiradores(v[..], 0)
	
	{
		// Inicializar variables
		var i := v.Length-1; 
		var i_max := v.Length - 1;
		n := 1;
		
		while (i > 0)
			invariant 0 <= i <= v.Length && i <= i_max < v.Length
			invariant forall k:: i <= k < v.Length ==> v[i_max] >= v[k]
			invariant n == CountMiradores(v[..], i)
			{
				if (v[i-1] >= v[i_max])
				{ 
					i_max := i -1;
					n := n + 1;
				}
				i := i - 1;
      }
	}

/*******************************************************************************************************/

// Implementar un metodo que elimine los valores iguales a x de un vector v
// Debe resolverse con complejidad lineal
// tam :  numero de elemento diferentes de x en el vector v de entrada. 
// El vector modificado debe tener estos elementos en las tam primeras posiciones
// Se probará primero que el valor x no aparece en las tam primeras posiciones
// Despues escribir otra postcondicion que indique que los tam primeros valores del 
// vector modificado estan en el vector original
method eliminar (v : array<int>, x : int) returns (tam : int)
	requires v != null && v.Length > 0
	ensures 0 <= tam <= v.Length 
	ensures forall k :: 0 <= k < tam ==> v[k] in old(v[..])
	ensures !(x in v[..tam])
	modifies v

	{
		var i := 0;
		tam := 0;

		while (i < v.Length) 
			invariant 0 <= i <= v.Length
			invariant 0 <= tam <= i
			invariant !(x in v[..tam])
      		invariant forall k :: 0 <= k < tam ==> v[k] in old(v[..])
			
			{
				if (v[i] != x) 
				{ 
					v[tam] := v[i];
					tam := tam + 1;
				}
				i := i + 1;
			}
	}

/*******************************************************************************************************/

// Implementar un metodo que calcule el n-esimo numero de Jacobsthal

// Funcion que define los numeros de Jacobsthal
function Jacob (n : int) : int
	requires n >= 0
	ensures n < 2 ==> Jacob(n) == n
	ensures n >= 2 ==> Jacob(n) == Jacob(n-1) + 2 * Jacob(n-2)
	
	{
		if (n < 2) then n
		else Jacob(n-1) + 2 * Jacob(n-2)
	}

// Implementar el metodo
method Jacobsthal (n : int) returns (j : int)
	requires n >= 0
	ensures j == Jacob(n)
	
	{
		// Resolver los casos n == 0 y n == 1

		if(n == 0){
			j := 0;
			return;
		}
		else if(n == 1){
			j := 1;
			return;
		}

		var num1 := 1;
		var num2 := 0;
		j := 1;
		var i := 2;

		while(i < n)
			invariant 0 <= i <= n
			invariant j == Jacob(i)
			invariant num1 == Jacob(i - 1)
			invariant num2 == Jacob(i - 2)
			{
				num2 := num1;
				num1 := j;
				j:= num1 + 2*num2;
				i := i + 1;
			}
	}
		