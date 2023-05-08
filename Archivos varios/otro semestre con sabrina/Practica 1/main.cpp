#include <iostream>
#include <windows.h>
#include <ctime>

using namespace std;

class Edad{
private:
    int Anio_Act, Dia_y_Anio, Dia_Nac, Mes_Nac, Anio_Nac, Dias, Edad_Act;
    char Nombre[20];
public:
    void Entrada_Datos();
    void Operaciones();
    void Imprimir_Datos();
    void Convertir();
Edad();
~Edad();
     };


void Edad::Entrada_Datos(){
    cout<<"ingresa tu nombre: ";
    cin>>Nombre;
    system("cls");
    cout<<"Ingresa tu dia de nacimiento en formato [DD] ";
    cin>>Dia_Nac;
    system("cls");
    cout<<"Ingresa tu mes de nacimiento en formato [MM] ";
    cin>>Mes_Nac;
    system("cls");
    cout<<("Ingresa tu anio de nacimiento en formato [AAAA] ");
    cin>>Anio_Nac;
}

void Edad::Operaciones(){
    time_t now = time(0);
    tm *date_ = localtime(&now);
    Anio_Act=1900 + date_->tm_year;
    Edad_Act= Anio_Act - Anio_Nac;
    Dia_y_Anio = 1+date_->tm_yday;
}

void Edad::Convertir(){
    int Dias_Mes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    Dias = 0;
    for(int i = 0; i < (Mes_Nac-1); i++){
        Dias+=Dias_Mes[i];
    };
    Dias+=Dia_Nac;
}
void Edad::Imprimir_Datos(){
    system("cls");
    if (Dias==Dia_y_Anio)
    {
        cout<<":0 hoy es tu cumpleanios "<<Nombre<<", feliz cumpleanios!!"<<endl;
        cout<<endl;
    }
    if (Dias>Dia_y_Anio){
        cout<<"aun no has cumplido anios este anio ";
        Edad_Act-=1;
    }
    if (Dias<Dia_y_Anio){
        cout<<"ya ha pasado tu cumpleanios este anio, ";
    }

    cout<<"Tienes "<<Edad_Act<<" anios"<<endl;

}
Edad::Edad(){}
Edad::~Edad(){}
int main()
{
    cout<<"Bienvenido al programa"<<endl;
    Sleep(1500);
    system("cls");
    Edad Edad_Usuario;
    Edad_Usuario.Entrada_Datos();
    Edad_Usuario.Convertir();
    Edad_Usuario.Operaciones();
    Edad_Usuario.Imprimir_Datos();
    return 0;
}
