#include <stdio.h> 
#include <stdlib.h>
#include <rw.h>
#include <InterpRegression.h>
#include <math.h>

double computeMSE(float* rawData, size_t n3, size_t n2, size_t n1, double* coefficients)
{
	size_t i = 0, j = 0, k = 0;
	size_t index = 0;
	size_t n2xn1 = n2*n1;
	
	size_t counter = 0;
	double sum2 = 0;
	for(i=1;i<n3;i++)
		for(j = 1;j<n2;j++)
			for(k =1;k<n1;k++)
			{
				index = i*n2xn1+j*n1+k;
				float predValue = coefficients[0]*rawData[index-1] + coefficients[1]*rawData[index-n1] + coefficients[2]*rawData[index-n2xn1] +  coefficients[3]*rawData[index-n1-1]  + coefficients[4]*rawData[index-n2xn1-1] + coefficients[5]*rawData[index-n2xn1-n1]+coefficients[6]*rawData[index-n2xn1-n1-1];
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
	
	int offset = 3;
	double coefficients[7] = {1, 1, 1, -1, -1, -1, 1};
	
	double mse = computeMSE(rawData, n3, n2, n1, coefficients);
	
	printf("MSE = %.20G\n", mse);
	
	return 0;
}
