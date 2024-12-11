//
// Created by user on 03/12/2024.
//

#include "headers/EnergyCard.h"
#include <iostream>

EnergyCard::EnergyCard(const std::string& type)
    : Card("Energy"), energyType(type) {}

void EnergyCard::displayInfo() const {
    std::cout << "Energy Card - Name : " << cardName << ", Type: " << energyType << std::endl;
}

// Getter pour energyType
const std::string& EnergyCard::getEnergyType() const {
    return energyType;
}