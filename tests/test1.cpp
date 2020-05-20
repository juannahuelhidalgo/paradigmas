// #define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "tateti-funcional.hpp"

TEST_CASE("fila", "[matriz]") {

    /* TEMPLATE VARIANT */
#if	TEMPLATE_VARIANT == 1
    Matriz<TTT> mat = Matriz<TTT> {Fila<TTT>{V, V, V}, Fila<TTT>{V, V, V}, Fila<TTT>{V, V, V}};
    Fila<TTT> aaa = fila<TTT>(0,mat);
    Fila<TTT> bbb = Fila<TTT>{V, V, V};
#endif

    /* NON-TEMPLATE VARIANT */
#if	TEMPLATE_VARIANT == 0
    Matriz mat = Matriz {Fila{X, X, V}, Fila{Y, V, X}, Fila{V, Y, Y}};
    Fila aaa = fila(1,mat);
    Fila bbb = Fila{X, X, V};
#endif

    REQUIRE(aaa==bbb);
}
