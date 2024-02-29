#include "SimBase.hpp"

bool SimBase::createNew(const Params &usrPrms)
{
    prms = usrPrms;

    seedRand();

    sf::VideoMode vmd = sf::VideoMode(prms.WIN_WIDTH, prms.WIN_HEIGHT);
    sf::ContextSettings ctx = sf::ContextSettings(0, 0, prms.ANTIALIAS, 2, 0);
    window.create(vmd, "Neural Guppies - 0.1 beta", sf::Style::Default, ctx);
    window.setVerticalSyncEnabled(vSync);

    sf::Image icon;
    icon.loadFromFile("gfx/icon.png");
    window.setIcon(32, 32, icon.getPixelsPtr());

    prepareGraphics();

    camera.create(this);
    tank.create(this);

    zappers.resize(prms.zapperQtty);
    for (auto &i : zappers)
    {
        i.startup(this);
        i.create();
    }

    pellets.resize(prms.pelletQtty);
    for (auto &i : pellets)
    {
        i.startup(this);
    }
    if (!prms.startScarce)
    {
        for (auto &i : pellets)
        {
            i.create();
        }
    }

    if (!startSpecs())
    {
        return false;
    }

    return true;
}
