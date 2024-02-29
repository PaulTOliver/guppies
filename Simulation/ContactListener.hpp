#ifndef __CONTACTLISTENER_HPP__
#define __CONTACTLISTENER_HPP__

#include <Box2D.h>

class SimBase;

class ContactListener : public b2ContactListener
{
public:
    void PreSolve(b2Contact *contact, const b2Manifold *oldManifold);

    SimBase *hSim = nullptr;
};

#endif // __CONTACTLISTENER_HPP__
