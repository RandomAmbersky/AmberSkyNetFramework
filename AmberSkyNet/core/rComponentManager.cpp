#include "rComponentManager.h"
#include <iostream>

class rComponentType
{
public:
    int id;
    std::bitset<BITSIZE> bit;
};

rComponentManager::rComponentManager()
{
    _next_bit = 1;
    _next_id = 1;
}

rComponentManager::~rComponentManager()
{

}

long rComponentManager::getTypeId(const std::type_info &c)
{

    rComponentType* my_type;
    std::map<const std::type_info*, rComponentType*>::iterator it = _componentTypes.find(&c);

    if ( it == _componentTypes.end() )
    {
        my_type = new rComponentType();
        my_type->bit = _next_bit;
        _next_bit = _next_bit << 1;
        my_type->id = _next_id++;
        _componentTypes[&c] = my_type;
    }
    else my_type = it->second;

    std::cout << "create component" << &c << " " << my_type->id << std::endl;
    return my_type->id;
}

rComponent *rComponentManager::getComponent(rEntity *e, const long type)
{

}
