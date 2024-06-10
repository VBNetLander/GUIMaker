#include <GUIMaker.h>

GUIMaker gui;

void onButtonClick(lv_event_t * e) {
    Serial.println("Button Pressed!");
}

void setup() {
    Serial.begin(115200);
    gui.begin();
    gui.clear();

    // Creazione di una schermata
    auto screen = gui.CreateScreen(800, 480);

    // Creazione di una barra
    gui.CreateBar(screen, 200, 20, 70);

    // Creazione di un'etichetta
    gui.CreateLabel(screen, "Hello World", 350, 250);

    // Creazione di un bottone con callback
    gui.CreateButton(screen, "Press Me", 100, 50, onButtonClick);

    // Creazione di un container con griglia
    const uint16_t col_dsc[] = {370, 370};
    const uint16_t row_dsc[] = {215, 215};
    auto cont = gui.CreateContainer(screen, col_dsc, 2, row_dsc, 2, 800, 480, 0x03989e);

    // Creazione di un checkbox
    gui.CreateCheckbox(cont, "Checkbox", true);

    // Creazione di una textarea
    gui.CreateTextarea(cont, "Enter text here...", 200, 50, 50, 50);
}

void loop() {
    gui.update();
}
