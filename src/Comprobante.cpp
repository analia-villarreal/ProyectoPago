#include "Comprobante.h"

Comprobante::Comprobante()
{
    //ctor
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
