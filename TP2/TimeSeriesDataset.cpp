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