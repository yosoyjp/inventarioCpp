#include <iostream>
#include <vector>

using namespace std;

#include "Structuras.h"

//Declaramos un nuevo tipo de datos que es un vector de string
typedef vector<string> StringVector;

persona *listPersona = NULL;
proveedor * listProveedor = NULL;
empleado * listEmpleado = NULL;
cliente * listCliente = NULL;
factura * listFactura = NULL;

#include "Funciones.h"

void CargarTodosDatos(){
	 cout<<"Cargando los datos"<<endl;
	 loadDataPersonas();
	 loadDataProveedores();
	 loadDataClientes();
	 loadDataEmpleados();
	 loadDataFacturas();
}

#include "Menus.h"

int main(){
	CargarTodosDatos();
	MenuPrincipal();
	return 0;
}