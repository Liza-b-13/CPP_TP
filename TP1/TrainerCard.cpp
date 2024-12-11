//
// Created by user on 03/12/2024.
//

#include "headers/TrainerCard.h"
//Constructeur
TrainerCard::TrainerCard(const std::string& trainerName, const std::string& effect)
       : Card(trainerName), trainerEffect(effect) {}

// Implémentation de displayInfo
void TrainerCard::displayInfo() const {
    std::cout << "Trainer Card - Name : " << cardName << ", Effect: " << trainerEffect << std::endl ;
}

// Implémentation de applyEffect
void TrainerCard::applyEffect(std::vector<PokemonCard>& activePokemons) const {
    for (auto& pokemon : activePokemons) {
        pokemon.setHP(pokemon.getMaxHP());
    }
    std::cout << "All active Pokemon have been healed to their maximum HP.\n";
}

const std::string& TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}

