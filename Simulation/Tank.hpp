#ifndef __TANK_HPP__
#define __TANK_HPP__

#include <SFML/Graphics.hpp>
#include <Box2d.h>

#include "ContactListener.hpp"

class SimBase;

class Tank
{
public:
    void create(SimBase *sim);
    void updateAllPhysics();
    void draw();

private:
    SimBase *hSim = nullptr;

    b2World world = b2World(b2Vec2(0.f, 0.f));
    sf::CircleShape worldEdges;
    b2Body *tankEdge = nullptr;

    ContactListener contactListener;

    friend class Camera;
    friend class Entity;
    friend class Pellet;
    friend class Guppie;
    friend class Corpse;
};

#endif // __TANK_HPP__
