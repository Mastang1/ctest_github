//
// Created by sky on 2018/9/20.
//

#ifndef DJNI_AUDIOENERGY_H
#define DJNI_AUDIOENERGY_H



#include <stdio.h>


#ifdef __cplusplus
extern "C" {
#endif

#define		MAX_FRAME	400

float calculateScore(short data[], int len, const int LF, const int HF);

//class AudioEnergy {
//};

#ifdef __cplusplus
}
#endif

#endif //DJNI_AUDIOENERGY_H
