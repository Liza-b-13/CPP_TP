cmake_minimum_required(VERSION 3.29)
project(Pokemon3)

set(CMAKE_CXX_STANDARD 20)

add_executable(Pokemon3 main.cpp
        headers/Card.h
        Card.cpp
        headers/PokemonCard.h
        PokemonCard.cpp
        headers/EnergyCard.h
        EnergyCard.cpp
        TrainerCard.cpp
        headers/TrainerCard.h
        headers/Player.h
        Player.cpp
        main.cpp)
