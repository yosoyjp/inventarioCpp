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
const char* nameFileInventario = "./Data/inventario.txt";

/* Ejemplos de registro en los archivos
    Personas: {
        Nombre@Apellido@DNI@Telefono
    },
    Facturas:{
        Codigo@FormaDePago
    },
    Detalles:{
        CodigoFactura@Fecha@DNICliente@DNIEmpleado
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
        codigoFactura@CodigoProducto@Cantidad
    },
    Inventario:{
        Dinero
    }
*/

//Variables que usaremos para leer y parsear los datos de los archivos
ifstream fileLectura;
char cad[250];
string cadenaParser;
// StringVector registro; //Aqui cargamos los campos de el registro

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
                cout<<cadenaParser<<endl;
                lineas.push_back(cadenaParser); //La incluimos en el vector de string
            }
        }while(!fileLectura.eof()); //Mientras que no lleguemos el fin de el archivo
        fileLectura.close();
        return lineas;
    }catch(int e){
        cout<<endl<<"ERROR: #"<<e<<endl<<endl;
        system("pause");
    }
}

inventario * crearInventario(){
    return (inventario *)malloc(sizeof(inventario));
}

inventario * parsearRegInventario(string r){
    StringVector rv = Explode(r, '@');
    inventario * i = crearInventario();
    i->addDinero( atoi(rv[0].c_str() ) );
    return i;
}

void loadDataInvetario(){

    StringVector registros = loadDatas(nameFileInventario); //Cargamos las lineas del archivo
    //Si no esta vacio;
    
    while(!registros.empty()){
        
        dataInventario = parsearRegInventario(registros[0]);
        cout<<"*****************************HERE INVENTARIO**"<<endl;
        return;
    }
    cout<<"*****************************************HERE INVENTARIO**"<<endl;
    dataInventario = crearInventario(); //Si no habia datos, solo se crea el inventario con los datos iniciales.
}

persona * crearPersona(){
    persona *p = (persona *)malloc(sizeof(persona));
    p->sgte = NULL;
    return p;
}

persona * parsearRegPersona(string r){
    StringVector rv = Explode(r, '@');
    persona *p = crearPersona();
    p->setNombre(rv[0]);
    p->setApellido(rv[1]);
    p->setDNI(atoi(rv[2].c_str()));
    p->setTelefono(rv[3]);
    return p;
}

void loadDataPersonas(){
    StringVector registros = loadDatas(nameFilePersonas); //Cargamos las lineas del archivo
    persona *peoples = listPersona;

    
    //Guardamos los datos en la lista de la estructura personas;
    for(int i = 0; i < registros.size(); i++ ){
        if(listPersona == NULL){ //Si esta vacia
            listPersona = parsearRegPersona(registros[i]);
        }else{
            peoples = listPersona;
            while(peoples->sgte != NULL){
                peoples = peoples->getSiguiente();
            }
            peoples->setSiguiente( parsearRegPersona(registros[i])); //Se añade al final de la lista
        }
    }
    cout<<"************************************HERE PERSONA**"<<endl;
}

producto * crearProducto(){
    producto * p = (producto *)malloc(sizeof(producto));
    p->sgte = NULL;
    return p;
}

producto * parsearRegProducto(string r){
    StringVector rv = Explode(r, '@');
    producto * p = crearProducto();
    p->setNombre( rv[0] );
    p->setCodigo( atoi( rv[1].c_str() ) );
    p->setPrecio( atoi( rv[2].c_str() ) );
    p->setNITProveedor( rv[3] );
    return p;
}

producto * loadDataProductos(string NIT){
    StringVector registros = loadDatas(nameFileProductos);
    producto * prod = NULL;
    producto * aux = NULL;

    //Guardamos los datos en la lista de la estructura producto, la cual se va a retornar;
    for(int i = 0; i < registros.size(); i++ ){
        
        if(!prod){ //Si esta vacia
            /* Validamos si es un producto de este proveedor */
            string g = parsearRegProducto(registros[i])->getNITProveedor();
            if(g == NIT){
                prod = parsearRegProducto(registros[i]);
                prod->setSiguiente(NULL);
            }
        }else{
            aux = prod;
            while(aux->sgte){
                aux = aux->getSiguiente();
            }
            
            /* Validamos si es un producto de este proveedor */
            string g = parsearRegProducto(registros[i])->getNITProveedor();
            if(g == NIT){
                aux->sgte = parsearRegProducto(registros[i]); //Se añade al final de la lista
            }
        }
    }
    return prod;
}

proveedor * crearProveedor(){
    return ( proveedor *)malloc(sizeof(proveedor));
}

proveedor * parsearRegProveedor(string r){
    StringVector rv = Explode(r, '@');
    proveedor * p = crearProveedor();
    p->setNombre(rv[0]);
    p->setNIT(rv[1]);
    p->setTelefono(rv[2]);
    //Cargar productos
    p->setProducto(loadDataProductos( p->getNIT() ) );
    return p;
}

void loadDataProveedores(){
    StringVector registros = loadDatas(nameFileProveedores);
    proveedor * pro = listProveedor;
    
    if(!registros.empty()){
        cout<<"**HERE PROVEEDOR**"<<endl;
    }
    //Guardamos los datos en la lista de la estructura proveedor;
    for(int i = 0; i < registros.size(); i++ ){
        if(listProveedor == NULL){ //Si esta vacia
            listProveedor = parsearRegProveedor(registros[i]);
        }else{
            pro = listProveedor;
            while(pro->sgte != NULL){
                pro = pro->sgte;
            }
            pro->sgte = parsearRegProveedor(registros[i]); //Se añade al final de la lista
        }
    }
}

cliente * crearCliente(){
    return (cliente *)malloc(sizeof( cliente));
}

cliente * parsearRegCliente(string r){
    StringVector rv = Explode(r, '@');
    cliente * c = crearCliente();
    c->setDNI( atoi( rv[0].c_str() ) );
    return c;
}

void loadDataClientes(){
    StringVector registros = loadDatas(nameFileClientes);
    cliente * cli = listCliente;
    cout<<"**HERE CLIENTE**"<<endl;
    //Guardamos los datos en la lista de la estructura cliente;
    for(int i = 0; i < registros.size(); i++ ){
        if(listCliente == NULL){ //Si esta vacia
            listCliente = parsearRegCliente(registros[i]);
        }else{
            cli = listCliente;
            while(cli->sgte != NULL){
                cli = cli->sgte;
            }
            cli->sgte = parsearRegCliente(registros[i]); //Se añade al final de la lista
        }
    }
    cout<<"******************************* HERE CLIENTE**"<<endl;
}

empleado * crearEmpleado(){
    return (empleado *)malloc(sizeof( empleado));
}

empleado * parsearRegEmpleado(string r){
    StringVector rv = Explode(r, '@');
    empleado * e = crearEmpleado();
    e->setDNI( atoi( rv[0].c_str() ) );
    return e;
}

void loadDataEmpleados(){
    StringVector registros = loadDatas(nameFileEmpleados);
    empleado * emp = listEmpleado;

    //Guardamos los datos en la lista de la estructura empleado;
    for(int i = 0; i < registros.size(); i++ ){
        if(listEmpleado == NULL){ //Si esta vacia
            listEmpleado = parsearRegEmpleado(registros[i]);
        }else{
            emp = listEmpleado;
            while(emp->sgte != NULL){
                emp = emp->sgte;
            }
            emp->setSiguiente(parsearRegEmpleado(registros[i])); //Se añade al final de la lista
        }
    }
}

item * crearItem(){
    return (item *)malloc(sizeof(item));
}

item * parsearRegItem(string r){
    StringVector rv = Explode(r, '@');
    item * i = crearItem();

    i->setCodigoFactura(  atoi(rv[0].c_str() ) );
    i->setCodigoProducto( atoi(rv[1].c_str() ) );
    i->setCantidad( atoi(rv[2].c_str() ) );
    return i;
}

item * loadDataItems(int codigoFactura){
    StringVector registros = loadDatas(nameFileItems);
    item * it;
    item * aux;

    for(int i = 0; i < registros.size(); i++ ){
        if(parsearRegItem(registros[i])->getCodigoFactura() == codigoFactura){
            if(it == NULL){ //Si esta vacia        
                it = parsearRegItem(registros[i]);
            }else{
                aux = it;
                while(aux->getSiguiente() != NULL){
                    aux = aux->getSiguiente();
                }
                aux->setSiguiente(parsearRegItem(registros[i])); //Se añade al final de la lista
            }
        }
    }
    return it;
}

cliente * getClientesByDNI(int dni){
    cliente * aux = listCliente;
    cliente * ret = crearCliente();
    while( aux->getSiguiente() ){
        if(aux->getDNI() == dni){
            ret->setSiguiente(aux);
        }
        aux = aux->getSiguiente();
    }
    return ret;
}

empleado * getEmpleadosByDNI(int dni){
    empleado * aux = listEmpleado;
    empleado * ret = crearEmpleado();
    while( aux->getSiguiente() ){
        if(aux->getDNI() == dni){
            ret->setSiguiente(aux);
        }
        aux = aux->getSiguiente();
    }
    return ret;
}

detalles * crearDetalle(){
    return (detalles *)malloc(sizeof(detalles));    
}

detalles * parsearRegDetalles(string r){
    StringVector rv = Explode(r, '@');
    detalles * det = crearDetalle();
            // CodigoFactura@Fecha@DNICliente@DNIEmpleado
    det->setCodigoFactura( atoi(rv[0].c_str()) );
    det->setFecha( rv[1] );

    //Cargamos al cliente
    det->setCliente( getClientesByDNI( atoi(rv[2].c_str()) ) );
    //Cargamos al empleado
    det->setEmpleado( getEmpleadosByDNI( atoi(rv[3].c_str()) ) );
    return det;
}

detalles * loadDataDetalles(int codigoFactura){
    StringVector registros = loadDatas(nameFileDetalles);
    detalles * it;
    detalles * aux;

    for(int i = 0; i < registros.size(); i++ ){
        if(parsearRegDetalles(registros[i])->getCodigoFactura() == codigoFactura){
            if(it == NULL){ //Si esta vacia        
                it = parsearRegDetalles(registros[i]);
            }else{
                aux = it;
                while(aux->getSiguiente() != NULL){
                    aux = aux->getSiguiente();
                }
                aux->setSiguiente(parsearRegDetalles(registros[i])); //Se añade al final de la lista
            }
        }
    }
    return it;
}

factura * crearFactura(){
    return (factura *)malloc(sizeof(factura));
}

factura * parsearRegFactura(string r){
    StringVector rv = Explode(r, '@');
    factura * f = crearFactura();

    f->setCodigo( atoi(rv[0].c_str() ) );
    f->setFormaDePago(rv[1]);
    //Cargar item
    f->setItem( loadDataItems( f->getCodigo() ) );
    //Cargar detalles
    f->setDetalles( loadDataDetalles( f->getCodigo()) );
    return f;
}

void loadDataFacturas(){
    StringVector registros = loadDatas(nameFileFacturas);
    factura * fac = listFactura;

    for(int i = 0; i < registros.size(); i++ ){
        if(listFactura == NULL){ //Si esta vacia
            listFactura = parsearRegFactura(registros[i]);
        }else{
            fac = listFactura;
            while(fac->getSiguiente() != NULL){
                fac = fac->getSiguiente();
            }
            fac->setSiguiente(parsearRegFactura(registros[i])); //Se añade al final de la lista
        }
    }
}

void MostrarTodosProductos(){
    proveedor * aux = listProveedor;
    producto * auxP;
    while(aux){
        auxP = aux->getProducto();
        cout<<"Nombre: "<<aux->getNombre()<<endl;
        aux = aux->getSiguiente();
    }
}