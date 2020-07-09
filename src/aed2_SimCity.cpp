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
    list<tuple<Casilla, Nat, bool>> nuevaCons;
    for(tuple<Casilla, Nat, bool> con: construcciones) {
        Nat nivelNuevo = get<1>(con) + 1;
        tuple<Casilla, Nat, bool> nuevoElem(get<0>(con), nivelNuevo, get<2>(con));
        nuevaCons.push_back(nuevoElem);
    }

    construcciones.clear();
    construcciones = nuevaCons;
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
    Nat maxNivelDistancia3 = 0;
    Nat maxCasa = 0;
    Nat maxComercio = 0;
    bool hayCasa = false;
    for(tuple<Casilla, Nat, bool> con : construcciones){
        if (get<0>(con) == c){
            if (!get<2>(con)){
                hayCasa = true;
                if (get<1>(con) > maxCasa){
                    maxCasa = get<1>(con);
                }
            } else {
                if(get<1>(con) > maxComercio){
                    maxComercio = get<1>(con);
                }
            }
        } else {
            if(distanciaManhatan(get<0>(con), c) <= 3 && !get<2>(con)){
                if (maxNivelDistancia3 < get<1>(con)){
                    maxNivelDistancia3 = get<1>(con);
                }
            }
        }
    }

    Nat res = 0;
    if (hayCasa){
        res = maxCasa;
    } else {
        if (maxNivelDistancia3 > maxComercio){
            res = maxNivelDistancia3;
        } else {
            res = maxComercio;
        }

    }

    return res;
}

void aed2_SimCity::unir(aed2_SimCity sc) {}


