#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "FileSystem.hpp"
#include "Station.hpp"
#include "Line.hpp"

int main()
{
    std::cout << "Chargement des donnees ... \n" << std::endl;
    FileSystem fs("station.txt", "line.txt", "tramway.txt");
    if(!fs.isValid()) return EXIT_FAILURE;

    std::cout << fs << std::endl;


    return EXIT_SUCCESS;
}
