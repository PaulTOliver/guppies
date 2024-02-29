#include "Corpse.hpp"
#include "SimBase.hpp"

void Corpse::startup(SimBase *sim)
{
    hSim = sim;
    radius = Params::CORPSE_RAD;
}

void Corpse::setup(b2Vec2 pos, b2Vec2 lVel, float angle, float aVel)
{
    if (!body)
    {
        return;
    }

    lifetime = hSim->prms.corpseDecayTime;
    energy = hSim->prms.etFromCorpse;

    body->SetTransform(pos, angle);
    body->SetLinearVelocity(lVel);
    body->SetAngularVelocity(aVel);
}


void Corpse::update()
{
    if (!body)
    {
        return;
    }

    if (hSim->prms.corpseDecay)
    {
        --lifetime;
        energy = hSim->prms.etFromCorpse * ((float)lifetime / (float)hSim->prms.corpseDecayTime);
    }

    if (!lifetime || toBeDestroyed)
    {
        destroy();
    }
}


void Corpse::destroy()
{
    if (hSim->camera.trgtBody == body)
    {
        hSim->camera.prevCrds = hSim->camera.currentCrds;
        hSim->camera.trgtCrds = hSim->camera.currentCrds;
        hSim->camera.step = 0;
        hSim->camera.trgtBody = nullptr;
    }

    toBeDestroyed = false;
    hSim->tank.world.DestroyBody(body);
    body = nullptr;

    --hSim->corpseCount;
    hSim->text.corpseCnt.setString("Corpse count: " + nts(hSim->corpseCount));
}


void Corpse::draw()
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

    sf::Color corpseColor = mix(hSim->prms.corpseColor, hSim->prms.worldColor, ((float)lifetime / (float)hSim->prms.corpseDecayTime));
    if (hSim->camera.zoom > Params::CORPSE_RAD / 2.f)
    {
        hSim->corpsePoint.setFillColor(corpseColor);
        hSim->corpsePoint.setPosition(body->GetPosition().x, body->GetPosition().y);
        hSim->window.draw(hSim->corpsePoint);
    }
    else
    {
        hSim->corpseShell.setOutlineColor(corpseColor);
        hSim->corpseShell.setPosition(body->GetPosition().x, body->GetPosition().y);
        hSim->corpseNucleus.setFillColor(corpseColor);
        hSim->corpseNucleus.setPosition(body->GetPosition().x, body->GetPosition().y);
        hSim->corpseNucleus.setRotation(body->GetAngle() * Params::RAD_DGRS);
        hSim->window.draw(hSim->corpseShell);
        hSim->window.draw(hSim->corpseNucleus);
    }
}
