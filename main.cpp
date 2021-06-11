#include <iostream>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <cstdio>
#include "Comprobante.h"
#include "Fecha.h"
#include "Impuesto.h"
#include "MediosDePagos.h"
#include "OrdenDePago.h"
#include "PlanDeCuentas.h"
#include "Proveedor.h"
#include "rlutil.h"

using namespace std;

using namespace rlutil;

int main()
{
    setlocale(LC_ALL, "Spanish");

    int opcion;

    system("cls");

    do
    {
        cout << "------PAGO A PROVEEDORES--------"<< endl;
        cout << "---EMPECEMOS A PRACTICAR--------"<< endl;
        cout << "   1. CARGAR COMPROBANTE  "<< endl;
        cout << "   2. PAGAR OP  "<< endl;
        cout << "   3. CREAR    "<< endl;
        cout << "   4.   "<< endl;
        cout << "   5.   "<< endl;
        cout << "   0. SALIR                "<< endl;
        cout << "---------------------------"<< endl;
        cout << "OPCION: ";
        cin >> opcion;

        system("cls");

        switch(opcion)
        {
        case 1:
        {
            int tipoComp;
            Comprobante reg;
            cout << "Factura: 1  Nota de Crédito: 2"<< endl;
            cin>>tipoComp;
            reg.cargar(tipoComp);
        }
        break;
        case 2:
            break;
        case 3:
            break;
        case 4:
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
