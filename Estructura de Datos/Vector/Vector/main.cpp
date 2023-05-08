#include <iostream>
#define cap 10

using namespace std;

//Plantilla
template <typename objeto>
class vector_p
{
    public:
    explicit vector_p (int tam=0):tamanio{tam},capacidad{tamanio+cap}
    {
        arr=new objeto[capacidad];
    }
    vector_p (const vector_p &rhs):tamanio{rhs.tamanio},capacidad{rhs.capacidad}, arr{nullptr}
    {
        arr=new objeto[capacidad];
        for(int k=0;k<tamanio;k++)
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
    vector_p & operator = (const vector_p &rhs)
    {
        vector_p copia=rhs;
        swap(*this, copia);
        return *this;
    }
    vector_p & operator = (vector_p &&rhs)
    {
        swap(tamanio, rhs.tamanio);
        swap(capacidad, rhs.tamanio);
        swap(arr, rhs.arr);
        return *this;
    }
    void push_final(const objeto &rhs)
    {
        if(tamanio==capacidad)
            new_arr(2*capacidad);//invocar metodo para aumentar el espacio
        arr[tamanio]=rhs;
        tamanio++;
    }
    void push_final(objeto &&rhs)
    {
        if(tamanio==capacidad)
            new_arr(2*capacidad);//invocar metodo para aumentar el espacio
        arr[tamanio]=move(rhs);
        tamanio++;
    }
    void pop_final()
    {
        if(!vacia())//metodo
        tamanio--;
    }
    int vacia()
    {
        if(tamanio==0)
            return 1;
        else
            return 0;
    }
    const objeto & peek()const
    {
        return arr[tamanio-1];
    }
    int tam()const
    {
        return tamanio;
    }
    int capa()const
    {
        return capacidad;
    }
    void new_arr(int nueva_capacidad)
    {
        if(tamanio<capacidad)
            return;
        objeto *nuevo_arreglo=new objeto[nueva_capacidad];
        for (int k=0; k<tamanio; k++)
            nuevo_arreglo[k]=arr[k];
        capacidad = nueva_capacidad;
        swap(arr, nuevo_arreglo);
        delete []nuevo_arreglo;
    }
    void nuevo_tamanio(int nuevo_tam)
    {
        if(nuevo_tam>capacidad)
            new_arr(nuevo_tam*2);
        tamanio=nuevo_tam;
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
        return &arr[tamanio-1];
    }
    const_iterador fin()const
    {
        return &arr[tamanio-1];
    }
    void push_inicio(const objeto& x) {
    if(tamanio == capacidad)
        new_arr(2*capacidad);
    for(int i = tamanio; i > 0; i--)
        arr[i] = arr[i-1];
    arr[0] = x;
    tamanio++;
    }

    void push_inicio(objeto&& x) {
    if(tamanio == capacidad)
        new_arr(2*capacidad);
    for(int i = tamanio; i > 0; i--)
        arr[i] = move(arr[i-1]);
    arr[0] = move(x);
    tamanio++;
    }

    void peek_td() {
    for (int i = 0; i < tamanio; i++) {
        cout << arr[i] << " ";
    }
    cout <<endl;
}

    private:
    int tamanio;
    int capacidad;
    objeto *arr;
};

//Clase Platillo
class Platillo{
private:

    string nombre;
    float precio;
    int porcion;
    string tipo; //Clasificacion
    string descripcion; //Ingredientes


public:
    string get_nombre()const{
        return nombre;
    }
    float get_precio()const{
        return precio;
    }
    int get_porcion()const{
        return porcion;
    }
    string get_tipo()const{
        return tipo;
    }
    string get_descripcion()const{
        return descripcion;
    }


    void set_nombre(string nombreT){
        nombre=nombreT;
    }
    void set_precio(float precioT){
        precio=precioT;
    }
    void set_porcion(int porcionT){
        porcion=porcionT;
    }
    void set_tipo(string tipoT){
        tipo=tipoT;
    }

    void set_descripcion(string descripcionT){
        descripcion=descripcionT;
    }

    explicit Platillo (string nom="No hay nombre",float prec=0,int porc=0,string tip="No hay tipo",string descr="No hay descripcion"):nombre{nom},precio{prec},porcion{porc},tipo{tip},descripcion{descr}{

    }

    Platillo(const Platillo &rhs):nombre{rhs.nombre},precio{rhs.precio},porcion{rhs.porcion},tipo{rhs.tipo},descripcion{rhs.descripcion}{

    }

    Platillo (Platillo &&rhs):
        nombre{move(rhs.nombre)},
        precio{rhs.precio},
        porcion{rhs.porcion},
        tipo{move(rhs.tipo)},
        descripcion{move(rhs.descripcion)}
    {

    }

    Platillo & operator= (const Platillo &rhs){

        Platillo copia=rhs;
        swap(*this,copia);
        return *this;
    }

    Platillo & operator= (Platillo &&rhs){
        swap(nombre,rhs.nombre);
        swap(precio,rhs.precio);
        swap(porcion,rhs.porcion);
        swap(tipo,rhs.tipo);
        swap(descripcion,rhs.descripcion);
        return *this;
    }

    bool  operator== (const Platillo &rhs)const {
        return (nombre == rhs.nombre && precio == rhs.precio && porcion == rhs.porcion && tipo==rhs.tipo && descripcion == rhs.descripcion);

    }
    bool  operator== (Platillo &&rhs){
        return (nombre == rhs.nombre && precio == rhs.precio && porcion == rhs.porcion && tipo==rhs.tipo && descripcion == rhs.descripcion);

    }

    bool  operator!= (const Platillo &rhs)const {
         return (nombre != rhs.nombre || precio != rhs.precio || porcion != rhs.porcion || tipo != rhs.tipo || descripcion != rhs.descripcion);

    }
    bool  operator!= (Platillo &&rhs){
        return (nombre != rhs.nombre || precio != rhs.precio || porcion != rhs.porcion || tipo != rhs.tipo || descripcion != rhs.descripcion);

    }

    friend ostream& operator<<(ostream& salida, const Platillo &rhs){
        salida<<endl<<rhs.nombre<<endl<<"$"<<rhs.precio<<" pesos"<<endl<<rhs.porcion<<" g"<<endl<<rhs.tipo<<endl<<rhs.descripcion<<endl;
        //cout<<"copia"<<endl;
        return salida;
    }
    friend ostream& operator<<(ostream& salida, Platillo &&rhs){
        salida<<endl<<rhs.nombre<<endl<<"$"<<rhs.precio<<" pesos"<<endl<<rhs.porcion<<" g"<<endl<<rhs.tipo<<endl<<rhs.descripcion<<endl;
        return salida;
    }

};

int main()
{
    vector_p <Platillo> menu{3};
    Platillo Entrada{"Crema de Elote",85,130,"Entrada","Sopa suave y cremosa hecha con elotes frescos, cebolla, ajo, caldo y crema."};
    Platillo Fuerte{"Filete de Res",195,350,"Plato Fuerte","Filete de res con pure de papas y vegetales al vapor."};
    Platillo Postre{"Pastel de Zanahoria",45,100,"Postre","Se elabora con zanahorias ralladas, harina, azucar, huevos, aceite vegetal y una combinación de especias."};

    menu[0]=Entrada;
    menu[1]=Fuerte;
    menu[2]=Postre;

    cout<<Entrada;
    cout<<Fuerte;
    cout<<Postre;

    return 0;
}
