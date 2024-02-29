#include "ContactListener.hpp"
#include "SimBase.hpp"

void ContactListener::PreSolve(b2Contact *contact, const b2Manifold *oldManifold)
{
    b2Body *bodyA = contact->GetFixtureA()->GetBody();
    b2Body *bodyB = contact->GetFixtureB()->GetBody();

    Guppie *gp1 = nullptr;
    Guppie *gp2 = nullptr;

    if (bodyA->GetType() == b2_dynamicBody)
    {
        if (((Entity *)bodyA->GetUserData())->radius == Params::GUPPIE_RAD)
        {
            if (((Guppie *)bodyA->GetUserData())->isActive)
            {
                gp1 = (Guppie *)bodyA->GetUserData();
            }
        }
    }
    if (bodyB->GetType() == b2_dynamicBody)
    {
        if (((Entity *)bodyB->GetUserData())->radius == Params::GUPPIE_RAD)
        {
            if (((Guppie *)bodyB->GetUserData())->isActive)
            {
                gp2 = (Guppie *)bodyB->GetUserData();
            }
        }
    }

    // If only one body is a Guppie
    if ((gp1 && !gp2) || (!gp1 && gp2))
    {
        Guppie *gp = gp1 ? gp1 : gp2;
        b2Body *bd = gp1 ? bodyB : bodyA;

        if (bd->GetType() == b2_staticBody)
        {
            gp->lastContactStep = hSim->prms.contactSteps;
            gp->lastContact = Guppie::ZAPPER;
            gp->energy += hSim->prms.etFromZapper;
        }
        else
        {
            if (((Entity *)bd->GetUserData())->radius == Params::ZAPPER_RAD)
            {
                gp->lastContactStep = hSim->prms.contactSteps;
                gp->lastContact = Guppie::ZAPPER;
                gp->energy += hSim->prms.etFromZapper;
            }
            else
            {
                sf::Transform trans;
                trans.translate(gp->body->GetPosition().x, gp->body->GetPosition().y);
                trans.rotate(gp->body->GetAngle() * Params::RAD_DGRS);
                sf::Vector2f beak1 = trans.transformPoint(hSim->beak1.getPoint(1));
                sf::Vector2f beak2 = trans.transformPoint(hSim->beak2.getPoint(1));
                float cateteX1 = beak1.x - bd->GetPosition().x;
                float cateteY1 = beak1.y - bd->GetPosition().y;
                float cateteX2 = beak2.x - bd->GetPosition().x;
                float cateteY2 = beak2.y - bd->GetPosition().y;
                if (((Entity *)bd->GetUserData())->radius == Params::PELLET_RAD)
                {
                    if (cateteX1 * cateteX1 + cateteY1 * cateteY1 < hSim->prms.PELLET_RAD * hSim->prms.PELLET_RAD ||
                        cateteX2 * cateteX2 + cateteY2 * cateteY2 < hSim->prms.PELLET_RAD * hSim->prms.PELLET_RAD)
                    {
                        gp->lastContactStep = hSim->prms.contactSteps;
                        gp->lastContact = Guppie::PELLET;
                        gp->energy += hSim->prms.etFromPellet;
                        gp->fitness += hSim->prms.forPellet;
                        ((Pellet *)bd->GetUserData())->toBeDestroyed = true;
                        if (hSim->camera.trgtBody == bd)
                        {
                            hSim->camera.prevCrds = hSim->camera.currentCrds;
                            hSim->camera.step = Params::CAM_STEPS;
                            hSim->camera.trgtBody = gp->body;
                        }
                    }
                }
                else if (((Entity *)bd->GetUserData())->radius == Params::CORPSE_RAD)
                {
                    if (cateteX1 * cateteX1 + cateteY1 * cateteY1 < hSim->prms.CORPSE_RAD * hSim->prms.CORPSE_RAD ||
                        cateteX2 * cateteX2 + cateteY2 * cateteY2 < hSim->prms.CORPSE_RAD * hSim->prms.CORPSE_RAD)
                    {
                        gp->lastContactStep = hSim->prms.contactSteps;
                        gp->lastContact = Guppie::CORPSE;
                        gp->energy += ((Corpse *)bd->GetUserData())->energy;
                        gp->fitness += hSim->prms.forCorpse * (((Corpse *)bd->GetUserData())->energy / hSim->prms.etFromCorpse);
                        ((Corpse *)bd->GetUserData())->toBeDestroyed = true;
                        if (hSim->camera.trgtBody == bd)
                        {
                            hSim->camera.prevCrds = hSim->camera.currentCrds;
                            hSim->camera.step = Params::CAM_STEPS;
                            hSim->camera.trgtBody = gp->body;
                        }
                    }
                }
            }
        }

        if (gp->energy > hSim->prms.maxEnergy)
        {
            gp->energy = hSim->prms.maxEnergy;
        }
    }
    // If both bodies are guppies
    else if (gp1 && gp2)
    {
        sf::Transform trans1;
        sf::Transform trans2;
        trans1.translate(gp1->body->GetPosition().x, gp1->body->GetPosition().y);
        trans1.rotate(gp1->body->GetAngle() * Params::RAD_DGRS);
        trans2.translate(gp2->body->GetPosition().x, gp2->body->GetPosition().y);
        trans2.rotate(gp2->body->GetAngle() * Params::RAD_DGRS);

        sf::Vector2f beak1_1 = trans1.transformPoint(hSim->beak1.getPoint(1));
        sf::Vector2f beak1_2 = trans1.transformPoint(hSim->beak2.getPoint(1));
        sf::Vector2f beak2_1 = trans2.transformPoint(hSim->beak1.getPoint(1));
        sf::Vector2f beak2_2 = trans2.transformPoint(hSim->beak2.getPoint(1));

        float cateteX1_1 = beak1_1.x - gp2->body->GetPosition().x;
        float cateteY1_1 = beak1_1.y - gp2->body->GetPosition().y;
        float cateteX2_1 = beak2_1.x - gp2->body->GetPosition().x;
        float cateteY2_1 = beak2_1.y - gp2->body->GetPosition().y;
        float cateteX1_2 = beak1_2.x - gp1->body->GetPosition().x;
        float cateteY1_2 = beak1_2.y - gp1->body->GetPosition().y;
        float cateteX2_2 = beak2_2.x - gp1->body->GetPosition().x;
        float cateteY2_2 = beak2_2.y - gp1->body->GetPosition().y;

        if (cateteX1_1 * cateteX1_1 + cateteY1_1 * cateteY1_1 < hSim->prms.GUPPIE_RAD * hSim->prms.GUPPIE_RAD ||
            cateteX2_1 * cateteX2_1 + cateteY2_1 * cateteY2_1 < hSim->prms.GUPPIE_RAD * hSim->prms.GUPPIE_RAD)
        {
            gp1->lastContactStep = hSim->prms.contactSteps;
            gp1->lastContact = Guppie::GUPPIE;
            gp1->energy += hSim->prms.etFromGuppie;
            gp1->fitness += hSim->prms.forGuppie;

            gp2->lastContactStep = hSim->prms.contactSteps;
            gp2->lastContact = Guppie::GUPPIE;
            gp2->energy -= hSim->prms.etFromGuppie;
        }

        if (cateteX1_2 * cateteX1_2 + cateteY1_2 * cateteY1_2 < hSim->prms.GUPPIE_RAD * hSim->prms.GUPPIE_RAD ||
            cateteX2_2 * cateteX2_2 + cateteY2_2 * cateteY2_2 < hSim->prms.GUPPIE_RAD * hSim->prms.GUPPIE_RAD)
        {
            gp1->lastContactStep = hSim->prms.contactSteps;
            gp1->lastContact = Guppie::GUPPIE;
            gp1->energy -= hSim->prms.etFromGuppie;

            gp2->lastContactStep = hSim->prms.contactSteps;
            gp2->lastContact = Guppie::GUPPIE;
            gp2->energy += hSim->prms.etFromGuppie;
            gp2->fitness += hSim->prms.forGuppie;
        }

        if (gp1->energy > hSim->prms.maxEnergy)
        {
            gp1->energy = hSim->prms.maxEnergy;
        }

        if (gp2->energy > hSim->prms.maxEnergy)
        {
            gp2->energy = hSim->prms.maxEnergy;
        }
    }
}
