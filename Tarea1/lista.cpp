#include <iostream>
#include <cstdlib>

using namespace std;

void clear_screen()
{
#ifdef WINDOWS
  std::system ( "CLS" );
#else
  std::system ( "clear" );
#endif
}

struct Data
{
    string nombre;
    int cedula;
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
    lista->primero = nullptr;
    return lista;
}

bool isEmpty(Lista* lista)
{
    return (lista->primero == nullptr);
}

Nodo* buscarPersona(Lista* lista, int cedula)
{
    Nodo* aux = lista->primero;

    while(aux!=nullptr)
    {
        if(aux->data.cedula == cedula)
        {
            return aux;
        }
        else
        {
            aux = aux->sig;
        }
    }
    return nullptr;
}

void agregarOrdenado(Lista* lista)
{
    Nodo* nuevo;
    Nodo* aux=lista->primero;
    int cedula;

    nuevo = new Nodo;
    cout <<  "Ingrese el nombre"  << endl;
    cin  >> nuevo->data.nombre;
    cout << "Ingrese la cedula" << endl;
    cin >> cedula;

    while (buscarPersona(lista, cedula) != nullptr)
    {
        clear_screen();
        cout <<  "Ya existe una persona con esta cedula porfavor ingrese otra" << endl;
        cin >> cedula;
    }
    
    nuevo->data.cedula = cedula;
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
    Nodo* aux = lista->primero;

    while(aux!=nullptr)
    {
        cout << endl << aux->data.nombre<< endl;
        cout << aux->data.cedula<< endl;
        aux = aux->sig;
    }
}

void eliminarLista(Nodo* actual)
{
    if(actual == nullptr)
    {
        return;
    }

    eliminarLista(actual->sig);

    delete actual;
}


int main()
{
    int opcion;
    Lista* lista = crearLista();
    int cedula;
    Nodo* persona;

    do
    {
        do
        {
            clear_screen();
            cout << "Seleccione una Opcion" << endl;
            cout << "1.-)Agregar"<<endl<<"2.-)Mostrar"<<endl<<"3.-)Buscar"<<endl<<"4.-)Salir"<<endl;
            cin >> opcion;
        }while(opcion<1 || opcion > 4);

        switch(opcion)
        {
            case 1: 
                clear_screen();
                agregarOrdenado(lista);
            break;

            case 2:
                clear_screen(); 
                mostrarLista(lista);
                cin.ignore();
                cin.get();
            break;

            case 3:
                clear_screen();
                cout << "Ingrese la cedula a buscar" << endl;
                cin >> cedula;
                persona = buscarPersona(lista, cedula);
                if (persona != nullptr)
                {
                    cout << "Nombre: " << persona->data.nombre << endl;
                    cout << "Cedula: " << persona->data.cedula << endl;
                }
                else
                {
                    cout  << "No se encontro a  ninguna persona con ese numero de cedula";
                }
                cin.ignore();
                cin.get();
            break;

            case 4:
                clear_screen();
                eliminarLista(lista->primero);
                delete lista;
                lista  = nullptr;
                cout << "Hasta Luego!"<<endl;
            break;
        }
    }while(opcion!=4);
}