//
// Created by user on 03/12/2024.
//

#include "headers/PokemonCard.h"

PokemonCard::PokemonCard(const std::string& name, const std::string& type, const std::string& family, int evolution, int maxHPValue, int currentHP,
                const std::vector<std::tuple<int, int, std::string, int>>& attackList)
        : Card(name), pokemonType(type), familyName(family), evolutionLevel(evolution), maxHP(maxHPValue), hp(currentHP), attacks(attackList) {}


// Implémentation de la méthode displayInfo
void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Name: " << cardName << "\n";
    std::cout << "Type: " << pokemonType << "\n";
    std::cout << "Family: " << familyName << "\n";
    std::cout << "Evolution Level: " << evolutionLevel << "\n";
    std::cout << "Max HP: " << maxHP << "\n";
    std::cout << "Current HP: " << hp << "\n";
    std::cout << "Attacks:\n";
    for (size_t i = 0; i < attacks.size(); ++i) {
        const auto& [energyCost, currentEnergy, description, damage] = attacks[i];
        std::cout << "  Attack " << i + 1 << ":\n";
        std::cout << "    Energy Cost: " << energyCost << "\n";
        std::cout << "    Current Energy: " << currentEnergy << "\n";
        std::cout << "    Description: " << description << "\n";
        std::cout << "    Damage: " << damage << "\n";
    }
}

void PokemonCard::addEnergy(const std::string& energyType) {
    // Ajouter de l'énergie à l'attaque correspondante
    std::cout << "Adding energy of type " << energyType << " to Pokemon " << cardName << std::endl;
}

void PokemonCard::reduceHP(int damage) {
    hp -= damage;
    if (hp < 0) hp = 0;
}

const std::string& PokemonCard::getPokemonType() const { return pokemonType; }
const std::string& PokemonCard::getFamilyName() const { return familyName; }
int PokemonCard::getEvolutionLevel() const { return evolutionLevel; }
int PokemonCard::getMaxHP() const { return maxHP; }
int PokemonCard::getHP() const { return hp; }
const std::vector<std::tuple<int, int, std::string, int>>&  PokemonCard::getAttacks() const { return attacks; }

void PokemonCard::setHP(int newHP) {
    hp = (newHP > maxHP) ? maxHP : newHP; // S'assure que HP ne dépasse pas maxHP
    if (hp < 0) hp = 0;                   // S'assure que HP n'est pas négatif
}
