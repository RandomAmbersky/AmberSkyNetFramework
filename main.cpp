#include <iostream>
#include <typeinfo>

using namespace std;

#include "asn.h"

class VelocityComponent : public rComponent {
public:
    float velocityX;
    float velocityY;

    VelocityComponent(float velocityX, float velocityY)
    {
        this->velocityX = velocityX;
        this->velocityY = velocityY;
    }
};

class PositionComponent : public rComponent
{

public:
    float posX;
    float posY;
    PositionComponent(float posX, float posY)
    {
        this->posX = posX;
        this->posY = posY;
    }
};

/*
class MovementSystem : public rEntitySystem {
private:
    artemis::ComponentMapper<MovementComponent> velocityMapper;
    artemis::ComponentMapper<PositionComponent> positionMapper;

public:
    MovementSystem() {
        addComponentType<VelocityComponent>();
        addComponentType<PositionComponent>();
    };

    virtual void initialize() {
        velocityMapper.init(*world);
        positionMapper.init(*world);
    };

    virtual void processEntity(artemis::Entity &e) {
        positionMapper.get(e)->posX += velocityMapper.get(e)->velocityX * world->getDelta();
        positionMapper.get(e)->posY += velocityMapper.get(e)->velocityY * world->getDelta();
    };

};
*/

class MovementSystem : public rSystem {

public:
    MovementSystem() {

    }

    virtual void processEntity(rEntity* e) {
        //positionMapper.get(e)->posX += velocityMapper.get(e)->velocityX * world->getDelta();
        //positionMapper.get(e)->posY += velocityMapper.get(e)->velocityY * world->getDelta();
    }

};

int main()
{

    rApplication* app = new rApplication();

    app->addSystem( new MovementSystem() );

    app->getComponentManager()->getTypeId(typeid(VelocityComponent));
    app->getComponentManager()->getTypeId(typeid(PositionComponent));

    rEntity* e = app->createEntity();
    e->addComponent( new VelocityComponent(10,10) );
    e->addComponent( new PositionComponent(1,1) );
    e->refresh();

    cout << "Hello World!" << endl;

    delete app;

    return 0;
}

