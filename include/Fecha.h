#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    private:
        int _dia;
        int _mes,
        int _anio;
    public:
        Fecha(int, int, int);
        void setDia(int);
        void setMes(int);
        void setAnio(int);
        int getDia();
        int getMes();
        int getAnio();

};

#endif // FECHA_H
