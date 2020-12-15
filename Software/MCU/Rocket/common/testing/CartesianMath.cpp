#include "cartesian.h"
#include <cmath>
#include <iostream>
int main() {
	Cartesian one = {1, 2, 3};
	Cartesian two = {3, 4, 5};
	Cartesian result, trueResult;
	int exitCode = 0;
	float scalar;
	
	//check magnitude function
	float magnitude = one.magnitude();
	float trueMagnitude = sqrt( (one.x * one.x) + (one.y * one.y) + (one.z * one.z));
	if(magnitude != trueMagnitude) {
		exitCode = 1;
		std::cout << "Error with Cartesian magnitude function" << std::endl;
		std::cout << "Expected: " << trueMagnitude << std::endl;	
		std::cout << "Actual"  << magnitude << std::endl;
	}
	magnitude = two.magnitude();
	trueMagnitude = sqrt( (two.x * two.x) + (two.y * two.y) + (two.z * two.z));
	if(magnitude != trueMagnitude) {
		exitCode = 1;
		std::cout << "Error with Cartesian magnitude function" << std::endl;
		std::cout << "Expected: " << trueMagnitude << std::endl;	
		std::cout << "Actual"  << magnitude << std::endl;
	}
	
	
	//check equals and not equal function
	one = {1,2,3};
	two = {1,2,3};
	
	if( !(one == two) ) {
		exitCode = 1;
		std::cout << "Error with ==" << std::endl;
	}
	if( one != two ) {
		exitCode = 1;
		std::cout << "Error with !=" << std::endl;
	}
	
	//check normalize
	one = {4, 1, 2.3};
	two = {90, 3, 6.0};
	magnitude = one.magnitude();
	trueResult.x = one.x / magnitude;
	trueResult.y = one.y / magnitude;
	trueResult.z = one.z / magnitude;
	result = one.normalize();
	if(result != trueResult) {
		exitCode = 1;
		std::cout << "Error with the Cartesian normalize function" << std::endl;
		std::cout << "Expected: <" << trueResult.x << ", " <<  trueResult.y << ", " << trueResult.z << ">" << std::endl;
		std::cout << "actual: <" << result.x << ", " <<  result.y << ", " << result.z << ">" << std::endl;
	}
	magnitude = two.magnitude();
	trueResult.x = two.x / magnitude;
	trueResult.y = two.y / magnitude;
	trueResult.z = two.z / magnitude;
	result = two.normalize();
	if(result != trueResult) {
		exitCode = 1;
		std::cout << "Error with the Cartesian normalize function" << std::endl;
		std::cout << "Expected: <" << trueResult.x << ", " <<  trueResult.y << ", " << trueResult.z << ">" << std::endl;
		std::cout << "actual: <" << result.x << ", " <<  result.y << ", " << result.z << ">" << std::endl;
	}
	
	
	//check addition Math
	one = {5,1,3};
	two = {2,2,3};
	trueResult.x = one.x + two.x;
	trueResult.y = one.y + two.y;
	trueResult.z = one.z + two.z; 
	result = one + two;
	if(trueResult != result) {
		exitCode = 1;
		std::cout << "Error with Cartesian + function" << std::endl;
		std::cout << "Expected: <" << trueResult.x << ", " <<  trueResult.y << ", " << trueResult.z << ">" << std::endl;
		std::cout << "actual: <" << result.x << ", " <<  result.y << ", " << result.z << ">" << std::endl;
	}
	one = {3,1,6};
	two = {2.6,2.5,34};
	trueResult.x = one.x + two.x;
	trueResult.y = one.y + two.y;
	trueResult.z = one.z + two.z; 
	result = one + two;
	if(trueResult != result) {
		exitCode = 1;
		std::cout << "Error with Cartesian + function" << std::endl;
		std::cout << "Expected: <" << trueResult.x << ", " <<  trueResult.y << ", " << trueResult.z << ">" << std::endl;
		std::cout << "actual: <" << result.x << ", " <<  result.y << ", " << result.z << ">" << std::endl;
	}
	
	//check scalar Math
	one = {5,1,3};
	two = {2,2,3};
	scalar = 2.0;
	trueResult.x = one.x * scalar;
	trueResult.y = one.y * scalar;
	trueResult.z = one.z * scalar; 
	result = one * scalar;
	if(trueResult != result) {
		exitCode = 1;
		std::cout << "Error with scalar * function" << std::endl;
		std::cout << "Expected: <" << trueResult.x << ", " <<  trueResult.y << ", " << trueResult.z << ">" << std::endl;
		std::cout << "actual: <" << result.x << ", " <<  result.y << ", " << result.z << ">" << std::endl;
	}
	
	scalar = 6.3;
	trueResult.x = two.x * scalar;
	trueResult.y = two.y * scalar;
	trueResult.z = two.z * scalar; 
	result = two * scalar;
	if(trueResult != result) {
		exitCode = 1;
		std::cout << "Error with scalar * function" << std::endl;
		std::cout << "Expected: <" << trueResult.x << ", " <<  trueResult.y << ", " << trueResult.z << ">" << std::endl;
		std::cout << "actual: <" << result.x << ", " <<  result.y << ", " << result.z << ">" << std::endl;
	}
	
	//check cross product
	one = {5,1,3};
	two = {2,2,3};
	trueResult.x = (one.y * two.z) - (one.z * two.y);
	trueResult.y = (one.z * two.x) - (one.x * two.z);
	trueResult.z = (one.x * two.y) - (one.y * two.x);
	result = one * two;
	if(trueResult != result) {
		exitCode = 1;
		std::cout << "Error with cross product (*) function" << std::endl;
		std::cout << "Expected: <" << trueResult.x << ", " <<  trueResult.y << ", " << trueResult.z << ">" << std::endl;
		std::cout << "actual: <" << result.x << ", " <<  result.y << ", " << result.z << ">" << std::endl;
	}
	
	
	one = {2,2,3};
	two = {5,1,3};
	trueResult.x = (one.y * two.z) - (one.z * two.y);
	trueResult.y = (one.z * two.x) - (one.x * two.z);
	trueResult.z = (one.x * two.y) - (one.y * two.x);
	result = one * two;
	if(trueResult != result) {
		exitCode = 1;
		std::cout << "Error with cross product (*) function" << std::endl;
		std::cout << "Expected: <" << trueResult.x << ", " <<  trueResult.y << ", " << trueResult.z << ">" << std::endl;
		std::cout << "actual: <" << result.x << ", " <<  result.y << ", " << result.z << ">" << std::endl;
	}
	
	
	return exitCode;
}
