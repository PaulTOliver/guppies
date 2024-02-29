#ifndef __GRAPHICOBJS_HPP__
#define __GRAPHICOBJS_HPP__

#include <SFML/Graphics.hpp>

class GraphicObjs
{
protected:
    sf::CircleShape zapperPoint = sf::CircleShape(0, 12);
    sf::CircleShape zapperShell;
    sf::CircleShape zapperNucleus = sf::CircleShape(0, 5);

    sf::CircleShape pelletPoint = sf::CircleShape(0, 6);
	sf::CircleShape pelletShell;
	sf::CircleShape pelletNucleus = sf::CircleShape(0, 3);

	sf::CircleShape guppiePoint = sf::CircleShape(0, 6);
	sf::CircleShape guppieShell = sf::CircleShape(0, 30);
	///////////////
	sf::CircleShape eggPoint = sf::CircleShape(0, 6);
	sf::CircleShape guppieEgg = sf::CircleShape(0, 60);
	///////////////
	sf::Color guppN;
	sf::Vector2f visionCone[31];
	sf::Vector2f skinRadius[180];
	sf::Vector2f senseRadius[180];
	/////////////////////////////
	sf::CircleShape gOuterSkin;
	///////////////////////////
	sf::ConvexShape beak1;
	sf::ConvexShape beak2;
	///////////////////////////
	sf::ConvexShape touchCells[30];
	sf::ConvexShape smellCells[30];
	sf::ConvexShape tailMask;
	//////////////////////////////
	sf::CircleShape innerBodyMask;
	/////////////////////////////
	sf::ConvexShape thrusters[4];
	sf::ConvexShape thrusterMask;
	sf::ConvexShape heart;
	sf::ConvexShape heartMask;
	sf::ConvexShape heartTop;
	sf::ConvexShape heartTri;
	sf::ConvexShape glandMask;
	sf::ConvexShape gland;
	sf::ConvexShape eyeMask;
	sf::ConvexShape eyeCells[15];
	sf::ConvexShape eyeCavity;

    sf::CircleShape corpsePoint = sf::CircleShape(0, 6);
	sf::CircleShape corpseShell;
	sf::CircleShape corpseNucleus = sf::CircleShape(0, 4);
};

#endif // __GRAPHICOBJS_HPP__
