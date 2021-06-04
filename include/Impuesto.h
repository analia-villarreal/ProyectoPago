#ifndef IMPUESTO_H
#define IMPUESTO_H


class Impuesto
{
    private:
        int _idImpuesto;
        int _tipo;
        int _impuesto;
        char _descripcion[30];
        float _tasa;
        float _minNoImponible;

    public:
        Impuesto();
        void setidImpuesto(int);
        void setTipo(int);
        void setImpuesto(int);
        void setDescripcion (char*);
        void setTasa(float);
        void setMinNoImponible(float);
        int getIdImpuesto();
        int getTipo();
        int getImpuesto();
        char *getDescripcion();
        float getTasa();
        float getMinNoImponible();
        void mostrar();
        bool leerDeDisco();
        void cargar();
        bool guardarEnDisco();
        void guardarEnDisco(int);




};

#endif // IMPUESTO_H
