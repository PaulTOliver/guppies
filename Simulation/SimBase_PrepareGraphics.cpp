#include "SimBase.hpp"

void SimBase::prepareGraphics()
{
    // Prepare zappers
    setCenterRad(zapperShell, prms.ZAPPER_RAD);
    zapperShell.setPointCount(180);
    zapperShell.setFillColor(mix(prms.zapperColor, prms.worldColor));
    zapperShell.setOutlineColor(prms.zapperColor);
    setCenterRad(zapperNucleus, prms.ZAPPER_RAD);
    zapperNucleus.setFillColor(prms.zapperColor);

    // Prepare pellets
    setCenterRad(pelletShell, prms.PELLET_RAD);
    pelletShell.setPointCount(60);
    pelletShell.setFillColor(mix(prms.pelletColor, prms.worldColor));
    pelletShell.setOutlineColor(prms.pelletColor);
    setCenterRad(pelletNucleus, prms.PELLET_RAD);
    pelletNucleus.setFillColor(prms.pelletColor);

    // Prepare corpses
    setCenterRad(corpseShell, prms.CORPSE_RAD);
    corpseShell.setPointCount(60);
    corpseShell.setFillColor(mix(prms.corpseColor, prms.worldColor));
    corpseShell.setOutlineColor(prms.corpseColor);
    setCenterRad(corpseNucleus, prms.CORPSE_RAD);
    corpseNucleus.setFillColor(prms.corpseColor);

    // Prepare guppies
    guppieShell.setFillColor(sf::Color::Transparent);
    guppN = mix(prms.guppieColorI, prms.worldColor, 0.1f);
    // Prepare egg
    guppieEgg.setFillColor(sf::Color::Transparent);
    guppieEgg.setOutlineColor(guppN);
    guppieEgg.setRadius(prms.EGG_RAD);
    // Prepare vision cone shape
    sf::CircleShape fovTempA = sf::CircleShape(10.f, 360);
    sf::ConvexShape fovTemp;
    fovTemp.setPointCount(360);
    for (int i = 0; i < 360; ++i)
    {
        fovTemp.setPoint(i, fovTempA.getPoint(i) - sf::Vector2f(10.f, 10.f + prms.GUPPIE_RAD));
    }
    for (int i = 0; i < 15; ++i)
    {
        visionCone[i] = fovTemp.getPoint(i * 2 + 331);
    }
    for (int i = 0; i < 15; ++i)
    {
        visionCone[i + 15] = fovTemp.getPoint(i * 2 + 1);
    }
    visionCone[30] = sf::Vector2f(0.f, -prms.GUPPIE_RAD);
    // Prepare beaks
    beak1.setPointCount(3);
    beak1.setPoint(0, sf::Vector2f(0.f, -0.5f));
    beak1.setPoint(1, sf::Vector2f(0.0116f, -0.5201f));
    beak1.setPoint(2, sf::Vector2f(0.0236f, -0.4994f));
    beak2.setPointCount(3);
    beak2.setPoint(0, sf::Vector2f(0.f, -0.5f));
    beak2.setPoint(1, sf::Vector2f(-0.0116f, -0.5201f));
    beak2.setPoint(2, sf::Vector2f(-0.0236f, -0.4994f));
    // Prepare skin radius shape
    sf::CircleShape sknTempA = sf::CircleShape(prms.GUPPIE_RAD, 360);
    sf::ConvexShape sknTemp;
    sknTemp.setPointCount(360);
    for (int i = 0; i < 360; ++i)
    {
        sknTemp.setPoint(i, sknTempA.getPoint(i) - sf::Vector2f(prms.GUPPIE_RAD, prms.GUPPIE_RAD));
    }
    for (int i = 0; i < 180; ++i)
    {
        skinRadius[i] = sknTemp.getPoint(i * 2 + 1);
    }
    // Prepare sense radius shape
    sf::CircleShape snsTempA = sf::CircleShape(10.f, 360);
    sf::ConvexShape snsTemp;
    snsTemp.setPointCount(360);
    for (int i = 0; i < 360; ++i)
    {
        snsTemp.setPoint(i, snsTempA.getPoint(i) - sf::Vector2f(10.f, 10.f));
    }
    for (int i = 0; i < 180; ++i)
    {
        senseRadius[i] = snsTemp.getPoint(i * 2 + 1);
    }
    // Draw skin
    gOuterSkin.setPointCount(180);
    setCenterRad(gOuterSkin, prms.GUPPIE_RAD);
    // Draw touch and smell cells
    sf::CircleShape tcTemp = sf::CircleShape(prms.GUPPIE_RAD - 0.04f, 180);
    tcTemp.setOrigin(prms.GUPPIE_RAD - 0.04f, prms.GUPPIE_RAD - 0.04f);
    sf::CircleShape scTemp = sf::CircleShape(prms.GUPPIE_RAD - 0.06f, 180);
    scTemp.setOrigin(prms.GUPPIE_RAD - 0.06f, prms.GUPPIE_RAD - 0.06f);
    for (int i = 0; i < 30; ++i)
    {
        touchCells[i].setPointCount(8);
        smellCells[i].setPointCount(8);
        for (int j = 0; j < 7; ++j)
        {
            touchCells[i].setPoint(j, tcTemp.getPoint((i * 6 + j) % 180));
            smellCells[i].setPoint(j, scTemp.getPoint((i * 6 + j) % 180));
        }
        touchCells[i].setPoint(7, tcTemp.getOrigin());
        touchCells[i].setOrigin(tcTemp.getOrigin());
        smellCells[i].setPoint(7, scTemp.getOrigin());
        smellCells[i].setOrigin(scTemp.getOrigin());
        smellCells[i].setFillColor(guppN);
    }
    // Draw inner body masks
    tailMask.setFillColor(guppN);
    tailMask.setPointCount(3);
    tailMask.setPoint(0, sf::Vector2f(0.f, 0.5f));
    tailMask.setPoint(1, sf::Vector2f(-0.0478f, 0.4173f));
    tailMask.setPoint(2, sf::Vector2f( 0.0478f, 0.4173f));
    innerBodyMask.setFillColor(guppN);
    innerBodyMask.setPointCount(180);
    setCenterRad(innerBodyMask, prms.GUPPIE_RAD - 0.08f);
    // Draw thrusters
    sf::CircleShape thTemp = sf::CircleShape(prms.GUPPIE_RAD - 0.1f, 180);
    for (int i = 0; i < 4; ++i)
    {
        thrusters[i].setPointCount(41);
        thrusters[i].setOrigin(prms.GUPPIE_RAD - 0.1f, prms.GUPPIE_RAD - 0.1f);
    }
    thrusters[0].setPoint(0, sf::Vector2f(0.4863f, 0.0094f));
    for (int i = 0; i < 38; ++i)
    {
        thrusters[0].setPoint(i + 1, thTemp.getPoint(i + 7));
    }
    thrusters[0].setPoint(39, sf::Vector2f(0.7999f, 0.39f));
    thrusters[0].setPoint(40, sf::Vector2f(prms.GUPPIE_RAD - 0.1f, 0.39f));
    for (int i = 0; i < 41; ++i)
    {
        sf::Vector2f p1 = vecMult(thrusters[0].getPoint(i), sf::Vector2f(-1.f, 1.f)) + sf::Vector2f((prms.GUPPIE_RAD - 0.1f) * 2.f, 0.f);
        sf::Vector2f p2 = vecMult(thrusters[0].getPoint(i), sf::Vector2f(1.f, -1.f)) + sf::Vector2f(0.f, (prms.GUPPIE_RAD - 0.1f) * 2.f);
        sf::Vector2f p3 = vecMult(thrusters[0].getPoint(i), sf::Vector2f(-1.f, -1.f)) + sf::Vector2f((prms.GUPPIE_RAD - 0.1f) * 2.f, (prms.GUPPIE_RAD - 0.1f) * 2.f);
        thrusters[1].setPoint(i, p1);
        thrusters[2].setPoint(i, p2);
        thrusters[3].setPoint(i, p3);
    }
    // Draw thruster mask
    thrusterMask.setFillColor(guppN);
    thrusterMask.setPointCount(48);
    thrusterMask.setPoint(0, sf::Vector2f(0.0863f, -0.3906f));
    thrusterMask.setPoint(1, sf::Vector2f(0.214f, -0.1694f));
    thrusterMask.setPoint(2, sf::Vector2f(0.2148f, -0.1679f));
    thrusterMask.setPoint(3, sf::Vector2f(0.2237f, -0.1509f));
    thrusterMask.setPoint(4, sf::Vector2f(0.2313f, -0.1335f));
    thrusterMask.setPoint(5, sf::Vector2f(0.2377f, -0.1159f));
    thrusterMask.setPoint(6, sf::Vector2f(0.2429f, -0.0981f));
    thrusterMask.setPoint(7, sf::Vector2f(0.2471f, -0.0803f));
    thrusterMask.setPoint(8, sf::Vector2f(0.2504f, -0.0624f));
    thrusterMask.setPoint(9, sf::Vector2f(0.2527f, -0.0446f));
    thrusterMask.setPoint(10, sf::Vector2f(0.2542f, -0.0267f));
    thrusterMask.setPoint(11, sf::Vector2f(0.2549f, -0.01f));
    for (int i = 0; i < 12; ++i)
    {
        thrusterMask.setPoint(i + 12, vecMult(thrusterMask.getPoint(11 - i), sf::Vector2f(1.f, -1.f)));
    }
    for (int i = 0; i < 24; ++i)
    {
        thrusterMask.setPoint(i + 24, vecMult(thrusterMask.getPoint(23 - i), sf::Vector2f(-1.f, 1.f)));
    }
    // Draw heart
    heart.setPointCount(43);
    heart.setPoint(0, sf::Vector2f(0.1883f, -0.1321f));
    heart.setPoint(1, sf::Vector2f(0.1901f, -0.1282f));
    heart.setPoint(2, sf::Vector2f(0.1962f, -0.1133f));
    heart.setPoint(3, sf::Vector2f(0.2013f, -0.0982f));
    heart.setPoint(4, sf::Vector2f(0.2055f, -0.0830f));
    heart.setPoint(5, sf::Vector2f(0.2088f, -0.0679f));
    heart.setPoint(6, sf::Vector2f(0.2114f, -0.0527f));
    heart.setPoint(7, sf::Vector2f(0.2132f, -0.0376f));
    heart.setPoint(8, sf::Vector2f(0.2144f, -0.0225f));
    heart.setPoint(9, sf::Vector2f(0.2149f, -0.0075f));
    for (int i = 0; i < 9; ++i)
    {
        heart.setPoint(i + 10, vecMult(heart.getPoint(9 - i), sf::Vector2f(1.f, -1.f)));
    }
    heart.setPoint(19, sf::Vector2f(0.1829f, 0.1429f));
    heart.setPoint(20, sf::Vector2f(0.1793f, 0.1494f));
    heart.setPoint(21, sf::Vector2f(0.f, 0.46f));
    for (int i = 0; i < 21; ++i)
    {
        heart.setPoint(i + 22, vecMult(heart.getPoint(20 - i), sf::Vector2f(-1.f, 1.f)));
    }
    // Draw heart mask
    heartMask.setFillColor(guppN);
    heartMask.setPointCount(37);
    heartMask.setPoint(0, sf::Vector2f(0.1655f, -0.078f));
    heartMask.setPoint(1, sf::Vector2f(0.168f, -0.0679f));
    heartMask.setPoint(2, sf::Vector2f(0.1705f, -0.0554f));
    heartMask.setPoint(3, sf::Vector2f(0.1723f, -0.043f));
    heartMask.setPoint(4, sf::Vector2f(0.1737f, -0.0306f));
    heartMask.setPoint(5, sf::Vector2f(0.1745f, -0.0183f));
    heartMask.setPoint(6, sf::Vector2f(0.1749f, -0.0061f));
    for (int i = 0; i < 6; ++i)
    {
        heartMask.setPoint(i + 7, vecMult(heartMask.getPoint(6 - i), sf::Vector2f(1.f, -1.f)));
    }
    heartMask.setPoint(13, sf::Vector2f(0.1648f, 0.0804f));
    heartMask.setPoint(14, sf::Vector2f(0.1610f, 0.093f));
    heartMask.setPoint(15, sf::Vector2f(0.1563f, 0.1055f));
    heartMask.setPoint(16, sf::Vector2f(0.1508f, 0.1178f));
    heartMask.setPoint(17, sf::Vector2f(0.1447f, 0.1294f));
    heartMask.setPoint(18, sf::Vector2f(0.f, 0.38f));
    for (int i = 0; i < 18; ++i)
    {
        heartMask.setPoint(i + 19, vecMult(heartMask.getPoint(17 - i), sf::Vector2f(-1.f, 1.f)));
    }
    // Draw heart top
    heartTop.setPointCount(8);
    heartTop.setPoint(0, sf::Vector2f(-0.1655f, -0.0780f));
    heartTop.setPoint(1, sf::Vector2f(-0.1401f, -0.0689f));
    heartTop.setPoint(2, sf::Vector2f(-0.1097f, -0.0601f));
    heartTop.setPoint(3, sf::Vector2f(-0.1025f, -0.0584f));
    for (int i = 0; i < 4; ++i)
    {
        heartTop.setPoint(i + 4, vecMult(heartTop.getPoint(3 - i), sf::Vector2f(-1.f, 1.f)));
    }
    // Draw heart triangle
    heartTri.setPointCount(3);
    heartTri.setPoint(0, sf::Vector2f(-0.1025f, -0.0584f));
    heartTri.setPoint(1, sf::Vector2f(0.f, 0.0935f));
    heartTri.setPoint(2, sf::Vector2f(0.1025f, -0.0584f));
    // Draw gland mask
    glandMask.setFillColor(guppN);
    glandMask.setPointCount(3);
    glandMask.setPoint(0, sf::Vector2f(-0.0783f, -0.0942f));
    glandMask.setPoint(1, sf::Vector2f(0.f, 0.022f));
    glandMask.setPoint(2, sf::Vector2f(0.0783f, -0.0942f));
    // Draw gland
    gland.setPointCount(3);
    gland.setPoint(0, sf::Vector2f(-0.0513f, -0.0899f));
    gland.setPoint(1, sf::Vector2f(0.f, -0.0138f));
    gland.setPoint(2, sf::Vector2f(0.0513f, -0.0899f));
    // Draw eye mask
    sf::CircleShape emTemp = sf::CircleShape(0.4133f, 180);
    eyeMask.setFillColor(guppN);
    eyeMask.setOrigin(0.4133f, 0.9133f);
    eyeMask.setPointCount(32);
    for (int i = 0; i < 31; ++i)
    {
        eyeMask.setPoint(i, emTemp.getPoint(i + 75));
    }
    eyeMask.setPoint(31, sf::Vector2f(0.4133f, 0.4133f));
    // Draw eye cells
    sf::CircleShape ecTemp = sf::CircleShape(0.3933f, 180);
    for (int i = 0; i < 15; ++i)
    {
        eyeCells[i].setPointCount(4);
        eyeCells[i].setOrigin(0.3933f, 0.8933f);
        for (int j = 0; j < 3; ++j)
        {
            eyeCells[i].setPoint(j, ecTemp.getPoint(i * 2 + j + 75));
        }
        eyeCells[i].setPoint(3, sf::Vector2f(0.3933f, 0.3933f));
    }
    // Draw eye cavity
    sf::CircleShape ekTemp = sf::CircleShape(0.3333f, 180);
    eyeCavity.setPointCount(32);
    eyeCavity.setFillColor(prms.worldColor);
    eyeCavity.setOrigin(0.3333f, 0.8333f);
    for (int i = 0; i < 31; ++i)
    {
        eyeCavity.setPoint(i, ekTemp.getPoint(i + 75));
    }
    eyeCavity.setPoint(31, sf::Vector2f(0.3333f, 0.3333f));
}
