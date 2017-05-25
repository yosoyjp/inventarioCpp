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

Inventario crearInventario(){
    return (struct inventario *)malloc(sizeof(struct inventario));
}

Inventario parsearRegInventario(string r){
    StringVector rv = Explode(r, '@');
    Inventario i = crearInventario();
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
            peoples->sgte = parsearRegPersona(registros[i]); //Se añade al final de la lista
        }
    }
    cout<<"************************************HERE PERSONA**"<<endl;
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
    p->setNITProveedor( rv[3] );
    return p;
}

Producto loadDataProductos(string NIT){
    StringVector registros = loadDatas(nameFileProductos);
    Producto prod;
    Producto aux;

    //Guardamos los datos en la lista de la estructura producto, la cual se va a retornar;
    for(int i = 0; i < registros.size(); i++ ){
        
        if(i == 0){ //Si esta vacia
            /* Validamos si es un producto de este proveedor */
            string g = parsearRegProducto(registros[i])->getNITProveedor();
            if(g == NIT){
                prod = parsearRegProducto(registros[i]);
            }
        }else{
            cout<<prod->getNombre()<<endl;
            aux = prod;
            while(aux->getSiguiente() != NULL){
                cout<<aux->getSiguiente();
                aux = aux->getSiguiente();
                
                cout<<"************************************HERE PROfdsfDUCTO**"<<endl;    
            }
            cout<<"************************************HERE PROaaaaaDUCTO**"<<endl;    
            /* Validamos si es un producto de este proveedor */
            string g = parsearRegProducto(registros[i])->getNITProveedor();
            if(g == NIT){
                aux->sgte = parsearRegProducto(registros[i]); //Se añade al final de la lista
            }
        }
    }
    return prod;
}

Proveedor crearProveedor(){
    return (struct proveedor *)malloc(sizeof(struct proveedor));
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

Cliente crearCliente(){
    return (struct cliente *)malloc(sizeof(struct cliente));
}

Cliente parsearRegCliente(string r){
    StringVector rv = Explode(r, '@');
    Cliente c = crearCliente();
    c->setDNI( atoi( rv[0].c_str() ) );
    return c;
}

void loadDataClientes(){
    StringVector registros = loadDatas(nameFileClientes);
    Cliente cli = listCliente;
    cout<<"**HERE ADSDASD**"<<endl;
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

Empleado crearEmpleado(){
    return (struct empleado *)malloc(sizeof(struct empleado));
}

Empleado parsearRegEmpleado(string r){
    StringVector rv = Explode(r, '@');
    Empleado e = crearEmpleado();
    e->setDNI( atoi( rv[0].c_str() ) );
    return e;
}

void loadDataEmpleados(){
    StringVector registros = loadDatas(nameFileEmpleados);
    Empleado emp = listEmpleado;

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

Item crearItem(){
    return (struct item *)malloc(sizeof(struct item));
}

Item parsearRegItem(string r){
    StringVector rv = Explode(r, '@');
    Item i = crearItem();

    i->setCodigoFactura(  atoi(rv[0].c_str() ) );
    i->setCodigoProducto( atoi(rv[1].c_str() ) );
    i->setCantidad( atoi(rv[2].c_str() ) );
    return i;
}

Item loadDataItems(int codigoFactura){
    StringVector registros = loadDatas(nameFileItems);
    Item it;
    Item aux;

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

Cliente getClientesByDNI(int dni){
    Cliente aux = listCliente;
    Cliente ret = crearCliente();
    while( aux->getSiguiente() ){
        if(aux->getDNI() == dni){
            ret->setSiguiente(aux);
        }
        aux = aux->getSiguiente();
    }
    return ret;
}

Empleado getEmpleadosByDNI(int dni){
    Empleado aux = listEmpleado;
    Empleado ret = crearEmpleado();
    while( aux->getSiguiente() ){
        if(aux->getDNI() == dni){
            ret->setSiguiente(aux);
        }
        aux = aux->getSiguiente();
    }
    return ret;
}

Detalles crearDetalle(){
    return (struct detalles *)malloc(sizeof(struct detalles));    
}

Detalles parsearRegDetalles(string r){
    StringVector rv = Explode(r, '@');
    Detalles det = crearDetalle();
            // CodigoFactura@Fecha@DNICliente@DNIEmpleado
    det->setCodigoFactura( atoi(rv[0].c_str()) );
    det->setFecha( rv[1] );

    //Cargamos al cliente
    det->setCliente( getClientesByDNI( atoi(rv[2].c_str()) ) );
    //Cargamos al empleado
    det->setEmpleado( getEmpleadosByDNI( atoi(rv[3].c_str()) ) );
    return det;
}

Detalles loadDataDetalles(int codigoFactura){
    StringVector registros = loadDatas(nameFileDetalles);
    Detalles it;
    Detalles aux;

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

Factura crearFactura(){
    return (struct factura *)malloc(sizeof(struct factura));
}

Factura parsearRegFactura(string r){
    StringVector rv = Explode(r, '@');
    Factura f = crearFactura();

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
    Factura fac = listFactura;

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
    Proveedor aux = listProveedor;
    Producto auxP;
    while(aux){
        auxP = aux->getProducto();
        cout<<"Nombre: "<<aux->getNombre()<<endl;
        aux = aux->getSiguiente();
    }
}