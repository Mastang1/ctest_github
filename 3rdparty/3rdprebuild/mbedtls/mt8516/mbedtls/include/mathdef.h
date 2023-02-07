
#define TW_SPL_WORD16_MAX		(32767)
#define TW_SPL_WORD16_MIN		(-32768)
#define TW_SPL_MAX_SEED_USED    (0x80000000L)
//#define FXP_MAX_8U     ( 0xFF )
//#define FXP_MAX_16U    ( 0xFFFF )
//#define FXP_MAX_32U    ( 0xFFFFFFFF )
//#define FXP_MIN_8S     (-128 )
//#define FXP_MAX_8S     ( 127 )
#define FXP_MIN_16S    (-32768 )
#define FXP_MAX_16S    ( 32767 )
//#define FXP_MIN_32S    (-2147483647 - 1 )
//#define FXP_MAX_32S    ( 2147483647 )



#define LW_SIGN (long)0x80000000       /* sign bit */
#define LW_MIN (long)0x80000000
#define LW_MAX (long)0x7fffffff


//#define ONE_Q8        256           /* (1<<8) */
//#define ONE_Q9        512           /* (1<<9) */
//#define ONE_Q11       2048          /* (1<<11) */
//#define ONE_Q12       4096          /* (1<<12) */
//#define ONE_Q13       8192          /* (1<<13) */
//#define ONE_Q14       16384         /* (1<<14) */
#define ONE_Q15       32767         /* ((1<<15)-1) */
//#define ONE_Q19       524288L       /* (1<<19) */
//#define ONE_Q25       33554432L     /* (1<<25) */
//#define ONE_Q26       67108864L     /* (1<<26) */
//#define ONE_Q28       268435456L    /* (1<<28) */
//#define TWO_Q3        16            /* (2*(1<<3)) */
//#define TWO_Q19       1048576L      /* (2*(1<<19)) */
//#define THREE_Q8      768           /* (3*(1<<8)) */
//#define SIX_Q8        1536          /* (6*(1<<8)) */
//#define SIX_Q12       24576         /* (6*(1<<12)) */
//#define EIGHT_Q11     16384         /* (8*(1<<11)) */
//#define TEN_Q11       20480         /* (10 * (1<<11)) */
//#define X0001_Q8      0             /* (0.001*(1<<8)) */
//#define X005_Q19      26214         /* (0.05*(1<<19)) */
//#define X01_Q14       1638          /* (0.1*(1<<14)) */
//#define X016_Q15      5242          /* (0.16*(1<<15)) */
//#define X05_Q6        32            /* (0.5 * (1<<6)) */
//#define X05_Q7        64            /* (0.5*(1<<7)) */
//#define X05_Q13       4096          /* (0.5*(1<<13)) */
//#define X05_Q14       8192          /* (0.5*(1<<14)) */
#define X05_Q15       16384         /* (0.5*(1<<15)) */
//#define X064_Q15      20971         /* (0.64*(1<<15)) */
//#define X069_Q15      22609         /* (0.69*(1<<15)) */
//#define X14_Q14       22937         /* (1.4*(1<<14)) */
//#define X1_732_Q14    28377         /* (1.732*(1<<14)) */
//#define X12_Q8        3072          /* (12.0*(1<<8)) */
//#define X25_Q6        1600          /* (25*(1<<6)) */
//#define X30_Q8        7680          /* (30.0*(1<<8)) */
//#define X60_Q9        30720         /* (60*(1<<9)) */
//#define X75_Q8        19200         /* (75*(1<<8)) */
//#define X117_Q5       3744          /* (117*(1<<5)) */
//#define XN03_Q15      -9830         /* (-0.3*(1<<15)) */	
//#define N2_Q11        -4096         /* (-2*(1<<11)) */
//#define M01_Q15       -3276         /* (-0.1*(1<<15)) */
//#define M10_Q11       -20480        /* (-10*(1<<11)) */
//#define MONE_Q15      -32768        /* (-(1<<15)) */
//#define LOG2_Q15      22712	    /*log2*(1<<15) */ 
//#define ONE_Q15F      32768         /* 1<<15 */
//#define ONE_Q3        8             /* 1<<3 */
#define PI_Q13		25736			  /*Q13*/

//#define PI2_Q12		(25736)			/*Q12*/
#define EBASE_Q		(22282)			/*Q13: 2.71828*/

//#define Q32			32
//#define Q31			31
#define Q30			30
//#define Q29			29
//#define Q28			28
//#define Q24			24
//#define Q20			20
//#define Q19			19
//#define Q18			18
//#define Q17			17
//#define Q16			16
#define	Q15			15
#define	Q14			14
#define Q13			13
#define Q12			12
#define	Q11			11
//#define Q10			10
//#define Q9			9
//#define Q8			8
//#define Q6			6
//#define Q5			5
//#define	Q4			4
//#define Q2			2
#define Q0			0