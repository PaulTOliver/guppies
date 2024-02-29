#include "TextDisplay.hpp"
#include "SimBase.hpp"

#include <sstream>

bool TextDisplay::startup(SimBase *sim, SimStyle style)
{
    hSim = sim;
    sStyle = style;

    if (!font.loadFromFile("gfx\\font.ttf"))
    {
        return false;
    }

    const float TXT_MARGIN = Params::TXT_SIZE / 2.f;

    // RIGHT PANEL
    // Prepare left panel text
    simState  = sf::Text("Sim. state: RUNNING", font, Params::TXT_SIZE);
    steps     = sf::Text("Steps: 0", font, Params::TXT_SIZE);
    // Separator
    fps       = sf::Text("FPS: 0", font, Params::TXT_SIZE);
    gfx       = sf::Text("Graphics: ON", font, Params::TXT_SIZE);
    vSync     = sf::Text("V. Sync: ON", font, Params::TXT_SIZE);
    // Separator
    worldRad  = sf::Text("World radius: " + nts(hSim->prms.worldRad), font, Params::TXT_SIZE);
    // Separator
    zapperCnt = sf::Text("Zapper count: " + nts(hSim->prms.zapperQtty), font, Params::TXT_SIZE);
    pelletCnt = sf::Text("Pellet count: " + nts(hSim->pelletCount) + " / " + nts(hSim->prms.pelletQtty), font, Params::TXT_SIZE);
    guppieCnt = sf::Text("Guppie count: 0", font, Params::TXT_SIZE);
    corpseCnt = sf::Text("Corpse count: 0", font, Params::TXT_SIZE);
    if (sStyle == SELECTION_BY_FITNESS)
    {
        simStyle    = sf::Text("Sim. style: FITNESS SELECTION", font, Params::TXT_SIZE);
        currentPop  = sf::Text("Current population: 1 / " + nts(hSim->prms.popQtty), font, Params::TXT_SIZE);
        currentGen  = sf::Text("Current generation: 1", font, Params::TXT_SIZE);
        // Separator
        longestLife = sf::Text("Fitness record: 0", font, Params::TXT_SIZE);
    }
    // Position and color text items
    sf::Text *line = nullptr;
    float posX = TXT_MARGIN * 2.f;
    float posY = TXT_MARGIN * 2.f - Params::TXT_SIZE / 4.f;
    for (line = &simState; line <= &corpseCnt; ++line)
    {
        line->setPosition(posX, posY);
        line->setColor(hSim->prms.textColor);
        posY += Params::TXT_SIZE;
        if (line == &steps || line == &vSync || line == &worldRad || line == &corpseCnt)
        {
            posY += Params::TXT_SIZE;
        }
    }
    if (sStyle == SELECTION_BY_FITNESS)
    {
        for (line = &simStyle; line <= &longestLife; ++line)
        {
            line->setPosition(posX, posY);
            line->setColor(hSim->prms.textColor);
            posY += Params::TXT_SIZE;
            if (line == &currentGen)
            {
                posY += Params::TXT_SIZE;
            }
        }
    }
    // Prepare left panel
    float lpTxtWidth = 0.f;
    float lpTxtHeight = 0.f;
    for (line = &simState; line <= &corpseCnt; ++line)
    {
        line->getGlobalBounds().width > lpTxtWidth ? lpTxtWidth = line->getGlobalBounds().width : lpTxtWidth = lpTxtWidth;
    }
    if (sStyle == SELECTION_BY_FITNESS)
    {
        for (line = &simStyle; line <= &longestLife; ++line)
        {
            line->getGlobalBounds().width > lpTxtWidth ? lpTxtWidth = line->getGlobalBounds().width : lpTxtWidth = lpTxtWidth;
        }
        lpTxtHeight = (longestLife.getGlobalBounds().height + longestLife.getPosition().y) - simState.getPosition().y;
    }
    leftPanel.setSize(sf::Vector2f(lpTxtWidth + TXT_MARGIN * 2.f, lpTxtHeight + TXT_MARGIN * 2.f));
    leftPanel.setPosition(TXT_MARGIN, TXT_MARGIN);
    leftPanel.setOutlineThickness(1.f);
    leftPanel.setFillColor(sf::Color(0, 0, 0, 191));
    leftPanel.setOutlineColor(hSim->prms.textColor);
    // Append left panel separators
    for (int i = 0; i < 5; ++i)
    {
        sepLP[i].setSize(sf::Vector2f(lpTxtWidth, 1.f));
        sepLP[i].setFillColor(hSim->prms.textColor);
    }
    sepLP[0].setPosition(posX, fps.getPosition().y - TXT_MARGIN * 2.f / 3.f);
    sepLP[1].setPosition(posX, worldRad.getPosition().y - TXT_MARGIN * 2.f / 3.f);
    sepLP[2].setPosition(posX, zapperCnt.getPosition().y - TXT_MARGIN * 2.f / 3.f);
    if (sStyle == SELECTION_BY_FITNESS)
    {
        sepLP[3].setPosition(posX, simStyle.getPosition().y - TXT_MARGIN * 2.f / 3.f);
        sepLP[4].setPosition(posX, longestLife.getPosition().y - TXT_MARGIN * 2.f / 3.f);
    }

    return true;
}


void TextDisplay::print()
{
    sf::View textView = sf::View(sf::Vector2f(hSim->window.getSize().x / 2.f, hSim->window.getSize().y / 2.f), sf::Vector2f(hSim->window.getSize().x, hSim->window.getSize().y));
    sf::View crntView = hSim->window.getView();

    hSim->window.setView(textView);

    // Print left panel
    hSim->window.draw(leftPanel);
    sf::Text *line = nullptr;
    for (line = &simState; line <= &simStyle; ++line)
    {
        hSim->window.draw(*line);
    }
    if (sStyle == SELECTION_BY_FITNESS)
    {
        for (line = &currentPop; line <= &longestLife; ++line)
        {
            hSim->window.draw(*line);
        }
    }
    for (int i = 0; i < 5; ++i)
    {
        hSim->window.draw(sepLP[i]);
    }

    // Print right panel

    hSim->window.setView(crntView);
}
