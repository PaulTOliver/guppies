#ifndef __SIMFITNESS_HPP__
#define __SIMFITNESS_HPP__

#include <Population.hpp>
#include <SingleMLP.hpp>
#include <DualMLP.hpp>
#include <SimpleRN.hpp>
#include <FullyRN.hpp>

#include "SimBase.hpp"

class SimFitness : public SimBase
{
    bool startSpecs();
    void updateSpecs();

    std::unique_ptr<Population> population;

    unsigned currentPopulation = 0;
    unsigned currentGeneration = 0;
    unsigned fitnessRecord = 0;

    friend class Guppie;
};

#endif // __SIMFITNESS_HPP__
