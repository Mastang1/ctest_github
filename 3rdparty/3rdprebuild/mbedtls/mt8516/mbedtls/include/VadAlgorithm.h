#ifndef __VAD_H__
#define __VAD_H__
#include "VadDetecter.h"

class VadAlgorithm
{
public:
	VadAlgorithm(int _frame_length, int _frame_shift, double _adjustment,
		double _threshold, double _min_signal, double _average_number);
	~VadAlgorithm(void);

	void reset();	//����
	int detect_voice(short * samples, int begin_index, int sample_length,int frame_num);//������Ƶ
protected:
	void reset_stats();	//����ͳ������
	bool is_noisy();	//�Ƿ�Ϊ����
	double get_snr();	//��ȡ�����
	bool isspeech(short* samples, int begin_index, int sample_length);	//�Ƿ�Ϊ��Ƶ
	void classify(short* samples, int begin_index, int sample_length);	//��Ƶ���ࣨ�źŻ���������
	void collect_stats(bool is_speech);	//ͳ�ƣ�ͳ���źź���������������Ч���ʣ�
	double log_root_mean_square(short * samples, int begin_index,int sample_length) ;	//����ƽ������
private:
	double average_number;	//ƽ����
	double adjustment;	//������
	double level;		//�ź�ֵ
	double background;	//����ֵ
	double min_signal;	//��С�ź�
	double threshold;	//��ֵ(level-background threshold)
	int frame_length;	//֡��
	int frame_shift; //֡�仯��λ

	bool is_speech;	//�Ƿ�Ϊ�ź�
	int speech_frame_num;	//�ź�֡��Ŀ
	int background_frame_num;	//����֡��Ŀ
	double total_background_level;	//������Ч�����ܺ�
	double total_speech_level;	//�ź���Ч�����ܺ�
	bool begined;	 //�Ƿ�ʼ
};


#endif