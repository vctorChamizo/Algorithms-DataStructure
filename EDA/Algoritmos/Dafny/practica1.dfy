/*
	Practica 1 - Dafny
	Autores:
		- Guillermo Cortina Fernández.
		- Irene Martín Berlanga.
		- Víctor Chamizo Rodríguez
 */


// Intercambio del valor de dos posiciones de un vector
method swap (v : array<int>, i : int, j : int) 
	requires v != null
	requires 0 <= i < v.Length
	requires 0 <= j < v.Length
	requires  i != j
	ensures v[i] = old(v[j])
	ensures v[j] = old(v[i])
	modifies v 
	
	{
		var aux := v[i];
		v[i] := v[j];
		v[j] := aux;
	}

/*******************************************************************************************************/

// Funcion que comprueba que todos los elementos de un vector son pares
predicate par (n : int)
	requires n > 0
	ensures par(n) == (n % 2 == 0)

	{ 
		n % 2 == 0 
	}

method verificaPar (v : array<int>) returns (b : bool) 
	requires v != null
	ensures b == (forall w :: 0 <= w < v.Length ==> par(v[w])) 
	
	{
		var i := 0;

		while (i < v.Length && v[i] % 2 == 0) 
			invariant 0 <= i <= v.Length
			invariant forall w :: 0 <= w < i ==> par(v[w]) 
			{ i := i + 1; }

		b := i == v.Length;
	}

/*******************************************************************************************************/

// Funcion que calcula el valor maximo de un vector
method maximo (v : array<int>) returns (m : int)
	requires v != null
	ensures m in v[..]
	ensures forall w :: 0 <= w < v.Length ==> m >= v[w]

	{
		var i := 1;
		m := v[0];

		wile (i < v.Length) 
			invariant 0 <= i <= v.Length
			invariant forall k :: 0 <= k < i ==> m >= v[k]
			invariant m in v[..i]
			decreases v.Length - i
			{
				if (m < v[i]) { m := v[i]; }
				i := i+1;
			}
	}

/*
// Funcion que calcula el valor maximo de una secuencia
method maximo (v : seq<int>) returns (m : int)
requires v != []
ensures m in v
ensures forall i:: 0 <= i < |v| ==> v[i] <= m
{
	var i := 1;
	m := v[0];
	while (i < |v|) 
	invariant 0 < i <= |v|
	invariant forall k :: 0 <= k < i ==> m >= v[k]
	invariant m in v[..i]
	decreases |v| - i
	{
		if (m < v[i]) {m := v[i];}
		i := i+1;
	}
}
*/
