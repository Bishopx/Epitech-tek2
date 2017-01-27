#include "Errors.hpp"

NasaError::NasaError(std::string const &message, std::string const &component) throw() :
	_message(message), _component(component) {
}

NasaError::~NasaError() throw() {

}

std::string const &NasaError::getComponent() const {
	return _component;
}

MissionCriticalError::MissionCriticalError(std::string const &message, std::string const &component) :
	NasaError(message, component)  {
}

LifeCriticalError::LifeCriticalError(std::string const &message, std::string const &component) :
	NasaError(message, component)  {
}

UserError::UserError(std::string const &message, std::string const &component) :
	NasaError(message, component) {
}

CommunicationError::CommunicationError(std::string const &message) :
	NasaError(message, "CommunicationDevice") {
}