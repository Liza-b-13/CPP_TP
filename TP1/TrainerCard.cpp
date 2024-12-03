//
// Created by user on 03/12/2024.
//

#include "headers/TrainerCard.h"
//Constructeur
TrainerCard::TrainerCard(const std::string& trainerName, const std::string& effect)
       : Card(trainerName), trainerEffect(effect) {}

// Implémentation de displayInfo
void TrainerCard::displayInfo() const {
    std::cout << "Trainer Name: " << cardName << "\n";
    std::cout << "Effect: " << trainerEffect << "\n";
}

// Implémentation de applyEffect
void TrainerCard::applyEffect(std::vector<PokemonCard>& activePokemons) const {
    if (trainerEffect == "heal all your action pokemon") {
        for (auto& pokemon : activePokemons) {
            pokemon.setHP(pokemon.getMaxHP());
        }
        std::cout << "All active Pokémon have been healed to their maximum HP.\n";
    } else {
        std::cout << "Unknown effect: " << trainerEffect << "\n";
    }
}

const std::string& TrainerCard::getTrainerEffect() const {
    return trainerEffect;
}

