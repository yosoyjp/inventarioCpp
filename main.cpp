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

Persona listPersona;
Proveedor listProveedor;
Empleado listEmpleado;
Cliente listCliente;
Factura listFactura;
Inventario dataInventario;

#include "Structuras.h"
#include "Funciones.h"

void CargarTodosDatos(){
	 cout<<"Cargando los datos"<<endl;
	 loadDataInvetario();
	 loadDataPersonas();
	 loadDataProveedores();
	 loadDataClientes();
	 loadDataEmpleados();
	 loadDataFacturas();
}

#include "Menus.h"

int main(){
	CargarTodosDatos();
	cout<<listProveedor->getNombre()<<endl;
	// MenuPrincipal();
	 
	 return 0;
}