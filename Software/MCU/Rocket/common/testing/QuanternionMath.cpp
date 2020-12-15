#include "Quanternion.hpp"
#include <cmath>
#include <iostream>
int main() {
	Quanternion one = {1, 2, 3, 4};
	Quanternion two = {3, 4, 5, 6};
	Quanternion result, trueResult;
	int exitCode = 0;
	float scalar;
	
	//check magnitude function
	float magnitude = one.magnitude();
	float trueMagnitude = sqrt( (one.a * one.a) + (one.i * one.i) + (one.j * one.j) + (one.k * one.k));
	if(magnitude != trueMagnitude) {
		exitCode = 1;
		std::cout << "Error with Cartesian magnitude function" << std::endl;
		std::cout << "Expected: " << trueMagnitude << std::endl;	
		std::cout << "Actual"  << magnitude << std::endl;
	}
	magnitude = two.magnitude();
	trueMagnitude = sqrt( (two.a * two.a) + (two.i * two.i) + (two.j * two.j) + (two.k * two.k));
	if(magnitude != trueMagnitude) {
		exitCode = 1;
		std::cout << "Error with Cartesian magnitude function" << std::endl;
		std::cout << "Expected: " << trueMagnitude << std::endl;	
		std::cout << "Actual"  << magnitude << std::endl;
	}
	
	
	//check equals and not equal function
	one = {1,2,3,4};
	two = {1,2,3,4};
	
	if( !(one == two) ) {
		exitCode = 1;
		std::cout << "Error with ==" << std::endl;
	}
	if( one != two ) {
		exitCode = 1;
		std::cout << "Error with !=" << std::endl;
	}
	
	
	//check addition Math
	one = {5,1,3,6};
	two = {2,2,3,6.3};
	trueResult.a = one.a + two.a;
	trueResult.i = one.i + two.i;
	trueResult.j = one.j + two.j; 
	trueResult.k = one.k + two.k; 
	result = one + two;
	if(trueResult != result) {
		exitCode = 1;
		std::cout << "Error with Cartesian + function" << std::endl;
		std::cout << "Expected: <" << trueResult.a << ", " <<  trueResult.i << ", " << trueResult.j << ", " << trueResult.k << ">" << std::endl;
		std::cout << "actual: <" << result.a << ", " <<  result.i << ", " << result.j << ", " << result.k << ">" << std::endl;
	}
	one = {3,1,6,5.2};
	two = {2.6,2.5,34,6.5};
	trueResult.a = one.a + two.a;
	trueResult.i = one.i + two.i;
	trueResult.j = one.j + two.j; 
	trueResult.k = one.k + two.k; 
	result = one + two;
	if(trueResult != result) {
		exitCode = 1;
		std::cout << "Error with Cartesian + function" << std::endl;
		std::cout << "Expected: <" << trueResult.a << ", " <<  trueResult.i << ", " << trueResult.j << ", " << trueResult.k << ">" << std::endl;
		std::cout << "actual: <" << result.a << ", " <<  result.i << ", " << result.j << ", " << result.k << ">" << std::endl;
	}
	
	//check scalar Math
	one = {5,1,3,9};
	two = {5,2,3,1};
	scalar = 2.0;
	trueResult.a = one.a * scalar;
	trueResult.i = one.i * scalar;
	trueResult.j = one.j * scalar;
	trueResult.k = one.k * scalar;  
	result = one * scalar;
	if(trueResult != result) {
		exitCode = 1;
		std::cout << "Error with scalar * function" << std::endl;
		std::cout << "Expected: <" << trueResult.a << ", " <<  trueResult.i << ", " << trueResult.j << ", " << trueResult.k << ">" << std::endl;
		std::cout << "actual: <" << result.a << ", " <<  result.i << ", " << result.j << ", " << result.k << ">" << std::endl;
	}
	
	scalar = 6.3;
	trueResult.a = two.a * scalar;
	trueResult.i = two.i * scalar;
	trueResult.j = two.j * scalar; 
	trueResult.k = two.k * scalar;  
	result = two * scalar;
	if(trueResult != result) {
		exitCode = 1;
		std::cout << "Error with scalar * function" << std::endl;
		std::cout << "Expected: <" << trueResult.a << ", " <<  trueResult.i << ", " << trueResult.j << ", " << trueResult.k << ">" << std::endl;
		std::cout << "actual: <" << result.a << ", " <<  result.i << ", " << result.j << ", " << result.k << ">" << std::endl;
	}
	
	//check cross product
	one = {5,1,3,9};
	two = {5,2,3,1};
	trueResult.a = (one.a * two.a) + (-one.i * two.i) + (-one.j * two.j) + (-one.k * two.k);
	trueResult.i = (one.a * two.i) + (one.i * two.a) + (one.j * two.k) + (-one.k * two.j);
	trueResult.j = (one.a * two.j) + (-one.i * two.k) + (one.j * two.a) + (one.k * two.i);
	trueResult.k = (one.a * two.k) + (one.i * two.j) + (-one.j * two.i) + (one.k * two.a);
	result = one * two;
	if(trueResult != result) {
		exitCode = 1;
		std::cout << "Error with product (*) function" << std::endl;
		std::cout << "one: <" << one.a << ", " <<  one.i << ", " << one.j << ", " << one.k << ">" << std::endl;
		std::cout << "two: <" << two.a << ", " <<  two.i << ", " << two.j << ", " << two.k << ">" << std::endl;
		std::cout << "Expected: <" << trueResult.a << ", " <<  trueResult.i << ", " << trueResult.j << ", " << trueResult.k << ">" << std::endl;
		std::cout << "actual: <" << result.a << ", " <<  result.i << ", " << result.j << ", " << result.k << ">" << std::endl;
	}
	
	
	
	two = {5,1,3,9};
	one = {5,2,3,1};
	trueResult.a = (one.a * two.a) + (-one.i * two.i) + (-one.j * two.j) + (-one.k * two.k);
	trueResult.i = (one.a * two.i) + (one.i * two.a) + (one.j * two.k) + (-one.k * two.j);
	trueResult.j = (one.a * two.j) + (-one.i * two.k) + (one.j * two.a) + (one.k * two.i);
	trueResult.k = (one.a * two.k) + (one.i * two.j) + (-one.j * two.i) + (one.k * two.a);
	result = one * two;
	if(trueResult != result) {
		exitCode = 1;
		std::cout << "Error with product (*) function" << std::endl;
		std::cout << "one: <" << one.a << ", " <<  one.i << ", " << one.j << ", " << one.k << ">" << std::endl;
		std::cout << "two: <" << two.a << ", " <<  two.i << ", " << two.j << ", " << two.k << ">" << std::endl;
		std::cout << "Expected: <" << trueResult.a << ", " <<  trueResult.i << ", " << trueResult.j << ", " << trueResult.k << ">" << std::endl;
		std::cout << "actual: <" << result.a << ", " <<  result.i << ", " << result.j << ", " << result.k << ">" << std::endl;
	}
	
	
	return exitCode;
}
