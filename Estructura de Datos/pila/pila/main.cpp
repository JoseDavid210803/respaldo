#include <iostream>
#include <string>

#define cap 10

using namespace std;

template <typename objeto>
class pila
{
    private:
    int top;
    int capacidad;
    objeto *arr;

    public:
    explicit pila (int tam=0):top{tam},capacidad{top+cap}
    {
        arr=new objeto[capacidad];
    }
    pila (const pila &rhs):top{rhs.top},capacidad{rhs.capacidad}, arr{nullptr}
    {
        arr=new objeto[capacidad];
        for(int k=0;k<top;k++)
        arr[k]=rhs.arr[k];
    }
    pila(pila &&rhs)
    {
        rhs.top=0;
        rhs.capacidad=0;
        rhs.arr=nullptr;
    }
    ~pila()
    {
        delete []arr;
    }
    pila & operator = (const pila &rhs)
    {
        pila copia=rhs;
        swap(*this, copia);
        return *this;
    }
    pila & operator = (pila &&rhs)
    {
        swap(top, rhs.top);
        swap(capacidad, rhs.top);
        swap(arr, rhs.arr);
        return *this;
    }
    void push_final(const objeto &rhs)
    {
        if(top==capacidad)
            new_arr(2*capacidad);//invocar metodo para aumentar el espacio
        arr[top]=rhs;
        top++;
    }
    void push_final(objeto &&rhs)
    {
        if(top==capacidad)
            new_arr(2*capacidad);//invocar metodo para aumentar el espacio
        arr[top]=move(rhs);
        top++;
    }
    void pop_final()
    {
        if(!vacia())//metodo
        top--;
    }
    int vacia()
    {
        if(top==0)
            return 1;
        else
            return 0;
    }
    const objeto & peek()const
    {
        return arr[top-1];
    }
    int tam()const
    {
        return top;
    }
    int capa()const
    {
        return capacidad;
    }
    void new_arr(int nueva_capacidad)
    {
        if(top<capacidad)
            return;
        objeto *nuevo_arreglo=new objeto[nueva_capacidad];
        for (int k=0; k<top; k++)
            nuevo_arreglo[k]=arr[k];
        capacidad = nueva_capacidad;
        swap(arr, nuevo_arreglo);
        delete []nuevo_arreglo;
    }
    void nuevo_top(int nuevo_tam)
    {
        if(nuevo_tam>capacidad)
            new_arr(nuevo_tam*2);
        top=nuevo_tam;
    }
    objeto & operator[] (int i)
    {
        return arr[i];
    }
    const objeto & operator[] (int i)const
    {
        return arr[i];
    }

    typedef objeto *iterador;
    typedef const objeto *const_iterador;

    iterador inicio()
    {
        return &arr[0];
    }
    const_iterador inicio()const
    {
        return &arr[0];
    }

    iterador fin()
    {
        return &arr[top-1];
    }
    const_iterador fin()const
    {
        return &arr[top-1];
    }
    void push_inicio(const objeto& x) {
    if(top == capacidad)
        new_arr(2*capacidad);
    for(int i = top; i > 0; i--)
        arr[i] = arr[i-1];
    arr[0] = x;
    top++;
    }

    void push_inicio(objeto&& x) {
    if(top == capacidad)
        new_arr(2*capacidad);
    for(int i = top; i > 0; i--)
        arr[i] = move(arr[i-1]);
    arr[0] = move(x);
    top++;
    }

    void peek_td() {
    for (int i = 0; i < top; i++) {
        cout << arr[i] << " ";
    }
    }
};

int get_precedence(char op) {
    switch(op) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        default:
            return 0;
    }
}

string infija_posfija(pila<char> &operadores, string infija) {
    string posfija;
    for (char c : infija) {
        if (isdigit(c)) {
            posfija += c;
        } else if (c == '(') {
            operadores.push_final(c);
        } else if (c == ')') {
            while (!operadores.vacia() && operadores.peek() != '(') {
                posfija += operadores.peek();
                operadores.pop_final();
            }
            if (!operadores.vacia() && operadores.peek() == '(') {
                operadores.pop_final();
            }
        } else {
            while (!operadores.vacia() && get_precedence(c) <= get_precedence(operadores.peek())) {
                posfija += operadores.peek();
                operadores.pop_final();
            }
            operadores.push_final(c);
        }
    }
    while (!operadores.vacia()) {
        posfija += operadores.peek();
        operadores.pop_final();
    }
    return posfija;
}


int main()
{
    pila<char> operadores;
    string infija, posfija;

    cout << "Ingresa la expresion infija: ";
    cin >> infija;

    posfija = infija_posfija(operadores, infija);

    cout << "La expresion posfija es: " << posfija << endl;
    return 0;
}
