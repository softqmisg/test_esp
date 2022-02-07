#include <Arduino.h>
#include "SPI.h"
// #include "TouchScreen.h"
#include "TFT_eSPI.h"
#include "demo.h"

#define TFT_BL_PIN  2
// #define YP 26
// #define XM 25
// #define YM 32
// #define XP 33
// const lv_point_t points_array[]={{32,100},{142,100}};

// TouchScreen ts = TouchScreen(XP, YP, XM, YM, 340);
// TSPoint oldPoint;
static lv_disp_draw_buf_t disp_buf;
static lv_color_t buf[TFT_WIDTH * 10];
lv_disp_drv_t disp_drv;
// lv_indev_drv_t indev_drv;
lv_indev_drv_t indev_drv_button;
lv_indev_t *my_indev;

TFT_eSPI tft = TFT_eSPI();

void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
    uint32_t w = (area->x2 - area->x1 + 1);
    uint32_t h = (area->y2 - area->y1 + 1);
    uint32_t wh = w*h;

    tft.startWrite();
    tft.setAddrWindow(area->x1, area->y1, w, h);
    while (wh--) tft.pushColor(color_p++->full);
    tft.endWrite();

    lv_disp_flush_ready(disp);
}
// void my_input_read(lv_indev_drv_t * drv, lv_indev_data_t*data)
// {
//   TSPoint p = ts.getPoint();
  
//   if (p.z > ts.pressureThreshhold){
//     data->state = LV_INDEV_STATE_PR;
//     data->point.x = p.x*240/1024;
//     data->point.y = p.y*320/1024;
//     oldPoint.x = p.x;
//     oldPoint.y = p.y;
//   }
//   else {
//     data->state = LV_INDEV_STATE_REL;
//     data->point.x = oldPoint.x*240/1024;
//     data->point.y = oldPoint.y*320/1024;
//   }

//   // return false; /*No buffering now so no more data read*/
// }

int my_keys_read(void)
{
  int ID=-1;//LV_KEY_ENTER; LV_KEY_RIGHT ;//LV_KEY_LEFT
  if(!digitalRead(PIN_LEFT))
    ID=LV_KEY_LEFT;
  if(!digitalRead(PIN_RIGHT))
    ID=LV_KEY_RIGHT;
  if(!digitalRead(PIN_ENTER))
    ID=LV_KEY_ENTER;
    
  return ID;
}

void encoder_with_keys_read(lv_indev_drv_t *drv, lv_indev_data_t *data){
  static uint32_t last_btn = 0;   /*Store the last pressed button*/
  int key_pr = my_keys_read();     /* use LV_KEY_ENTER for encoder press */
  if(key_pr>=0)
  {
    last_btn = key_pr;            /*Get the last pressed or released key*/
                                     
    data->state = LV_INDEV_STATE_PR;
  }
  else
  {
    data->state = LV_INDEV_STATE_REL;
  }
 data->key = last_btn;
}

static void my_log(const char *buf)
{
  Serial.println(buf);
}
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(PIN_LEFT,INPUT_PULLUP);
   pinMode(PIN_RIGHT,INPUT_PULLUP);
   pinMode(PIN_ENTER,INPUT_PULLUP);
   ledcSetup(0, 5000, 8);
  ledcAttachPin(TFT_BL_PIN, 0);
  ledcWrite(0, 30);
  tft.begin();
  tft.setRotation(3);
  // analogReadResolution(10);

  // oldPoint = ts.getPoint();

  lv_init();
  lv_log_register_print_cb(my_log);
  lv_disp_draw_buf_init(&disp_buf, buf, NULL, TFT_WIDTH * 10);
  
  /*Initialize the display*/
  
  lv_disp_drv_init(&disp_drv);
  disp_drv.hor_res = 320;
  disp_drv.ver_res = 240;
  disp_drv.flush_cb = my_disp_flush;
  disp_drv.draw_buf = &disp_buf;
  lv_disp_t *mydisp=lv_disp_drv_register(&disp_drv);
  lv_disp_set_default(mydisp);
    /*Initialize the input device driver*/
  
  // lv_indev_drv_init(&indev_drv);
  // indev_drv.type = LV_INDEV_TYPE_POINTER;
  // indev_drv.read_cb = my_input_read;
  // lv_indev_drv_register(&indev_drv);

  lv_indev_drv_init(&indev_drv_button);
  indev_drv_button.type=LV_INDEV_TYPE_ENCODER;
  indev_drv_button.read_cb=encoder_with_keys_read;
  my_indev= lv_indev_drv_register(&indev_drv_button);
  
  // see also lv_group_create && lv_group_add_obj && lv_indev_set_group
  // https://docs.lvgl.io/8/overview/indev.html?highlight=lv_indev_set_button_points#groups
  // https://docs.lvgl.io/latest/en/html/porting/indev.html
  
#if LV_USE_DEMO1
   demo1_create();
#elif LV_USE_DEMO2
  demo2_create();
#elif LV_USE_DEMO3
  demo3_create();
#elif LV_USE_DEMO4
  demo4_create();
#endif
  
  lv_scr_load(lv_scr_act());  
}

void loop() {
  // put your main code here, to run repeatedly:
  lv_task_handler();
  delay(1);
}