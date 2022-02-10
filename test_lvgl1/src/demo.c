#include <Arduino.h>
#include "demo.h"
extern lv_indev_t *my_indev;
#if LV_USE_DEMO_TEST
void  demo_test_create(){
    lv_group_t * g = lv_group_create();
    lv_group_set_default(g);
    lv_indev_set_group(my_indev,g); 
    
    lv_obj_t *label=lv_label_create(lv_scr_act());
    lv_label_set_text(label,"test");
    lv_obj_set_pos(label,100,100);
    lv_group_add_obj(g,label);

    label=lv_label_create(lv_scr_act());
    lv_label_set_text(label,"test1");
    lv_obj_set_pos(label,100,120);
    lv_group_add_obj(g,label);

    lv_obj_t *text1=lv_textarea_create(lv_scr_act());
    lv_textarea_set_text(text1,LV_SYMBOL_GPS " test2");
    lv_textarea_set_one_line(text1,true);
    lv_textarea_set_cursor_click_pos(text1,false);
    lv_obj_set_pos(text1,100,150);
    lv_group_add_obj(g,text1);

    text1=lv_textarea_create(lv_scr_act());
    lv_textarea_set_text(text1,"test3");
    lv_textarea_set_one_line(text1,true);
    lv_textarea_set_cursor_click_pos(text1,false);
    lv_obj_set_pos(text1,100,180);
    lv_group_add_obj(g,text1);

}
#endif
#if LV_USE_DEMO6
static void start_btn_event(lv_event_t *e)
{
    lv_obj_t *menu=lv_obj_get_parent(lv_event_get_target(e));
    lv_obj_t *side=lv_event_get_user_data(e);
    lv_menu_set_page(menu, NULL);
    // lv_menu_clear_history(menu);
    lv_menu_set_sidebar_page(menu,side);
}
static void anim_width_cb(void *var,int32_t v)
{
    lv_obj_set_width(var,v);
}
void  demo6_create(){
    lv_group_t * g = lv_group_create();
    lv_group_set_default(g);
    lv_indev_set_group(my_indev,g); 

    lv_obj_t *menu=lv_menu_create(lv_scr_act());
    lv_color_t bg_color = lv_obj_get_style_bg_color(menu, 0);
    if(lv_color_brightness(bg_color) > 127) {
        lv_obj_set_style_bg_color(menu, lv_color_darken(lv_obj_get_style_bg_color(menu, 0), 10), 0);
    }else{
        lv_obj_set_style_bg_color(menu, lv_color_darken(lv_obj_get_style_bg_color(menu, 0), 50), 0);
    }
    lv_menu_set_mode_root_back_btn(menu,LV_MENU_ROOT_BACK_BTN_ENABLED);
    lv_obj_set_size(menu, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
    lv_obj_center(menu);

   static  lv_style_t btn_focuestyle;
    lv_style_init(&btn_focuestyle);
    lv_style_set_radius(&btn_focuestyle, 3);
    lv_style_set_bg_opa(&btn_focuestyle, LV_OPA_100);
    lv_style_set_bg_color(&btn_focuestyle, lv_palette_lighten(LV_PALETTE_LIGHT_BLUE,4));
    lv_style_set_outline_width(&btn_focuestyle, 1);
    lv_style_set_outline_color(&btn_focuestyle, lv_palette_lighten(LV_PALETTE_LIGHT_BLUE,4));
    lv_style_set_pad_all(&btn_focuestyle, 0);
    lv_style_set_text_color(&btn_focuestyle, lv_palette_darken(LV_PALETTE_LIGHT_BLUE,1));

    
   static  lv_style_t btn_pressed;
    lv_style_init(&btn_pressed);
    lv_style_set_radius(&btn_pressed, 3);
    lv_style_set_bg_opa(&btn_pressed, LV_OPA_100);
    lv_style_set_bg_color(&btn_pressed, lv_palette_lighten(LV_PALETTE_GREY,3));
    lv_style_set_outline_width(&btn_pressed, 1);
    lv_style_set_outline_color(&btn_pressed, lv_palette_lighten(LV_PALETTE_GREY,3));
    lv_style_set_pad_all(&btn_focuestyle, 0);
    lv_style_set_text_color(&btn_pressed, lv_color_hex(0x0));


    lv_obj_t *main_page=lv_menu_page_create(menu,NULL);
    lv_obj_set_style_pad_hor(main_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
        lv_obj_t *section1=lv_menu_section_create(main_page);
            lv_obj_t *con=lv_menu_cont_create(section1);
            lv_obj_set_style_pad_all(con, 0,0);
                lv_obj_t *btn_l=lv_btn_create(con);  
                lv_obj_remove_style_all(btn_l);
                lv_obj_add_style(btn_l,&btn_focuestyle,LV_STATE_FOCUSED);
                lv_obj_add_style(btn_l,&btn_pressed,LV_STATE_PRESSED);
                lv_obj_set_width(btn_l,lv_obj_get_style_width(section1,0));
                lv_group_add_obj(g,btn_l);    
                    con=lv_menu_cont_create(btn_l);
                        lv_obj_t *img =lv_img_create(con);
                        lv_img_set_src(img,LV_SYMBOL_HOME);   
                        lv_obj_set_style_pad_right(img,1,1);
                        lv_obj_t *label = lv_label_create(con);
                        lv_label_set_text(label, " Home");
                        lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
                        lv_obj_set_flex_grow(label, 1);

            con=lv_menu_cont_create(section1);
            lv_obj_set_style_pad_all(con, 0,0);
                btn_l=lv_btn_create(con);  
                lv_obj_remove_style_all(btn_l);
                lv_obj_add_style(btn_l,&btn_focuestyle,LV_STATE_FOCUSED);
                lv_obj_add_style(btn_l,&btn_pressed,LV_STATE_PRESSED);
                lv_obj_set_width(btn_l,lv_obj_get_style_width(section1,0));
                lv_group_add_obj(g,btn_l);  
                    con=lv_menu_cont_create(btn_l);
                        img =lv_img_create(con);
                        lv_img_set_src(img,LV_SYMBOL_WIFI);
                        label = lv_label_create(con);
                        lv_label_set_text(label, "WIFI");
                        lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
                        lv_obj_set_flex_grow(label, 1);

            con=lv_menu_cont_create(section1);
            lv_obj_set_style_pad_all(con, 0,0);
                btn_l=lv_btn_create(con);  
                lv_obj_remove_style_all(btn_l);
                lv_obj_add_style(btn_l,&btn_focuestyle,LV_STATE_FOCUSED);
                lv_obj_add_style(btn_l,&btn_pressed,LV_STATE_PRESSED);
                lv_obj_set_width(btn_l,lv_obj_get_style_width(section1,0));
                lv_group_add_obj(g,btn_l);  
                    con=lv_menu_cont_create(btn_l);
                        img =lv_img_create(con);
                        lv_img_set_src(img,LV_SYMBOL_GPS);
                        label = lv_label_create(con);
                        lv_label_set_text(label, "GPS");
                        lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
                        lv_obj_set_flex_grow(label, 1);

        con=lv_menu_cont_create(main_page);
            label = lv_label_create(con);
            lv_label_set_text(label, "Others");
            lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
            lv_obj_set_flex_grow(label, 1);

        lv_obj_t *section2=lv_menu_section_create(main_page);
            con=lv_menu_cont_create(section2);
            lv_obj_set_style_pad_all(con, 0,0);
                btn_l=lv_btn_create(con);  
                lv_obj_remove_style_all(btn_l);
                lv_obj_add_style(btn_l,&btn_focuestyle,LV_STATE_FOCUSED);
                lv_obj_add_style(btn_l,&btn_pressed,LV_STATE_PRESSED);
                lv_obj_set_width(btn_l,lv_obj_get_style_width(section2,0));
                lv_group_add_obj(g,btn_l);  
                    con=lv_menu_cont_create(btn_l);
                        img =lv_img_create(con);
                        lv_img_set_src(img,LV_SYMBOL_BLUETOOTH);
                        label = lv_label_create(con);
                        lv_label_set_text(label, "BLUETOOTH");
                        lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
                        lv_obj_set_flex_grow(label, 1);

            con=lv_menu_cont_create(section2);
            lv_obj_set_style_pad_all(con, 0,0);
                btn_l=lv_btn_create(con);  
                lv_obj_remove_style_all(btn_l);
                lv_obj_add_style(btn_l,&btn_focuestyle,LV_STATE_FOCUSED);
                lv_obj_add_style(btn_l,&btn_pressed,LV_STATE_PRESSED);
                lv_obj_set_width(btn_l,lv_obj_get_style_width(section2,0));
                lv_group_add_obj(g,btn_l);  
                    con=lv_menu_cont_create(btn_l);
                        img =lv_img_create(con);
                        lv_img_set_src(img,LV_SYMBOL_KEYBOARD);
                        label = lv_label_create(con);
                        lv_label_set_text(label, "KEYBOARD");
                        lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
                        lv_obj_set_flex_grow(label, 1);

    lv_menu_set_sidebar_page(menu,main_page);
    lv_obj_set_width(((lv_menu_t *)menu)->sidebar_header_back_btn,lv_obj_get_style_width(section1,0));
    lv_obj_t *btn_back_label=lv_label_create(((lv_menu_t *)menu)->sidebar_header_back_btn);
    lv_label_set_long_mode(btn_back_label, LV_LABEL_LONG_SCROLL_CIRCULAR);
    lv_obj_set_flex_grow(btn_back_label, 1);
    lv_label_set_text(btn_back_label,"Backcccccc"); 

    
    
    // lv_obj_t *start_btn=lv_btn_create(menu);
    // label=lv_label_create(start_btn);
    // lv_label_set_text(label,"start");
    // lv_obj_add_event_cb(start_btn,start_btn_event,LV_EVENT_CLICKED,main_page);
    

    LV_LOG_USER("starting demo\n");
    
    lv_anim_t a;
    lv_anim_init(&a);
    lv_anim_set_var(&a, ((lv_menu_t *)menu)->sidebar);

    lv_anim_set_values(&a, 0, 90);
    LV_LOG_USER("width:%d,%d",(int)lv_obj_get_width(lv_menu_get_main_header(menu))
                            ,lv_obj_get_style_width(((lv_menu_t *)menu)->sidebar,0));
    lv_anim_set_time(&a, 300);
    lv_anim_set_exec_cb(&a, anim_width_cb);
    lv_anim_set_path_cb(&a, lv_anim_path_linear);
    lv_anim_start(&a);
}
#endif
#if LV_USE_DEMO5

enum {
    LV_MENU_ITEM_BUILDER_VARIANT_1,
    LV_MENU_ITEM_BUILDER_VARIANT_2
};
typedef uint8_t lv_menu_builder_variant_t;

static void back_event_handler(lv_event_t * e);
static void switch_handler(lv_event_t * e);
lv_obj_t * root_page;
static lv_obj_t * create_text(lv_obj_t * parent, const char * icon, const char * txt,
                                        lv_menu_builder_variant_t builder_variant);
static lv_obj_t * create_slider(lv_obj_t * parent,
                                   const char * icon, const char * txt, int32_t min, int32_t max, int32_t val);
static lv_obj_t * create_switch(lv_obj_t * parent,
                                   const char * icon, const char * txt, bool chk);
lv_group_t * g;
void demo5_create(void)
{
     g = lv_group_create();
    lv_group_set_default(g);
    lv_indev_set_group(my_indev,g); 

    lv_obj_t * menu = lv_menu_create(lv_scr_act());
    
    lv_color_t bg_color = lv_obj_get_style_bg_color(menu, 0);
    if(lv_color_brightness(bg_color) > 127) {
        lv_obj_set_style_bg_color(menu, lv_color_darken(lv_obj_get_style_bg_color(menu, 0), 10), 0);
    }else{
        lv_obj_set_style_bg_color(menu, lv_color_darken(lv_obj_get_style_bg_color(menu, 0), 50), 0);
    }
    lv_menu_set_mode_root_back_btn(menu, LV_MENU_ROOT_BACK_BTN_ENABLED);
    lv_obj_add_event_cb(menu, back_event_handler, LV_EVENT_CLICKED, menu);
    lv_obj_set_size(menu, lv_disp_get_hor_res(NULL), lv_disp_get_ver_res(NULL));
    lv_obj_center(menu);

    lv_obj_t * cont;
    lv_obj_t * section;

    /*Create sub pages*/
    lv_obj_t * sub_mechanics_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(sub_mechanics_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(sub_mechanics_page);
    section = lv_menu_section_create(sub_mechanics_page);
    create_slider(section, LV_SYMBOL_SETTINGS, "Velocity", 0, 150, 120);
    create_slider(section, LV_SYMBOL_SETTINGS, "Acceleration", 0, 150, 50);
    create_slider(section, LV_SYMBOL_SETTINGS, "Weight limit", 0, 150, 80);

    lv_obj_t * sub_sound_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(sub_sound_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(sub_sound_page);
    section = lv_menu_section_create(sub_sound_page);
    create_switch(section, LV_SYMBOL_AUDIO, "Sound", false);

    lv_obj_t * sub_display_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(sub_display_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(sub_display_page);
    section = lv_menu_section_create(sub_display_page);
    create_slider(section, LV_SYMBOL_SETTINGS, "Brightness", 0, 150, 100);

    lv_obj_t * sub_software_info_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(sub_software_info_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    section = lv_menu_section_create(sub_software_info_page);
    create_text(section, NULL, "Version 1.0", LV_MENU_ITEM_BUILDER_VARIANT_1);

    lv_obj_t * sub_legal_info_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(sub_legal_info_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    section = lv_menu_section_create(sub_legal_info_page);
    for(uint32_t i=0; i<15; i++){
        create_text(section, NULL, "This is a long long long long long long long long long text, if it is long enough it may scroll.", LV_MENU_ITEM_BUILDER_VARIANT_1);
    }

    lv_obj_t * sub_about_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(sub_about_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(sub_about_page);
    section = lv_menu_section_create(sub_about_page);
    cont = create_text(section, NULL, "Software information", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, sub_software_info_page);
    cont = create_text(section, NULL, "Legal information", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, sub_legal_info_page);

    lv_obj_t * sub_menu_mode_page = lv_menu_page_create(menu, NULL);
    lv_obj_set_style_pad_hor(sub_menu_mode_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);
    lv_menu_separator_create(sub_menu_mode_page);
    section = lv_menu_section_create(sub_menu_mode_page);
    cont = create_switch(section, LV_SYMBOL_AUDIO, "Sidebar enable", true);
    lv_obj_add_event_cb(lv_obj_get_child(cont, 2), switch_handler, LV_EVENT_VALUE_CHANGED, menu);
    lv_group_add_obj(g,cont);

    /*Create a root page*/
    root_page = lv_menu_page_create(menu, "Settings");
    lv_obj_set_style_pad_hor(root_page, lv_obj_get_style_pad_left(lv_menu_get_main_header(menu), 0), 0);

    section = lv_menu_section_create(root_page);
    cont = create_text(section, LV_SYMBOL_SETTINGS, "Mechanics", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, sub_mechanics_page);
    lv_group_add_obj(g,cont);

    cont = create_text(section, LV_SYMBOL_AUDIO, "Sound", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, sub_sound_page);
    lv_group_add_obj(g,cont);
    
    cont = create_text(section, LV_SYMBOL_SETTINGS, "Display", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, sub_display_page);
    lv_group_add_obj(g,cont);
    
    create_text(root_page, NULL, "Others", LV_MENU_ITEM_BUILDER_VARIANT_1);
    
    section = lv_menu_section_create(root_page);
    cont = create_text(section, NULL, "About", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, sub_about_page);
        lv_group_add_obj(g,cont);

    cont = create_text(section, LV_SYMBOL_SETTINGS, "Menu mode", LV_MENU_ITEM_BUILDER_VARIANT_1);
    lv_menu_set_load_page_event(menu, cont, sub_menu_mode_page);
    lv_group_add_obj(g,cont);

    lv_menu_set_sidebar_page(menu, root_page);

    // lv_event_send(lv_obj_get_child(lv_obj_get_child(lv_menu_get_cur_sidebar_page(menu), 0), 0), LV_EVENT_CLICKED, NULL);
}

static void back_event_handler(lv_event_t * e)
{
    lv_obj_t * obj = lv_event_get_target(e);
    lv_obj_t * menu = lv_event_get_user_data(e);

    if(lv_menu_back_btn_is_root(menu, obj)) {
        lv_obj_t * mbox1 = lv_msgbox_create(NULL, "Hello", "Root back btn click.", NULL, true);
        lv_obj_center(mbox1);
    }
}

static void switch_handler(lv_event_t * e)
{
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * menu = lv_event_get_user_data(e);
    lv_obj_t * obj = lv_event_get_target(e);
    if(code == LV_EVENT_VALUE_CHANGED) {
        if(lv_obj_has_state(obj, LV_STATE_CHECKED)) {
            lv_menu_set_page(menu, NULL);
            lv_menu_set_sidebar_page(menu, root_page);
            lv_event_send(lv_obj_get_child(lv_obj_get_child(lv_menu_get_cur_sidebar_page(menu), 0), 0), LV_EVENT_CLICKED, NULL);
        }else {
            lv_menu_set_sidebar_page(menu, NULL);
            lv_menu_clear_history(menu); /* Clear history because we will be showing the root page later */
            lv_menu_set_page(menu, root_page);
        }
    }
}

static lv_obj_t * create_text(lv_obj_t * parent, const char * icon, const char * txt,
                                        lv_menu_builder_variant_t builder_variant)
{
    lv_obj_t * obj = lv_menu_cont_create(parent);

    lv_obj_t * img = NULL;
    lv_obj_t * label = NULL;

    if(icon) {
        img = lv_img_create(obj);
        lv_img_set_src(img, icon);
    }

    if(txt) {
        label = lv_label_create(obj);
        lv_label_set_text(label, txt);
        lv_label_set_long_mode(label, LV_LABEL_LONG_SCROLL_CIRCULAR);
        lv_obj_set_flex_grow(label, 1);
    }

    if(builder_variant == LV_MENU_ITEM_BUILDER_VARIANT_2 && icon && txt) {
        lv_obj_add_flag(img, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
        lv_obj_swap(img, label);
    }

    return obj;
}

static lv_obj_t * create_slider(lv_obj_t * parent, const char * icon, const char * txt, int32_t min, int32_t max, int32_t val)
{
    lv_obj_t * obj = create_text(parent, icon, txt, LV_MENU_ITEM_BUILDER_VARIANT_2);

    lv_obj_t * slider = lv_slider_create(obj);
    lv_obj_set_flex_grow(slider, 1);
    lv_slider_set_range(slider, min, max);
    lv_slider_set_value(slider, val, LV_ANIM_OFF);

    if(icon == NULL) {
        lv_obj_add_flag(slider, LV_OBJ_FLAG_FLEX_IN_NEW_TRACK);
    }

    return obj;
}

static lv_obj_t * create_switch(lv_obj_t * parent, const char * icon, const char * txt, bool chk)
{
    lv_obj_t * obj = create_text(parent, icon, txt, LV_MENU_ITEM_BUILDER_VARIANT_1);

    lv_obj_t * sw = lv_switch_create(obj);
    lv_obj_add_state(sw, chk ? LV_STATE_CHECKED : 0);

    return obj;
}

#endif 
#if LV_USE_DEMO4
static void calendar_event_handler(lv_event_t * e){
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_current_target(e);

    if(code == LV_EVENT_VALUE_CHANGED) {
        lv_calendar_date_t date;
        if(lv_calendar_get_pressed_date(obj, &date)) {
            LV_LOG_USER("Clicked date: %02d.%02d.%d", date.day, date.month, date.year);
            lv_group_focus_obj(obj);
        }
    }
}
void demo4_create(){

    lv_group_t * g = lv_group_create();
    lv_group_set_default(g);
    lv_indev_set_group(my_indev,g); 
    
    lv_obj_t *calendar=lv_calendar_create(lv_scr_act());
    lv_obj_set_size(calendar, 320, 185);
    lv_obj_set_pos(calendar,0,0);
    // lv_obj_align(calendar, LV_ALIGN_CENTER, 0, 0);
    lv_obj_add_event_cb(calendar, calendar_event_handler, LV_EVENT_ALL, NULL);

    lv_calendar_set_today_date(calendar, 2021, 02, 23);
    lv_calendar_set_showed_date(calendar, 2021, 02);

    /*Highlight a few days*/
    static lv_calendar_date_t highlighted_days[3];       /*Only its pointer will be saved so should be static*/
    highlighted_days[0].year = 2021;
    highlighted_days[0].month = 02;
    highlighted_days[0].day = 6;

    highlighted_days[1].year = 2021;
    highlighted_days[1].month = 02;
    highlighted_days[1].day = 11;

    highlighted_days[2].year = 2022;
    highlighted_days[2].month = 02;
    highlighted_days[2].day = 22;

    lv_calendar_set_highlighted_dates(calendar, highlighted_days, 3);

#if LV_USE_CALENDAR_HEADER_DROPDOWN
    lv_calendar_header_dropdown_create(calendar);
#elif LV_USE_CALENDAR_HEADER_ARROW
    lv_calendar_header_arrow_create(calendar);
#endif
    // lv_calendar_set_showed_date(calendar, 2021, 10);   
    lv_obj_t *btn=lv_btn_create(lv_scr_act());
  // lv_obj_add_event_cb(btn2,event_handler_btn,LV_EVENT_ALL,NULL);
  lv_obj_set_width(btn, 70);
  lv_obj_set_height(btn, 32);
  lv_obj_set_pos(btn, 190, 190);

  lv_obj_t * label2 = lv_label_create(btn);
  lv_label_set_text(label2, "Goodbye");
  lv_obj_set_align(label2,LV_TEXT_ALIGN_CENTER);
}
#endif
#if LV_USE_DEMO3
static void roller_event_handler(lv_event_t * e){
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t * obj = lv_event_get_target(e);
    // LV_LOG_USER("code:%d\n",(int)code);
    if(code == LV_EVENT_VALUE_CHANGED) {
        char buf[32];
        lv_roller_get_selected_str(obj, buf, sizeof(buf));
        LV_LOG_USER("Selected month: %s\n", buf);
    }    

}
void demo3_create(){
    lv_group_t * g = lv_group_create();
    lv_group_set_default(g);
    lv_indev_set_group(my_indev,g);    
    lv_obj_t *my_roll=lv_roller_create(lv_scr_act());
    lv_roller_set_options(my_roll,
                        "January\n"
                        "February\n"
                        "March\n"
                        "April\n"
                        "May\n"
                        "June\n"
                        "July\n"
                        "August\n"
                        "September\n"
                        "October\n"
                        "November\n"
                        "December",
                        LV_ROLLER_MODE_INFINITE);
    lv_roller_set_visible_row_count(my_roll, 4);
    lv_obj_center(my_roll);
    lv_obj_add_event_cb(my_roll, roller_event_handler, LV_EVENT_ALL, NULL);
    lv_group_focus_obj(my_roll);


}
#endif
#if LV_USE_DEMO1
lv_obj_t *btn1;
lv_obj_t *btn2;
lv_obj_t *btn3;
lv_obj_t *label;

static void event_handler_btn( lv_event_t *e){
    lv_event_code_t code = lv_event_get_code(e);
    lv_obj_t *obj=lv_event_get_target(e);
    // Serial.println(code);
    if(code == LV_EVENT_CLICKED) {
        if (obj == btn1)
          lv_label_set_text(label, "Hello");
        else if (obj == btn2)
          lv_label_set_text(label, "Goodbye");
        else if (obj == btn3)
          lv_label_set_text(label, "مهدی");         
    }
}
void demo1_create()
{
lv_group_t * g = lv_group_create();
  lv_group_set_default(g);
  lv_indev_set_group(my_indev,g);
  /*Create screen objects*/
  lv_obj_t *screenMain = lv_scr_act();
label=lv_label_create(screenMain);
  lv_label_set_recolor(label,true);
  lv_label_set_text(label,  LV_SYMBOL_OK "#00ff00 Apply #" "#0000ff \xef\x87\xab #" "#ff0000 \xef\x8a\x93 #");  //LV_SYMBOL_SD_CARD LV_SYMBOL_BLUETOOTH LV_SYMBOL_BATTERY_EMPTY);
  lv_obj_set_size(label, 240, 40);
  lv_obj_set_pos(label, 40, 150);
  lv_obj_set_style_text_font(label,&lv_font_montserrat_20,0 );
  // lv_obj_set_style_text_color(label,lv_color_hex(0xff0000),0);//LV_PALETTE_YELLOW
  // lv_obj_set_style_text_color(label,lv_palette_main(LV_PALETTE_GREEN),0);

    static lv_style_t style;
    lv_style_init(&style);

    lv_style_set_border_color(&style, lv_palette_main(LV_PALETTE_AMBER));
    lv_style_set_border_width(&style, 3);
    lv_style_set_border_opa(&style, LV_OPA_50);
    lv_style_set_border_side(&style, LV_BORDER_SIDE_BOTTOM | LV_BORDER_SIDE_RIGHT | LV_BORDER_SIDE_TOP | LV_BORDER_SIDE_LEFT); //LV_BORDER_SIDE_FULL

  label = lv_label_create(screenMain);
  lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
  // lv_label_set_text(label, "سلام مهدی: this is start");
  // lv_label_set_text(label, "سلام مهدی1ودیگر2:thisوما2");
  // lv_label_set_text(label, "سللام مهدی1ودیگر 2 :this و ما2");
  lv_label_set_text(label, "سلام مهدی 1 و دیگر :this is us وما 2");
  lv_obj_set_align(label,LV_TEXT_ALIGN_CENTER);
  lv_obj_set_style_base_dir(label, LV_BASE_DIR_AUTO, 0);
  lv_obj_set_size(label, 310, 40);
  lv_obj_set_pos(label, 0, 180);
  lv_obj_set_style_text_font(label, &lv_font_dejavu_16_persian_hebrew, 0);
  lv_obj_add_style(label, &style, 0);

  label = lv_label_create(screenMain);
  lv_label_set_long_mode(label, LV_LABEL_LONG_WRAP);
  lv_label_set_text(label, "Press a button");
  lv_obj_set_align(label,LV_TEXT_ALIGN_CENTER);
  lv_obj_set_style_base_dir(label, LV_BASE_DIR_AUTO, 0);
  lv_obj_set_style_text_font(label,&lv_font_dejavu_16_persian_hebrew,0 );
  lv_obj_set_size(label, 320, 40);
  lv_obj_set_pos(label, 0, 15);
  

  btn1 = lv_btn_create(screenMain);
  lv_obj_add_event_cb(btn1,event_handler_btn,LV_EVENT_ALL,NULL);
  lv_obj_set_width(btn1, 70);
  lv_obj_set_height(btn1, 32);
  lv_obj_set_pos(btn1, 32, 100);

  lv_obj_t * label1 = lv_label_create(btn1);
  lv_label_set_text(label1, "Hello");
 lv_obj_align(label1, LV_ALIGN_CENTER, 0, 0);


  btn2 = lv_btn_create(screenMain);
  lv_obj_add_event_cb(btn2,event_handler_btn,LV_EVENT_ALL,NULL);
  lv_obj_set_width(btn2, 70);
  lv_obj_set_height(btn2, 32);
  lv_obj_set_pos(btn2, 132, 100);

  lv_obj_t * label2 = lv_label_create(btn2);
  lv_label_set_text(label2, "Goodbye");
   lv_obj_align(label2, LV_ALIGN_CENTER, 0, 0);


  btn3 = lv_btn_create(screenMain);
  lv_obj_add_event_cb(btn3,event_handler_btn,LV_EVENT_ALL,NULL);
  lv_obj_set_width(btn3, 70);
  lv_obj_set_height(btn3, 32);
  lv_obj_set_pos(btn3, 232, 100);

  lv_obj_t * label3 = lv_label_create(btn3);
  lv_label_set_text(label3, "مهدی");
//   lv_obj_set_align(label3,LV_TEXT_ALIGN_CENTER);
   lv_obj_align(label3, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_style_base_dir(label3, LV_BASE_DIR_AUTO, 0);
  lv_obj_set_style_text_font(label3,&lv_font_dejavu_16_persian_hebrew,0 );
    
}
#endif
#if LV_USE_DEMO2
static void anim_x_cb(void * var, int32_t v)
{
    lv_obj_set_x((_lv_obj_t *)var, (lv_coord_t)v);
}

static void sw_event_cb(lv_event_t * e)
{
    lv_obj_t * sw = lv_event_get_target(e);
    lv_obj_t * label = (lv_obj_t *)lv_event_get_user_data(e);

    if(lv_obj_has_state(sw, LV_STATE_CHECKED)) {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, label);
        lv_anim_set_values(&a, lv_obj_get_x(label), 100);
        lv_anim_set_time(&a, 500);
        lv_anim_set_exec_cb(&a, anim_x_cb);
        lv_anim_set_path_cb(&a, lv_anim_path_overshoot);
        lv_anim_start(&a);
    } else {
        lv_anim_t a;
        lv_anim_init(&a);
        lv_anim_set_var(&a, label);
        lv_anim_set_values(&a, lv_obj_get_x(label), -lv_obj_get_width(label));
        lv_anim_set_time(&a, 500);
        lv_anim_set_exec_cb(&a, anim_x_cb);
        lv_anim_set_path_cb(&a, lv_anim_path_ease_in);
        lv_anim_start(&a);
    }

}

void demo2_create()
{
lv_group_t * g = lv_group_create();
  lv_group_set_default(g);
  lv_indev_set_group(my_indev,g);
  /*Create screen objects*/
  lv_obj_t *screenMain = lv_scr_act();

    lv_obj_t * label = lv_label_create(screenMain);
    lv_label_set_text(label, "Hello animations!");
    lv_obj_set_pos(label, 100, 10);


    lv_obj_t * sw = lv_switch_create(screenMain);
    lv_obj_center(sw);
    lv_obj_add_state(sw, LV_STATE_CHECKED);
    lv_obj_add_event_cb(sw, sw_event_cb, LV_EVENT_VALUE_CHANGED, label);
}
#endif