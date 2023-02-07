#ifndef __DISTRIBUTED_WAKEUP_COMM_MDNSCOMP_HPP__
#define __DISTRIBUTED_WAKEUP_COMM_MDNSCOMP_HPP__


#ifdef  __cplusplus
extern "C" {
#endif

typedef void (*nodelite_mDNS_discovery_cb)(const char* pszIP, const char* pszInfo, void* pCBO);

int nodelite_mDNS_init(const char* pszInterfaceName, nodelite_mDNS_discovery_cb cb, void* pCBO);
int nodelite_mDNS_fini();
int nodelite_mDNS_start(const char* pszServiceName, const char* pszServiceInfo, unsigned int iInfoLen);
int nodelite_mDNS_stop();

#ifdef  __cplusplus
}
#endif

#endif //__DISTRIBUTED_WAKEUP_COMM_MDNSCOMP_HPP__
