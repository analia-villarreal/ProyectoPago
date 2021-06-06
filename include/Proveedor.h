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
       // Impuesto _retIIBB;
       // Impuesto _retGanancias;

    public:
        Proveedor();
        void setId(int);
        void setRazonSocial(char*);
        void setCUIT();
        void setJuridiccion();
        int getId();
        char * getRazonSocial(char);
        int getCUIT();
        int getJuridiccion();
        void cargar();
        void mostrar();
        bool guardarEnDisco();
        void guardarEnDisco(int);
        bool leerEnDisco();

};

#endif // PROVEEDOR_H
