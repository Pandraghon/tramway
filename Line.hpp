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

#include <iostream>
#include "Station.hpp"
#include "Tramway.hpp"

class Line
{
    public:
        Line();
        Line(int id, int nbElem, Station** tabStation);
        Line(const Line& line);
        ~Line();

        int size() const { return m_nbElem; }
        int getId() const { return m_id; }


        /**
         * \brief Affichage
         *
         * \param[out] sout : flux de sortie
         */
        void display(std::ostream& sout) const;

        void setFirst(Tramway* first);

        /**
         * \brief Affichage (via surcharge d'operateur)
         *
         * \param[out] sout : flux de sortie
         * \param[in] l : ligne a afficher
         */
        friend std::ostream& operator<<(std::ostream& sout, const Line& l);

        Station* operator[](int i);
        const Station* operator[](int i) const;
        Line& operator=(const Line& line);
        Tramway* first() const { return m_first; }
    private:
        int m_id;
        int m_nbElem;
        Station** m_tabStation;
        Tramway* m_first;
};

#endif // LINE_HPP_INCLUDED
