#include <string.h>
#include "stm32f1xx.h"

UART_HandleTypeDef uart;
ADC_HandleTypeDef adc;
SPI_HandleTypeDef spi;

#define PIN_A_0		ADC1_CH_0
#define PIN_A_1		ADC1_CH_1
#define PIN_A_2		UART2_TX
#define PIN_A_3		UART2_RX
#define PIN_A_4		ADC1_CH4
#define PIN_A_5		SPI1_SCK
#define PIN_A_6		SPI1_MISO
#define PIN_A_7		SPI1_MOSI
#define PIN_B_0		ADC1_CH8
#define PIN_C_0		SPI1_CS



/**************************************************************
 * Function name: send_char
 * This function send char.
 * 
 * @param [in] char c - char to send.
 * 
 * 
 * @return void
 **************************************************************/
void send_char(char c);


/**************************************************************
 * Function name: __io_putchar
 * Function to put char to UART transmition.
 * 
 * @param [in] int ch - Symbol to send
 * 
 * 
 * @return int - Send Symbol
 **************************************************************/
int __io_putchar(int ch);

/**************************************************************
 * Function name: adc_read
 * Function to read ADC value
 * 
 * @param [in] uint32_t channel - Channel which read from
 * 
 * 
 * @return int - Value of ADC
 **************************************************************/
int adc_read(uint32_t channel);

/**************************************************************
 * Function name: UART_Init
 * Function to initialize UART
 * 
 * 
 * @return void
 **************************************************************/
void UART_Init();

/**************************************************************
 * Function name: ADC_Init
 * Function to initialize ADC
 * 
 * 
 * @return void
 **************************************************************/
void ADC_Init();

/**************************************************************
 * Function name: SPI_init
 * Function to initialize SPI 
 * 
 * 
 * @return void
 **************************************************************/
void SPI_init(); 

/**************************************************************
 * Function name: SPI_Send_Bit
 * Function to send by via SPI
 * 
 * @param [in] uint8_t byte - Bit to send
 * 
 * 
 * @return void
 **************************************************************/
void SPI_Send_Bit(uint8_t byte);

/**************************************************************
 * Function name: SPI_WRITE_ADC
 * Function to send ADC value via SPI
 * 
 * @param [in] uint8_t CH0 - First value to send
 * @param [in] uint8_t CH1 - Second value to send
 * @param [in] uint8_t CH4 - third value to send
 * @param [in] uint8_t CH8 - Forth value to send
 * 
 * 
 * @return void
 **************************************************************/
void SPI_WRITE_ADC(uint8_t CH0,uint8_t CH1,uint8_t CH4,uint8_t CH8);
