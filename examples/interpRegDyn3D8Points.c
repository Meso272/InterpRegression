#include <stdio.h> 
#include <stdlib.h>
#include <rw.h>
#include <InterpRegression.h>
#include <math.h>

double computeMSE(float* rawData, size_t n3, size_t n2, size_t n1, int offset, double* coefficients)
{
	size_t i = 0, j = 0, k = 0;
	size_t index = 0;
	size_t n2xn1 = n2*n1;
	
	size_t counter = 0;
	double sum2 = 0;	
	
	int offset_ = offset;
	for(i=offset_;i<n3-offset_;i+=2)
		for(j = offset_;j<n2-offset_;j+=2)
			for(k =offset_;k<n1-offset_;k+=2)
			{
				index = i*n2xn1+j*n1+k;
				float predValue = coefficients[0]*rawData[index-3] + coefficients[1]*rawData[index-1] + coefficients[2]*rawData[index+1] + coefficients[3]*rawData[index+3]
				+ coefficients[4]*rawData[index-n1] + coefficients[5]*rawData[index+n1] + coefficients[6]*rawData[index-n2xn1] + coefficients[7]*rawData[index+n2xn1];
				sum2 += (predValue - rawData[index])*(predValue - rawData[index]);
				counter++;
			}
	double mse = sqrt(sum2/counter);
	return mse;
}

int main(int argc, char*argv[])
{
	
	char dataFile[100];
	size_t nbEle = 0;
	int status = 0;

	sprintf(dataFile, "%s", argv[1]);
	size_t n3 = atoi(argv[2]);
	size_t n2 = atoi(argv[3]);
	size_t n1 = atoi(argv[4]);		
	
	printf("n3=%zu, n2=%zu, n1=%zu\n", n3, n2, n1);
	
	float* rawData = readFloatData_systemEndian(dataFile, &nbEle, &status);
	
	if(nbEle!=n1*n2*n3)
	{
		printf("Error: nbEle!=n1*n2*n3\n");
		exit(0);
	}
	
	int offset = 1;
	size_t nbPoints = 0;
	double* coefficients = calculateCoefficients_3D_X3D8Points(8, n3, n2, n1, offset, rawData, &nbPoints);
	printf("coefficients = %f %f %f %f %f %f %f %f, nbPoints = %zu\n", 
	coefficients[0], coefficients[1], coefficients[2], coefficients[3], coefficients[4], coefficients[5], coefficients[6], coefficients[7], nbPoints);
	
	double mse = computeMSE(rawData, n3, n2, n1, offset, coefficients);
	
	printf("MSE = %.20G\n", mse);
	
	return 0;
}
