#include "src/leds.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static uint16_t puerto_virtual;







void setUp(void){

    ledsInit(&puerto_virtual);

}



void test_todos_los_leds_inician_apagados(void){

    uint16_t puerto_virtual=0xFFFF;

    ledsInit(&puerto_virtual);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(27), UNITY_DISPLAY_STYLE_HEX16);

}







void test_prender_un_led (void){

    do {if ((ledTurnOnSingle(2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(33)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0002)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(34), UNITY_DISPLAY_STYLE_HEX16);

}







void test_preder_y_apagar_un_led(void){

    ledTurnOnSingle(2);

    do {if ((ledTurnOffSingle(2))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(41)));}} while(0);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(42), UNITY_DISPLAY_STYLE_HEX16);

}







void test_prender_y_apagar_varios_leds(void){

    ledTurnOnSingle(3);

    ledTurnOnSingle(5);

    ledTurnOffSingle(3);

    ledTurnOffSingle(7);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0010)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(52), UNITY_DISPLAY_STYLE_HEX16);

}





void test_consultar_led_encendido (void){

    ledTurnOnSingle(8);

    do {if ((isLedOn(8))) {} else {UnityFail( ((" Expected TRUE Was FALSE")), (UNITY_UINT)((UNITY_UINT)(58)));}} while(0);

}





void test_consultar_led_apagado (void){

    ledTurnOnSingle(4);

    ledTurnOffSingle(4);

    do {if (!(isLedOn(4))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(65)));}} while(0);

}







void test_encender_todos_los_leds(void){

    ledTurnOnAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0xFFFF)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(72), UNITY_DISPLAY_STYLE_HEX16);

}







void test_apagar_todos_los_leds(void){

    ledTurnOnAll();

    ledTurnOffAll();

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0000)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(80), UNITY_DISPLAY_STYLE_HEX16);

}







void test_de_valores_limites (void){

    ledTurnOffAll();

    ledTurnOnSingle(1);

    ledTurnOnSingle(16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x8001)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(89), UNITY_DISPLAY_STYLE_HEX16);

}







void test_de_parametros_erroneos (void){

    ledTurnOnSingle(5);

    ledTurnOnSingle(7);

    ledTurnOnSingle(33);

    ledTurnOnSingle(-17);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x0050)), (UNITY_INT)(UNITY_INT16)((puerto_virtual)), (

   ((void *)0)

   ), (UNITY_UINT)(99), UNITY_DISPLAY_STYLE_HEX16);

}







void test_error_de_inicializacion (void){

    uint16_t *puerto_virtual;

    puerto_virtual=

                  ((void *)0)

                      ;

    do {if (!(ledsInit(puerto_virtual))) {} else {UnityFail( ((" Expected FALSE Was TRUE")), (UNITY_UINT)((UNITY_UINT)(107)));}} while(0);

}
