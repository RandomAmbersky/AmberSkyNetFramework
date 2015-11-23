#include "rEntityManager.h"
#include "rEntity.h"

rEntityManager::rEntityManager()
{
    _nextAvailableId = 0;
    _count = 0;
    _uniqueEntityId = 0;
    _totalCreated = 0;
    _totalRemoved = 0;
}

rEntity* rEntityManager::create()
{

    rEntity* e = new rEntity(this, _nextAvailableId++);
    e->setUniqueId(_uniqueEntityId++);
    _count++;
    _totalCreated++;

    return e;

}

void rEntityManager::addComponent(rEntity *e, rComponent *c)
{

}

void rEntityManager::removeComponent(rEntity *e, asnComponentType type)
{

}

rComponent *rEntityManager::getComponent(rEntity *e, asnComponentType type)
{

}
