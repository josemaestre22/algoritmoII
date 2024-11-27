#include<iostream>

using namespace std;
//Crear al estructura de nodo (tipo de dato complejo)
struct nodo{
    int valor;
    nodo* siguiente;
};

nodo* tope = nullptr;

//Funcion que inserta un nuevo nodo a la pila
void push(int valor)
{
    nodo* nodoNuevo = new nodo; // funcion parecida a malloc
    nodoNuevo->valor = valor;
    nodoNuevo->siguiente = tope;
    tope = nodoNuevo;
}

bool pilaVacia()
{
    return tope==NULL;
}
 
 //Retira un nodo de la pila
nodo* pop()
{ 
    nodo* nodoExtraido = tope;

    if(!pilaVacia())
    {
        tope = tope->siguiente;
        nodoExtraido->siguiente = nullptr;
    }
    
    return nodoExtraido;
}

int main()
{
    int n;
    cout <<  "Ingrese la cantidad de nodos: ";
    cin >> n;
    int x;

    for(int i=0;i<n;i++)
    {

        cout << "Ingrese un valor para el nodo " << i << ": ";
        cin >> x;
        push(x);
    }

    nodo* nodoExt;
    for(int i=0;i<n;i++){
       nodoExt = pop();
       cout << nodoExt->valor << endl;
    }
}