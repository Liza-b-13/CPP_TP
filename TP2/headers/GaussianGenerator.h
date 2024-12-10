#ifndef GAUSSIANGENERATOR_H
#define GAUSSIANGENERATOR_H

#include "headers/TimeSeriesGenerator.h";

class GaussianGenerator: public TimeSeriesGenerator {
private:
    int mean;
    int stddev;

public:
    GaussianGenerator();

    GaussianGenerator(int seedValue , int mean, int stddev);

    std::vector<double> generateTimeSeries(int size) const override;
};



#endif //GAUSSIANGENERATOR_H