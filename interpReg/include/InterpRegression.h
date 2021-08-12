/**
 *  @file InterpRegression.h
 *  @author Sheng Di
 *  @date July, 2021
 *  @brief Header file for the InterpRegression.c.
 *  (C) 2021 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#ifndef _InterpRegression_H
#define _InterpRegression_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

double* calculateCoefficients_3D_X1D4Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* nbPoints);
double* calculateCoefficients_3D_X3D6Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* nbPoints);
double* calculateCoefficients_3D_X3D8Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* nbPoints);
double* calculateCoefficients_3D_X3D12Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* nbPoints);

#ifdef __cplusplus
}
#endif

#endif /* ----- #ifndef _InterpRgression_H  ----- */

