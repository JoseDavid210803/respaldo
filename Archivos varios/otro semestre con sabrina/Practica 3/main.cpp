#include <iostream>
#include <stdlib.h>
#include <clocale>
#include <cstring>
#include <vector>
#include <ctime>

using namespace std;

class VehiculoTerrestre;
class Persona;
class Carro;
class Moto;

class VehiculoTerrestre{
private:
    char placa[7];
    char color[20];
    string marca , modelo;
public:
    void pedirDatos();
    void imprimirDatos();
    virtual void propietario() = 0;
VehiculoTerrestre(char placaO[], char colorO[], string marca, string modelo);
~VehiculoTerrestre();
};

class Carro: public VehiculoTerrestre{
private:
    int num_puertas;
    Persona *comprador1;
public:
    void pedir_datos();
    void imprimir_datos() const;
    void propietario() override;
Carro(char *placa, char *color, string marca, string modelo, int num_puertas, Persona *comprador2);
~Carro();
};

class Moto: public VehiculoTerrestre {
private:
    bool canastilla;
    Persona *comprador1;
public:
    void pedir_datos();
    void imprimir_datos() const;
    void propietario() override;
Moto(char *placa, char *color, string marca, string modelo, bool canastilla, Persona *comprador1);
~Moto();
};

class Persona{
protected:
    string nombre , rfc;
    vector<Carro >c;
    vector<Moto >m;
public:
    void setrfc(string _rfc);
    string getrfc();
    void setnombre(string _nombre);
    string getnombre();
    void asignal(vector <Carro >hl, vector <Moto >h);
    Persona(string _nombre, string rfc, vector<Carro> vec, vector<Moto> vec2);
    ~Persona();
};

VehiculoTerrestre::VehiculoTerrestre(char placaO[], char colorO[], string marca, string modelo){
    strcpy(placa, placaO);
    strcpy(color, colorO);
    this->marca = marca;
    this->modelo = modelo;
}
VehiculoTerrestre::~VehiculoTerrestre(){};

Carro::Carro(char placa[], char color[], string marca, string modelo, int num_puertas, Persona *comprador2) : VehiculoTerrestre(placa, color, std::move(marca), std::move(modelo)), comprador1(comprador2) {
    this->num_puertas = num_puertas;
}
Carro::~Carro(){};

Moto::Moto(char placa[], char color[], string marca, string modelo, bool canastilla, Persona *comprador1) : VehiculoTerrestre(placa, color, std::move(marca), std::move(modelo)), comprador1(comprador1) {
    this->canastilla = canastilla;
}
Moto::~Moto(){};

Persona::Persona(string _nombre, string _rfc,vector<Carro> VectorA,vector<Moto> VectorB) {
    nombre = _nombre;
    rfc = _rfc;
    c = VectorA;
    m = VectorB;
}
Persona::~Persona()= default;

void VehiculoTerrestre::pedirDatos(){
    cout<<"Ingresa el numero de placa: ";
    cin>>placa;
    cout<<"Ingresa el color del vehiculo: ";
    cin>>color;
    cout<<"Ingresa la marca del vehiculo: ";
    cin>>marca;
    cout<<"Ingresa el año/modelo del vehiculo: ";
    cin>>modelo;
}
void VehiculoTerrestre::imprimirDatos(){
    cout<<"Datos del vehiculo: "<<endl<< "Placa: "<<placa<<endl<<"Color: "<<color<<endl<<"Marca: "<<marca<<endl<<"Modelo: "<<modelo<<endl;
}

void Carro::pedir_datos(){
    cout <<"Numero de puertas: ";
    cin >> num_puertas;
}
void Carro::imprimir_datos() const{
    cout <<"Numero de puertas: " << num_puertas << endl;
}

void Moto::pedir_datos(){
    int canastillacon;
    cout<<"¿Tiene canastilla tu vehiculo?"<<endl<<"[1]Si"<<endl<<"[2]No"<<endl;
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
        cout<<"Con canastilla"<<endl;
    }
    else{
        cout<<"Sin canastilla"<<endl;
    }
}

void Persona::setrfc(string rfcO){
    rfc = rfcO;
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
    cout <<"Nombre: " << comprador1->getnombre()<<endl;
    cout <<"NRC: " << comprador1->getrfc()<<endl;
}
void Moto::propietario(){
    cout <<"\nComprador de las motos " << endl;
    cout <<"Nombre: " << comprador1->getnombre()<<endl;
    cout <<"NRC: " << comprador1->getrfc()<<endl;
}
void Persona::asignal(vector<Carro>hl, vector<Moto>hm){
    int op = 0;
    system("cls");
    cout <<"¿Que tipo de vehiculo desea registrar?" << endl;
    cout <<"[1]Carro" << endl;
    cout <<"[2]Moto" << endl;
    cout <<"Opcion: ";
    cin >> op;
    int cant = 0;
    char PlacaO[10] = "";
    char colorO[10] = "";
    string marcaO = "";
    string modeloO = "";
    if(op==1){
        cout <<"\n�Cuantos carros desea registrar?" << endl;
        cout<< "Ingrese cantidad: ";cin >> cant;
        system("cls");
        for(int i=0;i<cant;i++){
            cout << "\nCarro " << i+1 << endl;
            Carro *CarroO = new Carro(PlacaO,colorO,marcaO,modeloO,0, this);
            CarroO->pedirDatos();
            CarroO->pedir_datos();
            hl.push_back(*CarroO);
        }
        system("cls");
        hl[0].propietario();
        cout << "Datos de los carros comprados: " << endl;
        for(int i=0;i<cant;i++){
            cout << "Carro " << i+1 << endl;
            hl[i].imprimirDatos();
            hl[i].imprimir_datos();
        }
    }else if(op==2){
        cout << "Cuantas motos seran registradas?" << endl;
        cin >> cant;
        system("cls");
        for(int i=0;i<cant;i++){
            cout << "Moto " << i+1 << endl;
            Moto *motos = new Moto(PlacaO,colorO,marcaO,modeloO,false, this);
            motos->pedirDatos();
            motos->pedir_datos();
            hm.push_back(*motos);
        }
        hm[0].propietario();
        system("cls");
        cout << "Datos de las motos compradas: " << endl;
        for(int i=0;i<cant;i++){
            cout << "Moto " << i+1 << endl;
            hm[i].imprimirDatos();
            hm[i].imprimir_datos();
        }
    }
    else{
        cout << "Opcion no valida" << endl;
    }
}

int Salir(int op){
    cout << "¿Desea salir del programa?"<<endl<<"[1]Si"<<endl<<"[2]No"<<endl;
    cin >> op;
    return op;
}

int main() {
    setlocale(LC_ALL,"");
    int cerrar;
    do{
        system("cls");
        vector<Carro> carros;
        vector<Moto> motos;
        string name;
        string rfc_ejecucion;
        int opcM = 0;
        system("cls");
        cout << "[1]Registrar datos" << endl;
        cout << "[2]Salir del programa" << endl;
        cin >> opcM;
        switch(opcM){
            case 1:{
                system("cls");
                cout << "Por favor registra tus datos\nNombre: ";
                cin >> name;
                cout << "RFC: ";
                cin >> rfc_ejecucion;
                Persona Persona1 = *new Persona(name, rfc_ejecucion, carros, motos);
                Persona1.setnombre(name);
                Persona1.setrfc(rfc_ejecucion);
                Persona1.asignal(carros,motos);
                cerrar = Salir(cerrar);
                break;
            }
            case 2: {
                system("cls");
                cout << "Gracias por usar el programa c:" << endl;
                cerrar = 1;
                break;
            }
            default: {
                cout << "Opcion no valida" << endl;
                cerrar = Salir(cerrar);
                break;
            }
        }
    }while(cerrar!=1);
    return 0;
}
