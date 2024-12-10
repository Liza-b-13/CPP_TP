#include "headers/SinWaveGenerator.h"
#include <cmath> // pour std::sin

// Constructeur par défaut
SinWaveGenerator::SinWaveGenerator()
    : TimeSeriesGenerator(), amplitude(1.0), frequency(1.0), phase(0.0) {}

// Constructeur paramétré
SinWaveGenerator::SinWaveGenerator(int seedValue, double amplitude, double frequency, double phase)
    : TimeSeriesGenerator(seedValue), amplitude(amplitude), frequency(frequency), phase(phase) {}

// Implémentation de la fonction generateTimeSeries
std::vector<double> SinWaveGenerator::generateTimeSeries(int size) const {
    std::vector<double> timeSeries(size);

    // Générer les valeurs de la série temporelle
    for (int i = 0; i < size; ++i) {
        timeSeries[i] = amplitude * std::sin(frequency * i + phase);
    }

    return timeSeries;
}
