#include "Line.hpp"

Line::Line() : m_id(0), m_nbElem(0), m_tabStation(NULL) {}

Line::Line(int id, int nbElem, Station** tabStation) : m_id(id), m_nbElem(nbElem), m_tabStation(tabStation) {}

Line::Line(const Line& line) : m_id(line.m_id), m_nbElem(line.m_nbElem), m_tabStation(line.m_tabStation) {}

Line::~Line()
{
    for(int i = 0 ; i < m_nbElem ; ++i)
        m_tabStation[i] = NULL;
}

Station* Line::operator[](int i)
{
    return m_tabStation[i];
}

const Station* Line::operator[](int i) const
{
    return m_tabStation[i];
}

Line& Line::operator=(const Line& line)
{
    m_id = line.m_id;
    m_nbElem = line.m_nbElem;
    m_tabStation = line.m_tabStation;

    return *this;
}
