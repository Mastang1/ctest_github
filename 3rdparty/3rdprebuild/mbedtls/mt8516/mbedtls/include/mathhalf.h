/*
2.4 kbps MELP Proposed Federal Standard speech coder

Fixed-point C code, version 1.0

*/

#ifndef __MATHHALF
#define __MATHHALF

//#define MAX_32 (WORD32)0x7fffffffL
//#define MIN_32 (WORD32)0x80000000L

//#define MAX_16 (WORD16)0x7fff
//#define MIN_16 (WORD16)0x8000

#ifndef Flag
typedef int   Flag;
#endif

//#define  COMPLEXITY // add by xia

/* addition */
/************/
 WORD16 add(WORD16 var1, WORD16 var2);  /* 1 ops */
 WORD16 sub(WORD16 var1, WORD16 var2);  /* 1 ops */
// WORD32 T_add(WORD32 L_var1, WORD32 L_var2);       /* 2 ops */
// WORD32 L_sub(WORD32 L_var1, WORD32 L_var2);       /* 2 ops */

/* multiplication */
/******************/

 WORD16 mult(WORD16 var1, WORD16 var2); /* 1 ops */
 WORD32 T_mult(WORD16 var1, WORD16 var2);        /* 1 ops */
// WORD16 mult_r(WORD16 var1, WORD16 var2);       /* 2 ops */

/* arithmetic shifts */
/*********************/

 WORD16 shr(WORD16 var1, WORD16 var2);  /* 1 ops */
 WORD16 shl(WORD16 var1, WORD16 var2);  /* 1 ops */
// WORD32 L_shr(WORD32 L_var1, WORD16 var2);        /* 2 ops */
// WORD32 L_shl(WORD32 L_var1, WORD16 var2);        /* 2 ops */
// WORD32 T_mac(WORD32 L_var3, WORD16 var1, WORD16 var2);  /* 1 op */
// WORD16 extract_l(WORD32 L_var1);  /* 1 ops */
 WORD16 extract_h(WORD32 L_var1);  /* 1 ops */
// WORD16 T_round(WORD32 L_var1);      /* 1 ops */
// WORD32 L_deposit_l(WORD16 var1);  /* 1 ops */
// WORD32 L_deposit_h(WORD16 var1);  /* 1 ops */
 WORD16 saturate(WORD32 L_var1);
// WORD32 L_abs(WORD32 L_var1);

 WORD32 T_add(WORD32 L_var1, WORD32 L_var2);
// WORD32 T_add(WORD32 L_var1, WORD32 L_var2);  
// WORD32 T_mult(WORD16 var1, WORD16 var2);        /* 1 ops */
// WORD32 T_mac(WORD32 L_var3, WORD16 var1, WORD16 var2);  /* 1 op */


// WORD16 shift_r(WORD16 var, WORD16 var2);       /* 2 ops */
// WORD32 L_shift_r(WORD32 L_var, WORD16 var2);     /* 3 ops */
// WORD32 L_shr_r (WORD32 L_var1, WORD16 var2);    /* from G723.1 code */


/* multiply accumulate  */
/************************/
// WORD16 mac_r(WORD32 L_var3, WORD16 var1, WORD16 var2); /* 2 op */
// WORD32 L_msu(WORD32 L_var3,WORD16 var1, WORD16 var2);  /* 1 op */
// WORD16 msu_r(WORD32 L_var3, WORD16 var1, WORD16 var2); /* 2 op */


/* negation  */
/*************/
 WORD16 negate(WORD16 var1);      /* 1 ops */
// WORD32 L_negate(WORD32 L_var1);    /* 2 ops */


/* Normalization */
/*****************/

// WORD16 norm_l(WORD32 L_var1);     /* 30 ops */
// WORD16 norm_s(WORD16 var1);      /* 15 ops */

/* Division */
/************/
// WORD16 divide_s(WORD16 var1, WORD16 var2);     /* 18 ops */

/* Non-saturating instructions */
/*******************************/
// WORD32 L_add_c(WORD32 L_Var1, WORD32 L_Var2);     /* 2 ops */
// WORD32 L_sub_c(WORD32 L_Var1, WORD32 L_Var2);     /* 2 ops */
// WORD32 L_sat(WORD32 L_var1);       /* 4 ops */
// WORD32 L_macNs(WORD32 L_var3, WORD16 var1, WORD16 var2);        /* 1 ops */
// WORD32 L_msuNs(WORD32 L_var3, WORD16 var1, WORD16 var2);        /* 1 ops */


/*
   Additional operators
*/
// WORD32 L_mls( WORD32, WORD16 ) ;        /* product of a WORD32 multiples a WORD16 commented by Li Ming*/
// WORD32 L_mls_scale (WORD32 Lv, WORD16 v, WORD16 s); /* L_shl( (Lv*v), s ) */
// WORD16 div_l( WORD32, WORD16 ) ;
// WORD16 i_mult(WORD16 a, WORD16 b);

/* added by Li Ming */
// WORD32 div_s_i(WORD16 num, WORD16 denom);  /* denum can great than numerator, return a WORD32 value, high 16-bit is integrate part and low 16-bit is decimal part*/
/* added by Shao Jian */
// WORD16 mult_Q(WORD16 var1, WORD16 var2,WORD16 var1_Q,WORD16 var2_Q,WORD16 output_Q);/**/
// void T_Log2(
//		  WORD32 L_x,       /* (i) Q0  : input value                                */
//		  WORD16 *exponent, /* (o) Q0  : integer part of Log2.   (range: 0<=val<=30)*/
//		  WORD16 *fraction  /* (o) Q15 : fractional part of Log2. (range: 0<=val<1) */
//		  );
#endif
