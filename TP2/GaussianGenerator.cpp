#include "headers/GaussianGenerator.h"
#include <cmath> // pour std::log et std::sqrt
#include <vector>
#include <random>

GaussianGenerator::GaussianGenerator() : TimeSeriesGenerator(), mean(0.0), stddev(1.0){}

GaussianGenerator::GaussianGenerator(int seedValue, int mean, int stddev) : TimeSeriesGenerator(seedValue), mean(mean), stddev(stddev) {}

// Méthode de Box-Muller pour générer des valeurs gaussiennes
std::vector<double> GaussianGenerator::generateTimeSeries(int size) const {
    std::vector<double> timeSeries;
    timeSeries.reserve(size);

    // Initialisation du générateur aléatoire
    std::mt19937 generator(seed); // Générateur avec la graine spécifiée
    std::uniform_real_distribution<double> distribution(0.0, 1.0);

    for (int i = 0; i < size; i++) {
        // Génération de deux variables uniformément distribuées
        double u1 = distribution(generator);
        double u2 = distribution(generator);

        // Application de la méthode de Box-Muller pour obtenir des variables gaussiennes
        double z0 = std::sqrt(-2.0 * std::log(u1)) * std::cos(2.0 * M_PI * u2);

        // Transformation selon la moyenne et l'écart type
        timeSeries.push_back(mean + z0 * stddev);
    }

    return timeSeries;
}