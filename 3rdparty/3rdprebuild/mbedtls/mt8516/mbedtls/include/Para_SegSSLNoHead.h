#include "my_debug.h"

#define PI		3.14159    
#define C_sound	340


#define SECTOR_NUM 		180		//ÿ��Mic��TDOA �ֳɶ��ٸ�С�飬ע�����������Զ�Ӧ��DOA�ĽǶ�
#define DEGREE_NUM		360		//����360�ȿռ��ڣ�����Ϊ���ٸ�Degree��ֱ�Ӷ�Ӧ�ڽǶ�ֵ

#define DEGREE_WIDTH	10		//�ҵ�����һ�飬����ȥ��ÿ��Mic�ľ�������Դ

#ifndef MUL_CHAN//////
#define SECTOR_WIDTH	2		//�ҵ�����һ�飬���ھ���DOA
#else
#define SECTOR_WIDTH	8       //�ҵ�����һ�飬���ھ���DOA
#endif////////////////

#define SAMPLE_RATE		16000	//�����ʣ���λ��Hz��

#ifndef MUL_CHAN//////
#define FREQ_LOWHZ		200		//Ƶ�ʷ�Χ��ͣ�Hz��
#else
#define FREQ_LOWHZ		100		
//Ƶ�ʷ�Χ��ͣ�Hz��
#endif////////////////

#define FREQ_HIGHHZ		6000	//Ƶ�ʷ�Χ��ߣ�Hz��

#ifndef MUL_CHAN//////
#define AliasTimes		2		//���������λ����1����λ����1�Σ����������ܵ���λ�
#else
#define AliasTimes		3		//���������λ����1����λ����1�Σ����������ܵ���λ�
#endif////////////////

#define ReliableThd		0.1		//�ж���TF��֧�ִ�DOA

#define FRAMESHIFT		160		//֡�ƣ�
#define DOA_FFT_SIZE	256		//FFT����
#define BIN_NUMBER		128		//����FFT������һ��


#define SPEECH_DOWN		0.1			// 1/16, 160ms   0.015625	//

#define REV_UP			0.5				// 1/2,  20ms 0.125		//	
#define REV_DOWN		0.02			//0.0167 for 600 ms;  0.0333 for 300 ms

#define GROUND_UP		0.01			//1000ms  0.0025		//
#define GROUND_DOWN		0.125			// 1/8, 80ms	0.003125	//	


//////////////////////////////////////////////////////////////////////////
#define ASSERT_EXIT(CND, MSG, CODE)  if(!(CND)) {printf("%s\n", MSG); exit(CODE);}
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define min(a,b)  (((a) < (b)) ? (a) : (b))

//#define SHOW_LOG		1
#define SHOW_BIN		32
#define SHOW_GROUP		0
#define SHOW_PAIR		0

