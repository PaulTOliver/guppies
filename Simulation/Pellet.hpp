#ifndef __PELLET_HPP__
#define __PELLET_HPP__

#include "Entity.hpp"

class Pellet : public Entity
{
public:
    void startup(SimBase *sim);
    void update();
    void draw();

    bool isCreated() const { return body ? true : false; }
    bool toBeDestroyed = false;

private:
    void destroy();
};

#endif // __PELLET_HPP__
