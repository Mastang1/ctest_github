#ifndef _NINDEX_CALCULATE_H_
#define _NINDEX_CALCULATE_H_

#ifdef __cplusplus
extern "C" {
#endif


#include"../dwakeup_com.h"

    typedef struct indexCaculateStruc
	{
		char    device_id[33];
		int     algo_type;
		float peakMeanEnergy;
		float doaMeanValue;
		float doaVar;
		int isCircular;
		device_status_cause dev_status_cause;

	}indexCalculateStruc;


	typedef struct indexCaculateListGroup
	{
		indexCalculateStruc *indexCalculateList;
		int feature_nums;
		int localIndex;
		int device_status;
		float energy_diffs;

	}indexCalculateListGroup;

	extern indexCalculateListGroup *indexCalculateGroup;


	uai_dwakeup_error nIndexCalculateInit(int dev_nums,float energy_diff_value);

	uai_dwakeup_error nIndexCalculateResult();

	uai_dwakeup_error nIndexCalculateReset();

	uai_dwakeup_error nIndexCalculateRelease();

#if 0
	/**
 * @fn
 * @brief	Calculate the index of the device which would be responsed depends on the Energy and DOA information 
 * @return	int			 - dev index
 * @param	dev_data	 	- [in] dev information on time, except the old information depending on the timestamp
 * @param	dev_nums	 	- [in] total numbers of all devices which have information, except the old information depending the timestamp,numbers should be at least 2
 */


int nIndexCalculate(indexCalculateStruc *dev_data, int dev_nums);

/**
* @fn
* @brief	Calculate the index of the device which would be responsed depends on the Energy and DOA information
* @return	int			 - dev index
* @param	dev_data	 	- [in] dev information on time, except the old information depending on the timestamp
* @param	dev_nums	 	- [in] total numbers of all devices which have information, except the old information depending the timestamp,numbers should be at least 2
*/


int nIndexCalculateTwo(indexCalculateStruc *dev_data);

#endif


#ifdef __cplusplus
}
#endif

#endif
