#include "Drivers/API/inc/API_sht31.h"
#include "mock_ports.h"
#include "/var/lib/gems/3.0.0/gems/ceedling-0.31.1/vendor/unity/src/unity.h"


static sht31_t sht31Sensor;





void setUp(void){

    initSensorData(&sht31Sensor);

}







void test_sensor_init(void){

    sht31Sensor.errState=

                        1

                            ;

    sht31Sensor.humidity=0xFF;

    sht31Sensor.temperature=0xFF;

    sht31Sensor.readCMD=0xFF;



    initSensorData(&sht31Sensor);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((sht31Sensor.humidity)), (UNITY_INT)(UNITY_INT16)((0x00)), (

   ((void *)0)

   ), (UNITY_UINT)(22), UNITY_DISPLAY_STYLE_HEX16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((sht31Sensor.temperature)), (UNITY_INT)(UNITY_INT16)((0x00)), (

   ((void *)0)

   ), (UNITY_UINT)(23), UNITY_DISPLAY_STYLE_HEX16);

    UnityAssertEqualNumber((UNITY_INT)((sht31Sensor.errState)), (UNITY_INT)((

   0

   )), (

   ((void *)0)

   ), (UNITY_UINT)(24), UNITY_DISPLAY_STYLE_INT);

    UnityAssertEqualNumber((UNITY_INT)((sht31Sensor.readCMD)), (UNITY_INT)((0x2400)), (

   ((void *)0)

   ), (UNITY_UINT)(25), UNITY_DISPLAY_STYLE_INT);

}









void test_new_measure_command_fail (void){



    sendI2C_CMD_CMockExpectAnyArgsAndReturn(33, 

   1

   );



    initNewMeasure(&sht31Sensor);

    UnityAssertEqualNumber((UNITY_INT)((

   1

   )), (UNITY_INT)((sht31Sensor.errState)), (

   ((void *)0)

   ), (UNITY_UINT)(36), UNITY_DISPLAY_STYLE_INT);

}









void test_new_measure_command_ok (void){



    sendI2C_CMD_CMockExpectAnyArgsAndReturn(44, 

   0

   );



    initNewMeasure(&sht31Sensor);

    UnityAssertEqualNumber((UNITY_INT)((

   0

   )), (UNITY_INT)((sht31Sensor.errState)), (

   ((void *)0)

   ), (UNITY_UINT)(47), UNITY_DISPLAY_STYLE_INT);

}











void test_read_data_fail (void){



    sht31Sensor.errState=

                        0

                             ;

    sht31Sensor.humidity=0xAA;

    sht31Sensor.temperature=0xAA;



    readI2C_Data_CMockExpectAnyArgsAndReturn(60, 

   1

   );



    readSensorData(&sht31Sensor);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x00)), (UNITY_INT)(UNITY_INT16)((sht31Sensor.humidity)), (

   ((void *)0)

   ), (UNITY_UINT)(64), UNITY_DISPLAY_STYLE_HEX16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x00)), (UNITY_INT)(UNITY_INT16)((sht31Sensor.temperature)), (

   ((void *)0)

   ), (UNITY_UINT)(65), UNITY_DISPLAY_STYLE_HEX16);

    UnityAssertEqualNumber((UNITY_INT)((

   1

   )), (UNITY_INT)((sht31Sensor.errState)), (

   ((void *)0)

   ), (UNITY_UINT)(66), UNITY_DISPLAY_STYLE_INT);

}













void test_read_data_ok (void){

    uint8_t sensorReturnFrame[] = {0x12,0x34,0x56,0x78,0x9A,0xBC};



    sht31Sensor.errState=

                        1

                            ;



    readI2C_Data_CMockExpectAnyArgsAndReturn(87, 

   0

   );

    readI2C_Data_CMockReturnMemThruPtr_data(88, sensorReturnFrame, 6 * sizeof(*sensorReturnFrame));



    readSensorData(&sht31Sensor);



    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x1234)), (UNITY_INT)(UNITY_INT16)((sht31Sensor.temperature)), (

   ((void *)0)

   ), (UNITY_UINT)(92), UNITY_DISPLAY_STYLE_HEX16);

    UnityAssertEqualNumber((UNITY_INT)(UNITY_INT16)((0x789A)), (UNITY_INT)(UNITY_INT16)((sht31Sensor.humidity)), (

   ((void *)0)

   ), (UNITY_UINT)(93), UNITY_DISPLAY_STYLE_HEX16);

    UnityAssertEqualNumber((UNITY_INT)((

   0

   )), (UNITY_INT)((sht31Sensor.errState)), (

   ((void *)0)

   ), (UNITY_UINT)(94), UNITY_DISPLAY_STYLE_INT);

}







void test_error_data_message(void){



    uint8_t buf_msg[50] ="Nunca debera verse este mensaje\r\n";



    sht31Sensor.errState=

                        1

                            ;

    sensorDataString(&sht31Sensor,buf_msg);



    UnityAssertEqualString((const char*)(("Sensor error\r\n")), (const char*)((buf_msg)), (

   ((void *)0)

   ), (UNITY_UINT)(106));

}













void test_correct_data_message(void){

    uint8_t buf_msg[50];



    sht31Sensor.errState=

                        0

                             ;

    sht31Sensor.temperature=0x1234;

    sht31Sensor.humidity=0x5678;



    sensorDataString(&sht31Sensor,buf_msg);



    UnityAssertEqualString((const char*)(("Temperature:-32.56 - Humidity:33.78\r\n")), (const char*)((buf_msg)), (

   ((void *)0)

   ), (UNITY_UINT)(123));

}
