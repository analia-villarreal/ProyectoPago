#ifndef COMPROBANTE_H
#define COMPROBANTE_H

#include "Fecha.h"
#include "Impuesto.h"
#include "Proveedor.h"

class Comprobante
{
    private:
        int _idComp;
        char _letra[1];
        Fecha _fechaContabilizacion;
        Fecha _fechaComp;
        int _tipo;
        int _idProveedor;
        int _pv;
        int _numFac;
        int _cuentaContable;
        int _cantidad;
        float _PU;
        float _IVA;
        float _importeTotal;
        bool _estado;
    public:
        Comprobante();
        void setIdComp(int);
        void setLetra(char*);
        void setFechaContabilizacion(Fecha);
        void setFechaFactura(Fecha);
        void setFecha(Fecha);
        void setTipo(int);
        void setPv(int);
        void setNumFac(int);
        void setCuentaContable(int);
        void setCantidad(int);
        void setPU(float);
        void setIVA(float);
        void setImporteTotal(float);
        void setEstado(bool);
        int getIdComp();
        char * getLetra();
        Fecha getFechaContabilizacion();
        Fecha getFechaFactura();
        int getTipo();
        int getIdProveedor();
        Proveedor getRazonSocial(int);
        int getPV();
        int getNumFac();
        int getCuentaContable();
        int getCantidad();
        float getPU();
        float getIVA();
        float getImporteTotal();
        bool getEstado();
        void cargar(int);
        void mostrar();
        bool leerDeDisco(int);
        bool guardarEnDisco();
        void guardarEnDisco(int);


};

#endif // COMPROBANTE_H
