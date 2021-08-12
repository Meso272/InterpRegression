/**
 *  @file ExtractData.h
 *  @author Sheng Di
 *  @date July, 2021
 *  @brief Header file for the ExtractData.c.
 *  (C) 2021 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#ifndef _ExtractData_H
#define _ExtractData_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

void extractMatrixFromData_float_3D_X1D4Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* counter, double** extractedMatrix, double** b);
void extractMatrixFromData_float_3D_X3D6Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* counter, double** extractedMatrix, double** b);
void extractMatrixFromData_float_3D_X3D8Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* counter, double** extractedMatrix, double** b);
void extractMatrixFromData_float_3D_X3D12Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* counter, double** extractedMatrix, double** b);

#ifdef __cplusplus
}
#endif

#endif /* ----- #ifndef _ExtractData_H  ----- */
