#include "rApplication.h"

rApplication::rApplication()
{
    //_world = new artemis::World();
}


rApplication::~rApplication()
{

}

artemis::EntitySystem *rApplication::addSystem(artemis::EntitySystem *sys)
{
    return _world.getSystemManager()->setSystem( sys );
}

artemis::Entity& rApplication::newEntity()
{
    return _world.getEntityManager()->create();
}

void rApplication::init()
{
    _world.getSystemManager()->initializeAll();
}

void rApplication::loop()
{

}

void rApplication::stop()
{

}

artemis::World &rApplication::getWorld()
{
    return _world;
}

void rApplication::step(float dt)
{
   _world.loopStart();
   _world.setDelta(dt);

   artemis::Bag<artemis::EntitySystem*> & bagged = _world.getSystemManager()->getSystems();

   for(int i=0; i< bagged.getCount(); i++) {
       bagged.get(i)->process();
       }

}
