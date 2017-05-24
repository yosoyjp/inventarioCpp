#include <iostream>
#include <vector>

using namespace std;

//Declaramos nuevos tipos de datos a usar;
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

//Punteros globales
Persona listPersona;
// Producto listProducto;
Proveedor listProveedor;
// Detalles listDetalles;
Empleado listEmpleado;
Cliente listCliente;
Factura listFactura;
Inventario dataInventario;

#include "Structuras.h"
#include "Funciones.h"


int main(){
    cout<<"Cargando los datos"<<endl;
    // loadDataPersonas();
    return 0;
}