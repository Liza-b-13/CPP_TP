//
// Created by user on 03/12/2024.
//

#ifndef POKEMONCARD_H
#define POKEMONCARD_H
#include "Card.h"
#include<string>
#include <vector>
#include <tuple>
#include <iostream>

class PokemonCard : public Card{
protected:
    std::string pokemonType; // Type du Pokémon
    std::string familyName;  // Famille du Pokémon
    int evolutionLevel;      // Niveau d'évolution
    int maxHP;               // Points de vie maximum
    int hp;                  // Points de vie actuels
    std::vector<std::tuple<int, int, std::string, int>> attacks; // Liste des attaques

public:
    // Constructeur
    PokemonCard(const std::string& name, const std::string& type, const std::string& family, int evolution, int maxHPValue, int currentHP,
                const std::vector<std::tuple<int, int, std::string, int>>& attackList);

    // Affiche les informations de la carte Pokémon
    void displayInfo() const override;

    //Methodes pour le main
    void addEnergy(const std::string& energyType);
    void reduceHP(int damage);

    // Getters pour les membres
    const std::string& getPokemonType() const;
    const std::string& getFamilyName() const;
    int getEvolutionLevel() const;
    int getMaxHP() const;
    int getHP() const;
    const std::vector<std::tuple<int, int, std::string, int>>& getAttacks() const;

    //setters
    void setHP(int newHP);
};



#endif //POKEMONCARD_H
