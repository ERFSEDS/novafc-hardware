
#include "barometer.h"
#include <stdio.h>


 unsigned long cmd_adc(char cmd, SPI_HandleTypeDef hspi1){

 unsigned long temp=0;
 HAL_GPIO_WritePin(BARO_CS_GPIO_Port, BARO_CS_Pin, GPIO_PIN_RESET); // pull CSB low
 uint8_t valtosend=CMD_ADC_CONV+cmd;
 HAL_SPI_Transmit(&hspi1, &valtosend, 1, 1000); // send conversion command
 switch (cmd & 0x0f) // wait necessary conversion time
 {
 case CMD_ADC_256 : HAL_Delay(1); break;
 case CMD_ADC_512 : HAL_Delay(3); break;
 case CMD_ADC_1024: HAL_Delay(4); break;
 case CMD_ADC_2048: HAL_Delay(6); break;
 case CMD_ADC_4096: HAL_Delay(10); break;
 }
 HAL_GPIO_WritePin(BARO_CS_GPIO_Port, BARO_CS_Pin, GPIO_PIN_SET); // pull CSB high to finish the conversion
 HAL_GPIO_WritePin(BARO_CS_GPIO_Port, BARO_CS_Pin, GPIO_PIN_RESET); // pull CSB low to start new command

 uint8_t ADCREAD=CMD_ADC_READ;
 HAL_SPI_Transmit(&hspi1, &ADCREAD, 1, 1000);// send ADC read command

 uint8_t buffer[3];
 HAL_SPI_Receive(&hspi1, buffer, 3, 1000); // send 0 to read 1st byte (MSB)
 temp = (buffer[2] << 16) & (buffer[1] << 8) & (buffer[0]);

 HAL_GPIO_WritePin(BARO_CS_GPIO_Port, BARO_CS_Pin, GPIO_PIN_SET); // pull CSB high to finish the read command
 return temp;
}




 unsigned int cmd_prom(char coef_num, SPI_HandleTypeDef hspi1)
 {

  unsigned int rC=0;

  HAL_GPIO_WritePin(BARO_CS_GPIO_Port, BARO_CS_Pin, GPIO_PIN_RESET); // pull CSB low
  uint8_t valtosend2=CMD_PROM_RD+coef_num*2;
  HAL_SPI_Transmit(&hspi1, &valtosend2, 1, 1000); // send PROM READ command
  uint8_t buffer[2];
  HAL_SPI_Receive(&hspi1, buffer, 2, 1000); //spi_send(0x00); // send 0 to read the MSB
  rC = (buffer[1] << 8) & (buffer[0]);
  HAL_GPIO_WritePin(BARO_CS_GPIO_Port, BARO_CS_Pin, GPIO_PIN_SET); // pull CSB high
  return rC;
 }


 void cmd_reset(SPI_HandleTypeDef hspi1)
 {
	 HAL_GPIO_WritePin(BARO_CS_GPIO_Port, BARO_CS_Pin, GPIO_PIN_RESET); // pull CSB low to start the command
	 uint8_t resetthingy=CMD_RESET;
	 HAL_SPI_Transmit(&hspi1, &resetthingy, 1, 1000); // send reset sequence
	 HAL_Delay(3); // wait for the reset sequence timing
	 HAL_GPIO_WritePin(BARO_CS_GPIO_Port, BARO_CS_Pin, GPIO_PIN_SET); // pull CSB high to finish the command
 }





 unsigned char crc4(unsigned int n_prom[])
 {
  int cnt; // simple counter
  unsigned int n_rem; // crc reminder
  unsigned int crc_read; // original value of the crc
  unsigned char n_bit;
  n_rem = 0x00;
  crc_read=n_prom[7]; //save read CRC
  n_prom[7]=(0xFF00 & (n_prom[7])); //CRC byte is replaced by 0
  for (cnt = 0; cnt < 16; cnt++) // operation is performed on bytes
  { // choose LSB or MSB
  if (cnt%2==1) n_rem ^= (unsigned short) ((n_prom[cnt>>1]) & 0x00FF);
  else n_rem ^= (unsigned short) (n_prom[cnt>>1]>>8);
  for (n_bit = 8; n_bit > 0; n_bit--)
  {
  if (n_rem & (0x8000))
  {
  n_rem = (n_rem << 1) ^ 0x3000;
  }
  else
  {
  n_rem = (n_rem << 1);
  }
  }
  }
  n_rem= (0x000F & (n_rem >> 12)); // // final 4-bit reminder is CRC code
  n_prom[7]=crc_read; // restore the crc_read to its original place
  return (n_rem ^ 0x00);
 }




 int barometer_test (SPI_HandleTypeDef hspi1, UART_HandleTypeDef huart2)
 {

  unsigned long D1; // ADC value of the pressure conversion
  unsigned long D2; // ADC value of the temperature conversion
  unsigned int C[8];
  unsigned char n_crc;
  double P;// calibration coefficients
  double T; // compensated temperature value
  double dT; // difference between actual and measured temperature
  double OFF; // offset at actual temperature
  double SENS; // sensitivity at actual temperature

  int i;





  cmd_reset(hspi1); // reset the module after powerup
  for (i=0;i<8;i++){ C[i]=cmd_prom(i, hspi1);} // read calibration coefficients
  n_crc=crc4(C);

 while(1) // loop without stopping
  {


  D1=cmd_adc(CMD_ADC_D1+CMD_ADC_256, hspi1); // read uncompensated pressure
  D2=cmd_adc(CMD_ADC_D2+CMD_ADC_4096, hspi1); // read uncompensated temperature

  // calcualte 1st order pressure and temperature (MS5607 1st order algorithm)
  dT=D2-C[5]*pow(2,8);
  OFF=C[2]*pow(2,17)+dT*C[4]/pow(2,6);
  SENS=C[1]*pow(2,16)+dT*C[3]/pow(2,7);

  T=(2000+(dT*C[6])/pow(2,23))/100;
  P=(((D1*SENS)/pow(2,21)-OFF)/pow(2,15))/100;
  // place to use P, T, put them on LCD, send them trough RS232 interface...


  sprintf(msg1,"Temperature : %d\n\r", (int)T);
  HAL_UART_Transmit(&huart2,msg1,20,1);

  }

  return 0;
 }

