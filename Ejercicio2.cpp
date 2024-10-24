#include <iostream>

using namespace std;

//Llenar y mostrar arreglo memoria estatica

int main()
{
    int arr[10];

    //LLenar arreglo
    cout << "Ingrese 10 numeros" << endl;
    for(int i=0;i<10;i++)
    {
        cout << "Ingrese el elemento " << i+1 << " : ";
        cin >> arr[i];
    }

    //Mostrar arreglo
    for(int i=0;i<10;i++)
    {
        cout << "ELemnto [" << i << "]: " << arr[i] << "  ";
    }
    cout << endl;
 
}
    