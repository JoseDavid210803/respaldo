#ifndef LISTA_S_H
#define LISTA_S_H

using namespace std;

template <typename objeto>
class lista_s
{
    public:
        lista_s(const lista_s <objeto> &rhs);
        ~lista_s();
        lista_s(lista_s <objeto> &&rhs);
        lista_s();
        lista_s <objeto> & operator=(const lista_s <objeto> & rhs);
        void iniciar();
        bool llena ();
        void push_b(const objeto &x);
        void push_b(objeto &&x);
        bool vacia();
        void push_f(const objeto &x);
        void push_f(objeto &&x);
        void push_p(const objeto &x, int po);
        void push_p(objeto &&x, int po);
        bool validacion();


    protected:

    private:
        struct nodo
        {
            objeto dato;
            nodo *next;
            nodo (const objeto &d=objeto{}, nodo *n=nullptr):dato{d},next{n}
            {}
            nodo (objeto &&d=objeto{}, nodo *n=nullptr):dato{move(d)},next{move(n)}
            {}
        };
        nodo *head;
        nodo *tail;
        int tamanio;
        int capacidad;
};

#endif // LISTA_S_H
