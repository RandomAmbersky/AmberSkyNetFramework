#include "asn.h"
#include "Artemis.h"

class VelocityComponent : public artemis::Component {
public:
    float velocityX;
    float velocityY;

    VelocityComponent(float velocityX, float velocityY)
    {
        this->velocityX = velocityX;
        this->velocityY = velocityY;
    };
};

class PositionComponent : public artemis::Component
{

public:
    float posX;
    float posY;
    PositionComponent(float posX, float posY)
    {
        this->posX = posX;
        this->posY = posY;
    };
};

class MovementSystem : public artemis::EntityProcessingSystem {
private:
    artemis::ComponentMapper<VelocityComponent> velocityMapper;
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

//int main(int argc, char *argv[])
int main(int , char *[])
{

    rApplication* app = new rApplication;

    app->addSystem( new MovementSystem() );
    app->init();

    artemis::Entity & player = app->newEntity();
    player.addComponent(new VelocityComponent(2,4));
    player.addComponent(new PositionComponent(0,0));
    player.refresh();

    PositionComponent* comp = (PositionComponent*)player.getComponent<PositionComponent>();

    while(true){

        app->step( 0.0016f );

        std::cout << "X:"<< comp->posX << std::endl;
        std::cout << "Y:"<< comp->posY << std::endl;

    }

    return 0;
}

