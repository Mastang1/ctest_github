#ifndef __READ_CFG_H__
#define __READ_CFG_H__

#include <iostream>
#include <string>
#include <map>
#include <mutex>
using namespace std;

class UaiDNNVadFilter
{
public:
	virtual ~UaiDNNVadFilter();
public:
	void ReadCfg(string cfg_file);
	static UaiDNNVadFilter* GetInstance();
private:
	UaiDNNVadFilter() = default;
	UaiDNNVadFilter(const UaiDNNVadFilter&) = delete;
	UaiDNNVadFilter& operator=(const UaiDNNVadFilter&) = delete;
public:
	short GetMaxFrm();
	short GetMinFrm();
	short GetMaxSpDur();
	short GetMinSpDur();
	short GetLookAheadFrame();
	short GetTraceBackTail();
	int GetAudio_minlen();
	int GetSpeechHistoryFrm();
	float GetMinVoiceRatio();
	int GetSilenceHistoryFrm();
	float GetMinSilenceRatio();
	int Getm_nMode();
	int Getewindow();
	float Getvad_threshold();

private:
	static UaiDNNVadFilter* p_instance_;
	static std::mutex m_mutext_;
private:
	std::map<string, string> m_cfgMap_; //读取配置文件中key/value对，保存在m_cfgMap_中
};

#endif /*__READ_CFG_H__*/
