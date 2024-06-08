#include <GUIMaker.h>

GUIMaker gui;

void setup() {
    Serial.begin(115200);
    gui.begin();
    gui.clear();

    // Creazione di una schermata
    lv_obj_t* screen = gui.createScreen(800, 480);

    // Creazione di un campo di testo con un'etichetta segnaposto
    lv_obj_t* textArea1 = gui.createTextarea(screen, "Enter text here...", 300, 50, 50, 50);

    // Creazione di un secondo campo di testo con un'etichetta segnaposto
    lv_obj_t* textArea2 = gui.createTextarea(screen, "Type something...", 300, 50, 50, 150);

    // Creazione di un terzo campo di testo con un'etichetta segnaposto
    lv_obj_t* textArea3 = gui.createTextarea(screen, "Your message...", 300, 50, 50, 250);
}

void loop() {
    gui.update();
}
