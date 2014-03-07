#ifndef FILESYSTEM_HPP_INCLUDED
#define FILESYSTEM_HPP_INCLUDED

/**
 * \file filesystem.hpp
 * \brief Systeme de gestion des fichiers
 * \author Sylvain_Albasser
 * \date 21/02/2014 (creation)
 * \date 21/02/2014 (derniere modification)
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
 * \namespace fs
 *
 * Namespace regroupant les outils de gestion des fichiers.
 */
namespace fs{

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
    void loadStations(const std::string& stationFile, std::vector< Station >& station);
}

#endif // FILESYSTEM_HPP_INCLUDED
