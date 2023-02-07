#define PI		3.14159
#define C_sound	340

#define SECTOR_NUM 		180		//每对Mic，TDOA 分成多少个小块，注意它不是线性对应于DOA的角度

#define DEGREE_WIDTH	10		//找到最大的一块，用以去掉每对Mic的镜像虚声源

#define SECTOR_WIDTH	4		//找到最大的一块，用于决定DOA


#define SAMPLE_RATE		16000	//采样率（单位：Hz）

#define FREQ_LOWHZ		200		//频率范围最低（Hz）
#define FREQ_HIGHHZ		7500	//频率范围最高（Hz）
#define AliasTimes		2		//不超过几次混叠（1个相位差算1次，共几个可能的相位差）

 
#define FRAMESHIFT		160		//帧移：
#define FFT_SIZE		512		//FFT点数
#define BIN_NUMBER		256		//等于FFT点数的一半


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

#define ReliableThd		0.05		//有多少TF点支持此Mic