#pragma once
#include <string>

#define NUMBER_OF_STATES 10
#define DEFAULT_START_STATE (UNARMED)
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
	public:
		StateMap();
		bool checkTransition(State currentState, State desiredTransition);
		void setupTransitions();
		void resetTransitions();
};

class StateMachine
{
	public:
		static void changeState(State state);
		static State getCurrentState();
		static State getPreviousState();
		static void refresh();
	private:
		static StateMachine INSTANCE;
		State currentState;
		State previousState;
		StateMap stateMap;
		
		
		static StateMachine &GET_INSTANCE();
		void changeState_I(State state);
		State getCurrentState_I();
		State getPreviousState_I();
		void refresh_I();
	public:
		StateMachine(const StateMachine &state) = delete;

	private:
		StateMachine();
		~StateMachine();
	
};
