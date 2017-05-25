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

void CargarTodosDatos(){
	 cout<<"Cargando los datos"<<endl;
	 loadDataInvetario();
	 loadDataPersonas();
	 loadDataProveedores();
	 loadDataClientes();
	 loadDataEmpleados();
	 loadDataFacturas();
}


void ImprimirMenuPrincipal(){
	system("clear");
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	||***                                             Inventario                                             ***||"<<endl;
	cout<<"	||***                                             __________                                             ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                      [1]. Realizar Compra                                                          ***||"<<endl;
	cout<<"	||***                      [2]. Productos                                                                ***||"<<endl;
	cout<<"	||***                      [3]. Proveedor                                                                ***||"<<endl;
	cout<<"	||***                      [4]. Facturas                                                                 ***||"<<endl;
	cout<<"	||***                      [5]. Clientes                                                                 ***||"<<endl;
	cout<<"	||***                      [6]. Empleados                                                                ***||"<<endl;
	cout<<"	||***                      [7]. Dinero En Fondo                                                          ***||"<<endl;
	cout<<"	||***                      [8]. Guardar                                                                  ***||"<<endl;
	cout<<"	||***                      [9]. Guardar y Salir                                                          ***||"<<endl;
	cout<<"	||***                      [10]. Salir Sin Guardar                                                        ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                               Digite El Numero De Su Opcion        ***||"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
	return;
}

void Menu(){
	int op = 0;
	while(true){
		ImprimirMenuPrincipal();
		cin>>op;
		if(cin.fail() || op>10 || op<1){ //Si ingreso un dato invalido
			cin.clear();
			cin.ignore(256, '\n');
			op=0;
			continue;
		}
		switch(op){
			case 1:
				//Realizar compra
				break;
			case 2:
				//Productos
				break;
			case 3:
				//Proveedor
				break;
			case 4:
				//Facturas
				break;
			case 5:
				//Clientes
				break;
			case 6:
				//Empleados
				break;
			case 7:
				//DINERO
				break;
			case 8:
				//Guardar
				break;
			case 9:
				//Guardar y salir
				break;
			case 10:
				//Salir sin guardar
				system("clear");
				exit(0);
				break;
		}
	}
}

int main(){
	 CargarTodosDatos();
	 Menu();
	 return 0;
}