#include <iostream>//Libreria estandar
#include <stdlib.h>//Libreria estandar
#include <locale.h>//Libreria para poder poner la �
#include <cstring>//Libreria para la funcion strcpy
#include <vector>//Libreria para el manejo de vectores

using namespace std;


class Persona;
class Vehiculo;
class Carro;
class Moto;


class Vehiculo{
private:
    char placa[7];
    char color[10];
    string marca;
    string modelo;
public:
    void pedirDatos();
    void imprimirDatos();
    virtual void propietario() = 0;
    Vehiculo(char _placa[], char _color[], string marca, string modelo);
    ~Vehiculo();
};

Vehiculo::Vehiculo(char _placa[], char _color[], string marca, string modelo){
    strcpy(placa, _placa);
    strcpy(color, _color);
    this->marca = marca;
    this->modelo = modelo;
}
Vehiculo::~Vehiculo(){};

void Vehiculo::pedirDatos(){
    cout<<"Ingresa tu placa: ";
    cin>>placa;
    cout<<"Ingresa el color del vehculo: ";
    cin>>color;
    cout<<"Ingresa la marca del vehiculo: ";
    cin>>marca;
    cout<<"Ingresa el a�o del vehiculo: ";
    cin>>modelo;
}
void Vehiculo::imprimirDatos(){
    cout<<"Datos ingresados del vehiculo:\nPlaca: "<<placa<<"\nColor: "<<color;
    cout<<"\nMarca: "<<marca<<"\nModelo: "<<modelo;
}

class Carro: public Vehiculo{
private:
    int num_puertas;
    Persona *comprador_2;
public:
    void pedir_datos();
    void imprimir_datos() const;
    void propietario() override;
    Carro(char *placa, char *color, string marca, string modelo, int num_puertas, Persona *comprador2);
    ~Carro();
};


Carro::Carro(char placa[], char color[], string marca, string modelo, int num_puertas, Persona *comprador2) : Vehiculo(placa, color, std::move(marca), std::move(modelo)), comprador_2(comprador2) {
    this->num_puertas = num_puertas;
}
Carro::~Carro(){};

void Carro::pedir_datos(){
    cout <<"Numero de puertas: ";
    cin >> num_puertas;
}
void Carro::imprimir_datos() const{
    cout <<"Numero de puertas: " << num_puertas << endl;
}


class Moto: public Vehiculo {
    private:
        bool canastilla;
        Persona *comprador_1;
    public:
        void pedir_datos();
        void imprimir_datos() const;
        void propietario() override;
        Moto(char *placa, char *color, string marca, string modelo, bool canastilla, Persona *comprador1);
        ~Moto();
};
Moto::Moto(char placa[], char color[], string marca, string modelo, bool canastilla, Persona *comprador1) : Vehiculo(placa, color, std::move(marca), std::move(modelo)), comprador_1(comprador1) {
    this->canastilla = canastilla;
}
Moto::~Moto(){};

void Moto::pedir_datos(){
    int canastillacon;
    cout<<"�Tiene canastilla tu vehiculo?\n1)Si\n2)No\n";
    cin>>canastillacon;
    if(canastillacon == 1){
        canastilla = true;
    }
    else{
        canastilla = false;
    }
}
void Moto::imprimir_datos() const{
    if (canastilla == true){
        cout<<"\nCon canastilla\n";
    }
    else{
        cout<<"\nSin canastilla\n";
    }
}

class Persona{
    protected:
        string nombre;
        string rfc;
        vector<Carro >c;
        vector<Moto >m;
    public://Metodos
        void setrfc(string _rfc);
        string getrfc();
        void setnombre(string _nombre);
        string getnombre();
        void asignar(vector <Carro >hl, vector <Moto >h);
        Persona(string _nombre, string rfc, vector<Carro> vec, vector<Moto> vec2);
        ~Persona();
};
Persona::Persona(string _nombre, string _rfc,vector<Carro> vec,vector<Moto> vec2) {
    nombre = _nombre;
    rfc = _rfc;
    c = vec;
    m = vec2;
}
Persona::~Persona()= default;


void Persona::setrfc(string _rfc){
    rfc = _rfc;
}
string Persona::getrfc(){
    return rfc;
}
void Persona::setnombre(string _nombre){
    this->nombre = _nombre;
}
string Persona::getnombre(){
    return nombre;
}

void Carro::propietario(){
    cout <<"\nComprador de los carros " << endl;
    cout <<"Nombre: " << comprador_2->getnombre()<<endl;
    cout <<"Apellido: " << comprador_2->getrfc()<<endl;
}
void Moto::propietario(){
    cout <<"\nComprador de las motos " << endl;
    cout <<"Nombre: " << comprador_1->getnombre()<<endl;
    cout <<"Apellido: " << comprador_1->getrfc()<<endl;
}

void Persona::asignar(vector<Carro>hl, vector<Moto>hm){
    int opc = 0;
    system("cls");
    cout <<"\n�Que tipo de vehiculo desea registrar?" << endl;
    cout <<"1)Carro" << endl;
    cout <<"2)Moto" << endl;
    cout <<"Opcion: ";
    cin >> opc;
    int cant = 0;
    char plate[10] = "";
    char colors[10] = "";
    string marca = "";
    string model = "";
    if(opc==1){
        cout <<"\n�Cuantos carros desea registrar?" << endl;
        cout<< "Ingrese cantidad: ";cin >> cant;
        system("cls");
        for(int i=0;i<cant;i++){
            cout << "\nCarro " << i+1 << endl;
            Carro *cars = new Carro(plate,colors,marca,model,0, this);
            cars->pedirDatos();
            cars->pedir_datos();
            hl.push_back(*cars);
        }
        system("cls");
        hl[0].propietario();
        cout << "\nDatos de los carros comprados: " << endl;
        for(int i=0;i<cant;i++){
            cout << "\nCarro " << i+1 << endl;
            hl[i].imprimirDatos();
            hl[i].imprimir_datos();
        }
    }else if(opc==2){
        cout << "\n�Cuantas motos desea registrar?" << endl;
        cout<< "Ingrese cantidad: ";cin >> cant;
        system("cls");
        for(int i=0;i<cant;i++){
            cout << "\nMoto " << i+1 << endl;
            Moto *motos = new Moto(plate,colors,marca,model,false, this);
            motos->pedirDatos();
            motos->pedir_datos();
            hm.push_back(*motos);
        }
        hm[0].propietario();
        system("cls");
        cout << "\nDatos de las motos compradas: " << endl;
        for(int i=0;i<cant;i++){
            cout << "\nMoto " << i+1 << endl;
            hm[i].imprimirDatos();
            hm[i].imprimir_datos();
        }
    }else{
        cout << "Opcion no valida" << endl;
    }
}

int cerrarPrograma(int opc){
    cout << "\n�Desea salir del programa?\n1)Si\n2)No" << endl;
    cin >> opc;
    return opc;
}


int main() {
    setlocale(LC_CTYPE, "Spanish");
    int cerrar;
    do{
        system("cls");
        vector<Carro> carros;
        vector<Moto> motos;
        string name;
        string rfc_ejecucion;
        int opcMenu = 0;
        cout << "----------Sistema de compra de Vehiculos----------" << endl;
        cout << "1)Registrar datos de los compradores" << endl;
        cout << "2)Salir" << endl;
        cin >> opcMenu;
        switch(opcMenu){
            case 1:{
                system("cls");
                cout << "Por favor registra tus datos\nNombre: ";
                cin >> name;
                cout << "RFC: ";
                cin >> rfc_ejecucion;
                Persona compradores = *new Persona(name, rfc_ejecucion, carros, motos);
                compradores.setnombre(name);
                compradores.setrfc(rfc_ejecucion);
                compradores.asignar(carros,motos);
                cerrar = cerrarPrograma(cerrar);
                break;
            }
            case 2: {
                system("cls");
                cout << "Saliendo..." << endl;
                cerrar = 1;
                break;
            }
            default: {
                cout << "Opcion no valida" << endl;
                cerrar = cerrarPrograma(cerrar);
                break;
            }
        }
    }while(cerrar!=1);
    return 0;
}

