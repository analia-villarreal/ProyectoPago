#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Comprobante.h"
#include "Fecha.h"
#include "Impuesto.h"
#include "MediosDePagos.h"
#include "OrdenDePago.h"
#include "PlanDeCuentas.h"
#include "rlutil.h"

using namespace std;

using namespace rlutil;

int main()
{
    setlocale(LL_ALL; "Spanish");
    int opcion;


    Comprobante obj(decision);

    system("cls");

    do
    {
        cout << "------PAGO A PROVEEDORES--------"<< endl;
        cout << "---EMPECEMOS A PRACTICAR--------"<< endl;
        cout << "   1. CARGAR COMPROBANTE  "<< endl;
        cout << "   2.   "<< endl;
        cout << "   3.   "<< endl;
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
            Comprobante obj(tipoComp);
            cout << "Factura: 1  Nota de Crédito: 2"<< endl;
            int tipoComp;
            cin>>tipoComp;
            break;
        case 2:
            int agua;
            cout << "CANTIDAD DE AGUA A LLENAR: ";
            cin >> agua;
            obj.llenar(agua);
            break;
        case 3:
            obj.vaciar();
            break;
        case 5:
            obj.apagar();
            break;





        }
        system("pause");
        system("cls");


    }
    while(opcion != 0);




    return 0;


}
