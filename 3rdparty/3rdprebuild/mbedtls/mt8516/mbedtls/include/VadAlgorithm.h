#ifndef __VAD_H__
#define __VAD_H__
#include "VadDetecter.h"

class VadAlgorithm
{
public:
	VadAlgorithm(int _frame_length, int _frame_shift, double _adjustment,
		double _threshold, double _min_signal, double _average_number);
	~VadAlgorithm(void);

	void reset();	//重置
	int detect_voice(short * samples, int begin_index, int sample_length,int frame_num);//处理音频
protected:
	void reset_stats();	//重置统计数据
	bool is_noisy();	//是否为噪音
	double get_snr();	//获取信噪比
	bool isspeech(short* samples, int begin_index, int sample_length);	//是否为音频
	void classify(short* samples, int begin_index, int sample_length);	//音频分类（信号还是噪音）
	void collect_stats(bool is_speech);	//统计（统计信号和噪音的数量和有效功率）
	double log_root_mean_square(short * samples, int begin_index,int sample_length) ;	//计算平均功率
private:
	double average_number;	//平均数
	double adjustment;	//调节器
	double level;		//信号值
	double background;	//噪音值
	double min_signal;	//最小信号
	double threshold;	//阀值(level-background threshold)
	int frame_length;	//帧长
	int frame_shift; //帧变化单位

	bool is_speech;	//是否为信号
	int speech_frame_num;	//信号帧数目
	int background_frame_num;	//噪音帧数目
	double total_background_level;	//噪音有效功率总和
	double total_speech_level;	//信号有效功率总和
	bool begined;	 //是否开始
};


#endif