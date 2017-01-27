#ifndef _CONVERYORBELT_H_
# define _CONVERYORBELT_H_

#include <string>
#include <iostream>
#include "Object.hh"

class IConveyorBelt {
public:
    virtual ~IConveyorBelt();
    virtual Object  *Take() = 0;
    virtual void    Put(Object * const &, int) = 0;
    virtual Object *In() = 0;
    virtual void    Out(Object *obj) = 0;
    virtual std::string*    Look() = 0;    
};

class ConveyorBeltPePeNoel : public IConveyorBelt {
protected:
    bool            free;
    Object          **_obj;
    int             _index;
public:
    ConveyorBeltPePeNoel();
    virtual ~ConveyorBeltPePeNoel();
    ConveyorBeltPePeNoel(ConveyorBeltPePeNoel const &);
    ConveyorBeltPePeNoel &operator=(ConveyorBeltPePeNoel const &);
    virtual Object      *Take();
    virtual void        Put(Object * const &, int);
    virtual Object      *In();
    virtual void        Out(Object *obj);
    virtual std::string*    Look();    
};

#endif /* !_CONVERYORBELTP_H_ */
