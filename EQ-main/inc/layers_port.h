/*
 * layers_port.h
 *
 * @author  Lucjan Maciej, Zachariasz Monka
 *
 */

//config interrup tim10!

#ifndef LAYERS_PORT_H_
#define LAYERS_PORT_H_

#ifndef includestm32f4xx
	#define includestm32f4xx_h_
	#include "stm32f4xx.h"
#endif //includestm32f4xx_h_


//todo pin and port in LLP
#define LP_pin_LED_BLUE GPIO_PIN_15
#define LP_pin_LED_RED GPIO_PIN_14
#define LP_pin_LED_ORANGE GPIO_PIN_13
#define LP_pin_LED_GREEN GPIO_PIN_12
#define LP_port_LED GPIOD

#define LP_pin_MOSI GPIO_PIN_14
#define LP_pin_MISO GPIO_PIN_13
#define LP_pin_SCK  GPIO_PIN_12
#define LP_port_SPI GPIOE

#define LP_pin_CCS  GPIO_PIN_6
#define LP_pin_DCS  GPIO_PIN_7
#define LP_pin_DREQ  GPIO_PIN_1
#define LP_pin_RES  GPIO_PIN_2
#define LP_port_RES  GPIOD 

#define LP_pin_ADC  GPIO_PIN_1
#define LP_port_ADC  GPIOA

#define LP_pin_SPI_ADC_CS  GPIO_PIN_3
#define LP_port_SPI_ADC_CS  GPIOD


//TODO encapsulation LLP
GPIO_InitTypeDef LLP_gpio;
volatile TIM_HandleTypeDef LLP_tim10;
volatile SPI_HandleTypeDef LLP_hspi4;
volatile ADC_HandleTypeDef LP_ADC;
volatile DMA_HandleTypeDef LLP_dma_spi4_tx;
volatile DMA_HandleTypeDef LLP_dma_spi4_rx;
volatile DMA_HandleTypeDef LLP_dma_adc;
volatile TIM_HandleTypeDef tim2;
volatile TIM_OC_InitTypeDef OC;
volatile SPI_HandleTypeDef LLP_hspi5;
volatile DMA_HandleTypeDef LLP_dma_spi5_rx;
volatile DMA_HandleTypeDef LLP_dma_spi5_tx;


typedef enum
{
	LP_LED_OFF = 0U,
	LP_LED_ON = 1U,
	LP_LED_TOGLE = 4U,
} LP_LED_STATUS;

typedef enum
{
	LP_LED_BLUE = 0U,
	LP_LED_RED = 1U,
	LP_LED_ORANGE = 2U,
	LP_LED_GREEN = 3U,
} LP_LED_COLOR;

typedef enum
{
	LLP_ADC_WAIT = 0U,
	LLP_ADC_READY= 1U,
	LLP_ADC_HALF= 2U,

} LP_ADC_state;

volatile LP_LED_STATUS LLP_led_tab[4];
volatile uint8_t LLP_tim10_cycle;
volatile LP_ADC_state LLP_ADC_tab;
volatile uint8_t LP_ADC_EXTERNAL[4];


/**************************************************************
 * Function name: SystemClock_Config
 * Function to config SystemClock
 * 
 * 
 * @return void
 **************************************************************/
void SystemClock_Config(void);


/**************************************************************
 * Function name: Error_Handler
 * Function to Handle with error
 * 
 * 
 * @return void
 **************************************************************/
void Error_Handler(void);


/**************************************************************
 * Function name: LP_Delay
 * Function to delay MCU
 * 
 * @param [in] uint32_t Delay - delay time in  ms
 * 
 * @return void
 **************************************************************/
void LP_Delay(uint32_t Delay);



/**************************************************************
 * Function name: LLP_interrup_EXTI1
 * Function to interrup
 * 
 * 
 * @return void
 **************************************************************/
volatile void LLP_interrup_EXTI1(void);


/**************************************************************
 * Function name: LLP_iunerrup_dma_tx
 * Function to interrup dma
 * 
 * 
 * @return void
 **************************************************************/
volatile void LLP_iunerrup_dma_tx(void);


/**************************************************************
 * Function name: LLP_iunerrup_tim10
 * Function to interrup tim number 10
 * 
 * 
 * @return void
 **************************************************************/
volatile void LLP_iunerrup_tim10(void);


/**************************************************************
 * Function name: LP_init
 * Function to initialize Layers port
 * 
 * 
 * @return void
 **************************************************************/
void LP_init(void);



/**************************************************************
 * Function name: LP_LED
 * Function to set layers port LED
 * 
 * @param [in] LP_LED_COLOR color - LED color
 * @param [in] LP_LED_STATUS status - LED status
 * 
 * @return void
 **************************************************************/
void LP_LED(LP_LED_COLOR color, LP_LED_STATUS status);


/**************************************************************
 * Function name: LP_SPI_low_speed
 * Function to set low speed of Spi
 * 
 * 
 * @return void
 **************************************************************/
void LP_SPI_low_speed(void);


/**************************************************************
 * Function name: LP_SPI_high_speed
 * Function to set high speed of Spi
 * 
 * 
 * @return void
 **************************************************************/
void LP_SPI_high_speed(void);


/**************************************************************
 * Function name: LP_VS1003_register_read
 * Function to read value from VS1003 register
 * 
 * @param [in] uint8_t register_adres - Adress from read data
 * 
 * @return uint16_t - Data from register
 **************************************************************/
uint16_t LP_VS1003_register_read(uint8_t register_adres);


/**************************************************************
 * Function name: LP_VS1003_register_write
 * Function to write data to register of VS1003
 * 
 * @param [in] uint8_t register_adres - Adress from read data
 * @param [in] uint16_t data - Data to write
 * 
 * @return void
 **************************************************************/
void LP_VS1003_register_write(uint8_t register_adres, uint16_t data);


/**************************************************************
 * Function name: LP_VS1003_set_bit
 * Function to set bit
 * 
 * @param [in] uint8_t register_adres - Adress from read data
 * @param [in] uint16_t bit - Bit to set
 * 
 * @return void
 **************************************************************/
void LP_VS1003_set_bit(uint8_t register_adres, uint16_t bit);


/**************************************************************
 * Function name: LP_VS1003_reset_bit
 * Function to reset bit
 * 
 * @param [in] uint8_t register_adres - Adress from read data
 * @param [in] uint16_t bit - Bit to reset
 * 
 * @return void
 **************************************************************/
void LP_VS1003_reset_bit(uint8_t register_adres, uint16_t bit);


/**************************************************************
 * Function name: LP_VS1003_WRITE_DATA_pooling
 * 
 * 
 * @param [in] uint16_t data - Data to write
 * @param [in] uint16_t size - Size of buffor
 * 
 * @return void
 **************************************************************/
void LP_VS1003_WRITE_DATA_pooling(uint16_t* data,uint16_t size);


/**************************************************************
 * Function name: LP_VS1003_WRITE_DATA
 * Function to write data to VS1003
 * 
 * @param [in] uint16_t data -Data to write
 * @param [in] uint16_t size - Size of buffor
 * 
 * @return void
 **************************************************************/
void LP_VS1003_WRITE_DATA(uint16_t* data,uint16_t size);


/**************************************************************
 * Function name: LP_VS1003_WRITE_DATA_wait_for_end
 * Function to write data and waiting for end of transmision
 * 
 * 
 * @return void
 **************************************************************/
void LP_VS1003_WRITE_DATA_wait_for_end(void);


/**************************************************************
 * Function name: LP_VS1003_Hardware_reset
 * Function to reset hardware
 * 
 * 
 * @return void
 **************************************************************/
void LP_VS1003_Hardware_reset(void);


/**************************************************************
 * Function name: LP_ADC_read
 * Function to read ADC 
 * 
 * @param [in] uint16_t data -Data to write
 * @param [in] uint16_t size - Size of buffor
 * 
 * @return void
 **************************************************************/
void LP_ADC_read(uint16_t* data,uint16_t size);


/**************************************************************
 * Function name: LP_ADC_wait_FULL
 * Function to wait for all ADC read
 * 
 * 
 * @return void
 **************************************************************/
void LP_ADC_wait_FULL(void);


/**************************************************************
 * Function name: LP_ADC_wait_HALF
 * Function to wait for half ADC
 * 
 * 
 * @return void
 **************************************************************/
void LP_ADC_wait_HALF(void);


/**************************************************************
 * Function name: LP_ADC_EXTERNAL_CH_L
 * Function to read external
 * 
 * 
 * @return uint8_t
 **************************************************************/
uint8_t LP_ADC_EXTERNAL_CH_L(void);


/**************************************************************
 * Function name: LP_ADC_EXTERNAL_CH_M
 * Function to LP_ADC_EXTERNAL_CH_M
 * 
 * 
 * @return uint8_t
 **************************************************************/
uint8_t LP_ADC_EXTERNAL_CH_M(void);


/**************************************************************
 * Function name: LP_ADC_EXTERNAL_CH_H
 * Function to LP_ADC_EXTERNAL_CH_H
 * 
 * 
 * @return uint8_t
 **************************************************************/
uint8_t LP_ADC_EXTERNAL_CH_H(void);


/**************************************************************
 * Function name: LP_ADC_EXTERNAL_CH_V
 * 
 * 
 * @return uint8_t
 **************************************************************/
uint8_t LP_ADC_EXTERNAL_CH_V(void);



/**************************************************************
 * Function name: LLP_TIM2_init
 * Function to initialize timer
 * 
 * 
 * @return void
 **************************************************************/
void LLP_TIM2_init(void);


/**************************************************************
 * Function name: LLP_ADC_init
 * Function to initialize ADC
 * 
 * 
 * @return void
 **************************************************************/
void LLP_ADC_init(void);


/**************************************************************
 * Function name: LLP_DMA_init
 * Function to initialize DMA
 * 
 * 
 * @return void
 **************************************************************/
void LLP_DMA_init(void);


/**************************************************************
 * Function name: LLP_DREQ_mode_interrup
 * Function to interupt
 * 
 * 
 * @return void
 **************************************************************/
void LLP_DREQ_mode_interrup(void);


/**************************************************************
 * Function name: LLP_DREQ_mode_pooling
 * Function to pooling
 * 
 * 
 * @return void
 **************************************************************/
void LLP_DREQ_mode_pooling(void);


/**************************************************************
 * Function name: LLP_SPI_write
 * Function to write via SPI
 * 
 * @param [in] uint16_t* tx_buff - Buffor with data to transmit
 * @param [in] uint16_t size - Size of buffor
 * 
 * @return void
 **************************************************************/
void LLP_SPI_write(uint16_t* tx_buff , uint16_t size);


/**************************************************************
 * Function name: LLP_SPI_read
 * Function to read via SPI
 * 
 * @param [in] uint16_t* rx_buff -Buffor with read data
 * @param [in] uint16_t size - Size of buffor
 * 
 * @return void
 **************************************************************/
void LLP_SPI_read(uint16_t* rx_buff , uint16_t size);


/**************************************************************
 * Function name: LLP_SPI_read_write
 * Function to write and read via SPI
 * 
 * @param [in] uint16_t* tx_buff -Buffor with data to transmit
 * @param [in] uint16_t* rx_buff -Buffor with read data
 * @param [in] uint16_t size - Size of buffor
 * 
 * @return void
 **************************************************************/
void LLP_SPI_read_write(uint16_t* tx_buff,uint16_t* rx_buff , uint16_t size);


/**************************************************************
 * Function name: LLP_SPI_CS_SCI_inactive_SDI_active
 * Function to choose SPI CS active state
 * 
 * 
 * @return void
 **************************************************************/
void LLP_SPI_CS_SCI_inactive_SDI_active(void);


/**************************************************************
 * Function name: LLP_SPI_CS_SCI_active_SDI_inactive
 * Function to choose SPI CS inactive state
 * 
 * 
 * @return void
 **************************************************************/
void LLP_SPI_CS_SCI_active_SDI_inactive(void);


/**************************************************************
 * Function name: LLP_SPI_DCS_inactive
 * Function to choose inactive DSC
 * 
 * 
 * @return void
 **************************************************************/
void LLP_SPI_DCS_inactive(void);


/**************************************************************
 * Function name: LLP_SPI_DCS_active
 * Function to choose active DCS
 * 
 * 
 * @return void
 **************************************************************/
void LLP_SPI_DCS_active(void);


/**************************************************************
 * Function name: LLP_SPI_RES_inactive
 * Function to set reset inactive state
 * 
 * 
 * @return void
 **************************************************************/
void LLP_SPI_RES_inactive(void);


/**************************************************************
 * Function name: LLP_SPI_RES_active
 * Function to set reset active state
 * 
 * 
 * @return void
 **************************************************************/
void LLP_SPI_RES_active(void);


/**************************************************************
 * Function name: LLP_DREQ_WAIT
 * Function to wait fo DREQ
 * 
 * 
 * @return void
 **************************************************************/
void LLP_DREQ_WAIT(void);

#endif // LAYERS_PORT_H_
