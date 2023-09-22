#ifndef CONTACTO_H
#define CONTACTO_H

#include "encabezados.h"

enum Grupo { NINGUNO, FAMILIA, AMIGO, TRABAJO, UNIVERSIDAD };
typedef Grupo eGrupo;

struct Fecha {
    u_int dia, mes, anyo;
}; typedef struct Fecha sFecha;

struct Contacto {
    str Nombre, Apellido, Direccion, Correo, Telefono;
    sFecha FecNac;
    eGrupo Grupo;
}; typedef struct Contacto sContacto;

sContacto crearContacto(str Nombre, str Apellido, sFecha FacNac, str Telefono, str Correo);

#endif // CONTACTO_H
