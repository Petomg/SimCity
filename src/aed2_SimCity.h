#ifndef AED2_SIMCITY_H
#define AED2_SIMCITY_H

#include <iostream>
#include <set>
#include <tuple>
#include "aed2_Mapa.h"

using namespace std;

using Nat = unsigned int;

using SimCity = /* Completar con su clase implementada de SimCity */

class aed2_SimCity {
public:

    // Generadores:

    aed2_SimCity(aed2_Mapa m);

    // Precondicion: Se puede construir en la Casilla c
    void agregarCasa(Casilla c);

    // Precondicion: Se puede construir en la Casilla c
    void agregarComercio(Casilla c);

    // Precondicion: Hubo construccion en el turno actual
    void avanzarTurno();

    // Precondicion: No se solapan las construcciones con los rios
    //  ni las construcciones de nivel maximo de ambas partidas
    void unir(aed2_SimCity sc);

    // Observadores:

    //Mapa mapa() const;
    aed2_Mapa mapa() const;

    set<Casilla> casas() const;

    set<Casilla> comercios() const;

    // Precondicion: Hay construccion en la Casilla p
    Nat nivel(Casilla c) const;

    bool huboConstruccion() const;

    Nat popularidad() const;

    Nat antiguedad() const;

    // Conversiones
    
    // Esta función sirve para convertir del SimCity de la cátedra al SimCity
    // implementado por ustedes
    //SimCity simCity();

private:
    aed2_Mapa _mapa;
    bool huboConstr;
    Nat turnoActual;
    Nat cantidadUniones;
    list<tuple<Casilla, Nat, bool>> construcciones;

};

#endif // AED2_SIMCITY_H
