#include "OrdenDePago.h"
#include "Impuesto.h"
#include "Proveedor.h"
#include "PlanDeCuentas.h"
#include "rlutil.h"
#include "Funciones.h"

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <clocale>
#include <cstdio>

using namespace std;

using namespace rlutil;

OrdenDePago::OrdenDePago()
{
    //ctor
}

void OrdenDePago::setIdOP(int idOP) {

    _idOP=idOP;
}
void OrdenDePago::setFechaContabilizacion(Fecha conta) {

    _fechaContabilizacion=conta;
}
void OrdenDePago::setTipoOP(int tipo) {

    _tipoOP=tipo;
}
void OrdenDePago::setRetIIBB(float retiibb) {

    _retIIBB=retiibb;
}
void OrdenDePago::setRetGanancias(float retGanan) {

    _retGanancias=retGanan;
}
void OrdenDePago::setImporteAPagar(float importe)  {

    _importeAPagar=importe;
}
void OrdenDePago::setImporteTotal(float importeTotal) {

    _importeTotal=importeTotal;
}
void OrdenDePago::setFormaDePago(MediosDePagos formaPago) {

    _formDePago=formaPago;
}
bool OrdenDePago::setEstadoOP(int estado) {


}
int OrdenDePago::getIdOP() {}
Fecha OrdenDePago::getFechaContabilizacion() {}
int OrdenDePago::getTipoOP() {}
int OrdenDePago::getIdProveedor() {}
Proveedor OrdenDePago::getRazonSocial(int) {}
int OrdenDePago::getNumComp() {}
float OrdenDePago::getRetIIBB() {}
float OrdenDePago::getRetGanancias() {}
float OrdenDePago::getImporteAPagar() {}
float OrdenDePago::getImporteTotal() {}
int OrdenDePago::getEstado() {}
void OrdenDePago::cargar(int) {}
void OrdenDePago::mostrar() {}
bool OrdenDePago::leerDeDisco(int) {}
bool OrdenDePago::guardarEnDisco() {}
void OrdenDePago::guardarEnDisco(int) {}
void OrdenDePago::listarOrdenesDePago() {}
void OrdenDePago::listarOrdenadoFechaConta() {}
