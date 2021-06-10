#ifndef PROVEEDOR_H
#define PROVEEDOR_H

#include "Impuesto.h"

class Proveedor
{

    private:
        int _idProveedor;
        char _razonSocial[45];
        int _CUIT;
        int _juridiccion;
        char _nombJuridiccion[20];
        char _tipoReg[2];
       Impuesto _retIIBB;
       Impuesto _retGanancias;
       Impuesto _IVA;

    public:
        Proveedor();
        void setIdProveedor(int);
        void setRazonSocial(char*);
        void setCUIT(int);
        void setJuridiccion(int);
        void setNombJu(char*);
        Impuesto setRetIIBB(float);
        Impuesto setRetGanancias(float);
        Impuesto setIVA();
        int getIdProveedor();
        char * getRazonSocial();
        int getCUIT();
        int getJuridiccion();
        char * getNombJur();
        Impuesto getRetIIBB(Impuesto);
        Impuesto getRetGanancias(Impuesto);
        Impuesto getIVA(Impuesto);
        void cargar();
        void mostrar();
        bool guardarEnDisco();
        void guardarEnDisco(int);
        bool leerEnDisco();

};

#endif // PROVEEDOR_H
