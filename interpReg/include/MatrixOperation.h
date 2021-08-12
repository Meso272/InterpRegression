/**
 *  @file MatrixOperation.h
 *  @author Sheng Di
 *  @date July, 2021
 *  @brief Header file for the MatrixOperation.c.
 *  (C) 2021 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#ifndef _MatrixOperation_H
#define _MatrixOperation_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>

void matrixTransport(double *a, double *b, size_t row, size_t column);
void matrixMul(double *A, double *B, double *C, size_t rowA, size_t columnB, size_t columnA);
void matrixVecMul(double *A, double *b, double *c, size_t rowA, size_t columnA);
int Gauss(double *a, double *b, size_t size, double** result);
void printMatrix(double* matrix, int m, int n);
void printVector(double* vector, int n);

#ifdef __cplusplus
}
#endif

#endif /* ----- #ifndef MatrixOperation_H  ----- */

