#include <sstream>
#include <fstream>

const char* nameFilePersonas = "./Data/personas.txt";
const char* nameFileFacturas = "./Data/facturas.txt";
const char* nameFileDetalles = "./Data/detalles.txt";
const char* nameFileClientes = "./Data/clientes.txt";
const char* nameFileEmpleados = "./Data/empleados.txt";
const char* nameFileProveedores = "./Data/proveedores.txt";
const char* nameFileItems = "./Data/items.txt";
const char* nameFileProductos = "./Data/productos.txt";

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

//Variables que usaremos para leer y parsear los datos de los archivos
ifstream fileLectura;
char cad[250];
string cadenaParser;
StringVector registro; //Aqui cargamos los campos de el registro

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


StringVector loadDatas(const char* nameFile){
    try{
        fileLectura.open(nameFile, ios::out | ios::in);
        StringVector lineas;
        // Si no abre el archivo
        if(!fileLectura.is_open()){
            system("clear");
            cout<<"Ha ocurrido un error abriendo el archivo"<<endl;
            cout<<"EL problema se cerrará automaticamente"<<endl;
            system("pause");
            exit(0);
        }

        //Si si lo abrió
        do{
            fileLectura.getline(cad, 250); //Leemos linea por linea el archivo.
            cadenaParser = (string)cad; //Lo convertimos en string
            if(!cadenaParser.empty()){ //Si la cadena no esta vacia
                lineas.push_back(cadenaParser); //La incluimos en el vector de string
            }
        }while(!fileLectura.eof()); //Mientras que no lleguemos el fin de el archivo

        return lineas;
    }catch(int e){
        cout<<endl<<"ERROR: #"<<e<<endl<<endl;
        system("pause");
    }
}

Persona crearPersona(){
    return (struct persona *)malloc(sizeof(struct persona));
}

Persona parsearRegPersona(string r){
    StringVector rv = Explode(r, '@');
    Persona p = crearPersona();
    p->setNombre(rv[0]);
    p->setApellido(rv[1]);
    p->setDNI(atoi(rv[2].c_str()));
    p->setTelefono(rv[3]);
    return p;
}

void loadDataPersonas(){
    StringVector registros = loadDatas(nameFilePersonas); //Cargamos las lineas del archivo
    Persona peoples = listPersona;

    //Guardamos los datos en la lista de la estructura personas;
    for(int i = 0; i < registros.size(); i++ ){
        if(listPersona == NULL){ //Si esta vacia
            listPersona = parsearRegPersona(registros[i]);
        }else{
            peoples = listPersona;
            while(peoples->sgte != NULL){
                peoples = peoples->sgte;
            }
            peoples->sgte = parsearRegPersona(registro[i]); //Se añade al final de la lista
        }
    }
}

Producto crearProducto(){
    return (struct producto *)malloc(sizeof(struct producto));
}

Producto parsearRegProducto(string r){
    StringVector rv = Explode(r, '@');
    Producto p = crearProducto();
    p->setNombre( rv[0] );
    p->setCodigo( atoi( rv[1].c_str() ) );
    p->setPrecio( atoi( rv[2].c_str() ) );
    p->setNITProveedor( rv[4] );
    return p;
}

Producto loadDataProductos(string NIT){
    StringVector registros = loadDatas(nameFileProductos);
    Producto pro;
    Producto aux;

    //Guardamos los datos en la lista de la estructura producto, la cual se va a retornar;
    for(int i = 0; i < registros.size(); i++ ){
        if(pro == NULL){ //Si esta vacia
            /* Validamos si es un producto de este proveedor */
            if(parsearRegProducto(registros[i])->getNITProveedor() == NIT){
                pro = parsearRegProducto(registros[i]);
            }
        }else{
            aux = pro;
            while(aux->sgte != NULL){
                aux = aux->sgte;
            }
            /* Validamos si es un producto de este proveedor */
            if(parsearRegProducto(registros[i])->getNITProveedor() == NIT){
                aux->sgte = parsearRegProducto(registro[i]); //Se añade al final de la lista
            }
        }
    }
    return pro;
}

Proveedor crearProveedor(){
    return (struct proveedor *)malloc(sizeof(struct persona));
}

Proveedor parsearRegProveedor(string r){
    StringVector rv = Explode(r, '@');
    Proveedor p = crearProveedor();
    p->setNombre(rv[0]);
    p->setNIT(rv[1]);
    p->setTelefono(rv[2]);
    //Cargar productos
    p->setProducto(loadDataProductos( p->getNIT() ) );
    return p;
}

void loadDataProveedores(){
    StringVector registros = loadDatas(nameFileProveedores);
    Proveedor pro = listProveedor;

    //Guardamos los datos en la lista de la estructura proveedor;
    for(int i = 0; i < registros.size(); i++ ){
        if(listProveedor == NULL){ //Si esta vacia
            listProveedor = parsearRegProveedor(registros[i]);
        }else{
            pro = listProveedor;
            while(pro->sgte != NULL){
                pro = pro->sgte;
            }
            pro->sgte = parsearRegProveedor(registro[i]); //Se añade al final de la lista
        }
    }
}