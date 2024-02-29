#ifndef __TEXTDISPLAY_HPP__
#define __TEXTDISPLAY_HPP__

#include <SFML/Graphics.hpp>

#include "Params.hpp"

class SimBase;

class TextDisplay
{
public:
    bool startup(SimBase *sim, SimStyle style);
    void print();

private:
    SimBase *hSim = nullptr;
    SimStyle sStyle;

    sf::Font font;
    sf::RectangleShape leftPanel;

    // ON LEFT PANEL
    sf::Text simState;
    sf::Text steps;
    // Separator
    sf::Text fps;
    sf::Text gfx;
    sf::Text vSync;
    // Separator
    sf::Text worldRad;
    // Separator
    sf::Text zapperCnt;
    sf::Text pelletCnt;
    sf::Text guppieCnt;
    sf::Text corpseCnt;
    // Separator
    sf::Text simStyle;
    // If sim. style == sel. by fitness
        sf::Text currentPop;
        sf::Text currentGen;
        // Separator
        sf::Text longestLife;
    // Left panel separators
    sf::RectangleShape sepLP[5];

    friend class SimBase;
    friend class SimFitness;
    friend class Entity;
    friend class Pellet;
    friend class Guppie;
    friend class Corpse;
};

#endif // __TEXTDISPLAY_HPP__
