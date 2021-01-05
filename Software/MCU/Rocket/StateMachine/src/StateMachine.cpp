#include "StateMachine.hpp"
#include "Logger.hpp"
#include "Configuration.hpp"
#include <iostream>
#include <sstream>

void StateMachine::changeState(State state) {
	if(stateMap.checkTransition(this->currentState, state) ) {
		std::stringstream ss;
		this->previousState = this->currentState;
		this->currentState = state;
		ss << "Switching State from " << (int)previousState << " to " << (int)currentState;
		Logger::Event(ss.str());
	}
	else {
		std::stringstream ss;
		ss << "Illegal state change from " << (int)currentState << " to " << (int)state;
		Logger::Warning(ss.str());
	}
}
State StateMachine::getCurrentState() {
	return this->currentState;
}
State StateMachine::getPreviousState() {
	return this->previousState;
}
		
StateMachine::StateMachine(Configuration& config) : config(config), stateMap(config) {
	this->currentState = DEFAULT_START_STATE;
	this->previousState = DEFAULT_START_STATE;
	stateMap.setupTransitions();
}
StateMachine::~StateMachine() {

}
void StateMachine::refresh() {
	this->stateMap.resetTransitions(); 
	this->stateMap.setupTransitions();
}

StateMap::StateMap(Configuration& config) : config(config){
	setupTransitions();
}
bool StateMap::checkTransition(State currentState, State desiredTransition) {
	return this->nodes[(int)currentState].checkIfPresent(desiredTransition);
}
void StateMap::setupTransitions() {
	this->nodes[(int)UNARMED].addTransition(READY);
	this->nodes[(int)READY].addTransition(UNARMED);
	this->nodes[(int)READY].addTransition(STAGE1POWERED);
	this->nodes[(int)STAGE1POWERED].addTransition(STAGE1COAST);
	if(config.getTwoStageRocket()) {
		this->nodes[(int)STAGE1COAST].addTransition(STAGE2POWERED);
		this->nodes[(int)STAGE2POWERED].addTransition(STAGE2COAST);
		if(config.getDrogueChute()) {
			this->nodes[(int)STAGE2COAST].addTransition(DROGUEPAR);
			this->nodes[(int)DROGUEPAR].addTransition(MAINPAR);
		}
		else {
			this->nodes[(int)STAGE2COAST].addTransition(MAINPAR);
		}
		
	}
	else {
		if(config.getDrogueChute()) {
			this->nodes[(int)STAGE1COAST].addTransition(DROGUEPAR);
			this->nodes[(int)DROGUEPAR].addTransition(MAINPAR);
		}
		else {
			this->nodes[(int)STAGE1COAST].addTransition(MAINPAR);
		}
	}
	this->nodes[(int)MAINPAR].addTransition(LANDED);
	this->nodes[(int)LANDED].addTransition(RESET);

}

void StateMap::resetTransitions() {
	for(int i = 0; i < NUMBER_OF_STATES; i++) {
		this->nodes[i].removeAll();
	}
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
		this->tail = head;
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
	
void TransitionLinkedList::removeAll() {
	if(this->head == NULL) {
		return;
	}
	ValidTransitionNode * thisNode = this->head;
	ValidTransitionNode * previousNode = NULL;
	while(thisNode != NULL) {
		previousNode = thisNode;
		thisNode = thisNode->nextTransition;
		delete previousNode;
	}
	this->head = NULL;
	this->tail = NULL;
}
