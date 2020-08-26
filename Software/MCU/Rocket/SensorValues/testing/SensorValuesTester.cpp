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

unsigned short int testValueX = 0;
unsigned short int testValueY = 0;
unsigned short int testValueZ = 0;

int testResult = 0;

void testValuePass(){
    if(holder.x != testValue.x){
        std::cout << "[ERROR] Test failed at " << testNumber << " for x" << std::endl;
        testResult = 1;
    }
    if(holder.y != testValue.y){
        std::cout << "[ERROR] Test failed at " << testNumber << " for y" << std::endl;
        testResult = 1;
    }
    if(holder.z != testValue.z){
        std::cout << "[ERROR] Test failed at " << testNumber << " for z" << std::endl;
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
            std::cout << "[ERROR] Pyro Test Failed for iteration:[ " << i <<  "] on pyroOne" << std::endl;
            testResult = 1;
        }
        if(run.checkPyro(2) != i){
            std::cout << "[ERROR] Pyro Test Failed for iteration:[ " << i << " ] on pyroTwo" << std::endl;
            testResult = 1;
        }
    }

    //run.firePyro(one;
    //run.firePyro(two);

    return testResult;
}
