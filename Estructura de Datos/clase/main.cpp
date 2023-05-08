//Librerias
#include <iostream>
#include <string>
#include "celda_entero.h"

using namespace std;

//clase del 13 de febrero
template <typename objeto>
class celda_memoria
{
public:
    explicit celda_memoria(const objeto &valor_inicial=objeto{}):valor_celda{valor_inicial}{

    }
const objeto & get_valor()
{
    return valor_celda;
}
void set_valor(const objeto &x)
{
    valor_celda=x;
}
    objeto valor_celda;
private:
};

int main()
{
    celda_memoria <int> a, c;
    celda_memoria <string> b{"Hola"};
    a.set_valor(6);
    a.set_valor(7);
    c=a;
    vector <float> f;

    cout<<"El valor de a es: "<<a.get_valor()<<endl;
    cout<<"El valor de b es: "<<b.get_valor()<<endl;
    cout<<"El valor de c es: "<<c.get_valor()<<endl;


    celda_entero entero(6);
    cout<< "El valor del entero es: "<<entero.get_celda()<<endl;
    return 0;
}
