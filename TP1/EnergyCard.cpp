//
// Created by user on 03/12/2024.
//

#include "headers/EnergyCard.h"
#include <iostream>

EnergyCard::EnergyCard(const std::string& type)
    : Card("Energy"), energyType(type) {}

void EnergyCard::displayInfo() const {
    std::cout << "Card Name: " << cardName << "\n";
    std::cout << "Energy Type: " << energyType << "\n";
}

// Getter pour energyType
const std::string& EnergyCard::getEnergyType() const {
    return energyType;
}