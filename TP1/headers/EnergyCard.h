//
// Created by user on 03/12/2024.
//

#ifndef ENERGYCARD_H
#define ENERGYCARD_H
#include <string>
#include <iostream>

#include "Card.h"


class EnergyCard : public Card{
private:
    std::string energyType;

public:
    EnergyCard(const std::string& type);

    void displayInfo() const override;

    // Getter pour le type d'énergie
    const std::string& getEnergyType() const;
};



#endif //ENERGYCARD_H
