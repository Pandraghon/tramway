#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED

/**
 * \file Line.hpp
 * \brief Ligne de tramway
 * \author Sylvain_Albasser
 * \date 22/02/2014 (creation)
 * \date 06/03/2014 (derniere modification)
 * \version 0.1
 */

#include "Station.hpp"

class LineStation
{
    friend class Line;
    private:
        LineStation(Station* station) : m_station(station), nextThere(NULL), nextBack(NULL) {}
        Station* getInfos() const {return m_station;}
        Station* m_station;
        LineStation *nextThere, *nextBack;
};

class Line
{
    public:
        Line();
        ~Line();
    private:
        Station *first, *last;
};

#endif // LINE_HPP_INCLUDED
