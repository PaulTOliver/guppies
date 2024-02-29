#include "SimFitness.hpp"

void SimFitness::updateSpecs()
{
    for (auto &i : guppies)
    {
        i.update();
    }

    if (!guppieCount)
    {
        unsigned soul = 0;
        for (auto &i : guppies)
        {
            population->setFitness(currentPopulation * prms.popSize + soul, (unsigned)i.fitness);
            ++soul;
        }

        ++currentPopulation;
        if (currentPopulation == prms.popQtty)
        {
            population->roulleteWheel();

            currentPopulation = 0;
            ++currentGeneration;
        }

        unsigned index = 0;
        for (auto &i : guppies)
        {
            i.clean();
            i.create();
            i.neuralNet->setChromosome(population->getChromosome(currentPopulation * prms.popSize + index));
            ++index;
        }

        text.currentPop.setString("Current population: " + nts(currentPopulation + 1) + " / " + nts(prms.popQtty));
        text.currentGen.setString("Current generation: " + nts(currentGeneration + 1));
    }
}
