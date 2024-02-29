#ifndef __GUPPIE_HPP__
#define __GUPPIE_HPP__

#include <NeuralNet.hpp>
#include "Entity.hpp"

class Guppie : public Entity
{
public:
    void startup(SimBase *sim);
    void update();
    void draw();

private:
    void destroy();
    void clean();

    // State variables
    bool isActive = false;
    unsigned lifetime = 0;
    double fitness = 0;
    float energy = 0.f;
    sf::Color skinColor;
    enum gs { ALPHA = 0, BETTA = 1, GAMMA = 2 } glandState;
//    float nGland1 = 0.f;
//    float nGland2 = 0.f;
//    float nGland3 = 0.f;
    enum lc { ZAPPER, PELLET, CORPSE, GUPPIE } lastContact;
    unsigned lastContactStep = 0;

    // Sensors
    std::vector<float> eyeR = std::vector<float>(15, 0.f);
    std::vector<float> eyeG = std::vector<float>(15, 0.f);
    std::vector<float> eyeB = std::vector<float>(15, 0.f);
    std::vector<float> touch = std::vector<float>(30, 0.f);
//    std::vector<float> smell = std::vector<float>(30, 0.f);
    float cColorR = 0.f, cColorG = 0.f, cColorB = 0.f;
//    float cGland1 = 0.f, cGland2 = 0.f, cGland3 = 0.f;
    float fwdSpeed = 0.f;
    float sideSpeed = 0.f;
    float rotation = 0.f;
    float lowEnergy = 0.f;

    // Neural net
    std::shared_ptr<NeuralNet> neuralNet;

    // Outputs
    float thruster1 = 0.f, thruster2 = 0.f;
    float addClrR = 0.f, addClrG = 0.f, addClrB = 0.f;
//    float addGln1 = 0.f, addGln2 = 0.f, addGln3 = 0.f;

    friend class ContactListener;
    friend class SimFitness;
    friend class Entity;
    friend class Camera;
};

#endif // __GUPPIE_HPP__
