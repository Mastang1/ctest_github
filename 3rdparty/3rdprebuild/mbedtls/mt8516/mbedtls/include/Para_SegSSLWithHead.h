#define PI		3.14159
#define C_sound	340

#define SECTOR_NUM 		180		//ÿ��Mic��TDOA �ֳɶ��ٸ�С�飬ע�����������Զ�Ӧ��DOA�ĽǶ�

#define DEGREE_WIDTH	10		//�ҵ�����һ�飬����ȥ��ÿ��Mic�ľ�������Դ

#define SECTOR_WIDTH	4		//�ҵ�����һ�飬���ھ���DOA


#define SAMPLE_RATE		16000	//�����ʣ���λ��Hz��

#define FREQ_LOWHZ		200		//Ƶ�ʷ�Χ��ͣ�Hz��
#define FREQ_HIGHHZ		7500	//Ƶ�ʷ�Χ��ߣ�Hz��
#define AliasTimes		2		//���������λ����1����λ����1�Σ����������ܵ���λ�

 
#define FRAMESHIFT		160		//֡�ƣ�
#define FFT_SIZE		512		//FFT����
#define BIN_NUMBER		256		//����FFT������һ��


#define SPEECH_DOWN		0.1			// 1/16, 160ms   0.015625	//

#define REV_UP			0.5			// 1/2,  20ms 0.125		//	
#define REV_DOWN		0.02		//0.0167 for 600 ms;  0.0333 for 300 ms
#define GROUND_UP		0.01		//1000ms  0.0025		//
#define GROUND_DOWN		0.125		// 1/8, 80ms	0.003125	//	


//////////////////////////////////////////////////////////////////////////
#define ASSERT_EXIT(CND, MSG, CODE)  if(!(CND)) {printf("%s\n", MSG); return(CODE);}
#define max(a,b)  (((a) > (b)) ? (a) : (b))
#define min(a,b)  (((a) < (b)) ? (a) : (b))

//#define SHOW_LOG		1
#define SHOW_BIN		32
#define SHOW_PAIR		2

#define SHOW_MIC	4 

#define ReliableThd		0.05		//�ж���TF��֧�ִ�Mic