#include "aed2_SimCity.h"

// Completar

aed2_SimCity::aed2_SimCity(aed2_Mapa m) :
    _mapa(m), construcciones(list<tuple<Casilla, Nat, bool>>()), huboConstr(false), turnoActual(0), cantidadUniones(0) {}


void aed2_SimCity::agregarCasa(Casilla c) {
    tuple<Casilla, Nat, bool> elem(c, 0, false);
    construcciones.insert(construcciones.end(), elem);
    huboConstr = true;
}

void aed2_SimCity::agregarComercio(Casilla c) {
    tuple<Casilla, Nat, bool> elem(c, 0, true);
    construcciones.insert(construcciones.end(), elem);
    huboConstr = true;
}

void aed2_SimCity::avanzarTurno() {
    for(tuple<Casilla, Nat, bool> con: construcciones) {
        get<1>(con)++;
    }
    turnoActual++;
    huboConstr = false;
}

bool aed2_SimCity::huboConstruccion() const {
    return huboConstr;
}

Nat aed2_SimCity::popularidad() const {
    return cantidadUniones;
}

aed2_Mapa aed2_SimCity::mapa() const {
    return _mapa;
}

Nat aed2_SimCity::antiguedad() const {
    return turnoActual;
}

Nat distanciaManhatan(Casilla c1, Casilla c2) {
    return abs(c1.first - c2.first) + abs(c1.second - c2.second);
}

set<Casilla> aed2_SimCity::casas() const {
    set<Casilla> casillasCasas = {};
    for(tuple<Casilla, Nat, bool> con: construcciones){
        if(!get<2>(con)){
            casillasCasas.insert(get<0>(con));
        }
    }

    return casillasCasas;
}

set<Casilla> aed2_SimCity::comercios() const {
    set<Casilla> casillasComercios = {};
    set<Casilla> casillasCasas = casas();
    for(tuple<Casilla, Nat, bool> con: construcciones){
        if(get<2>(con) && !casillasCasas.count(get<0>(con))){
            casillasComercios.insert(get<0>(con));
        }
    }

    return casillasComercios;
}

Nat aed2_SimCity::nivel(Casilla c) const {
    int maxNivelDistancia3 = -1;
    int maxCasa = -1;
    int maxComercio = -1;
    for(tuple<Casilla, Nat, bool> con : construcciones){
        if (get<0>(con) == c){
            if (!get<2>(con)){
                if (get<1>(con) > maxCasa){
                    maxCasa = get<1>(con);
                }
            } else {
                if(get<1>(con) > maxComercio){
                    maxComercio = get<1>(con);
                }
            }
        } else {
            if(distanciaManhatan(get<0>(con), c) < 3 && !get<2>(con)){
                if (maxNivelDistancia3 < get<1>(con)){
                    maxNivelDistancia3 = get<1>(con);
                }
            }
        }
    }

    Nat res = 0;
    if (maxCasa != -1){
        res = maxCasa;
    } else {
        if (maxNivelDistancia3 != -1){
            res = maxNivelDistancia3;
        } else {
            res = maxComercio;
        }

    }

    return res;
}

void aed2_SimCity::unir(aed2_SimCity sc) {}


