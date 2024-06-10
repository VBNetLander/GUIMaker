#ifndef GUIMAKER_H
#define GUIMAKER_H

#include <lvgl.h>
#include "Arduino_H7_Video.h"
#include "Arduino_GigaDisplayTouch.h"

// Classe principale per la gestione della GUI
class GUIMaker {
public:
    GUIMaker();
    void begin();
    void update();
    void clear();

    // Metodi di creazione dei widget
    lv_obj_t* CreateScreen(uint16_t width, uint16_t height);
    lv_obj_t* CreateButton(lv_obj_t* parent, const char* label, uint16_t width, uint16_t height, lv_event_cb_t event_cb);
    lv_obj_t* CreateLabel(lv_obj_t* parent, const char* text, uint16_t x, uint16_t y);
    lv_obj_t* CreateImage(lv_obj_t* parent, const void* src, uint16_t width, uint16_t height);
    lv_obj_t* CreateLine(lv_obj_t* parent, const lv_point_t* points, uint16_t point_num, uint16_t x, uint16_t y);
    lv_obj_t* CreateArc(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* CreateBar(lv_obj_t* parent, uint16_t width, uint16_t height, int32_t initial_value);
    lv_obj_t* CreateSlider(lv_obj_t* parent, uint16_t width, uint16_t height, int32_t initial_value);
    lv_obj_t* CreateSwitch(lv_obj_t* parent, uint16_t x, uint16_t y);
    lv_obj_t* CreateLED(lv_obj_t* parent, uint16_t x, uint16_t y);
    lv_obj_t* CreateCheckbox(lv_obj_t* parent, const char* label, bool checked);
    lv_obj_t* CreateDropdown(lv_obj_t* parent, const char* options, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* CreateRoller(lv_obj_t* parent, const char* options, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* CreateTextarea(lv_obj_t* parent, const char* placeholder, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* CreateKeyboard(lv_obj_t* parent);
    lv_obj_t* CreateMessagebox(const char* title, const char* text, const char* buttons[], bool add_close_button);
    lv_obj_t* CreateTable(lv_obj_t* parent, uint16_t col_count, uint16_t row_count, uint16_t x, uint16_t y);
    lv_obj_t* CreateChart(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* CreateList(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* CreateTileview(lv_obj_t* parent, uint16_t x, uint16_t y);
    lv_obj_t* CreateTabview(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* CreateCalendar(lv_obj_t* parent, uint16_t x, uint16_t y);
    lv_obj_t* CreateSpinbox(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* CreateColorPicker(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y);
    lv_obj_t* CreatePreloader(lv_obj_t* parent, uint16_t width, uint16_t height, uint32_t time, uint16_t x, uint16_t y);
    lv_obj_t* CreateMeter(lv_obj_t* parent, uint16_t x, uint16_t y);
    lv_obj_t* CreateGauge(lv_obj_t* parent, uint16_t x, uint16_t y);
    lv_obj_t* CreateContainer(lv_obj_t* parent, const uint16_t* col_dsc, size_t col_cnt, const uint16_t* row_dsc, size_t row_cnt, uint16_t width, uint16_t height, uint32_t bg_color);
    lv_obj_t* CreateGrid(lv_obj_t* parent, const uint16_t* col_dsc, size_t col_cnt, const uint16_t* row_dsc, size_t row_cnt, uint16_t width, uint16_t height);

    void SetFlexFlow(lv_obj_t* obj, lv_flex_flow_t flow);

private:
    lv_obj_t* screen;
    lv_obj_t* keyboard;
    Arduino_H7_Video Display;
    Arduino_GigaDisplayTouch Touch;

    static void textarea_event_cb(lv_event_t * e);
};

#endif // GUIMAKER_H
