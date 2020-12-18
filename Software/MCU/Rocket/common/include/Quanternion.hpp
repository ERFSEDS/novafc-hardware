#pragma once
#include "cartesian.h"

struct Quanternion {
	float a;
	float i;
	float j;
	float k;
	
	float magnitude() {
    	return sqrt( (a*a) + (i*i) + (j*j) + (k*k) );
    }
    void normalize() {
    	float magnitude = this->magnitude();
    	this->a /= magnitude;
    	this->i /= magnitude;
    	this->j /= magnitude;
    	this->k /= magnitude;
    }
    Quanternion operator+(const Quanternion& other) {
		Quanternion returnVal;
		returnVal.a = a + other.a;
		returnVal.i = i + other.i;
		returnVal.j = j + other.j;
		returnVal.k = k + other.k;
		return returnVal;
    }
    
    Quanternion operator*(const Quanternion& other) { 
    	Quanternion returnVal;
		returnVal.a = (a * other.a) - (i * other.i) - (j * other.j) - (k * other.k);
		returnVal.i = (a * other.i) + (i * other.a) + (j * other.k) - (k * other.j);
		returnVal.j = (a * other.j) - (i * other.k) + (j * other.a) + (k * other.i);
		returnVal.k = (a * other.k) + (i * other.j) - (j * other.i) + (k * other.a);
    	return returnVal;
    }
    
    Quanternion operator*(const float& scalar) { 
    	Quanternion returnVal;
		returnVal.a = a * scalar;
		returnVal.i = i * scalar;
		returnVal.j = j * scalar;
		returnVal.k = k * scalar;
    	return returnVal;
    }
    
    bool operator==(const Quanternion& other) {
		return (a == other.a) && (i == other.i) && (j == other.j) || (k == other.k) ;
    }
    bool operator!=(const Quanternion& other) {
		return (a != other.a) || (i != other.i) || (j != other.j) || (k != other.k);
    }
    
    Cartesian const getCartesian() {
    	Cartesian returnVal;
    	returnVal.x = i;
    	returnVal.y = j;
    	returnVal.z = k;
    	return returnVal;
    }
    void setCartesian(const Cartesian vector) {
    	a = 0;
    	i = vector.x;
    	j = vector.y;
    	k = vector.z;
    }
    
    Quanternion inverse() {
    	float dividend = (a*a)+(i*i)+(j*j)+(k*k);
    	Quanternion returnVal;
    	returnVal.a = a/dividend;
    	returnVal.i = i/dividend;
    	returnVal.j = j/dividend;
    	returnVal.k = k/dividend;
    	return returnVal;
    }
    /*
    	0,0  0,1  0,2
    	1,0  1,1  1,2
    	2,0  2,1  2,2
    */
    void toRotationMatrix(float rotationMatrix[3][3]) {
    	rotationMatrix[0][0] = 1-2*(j*j)-2*(k*k);
    	rotationMatrix[0][1] = 2*i*j-2*k*a;
    	rotationMatrix[0][2] = 2*i*k+2*i*a;
    	rotationMatrix[1][0] = 2*i*j+2*k*a;		
    	rotationMatrix[1][1] = 1-2*(i*i)-2*(k*k);
    	rotationMatrix[1][2] = 2*j*k-2*i*a;
    	rotationMatrix[2][0] = 2*i*k-2*j*a; 				
    	rotationMatrix[2][1] = 2*j*k+2*i*a;
    	rotationMatrix[2][2] = 1-2*(i*i)-2*(j*j);
    }
};
