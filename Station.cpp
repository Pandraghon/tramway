#include "Station.hpp"

Station::Station(int id, const std::string& name, int posX, int posY, int duration)
                : m_id(id), m_name(name), m_posX(posX), m_posY(posY), m_duration(duration)
{
    //ctor
}

Station::~Station()
{
    //dtor
}

void Station::display(std::ostream& sout) const
{
    sout << m_id << " " << m_name << " (" << m_posX << ";" << m_posY << ") " << m_duration << "s";
}

std::ostream& operator<<(std::ostream& sout, const Station& station)
{
    station.display(sout);
    return sout;
}
