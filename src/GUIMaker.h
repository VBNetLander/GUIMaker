#ifndef GUIMAKER_H
#define GUIMAKER_H

#include <stdint.h>
#include "lvgl/lvgl.h"
#include "Arduino_H7_Video.h"
#include "Arduino_GigaDisplayTouch.h"

class GUIMaker {
public:
    GUIMaker();
    void begin();
    void update();
    void clear();

    // Metodi di creazione dei widget
    lv_obj_t* createScreen(uint16_t width, uint16_t height);
    lv_obj_t* createButton(lv_obj_t* parent, const char* label, uint16_t width, uint16_t height, void (*event_cb)(void));
    lv_obj_t* createLabel(lv_obj_t* parent, const char* text, uint16_t x, uint16_t y);
    lv_obj_t* createImage(lv_obj_t* parent, const void* src, uint16_t x, uint16_t y);
    lv_obj_t* createLine(lv_obj_t* parent, const lv_point_t* points, uint16_t point_num, uint16_t x, uint16_t y);
    lv_obj_t* createArc(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* createBar(lv_obj_t* parent, uint16_t width, uint16_t height, int32_t initial_value, uint16_t x, uint16_t y);
    lv_obj_t* createSlider(lv_obj_t* parent, uint16_t width, uint16_t height, int32_t initial_value, uint16_t x, uint16_t y);
    lv_obj_t* createSwitch(lv_obj_t* parent, uint16_t x, uint16_t y);
    lv_obj_t* createLED(lv_obj_t* parent, uint16_t x, uint16_t y);
    lv_obj_t* createCheckbox(lv_obj_t* parent, const char* label, uint16_t x, uint16_t y);
    lv_obj_t* createDropdown(lv_obj_t* parent, const char* options, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* createRoller(lv_obj_t* parent, const char* options, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* createTextarea(lv_obj_t* parent, const char* placeholder, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* createKeyboard(lv_obj_t* parent);
    lv_obj_t* createMessagebox(const char* title, const char* text, const char* buttons[], bool add_close_button);
    lv_obj_t* createTable(lv_obj_t* parent, uint16_t col_count, uint16_t row_count, uint16_t x, uint16_t y);
    lv_obj_t* createChart(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* createList(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* createTileview(lv_obj_t* parent, uint16_t x, uint16_t y);
    lv_obj_t* createTabview(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* createCalendar(lv_obj_t* parent, uint16_t x, uint16_t y);
    lv_obj_t* createSpinbox(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* createColorPicker(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* createPreloader(lv_obj_t* parent, uint16_t width, uint16_t height, uint32_t time, uint16_t x, uint16_t y);
    lv_obj_t* createMeter(lv_obj_t* parent, uint16_t x, uint16_t y);
    lv_obj_t* createGauge(lv_obj_t* parent, uint16_t x, uint16_t y);

private:
    lv_obj_t* screen;
    lv_obj_t* keyboard;
    Arduino_H7_Video Display;
    Arduino_GigaDisplayTouch Touch;

    static void textarea_event_cb(lv_event_t * e);
};

#endif // GUIMAKER_H
