/**
 *  @file InterpRegression.c
 *  @author Sheng Di
 *  @date Aug., 2021
 *  @brief 
 *  (C) 2021 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */

#include <stdio.h>
#include <stdlib.h> 
#include <InterpRegression.h>
#include <MatrixOperation.h>
#include <ExtractData.h>

double* calculateCoefficients_3D_X1D4Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* nbPoints)
{
	size_t counter = 0;
	double* extractedMatrix = NULL;
	double* b = NULL;
	extractMatrixFromData_float_3D_X1D4Points(interpSize, n3, n2, n1, offset, rawData, &counter, &extractedMatrix, &b);
	*nbPoints = counter;
	double* extractedMatrixT = (double*) malloc(sizeof(double)*counter*interpSize); //transpose
	
	matrixTransport(extractedMatrix, extractedMatrixT, counter, interpSize);
	
	double* c = (double*) malloc(sizeof(double)*interpSize);
	matrixVecMul(extractedMatrixT, b, c, interpSize, counter);
	
	double* ATA = (double*) malloc(sizeof(double)*interpSize*interpSize);
	matrixMul(extractedMatrixT, extractedMatrix, ATA, interpSize, interpSize, counter);
	
	printMatrix(ATA, interpSize, interpSize);
	printf("-----------------------------------\n");
	printVector(c, interpSize);
	
	double* result = NULL;
	Gauss(ATA, c, interpSize, &result);
	
	free(extractedMatrix);
	free(extractedMatrixT);
	free(ATA);	
	free(b);
	free(c);
	
	return result;
}

double* calculateCoefficients_3D_X3D6Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* nbPoints)
{
	size_t counter = 0;
	double* extractedMatrix = NULL;
	double* b = NULL;
	extractMatrixFromData_float_3D_X3D6Points(interpSize, n3, n2, n1, offset, rawData, &counter, &extractedMatrix, &b);
	*nbPoints = counter;
	double* extractedMatrixT = (double*) malloc(sizeof(double)*counter*interpSize); //transpose
	
	matrixTransport(extractedMatrix, extractedMatrixT, counter, interpSize);
	
	double* c = (double*) malloc(sizeof(double)*interpSize);
	matrixVecMul(extractedMatrixT, b, c, interpSize, counter);
	
	double* ATA = (double*) malloc(sizeof(double)*interpSize*interpSize);
	matrixMul(extractedMatrixT, extractedMatrix, ATA, interpSize, interpSize, counter);

	printMatrix(ATA, interpSize, interpSize);
	printf("-----------------------------------\n");
	printVector(c, interpSize);

	double* result = NULL;
	Gauss(ATA, c, interpSize, &result);
	
	free(extractedMatrix);
	free(extractedMatrixT);
	free(ATA);	
	free(b);
	free(c);
	
	return result;
}

double* calculateCoefficients_3D_X3D8Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* nbPoints)
{
	size_t counter = 0;
	double* extractedMatrix = NULL;
	double* b = NULL;
	extractMatrixFromData_float_3D_X3D8Points(interpSize, n3, n2, n1, offset, rawData, &counter, &extractedMatrix, &b);
	*nbPoints = counter;
	double* extractedMatrixT = (double*) malloc(sizeof(double)*counter*interpSize); //transpose
	
	matrixTransport(extractedMatrix, extractedMatrixT, counter, interpSize);
	
	double* c = (double*) malloc(sizeof(double)*interpSize);
	matrixVecMul(extractedMatrixT, b, c, interpSize, counter);
	
	double* ATA = (double*) malloc(sizeof(double)*interpSize*interpSize);
	matrixMul(extractedMatrixT, extractedMatrix, ATA, interpSize, interpSize, counter);

	printMatrix(ATA, interpSize, interpSize);
	printf("-----------------------------------\n");
	printVector(c, interpSize);

	double* result = NULL;
	Gauss(ATA, c, interpSize, &result);
	
	free(extractedMatrix);
	free(extractedMatrixT);
	free(ATA);	
	free(b);
	free(c);
	
	return result;
}

double* calculateCoefficients_3D_X3D12Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* nbPoints)
{
	size_t counter = 0;
	double* extractedMatrix = NULL;
	double* b = NULL;
	extractMatrixFromData_float_3D_X3D12Points(interpSize, n3, n2, n1, offset, rawData, &counter, &extractedMatrix, &b);
	*nbPoints = counter;
	double* extractedMatrixT = (double*) malloc(sizeof(double)*counter*interpSize); //transpose
	
	matrixTransport(extractedMatrix, extractedMatrixT, counter, interpSize);
	
	double* c = (double*) malloc(sizeof(double)*interpSize);
	matrixVecMul(extractedMatrixT, b, c, interpSize, counter);
	
	double* ATA = (double*) malloc(sizeof(double)*interpSize*interpSize);
	matrixMul(extractedMatrixT, extractedMatrix, ATA, interpSize, interpSize, counter);

	printMatrix(ATA, interpSize, interpSize);
	printf("-----------------------------------\n");
	printVector(c, interpSize);

	double* result = NULL;
	Gauss(ATA, c, interpSize, &result);
	
	free(extractedMatrix);
	free(extractedMatrixT);
	free(ATA);	
	free(b);
	free(c);
	
	return result;
}

