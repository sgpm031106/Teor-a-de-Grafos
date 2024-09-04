/*
P�rez Moreno Sergio Gabriel
Estructuras Computacionales Avanzadas
Recorridos en altura y anchira de un grafo
Septiembre del 2022
*/
#include <bits/stdc++.h>

/*
0 1 1 0 0 0 0
0 0 0 1 0 0 0
0 0 0 0 1 0 0
1 0 0 0 0 1 1
0 0 0 1 0 0 0
0 0 0 0 0 0 0
0 0 0 0 0 0 0 
*/

using namespace std;

bool todosVisitados(bool v[], int n){
	for (int x = 0; x < n; x++){
		if (v[x] == false){
			return false;
		}
	}
	return true;
}

void anchura();
void altura();

int main()
{
	int op;
	do
	{
		cout<<"---MENU---"<<endl;
		cout<<"1. Recorrido en altura. "<<endl;
		cout<<"2. Recorrido en anchura. "<<endl;
		cout<<"3. Salir del programa. "<<endl;
		cout<<"Que desea realizar? ";
		cin>>op;
		switch(op)
		{
			case 1:
				altura();
				cout<<"\n";
				break;
			
			case 2:
				anchura();
				cout<<"\n";
				break;
			
			case 3:
				cout<<"Saliendo del programa. "<<endl;
				break;
		
			default:
				cout<<"Opcion invalida ingrese otra opcion. "<<endl;
				break; 	
		}
		system("pause");
		system("cls");
	}while(op != 3);
}

void altura()
{
	srand(time(NULL));

	cout << "Introduce la cantidad de nodos: ";
	int n; cin >> n;

	bool ady[n][n] = {};
	bool visitado[n] = {};
	stack<int> pila;

	cout << "Introduce su matriz de adyacencia: " << endl;

	// Llenamos la matriz de adyacencia
	for (int x = 0; x < n; x++){
		for (int y = 0; y < n; y++){
			cin >> ady[x][y];
		}
		cout << endl;
	}

	int inicio = 0;
	cout << "Inicio: " << inicio;
	visitado[inicio] = true;

	do{
		for (int x = 0; x < n; x++){
			if ((ady[inicio][x] == 1) && (visitado[x] == false)){
				visitado[x] = true;
				pila.push(x);
			}
		}

		inicio = pila.top();
		cout << " -> " << pila.top();
		pila.pop();

	} while(!todosVisitados(visitado, n) || !pila.empty());

	cout << "\n";
	// Mostramos la matriz de adyacencia.
	for (int x = 0; x < n; x++){
		for (int y = 0; y < n; y++){
			cout << ady[x][y]<<"  ";
		}
		cout << endl;
	}
}
void anchura()
{
	srand(time(NULL));

	cout << "Introduce la cantidad de nodos: ";
	int n; cin >> n;

	bool ady[n][n] = {};
	bool visitado[n] = {};
	queue<int> cola;

	cout << "Introduce su matriz de adyacencia: " << endl;

	// Llenamos la matriz de adyacencia
	for (int x = 0; x < n; x++){
		for (int y = 0; y < n; y++){
			cin >> ady[x][y];
		}
		cout << endl;
	}

	int inicio = 0;
	cout << "Inicio: " << inicio;
	visitado[inicio] = true;

	do{
		for (int x = 0; x < n; x++){
			if ((ady[inicio][x] == 1) && (visitado[x] == false)){
				visitado[x] = true;
				cola.push(x);
			}
		}

		inicio = cola.front();
		cout << " -> " << cola.front();
		cola.pop();

	} while(!todosVisitados(visitado, n) || !cola.empty());

	cout << "\n";
	// Mostramos la matriz de adyacencia.
	for (int x = 0; x < n; x++){
		for (int y = 0; y < n; y++){
			cout << ady[x][y]<<"  ";
		}
		cout << endl;
	}
}
