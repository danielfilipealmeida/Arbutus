//
//  Viewport.cpp
//  Arbutus
//
//  Created by Daniel Almeida on 03/10/17.
//
//

#include <stdio.h>
#include "catch.hpp"
#include "Viewport.hpp"


TEST_CASE("Viewport should be properly created", "[Viewport]") {
    Viewport *viewport;
    
    viewport = new Viewport();
    viewport->set({
        {"x", 100},
        {"y", 100},
        {"width", 100},
        {"height", 100},
        {"totalWidth", 200},
        {"totalHeight", 200}
    });
    viewport->update();
    
    REQUIRE(viewport->totalWidth == 200);
    REQUIRE(viewport->totalHeight == 200);
    REQUIRE(viewport->overflowX == 100);
    REQUIRE(viewport->overflowY == 100);
}

TEST_CASE("Viewport should accept elements", "[Viewport]") {
    Viewport *viewport;
    
    viewport = new Viewport();
    viewport->set({
        {"x", 100},
        {"y", 100},
        {"width", 100},
        {"height", 100},
        {"totalWidth", 200},
        {"totalHeight", 200}
    });

    Element *element;
    element = new Element;
    element->set({
        {"x", 10},
        {"y", 10},
        {"width", 80},
        {"height", 32}
    });
    element->setParent(viewport);
    viewport->update();
    element->update();
    
    REQUIRE(element->parent == viewport);
}


TEST_CASE("Elements should be properly scrollable inside viewport", "[Viewport]") {
    Viewport *viewport;
    
    viewport = new Viewport();
    viewport->set({
        {"x", 100},
        {"y", 100},
        {"width", 100},
        {"height", 100},
        {"totalWidth", 200},
        {"totalHeight", 200}
    });
    
    Element *element;
    element = new Element;
    element->set({
        {"x", 10},
        {"y", 10},
        {"width", 80},
        {"height", 32}
    });
    element->setParent(viewport);
    viewport->update();
    element->update();
    ofRectangle drawingRect = viewport->calculateDrawingRectForElement(element);
    
    REQUIRE(drawingRect.x == 10);
    REQUIRE(drawingRect.y == 10);
    
    viewport->scrollPositionX = viewport->scrollPositionY = 0.5;
    viewport->update();
    element->update();
    drawingRect = viewport->calculateDrawingRectForElement(element);
    
    REQUIRE(drawingRect.x == (10 - (viewport->overflowX / 2.0)));
    REQUIRE(drawingRect.y == (10 - (viewport->overflowY / 2.0)));

    viewport->scrollPositionX = viewport->scrollPositionY = 1.0;
    viewport->update();
    element->update();
    drawingRect = viewport->calculateDrawingRectForElement(element);
    
    REQUIRE(drawingRect.x == (10 - (viewport->overflowX)));
    REQUIRE(drawingRect.y == (10 - (viewport->overflowY)));
}
