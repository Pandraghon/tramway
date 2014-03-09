#ifndef LINE_HPP_INCLUDED
#define LINE_HPP_INCLUDED

/**
 * \file Line.hpp
 * \brief Ligne de tramway
 * \author Sylvain_Albasser
 * \date 22/02/2014 (creation)
 * \date 09/03/2014 (derniere modification)
 * \version 0.1
 */

#include "Station.hpp"

class Line
{
    public:
        Line();
        Line(int id, int nbElem, Station** tabStation);
        Line(const Line& line);
        ~Line();

        Station* operator[](int i);
        const Station* operator[](int i) const;
        Line& operator=(const Line& line);
    private:
        int m_id;
        int m_nbElem;
        Station** m_tabStation;
};

#endif // LINE_HPP_INCLUDED
