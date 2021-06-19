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
        cout << "   1. CARGAR COMPROBANTE        "<< endl;
        cout << "   2.                           "<< endl;
        cout << "   3. CREAR PROVEEDOR           "<< endl;
        cout << "   4. LISTAR PROVEEDORES        "<< endl;
        cout << "   5.                           "<< endl;
        cout << "   0. SALIR                     "<< endl;
        cout << "--------------------------------"<< endl;
        cout << "OPCION: ";
        cin >> opcion;

        system("cls");

        switch(opcion)
        {
        case 1:cargarComprobante();

        break;
        case 2:
            break;
        case 3: cargarProveedor();
            //no tengo ninguna validacion todavia
            break;
        case 4:listarProveedores();
            break;
        case 5:
            break;

        }
        system("pause");
        system("cls");


    }
    while(opcion != 0);


    return 0;


}
