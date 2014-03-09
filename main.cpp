#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "FileSystem.hpp"
#include "Station.hpp"

int main()
{
    std::cout << "Chargement des donnees ...";
    FileSystem fs("station.txt", "line.txt", "tramway.txt");
    if(!fs.isValid()) return EXIT_FAILURE;


    return EXIT_SUCCESS;
}
