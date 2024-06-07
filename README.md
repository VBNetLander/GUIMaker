# GUIMaker

GUIMaker è una libreria che semplifica la creazione di GUI per Arduino Giga Display Shield ed altri display con supporto al touch screen. La libreria sfrutta tutte le caratteristiche della popolare LVGL (Light and Versatile Graphics Library).

## Installazione

Per utilizzare GUIMaker nel tuo progetto, segui i seguenti passaggi:

1. Scarica il file ZIP della libreria dal repository GitHub.
2. Apri l'IDE di Arduino.
3. Vai su "Sketch" > "Includi Libreria" > "Aggiungi Libreria .ZIP".
4. Seleziona il file ZIP scaricato e clicca su "Apri".
5. L'IDE di Arduino installerà automaticamente la libreria GUIMaker.

## Utilizzo

Ecco un esempio di come utilizzare GUIMaker per creare una semplice interfaccia utente:

```cpp
#include <GUIMaker.h>

GUIMaker gui;

void setup() {
    // Inizializza il display
    gui.init();
    
    // Crea un pulsante
    gui.createButton(50, 50, 100, 50, "Clicca");
}

void loop() {
    // Aggiorna la GUI
    gui.update();
}
```

## Documentazione

La documentazione completa di GUIMaker è disponibile nel file [DOCUMENTAZIONE.md](DOCUMENTAZIONE.md).

## Contributi

Se desideri contribuire allo sviluppo di GUIMaker, puoi aprire una pull request nel repository GitHub.

## Licenza

GUIMaker è distribuito con licenza MIT. Per ulteriori informazioni, consulta il file [LICENSE.md](LICENSE.md).
