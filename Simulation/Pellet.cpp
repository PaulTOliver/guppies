#include "Pellet.hpp"
#include "SimBase.hpp"

void Pellet::startup(SimBase *sim)
{
    hSim = sim;
    radius = Params::PELLET_RAD;
}


void Pellet::update()
{
    if (!body)
    {
        return;
    }

    if (toBeDestroyed)
    {
        destroy();
    }
}


void Pellet::destroy()
{
    toBeDestroyed = false;
    hSim->tank.world.DestroyBody(body);
    body = nullptr;

    --hSim->pelletCount;
    hSim->text.pelletCnt.setString("Pellet count: " + nts(hSim->pelletCount) + " / " + nts(hSim->prms.pelletQtty));
}


void Pellet::draw()
{
    if (!body)
    {
        return;
    }

    sf::Vector2f vSize = hSim->window.getView().getSize();
    sf::Vector2f vCent = hSim->window.getView().getCenter();
    if ( body->GetPosition().x + radius < vCent.x - vSize.x / 2.f ||
         body->GetPosition().y + radius < vCent.y - vSize.y / 2.f ||
         body->GetPosition().x - radius > vCent.x + vSize.x / 2.f ||
         body->GetPosition().y - radius > vCent.y + vSize.y / 2.f  )
    {
        return;
    }

    if (hSim->camera.zoom > Params::PELLET_RAD / 2.f)
    {
        hSim->pelletPoint.setPosition(body->GetPosition().x, body->GetPosition().y);
        hSim->window.draw(hSim->pelletPoint);
    }
    else
    {
        hSim->pelletShell.setPosition(body->GetPosition().x, body->GetPosition().y);
        hSim->pelletNucleus.setPosition(body->GetPosition().x, body->GetPosition().y);
        hSim->pelletNucleus.setRotation(body->GetAngle() * hSim->prms.RAD_DGRS);
        hSim->window.draw(hSim->pelletShell);
        hSim->window.draw(hSim->pelletNucleus);
    }
}
