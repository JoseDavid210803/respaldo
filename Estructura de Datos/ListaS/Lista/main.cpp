#include <iostream>
#include <wchar.h>
#include <unistd.h>
#include <stdlib.h>

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
        void imprimir();

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

template <typename objeto>
lista_s <objeto>::lista_s(const lista_s <objeto> &rhs)
{
            iniciar();
            /*for(auto &x:rhs)
            push_b(x);*/
            //copy ctor
}
template <typename objeto>
lista_s <objeto>::lista_s(lista_s <objeto> &&rhs):head{rhs.head},tail{rhs.tail},tamanio{rhs.tamanio},capacidad{rhs.capacidad}
{
            rhs.head=nullptr;
            rhs.tail=nullptr;
            rhs.tamanio=0;
            rhs.capacidad=10000;
}
template <typename objeto>
lista_s <objeto>::~lista_s()
{
	//metodo limpiar
    delete head;
    delete tail;
    //dtor
}
template <typename objeto>
lista_s <objeto>::lista_s()
{
    iniciar();
}
template <typename objeto>
lista_s <objeto> & lista_s <objeto>::operator=(const lista_s <objeto> & rhs)
{
    if (this == &rhs) return *this; // handle self assignment
    //assignment operator
    return *this;
}
template <typename objeto>
void lista_s <objeto>::iniciar()
{
	head=nullptr;
    tail=nullptr;
    tamanio=0;
    capacidad=10000;
}
template <typename objeto>
bool lista_s <objeto>::llena()
{
    if (tamanio==capacidad)
        return true;
    else
        return false;
}
template <typename objeto>
bool lista_s <objeto>::vacia()
{
    if(head==nullptr)
        return true;
    else
        return false;
}
template <typename objeto>
void lista_s <objeto>::push_b(const objeto &x)
{
    nodo *p=new nodo{x,nullptr};
    if(vacia())
    {
      p->next=head;
      head=p;
      tail=head;
      tamanio++;
    }
    else
    {
    tail->next=p;
    tail=p;
    tamanio++;
	}
}
template <typename objeto>
void lista_s <objeto>::push_b(objeto &&x)
{
    nodo *p=new nodo{move(x),nullptr};
    if(vacia())
    {
      p->next=head;
      head=p;
      tail=head;
      tamanio++;
    }
    else
    {
    tail->next=p;
    tail=p;
    tamanio++;
	}
}
template <typename objeto>
void lista_s <objeto>::push_f(const objeto &x)
{
    nodo *p=new nodo{x,nullptr};
    if(vacia())
    {
      p->next=head;
      head=p;
      tail=head;
      tamanio++;
    }
    else
    {
    p->next=head;
    head=p;
    tamanio++;
    }
}
template <typename objeto>
void lista_s <objeto>::push_f(objeto &&x)
{
    nodo *p=new nodo{move(x),nullptr};
    if(vacia())
    {
      p->next=head;
      head=p;
      tail=head;
      tamanio++;
    }
    else
    {
    p->next=head;
    head=p;
    tamanio++;
	}
}
template <typename objeto>
void lista_s <objeto>::push_p(const objeto &x, int po)
{
	nodo *pre, *aft;
    if(vacia())
    {
      cout<<"Error. La opcion que intenta utilizar es invalida"<<endl;
    }
    else if(validacion())
    {
		pre=head;
		for(int k=0;k<po-1;k++)
		pre=pre->next;
		aft=pre->next;
		nodo *p=new nodo{x,nullptr};
		p->next=aft;
		pre->next=p;
	}
	else
	{
	}
}
template <typename objeto>
void lista_s <objeto>::push_p(objeto &&x, int po)
{
	nodo *pre, *aft;
    if(vacia())
    {
      cout<<"Error. La opcion que intenta utilizar es invalida"<<endl;
    }
    else if(validacion())
    {
		pre=head;
		for(int k=0;k<po-1;k++)
		pre=pre->next;
		aft=pre->next;
		nodo *p=new nodo{move(x),nullptr};
		p->next=aft;
		pre->next=p;
	}
	else
	{
	}
}
template <typename objeto>
bool lista_s <objeto>::validacion()
{
	return true;
}
template<typename objeto>
void lista_s<objeto>::imprimir()
{
    nodo *p = head;
    while (p!= nullptr)
    {
        cout<<p->dato<<endl;
        p=p->next;
    }
}

int main()
{
    setlocale(LC_ALL, "");
    lista_s<int> lista;
    int opcion, valor, posicion;

    do {
        system("cls");
        cout << "         Menu     " << endl;
        cout << "--------------------- \n" << endl;
        cout << "1. Insertar al inicio" << endl;
        cout << "2. Insertar al final" << endl;
        cout << "3. Insertar en posición" << endl;
        cout << "4. Verificar si está vacía" << endl;
        cout << "5. Imprimir" << endl;
        cout << "6. Salir \n" << endl;
        cout << "Ingrese su opción: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                system("cls");
                cout << "\nUsted eligio insertar al inicio";
                cout << "\nIngrese el valor a insertar: ";
                cin >> valor;
                lista.push_f(valor);
                sleep(1.5);
                break;
            case 2:
                system("cls");
                cout << "\nUsted eligio insertar al final";
                cout << "\nIngrese el valor a insertar: ";
                cin >> valor;
                lista.push_b(valor);
                sleep(1.5);
                break;
            case 3:
                system("cls");
                cout << "\nUsted eligio insertar por posicion";
                cout << "\nIngrese el valor a insertar: ";
                cin >> valor;
                cout << "Ingrese la posición: ";
                cin >> posicion;
                lista.push_p(valor, posicion);
                sleep(2);
                break;
            case 4:
                system("cls");
                if (lista.vacia()) {
                    cout << "La lista está vacía" << endl;
                    sleep(2);
                } else {
                    cout << "La lista no está vacía" << endl;
                    sleep(2);
                }
                break;
            case 5:
                system("cls");
                cout << "Su lista simple es: " << endl;
                lista.imprimir();
                sleep(5);
                break;
            case 6:
                system("cls");
                cout << "Saliendo..." << endl;
                sleep(3);
                break;
            default:
                system("cls");
                cout << "Opción inválida" << endl;
                system("PAUSE");
        }

    } while (opcion != 6);

    return 0;
}
