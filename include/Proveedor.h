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
       Impuesto _retIIBB;
       Impuesto _retGanancias;
       Impuesto _IVA;

    public:
        Proveedor();
        void setId(int);
        void setRazonSocial(char*);
        void setCUIT();
        void setJuridiccion();
        Impuesto setRetIIBB(float);
        Impuesto setRetGanancias(float));
        Impuesto setIVA();
        int getId();
        char * getRazonSocial(char);
        int getCUIT();
        int getJuridiccion();
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
