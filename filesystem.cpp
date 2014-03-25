#include "FileSystem.hpp"

FileSystem::FileSystem(const std::string& stationFile, const std::string& lineFile, const std::string& tramwayFile)
                      : m_valid(true)
                      , m_nbStations(0), m_nbLines(0), m_nbTramways(0)
                      , m_tabStations(NULL), m_tabLines(NULL)
{
    m_valid = loadStations(stationFile) && loadLines(lineFile) && loadTramways(tramwayFile);
}

FileSystem::~FileSystem()
{
    for(int i = 0 ; i < m_nbLines ; ++i){
        Tramway* first = m_tabLines[i].first();
        if(first){
            Tramway* crt = first->d_suivant;
            delete first;
            while(crt != first){
                Tramway* as = crt;
                crt = crt->d_suivant;
                delete as;
            }
        }
    }
    delete[] m_tabLines;
    delete[] m_tabStations;
}

void FileSystem::clear(std::istream& sin)
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

bool FileSystem::loadTramways(const std::string& tramwayFile)
{
    int id, noLine, idStation, direction, speed, distance;
    int currentLine = -1;
    std::ifstream fin(tramwayFile.c_str());
    if(!fin){
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << tramwayFile << std::endl;
        return false;
    }else{
        clear(fin);
        fin >> m_nbTramways;
        if(m_nbTramways < 1){
            std::cerr << "Erreur : Il faut au moins un tramway dans " << tramwayFile << " !" << std::endl;
            return false;
        }
        Tramway *crt, *next, *first = NULL;
        for(int i = 0 ; i < m_nbTramways ; ++i){
            clear(fin);
            fin >> id >> noLine >> idStation >> direction >> speed >> distance;
            if(currentLine != noLine){
                if(first){
                    first->d_precedent = crt;
                    crt->d_suivant = first;
                }
                first = new Tramway(id, distance, idStation, direction, speed, NULL);
                crt = first;
                currentLine = noLine;
                getLineById(noLine)->setFirst(first);
            }else{
                next = new Tramway(id, distance, idStation, direction, speed, crt);
                crt->d_suivant = next;
                crt = next;
            }
        }
        if(first){
            first->d_precedent = crt;
            crt->d_suivant = first;
        }
    }
    return true;
}

bool FileSystem::loadStations(const std::string& stationFile)
{
    int id, posX, posY, duration;
    std::string name;
    std::ifstream fin(stationFile.c_str());
    if(!fin){
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << stationFile << std::endl;
        return false;
    } else {
        clear(fin);
        fin >> m_nbStations;
        if(m_nbStations < 1){
            std::cerr << "Erreur : Il faut au moins un arret dans " << stationFile << " !" << std::endl;
            return false;
        }
        m_tabStations = new Station[m_nbStations];
        for(int i = 0 ; i < m_nbStations ; ++i){
            clear(fin);
            fin >> id >> name >> posX >> posY >> duration;
            m_tabStations[i] = Station(id, name, posX, posY, duration);
        }
    }
    return true;
}

bool FileSystem::loadLines(const std::string& lineFile)
{
    int no, nbStations, id, k;
    std::ifstream fin(lineFile.c_str());
    if(!fin){
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << lineFile << std::endl;
        return false;
    } else {
        clear(fin);
        fin >> m_nbLines;
        if(m_nbLines < 1){
            std::cerr << "Erreur : Il faut au moins une ligne dans " << lineFile << " !" << std::endl;
            return false;
        }
        m_tabLines = new Line[m_nbLines];
        for(int i = 0 ; i < m_nbLines ; ++i){
            clear(fin);
            fin >> no >> nbStations;
            Station** stations = new Station*[nbStations];
            for(int j = 0 ; j < nbStations ; ++j){
                fin >> id;
                for(k = 0 ; k < m_nbStations && m_tabStations[k].getId() != id ; ++k);
                if(k >= m_nbStations){
                    std::cerr << "Erreur : Le fichier " << lineFile << " ne semble pas conforme. L'arret a l'id " << id << " n'existe pas." << std::endl;
                    return false;
                }
                stations[j] = &m_tabStations[k];
            }
            m_tabLines[i] = Line(no, nbStations, stations);
        }
    }
    return true;
}

Line* FileSystem::getLineById(int id) const
{
    int i = 0;
    for(; i < m_nbLines && m_tabLines[i].getId() != id ; ++i);
    if(i == m_nbLines) return NULL;
    else return &m_tabLines[i];
}

void FileSystem::display(std::ostream& sout) const
{
    sout << "Nombre d'arrets charges : " << m_nbStations << "\n\n";
    for(int i = 0 ; i < m_nbStations ; ++i)
        sout << "\t" << m_tabStations[i] << "\n";
    sout << "\nNombre de lignes chargees : " << m_nbLines << "\n";
    for(int i = 0 ; i < m_nbLines ; ++i){
        sout << "\n\t" << m_tabLines[i] << "\n";
        for(int j = 0 ; j < m_tabLines[i].size() ; ++j)
            sout << "\t\t" << *(m_tabLines[i][j]) << "\n";
        sout << "\t\t---" << "\n";
        Tramway* crt = m_tabLines[i].first();
        if(crt){
            sout << "\t\t" << *(crt) << "\n";
            crt = crt->d_suivant;
            while(crt != m_tabLines[i].first()){
                sout << "\t\t" << *(crt) << "\n";
                crt = crt->d_suivant;
            }
        }
    }
}

std::ostream& operator<<(std::ostream& sout, const FileSystem& fs)
{
    fs.display(sout);
    return sout;
}
