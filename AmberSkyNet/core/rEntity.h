#ifndef RENTITY_H
#define RENTITY_H

#include "rBase.h"

#include <bitset>
#include "BitSize.h"

class rComponent;
class rEntityManager;

class rEntity
{
public:
    rEntity(rEntityManager* entityManager, int id);
    ~rEntity();

    void addComponent(rComponent* c);
    void removeComponent(asnComponentType type);
    rComponent* getComponent(asnComponentType type);

    void refresh();

    long int getUniqueId();
    int getId();

    void setUniqueId(long int uniqueId);

private:
    int _id; // id - entity can be deleted and created without new() and delete() command
    long int _uniqueId; // unique id

    std::bitset<BITSIZE> _typeBits; // components in the entity
    std::bitset<BITSIZE> _systemBits; // systems interested this entity

    rEntityManager* _entityManager;

};

#endif // RENTITY_H
