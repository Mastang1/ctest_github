// ********************************************
//     Windows PCM (.wav) file IO interface
//                     Sep. 2006 H. Zhang
// ********************************************
#ifndef WAV_FILE_IO
#define WAV_FILE_IO

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
  		   char Riff[5];
  		   char WAVEfmt[9];
  		   char Cdata[5];
  		   unsigned long sizeOfFile;
  		   unsigned long nSamplesPerSec;
  		   unsigned long navgBytesPerSec;
  		   unsigned long sizeOfData;
		   unsigned short nBlockAlign;
		   unsigned long sizeOfFmt;
		   unsigned short wFormatTag;
		   unsigned short nChannels;
		   unsigned short nBitPerSample;
}WAVEHEADFMT;


int ReadWaveHead( WAVEHEADFMT *wav_in, FILE *file_in );

int WriteWaveHead( WAVEHEADFMT *wav_out, FILE *file_out );

int PrepareWaveHead( WAVEHEADFMT *wav_head, 
					 unsigned short nChannels,
					 unsigned long nSamplesPerSec,
					 unsigned short nBitPerSample,
					 unsigned long sizeOfData
				   );

int ReadWaveFile( char *filename, WAVEHEADFMT *wavhead, char** data );

int WriteWaveFile( unsigned short nChannels,
				   unsigned long nSamplesPerSec,
				   unsigned short nBitPerSample,
				   unsigned long sizeOfData,
				   char* data,
				   char* filename
				 );

void extract( float  *inbuf, float *outbuf, int length, int nChn , int chn);


#ifdef __cplusplus
}
#endif

#endif
