#include <iostream>
#include <string>
#include "Warpsystem.hh"

WarpSystem::QuantumReactor::QuantumReactor() {
	this->_stability = true;
}

bool WarpSystem::QuantumReactor::isStable() {
	return this->_stability;
}

void WarpSystem::QuantumReactor::setStability(bool  stability) {
	this->_stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *core) {
	this->_coreReactor = core;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor() {
	return this->_coreReactor;
}