#ifndef RCOMPONENTMANAGER_H
#define RCOMPONENTMANAGER_H

#include <typeinfo>
#include <map>
#include <bitset>
#include "BitSize.h"

class rComponent;
class rComponentType;
class rEntity;

class rComponentManager
{
public:
    rComponentManager();
    ~rComponentManager();
    long getTypeId(const std::type_info &c);
    rComponent* getComponent( rEntity* e, const long type );
private:
    std::map<const std::type_info*, rComponentType*> _componentTypes;
    std::bitset<BITSIZE> _next_bit;
    long _next_id;
};

#endif // RCOMPONENTMANAGER_H
