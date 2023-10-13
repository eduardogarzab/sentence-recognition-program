# include <iostream>
# include "Nodo.h"

using namespace std;

// DefiniciÃ³n de la clase Lista Encadenada
template <typename T>
class ListaEncadenada 
{
public:
    ListaEncadenada();            // constructor
    ~ListaEncadenada();           // destructor
    bool estaVacia();
    bool insertarElementoInicio(T info);
    bool insertarElementoFinal(T info);
    int tamanio();
    int encontrarPosicionElemento(T info);
    void borrarElementoInicio();
    void borrarElementoFinal();
    void desplegar();
    T traerDatosInicio();
    bool buscarElemento(T info);
    

private:       
    Nodo<T> *inicio, *final;        // ptr a objeto inicial de la lista
};

template <typename T>
ListaEncadenada<T>::ListaEncadenada()
{
    inicio = nullptr;
    final = nullptr;
}

template <typename T>
ListaEncadenada<T>::~ListaEncadenada()
{
    Nodo<T>* auxiliar;

    while (inicio != nullptr)
    {
        auxiliar = inicio;
        inicio = inicio->siguiente;
        delete auxiliar;
    }
}

template <typename T>
bool ListaEncadenada<T>::estaVacia()
{
    return (inicio == nullptr);
}

template <typename T>
bool ListaEncadenada<T>::insertarElementoInicio(T info)
{
    Nodo<T>* nuevo;
    bool bandera;

    nuevo = new Nodo<T>(info);
    bandera = (nuevo != nullptr);

    if (bandera)
    {
        if (inicio == nullptr)
        {
            inicio = nuevo;
            final = nuevo;
        }
        else
        {
            nuevo -> siguiente = inicio;
            inicio = nuevo;
        }
    }

    return bandera;
}

template <typename T>
bool ListaEncadenada<T>::insertarElementoFinal(T info)
{
    Nodo<T>* nuevo;
    bool bandera;

    nuevo = new Nodo<T>(info);
    bandera = (nuevo != nullptr);

    if (bandera)
    {
        if (inicio == nullptr){
            inicio = nuevo;
            final = nuevo;
        }
        else{
            final -> siguiente = nuevo;
            final = nuevo;
        }
    }

    return bandera;
}

template <typename T>
void ListaEncadenada<T>::desplegar()
{
    Nodo<T>* auxiliar = inicio;
    int indice = 0;

    if (inicio != nullptr)
        do
        {
            indice = indice + 1;
            cout << indice << ". " << auxiliar->informacion <<endl;
            auxiliar = auxiliar ->siguiente;
        }while(auxiliar != nullptr);
    else
        cout << "No hay"<<endl;
    
}

template <typename T>
int ListaEncadenada<T>::tamanio()
{
    Nodo<T>* auxiliar = inicio;
    int indice = 0;

    if (inicio != nullptr)
        do
        {   
            indice = indice + 1;
            auxiliar = auxiliar ->siguiente;
        }while(auxiliar != nullptr);
    
    return indice;
    
}

template <typename T>
void ListaEncadenada<T>::borrarElementoFinal()
{
    Nodo<T>* auxiliar = inicio;

    if (inicio != nullptr)
    {
        if (inicio->siguiente == nullptr)
        {  
            delete inicio;
            inicio = nullptr;
        }
        else
        {   while((auxiliar->siguiente)->siguiente != nullptr)
                auxiliar = auxiliar->siguiente;
            delete auxiliar->siguiente;
            final = auxiliar;
            auxiliar -> siguiente = nullptr;
        }
    }
}

template <typename T>    
int ListaEncadenada<T>::encontrarPosicionElemento(T info)
{
    Nodo<T>* auxiliar = inicio;
    int indice = 1;

 
    while ( (auxiliar != nullptr) and (auxiliar->informacion != info))
    {   
        indice = indice + 1;
        auxiliar = auxiliar ->siguiente;
    };

    if (auxiliar == nullptr)
        indice = 0;

    return indice;
 
}

template <typename T>  
void ListaEncadenada<T>::borrarElementoInicio()
{
  Nodo<T>* auxiliar;

  if (inicio != nullptr)
  {
    auxiliar = inicio -> siguiente;
    delete inicio;
    inicio = auxiliar;
  }
}

template <typename T>     
T ListaEncadenada<T>::traerDatosInicio()
{
    if(inicio != nullptr)
        return (inicio->informacion);
    else
        return (T) NULL;
}

template <typename T>
bool ListaEncadenada<T>::buscarElemento(T info)
{
    Nodo<T>* auxiliar = inicio;
    bool bandera = false;

    while ( (auxiliar != nullptr) and (auxiliar->informacion != info))
        auxiliar = auxiliar ->siguiente;

    if (auxiliar != nullptr)
        bandera = true;

    return bandera;
}

