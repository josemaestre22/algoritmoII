#include <iostream>

using namespace std;

struct Data
{
    int cedula;
    string nombre;
};

struct Nodo
{
    Data data;
    Nodo* sig;
};

struct Lista
{
    Nodo* primero;
};

Lista* crearLista()
{
    Lista* lista = new Lista;
    lista->primero=  nullptr;
    return lista;
}

bool isEmpty(Lista* lista)
{
    return (lista->primero == nullptr);
}

//AGREGAR ORDENADAMENTE
void agregarOrdenado(Lista* lista, int cedula, string nombre)
{
    struct Nodo *nuevo;
    struct Nodo *aux=lista->primero;

    nuevo = new Nodo;
    nuevo->data.cedula = cedula;
    nuevo->data.nombre = nombre;
    nuevo->sig = nullptr;

    if(isEmpty(lista))
    {
        lista->primero = nuevo;
    }
    else if(nuevo->data.cedula < lista->primero->data.cedula)
    {
        nuevo->sig = lista->primero;
        lista->primero = nuevo;
    }
    else
    {
        while((aux->sig!=nullptr)&&(aux->sig->data.cedula <= nuevo->data.cedula))
        {
            aux = aux->sig;
        }
        nuevo->sig = aux->sig;
        aux->sig = nuevo;
    }
}


void mostrarLista(Lista* lista)
{
    struct Nodo *aux = lista->primero;

    while(aux!=nullptr)
    {
        cout << aux->data.nombre<< endl;
        cout << aux->data.cedula<< endl;
        aux = aux->sig;
    }
}


int main()
{
    int opcion;
    
    do
    {
        opcion 
    }
}