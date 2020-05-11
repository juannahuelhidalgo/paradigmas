// #define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tateti-funcional.hpp"

TEST_CASE("fila", "[matriz]") {
    // Matriz<Fila<int>> mat = {Fila<int> {0,0,0}, Fila<int> {0,0,0}, Fila<int> {0,0,0}};

    // REQUIRE(fila<Fila<int>,Matriz<Fila<int>>>(2, mat) == Fila<int>{0,0,0});

    /* TEMPLATE VARIANT */
    // Matriz<TTT> mat = Matriz<TTT> {Fila<TTT>{V, V, V}, Fila<TTT>{V, V, V}, Fila<TTT>{V, V, V}};
    // Fila<TTT> aaa = fila<TTT>(0,mat);
    // Fila<TTT> bbb = Fila<TTT>{V, V, V};

    /* NON-TEMPLATE VARIANT */
    Matriz mat = Matriz {Fila{V, V, V}, Fila{V, V, V}, Fila{V, V, V}};
    Fila aaa = fila(1,mat);
    Fila bbb = Fila{V, V, V};
    
    REQUIRE(aaa==bbb);
}
