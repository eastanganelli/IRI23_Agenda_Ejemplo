#include "archivos.h"

eCodArchivos leerArchivoAgenda(std::fstream	*archi, sAgenda *agenda){
    // Comprueba que el archivo se pudo abrir.
    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    // Lee la estructura de la agenda completa.
    archi->read((char*)agenda, sizeof(sAgenda));

    if(!*archi){
        return eCodArchivos::ErrorEscritura;
    }

    return eCodArchivos::ExitoOperacion;
}

eCodArchivos escribirArchivoAgenda(std::fstream	*archi, sAgenda *agenda){

    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    archi->write((char*)agenda, sizeof(sAgenda));

    return eCodArchivos::ExitoOperacion;
}

eCodArchivos leerArchivoGrupos(std::fstream *archi, sGrupo *grupos){
    unsigned int auxId;
    std::string auxNombre;
    char coma;
    int i=0;

    if(!archi->is_open())
        return eCodArchivos::ErrorApertura;

    while(*archi>>auxId>>coma>>auxNombre){
        (grupos+i)->id=auxId;
        (grupos+i)->nombre=auxNombre;
        i++;
    }

    return eCodArchivos::ExitoOperacion;
}
