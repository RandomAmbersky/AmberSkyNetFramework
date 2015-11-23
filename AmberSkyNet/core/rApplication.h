#ifndef RAPPLICATION_H
#define RAPPLICATION_H

#include "Artemis.h"
#include <list>

class rApplication
{
public:
    rApplication();
    ~rApplication();

    artemis::EntitySystem* addSystem( artemis::EntitySystem* sys );
    artemis::Entity &newEntity();

    void init();
    void loop();
    void stop();

    artemis::World & getWorld();

    void step( float dt );

private:
   artemis::World _world;
   std::list<artemis::EntitySystem*> _sys;
};

#endif // RAPPLICATION_H
