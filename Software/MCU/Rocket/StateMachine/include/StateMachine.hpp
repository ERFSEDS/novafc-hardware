#pragma once
#include <string>
#include "Configuration.hpp"
#include "Logger.hpp"
#define NUMBER_OF_STATES 9
#define DEFAULT_START_STATE (UNARMED)
enum State
{
	UNARMED = 0,
	READY = 1,
	STAGE1POWERED = 2,
	STAGE1COAST = 3,
	STAGE2POWERED = 4,
	STAGE2COAST = 5,
	DESCENT = 6,
	LANDED = 7,
	RESET = 8
	
};

struct ValidTransitionNode {
	State validTransition;
	ValidTransitionNode * nextTransition;
};
class TransitionLinkedList {
	private:
		ValidTransitionNode * head;
		ValidTransitionNode * tail;
	public:
		TransitionLinkedList();
		void addTransition(State state);
		void removeTransition(State state);
		bool checkIfPresent(State state);
		void removeAll();
		void print();
	
};
class StateMap {
	private:
		TransitionLinkedList nodes[NUMBER_OF_STATES];
		Configuration& config;
	public:
		StateMap(Configuration& config);
		bool checkTransition(State currentState, State desiredTransition);
		void setupTransitions();
		void resetTransitions();
};

class StateMachine
{
	public:
  StateMachine(Configuration& config, Logger& logger);
		~StateMachine();
		void changeState(State state);
		State getCurrentState();
		State getPreviousState();
		void refresh();
	private:
		Configuration& config;
  Logger& logger;
		State currentState;
		State previousState;
		StateMap stateMap;
	
};
