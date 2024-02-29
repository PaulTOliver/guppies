#ifndef __CORPSE_HPP__
#define __CORPSE_HPP__

#include "Entity.hpp"

class Corpse : public Entity
{
public:
    void startup(SimBase *sim);
    void update();
    void draw();

    bool isCreated() const { return body ? true : false; }
    bool toBeDestroyed = false;

    void setup(b2Vec2 pos, b2Vec2 lVel, float angle, float aVel);

private:
    void destroy();

    unsigned lifetime = 0;
    float energy = 0.f;

    friend class ContactListener;
    friend class Guppie;
};

#endif // __CORPSE_HPP__
