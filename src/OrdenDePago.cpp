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
void OrdenDePago::setEstadoOP(bool estado) {

    _estadoOP=estado;
}
int OrdenDePago::getIdOP() {

    return _idOP;
}
Fecha OrdenDePago::getFechaContabilizacion() {

    return _fechaContabilizacion;
}
int OrdenDePago::getTipoOP() {

    return _tipoOP;
}
int OrdenDePago::getIdProveedor() {

    return _idProveedor;
}

int OrdenDePago::getNumComp() {

    return _numComp;
}
float OrdenDePago::getRetIIBB() {

    return _retIIBB;
}
float OrdenDePago::getRetGanancias() {

    return _retGanancias;
}
float OrdenDePago::getImporteAPagar() {

    return _importeAPagar;
}
float OrdenDePago::getImporteTotal() {

    return _importeTotal;
}
bool OrdenDePago::getEstadoOP() {

    return _estadoOP;
}
void OrdenDePago::cargar(int tipo) {



}
void OrdenDePago::mostrar() {




}
bool OrdenDePago::leerDeDisco(int pos) {

    bool lectura;
    FILE *p;
    p = fopen("ordenesdepago.dat", "rb");
    if (p == NULL)
    {
        return false;
    }
    fseek(p, sizeof(OrdenDePago)*pos, SEEK_SET);
    lectura = fread(this, sizeof(OrdenDePago), 1, p);
    fclose(p);
    return lectura;
}
bool OrdenDePago::guardarEnDisco() {

    bool guardo;
    FILE *p;
    p = fopen("ordenesdepago.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    guardo = fwrite(this, sizeof(OrdenDePago), 1, p);
    fclose(p);
    return guardo;

}
void OrdenDePago::guardarEnDisco(int pos) {
    bool guardo;
    FILE *p;
    p = fopen("comprobantes.dat", "rb+");
    if (p == NULL){
        return;
    }
    fseek(p, sizeof(OrdenDePago)*pos, SEEK_SET);
    guardo = fwrite(this, sizeof(OrdenDePago), 1, p);
    fclose(p);
    return;;

}
void OrdenDePago::listarOrdenesDePago() {


}
void OrdenDePago::listarOrdenadoFechaConta() {


}
