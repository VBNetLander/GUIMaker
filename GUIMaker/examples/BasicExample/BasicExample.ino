#include "GUIMaker.h"

GUIMaker gui;

void onButtonClick() {
    Serial.println("Button Pressed!");
}

void setup() {
    Serial.begin(115200);
    gui.begin();
    gui.clear();

    lv_obj_t* screen = gui.createScreen(800, 480);

    gui.createBar(screen, 200, 20, 70, 300, 200);
    gui.createLabel(screen, "Hello World", 350, 250);

    gui.createButton(screen, "Press Me", 100, 50, onButtonClick);
}

void loop() {
    gui.update();
}
