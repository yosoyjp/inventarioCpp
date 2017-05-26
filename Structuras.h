#include <string.h>
#include <stdlib.h>
#include <iostream>

const string CHEQUE = "Cheque";
const string TARJETA_CREDITO = "Tarjeta de credito";
const string TARJETA_DEBITO = "Tarjeta debido";
const string EFECTIVO = "Efectivo";

const string cadena = "";

typedef struct persona{
    char Nombre[100];
    char Apellido[100];
    int DNI;
    char Telefono[20];
    struct persona *sgte;

    string getNombre(){
        return (string)Nombre;
    }
    bool setNombre(string name){
        if(!name.empty()){
            strcpy(Nombre, name.c_str());
            return true;
        }
        return false;
    }
    string getApellido(){
        return (string)Apellido;
    }
    bool setApellido(string lastName){
        if(!lastName.empty()){
            strcpy(Apellido, lastName.c_str());
            return true;
        }
        return false;
    }
    int getDNI(){
        return DNI;
    }
    bool setDNI(int doc){
        if(doc != (int)NULL){
            DNI = doc;
            return true;
        }
        return false;
    }
    string getTelefono(){
        return (string)Telefono;
    }
    bool setTelefono(string tel){
        if(!tel.empty()){
            strcpy(Telefono, tel.c_str());
            return true;
        }
        return false;
    }
    void setSiguiente(struct persona *f){
        sgte=f;
    }
    struct persona *getSiguiente(){
        return sgte;
    }
}persona;

typedef struct producto{
    char Nombre[100];
    int Codigo;
    int Precio;
    char NITProveedor[20];
    struct producto *sgte;

    string getNombre(){
        return string(Nombre);
    }
    bool setNombre(string name){
        if(!name.empty()){
            strcpy(Nombre, name.c_str());
            return true;
        }
        return false;
    }
    int getCodigo(){
        return Codigo;
    }
    bool setCodigo(int c){
        if(c != (int)NULL && c >= 0){
            Codigo = c;
            return true;
        }
        return false;
    }
    int getPrecio(){
        return Precio;
    }
    bool setPrecio(int c){
        if(c != (int)NULL && c >= 0){
            Precio = c;
            return true;
        }
        return false;
    }
    bool setNITProveedor(string nit){
        if(!nit.empty()){
            strcpy(NITProveedor, nit.c_str());
            return true;
        }
        return false;
    }
    string getNITProveedor(){
        return (string)NITProveedor;
    }
    void setSiguiente(struct producto *f){
        sgte = f;
    }
    struct producto *getSiguiente(){
        return sgte;
    }
}producto;

typedef struct proveedor{
    proveedor *sgte;
    char Nombre[100];
    char NIT[20];
    char Telefono[20];
    producto *prodc;

    // METODOS
    string getNombre(){
        return (string)Nombre;
    }
    bool setNombre(string name){
        if(!name.empty()){
            strcpy(Nombre, name.c_str());
            return true;
        }
        return false;
    }
    string getTelefono(){
        return (string)Telefono;
    }
    bool setTelefono(string tel){
        if(!tel.empty()){
            strcpy(Telefono, tel.c_str());
            return true;
        }
        return false;
    }
    string getNIT(){
        return (string)NIT;
    }
    bool setNIT(string n){
        if(!n.empty()){
            strcpy(NIT, n.c_str());
            return true;
        }
        return false;
    }
    void setSiguiente(proveedor *f){
        sgte=f;
    }
    proveedor *getSiguiente(){
        return sgte;
    }
    void setProducto(producto *f){
        prodc=f;
    }
    producto * getProducto(){
        return prodc;
    }
}proveedor;

typedef struct detalles{
    int codigoFactura;
    char Fecha[100];
    struct empleado *emple;
    struct cliente *clie;
    struct detalles *sgte;

    int getCodigoFactura(){
        return codigoFactura;
    }
    bool setCodigoFactura(int c){
        if(c != (int)NULL && c >= 0){
            codigoFactura = c;
            return true;
        }
        return false;
    }
    string getFecha(){
        return (string)Fecha;
    }
    bool setFecha(string f){
        if(!f.empty()){
            strcpy(Fecha, f.c_str());
            return true;
        }
        return false;
    }
    bool setEmpleado(struct empleado *e){
        if(e != NULL){
            emple = e;
            return true;
        }
    }
    struct empleado *getEmpleado(){
        return emple;
    }
    bool setCliente(struct cliente *e){
        if(e != NULL){
            clie = e;
            return true;
        }
    }
    struct cliente *getCliente(){
        return clie;
    }
    void setSiguiente(struct detalles *i){
        sgte = i;
    }
    struct detalles *getSiguiente(){
        return sgte;
    }
}detalles;

typedef struct item{
    int codigoPoducto;
    int cantidad;
    int codigoFactura;
    item *sgte;
    item(){
        cantidad = 0;
        codigoPoducto = 0;
    }
    bool setCodigoFactura(int c){
        if(c != (int)NULL && c >= 0){
            codigoFactura = c;
            return true;
        }
        return false;
    }
    int getCodigoFactura(){
        return codigoFactura;
    }
    bool setCodigoProducto(int c){
        if(c != (int)NULL && c >= 0){
            codigoPoducto = c;
            return true;
        }
        return false;
    }
    int getCodigoProducto(){
        return codigoPoducto;
    }
    bool setCantidad(int c){
        if(c != (int)NULL && c > 0){
            cantidad = c;
            return true;
        }
        return false;
    }
    int getCantidad(){
        return cantidad;
    }
    void setSiguiente(item *i){
        sgte = i;
    }
    item *getSiguiente(){
        return sgte;
    }
}item;

typedef struct factura{
    int Codigo;
    char formaPago[20];
    item *it;
    detalles *deta;
    factura *sgte;

    // METODOS
    void setItem(item *i){
        it = i;
    }
    item *getItem(){
        return it;
    }
    factura *getSiguiente(){
        return sgte;
    }
    bool setSiguiente(factura *f){
        sgte = f;
    }
    detalles *getDetalle(){
        return deta;
    }
    bool setDetalles(detalles *d){
        deta = d;
    }
    bool setFormaDePago(string f){
        if(!f.empty() && (f == CHEQUE || f==TARJETA_CREDITO || f==TARJETA_DEBITO || f==EFECTIVO)){
            strcpy(formaPago, f.c_str());
            return true;
        }
        return false;
    }
    int getCodigo(){
        return Codigo;
    }
    bool setCodigo(int c){
        if(c != (int)NULL && c >= 0){
            Codigo = c;
            return true;
        }
        return false;
    }
}factura;

typedef struct cliente{
    int DNI;
    cliente *sgte;
    cliente(){
        DNI = 0;
    }
    int getDNI(){
        return DNI;
    }
    bool setDNI(int doc){
        if(doc != (int)NULL){
            DNI = doc;
            return true;
        }
        return false;
    }
    cliente *getSiguiente(){
        return sgte;
    }
    bool setSiguiente(cliente *f){
        sgte = f;
    }
}cliente;

typedef struct empleado{
    int DNI;
    empleado *sgte;
    empleado(){
        DNI = 0;
    }
    int getDNI(){
        return DNI;
    }
    bool setDNI(int doc){
        if(doc != (int)NULL){
            DNI = doc;
            return true;
        }
        return false;
    }
    empleado *getSiguiente(){
        return sgte;
    }
    bool setSiguiente(empleado *f){
        sgte = f;
    }
}empleado;

typedef struct inventario{
    int Dinero;
    inventario(){
        Dinero = 0;
    }
    bool addDinero(int cash){
        if(cash != (int)NULL && cash>0){
            Dinero = Dinero+cash;
            return true;
        }
        return false;
    }
    int getDinero(){
        return Dinero;
    }
}inventario;