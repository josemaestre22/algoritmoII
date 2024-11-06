#include<iostream>

using namespace std;

struct Data{
    int dato;
};

struct Nodo{
    struct Data data;
    Nodo* siguiente;
};

struct Cola{
    Nodo* primero;
    NFDBITS* ultimo;
};

void isEmpty(Cola c)
{

}

