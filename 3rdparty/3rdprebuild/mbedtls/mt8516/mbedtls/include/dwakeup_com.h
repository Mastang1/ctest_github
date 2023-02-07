#ifndef __DWAKEUP_COM_H__
#define __DWAKEUP_COM_H__

#ifdef __cplusplus
extern "C" {
#endif

//#define	BUILD_FOR_XR872
#define BUILD_FOR_UAI_LOG

/**
 * dwakeup error type
 */ 
typedef enum 
{
    UAI_DWAKEUP_ERR_NONE = 0,       /** no error */
    UAI_DWAKEUP_ERR_UNSUPPORT,     /** not support type or fun*/
    UAI_DWAKEUP_ERR_PARAM,       /** wrong para*/
    UAI_DWAKEUP_ERR_NOMEM,      /** no enough momery */
    UAI_DWAKEUP_ERR_PENDING,    /** no enough data */
    UAI_DWAKEUP_ERR_FAILED      /** caculate error */
} uai_dwakeup_error;

/**
 * dwakeup algorithmn type
 */
typedef enum 
{
    UAI_DWAKEUP_ALGO_ENERGY = 0,        /**0: base on Energy */
    UAI_DWAKEUP_ALGO_ENERGY_DOASELF,           /** 1: both Energy and DOA caculated by self */
	UAI_DWAKEUP_ALGO_ENERGY_DOAIN,           /** 2: both Energy and DOA from SDK */
	UAI_DWAKEUP_ALGO_ENERGY_NOAEC,          /**  3: Energy without AEC inside */
	UAI_DWAKEUP_ALGO_ENERGY_NOAEC_DOAIN,     /** 4:  both Energy without AEC inside and DOA from SDK */
	UAI_DWAKEUP_ALGO_ENERGY_NOAEC_DOASELF,   /** 5:  both Energy without AEC inside and DOA caculated by self */
    UAI_DWAKEUO_ALGO_UNKNOWN
}uai_dwakeup_algo;

/**
 * mic array type
 */
typedef enum 
{
    UAI_DWAKEUP_MICTYPE_LINEAR = 0,
    UAI_DWAKEUP_MICTYPE_CIRCULAR
}uai_dwakup_array_type;

typedef enum
{
	LOW_SCORE = 0,
	HIGH_SCORE,
	FAR90,
	CLOSE90,
	LOW_VAR,
	HIGH_VAR,
}device_status_cause;


typedef struct uai_dwakeup_tune_config
{
	int board_type;
	int mic_number;
	int isCircular;
	float *mic_pos;  //mic_pos is array, for example
	float mic_ratio;
	int ratio_active;
	int block_size;
	float energy_diff;
	int debug;
	int savefile_nums;
	char* savefile_path;
	int algo_type;
}uai_dwakeup_tune_config;

#ifdef __cplusplus
};
#endif

#endif /* __DWAKEUP_COM_H__ */
