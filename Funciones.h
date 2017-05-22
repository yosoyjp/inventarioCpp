#include <sstream>
#include <fstream>

const string nameFilePersonas = "./Data/personas.txt";
const string nameFileFacturas = "./Data/facturas.txt";
const string nameFileDetalles = "./Data/detalles.txt";
const string nameFileClientes = "./Data/clientes.txt";
const string nameFileEmpleados = "./Data/empleados.txt";
const string nameFileProveedores = "./Data/proveedores.txt";
const string nameFileItems = "./Data/items.txt";
const string nameFileProductos = "./Data/productos.txt";

/* Ejemplos de registro en los archivos
    Personas: {
        Nombre@Apellido@DNI@Telefono
    },
    Facturas:{
        Codigo@FormaDePago
    },
    Detalles:{
        Codigo@Fecha@DNICliente@DNIEmpleado
    },
    Empleados:{
        DNI
    },
    Clientes:{
        DNI
    },
    Proveedores:{
        Nombre@NIT@Telefono
    },
    Productos:{
        Nombre@Codigo@Precio@NITProveedor
    }
    Item:{
        CodigoProducto@Cantidad
    }
*/

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


void loadDatas(){
    
}