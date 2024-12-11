//
// Created by user on 03/12/2024.
//

#include "headers/PokemonCard.h"

PokemonCard::PokemonCard(std::string _pokemonName,std::string _pokeType, std::string _famName,int _evLevel,int _maxHP,int _energyCost1,std::string _attackDesc1,int _damageAttack1,int _energyCost2,std::string _attackDesc2,int _damageAttack2):
Card(_pokemonName),
pokemonType(_pokeType),
familyName(_famName),
evolutionLevel(_evLevel),
maxHP(_maxHP),
hp(_maxHP)
{
    attacks[0] = make_tuple(_energyCost1,0,_attackDesc1,_damageAttack1);
    attacks[1] = make_tuple(_energyCost2,0,_attackDesc2,_damageAttack2);
}

// Implémentation de la méthode displayInfo
void PokemonCard::displayInfo() const {
    std::cout << "Pokemon Card - Name : " << cardName << ", Type: " << pokemonType << " , Evolution Level: " << std::to_string(evolutionLevel) << " of the family " << familyName << ", HP: " << std::to_string(hp) ;

    std::cout << std::endl;
    std::cout << "Attacks :"<< std::endl;
    for (int i = 0; i < 2; ++i) {
        std::cout << "Attack #" + std::to_string(i) << std::endl;
        std::cout << "Attack cost: " << get<0>(attacks[i]) << std::endl ;
        std::cout << "Attack current energy storage: " << get<1>(attacks[i]) << std::endl;
        std::cout << "Attack description: " << get<2>(attacks[i]) << std::endl ;
        std::cout << "Attack damage: " << get<3>(attacks[i]) << std::endl;
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

// Getter for the attacks
const std::tuple<int, int, std::string, int>* PokemonCard::getAttacks() const {
    return attacks; // Retourne un pointeur constant vers le tableau d'attaques
}




void PokemonCard::setHP(int newHP) {
    hp = (newHP > maxHP) ? maxHP : newHP; // S'assure que HP ne dépasse pas maxHP
    if (hp < 0) hp = 0;                   // S'assure que HP n'est pas négatif
}
