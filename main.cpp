#include <iostream>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <cstdio>
#include <conio.h>
#include <ctime>
#include "Comprobante.h"
#include "Fecha.h"
#include "Impuesto.h"
#include "MediosDePagos.h"
#include "OrdenDePago.h"
#include "PlanDeCuentas.h"
#include "Proveedor.h"
#include "rlutil.h"
#include "Funciones.h"

using namespace std;

using namespace rlutil;

int main()
{
    setlocale(LC_ALL, "Spanish");
    srand(time(NULL));
    int opcion;

    system("cls");

    do
    {
        cout << "------PAGO A PROVEEDORES--------"<< endl;
        cout << "---EMPECEMOS A PRACTICAR--------"<< endl;
        cout << "   1. MENU COMPROBANTE          "<< endl;
        cout << "   2. MENU PROVEEDOR            "<< endl;
        cout << "   3.                           "<< endl;
        cout << "   4.                           "<< endl;
        cout << "   0. SALIR                     "<< endl;
        cout << "--------------------------------"<< endl;
        cout << "OPCION: ";
        cin >> opcion;

        system("cls");

        switch(opcion)
        {
        case 1:menuComprobante();

        break;
        case 2:menuProveedor();
            break;
        case 3: ;
            //no tengo ninguna validacion todavia
            break;
        case 4:listarProveedores();
            break;

        }
        system("pause");
        system("cls");


    }
    while(opcion != 0);


    return 0;


}
