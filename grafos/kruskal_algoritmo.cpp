#include <bits/stdc++.h>

using namespace std;

/*
Lista de Adyacencia del grafo de las ofertas
9 vertices y 9 aristas
Noche de inicio - Noche final - Costo de la estancia
    0                   1               0
    0                   2               0 
    1                   2               0
    0                   3               10
    3                   4               15
    1                   5               12
    5                   6               20
    2                   7               5
    7                   8               10

*/
/*
La anterior lista de adyacencia está hecha con el modelo de que solo se propongan 3 ofertas 


En este algoritmo de Kruskal, el usuario no modifica los pesos de las aristas.
Estos ya tienen que estar definidos en la lista de adyacencia que se ingresara el ejecutarse el codigo
*/

vector<int> link;

//Inicializar la estructura de datos
void iniciar(int n)
{
    link.resize(n);
    for(int i=0; i<n; i++)
    {
        link[i]= i;
    }
}

//Identificar el padre de un respectivo nodo
int encontrar_padre(int v)
{
    if(v == link[v])
    {
        return v;
    }
    return link[v] = encontrar_padre(link[v]);
}

//Unir componentes
void union_sets(int a, int b)
{
    a = encontrar_padre(a);
    b = encontrar_padre(b);
    link[b] = a;
}
//Lista de aristas
vector<pair<int, pair<int, int>>> lista_aristas;

int kruskal(int n, int aristas)
{
    sort(lista_aristas.begin(), lista_aristas.end()); //Ordenar de menor a mayor el peso de las aristas
    iniciar(n);
    int cm = n; //Cantidad de componentes
    int pos = 0; //Posicion para iterar cada arista
    int minimo = 0; // sumar la expansion minima

    while(cm != 1 && pos < aristas) //Mientras la cantidad de componentes no sea 1 y aun no consultemos todas las aristas
    {
        pair<int, pair<int, int>> actual = lista_aristas[pos];
        if(encontrar_padre(actual.second.first) != encontrar_padre(actual.second.second))
        {

            /*
            cout<<actual.second.first<< " --- "<<actual.second.second<<endl;
            */
            union_sets(actual.second.first, actual.second.second);
            minimo = minimo + actual.first;
            cm--;
        }
        pos++;
    }
    cout<<endl<<"El coste total de las 3 ofertas es de: $";
    minimo = minimo  * 1000;
    return minimo;
}



int main()
{
    cout<<"Perez Moreno Sergio Gabriel   Estructuras Computacionales Avanzadas   2do Parcial. "<<endl;
    cout<<"Implementacion con algoritmo de Kruskal. "<<endl<<endl;
    cout<<"3 ofertas y 3 noches. "<<endl;

    int ofertas, noches,  n, aristas; // n = cantidad de nodos, aristas = cantidad de aristas
    cout<<"Ingresa cantidad de ofertas: ";
    cin>> ofertas;
    cout<<"Ingresa la cantidad de noches de estancia: ";
    cin>> noches;

    n = ofertas * 3;
    aristas = noches  *3;


    lista_aristas.resize(aristas);

    cout<<"Ingresa la lista de adyacencia de tu grafo:"<<endl;
    cout<<"(Lista de adyacencia ya creada a partir del grafo de las ofertas dado en la hoja de libreta). "<<endl;
    for(int i = 0; i < aristas; i++)
    {
        int origen, destino, peso;
        cin>> origen >> destino >> peso;
        lista_aristas[i] = {peso,{origen, destino}};
    }

    cout<<endl<<kruskal(n, aristas)<<endl;
    cout<<"Precio en miles refiriendose al precio realista. "<<endl;
    return 0;
}

