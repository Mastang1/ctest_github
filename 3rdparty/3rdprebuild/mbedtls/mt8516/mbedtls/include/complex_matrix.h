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

//����ȡģ����
Flt32 complexModulus(Complex c);
Flt32 complexSquare(Complex c);
//�����������
Complex ComplexMultComplex(Complex c1,Complex c2);

Complex ComplexConjugate(Complex* c);

//�����������
Complex ComplexAddComplex(Complex c1,Complex c2);
//�������Ը���
Complex ComplexMultValue(Complex c1,Flt32 value);

ComplexVector ComplexVectorDivComplex(ComplexVector cv1, Complex c2);

Complex ComplexVectorMultComplexVector(ComplexVector cv1, ComplexVector cv2);

//����ÿ��Ԫ�س���һ������
void scalarMultiply(Flt32 s,ComplexMATRIX_2BY2 m, ComplexMATRIX_2BY2* result);
// ��1*2���������ԣ�2*2������
void ComplexVectorMultComplexMatrix(ComplexMATRIX_2BY2 m, ComplexVector v, ComplexVector* result);
// �������
void ComplexMatrixAddComplexMatrix(ComplexMATRIX_2BY2 m1,ComplexMATRIX_2BY2 m2, ComplexMATRIX_2BY2* result);

void setComplexValue(Complex* c,Flt32 real, Flt32 imag);
void setComplexVectorValue(ComplexVector* cv,Complex c0, Complex c1);
void setComplexMatrixValue(ComplexMATRIX_2BY2* cm,ComplexVector cv0, ComplexVector cv1);
#endif  // COMPLEX_MATRIX_H_