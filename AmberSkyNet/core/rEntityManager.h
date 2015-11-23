#ifndef RENTITYMANAGER_H
#define RENTITYMANAGER_H

class rEntity;
class rComponent;
class rComponentType;

class rEntityManager
{
public:
    rEntityManager();
    rEntity* create();

    void addComponent(rEntity* e, rComponent* c);
    void removeComponent(rEntity* e, rComponentType & type);
    rComponent* getComponent(rEntity* e, rComponentType & type);

private:
    int _nextAvailableId;
    int _count;
    long int _uniqueEntityId;
    long int _totalCreated;
    long int _totalRemoved;
};

#endif // RENTITYMANAGER_H
