# include <iostream>
# include "listaEncadenada.h"

using namespace std;

template <typename T>
class Fila: public ListaEncadenada<T>{
    public:
        bool mete(T info);
        void saca();
        T siguiente();
};

template <typename T>
bool Fila<T>::mete(T info){
    this->insertarElementoFinal(info);
}

template <typename T>
void Fila<T>::saca(){
    this->borrarElementoInicio();
}

template <typename T>
T Fila<T>::siguiente(){
    return this->traerDatosInicio();
}

