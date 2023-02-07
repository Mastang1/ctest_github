#ifndef __MYOPUS_H__
#define __MYOPUS_H__

#ifdef __cplusplus
extern "C" {
#endif

#pragma pack(push,1)

typedef struct _encoder_param
{
    int sample_rate;        // Sampling rate: Narrowband (8 kHz),Wideband (16 kHz),\"Ultra-wideband\" (32 kHz), please set
    int bit_rate;           // encoding bit rate, similar as the quality, set to 0 is OK.
    int vbr_enabled;        // Enable variable bit-rate (VBR)
    int max_bandwidth;    	// max VBR bit-rate allowed
    int channels;           // Voice channels
    int signal_type;        // Enable voice activity detection (VAD)
    int complexity;         // Set encoding complexity (0-10), default 3
    int dtx;                // Set DTX (0/1), default 0

} encoder_param;

typedef struct _opus_header
{
    char c1;          		// check header first bit
    char c2;          		// check header second bit
    short payload_len;      // encoded packet payload length
} opus_header;

typedef struct opus_state_enc_
{
    void *codec_st;         // opus encoder
    void *out_bits;     	// output bits buffer
    int out_len;       		// output bits length
    void *left;             // left data buffer
    int left_len;           // left data length
    char left_flag;         // left data flag
} opus_state_enc;

typedef struct opus_state_dec_
{
    void *codec_st;
    void *out_data;
    int out_len;
} opus_state_dec;

#pragma pack(pop)

int open_encoder(opus_state_enc **enc, int sample_rate, int channels, int bit_rate);

int myopus_encode(void *enc, short *input_buf, int input_len, char **cbits);

void close_encoder(void *enc);

int open_decoder(opus_state_dec **dec, int sample_rate, int channels);

int myopus_decode(void *dec, char *cbits, int cbits_len, short **output_buf);

void close_decoder(void *dec);

#ifdef __cplusplus
}
#endif

#endif
