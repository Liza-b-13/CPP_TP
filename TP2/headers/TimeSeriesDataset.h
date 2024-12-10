#ifndef TIMESERIESDATASET_H
#define TIMESERIESDATASET_H

#include <vector>
#include <iostream>

class TimeSeriesDataset {
private:
    bool znormalize;               // Indique si les données doivent être normalisées
    bool isTrain;                  // Indique si c'est un ensemble d'entraînement
    std::vector<std::vector<double>> data; // Données : vecteurs de séries temporelles
    std::vector<int> labels;       // Étiquettes associées aux séries temporelles
    int maxLength;                 // Longueur maximale des séries
    int numberOfSamples;           // Nombre d'échantillons

    // Fonction privée pour effectuer la normalisation Z-score
    void zNormalizeData();

public:
    // Constructeur par défaut
    TimeSeriesDataset();

    // Constructeur paramétré
    TimeSeriesDataset(bool znormalize, bool isTrain, int maxLength, int numberOfSamples);
};

#endif // TIMESERIESDATASET_H
