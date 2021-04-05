#pragma once


#include "main.h"
#include <math.h>

#define CMD_RESET      0x1E
#define CMD_ADC_READ   0x00
#define CMD_ADC_CONV   0x40
#define CMD_ADC_D1     0x00
#define CMD_ADC_D2     0x10
#define CMD_ADC_256    0x00
#define CMD_ADC_512    0x02
#define CMD_ADC_1024   0x04
#define CMD_ADC_2048   0x06
#define CMD_ADC_4096   0x08
#define CMD_PROM_RD    0xA0


char msg1[20] = "                    ";

void spi_send(char cmd);
void cmd_reset(SPI_HandleTypeDef hspi1);
unsigned long cmd_adc(char cmd, SPI_HandleTypeDef hspi1);
unsigned int cmd_prom(char coef_num, SPI_HandleTypeDef hspi1);
unsigned char crc4(unsigned int n_prom[]);


int barometer_test (SPI_HandleTypeDef hspi1, UART_HandleTypeDef huart2);
