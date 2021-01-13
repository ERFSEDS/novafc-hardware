#pragma once
#include "cartesian.h"
#include <iostream>
struct Matrix {
	float values[3][3];
	
    Matrix operator+(const Matrix& other) {
    	Matrix returnMatrix;
    	for(int i = 0; i < 3; i++) {
    		for(int j = 0; j < 3; j++) {
    			returnMatrix.values[i][j] = values[i][j] + other.values[i][j];
    		}
    	}
    	return returnMatrix;
    }
    
    Cartesian operator*(const Cartesian& vector) { 
    	Cartesian returnVector;
    	returnVector.x = values[0][0] * vector.x + values[0][1] * vector.x + values[0][2] * vector.x;
    	returnVector.y = values[1][0] * vector.y + values[1][1] * vector.y + values[1][2] * vector.y;
    	returnVector.z = values[2][0] * vector.z + values[2][1] * vector.z + values[2][2] * vector.z;
    	returnVector.unNAN();
    	return returnVector;
    }
    
    
    bool operator==(const Matrix& other) {
    	for(int i = 0; i < 3; i++) {
    		for(int j = 0; j < 3; j++) {
    			if( values[i][j] != other.values[i][j]) {
    				return false;
    			}
    		}
    	}
    	return true;
    }
    bool operator!=(const Matrix& other) {
    	for(int i = 0; i < 3; i++) {
    		for(int j = 0; j < 3; j++) {
    			if( values[i][j] != other.values[i][j]) {
    				return true;
    			}
    		}
    	}
    	return false;
    }
    
};
