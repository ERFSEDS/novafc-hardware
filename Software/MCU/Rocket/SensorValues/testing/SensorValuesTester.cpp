/*
 * ProjectCerberus: Nova/SensorValues
 * 
 * This file is for the testing of SensorValues Class
 * 
 * Author: Matthew Gasper
 */
#include <iostream>
#include "SensorValues.h"
#include "cartesian.h"

//Yes I know.....
cartesian testValue;
cartesian holder;
int testNumber = 0;

int testValueX = 0;
int testValueY = 0;
int testValueZ = 0;

int testResult = 0;

void testValuePass(){
    if(holder.x != testValue.x){
        std::cout << "[ERROR] Test failed at %d for x /n",testNumber;
        testResult = 1;
    }
    if(holder.y != testValue.y){
        std::cout << "[ERROR] Test failed at %d for y /n",testNumber;
        testResult = 1;
    }
    if(holder.z != testValue.z){
        std::cout << "[ERROR] Test failed at %d for z /n",testNumber;
        testResult = 1;
    }  
}

void setTestValues( unsigned short int i, unsigned short int j, unsigned short int k){
    testValue.x = i;
    testValue.y = j;
    testValue.z = k;
}

int main(){
    SensorValues run;
    setTestValues(testValueX, testValueY, testValueZ);

/*##########[ Acceleration TEST ]##########*/
    run.setAcceleration(testValue);
    holder = run.getAcceleration();
    testValuePass();

/*##########[ Velocity TEST ]##########*/
    run.setVelocity(testValue);
    holder = run.getVelocity();
    testValuePass();

/*##########[ Location TEST ]##########*/
    run.setLocation(testValue);
    holder = run.getLocation();
    testValuePass();

/*##########[ AngularPos TEST ]##########*/
    run.setAngularPos(testValue);
    holder = run.getAngularPos();
    testValuePass();

/*##########[ PYRO TEST ]##########*/
    for(int i=0; i<2; i++){
        run.setPyro(1,i);
        run.setPyro(2,i);

        if(run.checkPyro(1) != i){
            std::cout << ("[ERROR] Pyro Test Failed for iteration:[ %d ] on pyroOne", i);
            testResult = 1;
        }
        if(run.checkPyro(2) != i){
            std::cout << ("[ERROR] Pyro Test Failed for iteration:[ %d ] on pyroTwo", i);
            testResult = 1;
        }
    }

    //run.firePyro(one;
    //run.firePyro(two);

    return testResult;
}