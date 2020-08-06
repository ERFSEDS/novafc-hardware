#pragma once
#include <string>

enum State
{
	UNARMED = 0,
	READY = 1,
	STAGE1POWERED = 2,
	STAGE1COAST = 3,
	STAGE2POWERED = 4,
	STAGE2COAST = 5,
	DROGUEPAR = 6,
	MAINPAR = 7,
	LANDED = 8,
	RESET = 9
};

class StateMachine
{
private:
	State currentState;
	int switchFailed; // Is for testing purposes
	int switchConfirmed; // Is for testing purposes
	int attempts; // Is for testing purposes
public:
	StateMachine();
	void switchState(State state);
	void confirmState(State state);
	void failedState(State state);
	void testFinalize(int version, int type); // Is for testing purposes
};
