
#ifndef STEPGENERATOR_H
#define STEPGENERATOR_H

#include "headers/TimeSeriesGenerator.h"

class StepGenerator : public TimeSeriesGenerator {
public:
    // Constructeur par défaut
    StepGenerator();

    // Constructeur paramétré
    StepGenerator(int seedValue);

    // Implémentation de la fonction pour générer la série temporelle
    std::vector<double> generateTimeSeries(int size) const override;
};




#endif //STEPGENERATOR_H
