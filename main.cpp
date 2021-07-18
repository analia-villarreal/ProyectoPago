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
    setColor(WHITE);
    setlocale(LC_ALL, "Spanish");
    srand(time(NULL));
    int opcion;

    system("cls");

    do
    {
        gotoxy(40,5);cout << "----PAGO A PROVEEDORES--------"<< endl;
        gotoxy(40,6);cout << "--EMPECEMOS A PRACTICAR--------"<< endl;
        gotoxy(40,7);cout << "1. MENU COMPROBANTE          "<< endl;
        gotoxy(40,8);cout << "2. MENU PROVEEDOR            "<< endl;
        gotoxy(40,9);cout << "3. MENU PLAN DE CUENTAS      "<< endl;
        gotoxy(40,10);cout <<"4. MENU LISTADOS Y CONSULTAS "<< endl;
        gotoxy(40,11);cout <<"0. FIN DEL PROGRAMA          "<< endl;
        gotoxy(40,12);cout <<"- SELECCIONE UNA OPCION: -   "<< endl;
        gotoxy(40,13);cout <<"-------------------------------"<< endl;
        gotoxy(40,14);cout<<"   > ";cin>>opcion;


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
