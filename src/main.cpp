#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "calc.h"
#include "doctest.h"
#include <iostream>

using namespace std;

TEST_CASE("add"){
    Calculator calc;
    CHECK(calc.add(2,3) == 5);
    CHECK(calc.add(-3,3) == 0);
}
TEST_CASE("sub"){
    Calculator calc;
    CHECK(calc.sub(2,3) == -1);
    CHECK(calc.sub(-3,3) == -6);
}
TEST_CASE("mul"){
    Calculator calc;
    CHECK(calc.mul(2,3) == 6);
    CHECK(calc.mul(-3,3) == -9);
}
TEST_CASE("div"){
    Calculator calc;
    CHECK(calc.div(3,2) == 1);
    CHECK(calc.div(-3,3) == -1);
}