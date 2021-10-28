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
#include "Reportes.h"


using namespace std;
using namespace rlutil;


void PlanDeCuentas::setCuentaContable(int cuenta)
{
    _cuentaContable=cuenta;
}
void PlanDeCuentas::setDescripcionCuenta(char* descCuenta )
{
    strcpy(_descripcionCuenta,descCuenta);
}
void PlanDeCuentas::setEstado(bool estado)
{
    _estado=estado;
}
int PlanDeCuentas::getCuentaContable()
{
    return _cuentaContable;
}
char *PlanDeCuentas::getDescripcionCuenta()
{
    return _descripcionCuenta;
}
bool PlanDeCuentas::getEstadoPlan()
{
    return _estado;
}
void PlanDeCuentas::cargar()
{
    int cuenta;
    char desc[30];

    cout<<"CUENTA CONTABLE"<<endl;
    cin>>cuenta;
    setCuentaContable(cuenta);

    cout<<"DESCRIPCION    "<<endl;
    cin>> desc;
    strcpy(_descripcionCuenta, desc);
    setEstado(true);
}
void PlanDeCuentas::mostrar()
{
    gotoxy(2,3);
    cout<< _cuentaContable;
    gotoxy(25,3);
    cout<<_descripcionCuenta;


}
bool PlanDeCuentas::guardarEnDisco()
{
    bool guardo;
    FILE *p;
    p = fopen("plandecuentas.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(PlanDeCuentas), 1, p);
    fclose(p);
    return guardo;
}
bool PlanDeCuentas::leerDeDisco(int pos)
{
    bool lectura;
    FILE *p;
    p = fopen("plandecuentas.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(PlanDeCuentas)*pos, SEEK_SET);
    lectura = fread(this, sizeof(PlanDeCuentas), 1, p);
    fclose(p);
    return lectura;
}


void PlanDeCuentas::listarPlanDeCuentas()
{
    PlanDeCuentas obj;
    gotoxy(2,2);
    cout<<"CODIGO CUENTA ";
    gotoxy(25,2);
    cout<<"DESCRIPCION CUENTA ";
    int pos=0;
    while(obj.leerDeDisco(pos)==true)
    {
        obj.mostrar();
        pos++;
    }
    cout<<endl;
}
