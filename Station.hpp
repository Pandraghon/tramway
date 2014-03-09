#ifndef STATION_HPP
#define STATION_HPP

/**
 * \file Station.hpp
 * \brief Arret de Tramway
 * \author Sylvain_Albasser
 * \date 21/02/2014 (creation)
 * \date 09/03/2014 (derniere modification)
 * \version 0.1
 */

#include <cstdlib>
#include <iostream>
#include <string>

/**
 * \class Station
 *
 * Classe regroupant les informations et les methodes liees aux arrets
 */
class Station
{
    public:

        Station();

        /**
         * \brief Constructeur
         *
         * \param[in] id : numero d'identification de l'arret
         * \param[in] name : nom de l'arret
         * \param[in] posX : abscisse de l'arret
         * \param[in] posY : ordonnee de l'arret
         * \param[in] duration : temps d'arret min
         */
        Station(int id, const std::string& name, int posX, int posY, int duration);


        /** Acces a m_id
         * \return m_id : numero d'identification
         */
        int getId() const { return m_id; }

        /** Acces a m_name
         * \return m_name : nom de l'arret
         */
        std::string getName() const { return m_name; }

        /** Acces a m_posX
         * \return m_posX : abscisse
         */
        int getPosX() const  { return m_posX; }

        /** Acces a m_posY
         * \return m_posY : ordonnee
         */
        int getPosY() const { return m_posY; }

        /** Acces a m_duration
         * \return m_duration : duree d'arret min (secondes)
         */
        int getDuration() const { return m_duration; }


        /**
         * \brief Affichage
         *
         * \param[out] sout : flux de sortie
         */
        void display(std::ostream& sout) const;

        /**
         * \brief Affichage (via surcharge d'operateur)
         *
         * \param[out] sout : flux de sortie
         * \param[in] station : station a afficher
         */
        friend std::ostream& operator<<(std::ostream& sout, const Station& station);

    private:
        int m_id; //!< Numero d'identification de l'arret
        std::string m_name; //!< Nom de l'arret
        int m_posX; //!< Abscisse
        int m_posY; //!< Ordonnee
        int m_duration; //!< Temps d'arret min
};

#endif // STATION_HPP
