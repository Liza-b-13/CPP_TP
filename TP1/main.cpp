# include "headers/Card.h"
# include "headers/PokemonCard.h"
# include "headers/EnergyCard.h"
# include "headers/TrainerCard.h"
# include "headers/Player.h"
# include <iostream>
# include <string>

using namespace std ;
int main ()
{
    Player player1 (" Hadi ") ;
    player1.addCardToBench (new EnergyCard (" Electric ") ) ;
    player1.addCardToBench (new EnergyCard (" Electric ") ) ;
    player1.addCardToBench (new TrainerCard (" Ash", " heal all your action pokemon ") ) ;

    std::vector<std::tuple<int, int, std::string, int>> pikachuAttacks = {
        {2, 20, "thunder bolt", 3},
        {3, 30, "thunder storm", 4} // Modifiez le coût si nécessaire
    };
    player1.addCardToBench(new PokemonCard("Pikachu", "Electric", "Pikachu", 2, 100, 100, pikachuAttacks));

    player1.activatePokemonCard (3) ;
    player1.attachEnergyCard (0 , 0) ;
    player1.attachEnergyCard (0 , 0) ;
    cout << endl ;
    player1.displayBench () ;
    cout << endl ;
    player1.displayAction () ;

    Player player2 (" Germain ") ;
    player2 . addCardToBench (new EnergyCard (" Grass ") ) ;
    player2 . addCardToBench (new TrainerCard (" Brock ", " heal all your action pokemon ") ) ;

    // Créer les attaques pour Bulbasaur
    std::vector<std::tuple<int, int, std::string, int>> bulbasaurAttacks = {
        {1, 15, "LeechSeed", 3},
        {2, 25, "Vine Whip", 4} // Modifiez le coût si nécessaire
    };
    player2.addCardToBench(new PokemonCard("Bulbasaur", "Grass", "Bulbasaur", 1, 100, 100, bulbasaurAttacks));

    player2 . activatePokemonCard (2) ;
    player2 . attachEnergyCard (0 , 0) ;
    cout << endl ;
    player2 . displayBench () ;
    cout << endl ;
    player2 . displayAction () ;
    player1 . attack (0 , 0 , player2 , 0) ;
    cout << endl ;
    player2 . displayAction () ;
    player2 . useTrainer (0) ;
    cout << endl ;
    player2 . displayAction () ;
    return 0;
    }