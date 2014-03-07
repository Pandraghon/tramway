#include "filesystem.hpp"

namespace fs{

    void clear(std::istream& sin)
    {
        char c;
        std::string trash;
        sin >> std::ws >> c;
        while(c == '#'){
            std::getline(sin, trash);
            sin >> std::ws >> c;
        }
        sin.putback(c);
    }

    void loadStations(const std::string& stationFile, std::vector< Station >& station)
    {
        int nbLine;
        int id, posX, posY, duration;
        std::string name;
        std::ifstream fin(stationFile.c_str());
        station.clear();
        if(!fin){
            std::cerr << "Erreur : Impossible d'ouvrir le fichier " << stationFile << std::endl;
        } else {
            clear(fin);
            fin >> nbLine;
            for(int i = 0 ; i < nbLine ; ++i){
                clear(fin);
                fin >> id >> name >> posX >> posY >> duration;
                station.push_back(Station(id, name, posX, posY, duration));
            }
        }
    }
}
