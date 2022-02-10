#ifndef DEMO_H
#define DEMO_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/
#include <Arduino.h>
#include <lvgl.h>



/*********************
 *      DEFINES
 *********************/
#define PIN_LEFT  21
#define PIN_RIGHT  3
#define PIN_ENTER  22

#define LV_USE_DEMO1 0
#define LV_USE_DEMO2 0
#define LV_USE_DEMO3 0
#define LV_USE_DEMO4 0
#define LV_USE_DEMO5 0
#define LV_USE_DEMO6 1

#define LV_USE_DEMO_TEST 0


/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/**
 * Create a demo application
 */
void demo_test_create(void);
void demo1_create(void);//simple button,persian font,SYMBOL,color
void demo2_create(void);//anim
void demo3_create(void);//roller
void demo4_create(void);//calender
void demo5_create(void);//complex menu
void demo6_create(void);//simple menu

/**********************
 *      MACROS
 **********************/

#endif /*USE_LV_DEMO*/

#ifdef __cplusplus
} /* extern "C" */
#endif
