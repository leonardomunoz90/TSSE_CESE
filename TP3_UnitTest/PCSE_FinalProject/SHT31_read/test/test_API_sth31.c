#include "unity.h"
#include "mock_ports.h"
#include "API_sht31.h"

static sht31_t sht31Sensor;

// Inicializa el sensor para todos los test y evitar repetir código
void setUp(void)
{
    initSensorData(&sht31Sensor);
}

// Prueba de iniciliación correcta de la estructura de sensor

void test_sensor_init(void)
{
    sht31Sensor.errState = true;
    sht31Sensor.humidity = 0xFF;
    sht31Sensor.temperature = 0xFF;
    sht31Sensor.readCMD = 0xFF;

    initSensorData(&sht31Sensor);

    TEST_ASSERT_EQUAL_HEX16(sht31Sensor.humidity, 0x00);
    TEST_ASSERT_EQUAL_HEX16(sht31Sensor.temperature, 0x00);
    TEST_ASSERT_EQUAL(sht31Sensor.errState, false);
    TEST_ASSERT_EQUAL(sht31Sensor.readCMD, SS_CLOCK_STR_DIS_HGH_REP);
}

// Prueba de inicialización de nueva medición del sensor, en caso de que el comando I2C
// envíe un NACK, se debe colocar la bandera de errState en true

void test_new_measure_command_fail(void)
{

    sendI2C_CMD_ExpectAnyArgsAndReturn(true);

    initNewMeasure(&sht31Sensor);
    TEST_ASSERT_EQUAL(true, sht31Sensor.errState);
}

// Prueba de inicialización de nueva medición del sensor, en caso de que el comando I2C
// envíe un ACK, se debe colocar la bandera de errState en false

void test_new_measure_command_ok(void)
{

    sendI2C_CMD_ExpectAnyArgsAndReturn(false);

    initNewMeasure(&sht31Sensor);
    TEST_ASSERT_EQUAL(false, sht31Sensor.errState);
}

// Prueba de que por más que previamente se tenga una medición correcta del sensor,
// si ocurre un error en la medición cambia el estado del flag errState y de
// las variables de humedad y temperatura

void test_read_data_fail(void)
{

    sht31Sensor.errState = false;
    sht31Sensor.humidity = 0xAA;
    sht31Sensor.temperature = 0xAA;

    readI2C_Data_ExpectAnyArgsAndReturn(true);

    readSensorData(&sht31Sensor);

    TEST_ASSERT_EQUAL_HEX16(0x00, sht31Sensor.humidity);
    TEST_ASSERT_EQUAL_HEX16(0x00, sht31Sensor.temperature);
    TEST_ASSERT_EQUAL(true, sht31Sensor.errState);
}

// Al contrario que el test anterior, busca validar que si anteriormente se tenía una
// medición con error y luego se logra una medición correcta, cambia el flag errState
// y los valores de las variables humedad y temperatura a los emulados con un arreglo que
// simula la trama de recepción por I2C

void test_read_data_ok(void)
{

    // La secuencia de tramas de 8 bits devuelta por el sensor es:
    //{ MSByte Temperature,LSByte Temperature, Temperature CRC,
    // MSByte Humidity,LSByte Humidity, Humidity CRC }

    // En este caso no se implementó la función de calculo de CRC por lo que sus valores
    // son aribitrarios

    uint8_t sensorReturnFrame[] = {0x12, 0x34, 0x56, 0x78, 0x9A, 0xBC};

    sht31Sensor.errState = true;

    readI2C_Data_ExpectAnyArgsAndReturn(false);
    readI2C_Data_ReturnArrayThruPtr_data(sensorReturnFrame, 6);

    readSensorData(&sht31Sensor);

    TEST_ASSERT_EQUAL_HEX16(0x1234, sht31Sensor.temperature);
    TEST_ASSERT_EQUAL_HEX16(0x789A, sht31Sensor.humidity);
    TEST_ASSERT_EQUAL(false, sht31Sensor.errState);
}

// Busca validad que se genera una trama de error en caso de que el flag errState esté en true

void test_error_data_message(void)
{

    uint8_t buf_msg[50] = "Nunca debería verse este mensaje\r\n";

    sht31Sensor.errState = true;
    sensorDataString(&sht31Sensor, buf_msg);

    TEST_ASSERT_EQUAL_STRING("Sensor error\r\n", buf_msg);
}

// Busca validar la cadena que se genera en caso de que no haya un error en el flag
// errState. Además valida que las funciones internas de conversión de los valores
// en binario del sensor se corresponda con un valor de temperatura y humedad conocido
//(fórmula extraida de la hoja de datos)

void test_correct_data_message(void)
{
    uint8_t buf_msg[50];

    sht31Sensor.errState = false;
    sht31Sensor.temperature = 0x1234; // Equivalente a -32.56°C
    sht31Sensor.humidity = 0x5678;    // Equivalente a humedad de 33.78%

    sensorDataString(&sht31Sensor, buf_msg);

    TEST_ASSERT_EQUAL_STRING("Temperature:-32.56 - Humidity:33.78\r\n", buf_msg);
}

// Para generación de reporte gcovr --html -o coverage.html -f Drivers