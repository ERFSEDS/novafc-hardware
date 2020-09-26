#pragma once
#include <cmath>
struct cartesian{
    float dimension[3];
    
    float magnitude() {
    	return sqrt( (dimension[0]*dimension[0]) + (dimension[1]*dimension[1]) + (dimension[2]*dimension[2]) );
    }
};
