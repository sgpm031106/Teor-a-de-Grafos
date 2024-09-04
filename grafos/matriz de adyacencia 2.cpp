/*
Pérez Moreno Sergio Gabriel
Estructuras Computacionales Avanzadas
Septiembre del 2022
*/
#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	//Variables
	unsigned int n, nodo1, nodo2;
	unsigned short int op = 1;
	
	//Capturar los nodos
	cout<<"Ingrese la cantidad de nodos: ";
	cin>>n;
	
	//Arreglos co tamaño dado por el usuario
	unsigned short int matriz[n][n];
	
	//Asignar ceros a la matriz de adyacencia
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			matriz[i][j] = 0;
		}
	}
	
	//Capturar el grafo
	while(op == 1)
	{
		cout<<"\n";
		cout<<"Arista\n";
		cout<<"Dame un nodo: ";
		cin>>nodo1; //Primer nodo del grafo
		cout<<"\n";
		cout<<"Dame el segundo nodo: "; //Nodo al que se conecta el primer nodo
		cin>>nodo2;
		
		matriz[nodo1-1][nodo2-1] = 1;
		matriz[nodo2-1][nodo1-1] = 1;
		
		cout<<"Desea continuar 1. Si  2. NO: ";
		cin>>op;
	}
	cout<<"\n\n";
	
	//Imprimir la matriz de adyacencia
	cout<<"Matriz de adyacencia dada por el usuario.\n\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<matriz[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	//Imprimir matriz de adyacencia por aristas
	cout<<"El grafo (aristas) esta conectado con: \n\n";
	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			if(matriz[i][j] == 1)
			{
				cout<<"Nodo "<<i+1<<" con nodo "<<j+1<<endl;
			}
		}
	}
}
