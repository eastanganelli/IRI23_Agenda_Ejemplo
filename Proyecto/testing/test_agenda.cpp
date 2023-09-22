#include <catch2/catch.hpp>
#include <agenda.h>

TEST_CASE("Agenda Agregacion") {
    sAgenda* miAgenda = new sAgenda;
    REQUIRE(miAgenda != nullptr); // Puntero de Agenda es nullptr?

    miAgenda->CantMaxima = 6;
    miAgenda->CantContactos = 0;
    miAgenda->misContactos = new sContacto[miAgenda->CantMaxima];

    REQUIRE(miAgenda->misContactos != nullptr);

    SECTION("Agregando 2 elementos") {
        agregarContacto(miAgenda, {"Juan", "Perez", "Calle 123", "juan@example.com", "123-456-7890", {5, 3, 1985}, eGrupo::FAMILIA});
        agregarContacto(miAgenda, {"Carlos", "Lopez", "Plaza 789", "carlos@example.com", "555-123-4567", {8, 7, 1980}, eGrupo::TRABAJO});

        REQUIRE(miAgenda->CantContactos == 2);
    }

    SECTION("Agregando 1 elemento") {
        agregarContacto(miAgenda, {"Laura", "Lopez", "Plaza 123", "laura@example.com", "333-444-5555", {3, 9, 1995}, eGrupo::TRABAJO});
        REQUIRE(miAgenda->CantContactos == 1);
    }

    delete[] miAgenda->misContactos;
    delete miAgenda;
};

TEST_CASE("Agenda Modificacion") {
    sAgenda* miAgenda = new sAgenda;
    REQUIRE(miAgenda != nullptr); // Puntero de Agenda es nullptr?

    miAgenda->CantMaxima = 6;
    miAgenda->CantContactos = 0;
    miAgenda->misContactos = new sContacto[miAgenda->CantMaxima];

    REQUIRE(miAgenda->misContactos != nullptr);

    agregarContacto(miAgenda, {"Juan", "Perez", "Calle 123", "juan@example.com", "123-456-7890", {5, 3, 1985},  eGrupo::AMIGO});
    agregarContacto(miAgenda, {"Maria", "Gonzalez", "Avenida 456", "maria@example.com", "987-654-3210", {15, 11, 1992},  eGrupo::FAMILIA});
    agregarContacto(miAgenda, {"Carlos", "Lopez", "Plaza 789", "carlos@example.com", "555-123-4567", {8, 7, 1980},  eGrupo::TRABAJO});
    agregarContacto(miAgenda, {"Ana", "Martinez", "Calle 567", "ana@example.com", "111-222-3333", {20, 12, 1998},  eGrupo::AMIGO});
    agregarContacto(miAgenda, {"Pedro", "Rodriguez", "Avenida 890", "pedro@example.com", "999-888-7777", {10, 4, 1987},  eGrupo::FAMILIA});
    agregarContacto(miAgenda, {"Laura", "Lopez", "Plaza 123", "laura@example.com", "333-444-5555", {3, 9, 1995},  eGrupo::TRABAJO});

    SECTION("Modificando el 2do elemento") {
        eUpdContacto res = actualizarContacto(miAgenda, {"Maria", "Gonzalez", "Avenida 456", "maria@example.com", "489-3454-2345", {15, 11, 1992},  eGrupo::FAMILIA});
        REQUIRE(res == eUpdContacto::ExitoModificar);
    }

    SECTION("Modificando el 9no elemento") {
        eUpdContacto res = actualizarContacto(miAgenda, 9, {"Laura", "Juan", "Mendonza 4545", "laura@example.com", "333-444-43643", {3, 10, 1995},  eGrupo::UNIVERSIDAD});
        REQUIRE(res == eUpdContacto::ErrUpdIndex);
    }

    delete[] miAgenda->misContactos;
    delete miAgenda;
};

TEST_CASE("Agenda Eliminacion") {
    sAgenda* miAgenda = new sAgenda;
    REQUIRE(miAgenda != nullptr); // Puntero de Agenda es nullptr?

    miAgenda->CantMaxima = 6;
    miAgenda->CantContactos = 0;
    miAgenda->misContactos = new sContacto[miAgenda->CantMaxima];

    REQUIRE(miAgenda->misContactos != nullptr);

    {
        agregarContacto(miAgenda, {"Juan", "Perez", "Calle 123", "juan@example.com", "123-456-7890", {5, 3, 1985},  eGrupo::AMIGO});
        agregarContacto(miAgenda, {"Maria", "Gonzalez", "Avenida 456", "maria@example.com", "987-654-3210", {15, 11, 1992},  eGrupo::FAMILIA});
        agregarContacto(miAgenda, {"Carlos", "Lopez", "Plaza 789", "carlos@example.com", "555-123-4567", {8, 7, 1980},  eGrupo::TRABAJO});
        agregarContacto(miAgenda, {"Ana", "Martinez", "Calle 567", "ana@example.com", "111-222-3333", {20, 12, 1998},  eGrupo::AMIGO});
        agregarContacto(miAgenda, {"Pedro", "Rodriguez", "Avenida 890", "pedro@example.com", "999-888-7777", {10, 4, 1987},  eGrupo::FAMILIA});
        agregarContacto(miAgenda, {"Laura", "Lopez", "Plaza 123", "laura@example.com", "333-444-5555", {3, 9, 1995},  eGrupo::TRABAJO});
    }
    SECTION("Eliminando el 3ero y 4to elemento") {
        eRmContacto res = removerContacto(miAgenda, "Carlos", "Lopez");
        REQUIRE(res == eRmContacto::ExitoRemover);

        res = removerContacto(miAgenda, "Ana", "Lopez");
        REQUIRE(res == eRmContacto::ErrRmNomApe);
    }

    SECTION("Eliminando el 9noelemento") {
        eRmContacto res = removerContacto(miAgenda, 8);
        REQUIRE(res == eRmContacto::ErrRmIndex);
    }

    SECTION("Eliminando el 3 y 4 elemento") {
        eRmContacto res = removerContacto(miAgenda, {"Pedro", "Rodriguez", "Avenida 890", "pedro@example.com", "999-888-7777", {10, 4, 1987},  eGrupo::FAMILIA});
        REQUIRE(res == eRmContacto::ExitoRemover);
    }

    delete[] miAgenda->misContactos;
    delete miAgenda;
};

TEST_CASE("Agenda Busqueda") {
    sAgenda* miAgenda = new sAgenda;
    REQUIRE(miAgenda != nullptr); // Puntero de Agenda es nullptr?

    miAgenda->CantMaxima = 6;
    miAgenda->CantContactos = 0;
    miAgenda->misContactos = new sContacto[miAgenda->CantMaxima];

    REQUIRE(miAgenda->misContactos != nullptr);

    {
        agregarContacto(miAgenda, {"Juan", "Perez", "Calle 123", "juan@example.com", "123-456-7890", {5, 3, 1985},  eGrupo::AMIGO});
        agregarContacto(miAgenda, {"Maria", "Gonzalez", "Avenida 456", "maria@example.com", "987-654-3210", {15, 11, 1992},  eGrupo::FAMILIA});
        agregarContacto(miAgenda, {"Carlos", "Lopez", "Plaza 789", "carlos@example.com", "555-123-4567", {8, 7, 1980},  eGrupo::TRABAJO});
        agregarContacto(miAgenda, {"Ana", "Martinez", "Calle 567", "ana@example.com", "111-222-3333", {20, 12, 1998},  eGrupo::AMIGO});
        agregarContacto(miAgenda, {"Pedro", "Rodriguez", "Avenida 890", "pedro@example.com", "999-888-7777", {10, 4, 1987},  eGrupo::FAMILIA});
        agregarContacto(miAgenda, {"Laura", "Lopez", "Plaza 123", "laura@example.com", "333-444-5555", {3, 9, 1995},  eGrupo::TRABAJO});
    }
    SECTION("Buscando el contacto con correo") {
        sContacto res = buscarContacto(miAgenda, "ana@example.com");
        REQUIRE(res.Nombre == "Ana" );
    }

    SECTION("Buscando el 7mo elemento") {
        sContacto res = buscarContacto(miAgenda, 7);
        REQUIRE(res.Nombre == "");
    }

    SECTION("Buscando contacto por Nombre y Apellido") {
        sContacto res = buscarContacto(miAgenda, "Laura Lopez" );
        REQUIRE(res.Nombre == "Laura");
    }

    delete[] miAgenda->misContactos;
    delete miAgenda;
};
