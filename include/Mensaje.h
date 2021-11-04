#ifndef MENSAJE_H
#define MENSAJE_H


class Mensaje
{


    private:

        TipoMensaje _tipoMensaje;
        string _mensaje;
        int _x , _y;


    public:
        enum class TipoMensaje{

            Info;
            Exito;
            Error

        };
        Mensaje(string mensaje, TipoMensaje tipoMensaje::Info , int x=1 , int y=24);
        void mostrar();

};

#endif // MENSAJE_H
