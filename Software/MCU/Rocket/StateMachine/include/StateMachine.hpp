#pragma once
#include <string>
#include "Configuration.hpp"
#include "Logger.hpp"
#include "State.hpp"
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
