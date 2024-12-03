//
// Created by user on 03/12/2024.
//

#ifndef CARD_H
#define CARD_H
#include <string>


class Card {
protected:
    std::string cardName;
public:
    //constructeur
    Card(const std::string& name) : cardName(name) {}

    //Destructeur
    virtual ~Card() {}

    //fonction virtuelle pure
    virtual void displayInfo() const = 0;

    // Méthode pour obtenir le nom de la carte
    const std::string& getCardName() const;
};



#endif //CARD_H
