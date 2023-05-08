#include <iostream>
#include "lista_s.h"

using namespace std;

int main()
{
	lista_s <int> lista;
	lista.push_b(3);
	lista.push_b(6);
	lista.push_p(5,1);
	lista_s <int> lista2{lista};
	cout << "Hello world!" << endl;
    return 0;
}
