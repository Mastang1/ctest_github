#ifndef MY_DEBUG
#define MY_DEBUG



//#define BATCH_TEST
//#define DOT_NOT_DISPLAY__MESSAG

////////////////////add defines for input format/////////////////////////////#define PCM_INPUT
#define PCM_INPUT
#define ONE_FILE_INPUT    			//1 chanel
#ifndef ONE_FILE_INPUT
#define TWO_CHAN_FILES_INPUT        	//ch1 and ch2 are in two files
#define CHAN2_POSTFIX		'8'
#endif


/////////////////////add defines for output file format/////////////////
//#define ADD_SILENCE_IN_THE_TAIL
//#define ONE_CHAN_OUTPUT
#ifndef ONE_CHAN_OUTPUT
#define OUTPUT_2CHAN
#endif


//#define WIN32


/////////////////////add defines for AEC////////////////////////////////////
//#define WJ_AEC         //remove bug?
#define AEC_SUPPORT_COMM  //support commucation mode  0 for comm 1 for asr
//#define AEC_NLP_AGGRESSIVE
//#define AEC_NLP_MODERATE

#define WebRTC_AEC



//////////////////////add defines for NS///////////////////////////////////
//#define NS_TDEREVERB_X           //default    
//#define NS_GENTLE				 //gentle
#define NS_default             //default
//#define NS_MEDIUM             //medium
//#define NS_AGGRESS             //aggressive




/////////////////////add defines for BF///////////////////////////////////
//#define BFWeight_Method1
//#define BFWeight_Method2
//#define BFWeight_Method3

//#define DOI_Method1

#define BEAMWIETH 50

#define EIG_BF

//#define MVDR_BF

#define EigMaxFind   // find the vector corresponding to the maximum eig value


#define IVA_C




////////////////////add defines for WPE/////////////////////////////////
//#define WJ_WPE                  //dereverbaration  need to be open for building








#endif
