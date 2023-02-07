// ********************************************
//     Copyright by the T auhtor X.F. WANG
//     Sep. 2011, HCCL
// ********************************************

#ifndef T_MODULES_AUDIO_PROCESSING_AGC_MAIN_SOURCE_ANALOG_AGC_H_
#define T_MODULES_AUDIO_PROCESSING_AGC_MAIN_SOURCE_ANALOG_AGC_H_

#include "../spl/typedefs.h"
#include "gain_control.h"
#include "digital_agc.h"

//#define AGC_DEBUG
//#define MIC_LEVEL_FEEDBACK
#ifdef AGC_DEBUG
#include <stdio.h>
#endif

#define RXX_BUFFER_LEN  10

static const T_Word16 kMsecSpeechInner = 520;
static const T_Word16 kMsecSpeechOuter = 340;

static const T_Word16 kNormalVadThreshold = 400;

static const T_Word16 kAlphaShortTerm = 6; // 1 >> 6 = 0.0156
static const T_Word16 kAlphaLongTerm = 10; // 1 >> 10 = 0.000977

typedef struct
{
    // Configurable parameters/variables
    T_UWord32      fs;                 // Sampling frequency
    T_Word16       compressionGaindB;  // Fixed gain level in dB
    T_Word16       targetLevelDbfs;    // Target level in -dBfs of envelope (default -3)
    T_Word16       agcMode;            // Hard coded mode (adaptAna/adaptDig/fixedDig)
    T_UWord8       limiterEnable;      // Enabling limiter (on/off (default off))
    TAgc_config_t  defaultConfig;
    TAgc_config_t  usedConfig;

    // General variables
    T_Word16       initFlag;
    T_Word16       lastError;

    // Target level parameters
    // Based on the above: analogTargetLevel = round((32767*10^(-22/20))^2*16/2^7)
    T_Word32       analogTargetLevel;  // = RXX_BUFFER_LEN * 846805;       -22 dBfs
    T_Word32       startUpperLimit;    // = RXX_BUFFER_LEN * 1066064;      -21 dBfs
    T_Word32       startLowerLimit;    // = RXX_BUFFER_LEN * 672641;       -23 dBfs
    T_Word32       upperPrimaryLimit;  // = RXX_BUFFER_LEN * 1342095;      -20 dBfs
    T_Word32       lowerPrimaryLimit;  // = RXX_BUFFER_LEN * 534298;       -24 dBfs
    T_Word32       upperSecondaryLimit;// = RXX_BUFFER_LEN * 2677832;      -17 dBfs
    T_Word32       lowerSecondaryLimit;// = RXX_BUFFER_LEN * 267783;       -27 dBfs
    T_UWord16      targetIdx;          // Table index for corresponding target level
#ifdef MIC_LEVEL_FEEDBACK
    T_UWord16      targetIdxOffset;    // Table index offset for level compensation
#endif
    T_Word16       analogTarget;       // Digital reference level in ENV scale

    // Analog AGC specific variables
    T_Word32       filterState[8];     // For downsampling wb to nb
    T_Word32       upperLimit;         // Upper limit for mic energy
    T_Word32       lowerLimit;         // Lower limit for mic energy
    T_Word32       Rxx160w32;          // Average energy for one frame
    T_Word32       Rxx16_LPw32;        // Low pass filtered subframe energies
    T_Word32       Rxx160_LPw32;       // Low pass filtered frame energies
    T_Word32       Rxx16_LPw32Max;     // Keeps track of largest energy subframe
    T_Word32       Rxx16_vectorw32[RXX_BUFFER_LEN];// Array with subframe energies
    T_Word32       Rxx16w32_array[2][5];// Energy values of microphone signal
    T_Word32       env[2][10];         // Envelope values of subframes

    T_Word16       Rxx16pos;           // Current position in the Rxx16_vectorw32
    T_Word16       envSum;             // Filtered scaled envelope in subframes
    T_Word16       vadThreshold;       // Threshold for VAD decision
    T_Word16       inActive;           // Inactive time in milliseconds
    T_Word16       msTooLow;           // Milliseconds of speech at a too low level
    T_Word16       msTooHigh;          // Milliseconds of speech at a too high level
    T_Word16       changeToSlowMode;   // Change to slow mode after some time at target
    T_Word16       firstCall;          // First call to the process-function
    T_Word16       msZero;             // Milliseconds of zero input
    T_Word16       msecSpeechOuterChange;// Min ms of speech between volume changes
    T_Word16       msecSpeechInnerChange;// Min ms of speech between volume changes
    T_Word16       activeSpeech;       // Milliseconds of active speech
    T_Word16       muteGuardMs;        // Counter to prevent mute action
    T_Word16       inQueue;            // 10 ms batch indicator

    // Microphone level variables
    T_Word32       micRef;             // Remember ref. mic level for virtual mic
    T_UWord16      gainTableIdx;       // Current position in virtual gain table
    T_Word32       micGainIdx;         // Gain index of mic level to increase slowly
    T_Word32       micVol;             // Remember volume between frames
    T_Word32       maxLevel;           // Max possible vol level, incl dig gain
    T_Word32       maxAnalog;          // Maximum possible analog volume level
    T_Word32       maxInit;            // Initial value of "max"
    T_Word32       minLevel;           // Minimum possible volume level
    T_Word32       minOutput;          // Minimum output volume level
    T_Word32       zeroCtrlMax;        // Remember max gain => don't amp low input

    T_Word16       scale;              // Scale factor for internal volume levels
#ifdef MIC_LEVEL_FEEDBACK
    T_Word16       numBlocksMicLvlSat;
    T_UWord8 micLvlSat;
#endif
    // Structs for VAD and digital_agc
    AgcVad_t            vadMic;
    DigitalAgc_t        digitalAgc;

#ifdef AGC_DEBUG
    FILE*               fpt;
    FILE*               agcLog;
    T_Word32       fcount;
#endif

    T_Word16       lowLevelSignal;
} Agc_t;

#endif // T_MODULES_AUDIO_PROCESSING_AGC_MAIN_SOURCE_ANALOG_AGC_H_
