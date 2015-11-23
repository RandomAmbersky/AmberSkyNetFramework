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

    rComponentType* my_type = _componentTypes.find(&c)->second;

    if(my_type == NULL) {
        my_type = new rComponentType();
        my_type->bit = _next_bit;
        _next_bit = _next_bit << 1;
        my_type->id = _next_id++;
        _componentTypes[&c] = my_type;
    }

    //std::cout << "create component" << &c << " " << my_type->id << std::endl;
    return my_type->id;
}

rComponent *rComponentManager::getComponent(rEntity *e, const long type)
{

}
