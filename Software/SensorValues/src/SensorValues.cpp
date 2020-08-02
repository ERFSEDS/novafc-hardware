/*
 * ProjectCerberus: Nova/SensorValues
 * 
 * This class is to act like a Storage class for sensor values
 * 
 * Author: Matthew Gasper
 */
#include "SensorValues.h"

class SensorValues{
    private:
        cartesian  acceleration, velocity, location, angularPos;
        bool pyro[2];

    public:
        void setAcceleration(cartesian data){
            acceleration = data;
        }
        void setVelocity(cartesian data){
            velocity = data;
        }
        void setLocation(cartesian data){
            location = data;
        }
        void setAngularPos(cartesian data){
            angularPos = data;
        }

        cartesian getAcceleration(){
            return acceleration;
        }
        cartesian getVelocity(){
            return velocity;
        }
        cartesian getLocation(){
            return location;
        }
        cartesian getAngularPos(){
            return angularPos;
        }
        
        void setPyro(int cmd, bool state){
            enum pyros{one = 1, two = 2};
            switch(cmd){
                case one:
                    pyro[0] = state;
                    break;
                case two:
                    pyro[1] = state;
                    break;
            }
        }
        bool checkPyro(int cmd){
            enum pyros{one = 1, two = 2};
            switch(cmd){
                case one:
                    return pyro[0];
                    break;
                case two:
                    return pyro[1];
                    break;
            }
        }
        void firePyro(int cmd){
            enum pyros{one = 1, two = 2};
            switch(cmd){
                case one:
                    //Insert command to fire pyro one
                    break;
                case two:
                    //Insert command to fire pyro two
                    break;
            }
        }
};