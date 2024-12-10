

#ifndef TIMESERIESGENERATOR_H
#define TIMESERIESGENERATOR_H

#include <vector>

class TimeSeriesGenerator {
protected:
    int seed;

public:
    //constructeur par défaut
    TimeSeriesGenerator();

    //constructeur paramétré
    TimeSeriesGenerator(int seedValue);

    // Fonction virtuelle pure pour générer une série temporelle
    virtual std::vector<double> generateTimeSeries(int size) const = 0;

    // Fonction statique pour imprimer une série temporelle
    static void printTimeSeries(const std::vector<double>& timeSeries);
};



#endif //TIMESERIESGENERATOR_H
