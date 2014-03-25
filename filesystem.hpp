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
#include "Line.hpp"
#include "Station.hpp"
#include "Tramway.hpp"


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
        int getNbStations() const { return m_nbStations; }
        int getNbLines() const { return m_nbLines; }
        Station* getTabStations() const { return m_tabStations; }
        Line* getTabLines() const { return m_tabLines; }
        Line* getLineById(int id) const;

        void display(std::ostream& out) const;
        friend std::ostream& operator<<(std::ostream& sout, const FileSystem& fs);

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
         * \brief Recuperation des trams
         *
         * Recupere les informations des trams contenues dans le fichier tramwayFile
         * et les range dans une structure
         *
         * \param[in] tramwayFile : nom du fichier des informations
         */
        bool loadTramways(const std::string& tramwayFile);

        /**
         * \brief Recuperation des arrets
         *
         * Recupere les informations des arrets contenues dans le fichier stationFile
         * et les range dans une structure
         *
         * \param[in] stationFile : nom du fichier des informations
         */
        bool loadStations(const std::string& stationFile);

        /**
         * \brief Recuperation des lignes
         *
         * Recupere les informations des lignes contenues dans le fichier lineFile
         * et les range dans une structure
         *
         * \param[in] lineFile : nom du fichier des informations
         */
        bool loadLines(const std::string& lineFile);

        bool m_valid;
        int m_nbStations, m_nbLines, m_nbTramways;
        Station* m_tabStations;
        Line* m_tabLines;
        Tramway* m_tabTramways;
};

#endif // FILESYSTEM_HPP_INCLUDED
