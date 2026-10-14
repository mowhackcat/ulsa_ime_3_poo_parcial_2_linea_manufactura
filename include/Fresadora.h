#ifndef FRESADORA_H
#define FRESADORA_H

#include "Maquina.h"
#include <string>

class HerramientaCorte {
private:
    int vidaUtil;
    int limiteDesgaste;

public:
    explicit HerramientaCorte(int limite);

    bool desgastar();
    void restaurar();

    int getVidaUtil() const;
    int getLimiteDesgaste() const;
    bool necesitaMantenimiento() const;
};

class Fresadora : public Maquina {
private:
    HerramientaCorte herramienta;
    int tiempoPorPieza;
    int ranurasRealizadas;
public:
    Fresadora(int id, const std::string& nombre,
              int tiempo, int limiteDesgaste);
              bool ranurar ();
              void realizarMantenimiento();
              void mostrarEstado() const;
               int getRanurasRealizadas() const;
               int getTiempoPorPieza() const;

};
#endif