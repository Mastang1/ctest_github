/*
 * @file
 * @brief split audio data for some mic board.
 *
 * 
 * 
 * Common steps:
 *	split_process,
 *	
 *
 */

#ifndef __SPLIT__
#define __SPLIT__

#include <wave_file.h>

typedef enum
{
	MIC_BOARD_DOT_NAU85L40 = 0,
	MIC_BOARD_DOT_AC108,
	MIC_BOARD_DOT_NAU85L40_IFLYTEK,
	MIC_BOARD_DOT_AC108_IFLYTEK,
	MIC_BOARD_DOT_NAU85L40_SOUNDAI,
	MIC_BOARD_DOT_NAU85L40_AW_R331,
	MIC_BOARD_DOT_NAU85L40_ROKID,
	MIC_BOARD_MT8163_MVSIICON,//Refrigerator
	MIC_BOARD_CX20921,
	MIC_BOARD_ES7210_IFLYTEK,//air conditioner TFT MT8163
	MIC_BOARD_XMOS,//XMOS 2MIC
	MIC_BOARD_RK3308_2MIC,
	MIC_BOARD_MAX,
}mic_board_type_e;
//haier mic start
#define RECORD_PATH "/tmp/record"

#ifdef __cplusplus
extern "C" {
#endif /* C++ */

/** 
 * @fn
 * @brief	open save split audio data file.
 *
 * @return	int			- 1: error. 0 : success.
 *
 */
int split_open_save_file(void);


/** 
 * @fn
 * @brief	close save split audio data file.
 *
 * @return	int			- 1: error. 0 : success.
 *
 */
int split_close_save_file(void);

/**
 * @fn
 * @brief	split mic board audio data and save split audio data to out_buffer .
 * @return	int			 	- 1: stopped. 0 : recording.
 * @param	in_buffer	 	- [in] audio data input buffer
 * @param	in_data_size	- [in] audio data input size
 * @param	out_buffer	 	- [out] audio data malloc for output buffer
 * @param	out_data_size	- [out] audio data output size
 * @param	mic_board_type	- [in] mic board type
 */
int split_process(void * in_buffer, unsigned int in_data_size, void ** out_buffer, unsigned int * out_data_size);

/**
 * @fn
 * @brief	set split param.
 * @return	int			 	- 1: stopped. 0 : recording.
 * @param	mic_board_type	- [in] mic board type
 */
int set_split_param(mic_board_type_e mic_board_type);

#ifdef __cplusplus
} /* extern "C" */	
#endif /* C++ */

#endif
