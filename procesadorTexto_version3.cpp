#include <iostream>
#include <fstream>
#include <sstream>

#include "fila.h"
using namespace std;

void convertirAMinusculas(string& palabra){
    for (int i = 0; i < palabra.length(); i++) { // Convierte la palabra a minusculas caracter por caracter
        palabra[i] = tolower(palabra[i]); // Convierte el caracter a minuscula
    }
}
bool palabraEsValida(const string& palabra, Fila<string>& fila){
    return fila.buscarElemento(palabra); // Regresa true si la palabra esta en la fila, false si no esta
}

Fila<string> leerArchivo(const string& nombreArchivo){
    Fila<string> fila;
    ifstream archivo;
    string linea;

    archivo.open(nombreArchivo, ios::in); // Abre el archivo en modo lectura
    if(archivo.is_open()){ // Si se pudo abrir el archivo
        while (!archivo.eof()) { // Mientras no sea el final del archivo
            getline(archivo, linea); // Lee una linea 
            fila.mete(linea); // Mete la linea a la fila
        }
        archivo.close();
    }else {
        cout << "No se pudo abrir el archivo " << nombreArchivo << endl;
    }
    return fila;
}

int main(){
    system("cls");

    Fila<string> filaArticulos = leerArchivo("articulos.txt");
    Fila<string> filaSustantivos = leerArchivo("sustantivos.txt");
    Fila<string> filaAdjetivos = leerArchivo("adjetivos.txt");
    Fila<string> filaVerbos = leerArchivo("verbos.txt");
    Fila<string> filaObjetos = leerArchivo("objetosDirectos.txt");
    Fila<string> filaOraciones = leerArchivo("oraciones.txt");
    Fila<string> filaOracionesValidas, filaOracionesInvalidas;

    while (!filaOraciones.estaVacia()) {
        string oracion = filaOraciones.siguiente(); // Obtiene la oracion de la fila
        convertirAMinusculas(oracion); // Convierte la oracion a minusculas para comparar las palabras con las filas que tambien estan en minusculas

        int contador = 0;
        string articulo, sustantivo, adjetivo, verbo, objetoDirecto, palabra, palabras[5];
        istringstream is(oracion); // Convierte la oracion en un objeto
        Fila<string> filaPalabras;

        while(is >> palabra){ // Mientras haya palabras en la oracion
            filaPalabras.mete(palabra); // Mete la palabra a la fila de palabras
            contador++; // Cuenta las palabras que componen la oracion
        }

        if (contador == 5) {
            for (int i = 0; i < 5; i++){
                palabras[i] = filaPalabras.siguiente(); filaPalabras.saca();// Obtiene las palabras de la fila de palabras
            }

            if (palabraEsValida(palabras[0], filaArticulos) && palabraEsValida(palabras[1], filaSustantivos) && palabraEsValida(palabras[2], filaAdjetivos) && palabraEsValida(palabras[3], filaVerbos) && palabraEsValida(palabras[4], filaObjetos)) { // Si todas las palabras que componen la oracion son validas
                filaOracionesValidas.mete(filaOraciones.siguiente()); // Mete la oracion a la fila de oraciones validas
            }
            else { // Si alguna de las palabras no es valida
                filaOracionesInvalidas.mete(filaOraciones.siguiente()); // Mete la oracion a la fila de oraciones invalidas
            }
        }
        else {
            filaOracionesInvalidas.mete(filaOraciones.siguiente()); // Mete la oracion a la fila de oraciones invalidas
        }
        filaOraciones.saca(); // Saca la oracion de la fila ya que se realizo todo el proceso
    }

    cout << endl << "====================== Oraciones validas ======================" << endl << endl;
    filaOracionesValidas.desplegar(); // Imprime la fila de oraciones validas

    cout << endl << "===================== Oraciones invalidas =====================" << endl << endl;
    filaOracionesInvalidas.desplegar(); // Imprime la fila de oraciones invalidas
    cout << endl;

    return 0;
}