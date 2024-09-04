//Gillbran Cadengo Rodriguez
//Sergio Gabriel Perez Moreno
//27/09/2022
//Programa para camino conexo de un grafo

//Programa para determinar los componentes conexos de un grafo, a partir de su matriz de adyacencia


//NOTA: NO FUNCIONA CON TODOS LOS GRAFOS, A MENOS QUE AL ESTAR ORDENADO LOS 1's QUE TIENEN HACIA ABAJO LOS TENGA TAMBIEN A LA DERECHA
//PARA QUE FORMEN SUS RESPECTIVOS CUADRADOS

#include <iostream>

using namespace std;

/*
0 0 0 1 1 0
0 0 0 0 0 0
0 0 0 0 0 1
1 1 1 0 0 0
0 1 1 0 0 1
0 0 0 0 1 0
*/


int main()
{
    int n; //Cantidad nodos
    cout<<"Ingresa cantidad de nodos: ";
    cin>>n;
    
    
    bool matriz_ad[n][n]={'\0'};
    bool matriz_ordenada_filas[n][n]={};
    bool matriz_ordenada_col[n][n]={};
    int posicion_original[n]={};
    int posicion_original_col[n]={};
    int cont_unos[n];
    int cont_unos_col[n];
    int cont_para_conexos[n];
    int aux=0;

    //Leer matriz de adyacencia
    cout<<"Ingresa matriz de adyacencia:"<<endl;
    for (int i=0; i<n; i++)
    {
        cont_unos[i]=0;
        cont_unos_col[i]=0;
        cont_para_conexos[i]=0;
        posicion_original[i]=i;
        posicion_original_col[i]=i;
        
        for(int j=0; j<n; j++)
        {
            cin>>matriz_ad[i][j];
            matriz_ordenada_filas[i][j]=0;
            matriz_ordenada_col[i][j]=0;
            if(i==j)
            {
                matriz_ad[i][j]=1;
            }
        }
        cout<<endl;
    }
    

    //Camino de componentes conexos
    for (int r=0; r<2; r++) //Hacer procesos 2 veces
    {
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i!=j && matriz_ad[i][j]==1) //Evaluar que no sea la diagonal y posicion sea 1
                {
                    for(int k=0; k<n; k++) //Ayuda a iterar las columnas
                    {
                        if(matriz_ad[j][k]==1) //Verificar que sea 1, cambiando a j como renglon y k como columna
                        {
                            matriz_ad[i][k]=1; //Activar con 1
                        }
                    }
                }
            }
        }
    }
    
    //Mostrar paso 2
    for (int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout<<matriz_ad[i][j];
            if(matriz_ad[i][j]==1) //Hacer conteos de 1's
            {
                cont_unos[i]=cont_unos[i]+1;
            }
        }
        cout<<endl;
    }

    //Ordenar de mayor a menos numero de 1's con su respectiva posicion
    for(int i=n-1; i>=0; i--)
    {
        for(int j=i-1; j>=0; j--)
        {
            if(cont_unos[i]>cont_unos[j])
            {
                //Ordenar por 1's
                aux=cont_unos[i];
                cont_unos[i]=cont_unos[j];
                cont_unos[j]=aux;

                //Ordenar por posicion
                aux=posicion_original[i];
                posicion_original[i]=posicion_original[j];
                posicion_original[j]=aux;
            }
        }
        
    }

    for(int i=0; i<n; i++)
    {
        cout<<cont_unos[i]<<"   "<<posicion_original[i]<<endl;
        
    }
    
    //Ordenar filas matriz adyacencia mayor a menor
   for(int i=0; i<n; i++)
   {
        for(int j=0; j<n; j++)
        {
            matriz_ordenada_filas[i][j]= matriz_ad[posicion_original[i]][j];
        }
   }


   //Mostrar matriz ordenada por filas
   cout<<"Matriz ordenada por filas"<<endl;
   for(int i=0; i<n; i++)
   {
        for(int j=0; j<n; j++)
        {
            cout<<matriz_ordenada_filas[i][j];
        }
        cout<<endl;
   }

    
    //ORDENAR COLUMNAS
   for(int i=0; i<n; i++)
   {
        for(int j=0; j<n; j++)
        {
            if(matriz_ordenada_filas[j][i]==1)
            {
                cont_unos_col[i]=cont_unos_col[i]+1;
            }
        }
   }

   //Ordenar de mayor a menos numero de 1's con su respectiva posicion
    for(int i=n-1; i>=0; i--)
    {
        for(int j=n-1; j>=0; j--)
        {
            if(cont_unos_col[i]>cont_unos_col[j])
            {
                //Ordenar por 1's
                aux=cont_unos_col[i];
                cont_unos_col[i]=cont_unos_col[j];
                cont_unos_col[j]=aux;

                //Ordenar por posicion
                aux=posicion_original_col[i];
                posicion_original_col[i]=posicion_original_col[j];
                posicion_original_col[j]=aux;
            }
        }
        
    }

    for(int i=0; i<n; i++)
    {
        cout<<cont_unos_col[i]<<"   "<<posicion_original_col[i]<<endl;
    }

     //Ordenar columnas matriz adyacencia mayor a menor
   for(int i=0; i<n; i++)
   {
        for(int j=0; j<n; j++)
        {
            matriz_ordenada_col[i][j]= matriz_ordenada_filas[i][posicion_original_col[j]];
        }
   }
    cout<<"Matriz ordenada por columnas"<<endl;
   for(int i=0; i<n; i++)
   {
        for(int j=0; j<n; j++)
        {
            cout<<matriz_ordenada_col[i][j];
        }
        cout<<endl;
   }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(matriz_ordenada_col[j][i]==1)
            {
                cont_para_conexos[i]=cont_para_conexos[i]+1;
            }
        }
    }

    //Sacar componentes conexos
    int cont=0, contV=0;
    int tope=0;
    int inicia=0;
    int x=0, y=0;
    
    for(int i=inicia; i<n; i++)
    {
        
        tope=cont_para_conexos[inicia]-inicia;
        
        //Contar unos para determinar cuadros
        for(x=inicia; x<inicia+tope; x++)
        {
            for(y=inicia; y<inicia+tope; y++)
            {
                if(matriz_ordenada_col[x][y]==1)
                {
                    cont++;
                    
                }
            }
        }
        //Saber si forman cuadros
        if(cont==tope*tope)
        {
            
            contV++;
            cout<<"V"<<contV<<": {";
            //Mostrar componentes conexos
            for(int z=inicia; z<inicia+tope; z++)
            {
                cout<<posicion_original_col[z]<<" , ";
            }
            
            if(tope<n)
            {
                
                inicia=tope+inicia;
                
                
            }
            cout<<"}"<<endl;
        }
        cont=0;
    }
    cout<<endl<<endl;
    return 0;
}