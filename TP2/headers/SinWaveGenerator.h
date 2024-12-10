#ifndef SINWAVEGENERATOR_H
#define SINWAVEGENERATOR_H

#include "headers/TimeSeriesGenerator.h"
#include <vector>

class SinWaveGenerator : public TimeSeriesGenerator {
private:
    double amplitude;  // Amplitude (A)
    double frequency;  // Fréquence (ω)
    double phase;      // Phase initiale (ϕ)

public:
    // Constructeur par défaut
    SinWaveGenerator();

    // Constructeur paramétré
    SinWaveGenerator(int seedValue, double amplitude, double frequency, double phase);

    // Implémentation de la fonction pour générer la série temporelle
    std::vector<double> generateTimeSeries(int size) const override;
};

#endif // SINWAVEGENERATOR_H
