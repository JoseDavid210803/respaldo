#include "lista_s.h"

using namespace std;

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
      //que pasa
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
      //que pasa
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
