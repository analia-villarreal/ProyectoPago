#include "PlanDeCuentas.h"
#include "Impuesto.h"
#include "Proveedor.h"
#include "rlutil.h"
#include "Funciones.h"

#include <conio.h>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>



using namespace std;
using namespace rlutil;


PlanDeCuentas::PlanDeCuentas()
{
    //ctor
}


void PlanDeCuentas::setCuentaContable(int cuenta)
{
    _cuentaContable=cuenta;
}
void PlanDeCuentas::setDescripcionCuenta(char* descCuenta )
{
    strcpy(_descripcionCuenta,descCuenta);
}
int PlanDeCuentas::getCuentaContable()
{
    return _cuentaContable;
}
char *PlanDeCuentas::getDescripcionCuenta()
{
    return _descripcionCuenta;
}
void PlanDeCuentas::cargar()
{
    int cuenta;
    char desc[30];

    cout<<"CUENTA CONTABLE"<<endl;
    cin>>cuenta;
    cout<<"DESCRIPCION"<<endl;
    strcpy(_descripcionCuenta, desc);
}
void PlanDeCuentas::mostrar()
{

}
bool PlanDeCuentas::guardarEnDisco()
{

}
bool PlanDeCuentas::leerEnDisco()
{

}
