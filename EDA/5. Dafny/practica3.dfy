/*
	Practica 3 - Dafny
	Autores:
		- Guillermo Cortina Fernández (E15)
		- Irene Martín Berlanga (E35)
		- Víctor Chamizo Rodríguez (E12)
 */


// Intercambiar el valor de dos posiciones de un vector.
// Escribe las precondiciones mas debiles de cada una de las instrucciones del codigo
method swap (v : array<int>, i : int, j : int)
	requires v != null
	requires 0 <= i < v.Length
	requires 0 <= j < v.Length
	requires  i != j
	ensures v[i] == old(v[j]) && v[j] == old(v[i])
	modifies v
	
	{
		
		assert v[j] == old(v[j]) && v[i] == old(v[i]);
		
		v[i]:= v[i] - v[j];

		assert v[j] == old(v[j]) && v[i] + v[j] == old(v[i]);
		
		v[j]:= v[i] + v[j];

		assert v[j] - v[i] == old(v[j]) && v[j] == old(v[i]);
		
		v[i]:= v[j] - v[i];

		assert v[i] == old(v[j]) && v[j] == old(v[i]);
	}

/*******************************************************************************************************/

// Implementar un metodo que calcule el n-esimo numero de la sucesion de fibonacci
// Definicion de la funcion de Fibonacci para usarla en la especificacion
function Fib (n : int) : int
	requires n >= 0

	{ 
		if (n < 2) then n else Fib(n - 2) + Fib(n - 1) 
	}

// Metodo que calcula el n-esimo termino de la sucesion
method Fibonacci (n : int) returns (f : int)
	requires n >= 0
	ensures f == Fib(n)

	{
		// Resolver el problema para los casos n == 0 y n == 1 antes de entrar en el bucle
		if (n == 0) { f := 0; }
		else if (n == 1) {f := 1;}
		else {
		
			var i := 1
			f := 0
			var y := 1
			
			while (i < n) 
				invariant 0 <= i <= n
				invariant f == Fib(i)
				invariant y == Fib(i + 1)
				decreases n - i
				{
					f := y
					y := f + y
					i := i + 1
				}
		}
	}

/*******************************************************************************************************/

// Implementar un metodo que dado un vector devuelva en otro vector los valores acumulados
// Se acumulan los valores de derecha a izquierda. El elemento de la posicion cero del 
// nuevo vector es la suma del vector original completo y el ultimo elemento del nuevo vector
// coincide con el valor del ultimo elemento del vector original
// Escribir el invariante para probar la correccion del bucle (invariant)
// Dar una funcion cota del bucle (decreases) y comprobar que Dafny realiza la prueba con ella.
function suma (s : seq<int>) : int
	ensures s == [] ==> suma(s) == 0;
	ensures s != [] ==> suma(s) == s[0] + suma(s[1..])

	{
		if s == [] then 0 else s[0] + suma(s[1..])
	}

// Realizar un bucle que recorre el vector de derecha a izquierda
// Comenzar con el calculo de w[v.Length-1]
method acumulado (v : array<int>) returns (w : array<int>)
	requires v != null && v.Length > 0
	ensures w != null && w.Length == v.Length
	ensures forall k :: 0 <= k < v.Length ==> w[k] == suma(v[k..])
	
	{
		w := new int[v.Length];
		var suma := 0;
		var i := v.Length - 1;

		while (i >= 0 )
			invariant 0 <= i <= v.Length
			invariant forall x :: 0 <= x < v.Length ==> w[x] == suma(v[x..])
			decreases i
			{
				suma := suma + v[i]
				w[i] := suma
				i := i - 1
			}
	}

/*******************************************************************************************************/

// Implementar un metodo que cuente el numero de posiciones de un vector que son
// mayores que todas las posiciones que tienen a su izquierda. 
// Por ejemplo, el vector: 8 5 6 10 12 4 7 5 14 7, tiene como picos el 8, 10, 12, 14

// Definir un predicado que sea cierto si la posicion i del vector tiene un pico
predicate espico(s:seq<int>,i:int)
	requires s != []
	requires 0 <= i <|s|
	ensures espico(s,i) == forall x:: 0 <= x < i ==> s[x] < s[i]
	
	{
  		forall x:: 0 <= x < i ==> s[x] < s[i]
	}

// funcion que cuenta el numero de picos de una secuencia
function CountPicos(s:seq<int>,i:int):nat 
	requires 0<=i<|s| && |s| > 0
	ensures i == 0 ==> CountPicos(s,i) == 1
	ensures i > 0 && espico(s,i) ==> CountPicos(s,i) == 1 + CountPicos(s,i - 1)
	ensures i > 1 && !espico(s,i) ==> CountPicos(s,i) == CountPicos(s,i - 1)
	
	{
  		if |s| == 1 then 1
  		else if |s| > 1 && espico(s,i) then 1 + CountPicos(s,i - 1)
        else CountPicos(s,i - 1)
	}

// metodo que cuenta el numero de picos de un vector
method numPicos(v:array<int>) returns (n:int) 
	requires v != null && v.Length > 0
	ensures n == CountPicos(v[..], v.Length - 1)
	
	{
		var cont := 1
		var i := 1
		var max := v[0]

		while (i < v.Length)
			invariant 1 <= i < v.Length
			invariant 1 <= cont <= v.Length
			invariant max in v[..]
			decreases v.Length - i
			{
				if (v[i] > max){
					max := v[i]
					cont := cont + 1
				}  
				i := i + 1
			}
	}
