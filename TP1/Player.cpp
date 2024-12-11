//
// Created by user on 03/12/2024.
//

#include "headers/Player.h"

Player::Player(const std::string& name)
        : playerName(name) {}

// Affiche les informations sur le joueur et ses cartes
void Player::displayInfo() const {
        std::cout << "Player Name: " << playerName << "\n";

        std::cout << "\nBench Cards:\n";
        for (const auto& card : benchCards) {
            card->displayInfo();  // Affiche les informations de la carte
        }

        std::cout << "\nAction Cards (Pokemon):\n";
        for (const auto& pokemonCard : actionCards) {
            pokemonCard->displayInfo();  // Affiche les informations de la carte Pokémon
        }
    }

// Méthodes pour ajouter une carte au deck ou au banc
void Player::addCardToBench(Card* card) {
    benchCards.push_back(card); // Ajout au banc

    // Vérification si c'est une carte Pokemon
    PokemonCard* pokemonCard = dynamic_cast<PokemonCard*>(card);
    if (pokemonCard) {
        actionCards.push_back(pokemonCard); // Ajoute uniquement les PokemonCard
    }
}


void Player::addPokemonCardToAction(PokemonCard* pokemonCard) {
        actionCards.push_back(pokemonCard);
    }

void Player::activatePokemonCard(int index) {
    std::cout << playerName << " is activating a Pokemon Card : " << benchCards[index]->getCardName() << std::endl;
    benchCards.erase(benchCards.begin() + index);
}

void Player::attachEnergyCard(int pokemonIndex, int energyCardIndex) {
    if (pokemonIndex >= 0 && pokemonIndex < actionCards.size() && energyCardIndex >= 0 && energyCardIndex < benchCards.size()) {
        PokemonCard* pokemon = actionCards[pokemonIndex];
        EnergyCard* energyCard = dynamic_cast<EnergyCard*>(benchCards[energyCardIndex]);
        if (energyCard) {
            std::cout << playerName << " is attaching Energy Card of type " << energyCard->getEnergyType()
                      << " to the Pokemon " << pokemon->getCardName() << std::endl;

        }
    }
    benchCards.erase(benchCards.begin() + energyCardIndex);
}

void Player::attack(int pokemonIndex, int attackIndex, Player& opponent, int opponentPokemonIndex) {
    if (pokemonIndex >= 0 && pokemonIndex < actionCards.size()) {
        PokemonCard* attackingPokemon = actionCards[pokemonIndex];
        const auto* attacks = attackingPokemon->getAttacks(); // Récupération des attaques

        // Vérification de la validité de l'index de l'attaque
        if (attackIndex >= 0 && attackIndex < 2) {
            auto attack = attacks[attackIndex]; // Récupération de l'attaque sélectionnée
            int energyCost = std::get<0>(attack);  // Exemple : coût en énergie
            int damage = std::get<3>(attack);     // Exemple : dégâts infligés
            std::string description = std::get<2>(attack); // Exemple : description de l'attaque

            // Vérification de l'adversaire
            if (opponentPokemonIndex >= 0 && opponentPokemonIndex < opponent.actionCards.size()) {
                PokemonCard* opponentPokemon = opponent.actionCards[opponentPokemonIndex];

                // Afficher les détails de l'attaque
                std::cout << playerName << " is attacking " << opponent.playerName << "'s Pokemon "
                          << opponentPokemon->getCardName() << " with the Pokemon "
                          << attackingPokemon->getCardName() << " using its attack: " << description << "\n";

                // Réduire les HP du Pokémon adverse
                opponentPokemon->reduceHP(damage);
                std::cout << "Reducing " << damage << " from " << opponent.playerName <<"'s" << "Pokemon's HP" << "\n";

                // Vérifier si le Pokémon est toujours en vie
                if (opponentPokemon->getHP() > 0) {
                    std::cout <<"Pokemon" << opponentPokemon->getCardName() << " is still alive\n";
                } else {
                    std::cout << opponentPokemon->getCardName() << " has fainted\n";
                }
            }
        } else {
            std::cout << "Invalid attack index!\n";
        }
    } else {
        std::cout << "Invalid Pokemon index!\n";
    }
}


void Player::useTrainer(int index) {
    if (index >= 0 && index < benchCards.size()) {
        TrainerCard* trainer = dynamic_cast<TrainerCard*>(benchCards[index]);
        if (trainer) {
            std::cout << playerName << " is using the Trainer Card to \"" << trainer->getTrainerEffect() << "\"\n";

            // Convertir les pointeurs en objets temporaires pour appliquer l'effet
            std::vector<PokemonCard> tempActionCards;
            for (PokemonCard* card : actionCards) {
                if (card) {
                    tempActionCards.push_back(*card); // Crée une copie de chaque carte
                }
            }

            trainer->applyEffect(tempActionCards);

            // Mettre à jour les objets originaux à partir des temporaires
            for (size_t i = 0; i < actionCards.size() && i < tempActionCards.size(); ++i) {
                *actionCards[i] = tempActionCards[i];
            }
        }
    }
}

void Player::displayBench() const {
    std::cout << "Bench cards for Player " << playerName << ":\n";
    for (const auto& card : benchCards) {
        card->displayInfo();
    }
}

void Player::displayAction() const {
    std::cout << "Action cards for Player " << playerName << ":\n";
    for (const auto& pokemon : actionCards) {
        pokemon->displayInfo();
        std::cout << std::endl ;
        std::cout << std::endl ;

    }
}

// Getter pour le nom du joueur
const std::string& Player::getPlayerName() const { return playerName; }

// Getter pour les cartes en réserve
const std::vector<Card*>& Player::getBenchCards() const { return benchCards; }

// Getter pour les cartes Pokémon en action
std::vector<PokemonCard *> Player::getActionCards() const { return actionCards; }