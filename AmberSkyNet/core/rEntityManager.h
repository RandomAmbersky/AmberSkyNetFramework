#ifndef RENTITYMANAGER_H
#define RENTITYMANAGER_H

#include "rBase.h"

class rEntity;
class rComponent;

class rEntityManager
{
public:
    rEntityManager();
    rEntity* create();

    void addComponent(rEntity* e, rComponent* c);
    void removeComponent(rEntity* e, asnComponentType type);
    rComponent* getComponent(rEntity* e, asnComponentType type);

private:
    int _nextAvailableId;
    int _count;
    long int _uniqueEntityId;
    long int _totalCreated;
    long int _totalRemoved;
};

#endif // RENTITYMANAGER_H
