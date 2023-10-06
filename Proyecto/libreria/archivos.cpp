#include "archivos.h"

eCodArchivos leerArchivoAgenda(sAgenda *agenda){

    //Abre el archivo en modo binario y de lectura.
    std::fstream archi("Agenda.dat", std::ios::in | std::ios::binary);

    // Comprueba que el archivo se pudo abrir.
    if(!archi.is_open())
        return eCodArchivos::ErrorApertura;

    // Lee la estructura de la agenda completa.
    archi.read((char*)agenda, sizeof(sAgenda));

    if(!archi){
        archi.close();
        return eCodArchivos::ErrorEscritura;
    }
    // Cierra el archivo.
    archi.close();

    return eCodArchivos::ExitoOperacion;
}

eCodArchivos escribirArchivoAgenda(sAgenda *agenda){
    std::fstream archi("Agenda.dat", std::ios::out | std::ios::binary | std::ios::trunc);

    if(!archi.is_open())
        return eCodArchivos::ErrorApertura;

    archi.write((char*)agenda, sizeof(sAgenda));

    archi.close();

    return eCodArchivos::ExitoOperacion;
}
