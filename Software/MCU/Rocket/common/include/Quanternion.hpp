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
    	a /= magnitude;
    	i /= magnitude;
    	j /= magnitude;
    	k /= magnitude;
    }
    Quanternion operator+(Quanternion& other) {
		Quanternion returnVal;
		returnVal.a = a + other.a;
		returnVal.i = i + other.i;
		returnVal.j = j + other.j;
		returnVal.k = k + other.k;
		return returnVal;
    }
    
    Quanternion operator*(Quanternion& other) { 
    	Quanternion returnVal;
		returnVal.a = (a * other.a) - (i * other.i) - (j * other.j) - (k * other.k);
		returnVal.i = (a * other.i) + (i * other.a) + (j * other.k) - (k * other.j);
		returnVal.j = (a * other.j) - (i * other.k) + (j * other.a) + (k * other.i);
		returnVal.k = (a * other.k) + (i * other.j) - (j * other.i) + (k * other.a);
    	return returnVal;
    }
    
    Quanternion operator*(float& scalar) { 
    	Quanternion returnVal;
		returnVal.a = a * scalar;
		returnVal.i = i * scalar;
		returnVal.j = j * scalar;
		returnVal.k = k * scalar;
    	return returnVal;
    }
    
    bool operator==(Quanternion& other) {
		return (a == other.a) && (i == other.i) && (j == other.j) || (k == other.k) ;
    }
    bool operator!=(Quanternion& other) {
		return (a != other.a) || (i != other.i) || (j != other.j) || (k != other.k);
    }
};
