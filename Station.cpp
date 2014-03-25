#include "Station.hpp"

Station::Station() : m_id(0), m_name(""), m_posX(0), m_posY(0), m_duration(0) {}

Station::Station(int id, const std::string& name, int posX, int posY, int duration)
                : m_id(id), m_name(name), m_posX(posX), m_posY(posY), m_duration(duration)
{
    std::replace(m_name.begin(), m_name.end(), '_', ' ');
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
