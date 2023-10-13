// Para que reconozca que la clase amiga usa template
template <typename T> class ListaEncadenada;

// Definicion de la clase nodo

template <typename T>
class Nodo
{ 
    friend class ListaEncadenada<T>; // clase amiga para poder acceder directo a los atributos

public:
    Nodo(T e);            // constructor

private:
    T informacion;        // datos almacenados en este nodo
    Nodo<T>* siguiente;        // ptr a otro objeto del mismo tipo
};

template <class T>
Nodo<T>::Nodo(T e) 
{ 
    informacion=e; 
    siguiente = nullptr;
}; 
