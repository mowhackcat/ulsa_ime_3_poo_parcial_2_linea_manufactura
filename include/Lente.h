#ifndef LENTE_H
#define LENTE_H

class Lente {
    private:
    int vidaUtil;
    int desgaste;
    bool limpio;

    public:
    Lente(int vidaUtil);

    void desgastar();
    void limpiar();
    void reemplazar();

    bool estaDesgastado() const;
    bool estaLimpio() const;

    int getVidaUtil() const;
    int getDesgaste() const;
};

#endif
