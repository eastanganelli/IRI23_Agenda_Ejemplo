#ifndef CONTACTO_H
#define CONTACTO_H

#include "encabezados.h"

typedef struct sGrupo {
    unsigned int id;
    std::string nombre;
} sGrupo;

enum Grupo { NINGUNO, FAMILIA, AMIGO, TRABAJO, UNIVERSIDAD };
const str Grupos[5] = { "NINGUNO", "FAMILIA", "AMIGO", "TRABAJO", "UNIVERSIDAD" };
typedef enum Grupo eGrupo;

struct Fecha {
    u_int dia, mes, anyo;
}; typedef struct Fecha sFecha;

struct Contacto {
    str Nombre, Apellido, Direccion, Correo, Telefono;
    sFecha FecNac;
    eGrupo Grupo;
}; typedef struct Contacto sContacto;

struct Agrupar {
    sContacto* contactos;
    u_int tam, actual;
    str Grupito;
}; typedef struct Agrupar sAgrupar;

sContacto crearContacto(str Nombre, str Apellido, sFecha FacNac, str Telefono, str Correo);
sContacto* resizeContactos(sContacto* miLista, u_int tam, u_int nuevoTam);
void resizeContactos(sContacto** miLista, u_int tam, u_int nuevoTam);

#endif // CONTACTO_H







