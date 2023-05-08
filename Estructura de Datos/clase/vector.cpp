#include <iostream>

using namespace std;
template <typename objeto>
class vector_p
{
public:
    explicit vector_p (int tam=0):tamanio{tam}, capacidad{tam+1}
    {
        arr= new objeto[capacidad];
    }
    vector_p{const vector_p &rhs}:tamanio{rhs.tamanio},capacidad{rhs.capasidad},arr{nullptr}
    {
        arr= new objeto[capacidad];
        for (int k=0; k<tamanio;k++)
            arr[k]=rhs.arr[k];

    }
    vector_p(vector_p &&rhs)
    {
        rhs.tamanio=0;
        rhs.capacidad=0;
        rhs.arr=nullptr;
    }
    ~vector_p()
    {
        delete []arr;
    }
    vector_p & operator= (vector_p &&rhs)
    {
        swap(tamanio, rhs.tamanio);
        swap(capacidad, rhs.capacidad);
        swap(arr, rhs.arr);
        return *this;
    }
    void push_final(const objeto &x)
    {
        if(tamanio==capacidad)
            capacidad==capacidad+1; //pasar a un metodo separado
        arr[tamanio]=x;
        tamanio++;
    }
    void push_final(objeto &&x)
    {
        if(tamanio==capacidad)
            capacidad==capacidad+1; //pasar a un metodo separado
        arr[tamanio]= move(x);
        tamanio++;
    }
private:
    int tamanio;
    int capacidad;
    objeto *arr;
};
int main()
{
    return 0;
}
