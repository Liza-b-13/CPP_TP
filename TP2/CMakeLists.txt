cmake_minimum_required(VERSION 3.29)
project(Serie)

set(CMAKE_CXX_STANDARD 20)

add_executable(Serie main.cpp
        headers/TimeSeriesGenerator.h
        TimeSeriesGenerator.cpp
        TimeSeriesGenerator.cpp
        headers/GaussianGenerator.h
        GaussianGenerator.cpp
        StepGenerator.cpp
        headers/StepGenerator.h
        headers/SinWaveGenerator.h
        headers/SinWaveGenerator.h
        headers/SinWaveGenerator.h
        SinWaveGenerator.cpp
        SinWaveGenerator.cpp
        headers/TimeSeriesDataset.h
        TimeSeriesDataset.cpp)
