#ifndef TRAMWAY_HPP_INCLUDED
#define TRAMWAY_HPP_INCLUDED

#include <iostream>

class FileSystem;

class Tramway
{
public:
	Tramway();
	Tramway(int id, double distancemin, int stationsuivante, int d_sens, double vitesse, Tramway* precedent);
	int stationPrecedente() const; // d_stationsuivante+sens
	int stationSuivante() const;
	double distanceParcourue() const;
	int sens() const;
	Tramway* tramPrecedent() const;

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
     * \param[in] l : ligne a afficher
     */
    friend std::ostream& operator<<(std::ostream& sout, const Tramway& t);
	friend FileSystem;
private:
    int d_id;
	double d_distance; //distance parcourue
	int d_tempsdarret; //temps d’arrêt en ms
	int d_stationsuivante; //indice station suivante
	int d_sens; //sens -1 ou 1
	double d_vitesse; //vitesse en pixels/s
	double d_distancemin; //distance mini avec le tram precedent
	Tramway *d_precedent, *d_suivant;
};

#endif // TRAMWAY_HPP_INCLUDED
