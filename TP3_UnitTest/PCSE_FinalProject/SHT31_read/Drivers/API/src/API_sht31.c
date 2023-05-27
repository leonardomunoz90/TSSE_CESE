/*
 * API_sht31.c
 *
 *  Created on: Apr 13, 2023
 *      Author: leonardo
 */

#include "API_sht31.h"

static float tempConv(uint16_t temp); // converts raw 16 bits temperature in its actual value
static float humConv(uint16_t hum);	  // converts raw 16 bits temperature in its actual value

void initSensorData(sht31_t *sht31Sensor)
{
	sht31Sensor->errState = false;
	sht31Sensor->humidity = 0;
	sht31Sensor->temperature = 0;
	sht31Sensor->readCMD = SS_CLOCK_STR_DIS_HGH_REP;
}

void initNewMeasure(sht31_t *sht31Sensor)
{
	uint8_t i2cWriteCMD[CMD_BYTES_SIZE];

	i2cWriteCMD[0] = (uint8_t)((sht31Sensor->readCMD & 0xFF00) >> 8); // first byte command
	i2cWriteCMD[1] = (uint8_t)(sht31Sensor->readCMD & 0x00FF);		  // second byte command

	sht31Sensor->errState = sendI2C_CMD((DEFAULT_ADDR << 1), i2cWriteCMD, CMD_BYTES_SIZE);
}

void readSensorData(sht31_t *sht31Sensor)
{
	uint8_t i2cReadData[DATA_BYTES_SIZE];
	if (!readI2C_Data((DEFAULT_ADDR << 1), i2cReadData, DATA_BYTES_SIZE))
	{
		sht31Sensor->errState = false;

		// Merge return bytes in a single uint16_t variable
		sht31Sensor->temperature = (((uint16_t)i2cReadData[MSB_TEMPERATURE]) << 8) | i2cReadData[LSB_TEMPERATURE];
		sht31Sensor->humidity = (((uint16_t)i2cReadData[MSB_HUMIDITY]) << 8) | i2cReadData[LSB_HUMIDITY];
	}
	else
	{
		sht31Sensor->errState = true;
		sht31Sensor->temperature = 0;
		sht31Sensor->humidity = 0;
	}
}

// generates string to be sent (if error flag is asserted return error message)
void sensorDataString(sht31_t *sht31Sensor, uint8_t *buf)
{
	if (!sht31Sensor->errState)
	{
		sprintf(buf, "Temperature:%.2f - Humidity:%.2f\r\n",
				tempConv(sht31Sensor->temperature), humConv(sht31Sensor->humidity));
	}
	else
	{
		sprintf(buf, "Sensor error\r\n");
	}
}

// the following formulas are provided in sensor's data sheet
static float tempConv(uint16_t temp)
{
	float temperature = ((float)(temp)) / 65537;
	return (-45 + (temperature * 175));
}

static float humConv(uint16_t hum)
{
	float humidity = (float)(hum);
	return (100 * humidity / 65537);
}
