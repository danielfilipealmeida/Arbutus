//
//  Set.cpp
//  ArbutusEngine
//
//  Created by Daniel Almeida on 29/08/17.
//
//

#include <stdio.h>
#include "catch.hpp"
#include "Element.hpp"


TEST_CASE("Should create GUI element", "[Element::Element]") {
    Element element;
    
    REQUIRE(element.hover == FALSE);
    REQUIRE(element.pressed == FALSE);
    REQUIRE(element.entered == FALSE);
    REQUIRE(element.exited == FALSE);
    
}
