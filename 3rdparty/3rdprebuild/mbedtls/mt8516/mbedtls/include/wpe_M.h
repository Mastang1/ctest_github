#ifndef WPE_MUL_H
#define WPE_MUL_H

#ifndef WPE_MUL_D
#define WPE_MUL void*
//#define WPE_MUL int
#endif
#include "../top/my_debug.h"

#if defined(_cplusplus)
extern "C"
{
#endif





#define D        2     //delay
#define NFFT     512   //512
#define Fband    257   //257
#define Fra_half 256   //256

	typedef struct Complex_Atom
	{
		float real;
		float imag;
	}complex_atom;

	typedef struct WPE_MUL_Parameter
	{
		int      M;        
	    int      Order;   
	    int      MxO;        
		float    delta;
	    float    lambda;

		float*   output;                
		//short*   output_short;           
		float**  Out;                    
		float**  synbuf;                    
		float**  windata;                  
		complex_atom*   fin;               
		complex_atom**  fout;        
		float*          d;          
		float**         pxx;        
		float**         pyy;          

		complex_atom***  input;    
		complex_atom***  rev;        

		complex_atom***  U;        
		complex_atom***  KK;        
		complex_atom****  Psi_inv;  
	    complex_atom***  W;         

		float    flag;
		// for fft
		float**  pbuf;             

		float    buf[NFFT];
		float    wfft[Fra_half];
		int      ip[Fra_half];
		

	} WpeMParameter;



	typedef enum _TWPE_CODE
	{
		TWPE_OK = 0,
		TWPE_ERR_DATA,	
	}TWPE_CODE;	
		
		
//#endif

	WPE_MUL WPE_MUL_init(int M, int order);
	int WPE_MUL_process(WPE_MUL handle, const short** datain, int nlen, short** dataout);
	void WPE_MUL_release(WPE_MUL handle);


#if defined(_cplusplus)
}
#endif

#endif
