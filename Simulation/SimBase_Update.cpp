#include "SimBase.hpp"

void SimBase::update()
{
    if (paused)
    {
        camera.update();
        return;
    }

    ++step;
    text.steps.setString("Steps: " + nts(step));

    if (timer.getElapsedTime().asSeconds() > 1.f)
    {
        timer.restart();
        text.fps.setString("FPS: " + nts(frameCounter));
        frameCounter = 0;
    }
    else
    {
        ++frameCounter;
    }

    for (auto &i : zappers)
    {
        i.update();
    }

    // Create new pellet if needed
    if (pelletCount < prms.pelletQtty && !(step % prms.pelletCreationDelay))
    {
        for (auto &i : pellets)
        {
            if (!i.isCreated())
            {
                i.create();
                break;
            }
        }
    }
    for (auto &i : pellets)
    {
        i.update();
    }

    for (auto &i : corpses)
    {
        i.update();
    }

    updateSpecs();

    tank.updateAllPhysics();
}
