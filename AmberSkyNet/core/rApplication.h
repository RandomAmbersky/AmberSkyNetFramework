#ifndef RAPPLICATION_H
#define RAPPLICATION_H

class rEntityManager;
class rSystemManager;
class rComponentManager;
class rEntity;
class rSystem;

class rApplication
{
public:
    rApplication();
    ~rApplication();
    rEntityManager* getEntityManager();
    rSystemManager* getSystemManager();
    rComponentManager* getComponentManager();
    rEntity* createEntity();
    void addSystem( rSystem* s );
private:
    rEntityManager* _e_manager;
    rSystemManager* _s_manager;
    rComponentManager *_c_manager;
};

#endif // RAPPLICATION_H
