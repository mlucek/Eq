/*
 * sygnal.h
 *
 * @author  Lucjan Maciej, Zachariasz Monka
 *
 */


#ifndef SIGNALS_Z_H_
#define SIGNALS_Z_H_

#ifndef includestm32f4xx
	#define includestm32f4xx_h_
	#include "stm32f4xx.h"
#endif //includestm32f4xx_h_

uint16_t ssyg_last_sample[8];


/**************************************************************
 * Function name: syg_uint_to_int
 * Function to translate from uint to int
 * 
 * @param [in] uint16_t* in_buff -Buffor with data to translate
 * @param [out] int16_t* out_buff -Buffor with data after translate
 * @param [in] uint16_t size - Size of buffor
 * 
 * @return void
 **************************************************************/
void syg_uint_to_int(uint16_t* in_buff , int16_t* out_buff , uint16_t size);


/**************************************************************
 * Function name: syg_int_to_uint
 * Function to translate from int to uint
 * 
 * @param [in] int16_t* in_buff -Buffor with data to translate
 * @param [out] uint16_t* out_buff -Buffor with data after translate
 * @param [in] uint16_t size - Size of buffor
 * 
 * @return void
 **************************************************************/
void syg_int_to_uint(int16_t* in_buff , uint16_t* out_buff , uint16_t size);


/**************************************************************
 * Function name: syg_init
 * Function to initialize sygnal
 * 
 * 
 * @return void
 **************************************************************/
void syg_init(void);


/**************************************************************
 * Function name: syg_decoding
 * Function to decode sygnal
 * 
 * @param [in] uint16_t* in_buff -Buffor with data to transmit
 * @param [out] uint16_t* out_buff -Buffor with read data
 * @param [in] uint16_t size - Size of buffor
 * 
 * @return void
 **************************************************************/
void syg_decoding(uint16_t* in_buff , uint16_t* out_buff , uint16_t size);


/**************************************************************
 * Function name: syg_FIR
 * Function to filtering signal
 * 
 * @param [in] uint16_t* in_buff -Buffor with data to transmit
 * @param [in] int16_t* out_buff -Buffor with read data
 * @param [in] uint16_t size - Size of buffor
 * @param [in] int16_t FIR_table - table with fir conf
 * 
 * @return void
 **************************************************************/
void syg_FIR(int16_t* in_buff , int16_t* out_buff , uint16_t size, int16_t* FIR_table);


/**************************************************************
 * Function name: syg_mix2
 * Function to mixing signal
 * 
 * @param [in] uint16_t* inA_buff -Buffor with first data
 * @param [in] uint8_t scaleA -Buffor with scale first data
 * @param [in] uint16_t* inB_buff - Buffor with secound data
 * @param [in] uint8_t scaleB - Scale of secound data
 * @param [out] uint16_t out_buff - Out signal
 * @param [in] uint16_t size - Size of buffor
 * 
 * @return void
 **************************************************************/
void syg_mix2(uint16_t* inA_buff ,uint8_t scaleA , uint16_t* inB_buff, uint8_t scaleB, uint16_t* out_buff , uint16_t size);

#endif // SIGNALS_Z_H_
