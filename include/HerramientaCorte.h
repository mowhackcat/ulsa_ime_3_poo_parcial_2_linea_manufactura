#ifndef HERRAMIENTACORTE_H
#define HERRAMIENTACORTE_H

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

#endif