# GUIMaker

GUIMaker è una libreria semplice per Arduino che avvolge le funzionalità di LVGL, consentendo di creare interfacce grafiche utente (GUI) in modo semplice e intuitivo. Questa libreria include una serie di metodi per creare vari widget GUI come pulsanti, etichette, aree di testo, e molto altro.

## Funzionalità Principali

### Inizializzazione

- `GUIMaker()`
  - Costruttore della classe GUIMaker.
  - **Data**: 2024-06-06
  - **Descrizione**: Inizializza l'istanza della classe GUIMaker.

- `void begin()`
  - Inizializza la libreria LVGL e il display.
  - **Data**: 2024-06-06
  - **Descrizione**: Configura il display e il touch screen, inizializza il buffer di disegno e i driver di visualizzazione.

- `void update()`
  - Aggiorna LVGL.
  - **Data**: 2024-06-06
  - **Descrizione**: Chiama il gestore di attività di LVGL per mantenere aggiornata l'interfaccia utente.

- `void clear()`
  - Pulisce lo schermo corrente.
  - **Data**: 2024-06-06
  - **Descrizione**: Rimuove tutti i widget dallo schermo corrente.

### Creazione di Widget

- `lv_obj_t* createScreen(uint16_t width, uint16_t height)`
  - Crea una nuova schermata.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea una schermata vuota con le dimensioni specificate e la imposta come schermo attivo.

- `lv_obj_t* createButton(lv_obj_t* parent, const char* label, uint16_t width, uint16_t height, void (*event_cb)(void))`
  - Crea un pulsante.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un pulsante con un'etichetta e un callback evento.

- `lv_obj_t* createLabel(lv_obj_t* parent, const char* text, uint16_t x, uint16_t y)`
  - Crea un'etichetta.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un'etichetta con il testo specificato e la posizione specificata.

- `lv_obj_t* createImage(lv_obj_t* parent, const void* src, uint16_t x, uint16_t y)`
  - Crea un'immagine.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un'immagine con la sorgente specificata e la posizione specificata.

- `lv_obj_t* createLine(lv_obj_t* parent, const lv_point_t* points, uint16_t point_num, uint16_t x, uint16_t y)`
  - Crea una linea.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea una linea con i punti specificati e la posizione specificata.

- `lv_obj_t* createArc(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - Crea un arco.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un arco con le dimensioni e la posizione specificate.

- `lv_obj_t* createBar(lv_obj_t* parent, uint16_t width, uint16_t height, int32_t initial_value, uint16_t x, uint16_t y)`
  - Crea una barra di progresso.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea una barra di progresso con le dimensioni, il valore iniziale e la posizione specificati.

- `lv_obj_t* createSlider(lv_obj_t* parent, uint16_t width, uint16_t height, int32_t initial_value, uint16_t x, uint16_t y)`
  - Crea un cursore.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un cursore con le dimensioni, il valore iniziale e la posizione specificati.

- `lv_obj_t* createSwitch(lv_obj_t* parent, uint16_t x, uint16_t y)`
  - Crea un interruttore.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un interruttore a levetta con la posizione specificata.

- `lv_obj_t* createLED(lv_obj_t* parent, uint16_t x, uint16_t y)`
  - Crea un LED.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un LED virtuale con la posizione specificata.

- `lv_obj_t* createCheckbox(lv_obj_t* parent, const char* label, uint16_t x, uint16_t y)`
  - Crea una casella di controllo.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea una casella di controllo con l'etichetta e la posizione specificata.

- `lv_obj_t* createDropdown(lv_obj_t* parent, const char* options, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - Crea un menu a discesa.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un menu a discesa con le opzioni, le dimensioni e la posizione specificate.

- `lv_obj_t* createRoller(lv_obj_t* parent, const char* options, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - Crea un selettore a rullo.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un selettore a rullo con le opzioni, le dimensioni e la posizione specificate.

- `lv_obj_t* createTextarea(lv_obj_t* parent, const char* placeholder, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - Crea un'area di testo.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un'area di testo con il segnaposto, le dimensioni e la posizione specificate. Mostra automaticamente una tastiera virtuale quando viene toccata.

- `lv_obj_t* createKeyboard(lv_obj_t* parent)`
  - Crea una tastiera virtuale.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea una tastiera virtuale sullo schermo.

- `lv_obj_t* createMessagebox(const char* title, const char* text, const char* buttons[], bool add_close_button)`
  - Crea una finestra di messaggio.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea una finestra di messaggio con il titolo, il testo, i pulsanti e la possibilità di aggiungere un pulsante di chiusura.

- `lv_obj_t* createTable(lv_obj_t* parent, uint16_t col_count, uint16_t row_count, uint16_t x, uint16_t y)`
  - Crea una tabella.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea una tabella con il numero di colonne e righe, e la posizione specificati.

- `lv_obj_t* createChart(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - Crea un grafico.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un grafico con le dimensioni e la posizione specificate.

- `lv_obj_t* createList(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - Crea una lista.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea una lista con le dimensioni e la posizione specificate.

- `lv_obj_t* createTileview(lv_obj_t* parent, uint16_t x, uint16_t y)`
  - Crea un visualizzatore a piastrelle.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un visualizzatore a piastrelle con la posizione specificata.

- `lv_obj_t* createTabview(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - Crea un visualizzatore a schede.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un visualizzatore a schede con le dimensioni e la posizione specificate.

- `lv_obj_t* createCalendar(lv_obj_t* parent, uint16_t x, uint16_t y)`
  - Crea un calendario.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un calendario con la posizione specificata.

- `lv_obj_t* createSpinbox(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - Crea una casella di selezione numerica.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea una casella di selezione numerica con le dimensioni e la posizione specificate. Mostra automaticamente una tastiera virtuale quando viene toccata.

- `lv_obj_t* createColorPicker(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y)`
  - Crea un selettore di colori.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un selettore di colori con le dimensioni e la posizione specificate.

- `lv_obj_t* createPreloader(lv_obj_t* parent, uint16_t width, uint16_t height, uint32_t time, uint16_t x, uint16_t y)`
  - Crea un indicatore di caricamento.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un indicatore di caricamento con le dimensioni, il tempo e la posizione specificate.

- `lv_obj_t* createMeter(lv_obj_t* parent, uint16_t x, uint16_t y)`
  - Crea un misuratore.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un misuratore con la posizione specificata.

- `lv_obj_t* createGauge(lv_obj_t* parent, uint16_t x, uint16_t y)`
  - Crea un indicatore.
  - **Data**: 2024-06-06
  - **Descrizione**: Crea un indicatore con la posizione specificata.

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

    lv_obj_t* screen = gui.createScreen(800, 480);

    gui.createBar(screen, 200, 20, 70, 300, 200);
    gui.createLabel(screen, "Hello World", 350, 250);

    gui.createButton(screen, "Press Me", 100, 50, onButtonClick);
}

void loop() {
    gui.update();
}
