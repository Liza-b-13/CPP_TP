//
// Created by user on 03/12/2024.
//

#ifndef TRAINERCARD_H
#define TRAINERCARD_H
#include "Card.h"
#include "PokemonCard.h"
#include <string>
#include <vector>
#include <iostream>

class TrainerCard : public Card{
private:
    std::string trainerEffect;
public:
    //constructeur
    TrainerCard(const std::string& trainerName, const std::string& effect);

    // Affiche les informations de la carte de dresseur
    void displayInfo() const override;

    // Heal all your action pokemon
    void applyEffect(std::vector<PokemonCard>& activePokemons) const;

    const std::string& getTrainerEffect() const;

};



#endif //TRAINERCARD_H
