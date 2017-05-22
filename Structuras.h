#include <string.h>
#include <stdlib.h>
#include <iostream>

const string CHEQUE = "Cheque";
const string TARJETA_CREDITO = "Tarjeta de credito";
const string TARJETA_DEBITO = "Tarjeta debido";
const string EFECTIVO = "Efectivo";

const string cadena = "";

struct persona{
    char Nombre[100];
    char Apellido[100];
    int DNI;
    char Telefono[20];
    Persona *sgte;

    persona(){
        strcpy(Nombre, cadena.c_str());
        strcpy(Apellido, cadena.c_str());
        DNI = (int)NULL;
        strcpy(Telefono, cadena.c_str());
    }
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
};

struct proveedor{
    Proveedor *sgte;
    char Nombre[100];
    char NIT[20];
    char Telefono[20];

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
};

struct producto{
    char Nombre[100];
    int Codigo;
    int Precio;
    Proveedor *proveedor;
    Producto *sgte;

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
};

struct detalles{
    int Codigo;
    char Fecha[100];
    Empleado *empleado;
    Cliente *cliente;
    Detalles *sgte;

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

};

struct item{
    int codigoPoducto;
    int cantidad;
    item(){
        cantidad = 0;
        codigoPoducto = 0;
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
};

struct factura{
    int Codigo;
    Detalles *detalle;
    char formaPago[20];
    Item *items;
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
};

struct cliente{
    int DNI;
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
};

struct empleado{
    int DNI;
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
};

struct inventario{
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
};