#include "Camera.hpp"
#include "SimBase.hpp"

void Camera::create(SimBase *sim)
{
    hSim = sim;

    defaultZoom = hSim->prms.worldRad / 200.f;
    zoom = defaultZoom;
    prevZoom = zoom;
    trgtZoom = zoom;

    step = 1;
    update();
}


void Camera::onResize()
{
    sf::View view = hSim->window.getView();
    sf::Vector2u winSize = hSim->window.getSize();
    view.setSize(winSize.x * zoom, winSize.y * zoom);
    view.setCenter(currentCrds);
    hSim->window.setView(view);
}


void Camera::onClick()
{
    prevZoom = zoom;
    trgtZoom = zoom;

    prevCrds = currentCrds;

    sf::Vector2f mousePos = hSim->window.mapPixelToCoords(sf::Mouse::getPosition(hSim->window));
    b2Vec2 b2MousePos(mousePos.x, mousePos.y);
    b2Vec2 additive(0.001f, 0.001f);
    b2AABB aabb;
    aabb.upperBound = b2MousePos + additive;
    aabb.lowerBound = b2MousePos - additive;

    QueryCallback callback;
    callback.m_point = b2MousePos;
    hSim->tank.world.QueryAABB(&callback, aabb);

    if (callback.m_fixture)
    {
        trgtBody = callback.m_fixture->GetBody();
    }
    else
    {
        trgtCrds = mousePos;
        trgtBody = nullptr;
    }

    isOnFollow = false;
    step = Params::CAM_STEPS;
}


void Camera::shift(const sf::Vector2f &newTrgtCrds, int zoomInOut, bool release)
{
    if (!release && trgtBody)
    {
        prevCrds = sf::Vector2f(trgtBody->GetPosition().x, trgtBody->GetPosition().y);
        currentCrds =  sf::Vector2f(trgtBody->GetPosition().x, trgtBody->GetPosition().y);
        trgtCrds = sf::Vector2f(trgtBody->GetPosition().x, trgtBody->GetPosition().y);
        isOnFollow = true;
    }
    else
    {
        trgtBody = nullptr;
        prevCrds = currentCrds;
        trgtCrds = newTrgtCrds;
        isOnFollow = false;
    }

    prevZoom = zoom;
    if (zoomInOut)
    {
        if (zoomInOut == 1)
        {
            trgtZoom = zoom - 0.2f * zoom;
        }
        else if (zoomInOut == -1)
        {
            trgtZoom = zoom + 0.2f * zoom;
        }
        else if (zoomInOut == -2)
        {
            trgtZoom = defaultZoom;
        }
    }
    else
    {
        trgtZoom = zoom;
    }

    step = Params::CAM_STEPS;
}

void Camera::update()
{
    if (trgtBody || step)
    {
        if (!step)
        {
            currentCrds = sf::Vector2f(trgtBody->GetPosition().x, trgtBody->GetPosition().y);
        }
        else
        {
            if (trgtBody)
            {
                trgtCrds = sf::Vector2f(trgtBody->GetPosition().x, trgtBody->GetPosition().y);
                if (isOnFollow)
                {
                    prevCrds = trgtCrds;
                }
            }

            float f1 = (step - 1.f) / (float)Params::CAM_STEPS;
            float f2 = 1.f - f1;

            currentCrds = prevCrds * f1 + trgtCrds * f2;
            zoom = prevZoom * f1 + trgtZoom * f2;

            if (currentCrds.x * currentCrds.x + currentCrds.y * currentCrds.y > hSim->prms.worldRad * hSim->prms.worldRad)
            {
                float angle = atanf(currentCrds.y / currentCrds.x);
                currentCrds.y = sinf(angle) * hSim->prms.worldRad * (currentCrds.x > 1.f ? 1.f : -1.f);
                currentCrds.x = cosf(angle) * hSim->prms.worldRad * (currentCrds.x > 1.f ? 1.f : -1.f);
            }

            if (zoom > defaultZoom)
            {
                zoom = defaultZoom;
            }
            if (zoom < Params::MAX_ZOOM)
            {
                zoom = Params::MAX_ZOOM;
            }

            --step;
        }

        sf::View view = hSim->window.getView();
        view.setCenter(currentCrds);
        view.setSize(hSim->window.getSize().x * zoom, hSim->window.getSize().y * zoom);
        hSim->window.setView(view);
    }

    // Prepare low zoom graphics
    hSim->tank.worldEdges.setOutlineThickness(zoom * 2.f);

    if (zoom > Params::ZAPPER_RAD / 2.f)
    {
        if (zoom > Params::ZAPPER_RAD * 2.f)
        {
            setCenterRad(hSim->zapperPoint, zoom);
            hSim->zapperPoint.setFillColor(hSim->prms.zapperColor);
        }
        else
        {
            setCenterRad(hSim->zapperPoint, Params::ZAPPER_RAD);
            hSim->zapperPoint.setFillColor(hSim->prms.zapperColor);
        }
    }
    else
    {
        setCenterRad(hSim->zapperShell, hSim->prms.ZAPPER_RAD - zoom * 2.f);
        hSim->zapperShell.setOutlineThickness(zoom * 2.f);
    }

    if (zoom > Params::PELLET_RAD / 2.f)
    {
        if (zoom > Params::PELLET_RAD * 2.f)
        {
            setCenterRad(hSim->pelletPoint, zoom);
            hSim->pelletPoint.setFillColor(hSim->prms.pelletColor);
        }
        else
        {
            setCenterRad(hSim->pelletPoint, Params::PELLET_RAD);
            hSim->pelletPoint.setFillColor(hSim->prms.pelletColor);
        }
    }
    else
    {
        setCenterRad(hSim->pelletShell, hSim->prms.PELLET_RAD - zoom * 2.f);
        hSim->pelletShell.setOutlineThickness(zoom * 2.f);
    }

    if (zoom > Params::CORPSE_RAD / 2.f)
    {
        if (zoom > Params::CORPSE_RAD * 2.f)
        {
            setCenterRad(hSim->corpsePoint, zoom);
            hSim->corpsePoint.setFillColor(hSim->prms.corpseColor);
        }
        else
        {
            setCenterRad(hSim->corpsePoint, Params::CORPSE_RAD);
            hSim->corpsePoint.setFillColor(hSim->prms.corpseColor);
        }
    }
    else
    {
        setCenterRad(hSim->corpseShell, hSim->prms.CORPSE_RAD - zoom * 2.f);
        hSim->corpseShell.setOutlineThickness(zoom * 2.f);
    }

    if (zoom > Params::EGG_RAD / 2.f)
    {
        if (zoom > Params::EGG_RAD * 2.f)
        {
            setCenterRad(hSim->eggPoint, zoom);
            hSim->eggPoint.setFillColor(hSim->guppN);
        }
        else
        {
            setCenterRad(hSim->eggPoint, Params::EGG_RAD);
            hSim->eggPoint.setFillColor(hSim->guppN);
        }
    }
    else
    {
        setCenterRad(hSim->guppieEgg, hSim->prms.EGG_RAD - zoom * 2.f);
        hSim->guppieEgg.setOutlineThickness(zoom * 2.f);
    }

    if (zoom > Params::GUPPIE_RAD)
    {
        setCenterRad(hSim->guppiePoint, zoom);
    }

    else if (zoom > 0.02f)
    {
        setCenterRad(hSim->guppieShell, Params::GUPPIE_RAD - zoom);
        hSim->guppieShell.setOutlineThickness(zoom);
    }
}
