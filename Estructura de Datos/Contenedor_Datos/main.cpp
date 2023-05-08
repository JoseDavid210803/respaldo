//Librerias
#include <iostream>
#include <windows.h>
#include <clocale>

using namespace std;

//Clase Padre
class Seguro{

private:

    string nombre; //Atributos
    string direccion;
    string apellido;
    string num;
    float precio;
    float prima;
    int folio;
    float p_reparacion;
    float resta;
    float deducible;
    float porcent;

public:

    void entrada_datos(); //Metodos
    void imprimir();
    void ed_dedu();
    void imp_dedu();

Seguro(); //Constructor
~Seguro();//Destructor
};

//Clase Hija
class Svida : public Seguro{

private:
    string Dia;
    string Mes; //Atributos
    string year;
    string nom;
    int num_beneficiarios;
public:
    void beneficiarios(); //Metodos
    void datosVida();
    void mostrarSvida();
Svida();//Constructor
~Svida();//Destructor
};

//clase hija
class Sauto : public Seguro{

private:

    int n_licencia;
    string marca;
    string modelo;
    string a_auto;

public:

    void d_sauto();
    void imp_sauto();

Sauto();//Constructor
~Sauto();//Destructor

};

//Clase Hija
class Scasa : public Seguro{

private:
    string seguridad;
    int a_construccion;
    int a_actual;
    int antiguedad;
public:
    void datosScasa();
    void mostrarScasa();

Scasa();
~Scasa();

};

//Metodos de Seguro (Clase padre)
void Seguro::entrada_datos(){

    cout<<"\nIngresa tu  1er nombre: "<<endl;
    cin>>nombre;
    system("cls");

    cout<<"\nIngresa tu  1er apellido: "<<endl;
    cin>>apellido;
    system("cls");

    cout<<"Ingresa la calle en donde vives: "<<endl;
    cin>>direccion;
    system("cls");

    cout<<"Ingresa el numero de la casa en donde vives: "<<endl;
    cin>> num;
    system("cls");

    cout<<"Ingresa el Folio de tu poliza: "<<endl;
    cin>>folio;
    system("cls");

    cout<<"Ingresa el monto de tu poliza: "<<endl;
    cin>>precio;
    system("cls");

    prima = precio/12;

};

void Seguro::imprimir(){

    cout<<"Hola "<<nombre<<" "<<apellido<<endl;
    cout<<"Su direccion es: "<<direccion<<" "<<num<<endl;
    cout<<"El folio de su seguro es: "<<folio<<endl;
    cout<<"Usted paga $"<<precio<<" pesos al año"<<endl;
    cout<<"Su prima mensual es de $"<<prima<<" pesos mensuales"<<endl;

};

void Seguro :: ed_dedu(){

    system("cls");
    cout<<"Por favor ingrese el presio de la reparacion"<<endl;
    cin>>p_reparacion;
    system("cls");

    cout<<"Ingrese el porcentaje del deducible: "<<endl;
    cin>>porcent;
    system("cls");

    deducible= p_reparacion*(((float)porcent)/((float)100));
    resta= p_reparacion-deducible;
};

void Seguro ::imp_dedu(){

    cout<<"\nEl daño equivale a $"<<p_reparacion<<" pesos."<<endl;
    cout<<"El seguro cubrira $"<<resta<<" pesos."<<endl;
    cout<<"Su deducible es de $"<<deducible<<" pesos."<<endl;

}

//Metodos de Svida
void Svida::datosVida(){
    entrada_datos();
    Sleep(1000);

    cout<<"Ingresa tu dia de nacimiento(DD): "<<endl;
    cin>>Dia;
    system("cls");

    cout<<"Ingresa tu mes de nacimiento(MM): "<<endl;
    cin>>Mes;
    system("cls");

    cout<<"Ingresa tu año de nacimiento(YYYY): "<<endl;
    cin>>year;
    system("cls");

    cout<<"Ingresa el numero de beneficiarios: "<<endl;
    cin>>num_beneficiarios;
    system("cls");
};

void Svida::mostrarSvida(){

    imprimir();
    cout<<"Usted nacio el "<<Dia<<"/"<<Mes<<"/"<<year<<endl;
    cout<<"\nSu seguro cubre a "<<num_beneficiarios<<" beneficiarios"<<endl;
};

//Metodos Sauto
void Sauto::d_sauto(){
    entrada_datos();
    Sleep(500);

    cout<<"Ingrese la marca del automovil: "<<endl;
    cin>>marca;
    system("cls");

    cout<<"Ingrese el modelo del automovil: "<<endl;
    cin>>modelo;
    system("cls");

    cout<<"Ingrese el año del automovil: "<<endl;
    cin>>a_auto;
    system("cls");

    cout<<"Ingrese el numero de su licencia: "<<endl;
    cin>>n_licencia;
    system("cls");

    Sleep(500);
    ed_dedu();
}

void Sauto::imp_sauto(){

    imprimir();

    cout<<"\nSu auto es un "<<marca<<" "<<modelo<<" del año "<<a_auto<<endl;
    cout<<"El numero de su licencia es: "<<n_licencia<<endl;

    imp_dedu();
}

//Metodos Scasa
void Scasa::datosScasa(){
    entrada_datos();
    Sleep(1000);
    a_actual=2023;

    cout<<"Ingrese el año en el que construyeron la casa (YYYY)"<<endl;
    cin>>a_construccion;
    system("cls");

    antiguedad= a_actual-a_construccion;

    cout<<"Su casa tiene dispositivos de seguridad?"<<endl;
    cin>>seguridad;

    ed_dedu();
}

void Scasa::mostrarScasa(){

    imprimir();
    cout<<"Su casa tiene "<<antiguedad<<" años de antiguedad"<<endl;
    cout<<"La casa "<<seguridad<<" cuenta con dispositivos de seguridad"<<endl;

    imp_dedu();
}

//Constructores Y Destructores
Seguro::Seguro(){

}

Seguro::~Seguro(){

}

Svida::Svida(){

}

Svida::~Svida(){

}

Sauto::Sauto(){

}

Sauto::~Sauto(){

}

Scasa::Scasa(){

}

Scasa::~Scasa(){

}

int main()
{
    setlocale(LC_CTYPE,"Spanish");
    Sleep(500);

    //Definir Objetos
    Sauto poliza_auto;
    Svida poliza_vida;
    Scasa poliza_casa;

    //Menu Principal
    int opcion;
    bool volverMenu = true;

    while (volverMenu) {
        system("cls");
        cout << "----  Bienvenido a GNP  ----" << endl;
        cout << "\n¿Que tipo de poliza desea registrar?" << endl; //Opciones del menu
        cout << "\n1. Poliza de vida" << endl;
        cout << "\n2. Poliza de automovil" << endl;
        cout << "\n3. Poliza de casa" << endl;
        cout<< "\n4. Imprimir Polizas Registradas" << endl;
        cin >>opcion;

        switch (opcion) {
            case 1:
                // Seguro De Vida
                system("cls");
                cout<<"Usted escogio la poliza de vida \n"<<endl;//Rellena datos
                Sleep(1000);
                poliza_vida.datosVida();
                break;

            case 2:
                // Seguro de Automovil
                system("cls");
                cout<<"Usted escogio la poliza de automovil \n"<<endl;//Rellena datos
                Sleep(1000);
                poliza_auto.d_sauto();
                break;
            case 3:
                // Seguro de Casa
                system("cls");
                cout<<"Usted escogio la poliza de casa \n"<<endl;//Rellena datos
                Sleep(1000);
                poliza_casa.datosScasa();
                break;
            case 4:
                //Imprimir Polizas
                system("cls");
                cout<<"Las polizas registradas son: \n"<<endl;//Imprime Datos
                cout<<"Poliza de Vida: \n"<<endl;
                Sleep(1000);
                poliza_vida.mostrarSvida();

                cout<<"\nPoliza de automovil: \n"<<endl;//Imprime Datos
                Sleep(1000);
                poliza_auto.imp_sauto();

                cout<<"\nPoliza de Casa: \n"<<endl;//Imprime Datos
                Sleep(1000);
                poliza_casa.mostrarScasa();
                break;
            ;
            default:
                cout << "Opcion no valida. \nSeleccione una opcion valida." << endl;
                system("cls");
                break;
        }

        char volver;
        cout<<"\n¿Desea volver al menu principal? (S/N) \n"<<endl;//Pregunta si regresar al menu
        cin >>volver;

        if (volver == 'N' || volver == 'n') {
            volverMenu = false;
        }
    }

    return 0;
}
