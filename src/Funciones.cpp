#include "Funciones.h"

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


using namespace std;

using namespace rlutil;

void marco_comprobante()
{
    setBackgroundColor(GREY);
    setColor(BLUE);
    int x;
    for(x=1; x<=80; x++)
    {
        setlocale(LC_ALL, "C");
        gotoxy(x,2);
        printf("\xdB");
    }
}

int contarProveedores()
{
    int bytes, cr;
    FILE *p;
    p = fopen("proveedores.dat", "rb");
    if (p == NULL)
    {
        return 0;
    }
    fseek(p, 0, SEEK_END);
    bytes = ftell(p);
    cr = bytes / sizeof(Proveedor);
    fclose(p);
    return cr;
}

int  buscarPosProveedor(int idProveedor)
{
    Proveedor reg;
    int i = 0;
    while(reg.leerDeDisco(i))
    {
        if ( idProveedor == reg.getIdProveedor())
        {
            return i;
        }
        i++;
    }
    return -1;

}

bool buscarProveedor(int idProveedor)
{
    Proveedor reg;
    int i = 0;
    while(reg.leerDeDisco(i))
    {
        if ( idProveedor == reg.getIdProveedor())
        {
            return true;
        }
        i++;
    }
    return false;
}


void buscarNombProveedor(int idProveedor)
{
    Proveedor reg;

    int pos;

    pos=buscarPosProveedor(idProveedor);

    reg.leerDeDisco(pos);

    cout<<reg.getRazonSocial()<<endl;

}


bool sinRepetidos(int n, int vec[])
{

    for(int i=0; i<5; i++)
    {
        if(n == vec[i])
        {
            return true;
        }

    }
    return false;
}



void rand_proveedores()
{

    int vecNum[5]= {};

    int prov;

    prov = contarProveedores();

    int i=0;
    int valor;

    while(i<5)
    {

        valor=rand()%prov+1;
        while(sinRepetidos(valor,vecNum)==false)
        {
            vecNum[i]=valor;
            i++;
        }

    }

    for(int j=0; j<5; j++)
    {
        Proveedor reg;

        int pos;

        pos=buscarPosProveedor(vecNum[j]);

        reg.leerDeDisco(pos);

        cout<<vecNum[j]<<"-"<< reg.getRazonSocial()<<endl;

    }

}


void listarProveedores()
{
    int i=0;
    Proveedor reg;

    while(reg.leerDeDisco(i))
    {
        reg.mostrar();
        cout << endl;
        i++;
    }

}

bool soloNumeros(const char *cadena)
{
    int i=0;
    while(cadena[i] != '\0')
    {
        if(!(cadena[i] >= '0' && cadena[i] <= '9'))
        {
            return false;
        }
        i++;
    }
    return true;
}



float buscarAlicuota(int idProveedor)
{

    Proveedor reg;

    int pos;

    int ali;

    pos=buscarPosProveedor(idProveedor);


    while(reg.leerDeDisco(pos))
    {


        int  ali=reg.getIVA();

        if(ali=1)
        {
            return 21;
        }
        if(ali=2)
        {
            return 10.5;
        }
        if(ali=3)
        {
            return 0;
        }

    }
    return -1;
}

void menuComprobante()
{
    Comprobante reg;
    int opc;
    while(true)
    {
        system("cls");
        cout << "-----MENU COMPROBANTES-----" << endl;
        cout << "---------------------------" << endl;
        cout << "1. ALTA COMPROBANTE"         << endl;
        cout << "2. BAJA COMPROBANTE"         << endl;
        cout << "3. LISTAR COMPROBANTES"      << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << "- SELECCIONE UNA OPCION: - " << endl;
        cout << "---------------------------" << endl;
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            int tipoComp;
            cout << "Factura: 1  Nota de Crédito: 2"<< endl;
            cin>>tipoComp;
            system("cls");
            reg.cargar(tipoComp);
            if(reg.getEstado()==true)
            {
                if(reg.guardarEnDisco()==true)
                {
                    cout<<"REGISTRO GRABADO EN EL ARCHIVO"<<endl;
                }
                else
                {
                    cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
                }
            }
            else
            {
                cout<<"ERROR DE DATOS"<<endl;
            }
            system("pause");
            break;
        case 2:
        //BAJA COMPROBANTE;
        case 3:
            listarComprobantes();
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
    }

}
void menuProveedor()
{
    Proveedor reg1;
    int opc;
    while(true)
    {
        system("cls");
        cout << "-----MENU PROVEEDOR--------" << endl;
        cout << "---------------------------" << endl;
        cout << "1. ALTA PROVEEDOR          " << endl;
        cout << "2. BAJA PROVEEDOR          " << endl;
        cout << "3. LISTAR PROVEDORES       " << endl;
        cout << "0. VOLVER AL MENU PRINCIPAL" << endl;
        cout << "- SELECCIONE UNA OPCION: - " << endl;
        cout << "---------------------------" << endl;
        cin>>opc;
        system("cls");
        switch(opc)
        {
        case 1:
            reg1.cargar();
            if(reg1.getEstadoProv()==true)
            {
                if(reg1.guardarEnDisco()==true)
                {
                    cout<<"REGISTRO GRABADO EN EL ARCHIVO"<<endl;
                }
                else
                {
                    cout<<"NO SE PUDO GRABAR EL REGISTRO"<<endl;
                }
            }
            else
            {
                cout<<"ERROR DE DATOS"<<endl;
            }
            system("pause");
            break;
        case 2:
        //BAJA PROVEEDOR;
        case 3:
            listarProveedores();
            system("pause");
            break;
        case 0:
            return;
            break;
        default:
            cout<<" OPCION INCORRECTA"<<endl;
            break;
        }
    }

}






