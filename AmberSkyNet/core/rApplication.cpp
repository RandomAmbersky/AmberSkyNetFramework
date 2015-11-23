#include "rApplication.h"
#include "rEntityManager.h"
#include "rSystemManager.h"
#include "rComponentManager.h"

rApplication::rApplication()
{
    _e_manager = new rEntityManager();
    _s_manager = new rSystemManager();
    _c_manager = new rComponentManager();
}

rApplication::~rApplication()
{
    delete _s_manager;
    delete _e_manager;
}

rEntityManager *rApplication::getEntityManager()
{
    return _e_manager;
}

rSystemManager *rApplication::getSystemManager()
{
    return _s_manager;
}

rComponentManager *rApplication::getComponentManager()
{
    return _c_manager;
}

rEntity *rApplication::createEntity()
{
    return _e_manager->create();
}

void rApplication::addSystem(rSystem *s)
{
    _s_manager->addSystem( s );
}

