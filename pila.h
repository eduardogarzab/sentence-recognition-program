# include <iostream>
# include "listaEncadenada.h"

using namespace std;

template <typename T>
class Pila: public ListaEncadenada<T>{
    public:
        bool mete(T info);
        void saca();
        T tope();
};

template <typename T>
bool Pila<T>::mete(T info){
    return this->insertarElementoInicio(info);
}

template <typename T>
void Pila<T>::saca(){
    this->borrarElementoInicio();
}

template <typename T>
T Pila<T>::tope(){
    return this->traerDatosInicio();
}