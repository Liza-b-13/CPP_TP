//
// Created by user on 10/12/2024.
//

#include "headers/TimeSeriesDataset.h"

// Constructeur par défaut
TimeSeriesDataset::TimeSeriesDataset()
    : znormalize(false), isTrain(false), maxLength(0), numberOfSamples(0) {}

// Constructeur paramétré
TimeSeriesDataset::TimeSeriesDataset(bool znormalize, bool isTrain, int maxLength, int numberOfSamples)
    : znormalize(znormalize), isTrain(isTrain), maxLength(maxLength), numberOfSamples(numberOfSamples) {}


// Function to calculate Euclidean distance between two time series
double TimeSeriesDataset::euclidean_distance(const vector<double>& series1, const vector<double>& series2) {
    if (series1.size() != series2.size()) {
        throw invalid_argument("The two series must have the same length.");
    }

    double distance = 0.0;
    for (size_t i = 0; i < series1.size(); ++i) {
        double diff = series1[i] - series2[i];
        distance += diff * diff;
    }

    return sqrt(distance);
}
