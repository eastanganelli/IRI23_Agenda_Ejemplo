#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <fstream>
#include "agenda.h"

typedef enum codArchivos{ErrorApertura=-1, ErrorEscritura=0, ExitoOperacion=1} eCodArchivos;

eCodArchivos leerArchivoAgenda(std::fstream	*archi, sAgenda *agenda);
eCodArchivos escribirArchivoAgenda(std::fstream	*archi, sAgenda *agenda);
eCodArchivos leerArchivoGrupos(std::fstream *archi, sGrupo *grupos);

#endif // ARCHIVOS_H
