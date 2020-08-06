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
        bool parachutes, pyro;

    public:
        void updateData();
};