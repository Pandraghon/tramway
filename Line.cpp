#include "Line.hpp"

Line::Line() : m_id(0), m_nbElem(0), m_tabStation(NULL), m_first(NULL) {}

Line::Line(int id, int nbElem, Station** tabStation) : m_id(id), m_nbElem(nbElem), m_tabStation(tabStation), m_first(NULL) {}

Line::Line(const Line& line) : m_id(line.m_id), m_nbElem(line.m_nbElem), m_tabStation(new Station*[m_nbElem]), m_first(line.m_first)
{
    for(int i = 0 ; i < m_nbElem ; ++i)
        m_tabStation[i] = line.m_tabStation[i];
}

Line::~Line()
{
    delete[] m_tabStation;
}

void Line::display(std::ostream& sout) const
{
    sout << "Ligne " << m_id << " - " << m_nbElem << "arrets";
}

void Line::setFirst(Tramway* first)
{
    m_first = first;
}

std::ostream& operator<<(std::ostream& sout, const Line& l)
{
    l.display(sout);
    return sout;
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
    m_tabStation = new Station*[m_nbElem];
    for(int i = 0 ; i < m_nbElem ; ++i)
        m_tabStation[i] = line.m_tabStation[i];

    return *this;
}
