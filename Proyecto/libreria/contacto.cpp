#include "contacto.h"

sContacto* resizeContactos(sContacto* miLista, u_int tam, u_int nuevoTam) {
    sContacto* aux = new sContacto[nuevoTam];

    u_int longitud = (tam <  nuevoTam) ? tam : nuevoTam;

    if(aux != nullptr) {

        for(u_int i = 0; i < longitud; i++)
            aux[i] = miLista[i]; // *(miLista + i)

        delete[] miLista;
        return aux;
    }

    return nullptr;
}

void resizeContactos(sContacto** miLista, u_int tam, u_int nuevoTam) {
    sContacto* aux = new sContacto[nuevoTam];

    if(aux == nullptr)
        return;

    u_int longitud = (tam < nuevoTam) ? tam: nuevoTam;

    for(u_int i = 0; i < longitud; i++)
        aux[i] = *miLista[i]; // **(miLista + i)

    delete[] *miLista;
    *miLista = aux;
}




















