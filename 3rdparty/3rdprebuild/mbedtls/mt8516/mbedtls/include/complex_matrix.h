#ifndef COMPLEX_MATRIX_H_
#define COMPLEX_MATRIX_H_

#include "bf_common.h"

typedef struct Complex_{
	Flt32 real;
	Flt32 imag;
}Complex;

typedef struct ComplexVector_{
	Complex c0;
	Complex c1;
}ComplexVector;

typedef struct ComplexMATRIX_2BY2_{
	ComplexVector cv0;
	ComplexVector cv1;
}ComplexMATRIX_2BY2;

//复数取模运算
Flt32 complexModulus(Complex c);
Flt32 complexSquare(Complex c);
//两个复数相乘
Complex ComplexMultComplex(Complex c1,Complex c2);

Complex ComplexConjugate(Complex* c);

//两个复数相加
Complex ComplexAddComplex(Complex c1,Complex c2);
//标量乘以复数
Complex ComplexMultValue(Complex c1,Flt32 value);

ComplexVector ComplexVectorDivComplex(ComplexVector cv1, Complex c2);

Complex ComplexVectorMultComplexVector(ComplexVector cv1, ComplexVector cv2);

//矩阵每个元素乘以一个标量
void scalarMultiply(Flt32 s,ComplexMATRIX_2BY2 m, ComplexMATRIX_2BY2* result);
// （1*2）向量乘以（2*2）矩阵
void ComplexVectorMultComplexMatrix(ComplexMATRIX_2BY2 m, ComplexVector v, ComplexVector* result);
// 矩阵相加
void ComplexMatrixAddComplexMatrix(ComplexMATRIX_2BY2 m1,ComplexMATRIX_2BY2 m2, ComplexMATRIX_2BY2* result);

void setComplexValue(Complex* c,Flt32 real, Flt32 imag);
void setComplexVectorValue(ComplexVector* cv,Complex c0, Complex c1);
void setComplexMatrixValue(ComplexMATRIX_2BY2* cm,ComplexVector cv0, ComplexVector cv1);
#endif  // COMPLEX_MATRIX_H_