#ifndef RSYSTEM_H
#define RSYSTEM_H

class rEntity;

class rSystem
{
public:
    virtual ~rSystem();
protected:
    rSystem();
    virtual void processEntity(rEntity* e)=0;
};

#endif // RSYSTEM_H
