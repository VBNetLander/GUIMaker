#include "GUIMaker.h"

GUIMaker::GUIMaker() : Display(800, 480, GigaDisplayShield), Touch(), keyboard(NULL) {}

void GUIMaker::begin() {
    lv_init();

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
    keyboard = NULL;
}

lv_obj_t* GUIMaker::CreateScreen(uint16_t width, uint16_t height) {
    screen = lv_obj_create(NULL);
    lv_obj_set_size(screen, width, height);
    lv_scr_load(screen);
    return screen;
}

lv_obj_t* GUIMaker::CreateButton(lv_obj_t* parent, const char* label, uint16_t width, uint16_t height, lv_event_cb_t event_cb) {
    lv_obj_t* button = lv_btn_create(parent, NULL);
    lv_obj_set_size(button, width, height);
    lv_obj_add_event_cb(button, event_cb, LV_EVENT_CLICKED, NULL);

    lv_obj_t* lbl = lv_label_create(button, NULL);
    lv_label_set_text(lbl, label);
    lv_obj_center(lbl);

    return button;
}

lv_obj_t* GUIMaker::CreateLabel(lv_obj_t* parent, const char* text, uint16_t x, uint16_t y) {
    lv_obj_t* label = lv_label_create(parent, NULL);
    lv_label_set_text(label, text);
    lv_obj_set_pos(label, x, y);
    return label;
}

lv_obj_t* GUIMaker::CreateImage(lv_obj_t* parent, const void* src, uint16_t width, uint16_t height) {
    lv_obj_t* img = lv_img_create(parent, NULL);
    lv_img_set_src(img, src);
    lv_obj_set_size(img, width, height);
    lv_obj_center(img);
    return img;
}

lv_obj_t* GUIMaker::CreateLine(lv_obj_t* parent, const lv_point_t* points, uint16_t point_num, uint16_t x, uint16_t y) {
    lv_obj_t* line = lv_line_create(parent, NULL);
    lv_line_set_points(line, points, point_num);
    lv_obj_set_pos(line, x, y);
    return line;
}

lv_obj_t* GUIMaker::CreateArc(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* arc = lv_arc_create(parent, NULL);
    lv_obj_set_size(arc, width, height);
    lv_obj_set_pos(arc, x, y);
    return arc;
}

lv_obj_t* GUIMaker::CreateBar(lv_obj_t* parent, uint16_t width, uint16_t height, int32_t initial_value) {
    lv_obj_t* bar = lv_bar_create(parent, NULL);
    lv_obj_set_size(bar, width, height);
    lv_bar_set_value(bar, initial_value, LV_ANIM_OFF);
    lv_obj_center(bar);
    return bar;
}

lv_obj_t* GUIMaker::CreateSlider(lv_obj_t* parent, uint16_t width, uint16_t height, int32_t initial_value) {
    lv_obj_t* slider = lv_slider_create(parent, NULL);
    lv_obj_set_size(slider, width, height);
    lv_slider_set_value(slider, initial_value, LV_ANIM_OFF);
    lv_obj_center(slider);
    return slider;
}

lv_obj_t* GUIMaker::CreateSwitch(lv_obj_t* parent, uint16_t x, uint16_t y) {
    lv_obj_t* sw = lv_switch_create(parent, NULL);
    lv_obj_set_pos(sw, x, y);
    return sw;
}

lv_obj_t* GUIMaker::CreateLED(lv_obj_t* parent, uint16_t x, uint16_t y) {
    lv_obj_t* led = lv_led_create(parent, NULL);
    lv_obj_set_pos(led, x, y);
    return led;
}

lv_obj_t* GUIMaker::CreateCheckbox(lv_obj_t* parent, const char* label, bool checked, lv_style_t* style, lv_style_t* style_chk) {
    lv_obj_t* cb = lv_checkbox_create(parent, NULL);
    lv_checkbox_set_text(cb, label);
    if (checked) {
        lv_obj_add_state(cb, LV_STATE_CHECKED);
    }
    if (style != nullptr && style_chk != nullptr) {
        lv_obj_add_style(cb, style, LV_PART_INDICATOR);
        lv_obj_add_style(cb, style_chk, LV_PART_INDICATOR | LV_STATE_CHECKED);
    }
    return cb;
}

lv_obj_t* GUIMaker::CreateDropdown(lv_obj_t* parent, const char* options, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* dd = lv_dropdown_create(parent, NULL);
    lv_dropdown_set_options(dd, options);
    lv_obj_set_size(dd, width, height);
    lv_obj_set_pos(dd, x, y);
    return dd;
}

lv_obj_t* GUIMaker::CreateRoller(lv_obj_t* parent, const char* options, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* roller = lv_roller_create(parent, NULL);
    lv_roller_set_options(roller, options, LV_ROLLER_MODE_NORMAL);
    lv_obj_set_size(roller, width, height);
    lv_obj_set_pos(roller, x, y);
    return roller;
}

lv_obj_t* GUIMaker::CreateTextarea(lv_obj_t* parent, const char* placeholder, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* ta = lv_textarea_create(parent, NULL);
    lv_textarea_set_placeholder_text(ta, placeholder);
    lv_obj_set_size(ta, width, height);
    lv_obj_set_pos(ta, x, y);
    lv_obj_add_event_cb(ta, textarea_event_cb, LV_EVENT_FOCUSED, NULL);
    return ta;
}

lv_obj_t* GUIMaker::CreateKeyboard(lv_obj_t* parent) {
    if (!keyboard) {
        keyboard = lv_keyboard_create(parent, NULL);
        lv_keyboard_set_mode(keyboard, LV_KEYBOARD_MODE_TEXT_LOWER);
    }
    lv_obj_set_size(keyboard, LV_HOR_RES, LV_VER_RES / 2);
    lv_obj_align(keyboard, LV_ALIGN_BOTTOM_MID, 0, 0);
    return keyboard;
}

lv_obj_t* GUIMaker::CreateMessagebox(const char* title, const char* text, const char* buttons[], bool add_close_button) {
    lv_obj_t* mbox = lv_msgbox_create(NULL, title, text, buttons, add_close_button);
    lv_obj_center(mbox);
    return mbox;
}

lv_obj_t* GUIMaker::CreateTable(lv_obj_t* parent, uint16_t col_count, uint16_t row_count, uint16_t x, uint16_t y) {
    lv_obj_t* table = lv_table_create(parent, NULL);
    lv_table_set_col_cnt(table, col_count);
    lv_table_set_row_cnt(table, row_count);
    lv_obj_set_pos(table, x, y);
    return table;
}

lv_obj_t* GUIMaker::CreateChart(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* chart = lv_chart_create(parent, NULL);
    lv_obj_set_size(chart, width, height);
    lv_obj_set_pos(chart, x, y);
    return chart;
}

lv_obj_t* GUIMaker::CreateList(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* list = lv_list_create(parent, NULL);
    lv_obj_set_size(list, width, height);
    lv_obj_set_pos(list, x, y);
    return list;
}

lv_obj_t* GUIMaker::CreateTileview(lv_obj_t* parent, uint16_t x, uint16_t y) {
    lv_obj_t* tileview = lv_tileview_create(parent, NULL);
    lv_obj_set_pos(tileview, x, y);
    return tileview;
}

lv_obj_t* GUIMaker::CreateTabview(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* tabview = lv_tabview_create(parent, NULL);
    lv_obj_set_size(tabview, width, height);
    lv_obj_set_pos(tabview, x, y);
    return tabview;
}

lv_obj_t* GUIMaker::CreateCalendar(lv_obj_t* parent, uint16_t x, uint16_t y) {
    lv_obj_t* calendar = lv_calendar_create(parent, NULL);
    lv_obj_set_pos(calendar, x, y);
    return calendar;
}

lv_obj_t* GUIMaker::CreateSpinbox(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* spinbox = lv_spinbox_create(parent, NULL);
    lv_obj_set_size(spinbox, width, height);
    lv_obj_set_pos(spinbox, x, y);
    lv_obj_add_event_cb(spinbox, textarea_event_cb, LV_EVENT_FOCUSED, NULL);
    return spinbox;
}

lv_obj_t* GUIMaker::CreateColorPicker(lv_obj_t* parent, uint16_t width, uint16_t height, uint16_t x, uint16_t y) {
    lv_obj_t* cpicker = lv_cpicker_create(parent, NULL);
    lv_obj_set_size(cpicker, width, height);
    lv_obj_set_pos(cpicker, x, y);
    return cpicker;
}

lv_obj_t* GUIMaker::CreatePreloader(lv_obj_t* parent, uint16_t width, uint16_t height, uint32_t time, uint16_t x, uint16_t y) {
    lv_obj_t* preloader = lv_spinner_create(parent, NULL);
    lv_obj_set_size(preloader, width, height);
    lv_spinner_set_spin_time(preloader, time);
    lv_obj_set_pos(preloader, x, y);
    return preloader;
}

lv_obj_t* GUIMaker::CreateMeter(lv_obj_t* parent, uint16_t x, uint16_t y) {
    lv_obj_t* meter = lv_meter_create(parent, NULL);
    lv_obj_set_pos(meter, x, y);
    return meter;
}

lv_obj_t* GUIMaker::CreateGauge(lv_obj_t* parent, uint16_t x, uint16_t y) {
    lv_obj_t* gauge = lv_gauge_create(parent, NULL);
    lv_obj_set_pos(gauge, x, y);
    return gauge;
}

lv_obj_t* GUIMaker::CreateContainer(lv_obj_t* parent, lv_coord_t* col_dsc, lv_coord_t* row_dsc, uint16_t width, uint16_t height, lv_color_t bg_color) {
    lv_obj_t* cont = lv_obj_create(parent, NULL);
    lv_obj_set_grid_dsc_array(cont, col_dsc, row_dsc);
    lv_obj_set_size(cont, width, height);
    lv_obj_set_style_bg_color(cont, bg_color, LV_PART_MAIN);
    lv_obj_center(cont);
    return cont;
}

lv_obj_t* GUIMaker::CreateObject(lv_obj_t* parent, uint16_t col, uint16_t col_span, uint16_t row, uint16_t row_span) {
    lv_obj_t* obj = lv_obj_create(parent, NULL);
    lv_obj_set_grid_cell(obj, LV_GRID_ALIGN_STRETCH, col, col_span,
                         LV_GRID_ALIGN_STRETCH, row, row_span);
    return obj;
}

void GUIMaker::SetFlexFlow(lv_obj_t* obj, lv_flex_flow_t flow) {
    lv_obj_set_flex_flow(obj, flow);
}

void GUIMaker::textarea_event_cb(lv_event_t * e) {
    lv_obj_t* ta = lv_event_get_target(e);
    lv_keyboard_set_textarea(keyboard, ta);
    lv_obj_clear_flag(keyboard, LV_OBJ_FLAG_HIDDEN);
}
