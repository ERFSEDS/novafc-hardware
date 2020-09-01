#include "StateMachine.hpp"
#include "Logger.hpp"
#include "Configuration.hpp"
#include <iostream>

StateMachine StateMachine::INSTANCE;
void StateMachine::changeState_I(State state) {
	if(stateMap.checkTransition(this->currentState, state) ) {
		std::cout << "switching states" << std::endl;
		this->previousState = this->currentState;
		this->currentState = state;
	}
	else {
		std::cout << "Improper transition" << std::endl;
	}
}
State StateMachine::getCurrentState_I() {
	return this->currentState;
}
State StateMachine::getPreviousState_I() {
	return this->previousState;
}
		
StateMachine::StateMachine() {
	this->currentState = DEFAULT_START_STATE;
	this->previousState = DEFAULT_START_STATE;
	stateMap.setupTransitions();
}
StateMachine::~StateMachine() {

}
void StateMachine::refresh_I() {
	this->stateMap.setupTransitions();
}

StateMap::StateMap() {
	this->setupTransitions();
}
bool StateMap::checkTransition(State currentState, State desiredTransition) {
	return this->nodes[currentState].checkIfPresent(desiredTransition);
}
void StateMap::setupTransitions() {
	this->nodes[UNARMED].addTransition(READY);
	this->nodes[READY].addTransition(UNARMED);
	this->nodes[READY].addTransition(STAGE1POWERED);
	this->nodes[STAGE1POWERED].addTransition(STAGE1COAST);
	if(Configuration::getTwoStageRocket()) {
		this->nodes[STAGE1COAST].addTransition(STAGE2POWERED);
		this->nodes[STAGE2POWERED].addTransition(STAGE2COAST);
		if(Configuration::getDrogueChute()) {
			this->nodes[STAGE2COAST].addTransition(DROGUEPAR);
			this->nodes[DROGUEPAR].addTransition(MAINPAR);
		}
		else {
			this->nodes[STAGE2COAST].addTransition(MAINPAR);
		}
		
	}
	else {
		if(Configuration::getDrogueChute()) {
			this->nodes[STAGE1COAST].addTransition(DROGUEPAR);
			this->nodes[DROGUEPAR].addTransition(MAINPAR);
		}
		else {
			this->nodes[STAGE1COAST].addTransition(MAINPAR);
		}
	}
	this->nodes[MAINPAR].addTransition(LANDED);
	this->nodes[LANDED].addTransition(RESET);
}



StateMachine &StateMachine::GET_INSTANCE() {
	return INSTANCE;
}
void StateMachine::changeState(State state) {
	StateMachine::GET_INSTANCE().changeState_I(state);
}
State StateMachine::getCurrentState() {
	return StateMachine::GET_INSTANCE().getCurrentState_I();
}
State StateMachine::getPreviousState() {
	return StateMachine::GET_INSTANCE().getPreviousState_I();
}
void StateMachine::refresh() {
	return StateMachine::GET_INSTANCE().refresh_I();
}

TransitionLinkedList::TransitionLinkedList() {
	this->head = NULL;
	this->tail = NULL;
}
void TransitionLinkedList::addTransition(State state) {
	ValidTransitionNode * node = new ValidTransitionNode;
	node->validTransition = state;
	node->nextTransition = NULL;
	if(this->head == NULL) {
		this->head = node;
		this->tail = node;
	}
	else {
		this->tail->nextTransition = node;
		this->tail = this->tail->nextTransition;
	}
}
void TransitionLinkedList::removeTransition(State state) {
	if(this->head == NULL) {
		return;
	}
	
	ValidTransitionNode * currentNode = this->head;
	ValidTransitionNode * previousNode = NULL;
	while(true) {
		previousNode = currentNode;
		currentNode = currentNode->nextTransition;
		if(currentNode == NULL) {
			break;
			//no more to check
		}
		if(currentNode->validTransition == state) {
			previousNode->nextTransition = currentNode->nextTransition;
			delete currentNode;
		}
	}
}
bool TransitionLinkedList::checkIfPresent(State state) {
	ValidTransitionNode * nextNode = this->head;
	while(nextNode != NULL) {
		if(nextNode->validTransition == state) {
			return true;
		}
		nextNode = nextNode->nextTransition;
	}
	return false;
}
	


	
