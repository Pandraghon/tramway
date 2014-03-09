#ifndef FILESYSTEM_HPP_INCLUDED
#define FILESYSTEM_HPP_INCLUDED

/**
 * \file FileSystem.hpp
 * \brief Systeme de gestion des fichiers
 * \author Sylvain_Albasser
 * \date 21/02/2014 (creation)
 * \date 09/03/2014 (derniere modification)
 * \version 0.1
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Station.hpp"
#include "Line.hpp"


/**
 * \class fs
 *
 * Classe regroupant les outils de gestion des fichiers.
 */
class FileSystem
{
    public:
        FileSystem(const std::string& stationFile, const std::string& lineFile, const std::string& tramwayFile);
        ~FileSystem();

        bool isValid() const { return m_valid; }

    private:

        /**
         * \brief Nettoyage
         *
         * Nettoie le flux d'entree des espaces indesirables et des commentaire (#).
         *
         * \param[in,out] sin : flux d'entree
         */
        void clear(std::istream& sin);

        /**
         * \brief Recuperation des arrets
         *
         * Recupere les informations des arrets contenues dans le fichier stationFile
         * et les range dans une structure
         *
         * \param[in] stationFile : nom du fichier des informations
         * \param[out] station : structure des stations
         */
        bool loadStations(const std::string& stationFile);

        /**
         * \brief Recuperation des lignes
         *
         * Recupere les informations des lignes contenues dans le fichier lineFile
         * et les range dans une structure
         *
         * \param[in] lineFile : nom du fichier des informations
         * \param[out] line : structure des lignes
         */
        bool loadLines(const std::string& lineFile);

        bool m_valid;
        int m_nbStations, m_nbLines, m_nbTramways;
        Station* m_tabStations;
        Line* m_tabLines;
};

#endif // FILESYSTEM_HPP_INCLUDED
