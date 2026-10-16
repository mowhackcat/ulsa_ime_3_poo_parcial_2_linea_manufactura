#ifndef MAQUINA_H
#define MAQUINA_H

#include <string>

class Maquina {
private:
    int id;
    std::string nombre;
    bool encendida;
    bool enFalla;
    int piezasProcesadas;
    int tiempoTrabajado;
    int paros;

protected:
    void registrarPieza();
    void agregarTiempo(int segundos);
    void reportarFalla();
    void registrarMantenimiento();

public:
    Maquina(int id, const std::string& nombre);

    virtual ~Maquina() = default;

    void encender();
    void apagar();

    bool estaEncendida() const;
    bool estaEnFalla() const;
    bool puedeProcesar() const;

    int getId() const;
    std::string getNombre() const;
    int getPiezasProcesadas() const;
    int getTiempoTrabajado() const;
    int getParos() const;

    virtual bool procesarPieza() = 0;
    virtual void realizarMantenimiento() = 0;
    virtual void mostrarEstado() const;
};

#endif
