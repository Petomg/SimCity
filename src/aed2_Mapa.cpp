#include "aed2_Mapa.h"

aed2_Mapa::aed2_Mapa() : _horizontal({}), _vertical({}){}


void aed2_Mapa::agregarRio(Direccion d, int p) {
    if(d == Horizontal){
        _horizontal.push_back(p);
    }
    else {
        _vertical.push_back(p);
    }
}


bool aed2_Mapa::hayRio(Casilla c) const {
    bool res = false;
    for (int p: _horizontal){
        if (p == c.second) res = true;
    }
    for (int p: _vertical){
        if (p == c.first) res = true;
    }

    return res;
}


void aed2_Mapa::unirMapa(aed2_Mapa m2) {
        _horizontal.insert(_horizontal.end(), m2._horizontal.begin(), m2._horizontal.end());
        _vertical.insert(_vertical.end(), m2._vertical.begin(), m2._vertical.end());
}


