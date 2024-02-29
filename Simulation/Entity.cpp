#include "Entity.hpp"
#include "SimBase.hpp"

void Entity::create()
{
    if (!hSim || body || !radius)
    {
        return;
    }

    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position = { hSim->prms.worldRad, hSim->prms.worldRad };
    float hypotenuse = hSim->prms.worldRad - radius;
    while (bodyDef.position.x * bodyDef.position.x + bodyDef.position.y * bodyDef.position.y > hypotenuse * hypotenuse)
    {
        bodyDef.position.x = realRand(-hSim->prms.worldRad, hSim->prms.worldRad);
        bodyDef.position.y = realRand(-hSim->prms.worldRad, hSim->prms.worldRad);
    }
    bodyDef.angle = realRand(0.f, 360.f / Params::RAD_DGRS);
    bodyDef.linearDamping = 0.1f;
    bodyDef.angularDamping = 0.1f;
    bodyDef.allowSleep = true;
    bodyDef.userData = this;

    body = hSim->tank.world.CreateBody(&bodyDef);

    b2CircleShape shape;
    shape.m_radius = radius;

    b2FixtureDef fixture;
    fixture.shape = &shape;
    fixture.friction = 1.f;
    fixture.restitution = 1.f;
    fixture.density = 1.f;

    body->CreateFixture(&fixture);

    if (radius == Params::PELLET_RAD)
    {
        ++hSim->pelletCount;
        hSim->text.pelletCnt.setString("Pellet count: " + nts(hSim->pelletCount) + " / " + nts(hSim->prms.pelletQtty));
    }
    else if (radius == Params::CORPSE_RAD)
    {
        ++hSim->corpseCount;
        hSim->text.corpseCnt.setString("Corpse count: " + nts(hSim->corpseCount));
    }
    else if (radius == Params::GUPPIE_RAD)
    {
        ++hSim->guppieCount;
        hSim->text.guppieCnt.setString("Guppie count: " + nts(hSim->guppieCount));
        ((Guppie *)this)->energy = hSim->prms.initEnergy;
        body->SetLinearDamping(2.f);
        body->SetAngularDamping(2.f);

        ((b2CircleShape *)body->GetFixtureList()->GetShape())->m_radius = hSim->prms.EGG_RAD;
    }
}
