#ifndef __ZAPPER_HPP__
#define __ZAPPER_HPP__

#include "Entity.hpp"

class Zapper : public Entity
{
public:
    void startup(SimBase *sim);
    void update();
    void draw();
};

#endif // __ZAPPER_HPP__
