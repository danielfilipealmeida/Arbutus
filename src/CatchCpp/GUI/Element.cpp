//
//  Element.cpp
//  Arbutus - CatchCpp Unit Tests
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

TEST_CASE("GUI element should throw when set data invalid json", "[Element::Element]") {
    Element element;

    REQUIRE_THROWS(element.set({}));
    
    REQUIRE_THROWS(element.set({{'a','b'}}));
    REQUIRE_THROWS(element.set({
        {"y", 20},
        {"width", 100},
        {"height", 120}
    }));
    REQUIRE_THROWS(element.set({
        {"x", 10},
        {"width", 100},
        {"height", 120}
    }));
    REQUIRE_THROWS(element.set({
        {"x", 10},
        {"y", 20},
        {"height", 120}
    }));
    REQUIRE_THROWS(element.set({
        {"x", 10},
        {"y", 20},
        {"width", 100}
    }));
}

TEST_CASE("GUI element should properly set data", "[Element::Element]") {
    Element element;
    
    element.set({
        {"x", 10},
        {"y", 20},
        {"width", 100},
        {"height", 120}
    });
   
    ofRectangle rect = element.rect;
    
    REQUIRE(rect.x == 10);
    REQUIRE(rect.y == 20);
    REQUIRE(rect.width == 100);
    REQUIRE(rect.height == 120);
}
