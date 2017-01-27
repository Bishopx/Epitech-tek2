
#ifndef ERRORS_HPP_
#define ERRORS_HPP_

#include <string>
#include <iostream>

class NasaError : std::exception
{
    public:
        NasaError(std::string const &message,
                std::string const &component = "Unknown") throw();
        virtual ~NasaError() throw();
        std::string const &getComponent() const;
    private:
        std::string _message;
        std::string _component;        
};

class MissionCriticalError : public NasaError
{
    public:
        MissionCriticalError(std::string const &message,
                std::string const &component = "Unknown");
};

class LifeCriticalError : public NasaError
{
    public:
        LifeCriticalError(std::string const &message,
                std::string const &component = "Unknown");
};

class UserError : public NasaError
{
    public:
        UserError(std::string const &message,
                std::string const &component = "Unknown");
};

class CommunicationError : public NasaError
{
    public:
        CommunicationError(std::string const &message);
};

#endif
