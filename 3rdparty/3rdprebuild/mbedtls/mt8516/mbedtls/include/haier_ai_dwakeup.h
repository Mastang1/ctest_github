#ifndef __HAIER_AI_DWAKEUP_H__
#define __HAIER_AI_DWAKEUP_H__

#ifdef __cplusplus
extern "C" {
#endif

#include"dwakeup_com.h"

/**
 * pcm data from app
 * the pcm data should be whole datablock (mics+ref interweaved),16k,16bits
 */
typedef struct uai_audio_buffer
{
    short    *buffer;
    int     len;
} uai_audio_buffer;



/**
 * features of the dwakeup devives
 */
typedef struct uai_dwakeup_feature
{
	char    device_id[33];
	uai_dwakeup_algo     algo_type;     // 0 : energy 1: Energy+DOA
    float   peak_mean_energy;
    float   doa_mean_value;
    float   doa_var;
	uai_dwakup_array_type  mic_array_type;  //0: line array  1: circular array
}uai_dwakeup_feature;

/**
 * print log for dwakeup algo from SDK 
 */
 typedef int (*uai_log_fun_t)(const char *fromat, ...);

/**
 * config for dwakeup algo of the device 
 */

/*typedef struct uai_dwakeup_config
{
	char device_id[33];
	char *config_file;
	int dwakeup_algo_type;
	float mic_ratio_app;    
	uai_log_fun_t uai_log;
}uai_dwakeup_config;
*/

/**
* config for dwakeup algo of the device
 */

typedef struct uai_dwakeup_config
{
	char device_id[33];
	int config_type; // config type: if 1, config is from sdk; if 2, config is file path,0 err 
	char *config_file;  // 
	uai_dwakeup_tune_config *tune_config;
	int dwakeup_algo_type;  //
	float mic_ratio_app;    // 
	uai_log_fun_t uai_log;
}uai_dwakeup_config;


 /**
 * @fn
 * @brief	Init dwakeup algorithmn
 * @return	uai_dwakeup_error			
 * @param	config	 	- pointer to config parameters ,check the structure uai_dwakeup_config
 */
uai_dwakeup_error uai_dwakeup_init(uai_dwakeup_config *config);


/**
 * dwakeup process。
 *  add_audio ->get_feature() -> add_device_feature() -> get_score()  -> reset()
 * if provide doa
 *  add_audio ->add_doa()->get_feature() -> add_device_feature() -> get_score()  -> reset()
 */

 /**
 * @fn
 * @brief	add pcm data into the ring buffer
 * @return	uai_dwakeup_error
 * @param	buffer	 	- pointer to buffer parameters ,check the structure uai_audio_buffer
 */
uai_dwakeup_error uai_dwakeup_add_audio(uai_audio_buffer *buffer);


/**
* @fn
* @brief	get wakeup doa data from top sdk
* @return	uai_dwakeup_error
* @param	doa_data	- pointer to doa data buffer(range:0-360)
* @param	count 	    - numbers of doa value
*/
uai_dwakeup_error uai_dwakeup_add_doa(unsigned int *doa_data, int count);


 /**
 * @fn
 * @brief	get the audio feature of the audio which is used for dwakeup 
 * @return	uai_dwakeup_error
 * @param	feature	 	- pointer to feature  ,check the structure uai_dwakeup_feature
  *@param	volume	 	- volume level from app which is converted to x20 12 levels
 */
uai_dwakeup_error uai_dwakeup_get_audio_feature( uai_dwakeup_feature *feature,int volume, int mic_order);



 /**
 * @fn
 * @brief	reset for the dwakeup,mainly for the features group
 * @return	uai_dwakeup_error
 */

uai_dwakeup_error uai_dwakeup_reset();


 /**
 * @fn
 * @brief	add the audio feature of the device into the devices group list
 * @return	uai_dwakeup_error
 * @param	feature	 	- pointer to feature  ,check the structure uai_dwakeup_feature
  *@param	isLocal	 	- 0: not local device 1: local device.
 */

uai_dwakeup_error uai_dwakeup_add_device_feature(uai_dwakeup_feature *feature, int isLocal);

/**
 * get the status result of local device.
 * @para  result 0: dead 1:live.
 * @para  cause: cause value for refer.
 * @return err.
 */
uai_dwakeup_error uai_dwakeup_get_device_score(int *result, device_status_cause *cause);


 /**
 * @fn
 * @brief	release the resouces of the dwakeup algo
 * @return	uai_dwakeup_error
 */
uai_dwakeup_error uai_dwakeup_release();



 /**
 * @fn
 * @brief	get the version of the dwakeup algo
 * @return	const char *  
 */

const char *uai_dwakeup_version();

#ifdef __cplusplus
};
#endif

#endif /* __HAIER_AI_DWAKEUP_H__ */