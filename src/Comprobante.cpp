#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Comprobante.h"
#include "Impuesto.h"
#include "PlanDeCuentas.h"
#include "Proveedor.h"

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

void Comprobante::setFechaContabilizacion(Fecha contabilizacion){

    _fechaContabilizacion = contabilizacion;
}

void Comprobante::setFechaFactura(Fecha factura){

    _fechaComp = factura;
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
char * Comprobante:: getLetra()
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

cout<<"LETRA"<<endl;
cout<<"FECHA CONTABILIZACIÓN"<<endl;
cout<<"FECHA COMPROBANTE"<<endl;
cout<<"PROVEEDOR"<<endl;
cout<<"PV"<<endl;
cout<<"NUMERO"<<endl;
cout<<"CUENTA CONTABLE"<<endl;
cout<<"CANTIDAD"<<endl;
cout<<"PRECIO"<<endl;
cout<<"TOTAL"<<endl;

cin.ignore();
cin.getline(_letra,1);

int dc,mc,ac,df,mf,af;

cin>> dc;
cin>> mc;
cin>> ac;

cin>> df;
cin>> mf;
cin>> af;

cin>> _idProveedor;

//cout>> getRazonSocial(_idProveedor)>> endl; VER COMO AGREGO EL NOMBRE DEL PROVEEDOR


}
void Comprobante::mostrar()
{

}
bool Comprobante::leerDeDisco()
{

}
bool Comprobante::guardarEnDisco()
{

}
void Comprobante:: guardarEnDisco(int)
{

}
