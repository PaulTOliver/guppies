#ifndef __ENTITY_HPP__
#define __ENTITY_HPP__

#include <SFML/Graphics.hpp>
#include <Box2D.h>

class SimBase;

class Entity
{
public:
    virtual void startup(SimBase *sim) = 0;

    void create();
    void destroy();

    virtual void update() = 0;
    virtual void draw() = 0;

    float getRadius() const { return radius; }

protected:
    SimBase *hSim = nullptr;

    b2Body *body = nullptr;
    float radius = 0.f;
    float resistance = 0.f;

    friend class ContactListener;
    friend class Guppie;
    friend class Camera;
};

#endif // __ENTITY_HPP__
