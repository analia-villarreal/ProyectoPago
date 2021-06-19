#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <clocale>
#include <cstdio>

#include "Comprobante.h"
#include "Impuesto.h"
#include "PlanDeCuentas.h"
#include "Proveedor.h"
#include "Funciones.h"
#include "rlutil.h"

using namespace std;
using namespace rlutil;



Comprobante::Comprobante()
{

}

void Comprobante::setIdComp(int idComp)
{
    _idComp=idComp;
}
void Comprobante::setLetra(char* letra)
{
    strcpy(_letra,letra);
}

void Comprobante::setFechaContabilizacion(Fecha contabilizacion)
{
    _fechaContabilizacion=contabilizacion;
}

void Comprobante::setFechaFactura(Fecha factura)
{
    _fechaComp=factura;
}

void Comprobante::setTipo(int tipo)
{
   _tipo=tipo;
}

void Comprobante::setPv(int pv)
{

    if(pv<9999)
    {
        _pv=pv;
    }

}
void Comprobante::setNumFac(int numFac)
{
   if(numFac<99999999)
    {
        _numFac=numFac;
    }

}
void Comprobante::setCuentaContable(int cuenta)
{
    _cuentaContable=cuenta;
}
void Comprobante::setCantidad(int cant)
{
    _cantidad=cant;
}
void Comprobante::setPU(float pu)
{
    _PU=pu;
}
void Comprobante::setImporteTotal(float importe)
{
    _importeTotal=importe;
}
void Comprobante::setEstado(bool estado)
{
    _estado=estado;
}
int Comprobante::getIdComp()
{
    return _idComp;
}
char * Comprobante::getLetra()
{
    return _letra;
}

Fecha Comprobante::getFechaContabilizacion()
{
    return _fechaContabilizacion;
}

Fecha Comprobante::getFechaFactura()
{
    return _fechaComp;
}
int Comprobante::getTipo()
{
    return _tipo;
}

int Comprobante::getIdProveedor()
{
    return _idProveedor;
}
int Comprobante::getPV()
{
    return _pv;
}
int Comprobante::getNumFac()
{
    return _numFac;
}
int Comprobante::getCuentaContable()
{
    return _cuentaContable;
}
int Comprobante::getCantidad()
{
    return _cantidad;
}
float Comprobante::getPU()
{
    return _PU;
}
float Comprobante::getImporteTotal()
{
    return _importeTotal;
}
bool Comprobante::getEstado()
{
    return _estado;
}
void Comprobante::cargar(int tipo)
{
    setlocale(LC_ALL, "Spanish");
    int x;

    setTipo(tipo);

    if(getTipo()==1){
        cout<<"ESTA CARGANDO UNA FACTURA" <<endl;
    }
    if(getTipo()==2){
        cout<<"ESTA CARGANDO UNA NOTA DE CREDITO"<<endl;
    }
    //marco_comprobante();

   gotoxy(1,4);
   cout<<"FECHA CONTABILIZACI�N"<<endl;
    _fechaContabilizacion.cargar();

    cout<<"FECHA COMPROBANTE"<<endl;
    _fechaComp.cargar();
    cout<<"PROVEEDOR"<<endl;

    rand_proveedores();

    // llamar a la funcion randomProveedor() --> Mostrar un random de 5 proveedores con su categoria

    cin>> _idProveedor;

    cout<<buscarProveedor(_idProveedor)<<endl;

    cout<<"LETRA"<<endl;
    cin.ignore();
    cin.getline(_letra,1);
    // Mostrar opciones
    cout<<"PV"<<endl;
    cin>> _pv;
    cout<<"NUMERO"<<endl;
    cin>> _numFac;
    //cuenta contable del proveedor
    cout<<"CUENTA CONTABLE"<<endl;
    cout<<"CANTIDAD"<<endl;
    cin >> _cantidad;
    cout<<"PRECIO"<<endl;
    cin >> _PU;
    cout<<"IVA"<<endl;
//    cin >> _IVA;
    _importeTotal=_pv*_cantidad;
    cout<<"TOTAL"<< _importeTotal<< endl;

    guardarEnDisco();

    if(guardarEnDisco()==true){
        cout<<"Se guard� la factura correctamente"<< _importeTotal<< endl;
        //menuErrores();
    }




}
void Comprobante::mostrar()
{

    //cout<< "FECHA CONTABILIZACI�N" << _fechaContabilizacion <<endl;
    //cout<< "FECHA COMPROBANTE" << _fechaFactura <<endl;
    //cout<< "CODIGO PROVEEDOR" << getIdProveedor() <<endl;
    //cout<< "NOMBRE PROVEEDOR" << getRazonSocial() <<endl;
    cout<< "TIPO"<< _tipo <<endl;
    cout<< "COMPROBANTE" <<_letra << "-" << _pv << "-" << _numFac <<endl;
    cout<< "CUENTA CONTABLE" << _cuentaContable <<endl;
    cout<< "IMPORTE NETO" <<endl;
//    cout<< "TASA IVA" << getIva() <<endl;
    cout<< "TOTAL" << _importeTotal <<endl;

}

bool Comprobante::guardarEnDisco()
{
    bool guardo;
    FILE *p;
    p = fopen("comprobantes.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(Comprobante), 1, p);
    fclose(p);
    return guardo;
}
bool Comprobante::leerDeDisco()
{
    bool lectura;
    FILE *p;
    p = fopen("comprobantes.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(Comprobante), SEEK_SET);
    lectura = fread(this, sizeof(Comprobante), 1, p);
    fclose(p);
    return lectura;
}

void Comprobante::guardarEnDisco(int pos)
{

    bool guardo;
    FILE *p;
    p = fopen("comprobantes.dat", "rb+");
    if (p == NULL){
        return;
    }
    fseek(p, sizeof(Comprobante)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Comprobante), 1, p);
    fclose(p);
    return;
}

