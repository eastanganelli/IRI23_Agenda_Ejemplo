#include <catch2/catch.hpp>
#include <contacto.h>

const sContacto DefaultContactos[3] = {
    {"Juan", "Perez", "Calle 123", "juan@example.com", "123-456-7890", {5, 3, 1985},  eGrupo::AMIGO},
    {"Maria", "Gonzalez", "Avenida 456", "maria@example.com", "987-654-3210", {15, 11, 1992},  eGrupo::FAMILIA},
    {"Laura", "Lopez", "Plaza 123", "laura@example.com", "333-444-5555", {3, 9, 1995},  eGrupo::TRABAJO}
};

TEST_CASE("Resize Array Contactos") {
    sContacto* MisContactos = new sContacto[3];

    REQUIRE(MisContactos != nullptr);

    for(u_int i = 0; i < 3; i++)
        MisContactos[i] = DefaultContactos[i];

    SECTION("Agregando 2 nuevo dato") {
        sContacto* ViejaDireccion = MisContactos;

        resizeContactos(&MisContactos, 3 , 3 + 2);
        MisContactos[3] = {"Carlos", "Lopez", "Plaza 789", "carlos@example.com", "555-123-4567", {8, 7, 1980},  eGrupo::TRABAJO};
        MisContactos[3] = {"Ana", "Martinez", "Calle 567", "ana@example.com", "111-222-3333", {20, 12, 1998},  eGrupo::AMIGO};

        CHECK(ViejaDireccion != MisContactos);
    }

    resizeContactos(&MisContactos, 3 , 3 + 2);
    MisContactos[3] = {"Carlos", "Lopez", "Plaza 789", "carlos@example.com", "555-123-4567", {8, 7, 1980},  eGrupo::TRABAJO};
    MisContactos[3] = {"Ana", "Martinez", "Calle 567", "ana@example.com", "111-222-3333", {20, 12, 1998},  eGrupo::AMIGO};

    SECTION("Achicando 4 nuevo dato") {
        sContacto* ViejaDireccion = MisContactos;

        resizeContactos(&MisContactos, 5 , 1);

        CHECK(ViejaDireccion != MisContactos);
    }

}
