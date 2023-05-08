#ifndef CELDA_ENTERO_H
#define CELDA_ENTERO_H


class celda_entero
{

public:
    celda_entero()
    {
        celda=0;
    }
    explicit celda_entero(int valor_inicial=0);
    void set_celda(int nueva_celda);
    int get_celda();

private:

    int celda;

};

#endif // CELDA_ENTERO_H
