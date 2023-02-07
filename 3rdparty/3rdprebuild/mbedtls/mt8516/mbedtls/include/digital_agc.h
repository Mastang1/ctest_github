// ********************************************
//     Copyright by the T auhtor X.F. WANG
//     Sep. 2011, HCCL
// ********************************************

#ifndef T_MODULES_AUDIO_PROCESSING_AGC_MAIN_SOURCE_DIGITAL_AGC_H_
#define T_MODULES_AUDIO_PROCESSING_AGC_MAIN_SOURCE_DIGITAL_AGC_H_

#ifdef AGC_DEBUG
#include <stdio.h>
#endif
#include "../spl/typedefs.h"
#include "../spl/signal_processing_library.h"
#include "gain_control.h"



// the 32 most significant bits of A(19) * B(26) >> 13
#define AGC_MUL32(A, B)             (((B)>>13)*(A) + ( ((0x00001FFF & (B))*(A)) >> 13 ))
// C + the 32 most significant bits of A * B
#define AGC_SCALEDIFF32(A, B, C)    ((C) + ((B)>>16)*(A) + ( ((0x0000FFFF & (B))*(A)) >> 16 ))

typedef struct
{
    T_Word32 downState[8];
    T_Word16 HPstate;
    T_Word16 counter;
    T_Word16 logRatio; // log( P(active) / P(inactive) ) (Q10)
    T_Word16 meanLongTerm; // Q10
    T_Word32 varianceLongTerm; // Q8
    T_Word16 stdLongTerm; // Q10
    T_Word16 meanShortTerm; // Q10
    T_Word32 varianceShortTerm; // Q8
    T_Word16 stdShortTerm; // Q10
} AgcVad_t; // total = 54 bytes

typedef struct
{
    T_Word32 capacitorSlow;
    T_Word32 capacitorFast;
    T_Word32 gain;
    T_Word32 gainTable[32];
    T_Word16 gatePrevious;
    T_Word16 agcMode;
    AgcVad_t      vadNearend;
    AgcVad_t      vadFarend;
#ifdef AGC_DEBUG
    FILE*         logFile;
    int           frameCounter;
#endif
} DigitalAgc_t;

T_Word32 TAgc_InitDigital(DigitalAgc_t *digitalAgcInst, T_Word16 agcMode);

T_Word32 TAgc_ProcessDigital(DigitalAgc_t *digitalAgcInst, const T_Word16 *inNear,
                             const T_Word16 *inNear_H, T_Word16 *out,
                             T_Word16 *out_H, T_UWord32 FS,
                             T_Word16 lowLevelSignal);

T_Word32 TAgc_AddFarendToDigital(DigitalAgc_t *digitalAgcInst, const T_Word16 *inFar,
                                 T_Word16 nrSamples);

void TAgc_InitVad(AgcVad_t *vadInst);

T_Word16 TAgc_ProcessVad(AgcVad_t *vadInst, // (i) VAD state
                            const T_Word16 *in, // (i) Speech signal
                            T_Word16 nrSamples); // (i) number of samples

T_Word32 TAgc_CalculateGainTable(T_Word32 *gainTable, // Q16
                                 T_Word16 compressionGaindB, // Q0 (in dB)
                                 T_Word16 targetLevelDbfs,// Q0 (in dB)
                                 T_UWord8 limiterEnable, T_Word16 analogTarget);

#endif // T_MODULES_AUDIO_PROCESSING_AGC_MAIN_SOURCE_ANALOG_AGC_H_
