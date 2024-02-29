#include "Guppie.hpp"
#include "SimFitness.hpp"

void Guppie::startup(SimBase *sim)
{
    hSim = sim;
    radius = Params::GUPPIE_RAD;
}

void Guppie::update()
{
    if (!body)
    {
        return;
    }

    // Update states
    ++lifetime;

    if (lifetime < hSim->prms.activationDelay)
    {
        return;
    }

    if (lifetime == hSim->prms.activationDelay)
    {
        isActive = true;
        skinColor = hSim->guppN;
        glandState = ALPHA;

        ((b2CircleShape *)body->GetFixtureList()->GetShape())->m_radius = hSim->prms.GUPPIE_RAD;
    }

    fitness += energy;

    energy -= (1.f / 60.f) + (float)lifetime / (hSim->prms.agingRate * 3600.f);

    if (energy < 0.f)
    {
        destroy();
        return;
    }

    if (lastContactStep)
    {
        --lastContactStep;
    }

    if (skinColor.r)
    {
        skinColor.r -= 1;
    }
    if (skinColor.g)
    {
        skinColor.g -= 1;
    }
    if (skinColor.b)
    {
        skinColor.b -= 1;
    }

    // Update sensors
    sf::Transform trans;
    trans.translate(body->GetPosition().x, body->GetPosition().y);
    trans.rotate(body->GetAngle() * Params::RAD_DGRS);
    // Eye sensors
    sf::Vector2f eyePoint = trans.transformPoint(hSim->visionCone[30]);
    for (int i = 0; i < 15; ++i)
    {
        RayCastCallback points[2];
        sf::Color colors[2];
        for (int j = 0; j < 2; ++j)
        {
            colors[j] = hSim->prms.worldColor;
            sf::Vector2f eyeLine = trans.transformPoint(hSim->visionCone[i * 2 + j]);
            hSim->tank.world.RayCast(&points[j], b2Vec2(eyePoint.x, eyePoint.y), b2Vec2(eyeLine.x, eyeLine.y));
            if (points[j].m_fixture)
            {
                if (points[j].m_fixture->GetBody()->GetType() == b2_staticBody)
                {
                    colors[j] = mix(hSim->prms.worldColor, hSim->prms.zapperColor, points[j].m_fraction);
                }
                else
                {
                    Entity *entity = (Entity *)points[j].m_fixture->GetBody()->GetUserData();
                    if (entity->radius == Params::ZAPPER_RAD)
                    {
                        colors[j] = mix(hSim->prms.worldColor, hSim->prms.zapperColor, points[j].m_fraction);
                    }
                    else if (entity->radius == Params::EGG_RAD)
                    {
                        colors[j] = mix(hSim->prms.worldColor, hSim->guppN, points[j].m_fraction);
                    }
                    else if (entity->radius == Params::PELLET_RAD)
                    {
                        colors[j] = mix(hSim->prms.worldColor, hSim->prms.pelletColor, points[j].m_fraction);
                    }
                    else if (entity->radius == Params::CORPSE_RAD)
                    {
                        sf::Color corpseColor = mix(hSim->prms.corpseColor, hSim->prms.worldColor, ((float)((Corpse *)entity)->lifetime / (float)hSim->prms.corpseDecayTime));
                        colors[j] = mix(hSim->prms.worldColor, corpseColor, points[j].m_fraction);
                    }
                    else if (entity->radius == Params::GUPPIE_RAD)
                    {
                        if (!((Guppie *)entity)->isActive)
                        {
                            colors[j] = mix(hSim->prms.worldColor, hSim->guppN, points[j].m_fraction);
                        }
                        else
                        {
                            colors[j] = mix(hSim->prms.worldColor, ((Guppie *)entity)->skinColor, points[j].m_fraction);
                        }
                    }
                }
            }
        }

        sf::Color sum = mix(colors[0], colors[1], 0.5f);
        eyeR[i] = (float)sum.r / 256.f;
        eyeG[i] = (float)sum.g / 256.f;
        eyeB[i] = (float)sum.b / 256.f;
    }
    // Skin sensors
    for (int i = 0; i < 30; ++i)
    {
        RayCastCallback points[6];
        float valueTouch = 0.f;
//        float valueSmell = 0.f;
        for (int j = 0; j < 6; ++j)
        {
            sf::Vector2f skinPoint = trans.transformPoint(hSim->skinRadius[i * 6 + j]);
            sf::Vector2f senseLine = trans.transformPoint(hSim->senseRadius[i * 6 + j]);
            hSim->tank.world.RayCast(&points[j], b2Vec2(skinPoint.x, skinPoint.y), b2Vec2(senseLine.x, senseLine.y));
            if (points[j].m_fixture)
            {
                valueTouch += 1.f - points[j].m_fraction;
                // FOR SWARM SIMULATION STYLE
//                if (points[j].m_fixture->GetBody()->GetType() == b2_dynamicBody)
//                {
//                    Entity *entity = (Entity *)points[j].m_fixture->GetBody()->GetUserData();
//                    if (entity->radius == Params::GUPPIE_RAD)
//                    {
//                        if (((Guppie *)entity)->isActive)
//                        {
//                            if (((Guppie *)entity)->glandState == glandState)
//                            {
//                                valueSmell += 1.f - points[j].m_fraction;
//                            }
//                        }
//                    }
//                }
            }
        }

        touch[i] = valueTouch / 6.f;
//        smell[i] = valueSmell / 6.f;
    }
    // Current color sensor
    cColorR = (float)skinColor.r / 255.f;
    cColorG = (float)skinColor.g / 255.f;
    cColorB = (float)skinColor.b / 255.f;
    // Current gland color sensor
//    cGland1 = 0.f;
//    cGland2 = 0.f;
//    cGland3 = 0.f;
//    if (glandState == ALPHA)
//    {
//        cGland1 = 1.f;
//    }
//    else if (glandState == BETTA)
//    {
//        cGland2 = 1.f;
//    }
//    else
//    {
//        cGland3 = 1.f;
//    }
    // Speed sensors
    b2Vec2 axisSpeed = body->GetLinearVelocity();
    sf::Transform rotat;
    rotat.rotate(body->GetAngle() * Params::RAD_DGRS);
    sf::Vector2f fwdDirect = rotat.transformPoint(sf::Vector2f(0.f, -1.f));
    sf::Vector2f sdeDirect = rotat.transformPoint(sf::Vector2f(1.f, 0.f));
    fwdSpeed = sigmoid(axisSpeed.x * fwdDirect.x + axisSpeed.y * fwdDirect.y);
    sideSpeed = sigmoid(axisSpeed.x * sdeDirect.x + axisSpeed.y * sdeDirect.y);
    // Rotation sensor
    rotation = sigmoid(body->GetAngularVelocity());
    // Low energy sensor
    lowEnergy = sigmoid(energy / 10.f) * 2.f - 1.f;

    // Merge inputs and get response from neural net
    std::vector<float> inputs;
    inputs.insert(inputs.end(), eyeR.begin(), eyeR.end());
    inputs.insert(inputs.end(), eyeG.begin(), eyeG.end());
    inputs.insert(inputs.end(), eyeB.begin(), eyeB.end());
    inputs.insert(inputs.end(), touch.begin(), touch.end());
//    inputs.insert(inputs.end(), smell.begin(), smell.end());
    inputs.push_back(cColorR);
    inputs.push_back(cColorG);
    inputs.push_back(cColorB);
//    inputs.push_back(cGland1);
//    inputs.push_back(cGland2);
//    inputs.push_back(cGland3);
    inputs.push_back(fwdSpeed);
    inputs.push_back(sideSpeed);
    inputs.push_back(rotation);
    inputs.push_back(lowEnergy);

    std::vector<float> outputs = neuralNet->io(inputs);

    // Apply outputs
    thruster1 = outputs[0];
    thruster2 = outputs[1];
    addClrR = outputs[2];
    addClrG = outputs[3];
    addClrB = outputs[4];
//    addGln1 = outputs[5];
//    addGln2 = outputs[6];
//    addGln3 = outputs[7];

    // Handle outputs
    // Guppies gain fitness by going straight forward
    if (thruster1 + thruster2 > 1.f)
    {
        float forwardness = thruster1 + thruster2 - 1.f;
        fitness += forwardness * hSim->prms.forGoingStraight;
    }

    // Apply thrust
    sf::Vector2f leftThrustPoint = trans.transformPoint(-hSim->prms.thrustRadius, 0.f);
    sf::Vector2f rightThrustPoint = trans.transformPoint(hSim->prms.thrustRadius, 0.f);

    thruster1 = thruster1 * 2.f - 1.f;
    sf::Vector2f thrLeft = rotat.transformPoint(-hSim->prms.thrustRadius, thruster1 * hSim->prms.thrustForce);
    body->ApplyForce(b2Vec2(thrLeft.x, thrLeft.y), b2Vec2(leftThrustPoint.x, leftThrustPoint.y));

    thruster2 = thruster2 * 2.f - 1.f;
    sf::Vector2f thrRight = rotat.transformPoint(hSim->prms.thrustRadius, thruster2 * hSim->prms.thrustForce);
    body->ApplyForce(b2Vec2(thrRight.x, thrRight.y), b2Vec2(rightThrustPoint.x, rightThrustPoint.y));
    // Substract energy
//    energy -= fabsf(thruster1 / 60.f);
//    energy -= fabsf(thruster2 / 60.f);

    // Apply color change
    float temp = 0.f;
    if ((temp = skinColor.r + addClrR * 8.f) < 255)
    {
        skinColor.r += temp;
    }
    else
    {
        skinColor.r = 255;
    }
    if ((temp = skinColor.g + addClrG * 8.f) < 255)
    {
        skinColor.g += temp;
    }
    else
    {
        skinColor.g = 255;
    }
    if ((temp = skinColor.b + addClrB * 8.f) < 255)
    {
        skinColor.b += temp;
    }
    else
    {
        skinColor.b = 255;
    }
    // Substract energy
//    energy -= addClrR / 60.f;
//    energy -= addClrG / 60.f;
//    energy -= addClrB / 60.f;
    // Apply gland change
//    nGland1 += addGln1;
//    nGland2 += addGln2;
//    nGland3 += addGln3;
//    bool changeGln = false;
//    if (nGland1 > 30.f)
//    {
//        glandState = ALPHA;
//        changeGln = true;
//    }
//    else if (nGland2 > 30.f)
//    {
//        glandState = BETTA;
//        changeGln = true;
//    }
//    else if (nGland3 > 30.f)
//    {
//        glandState = GAMMA;
//        changeGln = true;
//    }
//    if (changeGln)
//    {
//        nGland1 = 0.f;
//        nGland2 = 0.f;
//        nGland3 = 0.f;
//    }
//    // Substract energy
//    energy -= addGln1 / 60.f;
//    energy -= addGln2 / 60.f;
//    energy -= addGln3 / 60.f;

    if (hSim->prms.simStyle == SELECTION_BY_FITNESS)
    {
        if (fitness > ((SimFitness *)hSim)->fitnessRecord)
        {
            ((SimFitness *)hSim)->fitnessRecord = fitness;
            hSim->text.longestLife.setString("Fitness record: " + nts(((SimFitness *)hSim)->fitnessRecord));
        }
    }
}


void Guppie::destroy()
{
    if (!body)
    {
        return;
    }

    --hSim->guppieCount;
    hSim->text.guppieCnt.setString("Guppie count: " + nts(hSim->guppieCount));

    // Place a corpse
    if (hSim->prms.leaveCorpse)
    {
        bool vacant = false;
        for (auto &i : hSim->corpses)
        {
            if (!i.isCreated())
            {
                i.create();
                i.setup(body->GetPosition(), body->GetLinearVelocity(), body->GetAngle(), body->GetAngularVelocity());
                if (hSim->camera.trgtBody == body)
                {
                    hSim->camera.trgtBody = i.body;
                }
                vacant = true;
                break;
            }
        }
        if (!vacant)
        {
            hSim->corpses.push_back(Corpse());
            hSim->corpses.back().startup(hSim);
            hSim->corpses.back().create();
            hSim->corpses.back().setup(body->GetPosition(), body->GetLinearVelocity(), body->GetAngle(), body->GetAngularVelocity());
            if (hSim->camera.trgtBody == body)
            {
                hSim->camera.trgtBody = hSim->corpses.back().body;
            }
        }
    }
    else if (hSim->camera.trgtBody == body)
    {
        hSim->camera.trgtBody = nullptr;
    }

    hSim->tank.world.DestroyBody(body);
    body = nullptr;
}


void Guppie::draw()
{
    if (!body)
    {
        return;
    }

    sf::Vector2f vSize = hSim->window.getView().getSize();
    sf::Vector2f vCent = hSim->window.getView().getCenter();
    if ( body->GetPosition().x + radius < vCent.x - vSize.x / 2.f ||
         body->GetPosition().y + radius < vCent.y - vSize.y / 2.f ||
         body->GetPosition().x - radius > vCent.x + vSize.x / 2.f ||
         body->GetPosition().y - radius > vCent.y + vSize.y / 2.f  )
    {
        return;
    }

    if (hSim->camera.zoom > Params::GUPPIE_RAD)
    {
        float blend = sigmoid((hSim->camera.zoom - Params::GUPPIE_RAD) * 8.f);
        if (isActive)
        {
            hSim->guppiePoint.setFillColor(mix(hSim->prms.worldColor, skinColor, blend));
        }
        else
        {
            hSim->guppiePoint.setFillColor(mix(hSim->prms.worldColor, hSim->guppN, blend));
        }

        hSim->guppiePoint.setPosition(body->GetPosition().x, body->GetPosition().y);
        hSim->window.draw(hSim->guppiePoint);
        return;
    }

    // Position and rotate
    float posX = body->GetPosition().x;
    float posY = body->GetPosition().y;
    float rot = body->GetAngle() * Params::RAD_DGRS;
    sf::ConvexShape *shape = nullptr;

    hSim->gOuterSkin.setPosition(posX, posY);
    for (shape = &hSim->beak1; shape <= &hSim->tailMask; ++shape)
    {
        shape->setPosition(posX, posY);
        shape->setRotation(rot);
    }
    hSim->innerBodyMask.setPosition(posX, posY);
    hSim->innerBodyMask.setRotation(rot);
    for (shape = hSim->thrusters; shape <= &hSim->eyeCavity; ++shape)
    {
        shape->setPosition(posX, posY);
        shape->setRotation(rot);
    }

    // Apply colors
    // When inactive
    if (!isActive)
    {
        // Skin
        hSim->beak1.setFillColor(hSim->guppN);
        hSim->beak2.setFillColor(hSim->guppN);
        hSim->gOuterSkin.setFillColor(hSim->guppN);
        for (int i = 0; i < 15; ++i)
        {
            hSim->eyeCells[i].setFillColor(hSim->prms.worldColor);
        }
        for (int i = 0; i < 30; ++i)
        {
            hSim->touchCells[i].setFillColor(hSim->guppN);
            hSim->smellCells[i].setFillColor(hSim->guppN);
        }
        // Thrusters
        for (int i = 0; i < 4; ++i)
        {
            hSim->thrusters[i].setFillColor(hSim->guppN);
        }
        // Heart
        hSim->heart.setFillColor(hSim->guppN);
        hSim->heartTop.setFillColor(hSim->guppN);
        hSim->heartTri.setFillColor(hSim->guppN);
        hSim->heartMask.setFillColor(hSim->guppN);
        // Gland
        hSim->gland.setFillColor(hSim->guppN);
    }
    // When active
    else
    {
        // Outer skin
        hSim->beak1.setFillColor(skinColor);
        hSim->beak2.setFillColor(skinColor);
        hSim->gOuterSkin.setFillColor(skinColor);
        // Eye cells
        for (int i = 0; i < 15; ++i)
        {
            sf::Color cellColor;
            cellColor.r = eyeR[i] * 255.f;
            cellColor.g = eyeG[i] * 255.f;
            cellColor.b = eyeB[i] * 255.f;
            hSim->eyeCells[i].setFillColor(cellColor);
        }
        // Skin cells
        for (int i = 0; i < 30; ++i)
        {
            hSim->touchCells[i].setFillColor(mix(hSim->prms.guppieColorI, hSim->guppN, touch[i]));
//            hSim->smellCells[i].setFillColor(mix(hSim->prms.guppieColorI, hSim->guppN, smell[i]));
        }
        // Thrusters
        if (thruster1 > 0.f)
        {
            hSim->thrusters[3].setFillColor(mix(hSim->prms.guppieColorI, hSim->guppN, thruster1));
            hSim->thrusters[1].setFillColor(hSim->guppN);
        }
        else
        {
            hSim->thrusters[1].setFillColor(mix(hSim->prms.guppieColorI, hSim->guppN, -thruster1));
            hSim->thrusters[3].setFillColor(hSim->guppN);
        }

        if (thruster2 > 0.f)
        {
            hSim->thrusters[2].setFillColor(mix(hSim->prms.guppieColorI, hSim->guppN, thruster2));
            hSim->thrusters[0].setFillColor(hSim->guppN);
        }
        else
        {
            hSim->thrusters[0].setFillColor(mix(hSim->prms.guppieColorI, hSim->guppN, -thruster2));
            hSim->thrusters[2].setFillColor(hSim->guppN);
        }
        // Heart beat
        sf::Color beat = mix(hSim->guppN, hSim->prms.guppieColorI, sinf(((float)lifetime * (1.f + (1.f - lowEnergy))) / 15.f) / 2.f + 0.5f);
        hSim->heart.setFillColor(beat);
        hSim->heartTop.setFillColor(beat);
        hSim->heartTri.setFillColor(beat);
        // Stomach
        if (lastContactStep)
        {
            if (lastContact == ZAPPER)
            {
                hSim->heartMask.setFillColor(mix(hSim->prms.zapperColor, hSim->guppN, (float)lastContactStep / (float)hSim->prms.contactSteps));
            }
            else if (lastContact == PELLET)
            {
                hSim->heartMask.setFillColor(mix(hSim->prms.pelletColor, hSim->guppN, (float)lastContactStep / (float)hSim->prms.contactSteps));
            }
            else if (lastContact == CORPSE)
            {
                hSim->heartMask.setFillColor(mix(hSim->prms.corpseColor, hSim->guppN, (float)lastContactStep / (float)hSim->prms.contactSteps));
            }
            else
            {
                hSim->heartMask.setFillColor(mix(hSim->prms.guppieColorI, hSim->guppN, (float)lastContactStep / (float)hSim->prms.contactSteps));
            }
        }
        else
        {
            hSim->heartMask.setFillColor(hSim->guppN);
        }
        // Gland
        if (glandState == ALPHA)
        {
            hSim->gland.setFillColor(hSim->prms.glandColor1);
        }
        else if (glandState == BETTA)
        {
            hSim->gland.setFillColor(hSim->prms.glandColor2);
        }
        else
        {
            hSim->gland.setFillColor(hSim->prms.glandColor3);
        }
    }

    // Draw
    hSim->window.draw(hSim->gOuterSkin);
    for (shape = &hSim->beak1; shape <= &hSim->tailMask; ++shape)
    {
        hSim->window.draw(*shape);
    }
    hSim->window.draw(hSim->innerBodyMask);
    for (shape = hSim->thrusters; shape <= &hSim->eyeCavity; ++shape)
    {
        hSim->window.draw(*shape);
    }

    if (hSim->camera.zoom > 0.02f)
    {
        if (isActive)
        {
            hSim->guppieShell.setOutlineColor(skinColor);
        }
        else
        {
            hSim->guppieShell.setOutlineColor(hSim->guppN);
        }

        hSim->guppieShell.setPosition(body->GetPosition().x, body->GetPosition().y);
        hSim->window.draw(hSim->guppieShell);
    }

    if (!isActive)
    {
        hSim->guppieEgg.setPosition(body->GetPosition().x, body->GetPosition().y);
        hSim->window.draw(hSim->guppieEgg);
    }
}


void Guppie::clean()
{
    isActive = false;
    lifetime = 0;
    fitness = 0.;
    energy = 0.f;
    skinColor = hSim->guppN;
//    nGland1 = 0.f;
//    nGland2 = 0.f;
//    nGland3 = 0.f;
    lastContactStep = 0;
}
