#include "Proveedor.h"
#include "Impuesto.h"

#include <iostream>
#include <cstring>
#include <cstdlib>


using namespace std;


Proveedor::Proveedor()
{
    //ctor
}

void Proveedor::setIdProveedor(int idProv)
{
    _idProveedor=idProv;
}
void Proveedor::setRazonSocial(char* razon)
{
    strcpy(_razonSocial,razon);
}
void Proveedor::setCUIT(int cuit)
{
    _CUIT=cuit;
}
void Proveedor::setJuridiccion(int jur)
{
    _juridiccion=jur;
}
void Proveedor::setNombJu(char* nombJur)
{
    strcpy(_nombJuridiccion,nombJur);
}
void Proveedor::setTipoRe(char* tipo)
{
   strcpy(_tipoReg,tipo);
}
void Proveedor::setRetIIBB(Impuesto retIIBB)
{
    _retIIBB=retIIBB;
}


void Proveedor::setRetGanancias(Impuesto retGanancias)
{
    _retGanancias=retGanancias;
}
void Proveedor::setIVA(Impuesto iva)
{
    _IVA=iva;
}
int Proveedor::getIdProveedor()
{
    return _idProveedor;
}
char * Proveedor::getRazonSocial()
{
    return _nombJuridiccion;
}
int Proveedor::getCUIT()
{
    return _CUIT;
}
int Proveedor::getJuridiccion()
{
    return _juridiccion;
}
char * Proveedor::getNombJur()
{
    return _nombJuridiccion;
}
Impuesto Proveedor::getRetIIBB()
{
    return _retIIBB;
}
Impuesto Proveedor::getRetGanancias()
{
    return _retGanancias;
}
Impuesto Proveedor::getIVA(Impuesto)
{
    return _IVA;
}
void Proveedor::cargar()
{

}
void Proveedor::mostrar()
{


}
bool Proveedor::guardarEnDisco(){

}
void Proveedor::guardarEnDisco(int){

}
bool Proveedor::leerEnDisco(){

}
