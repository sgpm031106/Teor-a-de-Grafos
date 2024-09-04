#include <bits/stdc++.h>
using namespace std;

/*
Bipartito:
0 0 1 1 0 1
0 0 0 0 1 1
1 0 0 0 0 0
1 0 0 0 0 0
0 1 0 0 0 0
1 1 0 0 0 0

No bipartito:
0 0 1 1 0 1
0 0 0 0 1 1
1 0 0 0 0 0
1 0 0 0 0 0
0 1 0 0 0 1
1 1 0 0 1 0
*/

int main()
{
	cout << "Nodos: " << endl;
	int n;
	cin >> n;

	cout << "Matriz de Adyacencia: " << endl;
	bool ady[n][n];
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			cin >> ady[x][y];
		}
	}
	// Colores tambien se utilizará como un array de visitados.
	// 0 = No visitado
	// 1 = Rojo
	// -1 = Azul
	int colores[n] = {};

	// Se declara el origen (puede ser cualquiera dentro del rango de n)
	int origen = 0;

	// Coloreamos el origen como rojo (da igual, puede ser azul, pero ya está visitado)
	colores[origen] = 1;

	// Creamos una cola para introducir los valores.
	queue<int> BFS;
	// Empujamos el origen.
	BFS.push(origen);

	// Mientras la cola no esté vacia:
	while (!BFS.empty()){
		// El origen será el frente de la cola.
		origen = BFS.front();
		// Quitamos el valor frontal.
		BFS.pop();

		// Por cada nodo adyacente al origen:
		for (int x = 0; x < n; x++)
		{
			// Si:
			// El nodo adyacente no sea 0 (ady[origen][x])
			// El color del nodo adyacente este sin visitar (colores[x] == 0)
			if (ady[origen][x] && (colores[x] == 0))
			{
				colores[x] = colores[origen] * -1; // El color del nodo adyacente será el inverso del color del nodo origen.
				BFS.push(x); // Empuajamos el nodo a la cola que acabamos de colorear.

			// Si no, entonces:
			// El nodo adyacente no sea 0 (ady[origen][x])
			// El color del nodo adyacente sea el mismo color que su nodo origen
			} else if (ady[origen][x] && (colores[origen] == colores[x])){
				cout << "El grafo no es bipartito";
				return 0;
			}
		}
	}
	
	// Si pasa por toda la ejecución sin parar, entonces: 
	cout << "El grafo si es bipartito.";
	return 0;
}