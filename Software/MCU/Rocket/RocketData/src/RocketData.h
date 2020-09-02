/*
 * ProjectCerberus: Nova/RocketData
 * 
 * 
 * 
 * Author: Matthew Gasper
 */
#include "cartesian.h"

class RocketData{
    private:
        cartesian  acceleration, velocity, location, angularPos;
        unsigned short int altitude;

    public:
        void updateData();
        cartesian getAcceleration();
        cartesian getAngularPos();
        cartesian getLocation();
        cartesian getVelocity();
        void getAltitude();
        
        
};