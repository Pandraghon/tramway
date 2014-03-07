#include <cstdlib>
#include <iostream>
#include <vector>
#include <string>
#include "filesystem.hpp"
#include "Station.hpp"

void loading(std::vector<Station> &stations)
{
    fs::loadStations("station.txt", stations);
}

int main()
{
    std::vector<Station> test;
    loading(test);
    if(test.size() > 0){
        for(unsigned int i = 0 ; i < test.size() ; std::cout << test[i++] << std::endl);
    }
    return 0;
}
