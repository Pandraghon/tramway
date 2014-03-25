#include "Tramway.hpp"

Tramway::Tramway() : d_id(0), d_distance(0), d_tempsdarret(0),
                         d_stationsuivante(1), d_sens(1), d_vitesse(1), d_distancemin(0),
                         d_precedent(0), d_suivant(0)
{

}

Tramway::Tramway(int id, double distancemin, int stationsuivante, int sens, double vitesse, Tramway* precedent)
    : d_id(id), d_distance(0), d_tempsdarret(0),
        d_stationsuivante(stationsuivante), d_sens(sens),
        d_vitesse(vitesse), d_distancemin(distancemin), d_precedent(precedent), d_suivant(0)
{

}

int Tramway::stationPrecedente() const
{
    return d_stationsuivante-d_sens;
}

int Tramway::stationSuivante() const
{
    return d_stationsuivante;
}

int Tramway::sens() const
{
    return d_sens;
}

double Tramway::distanceParcourue() const
{
    return d_distance;
}

Tramway* Tramway::tramPrecedent() const
{
    return d_precedent;
}

void Tramway::display(std::ostream& sout) const
{
    sout << "Tramway " << d_id << " - Max " << d_vitesse << "px/s";
}

std::ostream& operator<<(std::ostream& sout, const Tramway& t)
{
    t.display(sout);
    return sout;
}
