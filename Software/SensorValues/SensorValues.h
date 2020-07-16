/*
 * ProjectCerberus: Nova/SensorValues
 * 
 * This class is to act like a Storage class for sensor values
 * 
 * Author: Matthew Gasper
 */
#include "cartesian.h"

class SensorValues{
    
    private:
        cartesian  acceleration, velocity, location, angularPos;
        bool pyro[2];

    public:
        void setAcceleration(cartesian data);
        void setVelocity(cartesian data);
        void setLocation(cartesian data);
        void setAngularPos(cartesian data);

        cartesian getAcceleration();
        cartesian getVelocity();
        cartesian getLocation();
        cartesian getAngularPos();
        
        void setPyro();
        bool checkPyro();
        void firePyro();
};