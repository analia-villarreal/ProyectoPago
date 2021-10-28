#ifndef ORDENDEPAGO_H
#define ORDENDEPAGO_H


class OrdenDePago
{
    private:
        OrdenDePago();
        int _idOP;
        Fecha _fechaContabilizacion;
        int _tipoOP;
        int _idProveedor;
        char _razonSocial[45];
        int _numComp;
        float _retIIBB;
        float _retGanancias;
        float _importeAPagar;
        float _importeTotal;
        MediosDePagos _formDePago;
        bool _estadoOP;



    public:

        void setIdOP(int);
        void setFechaContabilizacion(Fecha);
        void setTipoOP(int);
        void setRetIIBB(float);
        void setRetGanancias(float);
        void setImporteAPagar(float);
        void setImporteTotal(float);
        void setFormaDePago(MediosDePagos);
        void setEstado(bool);
        int getIdOP();
        Fecha getFechaContabilizacion();
        int getIdProveedor();
        Proveedor getRazonSocial(int);
        int getNumComp();
        float getRetIIBB();
        float getRetGanancias();
        float getImporteAPagar();
        float getImporteTotal();
        bool getEstadoOP();
        void cargar(int);
        void mostrar();
        bool leerDeDisco(int);
        bool guardarEnDisco();
        void guardarEnDisco(int);
        void listarOrdenesDePago();
        void listarOrdenadoFechaConta();
};

#endif // ORDENDEPAGO_H
