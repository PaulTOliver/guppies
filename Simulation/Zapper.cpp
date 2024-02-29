#include "Zapper.hpp"
#include "SimBase.hpp"

void Zapper::startup(SimBase *sim)
{
    hSim = sim;
    radius = Params::ZAPPER_RAD;
}


void Zapper::update()
{
    float forceX = realRand(-hSim->prms.zapperForce, hSim->prms.zapperForce);
    float forceY = realRand(-hSim->prms.zapperForce, hSim->prms.zapperForce);
    body->ApplyForceToCenter(b2Vec2(forceX, forceY));
    float torque = realRand(-hSim->prms.zapperTorque, hSim->prms.zapperTorque);
    body->ApplyTorque(torque);
}


void Zapper::draw()
{
    sf::Vector2f vSize = hSim->window.getView().getSize();
    sf::Vector2f vCent = hSim->window.getView().getCenter();
    if ( body->GetPosition().x + radius < vCent.x - vSize.x / 2.f ||
         body->GetPosition().y + radius < vCent.y - vSize.y / 2.f ||
         body->GetPosition().x - radius > vCent.x + vSize.x / 2.f ||
         body->GetPosition().y - radius > vCent.y + vSize.y / 2.f  )
    {
        return;
    }

    if (hSim->camera.zoom > Params::ZAPPER_RAD / 2.f)
    {
        hSim->zapperPoint.setPosition(body->GetPosition().x, body->GetPosition().y);
        hSim->window.draw(hSim->zapperPoint);
    }
    else
    {
        hSim->zapperShell.setPosition(body->GetPosition().x, body->GetPosition().y);
        hSim->zapperNucleus.setPosition(body->GetPosition().x, body->GetPosition().y);
        hSim->zapperNucleus.setRotation(body->GetAngle() * hSim->prms.RAD_DGRS);
        hSim->window.draw(hSim->zapperShell);
        hSim->window.draw(hSim->zapperNucleus);
    }
}
