#include <iostream>
#include <cstring>
#include <cstdlib>
#include "Comprobante.h"
#include "Fecha.h"
#include "Impuesto.h"
#include "PlanDeCuentas.h"

using namespace std;

Comprobante::Comprobante(int tipoComp)
{

    _tipo=tipoComp;

}

void Comprobante::setIdComp(int idComp)
{

    _idComp=idComp;
}
void Comprobante::setLetra(char* letra)
{

    strcpy(_letra,letra);
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
int Comprobante::idProveedor()
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

    return _pu;
}
float Comprobante::getImporteTotal()
{

    return _importeTotal;
}
bool Comprobante::getEstado()
{

    return _estado;

}
void Comprobante::cargar()
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

<<"ESTA CARGANDO UNA"<< _tipo <<endl;

cout<<"LETRA"<<endl;
cout<<"FECHA CONTABILIZACIÓN"<<endl;
cout<<"
cout<<"
cout<<"
cout<<"
cout<<"
cout<<"
cout<<"



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
