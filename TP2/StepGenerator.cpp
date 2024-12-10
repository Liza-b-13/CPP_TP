#include "headers/StepGenerator.h"
#include <cstdlib> // pour std::rand et std::srand
#include <ctime>   // pour std::time si on veut une graine par défaut

// Constructeur par défaut
StepGenerator::StepGenerator() : TimeSeriesGenerator() {}

// Constructeur paramétré
StepGenerator::StepGenerator(int seedValue) : TimeSeriesGenerator(seedValue) {}

// Implémentation de la fonction generateTimeSeries
std::vector<double> StepGenerator::generateTimeSeries(int size) const {
    // Initialisation du générateur aléatoire avec la graine
    std::srand(seed);

    std::vector<double> timeSeries(size);
    timeSeries[0] = 0; // La première valeur est 0

    for (int i = 1; i < size; ++i) {
        // Générer un nombre aléatoire entre 0 et 1
        double randomValue = static_cast<double>(std::rand()) / RAND_MAX;

        if (randomValue < 0.5) {
            // Choisir une nouvelle valeur aléatoire entre 0 et 100
            timeSeries[i] = std::rand() % 101;
        } else {
            // Garder la valeur précédente
            timeSeries[i] = timeSeries[i - 1];
        }
    }

    return timeSeries;
}
