#ifndef RCOMPONENTMANAGER_H
#define RCOMPONENTMANAGER_H

#include "rBase.h"

#include <typeinfo>
#include <map>
#include <bitset>
#include "BitSize.h"

class rComponent;
class rEntity;
class rComponentType_priv;

class rComponentManager
{
public:
    rComponentManager();
    ~rComponentManager();
    asnComponentType getTypeId(const std::type_info &c);
    rComponent* getComponent( rEntity* e, const long type );
private:
    std::map<const std::type_info*, rComponentType_priv*> _componentTypes;
    std::bitset<BITSIZE> _next_bit;
    long _next_id;
};

#endif // RCOMPONENTMANAGER_H
