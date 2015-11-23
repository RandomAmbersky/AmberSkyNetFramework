#include "rEntity.h"
#include "rEntityManager.h"

rEntity::rEntity(rEntityManager* entityManager,int id)
{
    _entityManager = entityManager;
    _id = id;
}

rEntity::~rEntity()
{

}

void rEntity::addComponent(rComponent *c)
{
    _entityManager->addComponent( this, c);
}

void rEntity::removeComponent(asnComponentType type)
{
    _entityManager->removeComponent( this, type );
}

rComponent *rEntity::getComponent(asnComponentType type)
{
    return _entityManager->getComponent( this, type );
}

void rEntity::refresh()
{

}

int rEntity::getId() {
  return _id;
}

long int rEntity::getUniqueId() {
  return _uniqueId;
}

void rEntity::setUniqueId(long int uniqueId) {
  _uniqueId = uniqueId;
}
