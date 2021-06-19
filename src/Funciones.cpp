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

bool sinRepetidos(int n, int vec[], int tam)
{

    for(int i=0; i<tam; i++)
    {
        if(n == vec[i])
        {
            return true;
        }
        return false;
    }

}



void rand_proveedores()
{
    int vecNum[5];
    int prov;

    prov = contarProveedores();


    int i,valor;

    for(i=0; i<5; i++)
    {
        valor=rand()%prov+1;
        while(sinRepetidos(valor,vecNum,5))
        {
            vecNum[i]=valor;
        }
    }

    for( int j=0; j<5; j++)
    {
        Proveedor reg;
        reg.leerDeDisco(vecNum[j]);
        cout<< vecNum[j] <<" - "<<reg.getRazonSocial()<<endl;
    }

}



void cargarComprobante()
{

    int tipoComp;
    Comprobante reg;
    cout << "Factura: 1  Nota de Crédito: 2"<< endl;
    cin>>tipoComp;
    system("cls");

    reg.cargar(tipoComp);

}


void cargarProveedor()
{
    Proveedor reg1;

    reg1.cargar();

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

bool soloNumeros(const char *cadena){
    int i=0;
    while(cadena[i] != '\0'){
        if(!(cadena[i] >= '0' && cadena[i] <= '9')){
            return false;
        }
        i++;
    }
    return true;
}
