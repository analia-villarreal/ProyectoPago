#include <iostream>
#include <cstring>
#include <cstdlib>
#include <clocale>
#include <cstdio>
#include <conio.h>
#include <ctime>
#include <iomanip>

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
void PlanDeCuentas::setDescripcionCuenta(const char* descCuenta)
{
    strcpy(_descripcionCuenta,descCuenta);
}
void PlanDeCuentas::setEstadoPlan(bool estado)
{
    _estado=estado;
}
int PlanDeCuentas::getCuentaContable()
{
    return _cuentaContable;
}
const char *PlanDeCuentas::getDescripcionCuenta()
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
    setEstadoPlan(true);
}
void PlanDeCuentas::mostrar()
{
    cout << left;
    cout<< setw(16) << _cuentaContable;
    cout<< setw(20) <<_descripcionCuenta;
    cout<<endl;


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
    cout << left;
    cout<< setw(16) <<"CODIGO CUENTA ";
    cout<< setw(20) <<"DESCRIPCION CUENTA ";
    cout<<endl;
    int pos=0;
    while(leerDeDisco(pos)==true)
    {
        mostrar();
        pos++;
    }
    cout<<endl;
}
