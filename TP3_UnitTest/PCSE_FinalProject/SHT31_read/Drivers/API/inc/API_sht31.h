/*
 * API_sht31.h
 *
 *  Created on: Apr 13, 2023
 *      Author: leonardo
 */

#include "stdint.h"
#include "stdbool.h"
#include <stdio.h>
#include "API_delay.h"


#define CMD_OK 0
#define CMD_ERR -1
#ifndef API_SHT31_SRC_API_SHT31_H_
#define API_SHT31_SRC_API_SHT31_H_

#define LOW_REPETABILITY_DURATION_MS 4
#define MEDIUM_REPETABILITY_DURATION_MS 6
#define HIGH_REPETABILITY_DURATION_MS 15
#define POWER_UP_TIME 2

#define DEFAULT_ADDR 0x44
#define ADDR_HIGH 0x45

//commands for single shot (SS) measurement

#define SS_CLOCK_STR_EN_HGH_REP 0x2C06
#define SS_CLOCK_STR_EN_MED_REP 0x2C0D
#define SS_CLOCK_STR_EN_LOW_REP 0x2C10

#define SS_CLOCK_STR_DIS_HGH_REP 0x2400
#define SS_CLOCK_STR_DIS_MED_REP 0x240B
#define SS_CLOCK_STR_DIS_LOW_REP 0x2416

//commands for periodic (PER) measurement

#define PER_HGH_REP_05_MPS 0x2032
#define PER_MED_REP_05_MPS 0x2024
#define PER_LOW_REP_05_MPS 0x202F

#define PER_HGH_REP_1_MPS 0x2130
#define PER_MED_REP_1_MPS 0x2126
#define PER_LOW_REP_1_MPS 0x212D

#define PER_HGH_REP_2_MPS 0x2236
#define PER_MED_REP_2_MPS 0x2220
#define PER_LOW_REP_2_MPS 0x222B

#define PER_HGH_REP_4_MPS 0x2334
#define PER_MED_REP_4_MPS 0x2322
#define PER_LOW_REP_4_MPS 0x2329

#define PER_HGH_REP_10_MPS 0x2737
#define PER_MED_REP_10_MPS 0x2721
#define PER_LOW_REP_10_MPS 0x272A

//accelerated response time command
#define ACC_RESPONSE_TIME 0x2B32

//break command, stop periodic measurement
#define BREAK_CMD 0x3093

//soft reset command
#define SOFT_RST 0x30A2
#define GENERAL_CALL_RST 0x0006

//heater commands (write command)
#define HEATER_EN 0x306D
#define HEATER_DIS 0x3066

//readout status register (write command)
#define READ_STATUS_REG 0xF32D

//status reg mask fields

#define ALRT_PENDING_MASK   0x8000
#define HEATER_STATUS_MASK  0x2000
#define RH_ALRT_MASK        0x0800

typedef struct{
	float temperature;	//current temperature
	float humidity;		//current humidity
	uint16_t readCMD;	//single shot read command
	bool_t errState;	//asserted when there is a error in sensor communication commands
}sht31_t;

//Functions

void initNewMeasure(sht31_t * sht31Sensor);	//sends new measure command
void readSensorData(sht31_t * sht31Sensor);	//read data from sensor (temperature, humidity and CRC)
void sensorDataString(sht31_t * sht31Sensor ,uint8_t * buf); //creates data or error string
uint8_t sendI2C_CMD (uint8_t addr,uint8_t * sendCMD,int8_t size);	//abstracts HAL I2C write
uint8_t readI2C_Data (uint8_t addr,uint8_t * data,int8_t size);		//abstracts HAL I2C read
void sendStringUart(uint8_t * buf, uint8_t size);

#define CMD_BYTES_SIZE 2	//every write command to sensor is 2 bytes long
#define DATA_BYTES_SIZE 6	//two bytes from temperature and humidity and one byte CRC each

//data response position

#define MSB_TEMPERATURE 0
#define LSB_TEMPERATURE 1
#define TEMPERATURE_CRC	2
#define MSB_HUMIDITY 	3
#define LSB_HUMIDITY 	4
#define HUMIDITY_CRC	5


#endif /* API_SHT31_SRC_API_SHT31_H_ */
