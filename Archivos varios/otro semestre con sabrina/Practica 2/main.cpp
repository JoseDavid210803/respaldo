#include <iostream>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <clocale>
using namespace std;

int menu();
int ciclo();

class Registro{
protected:
    string nombre;
    int codigo;
public:
    Registro();
    ~Registro();

};
class Profesor:Registro{
protected:
        int anioTrab, numGrupos;
        float sueldoProfe;
public:
    void sueldo(int horasT);
    void leerDatos();
    void imprimirDatos();
    int horasTrab();
    Profesor();
    ~Profesor();
};

class Alumno:Registro{
protected:
    int semestre, numCalif;
    float calificacion, promedio;
public:
    void calif();
    void leer();
    void imprimir();
    Alumno();
    ~Alumno();
};
void Profesor::leerDatos(){
    cout<<"Ingrese su nombre: ";
    cin>>nombre;
    system("cls");
    cout<<"ingrese su codigo escolar: ";
    cin>>codigo;
    system("cls");
    cout<<"ingrese sus años de antiguedad trabajando: ";
    cin>>anioTrab;
    system("cls");
    cout<<"ingrese la cantidad de grupos que tiene a cargo: ";
    cin>>numGrupos;
}

int Profesor::horasTrab(){
    int horasT;
    horasT = numGrupos*4;
    cout<<horasT;
    return horasT;

}

void Profesor::sueldo(int horasT){
    float pagoHora;
    if(anioTrab < 10){
        pagoHora = 95;
        sueldoProfe = pagoHora*horasT;
    }
    else if(anioTrab > 10){
        pagoHora = 120;
        sueldoProfe = pagoHora*horasT;
    }
    else if(anioTrab >= 20){
        pagoHora = 210;
        sueldoProfe = pagoHora*horasT;
    }

}
void Profesor::imprimirDatos(){
    system("cls");
    cout<<"nombre: "<<nombre<<endl;
    cout<<"codigo: "<<codigo<<endl;
    cout<<"años de antiguedad: "<<anioTrab<< " años"<<endl;
    cout<<"cantidad de grupos a cargo: "<<numGrupos<<endl;
    cout<<"sueldo a la quincena: "<<sueldoProfe<<endl;
}

void Alumno::leer(){
    cout<<"Ingrese su nombre: ";
    cin>>nombre;
    system("cls");
    cout<<"ingrese su codigo escolar: ";
    cin>>codigo;
    system("cls");
    cout<<"ingrese su semestre: ";
    cin>>semestre;
    system("cls");
    cout<<"ingrese la cantidad de materias que esta cursando: ";
    cin>>numCalif;
}
void Alumno::calif(){
    for (int i = 0; i < numCalif; i++){
        system("cls");
        cout<<"ingrese la calificacion "<<i+1<<": ";
        cin>>calificacion;
        promedio = promedio+calificacion;
    }
    promedio = promedio/numCalif;
}

void Alumno::imprimir(){
    system("cls");
    cout<<"nombre: "<<nombre<<endl;
    cout<<"codigo: "<<codigo<<endl;
    cout<<"semestre: "<<semestre<<endl;
    cout<<"Numero de materias: "<<numCalif<<endl;
    cout<<"Promedio"<<promedio<<endl;
    cout<<"\n\nPresione ENTER para continuar";
    getch();
}
Alumno::Alumno(){
    semestre = 0;
    numCalif = 0;
    promedio = 0;
    calificacion = 0;
};
Alumno::~Alumno(){};

Profesor::Profesor(){
    anioTrab = 0;
    numGrupos = 0;
    sueldoProfe = 0;
};
Profesor::~Profesor(){};

Registro::Registro(){};
Registro::~Registro(){};


int ciclo(){
    int op;
    cout<<"\n¿Desea volver al menu?\n"<<endl;
    cout<<"[1] Si"<<endl;
	cout<<"[0] No"<<endl;
	cout<<"\n-> ";
	cin>>op;
	if(op == 1){
        system("cls");
        cout<<"regresando al menu";
        Sleep(600);
        return 0;
	}
    else{
        system("cls");
        cout<<"Gracias por usar el programa :)";
        getch();
        return 1;
    }

}
int menu(){
    int op;
    int c = 0;
    do{
        system("cls");
		cout<<"Ingrese el numero de la opcion que desea ejecutar:"<<endl;
		cout<<"[1] Ingresar la informacion de profesor."<<endl;
		cout<<"[2] Ingresar la informacion de Alumno."<<endl;
		cout<<"[0] Salir del programa."<<endl;
		cout<<"-> ";
		cin>>op;
		if (op == 1){
            system("cls");
            Profesor prof;
            prof.leerDatos();
            prof.sueldo(prof.horasTrab());
            prof.imprimirDatos();
            c = ciclo();
            getch();
		}
        else if(op == 2){
            system("cls");
            Alumno alum;
            alum.leer();
            alum.calif();
            alum.imprimir();
            c = ciclo();
        }
        else{
            system("cls");
            cout<<"Gracias por usar el programa :)";
            c = 1;
            getch();
        }
    }
    while(c == 0);
}


int main(){
    setlocale(LC_ALL,"");
    menu();
}
