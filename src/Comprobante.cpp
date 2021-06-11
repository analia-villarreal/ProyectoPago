#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Comprobante.h"
#include "Impuesto.h"
#include "PlanDeCuentas.h"
#include "Proveedor.h"
#include "Funciones.h"

using namespace std;

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
    _numFac=numFac;
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

    //  int _idComp;
    //  char letra[1];
    //  Fecha fechaContabilizacion;
    //  Fecha fechaComp;
    //  int _idProveedor;
    //  int _pv;
    //  int _numFac;
    //  int _cuentaContable;
    //  int _cantidad;
    //  float _PU;
    //  Impuesto IVA;
    //  float _importeTotal;
    //  bool _estado;

    setTipo(tipo);

    cout<<"ESTA CARGANDO UNA"<< getTipo() <<endl;
    cout<<"FECHA CONTABILIZACIÓN"<<endl;
    _fechaContabilizacion.cargar();

    cout<<"FECHA COMPROBANTE"<<endl;
    _fechaComp.cargar();
    cout<<"PROVEEDOR"<<endl;

    // llamar a la funcion randomProveedor() --> Mostrar un random de 5 proveedores con su categoria

    cout<<"LETRA"<<endl;
    // Mostrar opciones
    cout<<"PV"<<endl;
    cout<<"NUMERO"<<endl;
    //
    cout<<"CUENTA CONTABLE"<<endl;
    cout<<"CANTIDAD"<<endl;
    cout<<"PRECIO"<<endl;
    cout<<"TOTAL"<<endl;


    cin>> _idProveedor;

    cin.ignore();
    cin.getline(_letra,1);

//cout>> getRazonSocial(_idProveedor)>> endl; VER COMO AGREGO EL NOMBRE DEL PROVEEDOR


}
/*void Comprobante::mostrar()
{

    cout << "FECHA CONTABILIZACIÓN" << _fechaContabilizacion <<endl;
    cout << "FECHA COMPROBANTE" << _fechaFactura <<endl;
    cout<< "CODIGO PROVEEDOR" << getIdProveedor() <<endl;
    cout<< "NOMBRE PROVEEDOR" << getRazonSocial() <<endl;
    cout<< "TIPO"<< _tipo <<endl;
    cout<< "COMPROBANTE" <<_letra << "-" << _pv << "-" << _numFac <<endl;
    cout<< "CUENTA CONTABLE" << _cuentaContable <<endl;
    cout<< "IMPORTE NETO" <<endl;
    cout<< "TASA IVA" << getIva() <<endl;
    cout<< "TOTAL" << _importeTotal <<endl;

}

*/
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

/*void Comprobante::guardarEnDisco(int pos)
{

    bool guardo;
    FILE *p;
    p = fopen("comprobantes.dat", "rb+");
    if (p == NULL){
        return -1;
    }
    fseek(p, sizeof(Comprobante)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(Comprobante), 1, p);
    fclose(p);
    return guardo;
}
*/
