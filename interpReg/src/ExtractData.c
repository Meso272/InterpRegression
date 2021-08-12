/**
 *  @file ExtractData.c
 *  @author Sheng Di
 *  @date Aug., 2021
 *  @brief 
 *  (C) 2021 by Mathematics and Computer Science (MCS), Argonne National Laboratory.
 *      See COPYRIGHT in top-level directory.
 */
 
#include <InterpRegression.h>
#include <stdio.h>
#include <stdlib.h>
#include <MatrixOperation.h>
#include <ExtractData.h>

void extractMatrixFromData_float_3D_X1D4Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* counter, double** extractedMatrix, double** b)
{
	size_t i = 0, j = 0, k = 0;
	size_t index = 0;
	size_t n2xn1 = n2*n1;
	
	*counter = 0;
	size_t maxNBEle = n3*n2*((n1+1)/2-3); // number of elements to be extracted
	*extractedMatrix = (double*) malloc(sizeof(double)*maxNBEle*interpSize);
	*b = (double*)malloc(sizeof(double)*maxNBEle);
	size_t nonzeroCounter = 0;
	
	for(i=0;i<n3;i++)
		for(j = 0;j<n2;j++)
			for(k =offset;k<n1-offset;k+=2)
			{
				index = i*n2xn1+j*n1+k;
				(*extractedMatrix)[(*counter)*interpSize+0] = rawData[index-3];
				(*extractedMatrix)[(*counter)*interpSize+1] = rawData[index-1];
				(*extractedMatrix)[(*counter)*interpSize+2] = rawData[index+1];
				(*extractedMatrix)[(*counter)*interpSize+3] = rawData[index+3];
				if(rawData[index]!=0)
					nonzeroCounter++;
				//printf("data[%zu]=%.20G\n", nonzeroCounter, rawData[index]);
				(*b)[*counter] = rawData[index];
				(*counter)++;
			}
	printf("nonzeroCounter = %zu\n", nonzeroCounter);
}

void extractMatrixFromData_float_3D_X3D6Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* counter, double** extractedMatrix, double** b)
{
	size_t i = 0, j = 0, k = 0;
	size_t index = 0;
	size_t n2xn1 = n2*n1;
	
	*counter = 0;
	size_t maxNBEle = (n3-2*offset)*(n2-2*offset)*(n1-2*offset); // number of elements to be extracted
	*extractedMatrix = (double*) malloc(sizeof(double)*maxNBEle*interpSize);
	*b = (double*)malloc(sizeof(double)*maxNBEle);
	size_t nonzeroCounter = 0;
	
	int offset_ = offset+1;	
	
	for(i=offset;i<n3-offset;i+=2)
		for(j = offset;j<n2-offset;j+=2)
			for(k =offset;k<n1-offset;k+=2)
			{
				index = i*n2xn1+j*n1+k;
				(*extractedMatrix)[(*counter)*interpSize+0] = rawData[index-1];
				(*extractedMatrix)[(*counter)*interpSize+1] = rawData[index+1];
				(*extractedMatrix)[(*counter)*interpSize+2] = rawData[index-n1];
				(*extractedMatrix)[(*counter)*interpSize+3] = rawData[index+n1];
				(*extractedMatrix)[(*counter)*interpSize+4] = rawData[index-n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+5] = rawData[index+n2xn1];
				if(rawData[index]!=0)
					nonzeroCounter++;
				//printf("data[%zu]=%.20G\n", nonzeroCounter, rawData[index]);
				(*b)[*counter] = rawData[index];
				(*counter)++;
			}
				
	for(i=offset_;i<n3-offset_;i+=2)
		for(j = offset_;j<n2-offset_;j+=2)
			for(k =offset;k<n1-offset;k+=2)
			{
				index = i*n2xn1+j*n1+k;
				(*extractedMatrix)[(*counter)*interpSize+0] = rawData[index-1];
				(*extractedMatrix)[(*counter)*interpSize+1] = rawData[index+1];
				(*extractedMatrix)[(*counter)*interpSize+2] = rawData[index-n1];
				(*extractedMatrix)[(*counter)*interpSize+3] = rawData[index+n1];
				(*extractedMatrix)[(*counter)*interpSize+4] = rawData[index-n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+5] = rawData[index+n2xn1];
				if(rawData[index]!=0)
					nonzeroCounter++;
				//printf("data[%zu]=%.20G\n", nonzeroCounter, rawData[index]);
				(*b)[*counter] = rawData[index];
				(*counter)++;
			}		
			
	for(i=offset;i<n3-offset;i+=2)
		for(j = offset_;j<n2-offset_;j+=2)
			for(k =offset_;k<n1-offset_;k+=2)
			{
				index = i*n2xn1+j*n1+k;
				(*extractedMatrix)[(*counter)*interpSize+0] = rawData[index-1];
				(*extractedMatrix)[(*counter)*interpSize+1] = rawData[index+1];
				(*extractedMatrix)[(*counter)*interpSize+2] = rawData[index-n1];
				(*extractedMatrix)[(*counter)*interpSize+3] = rawData[index+n1];
				(*extractedMatrix)[(*counter)*interpSize+4] = rawData[index-n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+5] = rawData[index+n2xn1];
				if(rawData[index]!=0)
					nonzeroCounter++;
				//printf("data[%zu]=%.20G\n", nonzeroCounter, rawData[index]);
				(*b)[*counter] = rawData[index];
				(*counter)++;
			}						

	for(i=offset_;i<n3-offset_;i+=2)
		for(j = offset;j<n2-offset;j+=2)
			for(k =offset_;k<n1-offset_;k+=2)
			{
				index = i*n2xn1+j*n1+k;
				(*extractedMatrix)[(*counter)*interpSize+0] = rawData[index-1];
				(*extractedMatrix)[(*counter)*interpSize+1] = rawData[index+1];
				(*extractedMatrix)[(*counter)*interpSize+2] = rawData[index-n1];
				(*extractedMatrix)[(*counter)*interpSize+3] = rawData[index+n1];
				(*extractedMatrix)[(*counter)*interpSize+4] = rawData[index-n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+5] = rawData[index+n2xn1];
				if(rawData[index]!=0)
					nonzeroCounter++;
				//printf("data[%zu]=%.20G\n", nonzeroCounter, rawData[index]);
				(*b)[*counter] = rawData[index];
				(*counter)++;
			}		
			
	printf("nonzeroCounter = %zu\n", nonzeroCounter);
}

void extractMatrixFromData_float_3D_X3D8Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* counter, double** extractedMatrix, double** b)
{
	size_t i = 0, j = 0, k = 0;
	size_t index = 0;
	size_t n2xn1 = n2*n1;
	
	*counter = 0;
	size_t maxNBEle = (n3-2*offset)*(n2-2*offset)*(n1-6); // number of elements to be extracted
	*extractedMatrix = (double*) malloc(sizeof(double)*maxNBEle*interpSize);
	*b = (double*)malloc(sizeof(double)*maxNBEle);
	size_t nonzeroCounter = 0;
	
	int offset_ = offset;	
	
	for(i=offset_;i<n3-offset_;i+=2)
		for(j = offset_;j<n2-offset_;j+=2)
			for(k =offset_;k<n1-offset_;k+=2)
			{
				index = i*n2xn1+j*n1+k;
				(*extractedMatrix)[(*counter)*interpSize+0] = rawData[index-3];				
				(*extractedMatrix)[(*counter)*interpSize+1] = rawData[index-1];
				(*extractedMatrix)[(*counter)*interpSize+2] = rawData[index+1];
				(*extractedMatrix)[(*counter)*interpSize+3] = rawData[index+3];		
				(*extractedMatrix)[(*counter)*interpSize+4] = rawData[index-n1];
				(*extractedMatrix)[(*counter)*interpSize+5] = rawData[index+n1];
				(*extractedMatrix)[(*counter)*interpSize+6] = rawData[index-n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+7] = rawData[index+n2xn1];
								
				if(rawData[index]!=0)
					nonzeroCounter++;
				//printf("data[%zu]=%.20G\n", nonzeroCounter, rawData[index]);
				(*b)[*counter] = rawData[index];
				(*counter)++;
			}
	printf("nonzeroCounter = %zu\n", nonzeroCounter);
}

void extractMatrixFromData_float_3D_X3D12Points(int interpSize, size_t n3, size_t n2, size_t n1, int offset, float* rawData, size_t* counter, double** extractedMatrix, double** b)
{
	size_t i = 0, j = 0, k = 0;
	size_t index = 0;
	size_t n2xn1 = n2*n1;
	size_t n1x3 = n1*3;
	size_t n2xn1x3 = n2xn1*3;
	
	*counter = 0;
	size_t maxNBEle = (n3-2*offset)*(n2-2*offset)*(n1-2*offset); // number of elements to be extracted
	*extractedMatrix = (double*) malloc(sizeof(double)*maxNBEle*interpSize);
	*b = (double*)malloc(sizeof(double)*maxNBEle);
	size_t nonzeroCounter = 0;
	
	int offset_ = offset+1;	
	
	for(i=offset;i<n3-offset;i+=2)
		for(j = offset;j<n2-offset;j+=2)
			for(k =offset;k<n1-offset;k+=2)
			{
				index = i*n2xn1+j*n1+k;			
				(*extractedMatrix)[(*counter)*interpSize+0] = rawData[index-1];
				(*extractedMatrix)[(*counter)*interpSize+1] = rawData[index+1];	
				(*extractedMatrix)[(*counter)*interpSize+2] = rawData[index-n1];
				(*extractedMatrix)[(*counter)*interpSize+3] = rawData[index+n1];
				(*extractedMatrix)[(*counter)*interpSize+4] = rawData[index-n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+5] = rawData[index+n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+6] = rawData[index-3];
				(*extractedMatrix)[(*counter)*interpSize+7] = rawData[index+3];		
				(*extractedMatrix)[(*counter)*interpSize+8] = rawData[index-n1x3];
				(*extractedMatrix)[(*counter)*interpSize+9] = rawData[index+n1x3];
				(*extractedMatrix)[(*counter)*interpSize+10] = rawData[index-n2xn1x3];
				(*extractedMatrix)[(*counter)*interpSize+11] = rawData[index+n2xn1x3];															
				if(rawData[index]!=0)
					nonzeroCounter++;
				//printf("data[%zu]=%.20G\n", nonzeroCounter, rawData[index]);
				(*b)[*counter] = rawData[index];
				(*counter)++;
			}
				
	for(i=offset_;i<n3-offset_;i+=2)
		for(j = offset_;j<n2-offset_;j+=2)
			for(k =offset;k<n1-offset;k+=2)
			{
				index = i*n2xn1+j*n1+k;
				(*extractedMatrix)[(*counter)*interpSize+0] = rawData[index-1];
				(*extractedMatrix)[(*counter)*interpSize+1] = rawData[index+1];	
				(*extractedMatrix)[(*counter)*interpSize+2] = rawData[index-n1];
				(*extractedMatrix)[(*counter)*interpSize+3] = rawData[index+n1];
				(*extractedMatrix)[(*counter)*interpSize+4] = rawData[index-n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+5] = rawData[index+n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+6] = rawData[index-3];
				(*extractedMatrix)[(*counter)*interpSize+7] = rawData[index+3];		
				(*extractedMatrix)[(*counter)*interpSize+8] = rawData[index-n1x3];
				(*extractedMatrix)[(*counter)*interpSize+9] = rawData[index+n1x3];
				(*extractedMatrix)[(*counter)*interpSize+10] = rawData[index-n2xn1x3];
				(*extractedMatrix)[(*counter)*interpSize+11] = rawData[index+n2xn1x3];		
				if(rawData[index]!=0)
					nonzeroCounter++;
				//printf("data[%zu]=%.20G\n", nonzeroCounter, rawData[index]);
				(*b)[*counter] = rawData[index];
				(*counter)++;
			}		
			
	for(i=offset;i<n3-offset;i+=2)
		for(j = offset_;j<n2-offset_;j+=2)
			for(k =offset_;k<n1-offset_;k+=2)
			{
				index = i*n2xn1+j*n1+k;
				(*extractedMatrix)[(*counter)*interpSize+0] = rawData[index-1];
				(*extractedMatrix)[(*counter)*interpSize+1] = rawData[index+1];	
				(*extractedMatrix)[(*counter)*interpSize+2] = rawData[index-n1];
				(*extractedMatrix)[(*counter)*interpSize+3] = rawData[index+n1];
				(*extractedMatrix)[(*counter)*interpSize+4] = rawData[index-n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+5] = rawData[index+n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+6] = rawData[index-3];
				(*extractedMatrix)[(*counter)*interpSize+7] = rawData[index+3];		
				(*extractedMatrix)[(*counter)*interpSize+8] = rawData[index-n1x3];
				(*extractedMatrix)[(*counter)*interpSize+9] = rawData[index+n1x3];
				(*extractedMatrix)[(*counter)*interpSize+10] = rawData[index-n2xn1x3];
				(*extractedMatrix)[(*counter)*interpSize+11] = rawData[index+n2xn1x3];		
				if(rawData[index]!=0)
					nonzeroCounter++;
				//printf("data[%zu]=%.20G\n", nonzeroCounter, rawData[index]);
				(*b)[*counter] = rawData[index];
				(*counter)++;
			}						

	for(i=offset_;i<n3-offset_;i+=2)
		for(j = offset;j<n2-offset;j+=2)
			for(k =offset_;k<n1-offset_;k+=2)
			{
				index = i*n2xn1+j*n1+k;
				(*extractedMatrix)[(*counter)*interpSize+0] = rawData[index-1];
				(*extractedMatrix)[(*counter)*interpSize+1] = rawData[index+1];	
				(*extractedMatrix)[(*counter)*interpSize+2] = rawData[index-n1];
				(*extractedMatrix)[(*counter)*interpSize+3] = rawData[index+n1];
				(*extractedMatrix)[(*counter)*interpSize+4] = rawData[index-n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+5] = rawData[index+n2xn1];
				(*extractedMatrix)[(*counter)*interpSize+6] = rawData[index-3];
				(*extractedMatrix)[(*counter)*interpSize+7] = rawData[index+3];		
				(*extractedMatrix)[(*counter)*interpSize+8] = rawData[index-n1x3];
				(*extractedMatrix)[(*counter)*interpSize+9] = rawData[index+n1x3];
				(*extractedMatrix)[(*counter)*interpSize+10] = rawData[index-n2xn1x3];
				(*extractedMatrix)[(*counter)*interpSize+11] = rawData[index+n2xn1x3];		
				if(rawData[index]!=0)
					nonzeroCounter++;
				//printf("data[%zu]=%.20G\n", nonzeroCounter, rawData[index]);
				(*b)[*counter] = rawData[index];
				(*counter)++;
			}		
			
	printf("nonzeroCounter = %zu\n", nonzeroCounter);
}
