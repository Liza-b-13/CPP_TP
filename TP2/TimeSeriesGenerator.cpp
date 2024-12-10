
#include "headers/TimeSeriesGenerator.h"
#include <iomanip>
#include <iostream>

// Constructeur par défaut
TimeSeriesGenerator::TimeSeriesGenerator() : seed(0) {}

// Constructeur paramétré
TimeSeriesGenerator::TimeSeriesGenerator(int seedValue) : seed(seedValue) {}

// Fonction statique pour imprimer une série temporelle
void TimeSeriesGenerator::printTimeSeries(const std::vector<double>& timeSeries) {
    for (const auto& value : timeSeries) {
        std::cout << std::fixed << std::setprecision(2) << value << " ";
    }
    std::cout << std::endl;
}