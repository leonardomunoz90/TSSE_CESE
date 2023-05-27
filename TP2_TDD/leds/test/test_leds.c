// Al inicializar la biblioteca todos los leds quedan apagados
// Con todos los leds apagados, prendo led 2, verifico que el bit 1 vale 1
// Con led 2 prendido,apago led 2, verifico que bit 1 vale 0
// Con todos los leds apagados, prendo el 3, predo el 5, apago el 3 y apago el 7, quedebería quedar el bit 4 en 1 y el resto en cero
// Prendo un led, consulto el estado y tiene que estar prendido
// Apago un led, consulto el estado y tiene que estar apagado
// Con todos los leds apagados, prendo todos los leds y verifico que se encienden
// Con todos los leds prendidos, apagado todos los leds y verifico que se apagan
// Apago todos los led, enciendo led 1, apago led 16 (Revisar los valores limites de los argumentos)
// Enciendo led 5, 7, 33 y -17, debería ignorar los valores erroneos (Revisar que pasa con valores erroneos de los argumentos)
// Inicializo mal para que devuelva false

#include "unity.h"
#include "leds.h"

static uint16_t puerto_virtual;

// Al inicializar la biblioteca todos los leds quedan apagados

void setUp(void)
{
    ledsInit(&puerto_virtual);
}

void test_todos_los_leds_inician_apagados(void)
{
    uint16_t puerto_virtual = 0xFFFF;
    ledsInit(&puerto_virtual);
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// Con todos los leds apagados, prendo led 2, verifico que el bit 1 vale 1

void test_prender_un_led(void)
{
    TEST_ASSERT_TRUE(ledTurnOnSingle(2));
    TEST_ASSERT_EQUAL_HEX16(0x0002, puerto_virtual);
}

// Con led 2 prendido,apago led 2, verifico que bit 1 vale 0

void test_preder_y_apagar_un_led(void)
{
    ledTurnOnSingle(2);
    TEST_ASSERT_TRUE(ledTurnOffSingle(2));
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// Con todos los leds apagados, prendo el 3, predo el 5, apago el 3 y apago el 7, quedebería quedar el bit 4 en 1 y el resto en cero

void test_prender_y_apagar_varios_leds(void)
{
    ledTurnOnSingle(3);
    ledTurnOnSingle(5);
    ledTurnOffSingle(3);
    ledTurnOffSingle(7);
    TEST_ASSERT_EQUAL_HEX16(0x0010, puerto_virtual);
}

// Prendo un led, consulto el estado y tiene que estar prendido
void test_consultar_led_encendido(void)
{
    ledTurnOnSingle(8);
    TEST_ASSERT_TRUE(isLedOn(8));
}

// Apago un led, consulto el estado y tiene que estar apagado
void test_consultar_led_apagado(void)
{
    ledTurnOnSingle(4);
    ledTurnOffSingle(4);
    TEST_ASSERT_FALSE(isLedOn(4));
}

// Con todos los leds apagados, prendo todos los leds y verifico que se encienden

void test_encender_todos_los_leds(void)
{
    ledTurnOnAll();
    TEST_ASSERT_EQUAL_HEX16(0xFFFF, puerto_virtual);
}

// Con todos los leds prendidos, apagado todos los leds y verifico que se apagan

void test_apagar_todos_los_leds(void)
{
    ledTurnOnAll();
    ledTurnOffAll();
    TEST_ASSERT_EQUAL_HEX16(0x0000, puerto_virtual);
}

// Apago todos los led, enciendo led 1, enciendo led 16

void test_de_valores_limites(void)
{
    ledTurnOffAll();
    ledTurnOnSingle(1);
    ledTurnOnSingle(16);
    TEST_ASSERT_EQUAL_HEX16(0x8001, puerto_virtual);
}

// Enciendo led 5, 7, 33 y -17, debería ignorar los valores erroneos

void test_de_parametros_erroneos(void)
{
    ledTurnOnSingle(5);
    ledTurnOnSingle(7);
    ledTurnOnSingle(33);
    ledTurnOnSingle(-17);
    TEST_ASSERT_EQUAL_HEX16(0x0050, puerto_virtual);
}

// Inicializo mal para que devuelva false

void test_error_de_inicializacion(void)
{
    uint16_t *puerto_virtual;
    puerto_virtual = NULL;
    TEST_ASSERT_FALSE(ledsInit(puerto_virtual));
}