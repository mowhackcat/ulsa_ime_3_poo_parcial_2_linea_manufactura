#ifndef Prensa_H
#define Prensa_H

#include <string>
#include "Maquina.h"
#include "Troquel.h"

class Prensa : public Maquina {
private:
    Troquel troquel;
    int tiempoPorPieza;      
    int fuerzaTension;  

public:
    Prensa(const std::string& id, const std::string& nombre, int tiempoPorPieza, int vidaTroquel, double fuerzaTensionKN);

    void mostrarEstado() const;

    bool doblarPieza();
    void realizarMantenimiento();

    void setFuerzaTension(int fuerza);
    int getFuerzaTension() const;
    const Troquel& getTroquel() const;
};

#endif 