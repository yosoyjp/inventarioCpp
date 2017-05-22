#include <string.h>
#include <vector>
#include <stdlib.h>
#include <iostream>

const string CHEQUE = "Cheque";
const string TARJETA_CREDITO = "Tarjeta de credito";
const string TARJETA_DEBITO = "Tarjeta debido";
const string EFECTIVO = "Efectivo";

typedef vector<string> StringVector;
typedef struct persona *Persona;
typedef struct producto *Producto;
typedef struct proveedor *Proveedor;
typedef struct detalles *Detalles;
typedef struct empleado *Empleado;
typedef struct cliente *Cliente;
typedef struct factura *Factura;
typedef struct item *Item;
typedef struct inventario *Inventario;

StringVector Explode(const string & str, char separator ){
	StringVector  result;
	size_t pos1 = 0;
	size_t pos2 = 0;
	while ( pos2 != str.npos ){
	pos2 = str.find(separator, pos1);
    if(pos2 != str.npos){
    	if(pos2 > pos1){
    		result.push_back( str.substr(pos1, pos2-pos1) );
		}
        pos1 = pos2+1;
		}
	}
	result.push_back( str.substr(pos1, str.size()-pos1) );
	return result;
}


struct persona{
    char Nombre[100];
    char Apellido[100];
    int DNI;
    char Telefono[20];
    Persona *sgte;

    persona(){
        Nombre = "";
        Apellido = "";
        DNI = NULL;
        Telefono = "";
    }
    string getNombre(){
        return (string)Nombre;
    }
    bool setNombre(string name){
        if(!name.empty()){
            Nombre = name.c_str();
            return true;
        }
        return false;
    }
    string getApellido(){
        return (string)Apellido;
    }
    bool setApellido(string lastName){
        if(!lastName.empty()){
            Apellido = lastName.c_str();
            return true;
        }
        return false;
    }
    int getDNI(){
        return DNI;
    }
    bool setDNI(int doc){
        if(doc != NULL){
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
            Telefono = tel;
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
            Nombre = name.c_str();
            return true;
        }
        return false;
    }
    string getTelefono(){
        return (string)Telefono;
    }
    bool setTelefono(string tel){
        if(!tel.empty()){
            Telefono = tel;
            return true;
        }
        return false;
    }
    string getNIT(){
        return (string)NIT;
    }
    bool setNIT(string n){
        if(!n.empty()){
            NIT = n;
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
            Nombre = name.c_str();
            return true;
        }
        return false;
    }
    int getCodigo(){
        return Codigo;
    }
    bool setCodigo(int c){
        if(c != NULL && c >= 0){
            Codigo = c;
            return true;
        }
        return false;
    }
    int getPrecio(){
        return Precio;
    }
    bool setPrecio(int c){
        if(c != NULL && c => 0){
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
        if(c != NULL && c => 0){
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
            Fecha = f.c_str();
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
        if(c != NULL && c >= 0){
            codigoPoducto = c;
            return true;
        }
        return false;
    }
    int getCodigoProducto(){
        return codigoPoducto;
    }
    bool setCantidad(int c){
        if(c != NULL && c > 0){
            cantidad = c;
            return true;
        }
        return false;
    }
    int getCantidad(){
        return cantidad;
    }
}

struct factura{
    Detalles *detalle;
    string formaPago;
    Item *items;
    bool setFormaDePago(string f){
        if(!f.empty() && (f == CHEQUE || f==TARJETA_CREDITO || f==TARJETA_DEBITO || f==EFECTIVO)){
            formaPago = f;
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
        if(doc != NULL){
            DNI = doc;
            return true;
        }
        return false;
    }
}

struct empleado{
    int DNI;
    empleado(){
        DNI = 0;
    }
    int getDNI(){
        return DNI;
    }
    bool setDNI(int doc){
        if(doc != NULL){
            DNI = doc;
            return true;
        }
        return false;
    }
}

struct inventario{
    Producto *productos;
    int Dinero;
    inventario(){
        productos = NULL;
        Dinero = 0;
    }
    bool addDinero(int cash){
        if(cash != NULL && cash>0){
            Dinero = Dinero+cash;
            return true;
        }
        return false;
    }
}