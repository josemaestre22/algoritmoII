//Llenar y mostrar elementos de un arreglo con memoria dinamica
#include <iostream>

using namespace std;

int main()
{
    int n;
    cout << "Ingrese la cantidad de elementos del arreglo: ";
    cin >> n;

    int* arr = (int*) malloc(sizeof(int) * n);
    
    //Llenar arreglo
    for(int i=0;i<n;i++)
    {
        cout << "Ingrese el elemento [" << i << "] : ";
        cin >> arr[i];
    }

    //Imprimir elementos del arreglo
    for(int i=0;i<n;i++)
    {
        cout << "Elemento [" << i << "]: " << arr[i] << endl;
    }

}