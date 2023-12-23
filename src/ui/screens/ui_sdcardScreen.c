#include "../ui.h"

void ui_sdcardScreen_screen_init(void)
{

    ui_sdcardScreen = lv_obj_create(NULL);
    lv_obj_clear_flag(ui_sdcardScreen, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM); /// Flags
    lv_obj_set_scrollbar_mode(ui_sdcardScreen, LV_SCROLLBAR_MODE_OFF);
    lv_obj_set_flex_flow(ui_sdcardScreen, LV_FLEX_FLOW_COLUMN);
    lv_obj_set_flex_align(ui_sdcardScreen, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
    lv_obj_set_style_pad_left(ui_sdcardScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_sdcardScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_sdcardScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_sdcardScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_row(ui_sdcardScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_column(ui_sdcardScreen, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_t *ui_sdcardScreenCaption;
    ui_sdcardScreenCaption = lv_label_create(ui_sdcardScreen);
    lv_obj_set_height(ui_sdcardScreenCaption, 50);
    lv_obj_set_width(ui_sdcardScreenCaption, lv_pct(100));
    lv_label_set_text(ui_sdcardScreenCaption, "SDCard: ./model");
    lv_obj_set_style_text_align(ui_sdcardScreenCaption, LV_TEXT_ALIGN_CENTER, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_font(ui_sdcardScreenCaption, &lv_font_montserrat_28, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_left(ui_sdcardScreenCaption, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_right(ui_sdcardScreenCaption, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_top(ui_sdcardScreenCaption, 8, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_pad_bottom(ui_sdcardScreenCaption, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    // lv_obj_t *ui_sdcardScreenRoller;
    ui_sdcardScreenRoller = lv_roller_create(ui_sdcardScreen);

    lv_roller_set_options(ui_sdcardScreenRoller, LV_SYMBOL_CHARGE " Connecting...", LV_ROLLER_MODE_NORMAL);
    lv_obj_set_width(ui_sdcardScreenRoller, lv_pct(100));
    lv_obj_set_flex_grow(ui_sdcardScreenRoller, 5);
    lv_obj_set_style_text_align(ui_sdcardScreenRoller, LV_TEXT_ALIGN_LEFT, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_x(ui_sdcardScreenRoller, 344);
    lv_obj_set_y(ui_sdcardScreenRoller, 193);
    lv_obj_set_style_text_font(ui_sdcardScreenRoller, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_radius(ui_sdcardScreenRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_sdcardScreenRoller, lv_color_hex(0x444444), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_sdcardScreenRoller, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_width(ui_sdcardScreenRoller, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_sdcardScreenRoller, lv_color_hex(0x777777), LV_PART_SELECTED | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_sdcardScreenRoller, 255, LV_PART_SELECTED | LV_STATE_DEFAULT);

    // ui_sdcardScreenSubmitButton = lv_obj_create(ui_sdcardScreen);
    // lv_obj_set_width(ui_sdcardScreenSubmitButton, 48);
    // lv_obj_set_height(ui_sdcardScreenSubmitButton, 48);
    // lv_obj_set_x(ui_sdcardScreenSubmitButton, -8);
    // lv_obj_set_y(ui_sdcardScreenSubmitButton, -8);
    // lv_obj_set_align(ui_sdcardScreenSubmitButton, LV_ALIGN_BOTTOM_RIGHT);
    // lv_obj_set_flex_flow(ui_sdcardScreenSubmitButton, LV_FLEX_FLOW_ROW);
    // lv_obj_set_flex_align(ui_sdcardScreenSubmitButton, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
    // lv_obj_add_flag(ui_sdcardScreenSubmitButton, LV_OBJ_FLAG_FLOATING);                                                                                                                                                                                                       /// Flags
    // lv_obj_clear_flag(ui_sdcardScreenSubmitButton, LV_OBJ_FLAG_PRESS_LOCK | LV_OBJ_FLAG_CLICK_FOCUSABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE | LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM | LV_OBJ_FLAG_SCROLL_CHAIN); /// Flags
    // lv_obj_set_scrollbar_mode(ui_sdcardScreenSubmitButton, LV_SCROLLBAR_MODE_OFF);
    // lv_obj_set_style_bg_color(ui_sdcardScreenSubmitButton, lv_color_hex(0x22AF00), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_opa(ui_sdcardScreenSubmitButton, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_border_width(ui_sdcardScreenSubmitButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_left(ui_sdcardScreenSubmitButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_right(ui_sdcardScreenSubmitButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_top(ui_sdcardScreenSubmitButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_pad_bottom(ui_sdcardScreenSubmitButton, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_bg_color(ui_sdcardScreenSubmitButton, lv_color_hex(0x2AFF00), LV_PART_MAIN | LV_STATE_PRESSED);
    // lv_obj_set_style_bg_opa(ui_sdcardScreenSubmitButton, 255, LV_PART_MAIN | LV_STATE_PRESSED);

    // lv_obj_add_flag(ui_sdcardScreenSubmitButton, LV_OBJ_FLAG_HIDDEN);

    // lv_obj_t *ui_sdcardScreenSubmitIcon;
    // ui_sdcardScreenSubmitIcon = lv_label_create(ui_sdcardScreenSubmitButton);
    // lv_obj_set_width(ui_sdcardScreenSubmitIcon, LV_SIZE_CONTENT);  /// 1
    // lv_obj_set_height(ui_sdcardScreenSubmitIcon, LV_SIZE_CONTENT); /// 1
    // lv_label_set_text(ui_sdcardScreenSubmitIcon, "q");
    // lv_obj_set_style_text_color(ui_sdcardScreenSubmitIcon, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_opa(ui_sdcardScreenSubmitIcon, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    // lv_obj_set_style_text_font(ui_sdcardScreenSubmitIcon, &ui_font_xlcd, LV_PART_MAIN | LV_STATE_DEFAULT);

}
