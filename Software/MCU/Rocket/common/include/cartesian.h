#pragma once
#include <cmath>
struct Cartesian{
    float x;
    float y;
    float z;
    
    float magnitude() {
    	return sqrt( (x*x) + (y*y) + (z*z) );
    }
    Cartesian normalize() {
    	Cartesian returnVal;
    	float magnitude = this->magnitude();
    	returnVal.x = x / magnitude;
    	returnVal.y = y / magnitude;
    	returnVal.z = z / magnitude;
    	return returnVal;
    }
    Cartesian operator+(Cartesian& other) {
		Cartesian returnVal;
		returnVal.x = x + other.x;
		returnVal.y = y + other.y;
		returnVal.z = z + other.z;
		return returnVal;
    }
    
    Cartesian operator*(float& scalar) { 
    	Cartesian returnVal;
    	returnVal.x = x * scalar;
    	returnVal.y = y * scalar;
    	returnVal.z = z * scalar;
    	return returnVal;
    }
    
    Cartesian operator*(Cartesian& other) { 
    	Cartesian returnVal;
    	returnVal.x = (y * other.z) - (z * other.y);
    	returnVal.y = (z * other.x) - (x * other.z);
    	returnVal.z = (x * other.y) - (y * other.x);
    	return returnVal;
    }
    bool operator==(Cartesian& other) {
		return (x == other.x) && (y == other.y) && (z == other.z);
    }
    bool operator!=(Cartesian& other) {
		return (x != other.x) || (y != other.y) || (z != other.z);
    }
};
