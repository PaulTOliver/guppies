#ifndef __SIMBASE_HPP__
#define __SIMBASE_HPP__

//#include <fstream>
#include <list>

#include "Params.hpp"
#include "GraphicObjs.hpp"

#include "Camera.hpp"
#include "Tank.hpp"
#include "TextDisplay.hpp"
#include "Zapper.hpp"
#include "Pellet.hpp"
#include "Guppie.hpp"
#include "Corpse.hpp"

class SimBase : public GraphicObjs
{
public:
    bool createNew(const Params &usrPrms);
    //bool load(const std::ifstream &file);
    void execute();

protected:
    void prepareGraphics();
    void update();
    void draw();

    virtual bool startSpecs() = 0;
    virtual void updateSpecs() = 0;
    //void onClose();

    Params prms;
    sf::RenderWindow window;
    Camera camera;
    Tank tank;
    TextDisplay text;

    sf::Clock timer;
    unsigned frameCounter = 0;

    bool paused = false;
    bool gfx = true;
    bool displayText = true;
    bool vSync = true;
    bool fullscreen = false;
    unsigned step = 0;

    unsigned pelletCount = 0;
    unsigned guppieCount = 0;
    unsigned corpseCount = 0;

    std::list<Zapper> zappers;
    std::list<Pellet> pellets;
    std::list<Guppie> guppies;
    std::list<Corpse> corpses;

    friend class Camera;
    friend class Tank;
    friend class ContactListener;
    friend class TextDisplay;
    friend class Entity;
    friend class Zapper;
    friend class Pellet;
    friend class Corpse;
    friend class Guppie;
};

#endif // __SIMBASE_HPP__
