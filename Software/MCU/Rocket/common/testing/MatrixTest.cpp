#include "Matrix.hpp"
#include "Cartesian.hpp"
#include <iostream>
#include <algorithm>
void copyValuesToMatrix(Matrix * matrix, float values[3][3]);
void printMatrix(Matrix matrix);
int main() {
	Matrix matrixOne, matrixTwo, result, expectedResult;
	int exitCode = 0;
	float values[3][3] = {	1, 2, 3,
							4, 5, 6,
							7, 8, 9};
	copyValuesToMatrix(&matrixOne, values);
	//matrixOne.values = values;
	float valuesOne[3][3]  = {	1, 2, 3,
							4, 5, 6,
							7, 8, 9};
	copyValuesToMatrix(&matrixTwo, valuesOne);
	
	if(matrixOne != matrixTwo) {
		std::cout << "!= does not work when they are same" << std::endl;
		printMatrix(matrixOne);
		printMatrix(matrixTwo);
		exitCode = 1;
	}

	if(!(matrixOne == matrixTwo)) {
		std::cout << "== does not work when they are same" << std::endl;
		printMatrix(matrixOne);
		printMatrix(matrixTwo);
		exitCode = 1;
	}							
	float valuesTwo[3][3] = {	1.6, 2.0, 3.5,
							9, 55, 60,
							12, 20, 5.5};
	copyValuesToMatrix(&matrixTwo, valuesTwo);
	
	if(matrixOne == matrixTwo) {
		std::cout << "== does not work when they are not the same" << std::endl;
		printMatrix(matrixOne);
		printMatrix(matrixTwo);
		exitCode = 1;
	}

	if(!(matrixOne != matrixTwo)) {
		std::cout << "!= does not work when they are not the same" << std::endl;
		printMatrix(matrixOne);
		printMatrix(matrixTwo);
		exitCode = 1;
	}

			
	float valuesThree[3][3] =  {2.6, 4.0, 6.5,
								13, 60, 66,
								19, 28, 14.5};
	copyValuesToMatrix(&expectedResult, valuesThree);
	result = matrixOne + matrixTwo;
	if(result != expectedResult) {
		std::cout << "+ does not work" << std::endl;
		printMatrix(result);
		printMatrix(expectedResult);
		exitCode = 1;
	}
	return exitCode;
	
	Cartesian vector = {3,2,1};
	Cartesian resultVector = matrixOne * vector;
	Cartesian expectedVector = {10, 28, 46};
	if(expectedVector != resultVector) {
		std::cout << "Vector rotation does not work" << std::endl;
		exitCode =  1;
	}
	return exitCode;
}

void copyValuesToMatrix(Matrix * matrix, float values[3][3]) {
	for(int i = 0; i < 3; i++) {
		for(int j = 0; j < 3; j++) {
			matrix->values[i][j] = values[i][j];
		}
	}
	std::cout << "Copy COrrectly" << std::endl;
}

void printMatrix(Matrix matrix) {	
    std::cout << "Matrix" << std::endl;
    for(int i = 0; i < 3; i++) {
    	for(int j = 0; j < 3; j++) {
    		std::cout << matrix.values[i][j] << ", ";
    	}
    	std::cout <<  std::endl;
    }
    std::cout <<  std::endl;
}
