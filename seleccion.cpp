//Implementacion de algoritmo de ordenamiento  por  el metodo de seleccion
#include<iostream>

using namespace std;

#define ARR_SIZE 5

int main (void)
{
    int arr[ARR_SIZE];
    
    //Llenar Arreglo con valores dados por el usuario
    for(int i=0; i < ARR_SIZE; i++)
    {
        cout << "Ingrese un numero"  << endl;
        cin >>  arr[i];
    }

    //Por cada elemento del  arreglo
    int pos_menor;

    for(int i=0; i < ARR_SIZE; i++)
    {
        pos_menor=i;
        for(int j=i; j < ARR_SIZE; j++)
        {
            if(arr[j] < arr[pos_menor])
            {
                pos_menor = j;
            }
        }

        if(i!=pos_menor)
        {
            swap(arr[i], arr[pos_menor]);
        }
    }

    for(int i=0; i < ARR_SIZE; i++)
    {
        cout << endl << arr[i] << endl;
    }
}