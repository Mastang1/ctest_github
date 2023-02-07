#ifndef _SOUND_CONNECT_PARAMS_H_
#define _SOUND_CONNECT_PARAMS_H_

#ifdef __cplusplus 
extern "C"
{ 
#endif
/*
typedef enum schedule_{
	SCHEDULE_TIME_SHARING,//wakeup and ASR scheduled in dif time slice
	SCHEDULE_PARALLEL,    //wakeup and ASR scheduled meanwhile/simultaneously/at the same time
}SCHEDULE;
*/
typedef enum Interaction_Mode_{
	INTERACTION_MODE_JUST_RECOGNITION  =0,
	INTERACTION_MODE_JUST_UNDERSTANDING=1,
	INTERACTION_MODE_JUST_TTS,
	INTERACTION_MODE_JUST_SEARCH,
	INTERACTION_MODE_JUST_PLAY		
}Interaction_Mode;


#ifdef __cplusplus 
}
#endif

#endif
