#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include <SFML/Graphics.hpp>
#include <Box2D.h>

class SimBase;

class Camera
{
public:
    void create(SimBase *sim);
    void onResize();
    void onClick();
    void shift(const sf::Vector2f &newTrgtCrds, int zoomInOut = 0, bool release = true);
    void update();

    sf::Vector2f getCrds() const { return currentCrds; }
    float getZoom() const { return zoom; }

private:
    SimBase *hSim = nullptr;

    float defaultZoom = 0.f;
    float zoom = 0.f;
    float prevZoom = 0.f;
    float trgtZoom = 0.f;
    sf::Vector2f currentCrds = { 0.f, 0.f };
    sf::Vector2f prevCrds = { 0.f, 0.f };
    sf::Vector2f trgtCrds = { 0.f, 0.f };
    unsigned step = 0;
    bool isOnFollow = false;
    b2Body *trgtBody = nullptr;

    friend class ContactListener;
    friend class Zapper;
    friend class Pellet;
    friend class Guppie;
    friend class Corpse;
};

#endif // __CAMERA_HPP__
