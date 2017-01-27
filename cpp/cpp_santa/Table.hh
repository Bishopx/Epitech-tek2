#ifndef _TABLE_H_
# define _TABLE_H_

#include <string>
#include <iostream>
#include "Object.hh"

class ITable {
public:
    ~ITable();
    virtual void Put(Object * const &) = 0;
    virtual std::string *Look() = 0;
};

class TablePePeNoel : public ITable {
protected:
    bool            free;
    Object          **_obj;
    int             _index;
public:
    TablePePeNoel();
    TablePePeNoel(TablePePeNoel const &);
    TablePePeNoel &operator=(TablePePeNoel const &);
    ~TablePePeNoel();
    virtual void            Put(Object * const &);   
    virtual std::string*    Look();
};

#endif /* !_TABLE_H_ */
