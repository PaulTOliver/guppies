#ifndef __PARAMS_HPP__
#define __PARAMS_HPP__

#include <sstream>
#include <cmath>

#include <SFML/Graphics.hpp>
#include <Box2D.h>

#include <NeuralNetworks.hpp>


enum SimStyle
{
	SELECTION_BY_FITNESS
};

struct Params
{
	// Variable parameters must be defined before simulation starts

	// Simulation params
	SimStyle simStyle = SELECTION_BY_FITNESS;
	// If selection by fitness
	NeuralNetClass netClass = SIMPLE_RN;
	NodeClass nodeClass = MEMORY_CELL;
	unsigned npHiddenLayer = 80;
	unsigned popSize = 30;
	unsigned popQtty = 10;
	unsigned elites  = 30;

	// World params
	float worldRad = 40.f;

	// Entity params
	float zapperForce = 50.f;//100
	float zapperTorque = 150.f;//300
	unsigned zapperQtty = 20;
	unsigned pelletQtty = 400;
	unsigned pelletCreationDelay = 150;
	bool startScarce = false;
	bool corpseDecay = true;
	float corpseDecayTime = 3600.f;

	// Goopy params
	unsigned activationDelay = 120;
	unsigned contactSteps = 15;
	float thrustForce = 5.f;
	float thrustRadius = 0.05f;
	float initEnergy = 60.f;
	float maxEnergy = 180.f;
	float agingRate = 600.f;
	bool leaveCorpse = true;

	// Energy transfers
	float etFromZapper = -20.f;
	float etFromPellet = 15.f;
	float etFromGuppie = 60.f;
	float etFromCorpse = 60.f;

	// Fitness bonus
	float forPellet = 9000.f;
	float forGuppie = 36000.f;
	float forCorpse = 36000.f;
	float forGoingStraight = 12.f;

	// Colors
	sf::Color clearColor    = {   0,   0,  10 };
	sf::Color worldColor    = {   0,   0,   0 };
	sf::Color textColor     = { 191, 191, 191 };
	sf::Color zapperColor   = {   0,   0, 255 };
	sf::Color pelletColor   = {   0, 255,   0 };
	sf::Color corpseColor   = {   0, 255,   0 };
	sf::Color guppieColorI  = { 255,   0,   0 };
	sf::Color glandColor1   = { 255, 127,   0 };
	sf::Color glandColor2   = {   0, 255, 127 };
	sf::Color glandColor3   = { 127,   0, 255 };


	// Constant values cant be changed
	constexpr static unsigned WIN_WIDTH = 800;
	constexpr static unsigned WIN_HEIGHT = 600;
	constexpr static unsigned ANTIALIAS = 8;
	constexpr static unsigned CAM_STEPS = 8;
	constexpr static float ZAPPER_RAD = 5.f;
	constexpr static float GUPPIE_RAD = 0.5f;
	constexpr static float EGG_RAD    = 1.5f;
	constexpr static float CORPSE_RAD = 0.25f;
	constexpr static float PELLET_RAD = 0.1f;
	constexpr static float TXT_SIZE = 12.f;
	constexpr static float MAX_ZOOM = 0.002f;
	constexpr static float RAD_DGRS = 57.2957795f;
};


// Utility functions
template <class T>
inline std::string nts(T num)
{
    std::ostringstream ss;
    ss << num;
    return ss.str();
}


inline sf::Vector2f vecMult(const sf::Vector2f &v1, const sf::Vector2f &v2)
{
    return sf::Vector2f(v1.x * v2.x, v1.y * v2.y);
}


inline void setCenterRad(sf::CircleShape &circle, float radius)
{
    circle.setRadius(radius);
    circle.setOrigin(radius, radius);
}


inline sf::Color mix(const sf::Color &clr1, const sf::Color &clr2, float f1 = 0.2f)
{
    sf::Color result;
    float f2 = 1.f - f1;

    result.r = clr1.r * f1 + clr2.r * f2;
    result.g = clr1.g * f1 + clr2.g * f2;
    result.b = clr1.b * f1 + clr2.b * f2;

    return result;
}


// Utility classes
class QueryCallback : public b2QueryCallback
{
public:
    bool ReportFixture(b2Fixture* fixture)
    {
		b2Body* body = fixture->GetBody();
		if (body->GetType() != b2_staticBody)
		{
			bool inside = fixture->TestPoint(m_point);
			if (inside)
			{
				m_fixture = fixture;
				return false;
			}
		}

		return true;
	}

	b2Vec2 m_point;
	b2Fixture *m_fixture = nullptr;
};


class RayCastCallback : public b2RayCastCallback
{
public:
    float32 ReportFixture(b2Fixture *fixture, const b2Vec2 &point, const b2Vec2 &normal, float32 fraction)
    {
        m_fixture = fixture;
        m_fraction = fraction;

        return fraction;
    }

    float m_fraction = 0.f;
    b2Fixture *m_fixture = nullptr;
};

#endif // __PARAMS_HPP__
