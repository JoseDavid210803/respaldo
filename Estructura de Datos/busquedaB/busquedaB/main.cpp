#include <iostream>

using namespace std;

int busquedaB(int x[], int inicio, int fin, int bus)
{
    int mitad;
    if(inicio>fin)
        return -1;
    mitad=(inicio+fin)/2;
    if(bus==x[mitad])
        return mitad;
    if(bus<x[mitad])
        busquedaB(x,inicio, mitad-1,bus);
    if(bus>x[mitad])
        busquedaB(x,mitad+1,fin,bus);
}

int main(){

    int x[7]= {5,10,15,20,25,30,35};
    busquedaB(x,0,7,10);

}
