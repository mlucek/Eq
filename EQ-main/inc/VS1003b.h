/*
 * VS1003b.h
 *
 * @author  Lucjan Maciej, Zachariasz Monka
 *
 */
#ifndef VS1003b_H_
#define VS1003b_H_

#include "layers_port.h"

//User application
#define CODE_SIZE 411

//SCI Registers
#define SCI_MODE		0x0
#define SCI_STATUS		0x1
#define SCI_BASS		0x2
#define SCI_CLOCKF		0x3
#define SCI_DECODE_TIME	0x4
#define SCI_AUDATA		0x5
#define SCI_WRAM		0x6
#define SCI_WRAMADDR	0x7
#define SCI_HDAT0		0x8
#define SCI_HDAT1		0x9
#define SCI_AIADDR		0xA
#define SCI_VOL			0xB
#define SCI_AICTRL0		0xC
#define SCI_AICTRL1		0xD
#define SCI_AICTRL2		0xE
#define SCI_AICTRL3		0xF

//SCI_MODE bits
#define SM_DIFF			(1<<0)
#define SM_SETTOZERO	(1<<1)
#define SM_RESET		(1<<2)
#define SM_OUTOFWAV		(1<<3)
#define SM_PDOWN 		(1<<4)
#define SM_TESTS		(1<<5)
#define SM_STREAM		(1<<6)
#define SM_SETTOZERO2	(1<<7)
#define SM_DACT			(1<<8)
#define SM_SDIORD		(1<<9)
#define SM_SDISHARE		(1<<10)
#define SM_SDINEW		(1<<11)
#define SM_ADPCM		(1<<12)
#define SM_ADPCM_HP		(1<<13)
#define SM_LINE_IN		(1<<14)

//SCI_STATUS

//SCI_BASS

//SCI_CLOCKF_MULT
#define SC_MULT_XTALI_MASK		0x0000
#define SC_MULT_1_5_xXTALI_MASK	0x2000
#define SC_MULT_2_XTALI_MASK	0x4000
#define SC_MULT_2_5_XTALI_MASK	0x6000
#define SC_MULT_3_XTALI_MASK	0x8000
#define SC_MULT_3_5_XTALI_MASK	0xA000
#define SC_MULT_4_XTALI_MASK	0xC000
#define SC_MULT_4_5_XTALI_MASK	0xF000

//SCI_CLOCKF_ADD
#define SC_ADD_MASK				0x0000
#define SC_0_5_ADD_MASK			0x0800
#define SC_1_ADD_MASK			0x1000
#define SC_1_5_ADD_MASK			0x1800

//SCI_CLOCKF_FREQ
#define SC_12_288Mhz 			1072




/**************************************************************
 * Function name: VS1003b_Init
 * Function initialize VS1003b
 * 
 * 
 * @return void
 **************************************************************/
void VS1003b_Init();


/**************************************************************
 * Function name: VS1003b_Record_with_header_ADPCM
 * Function to record with header
 * 
 * @param [in] uint8_t* header -Buffor with header
 * @param [out] uint16_t* header_size -Size of header
 * @param [out] uint16_t* output -Buffor with output data
 * @param [in] uint16_t output_size - Size of output buff
 * 
 * @return void
 **************************************************************/
void VS1003b_Record_with_header_ADPCM(uint8_t* header, uint16_t header_size, uint8_t* output, uint16_t output_size);


/**************************************************************
 * Function name: VS1003b_Record_ADPCM
 * Function to record ADPCM
 * 
 * @param [out] uint8_t* output -Buffor with output data
 * @param [in] uint16_t output_size - Size of output buff
 * 
 * @return void
 **************************************************************/
void VS1003b_Record_ADPCM(uint8_t* output, uint16_t output_size);


/**************************************************************
 * Function name: VS1003b_8bit_to_16Bit
 * Function to translate 8 bit to 16 bit
 * 
 * @param [in] uint8_t* input -Buffor with output data
 * @param [in] uint16_t* input_size -Buffor with input data
 * @param [out] uint16_t* output -Buffor with output data
 * @param [in] uint16_t output_size - Size of output buff
 * 
 * @return void
 **************************************************************/
void VS1003b_8bit_to_16Bit(uint8_t* input, uint16_t input_size, uint16_t* output, uint16_t output_size);


/**************************************************************
 * Function name: VS1003b_Play_48kHz_Init
 * Function to initialize 48kHz play via VS1003b
 * 
 * 
 * @return void
 **************************************************************/
void VS1003b_Play_48kHz_Init();


/**************************************************************
 * Function name: VS1003b_Play
 * Function to play via VS1003b
 * 
 * @param [in] uint16_t* buff -Buffor with data
 * @param [in] uint16_t buff_size - Size of buffor
 * 
 * @return void
 **************************************************************/
void VS1003b_Play(uint16_t* buff,uint16_t buff_size);


/**************************************************************
 * Function name: VS1003b_END_Play
 * Function to stop play via VS1003b
 * 
 * @return void
 **************************************************************/
void VS1003b_END_Play();


/**************************************************************
 * Function name: VS1003b_test_sine
 * Function to test vs1003 usig sine
 * //Sin test 5168Hz  //5sec
 * 
 * 
 * @return void
 **************************************************************/
void VS1003b_test_sine();


/**************************************************************
 * Function name: VS1003b_Set_Freq_Mult
 * Function to set frequency
 * 
 * @param [in] uint16_t* Mult -frequency mult
 * 
 * @return void
 **************************************************************/
void VS1003b_Set_Freq_Mult(uint16_t Mult);


/**************************************************************
 * Function name: VS1003b_Finish
 * Function to end using VS1003b
 * 
 * @return void
 **************************************************************/
void VS1003b_Finish();


/**************************************************************
 * Function name: VS1003b_set_BASS_FREQ
 * Function to set bass
 * 
 * @param [in] uint8_t* bassfreq -bass freuency
 * 
 * @return void
 **************************************************************/
void VS1003b_set_BASS_FREQ(uint8_t bassfreq);


/**************************************************************
 * Function name: VS1003b_set_BASS_Enhancemeeps
 * Function to set bass enhancemeeps
 * 
 * @param [in] uint8_t bassenhancemeeps -bass enhancemeeps
 * 
 * @return void
 **************************************************************/
void VS1003b_set_BASS_Enhancemeeps(uint8_t bassenhancemeeps);


/**************************************************************
 * Function name: VS1003b_set_TRABLE_FREQ
 * Function to set trable freq
 * 
 * @param [in] uint8_t trablefreq -Trable frequency
 * 
 * @return void
 **************************************************************/
void VS1003b_set_TRABLE_FREQ(uint8_t trablefreq);


/**************************************************************
 * Function name: VS1003b_set_TRABLE_CONTROL
 * Function to set trable control
 * 
 * @param [in] uint8_t trablecontrol -Trable conntrol
 * 
 * @return void
 **************************************************************/
void VS1003b_set_TRABLE_CONTROL(uint8_t trablecontrol);


/**************************************************************
 * Function name: VS1003b_set_VOL_RIGHT
 * Function to set vol right channel
 * 
 * @param [in] uint8_t* vol -vol [0-255]
 * 
 * @return void
 **************************************************************/
void VS1003b_set_VOL_RIGHT(uint8_t vol);


/**************************************************************
 * Function name: VS1003b_set_VOL_left
 * Function to set vol left channel
 * 
 * @param [in] uint8_t* vol -vol [0-255]
 * 
 * @return void
 **************************************************************/
void VS1003b_set_VOL_LEFT(uint8_t vol);


/**************************************************************
 * Function name: VS1003b_set_VOL
 * Function to set vol 
 * 
 * @param [in] uint8_t* vol -vol [0-255]
 * 
 * @return void
 **************************************************************/
void VS1003b_set_VOL(uint8_t vol);


/**************************************************************
 * Function name: VS1003b_set_DIFF
 * Function to set diff
 * 
 * @return void
 **************************************************************/
void VS1003b_set_DIFF();

#endif	//VS1003b_H_
