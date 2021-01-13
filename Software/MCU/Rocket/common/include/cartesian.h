#pragma once
#include <cmath>
struct Cartesian{
    float x;
    float y;
    float z;
    
    float magnitude() {
    	return sqrt( (x*x) + (y*y) + (z*z) );
    }
    void unNAN() {
    	if(x != x) {
    		x = 0;
    	}
    	if(y != y) {
    		y = 0;
    	}
    	if(z != z) {
    		z = 0;
    	}
    }
    Cartesian normalize() {
    	Cartesian returnVal;
    	float magnitude = this->magnitude();
    	returnVal.x = x / magnitude;
    	returnVal.y = y / magnitude;
    	returnVal.z = z / magnitude;
    	returnVal.unNAN();
    	return returnVal;
    }
    Cartesian operator+(const Cartesian& other) {
		Cartesian returnVal;
		returnVal.x = x + other.x;
		returnVal.y = y + other.y;
		returnVal.z = z + other.z;
		return returnVal;
    }
    
    Cartesian operator*(const float& scalar) { 
    	Cartesian returnVal;
    	returnVal.x = x * scalar;
    	returnVal.y = y * scalar;
    	returnVal.z = z * scalar;
    	returnVal.unNAN();
    	return returnVal;
    }
    
    Cartesian operator*(const Cartesian& other) { 
    	Cartesian returnVal;
    	returnVal.x = (y * other.z) - (z * other.y);
    	returnVal.y = (z * other.x) - (x * other.z);
    	returnVal.z = (x * other.y) - (y * other.x);
    	returnVal.unNAN();
    	return returnVal;
    }
    bool operator==(const Cartesian& other) {
		return (x == other.x) && (y == other.y) && (z == other.z);
    }
    bool operator!=(const Cartesian& other) {
		return (x != other.x) || (y != other.y) || (z != other.z);
    }
};
