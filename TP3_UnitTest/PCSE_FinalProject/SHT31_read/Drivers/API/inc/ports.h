#ifndef PORTS_H_
#define PORTS_H_

#include "stdint.h"

uint8_t sendI2C_CMD(uint8_t addr, uint8_t *sendCMD, int8_t size); // abstracts HAL I2C write
uint8_t readI2C_Data(uint8_t addr, uint8_t *data, int8_t size);   // abstracts HAL I2C read
void sendStringUart(uint8_t *buf, uint8_t size);

#endif