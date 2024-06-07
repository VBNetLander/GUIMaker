#include "GUIMaker.h"

GUIMaker::GUIMaker() : Display(800, 480, GigaDisplayShield), Touch() {}

void GUIMaker::begin() {
    lv_init();

    // Inizializzazione del display
    Display.begin();
    Touch.begin();

    static lv_disp_draw_buf_t draw_buf;
    static lv_color_t buf[LV_HOR_RES_MAX * 10];
    lv_disp_draw_buf_init(&draw_buf, buf, NULL, LV_HOR_RES_MAX * 10);

    static lv_disp_drv_t disp_drv;
    lv_disp_drv_init(&disp_drv);
    disp_drv.flush_cb = [](lv_disp_drv_t * disp_drv, const lv_area_t * area, lv_color_t * color_p) {
        Display.flush(disp_drv, area, color_p);
    };
    disp_drv.draw_buf = &draw_buf;
    disp_drv.hor_res = 800;
    disp_drv.ver_res = 480;
    lv_disp_drv_register(&disp_drv);

    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = [](lv_indev_drv_t * indev_drv, lv_indev_data_t * data) {
        Touch.read(indev_drv, data);
    };
    lv_indev_drv_register(&indev_drv);
}

void GUIMaker::update() {
    lv_task_handler();
}

void GUIMaker::clear() {
    lv_obj_clean(lv_scr_act());
}

lv_obj_t* GUIMaker::createScreen(uint16_t width, uint16_t height) {
    screen = lv_obj_create(NULL);
    lv_obj_set_size(screen, width, height);
    lv_scr_load(screen);
    return screen;
}

lv_obj_t* GUIMaker::createButton(lv_obj_t* parent, const char* label, uint16_t width, uint16_t height, void (*event_cb)(void)) {
    lv_obj_t* button = lv_btn_create(parent, NULL);
    lv_obj_set_size(button, width, height);
    lv_obj_set_event_cb(button, [](lv_obj_t* btn, lv_event_t event) {
        if (event == LV_EVENT_CLICKED) {
            event_cb();
        }
    });

    lv_obj_t* lbl = lv_label_create(button, NULL);
    lv_label_set_text(lbl, label);
    lv_obj_center(lbl);

    return button;
}

lv_obj_t* GUIMaker::createLabel(lv_obj_t* parent, const char* text, uint16_t x, uint16_t y) {
    lv_obj_t* label = lv_label_create(parent, NULL);
    lv_label_set_text(label, text);
    lv_obj_set_pos(label, x, y);
    return label;
}

lv_obj_t* GUIMaker::createBar(lv_obj_t* parent, uint16_t width, uint16_t height, int32_t initial_value, uint16_t x, uint16_t y) {
    lv_obj_t* bar = lv_bar_create(parent, NULL);
    lv_obj_set_size(bar, width, height);
    lv_obj_set_pos(bar, x, y);
    lv_bar_set_value(bar, initial_value, LV_ANIM_OFF);
    return bar;
}

lv_obj_t* GUIMaker::createSlider(lv_obj_t* parent, uint16_t width, uint16_t height, int32_t initial_value, uint16_t x, uint16_t y) {
    lv_obj_t* slider = lv_slider_create(parent, NULL);
    lv_obj_set_size(slider, width, height);
    lv_obj_set_pos(slider, x, y);
    lv_slider_set_value(slider, initial_value, LV_ANIM_OFF);
    return slider;
}

lv_obj_t* GUIMaker::createChart(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* chart = lv_chart_create(parent, NULL);
    lv_obj_set_size(chart, width, height);
    lv_obj_set_pos(chart, x, y);
    return chart;
}

lv_obj_t* GUIMaker::createTable(lv_obj_t* parent, uint16_t col_count, uint16_t row_count, uint16_t x, uint16_t y) {
    lv_obj_t* table = lv_table_create(parent, NULL);
    lv_table_set_col_cnt(table, col_count);
    lv_table_set_row_cnt(table, row_count);
    lv_obj_set_pos(table, x, y);
    return table;
}

lv_obj_t* GUIMaker::createCheckbox(lv_obj_t* parent, const char* label, uint16_t x, uint16_t y) {
    lv_obj_t* checkbox = lv_checkbox_create(parent, NULL);
    lv_checkbox_set_text(checkbox, label);
    lv_obj_set_pos(checkbox, x, y);
    return checkbox;
}

lv_obj_t* GUIMaker::createDropdown(lv_obj_t* parent, const char* options, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* dropdown = lv_dropdown_create(parent, NULL);
    lv_dropdown_set_options(dropdown, options);
    lv_obj_set_size(dropdown, width, height);
    lv_obj_set_pos(dropdown, x, y);
    return dropdown;
}

lv_obj_t* GUIMaker::createSwitch(lv_obj_t* parent, uint16_t x, uint16_t y) {
    lv_obj_t* sw = lv_switch_create(parent, NULL);
    lv_obj_set_pos(sw, x, y);
    return sw;
}

lv_obj_t* GUIMaker::createTextarea(lv_obj_t* parent, const char* placeholder, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* textarea = lv_textarea_create(parent, NULL);
    lv_textarea_set_placeholder_text(textarea, placeholder);
    lv_obj_set_size(textarea, width, height);
    lv_obj_set_pos(textarea, x, y);
    return textarea;
}

lv_obj_t* GUIMaker::createKeyboard(lv_obj_t* parent) {
    lv_obj_t* keyboard = lv_keyboard_create(parent, NULL);
    return keyboard;
}

lv_obj_t* GUIMaker::createMessagebox(const char* title, const char* text, const char* buttons[], bool add_close_button) {
    lv_obj_t* msgbox = lv_msgbox_create(NULL, title, text, buttons, add_close_button);
    lv_obj_center(msgbox);
    return msgbox;
}

lv_obj_t* GUIMaker::createArc(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* arc = lv_arc_create(parent, NULL);
    lv_obj_set_size(arc, width, height);
    lv_obj_set_pos(arc, x, y);
    return arc;
}

lv_obj_t* GUIMaker::createSpinner(lv_obj_t* parent, uint16_t width, uint16_t height, uint32_t time, uint16_t x, uint16_t y) {
    lv_obj_t* spinner = lv_spinner_create(parent, time, 100);
    lv_obj_set_size(spinner, width, height);
    lv_obj_set_pos(spinner, x, y);
    return spinner;
}

lv_obj_t* GUIMaker::createLed(lv_obj_t* parent, uint16_t x, uint16_t y) {
    lv_obj_t* led = lv_led_create(parent, NULL);
    lv_obj_set_pos(led, x, y);
    return led;
}
