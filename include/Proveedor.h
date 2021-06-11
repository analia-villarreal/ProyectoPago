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
        void setTipoRe(char*);
        void setRetIIBB(Impuesto);
        void setRetGanancias(Impuesto);
        void setIVA(Impuesto);
        int getIdProveedor();
        char * getRazonSocial();
        int getCUIT();
        int getJuridiccion();
        char * getNombJur();
        Impuesto getRetIIBB();
        Impuesto getRetGanancias();
        Impuesto getIVA();
        void cargar();
        void mostrar();
        bool guardarEnDisco();
        void guardarEnDisco(int);
        bool leerEnDisco();

};

#endif // PROVEEDOR_H
