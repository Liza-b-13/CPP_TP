//
// Created by user on 03/12/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Card.h"
#include "PokemonCard.h"
#include "EnergyCard.h"
#include "TrainerCard.h"
#include <string>
#include <vector>
#include <iostream>


class Player {
private:
    std::string playerName;
    std::vector<Card*> benchCards;
    std::vector<PokemonCard*> actionCards;

public:
    //constructeur
    Player(const std::string& name);

    //information joueur et cartes
    void displayInfo() const;

    // Méthodes
    void addCardToBench(Card* card);

    void addPokemonCardToAction(PokemonCard* pokemonCard);

    void activatePokemonCard(int index);

    void attachEnergyCard(int pokemonIndex, int energyCardIndex);

    void attack(int pokemonIndex, int attackIndex, Player& opponent, int opponentPokemonIndex);

    void useTrainer(int index);

    void displayBench() const;

    void displayAction() const;


    // Getter pour le nom du joueur
    const std::string& getPlayerName() const;
    // Getter pour les cartes en réserve
    const std::vector<Card*>& getBenchCards() const;
    // Getter pour les cartes Pokémon en action
    std::vector<PokemonCard *> getActionCards() const;

};



#endif //PLAYER_H
