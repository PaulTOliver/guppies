#include "SimFitness.hpp"

bool SimFitness::startSpecs()
{
    if (!text.startup(this, SELECTION_BY_FITNESS))
    {
        return false;
    }

    std::unique_ptr<NeuralNet> dummy;
    if (prms.netClass == SINGLE_MLP)
    {
        dummy = std::unique_ptr<NeuralNet>(new SingleMLP(82, prms.npHiddenLayer, 5, prms.nodeClass, true));
    }
    else if (prms.netClass == DUAL_MLP)
    {
        dummy = std::unique_ptr<NeuralNet>(new DualMLP(82, prms.npHiddenLayer, 5, prms.nodeClass, true));
    }
    else if (prms.netClass == SIMPLE_RN)
    {
        dummy = std::unique_ptr<NeuralNet>(new SimpleRN(82, prms.npHiddenLayer, 5, prms.nodeClass, true));
    }
    else if (prms.netClass == FULLY_RN)
    {
        dummy = std::unique_ptr<NeuralNet>(new FullyRN(82, prms.npHiddenLayer, 5, prms.nodeClass, true));
    }
    unsigned chromosomeSize = dummy->getChromosomeSize();
    population = std::unique_ptr<Population>(new Population(prms.popQtty * prms.popSize, prms.elites, chromosomeSize));

    // Set first population
    guppies.resize(prms.popSize);
    unsigned index = 0;
    for (auto &i : guppies)
    {
        i.startup(this);
        if (prms.netClass == SINGLE_MLP)
        {
            i.neuralNet = std::shared_ptr<NeuralNet>(new SingleMLP(82, prms.npHiddenLayer, 5, prms.nodeClass, true));
        }
        else if (prms.netClass == DUAL_MLP)
        {
            i.neuralNet = std::shared_ptr<NeuralNet>(new DualMLP(82, prms.npHiddenLayer, 5, prms.nodeClass, true));
        }
        else if (prms.netClass == SIMPLE_RN)
        {
            i.neuralNet = std::shared_ptr<SimpleRN>(new SimpleRN(82, prms.npHiddenLayer, 5, prms.nodeClass, true));
        }
        else if (prms.netClass == FULLY_RN)
        {
            i.neuralNet = std::shared_ptr<FullyRN>(new FullyRN(82, prms.npHiddenLayer, 5, prms.nodeClass, true));
        }
        i.create();
        // Set neural net initial random weights
        i.neuralNet->setChromosome(population->getChromosome(index));

        ++index;
    }

    return true;
}
