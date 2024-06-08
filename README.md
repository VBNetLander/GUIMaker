# GUIMaker

GUIMaker è una libreria semplice per Arduino che avvolge le funzionalità di LVGL, consentendo di creare interfacce grafiche utente (GUI) in modo semplice e intuitivo. Questa libreria include una serie di metodi per creare vari widget GUI come pulsanti, etichette, aree di testo, e molto altro.

## Installazione

1. Scarica o clona il repository GUIMaker.
2. Copia la cartella GUIMaker nella cartella `libraries` dell'IDE Arduino.
3. Assicurati che la libreria LVGL e le librerie Arduino_H7_Video e Arduino_GigaDisplayTouch siano correttamente installate.
4. Apri l'IDE Arduino e carica uno degli esempi inclusi per iniziare.

## Funzionalità

### Inizializzazione

- **Nome funzione**: `GUIMaker()`
  - **Data**: 2024-06-06
  - **Ora**: 10:00
  - **Descrizione**: Costruttore della classe GUIMaker. Inizializza l'istanza della classe GUIMaker.
  - **Esempio di utilizzo**:
    ```cpp
    GUIMaker gui;
    ```

- **Nome funzione**: `void begin()`
  - **Data**: 2024-06-06
  - **Ora**: 10:15
  - **Descrizione**: Inizializza la libreria LVGL e il display.
  - **Esempio di utilizzo**:
    ```cpp
    void setup() {
        gui.begin();
    }
    ```

- **Nome funzione**: `void update()`
  - **Data**: 2024-06-06
  - **Ora**: 10:30
  - **Descrizione**: Aggiorna LVGL. Chiama il gestore di attività di LVGL per mantenere aggiornata l'interfaccia utente.
  - **Esempio di utilizzo**:
    ```cpp
    void loop() {
        gui.update();
    }
    ```

- **Nome funzione**: `void clear()`
  - **Data**: 2024-06-06
  - **Ora**: 10:45
  - **Descrizione**: Pulisce lo schermo corrente. Rimuove tutti i widget dallo schermo corrente.
  - **Esempio di utilizzo**:
    ```cpp
    gui.clear();
    ```

### Creazione di Widget

- **Nome funzione**: `CreateScreen(uint16_t width, uint16_t height)`
  - **Data**: 2024-06-06
  - **Ora**: 11:00
  - **Descrizione**: Crea una nuova schermata con le dimensioni specificate e la imposta come schermo attivo.
  - **Esempio di utilizzo**:
    ```cpp
    auto screen = gui.CreateScreen(800, 480);
    ```

- **Nome funzione**: `CreateButton(lv_obj_t* parent, const char* label, uint16_t width, uint16_t height, void (*event_cb)(void))`
  - **Data**: 2024-06-06
  - **Ora**: 11:15
  - **Descrizione**: Crea un pulsante con un'etichetta e un callback evento.
  - **Esempio di utilizzo**:
    ```cpp
    void onButtonClick() {
        Serial.println("Button Pressed!");
    }

    auto button = gui.CreateButton(screen, "Press Me", 100, 50, onButtonClick);
    ```

- **Nome funzione**: `CreateLabel(lv_obj_t* parent, const char* text, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 11:30
  - **Descrizione**: Crea un'etichetta con il testo specificato e la posizione specificata.
  - **Esempio di utilizzo**:
    ```cpp
    auto label = gui.CreateLabel(screen, "Hello World", 350, 250);
    ```

- **Nome funzione**: `CreateImage(lv_obj_t* parent, const void* src, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 11:45
  - **Descrizione**: Crea un'immagine con la sorgente specificata e la posizione specificata.
  - **Esempio di utilizzo**:
    ```cpp
    auto img = gui.CreateImage(screen, &your_image, 100, 100);
    ```

- **Nome funzione**: `CreateLine(lv_obj_t* parent, const lv_point_t* points, uint16_t point_num, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 12:00
  - **Descrizione**: Crea una linea con i punti specificati e la posizione specificata.
  - **Esempio di utilizzo**:
    ```cpp
    lv_point_t line_points[] = {{10, 10}, {100, 100}};
    auto line = gui.CreateLine(screen, line_points, 2, 50, 50);
    ```

- **Nome funzione**: `CreateArc(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 12:15
  - **Descrizione**: Crea un arco con le dimensioni e la posizione specificate.
  - **Esempio di utilizzo**:
    ```cpp
    auto arc = gui.CreateArc(screen, 150, 150, 200, 200);
    ```

- **Nome funzione**: `CreateBar(lv_obj_t* parent, uint16_t width, uint16_t height, int32_t initial_value, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 12:30
  - **Descrizione**: Crea una barra di progresso con le dimensioni, il valore iniziale e la posizione specificati.
  - **Esempio di utilizzo**:
    ```cpp
    auto bar = gui.CreateBar(screen, 200, 20, 70, 300, 200);
    ```

- **Nome funzione**: `CreateSlider(lv_obj_t* parent, uint16_t width, uint16_t height, int32_t initial_value, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 12:45
  - **Descrizione**: Crea un cursore con le dimensioni, il valore iniziale e la posizione specificati.
  - **Esempio di utilizzo**:
    ```cpp
    auto slider = gui.CreateSlider(screen, 200, 30, 50, 100, 100);
    ```

- **Nome funzione**: `CreateSwitch(lv_obj_t* parent, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 13:00
  - **Descrizione**: Crea un interruttore a levetta con la posizione specificata.
  - **Esempio di utilizzo**:
    ```cpp
    auto sw = gui.CreateSwitch(screen, 250, 250);
    ```

- **Nome funzione**: `CreateLED(lv_obj_t* parent, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 13:15
  - **Descrizione**: Crea un LED virtuale con la posizione specificata.
  - **Esempio di utilizzo**:
    ```cpp
    auto led = gui.CreateLED(screen, 50, 50);
    ```

- **Nome funzione**: `CreateCheckbox(lv_obj_t* parent, const char* label, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 13:30
  - **Descrizione**: Crea una casella di controllo con l'etichetta e la posizione specificata.
  - **Esempio di utilizzo**:
    ```cpp
    auto checkbox = gui.CreateCheckbox(screen, "I agree", 100, 100);
    ```

- **Nome funzione**: `CreateDropdown(lv_obj_t* parent, const char* options, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 13:45
  - **Descrizione**: Crea un menu a discesa con le opzioni, le dimensioni e la posizione specificate.
  - **Esempio di utilizzo**:
    ```cpp
    auto dropdown = gui.CreateDropdown(screen, "Option1\nOption2\nOption3", 150, 50, 50, 150);
    ```

- **Nome funzione**: `CreateRoller(lv_obj_t* parent, const char* options, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 14:00
  - **Descrizione**: Crea un selettore a rullo con le opzioni, le dimensioni e la posizione specificate.
  - **Esempio di utilizzo**:
    ```cpp
    auto roller = gui.CreateRoller(screen, "Item1\nItem2\nItem3", 100, 100, 50, 200);
    ```

- **Nome funzione**: `CreateTextarea(lv_obj_t* parent, const char* placeholder, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 14:15
  - **Descrizione**: Crea un'area di testo con il segnaposto, le dimensioni e la posizione specificate. Mostra automaticamente una tastiera virtuale quando viene toccata.
  - **Esempio di utilizzo**:
    ```cpp
    auto textarea = gui.CreateTextarea(screen, "Enter text here...", 300, 50, 50, 50);
    ```

- **Nome funzione**: `CreateKeyboard(lv_obj_t* parent)`
  - **Data**: 2024-06-06
  - **Ora**: 14:30
  - **Descrizione**: Crea una tastiera virtuale sullo schermo.
  - **Esempio di utilizzo**:
    ```cpp
    auto keyboard = gui.CreateKeyboard(screen);
    ```

- **Nome funzione**: `CreateMessagebox(const char* title, const char* text, const char* buttons[], bool add_close_button)`
  - **Data**: 2024-06-06
  - **Ora**: 14:45
  - **Descrizione**: Crea una finestra di messaggio con il titolo, il testo, i pulsanti e la possibilità di aggiungere un pulsante di chiusura.
  - **Esempio di utilizzo**:
    ```cpp
    const char* btns[] = {"OK", "Cancel", ""};
    auto msgbox = gui.CreateMessagebox("Title", "This is a message box", btns, true);
    ```

- **Nome funzione**: `CreateTable(lv_obj_t* parent, uint16_t col_count, uint16_t row_count, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 15:00
  - **Descrizione**: Crea una tabella con il numero di colonne e righe, e la posizione specificati.
  - **Esempio di utilizzo**:
    ```cpp
    auto table = gui.CreateTable(screen, 3, 5, 50, 50);
    ```

- **Nome funzione**: `CreateChart(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 15:15
  - **Descrizione**: Crea un grafico con le dimensioni e la posizione specificate.
  - **Esempio di utilizzo**:
    ```cpp
    auto chart = gui.CreateChart(screen, 200, 150, 100, 100);
    ```

- **Nome funzione**: `CreateList(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 15:30
  - **Descrizione**: Crea una lista con le dimensioni e la posizione specificate.
  - **Esempio di utilizzo**:
    ```cpp
    auto list = gui.CreateList(screen, 200, 150, 100, 100);
    ```

- **Nome funzione**: `CreateTileview(lv_obj_t* parent, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 15:45
  - **Descrizione**: Crea un visualizzatore a piastrelle con la posizione specificata.
  - **Esempio di utilizzo**:
    ```cpp
    auto tileview = gui.CreateTileview(screen, 50, 50);
    ```

- **Nome funzione**: `CreateTabview(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 16:00
  - **Descrizione**: Crea un visualizzatore a schede con le dimensioni e la posizione specificate.
  - **Esempio di utilizzo**:
    ```cpp
    auto tabview = gui.CreateTabview(screen, 300, 200, 100, 50);
    ```

- **Nome funzione**: `CreateCalendar(lv_obj_t* parent, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 16:15
  - **Descrizione**: Crea un calendario con la posizione specificata.
  - **Esempio di utilizzo**:
    ```cpp
    auto calendar = gui.CreateCalendar(screen, 200, 100);
    ```

- **Nome funzione**: `CreateSpinbox(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 16:30
  - **Descrizione**: Crea una casella di selezione numerica con le dimensioni e la posizione specificate. Mostra automaticamente una tastiera virtuale quando viene toccata.
  - **Esempio di utilizzo**:
    ```cpp
    auto spinbox = gui.CreateSpinbox(screen, 100, 50, 50, 200);
    ```

- **Nome funzione**: `CreateColorPicker(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 16:45
  - **Descrizione**: Crea un selettore di colori con le dimensioni e la posizione specificate.
  - **Esempio di utilizzo**:
    ```cpp
    auto colorpicker = gui.CreateColorPicker(screen, 200, 200, 100, 100);
    ```

- **Nome funzione**: `CreatePreloader(lv_obj_t* parent, uint16_t width, uint16_t height, uint32_t time, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 17:00
  - **Descrizione**: Crea un indicatore di caricamento con le dimensioni, il tempo e la posizione specificate.
  - **Esempio di utilizzo**:
    ```cpp
    auto spinner = gui.CreatePreloader(screen, 100, 100, 1000, 150, 150);
    ```

- **Nome funzione**: `CreateMeter(lv_obj_t* parent, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 17:15
  - **Descrizione**: Crea un misuratore con la posizione specificata.
  - **Esempio di utilizzo**:
    ```cpp
    auto meter = gui.CreateMeter(screen, 200, 200);
    ```

- **Nome funzione**: `CreateGauge(lv_obj_t* parent, uint16_t x, uint16_t y)`
  - **Data**: 2024-06-06
  - **Ora**: 17:30
  - **Descrizione**: Crea un indicatore con la posizione specificata.
  - **Esempio di utilizzo**:
    ```cpp
    auto gauge = gui.CreateGauge(screen, 300, 300);
    ```

## Esempi

### BasicExample.ino

```cpp
#include <GUIMaker.h>

GUIMaker gui;

void onButtonClick() {
    Serial.println("Button Pressed!");
}

void setup() {
    Serial.begin(115200);
    gui.begin();
    gui.clear();

    auto screen = gui.CreateScreen(800, 480);

    gui.CreateBar(screen, 200, 20, 70, 300, 200);
    gui.CreateLabel(screen, "Hello World", 350, 250);

    gui.CreateButton(screen, "Press Me", 100, 50, onButtonClick);
}

void loop() {
    gui.update();
}
