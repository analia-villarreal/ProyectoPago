#ifndef COMPROBANTE_H
#define COMPROBANTE_H


class Comprobante
{
    private:
        int _idComp;
        char letra[1];
        Fecha fechaContabilizacion;
        Fecha fechaComp;
        int _idProveedor;
        int _pv;
        int _numFac;
        int _cuentaContable;
        int _cantidad;
        float _PU;
        Impuesto IVA;
        float _importeTotal;
        bool _estado;
    public:
        Comprobante();
        void setIdComp(int);
        void setLetra(int);
        void setFecha(Fecha);
        void setPv(int);
        void setNumFac(int);
        void setCuentaContable(int);
        void setCantidad(int);
        void setPU(float);
        void setImporteTotal(float);
        void setEstado(bool);
        int getIdComp();
        char * getLetra();
        int idProveedor();
        int getPV();
        int getNumFac();
        int getCuentaContable();
        int getCantidad();
        float getPU();
        Impuesto getIVA();
        float getImporteTotal();
        bool getEstado();
        void cargar();
        void mostrar();
        bool leerDeDisco();
        bool guardarEnDisco();
        void guardarEnDisco(int);


};

#endif // COMPROBANTE_H
