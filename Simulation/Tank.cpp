#include "Tank.hpp"
#include "SimBase.hpp"

void Tank::create(SimBase *sim)
{
    hSim = sim;

    // Prepare tank graphics
    setCenterRad(worldEdges, hSim->prms.worldRad);
    worldEdges.setPointCount(360);
    worldEdges.setFillColor(hSim->prms.worldColor);
    worldEdges.setOutlineColor(hSim->prms.zapperColor);
    worldEdges.setOutlineThickness(hSim->prms.worldRad / 100.f);

    // Prepare tank physics
    world.SetAllowSleeping(true);
    contactListener.hSim = hSim;
    world.SetContactListener(&contactListener);

    // Create edge of the world
    b2BodyDef worldDef;
    worldDef.type = b2_staticBody;

    tankEdge = world.CreateBody(&worldDef);

    b2ChainShape shape;
    b2Vec2 vrtx[360];
    for (int dgr = 0; dgr < 360; ++dgr)
    {
        vrtx[dgr].Set(cosf((float)dgr / Params::RAD_DGRS), sinf((float)dgr / Params::RAD_DGRS)),
        vrtx[dgr] *= hSim->prms.worldRad;
    }
    shape.CreateLoop(vrtx, 360);

    b2FixtureDef worldFix;
    worldFix.shape = &shape;
    worldFix.friction = 1.f;

    tankEdge->CreateFixture(&worldFix);
}


void Tank::updateAllPhysics()
{
    world.Step(1.f / 60.f, 8, 3);
}


void Tank::draw()
{
    hSim->window.draw(worldEdges);
}
