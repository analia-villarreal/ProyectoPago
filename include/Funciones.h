#ifndef FUNCIONES_H
#define FUNCIONES_H

void marco_comprobante(int,int,int,int);

void menuComprobante();

void menuProveedor();

void menuOP();

void menuPrincipal();

void menuPlandeCuentas();

int buscarPosCuenta(int);

int buscarPosMP(int);

const char* buscarNombreCuentaContable(int);

const char* buscarNombreMedioDePago(int);

void buscarNombProveedor(int);

int buscarPosProveedor(int);

void buscarFacturasProveedor(int);

void cargarProveedor();

bool buscarProveedor(int);

int contarProveedores();

void rand_proveedores();

void rand_proveedoresOP();

void listarProveedores();

void bajaProveedor();

void listarComprobantes();

bool sinRepetidos(int,int[]);

bool soloNumeros(const char *);

float buscarAlicuota(int);

char* buscarNombProv2(int);

int contarProveedores();

#endif // FUNCIONES_H
