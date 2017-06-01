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
typedef vector<producto * > ProductosVector;
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
        
        while(!fileLectura.eof()){
            if(nameFile == nameFileProductos)
                cout<<"HOLA"<<endl;
            fileLectura.getline(cad, 250); //Leemos linea por linea el archivo.
            cadenaParser = (string)cad; //Lo convertimos en string
            if(!cadenaParser.empty()){ //Si la cadena no esta vacia
                cout<<cadenaParser<<endl;
                lineas.push_back(cadenaParser); //La incluimos en el vector de string
            }
        } //Mientras que no lleguemos el fin de el archivo
        fileLectura.close();
        return lineas;
    }catch(int e){
        cout<<endl<<"ERROR: #"<<e<<endl<<endl;
        system("pause");
    }
}

persona * crearPersona(){
    persona *p = (persona *)malloc(sizeof(persona));
    p->setSiguiente(NULL);
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
}

producto * crearProducto(){
    producto * p = (producto *)malloc(sizeof(producto));
    p->setSiguiente(NULL);
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
    proveedor * p = ( proveedor *)malloc(sizeof(proveedor));
    p->setSiguiente(NULL);
    return p;
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
    cliente * p = (cliente *)malloc(sizeof( cliente));
    p->setSiguiente(NULL);
    return p;
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
    empleado * p = (empleado *)malloc(sizeof( empleado));
    p->setSiguiente(NULL);
    return p;
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
    item * p = (item *)malloc(sizeof( item));
    p->setSiguiente(NULL);
    return p;
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
    item * it = NULL;
    item * aux = NULL; 
    
    for(int i = 0; i < registros.size(); i++ ){
        if(parsearRegItem(registros[i])->getCodigoFactura() == codigoFactura){
            if(!it){ //Si esta vacia        
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
    while( aux ){
        if(aux->getDNI() == dni){
            return aux;
        }
        aux = aux->getSiguiente();
    }
    return NULL;
}

empleado * getEmpleadosByDNI(int dni){
    empleado * aux = listEmpleado;
    while( aux ){
        if(aux->getDNI() == dni){
            return aux;
        }
        aux = aux->getSiguiente();
    }
    return NULL;
}

detalles * crearDetalle(){
    detalles * p = (detalles *)malloc(sizeof( detalles));
    p->setSiguiente(NULL);
    return p;
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
    detalles * it = NULL;
    detalles * aux = NULL;

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
    factura * p = (factura *)malloc(sizeof( factura));
    p->setSiguiente(NULL);
    return p;
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

void imprimirProducto(producto * p, bool nit){
    cout<<"************************"<<endl;
    cout<<"    *  Producto"<<endl;
    cout<<"    *  Nombre: "<<p->getNombre()<<endl;
    cout<<"    *  Precio: "<<p->getPrecio()<<endl;
    cout<<"    *  Codigo: "<<p->getCodigo()<<endl;
    if(nit)
        cout<<"    *  NIT Proveedor: "<<p->getNITProveedor()<<endl;
}

void loadDataFacturas(){
    StringVector registros = loadDatas(nameFileFacturas);
    factura * fac = listFactura;
    for(int i = 0; i < registros.size(); i++ ){
        if(listFactura == NULL){ //Si esta vacia
            listFactura = parsearRegFactura(registros[i]);
        }else{
            fac = listFactura;
            cout<<fac<<endl;
            while(fac->getSiguiente()){
                
                fac = fac->getSiguiente();
                
            }
            fac->setSiguiente(parsearRegFactura(registros[i])); //Se añade al final de la lista
        }
    }
}

void MostrarTodosProductos(){
    proveedor * aux = listProveedor;
    producto * auxP = NULL;
    while(aux){
        auxP = aux->getProducto();
        cout<<"____________________________________"<<endl;
        cout<<"    Proveedor: "<<aux->getNombre()<<endl;
        while(auxP){
            imprimirProducto(auxP, false);
            auxP = auxP->getSiguiente();
        }
        aux = aux->getSiguiente();
        cout<<endl;
    }
}

void MostrarTodosClientes(){
    cliente * aux = listCliente;
    persona * auxP = NULL;
    while(aux){
        auxP = listPersona;
        while(auxP){
            if(aux->getDNI() == auxP->getDNI()){
                cout<<"**************************"<<endl;
                cout<<"    Nombre: "<<auxP->getNombre()<<endl;
                cout<<"  Apellido: "<<auxP->getApellido()<<endl;
                cout<<"  Telefono: "<<auxP->getTelefono()<<endl;
                cout<<"       DNI: "<<auxP->getDNI()<<endl;
            }
            auxP = auxP->getSiguiente();
        }
        aux = aux->getSiguiente();
    }
}

void MostrarTodosEmpleado(){
    empleado * aux = listEmpleado;
    persona * auxP = NULL;
    while(aux){
        auxP = listPersona;
        while(auxP){
            if(aux->getDNI() == auxP->getDNI()){
                cout<<"**************************"<<endl;
                cout<<"    Nombre: "<<auxP->getNombre()<<endl;
                cout<<"  Apellido: "<<auxP->getApellido()<<endl;
                cout<<"  Telefono: "<<auxP->getTelefono()<<endl;
                cout<<"       DNI: "<<auxP->getDNI()<<endl;
            }
            auxP = auxP->getSiguiente();
        }
        aux = aux->getSiguiente();
    }
}

int MostrarTodosProveedores(){
    proveedor * aux = listProveedor;
    int i = 0;
    while(aux){
        cout<<"____________________________________"<<endl;
        cout<<"  "<<i<<".  Proveedor: "<<aux->getNombre()<<endl;
        aux = aux->getSiguiente();
        cout<<endl;
        if(aux){
            i++;
        }
    }
    return i;
}

proveedor *  seleccionarProveedor(){
    proveedor * aux = listProveedor;
    vector<proveedor* > Proveedores;
    int i = 0;
    int pos = 0;
    while(aux){
        cout<<"____________________________________"<<endl;
        cout<<"  "<<i<<". "<<aux->getNombre()<<endl;
        Proveedores.push_back(aux);
        i++;
        aux = aux->getSiguiente();
    }
    while(true){
        cout<<endl<<"Seleccione el proveedor"<<endl;
        cin>>pos;
        if(cin.fail() || i<0){
            cin.clear();
            cin.ignore(256, '\n');
        }else{
            return Proveedores.at(pos);
        }
    }

}

void RegistrarNuevoProducto(){
    string nombre;
    int codigo = 0;
    int precio =0;
    int i = 0;
    proveedor * prov;
    producto * auxP;

    do{
        // system("clear");
        prov = seleccionarProveedor();
        
        
        cout<<"Digite el Nombre"<<endl;
        cin>>nombre;
        cin.ignore(256, '\n');
        cout<<"Digite el Codigo"<<endl;
        cin>>codigo;
        cin.ignore(256, '\n');
        cout<<"Digite el Precio"<<endl;
        cin>>precio;
        cin.ignore(256, '\n');

        
        auxP = prov->getProducto();
        if(auxP){
            while(auxP){
                if(auxP->getSiguiente()){
                    auxP = auxP->getSiguiente();
                }else{
                    cout<<"aqui toy"<<endl;
                    auxP->setSiguiente(crearProducto());
                    auxP->getSiguiente()->setNombre(nombre);
                    auxP->getSiguiente()->setPrecio(precio);
                    auxP->getSiguiente()->setCodigo(codigo);
                    auxP->getSiguiente()->setNITProveedor(prov->getNIT());
                    return;
                }
            }
        }else{
            prov->setProducto(crearProducto());
            prov->getProducto()->setNombre(nombre);
            prov->getProducto()->setPrecio(precio);
            prov->getProducto()->setCodigo(codigo);
            prov->getProducto()->setNITProveedor(prov->getNIT());
            return;
        }
        
    }while(true);
}

void RegistrarNuevoProveedor(){
    string nombre, nit, telefono;
    proveedor * nuevo = crearProveedor();
    proveedor * aux = listProveedor;
    cout<<"Digite el nombre"<<endl;
    cin>>nombre;
    cin.ignore(256, '\n');
    cout<<"Digite el NIT"<<endl;
    cin>>nit;
    cin.ignore(256, '\n');
    cout<<"Digite el telefono"<<endl;
    cin>>telefono;
    cin.ignore(256, '\n');
    nuevo->setNombre(nombre);
    nuevo->setTelefono(telefono);
    nuevo->setNIT(nit);

    while(aux){
        if(aux->getSiguiente() == NULL){
            aux->setSiguiente(nuevo);
            break;
        }else{
            aux = aux->getSiguiente();
        }
    }
}

void RegistrarNuevoCliente(){
    string nombre, telefono, apellido;
    int dni;
    cliente * aux = listCliente;
    persona * auxP = listPersona;
    persona * nuevaP;
    cliente * nuevoC;

    cout<<"Digite el nombre"<<endl;
    cin>>nombre;
    cin.ignore(256, '\n');
    cout<<"Digite el apellido"<<endl;
    cin>>apellido;
    cin.ignore(256, '\n');
    cout<<"Digite el DNI"<<endl;
    cin>>dni;
    cin.ignore(256, '\n');
    cout<<"Digite el telefono"<<endl;
    cin>>telefono;
    cin.ignore(256, '\n');

    while(auxP){
        if(auxP->getSiguiente() == NULL){
            nuevaP = crearPersona();
            nuevaP->setNombre(nombre);
            nuevaP->setApellido(apellido);
            nuevaP->setDNI(dni);
            nuevaP->setTelefono(telefono);
            auxP->setSiguiente(nuevaP);
            break;
        }
        auxP = auxP->getSiguiente();
    }

    while(aux){
        if(aux->getSiguiente() == NULL){
            nuevoC = crearCliente();
            nuevoC->setDNI(dni);
            aux->setSiguiente(nuevoC);
            break;
        }
        aux = aux->getSiguiente();
    }
}

void RegistrarNuevoEmpleado(){
    string nombre, telefono, apellido;
    int dni;
    empleado * aux = listEmpleado;
    persona * auxP = listPersona;
    persona * nuevaP;
    empleado * nuevoC;

    cout<<"Digite el nombre"<<endl;
    cin>>nombre;
    cin.ignore(256, '\n');
    cout<<"Digite el apellido"<<endl;
    cin>>apellido;
    cin.ignore(256, '\n');
    cout<<"Digite el DNI"<<endl;
    cin>>dni;
    cin.ignore(256, '\n');
    cout<<"Digite el telefono"<<endl;
    cin>>telefono;
    cin.ignore(256, '\n');

    while(auxP){
        if(auxP->getSiguiente() == NULL){
            nuevaP = crearPersona();
            nuevaP->setNombre(nombre);
            nuevaP->setApellido(apellido);
            nuevaP->setDNI(dni);
            nuevaP->setTelefono(telefono);
            auxP->setSiguiente(nuevaP);
            break;
        }
        auxP = auxP->getSiguiente();
    }

    while(aux){
        if(aux->getSiguiente() == NULL){
            nuevoC = crearEmpleado();
            nuevoC->setDNI(dni);
            aux->setSiguiente(nuevoC);
            break;
        }
        aux = aux->getSiguiente();
    }
}

persona * loadDataPersonaPorDNI(int dni){
    persona * auxP = listPersona;
    persona * p;
    while(auxP){
        if(dni == auxP->getDNI()){
            p = crearPersona();
            cout<<"**************************"<<endl;
            p->setNombre(auxP->getNombre());
            p->setApellido(auxP->getApellido());
            p->setTelefono(auxP->getTelefono());
            p->setDNI(auxP->getDNI());
            return p;
        }
        auxP = auxP->getSiguiente();
    }
    return NULL;
}

producto * loadProductoPorCodigo(int codigo){
    proveedor * Proveedores  = listProveedor;
    producto * auxPro;
    while(Proveedores){
        auxPro = Proveedores->getProducto();
        while(auxPro){
            if(auxPro->getCodigo() == codigo){
                return auxPro;
            }
            auxPro = auxPro->getSiguiente();
        }
        Proveedores = Proveedores->getSiguiente();
    }
    return NULL;
}

void MostrarTodosFactura(){
    factura * aux = listFactura;
    item * auxItem;
    detalles * auxDetalle;
    producto * auxProducto;
    while(aux){
        auxItem = aux->getItem();
        auxDetalle = aux->getDetalle();
        if(auxDetalle && auxItem){
            cout<<"*********************************************"<<endl;
            cout<<"Codigo: "<<aux->getCodigo()<<endl;
            cout<<"Fecha: "<<auxDetalle->getFecha()<<endl;
            persona * auxP = loadDataPersonaPorDNI( auxDetalle->getCliente()->getDNI() );
            if(auxP){
                cout<<"   Cliente: "<<auxP->getNombre()<<" C.C "<<auxP->getDNI()<<endl;
            }
            auxP = loadDataPersonaPorDNI( auxDetalle->getEmpleado()->getDNI() );
            if(auxP){
                cout<<"   Empleado: "<<auxP->getNombre()<<" C.C "<<auxP->getDNI()<<endl;
            }
        }
        if(auxItem && auxDetalle){
            cout<<endl<<"    + + + + + + + + + + + + + + + + + + + + + + +"<<endl;
            while(auxItem){
                auxProducto = loadProductoPorCodigo(auxItem->getCodigoProducto());
                if(auxProducto){
                    cout<<"     __________________________________________________"<<endl;
                    cout<<"     Producto: "<<auxProducto->getNombre()<<endl;
                    //BUSCAR EL PRODUCTO
                    cout<<"     Cantidad: "<<auxItem->getCantidad()<<endl;
                    auxItem = auxItem->getSiguiente();
                }
            }
        }
        aux = aux->getSiguiente();
    }
}

bool ExisteFacturaCodigo(int codigo){
    factura * aux = listFactura;
    while(aux){
        if(aux->getCodigo() == codigo){
            return true;
        }
        aux = aux->getSiguiente();
    }
    return false;
}

void imprimirTodosProductos(){
    proveedor * aux = listProveedor;
    producto * auxP = NULL;
    int i = 0;
    while(aux){
        auxP = aux->getProducto();
        while(auxP){
            cout<<"   "<<i<<". "<<auxP->getNombre()<<endl;
            auxP = auxP->getSiguiente();
            i++;
        }
        aux = aux->getSiguiente();
    }
}

producto *seleccionarProducto(){
    proveedor * aux = listProveedor;
    producto * auxP = NULL;
    ProductosVector ProductosV;
    int i = 0;
    int pos;
    while(aux){
        auxP = aux->getProducto();
        while(auxP){
            cout<<"   "<<i<<". "<<auxP->getNombre()<<endl;
            ProductosV.push_back(auxP);
            i++;
            auxP = auxP->getSiguiente();
        }
        aux = aux->getSiguiente();
    }
    
    while(true){
        cout<<endl<<"Seleccione el producto"<<endl;
        cin>>pos;
        if(cin.fail() || pos<0){
            cin.clear();
            cin.ignore(256, '\n');
        }else{
            return ProductosV.at(pos);
        }
    }
}

int DevuelveCodigo(int cont){
    proveedor * aux = listProveedor;
    producto * auxP = NULL;
    int i = 0;
    while(aux){
        auxP = aux->getProducto();
        while(auxP){
            if(i == cont){
                return auxP->getCodigo();
            }
            auxP = auxP->getSiguiente();
            i++;
        }
        aux = aux->getSiguiente();
    }
    return (int)NULL;
}

void RegistrarItemEnFactura(factura * Fac){
    bool sw = true;
    producto * ProductoElegido;
    int cantidad = 0;
    item * nuevo = NULL;
    item * aux=NULL;
    int op = 0;
    
    do{
        system("clear");
        ProductoElegido = seleccionarProducto();
        
        if(ProductoElegido){
            cout<<"Digite la cantidad"<<endl;
            cin>>cantidad;

            if(!cantidad >0){
                cout<<"La cantidad debe ser mayor de 0"<<endl;
                system("pause");
                continue;
            }

            nuevo = crearItem();
            nuevo->setCantidad(cantidad);
            nuevo->setCodigoProducto(ProductoElegido->getCodigo());
            if(Fac->getItem() == NULL){
                Fac->setItem(nuevo);
            }else{
                aux = Fac->getItem();
                while(aux){
                    if(!aux->getSiguiente()){
                        aux->setSiguiente(nuevo);
                        break;
                    }
                    aux = aux->getSiguiente();
                }
            }
            cout<<"Quiere ingresar un nuevo item - (1,0)"<<endl;
            cin>>op;
            if(op == 0){
                return;
            }
        }
    }while(sw);
}

detalles * nuevoDetalles(){
    string fecha;
    cliente * auxCli = listCliente;
    empleado * auxEmple = listEmpleado;

    int dniCliente = 0;
    int dniEmpleado = 0;
    detalles * detal = crearDetalle();

    cout<<"Digite la fecha"<<endl;
    cin>>fecha;
    cout<<"Digite la cedula del cliente"<<endl;
    cin>>dniCliente;
    cout<<"Digite la cedula del empleado"<<endl;
    cin>>dniEmpleado;

    detal->setFecha(fecha);

    while(auxCli){
        if(dniCliente == auxCli->getDNI()){
            detal->setCliente(auxCli);
            break;
        }
        auxCli = auxCli->getSiguiente();
    }

    while(auxEmple){
        if(dniEmpleado == auxEmple->getDNI()){
            detal->setEmpleado(auxEmple);
            break;
        }
        auxEmple = auxEmple->getSiguiente();
    }

    return detal;
}

void RegistrarNuevaFactura(){
    int codigo = 0;
    int op = 0;
    factura * nuevaFactura;
    factura * aux = listFactura;
    while(true){
        system("clear");
        cout<<"Digite el codigo"<<endl;
        cin>>codigo;
        if(cin.fail()){ //Si los datos son incorrectos
            cin.ignore(256, '\n');
            cin.clear();
            continue;
        }
        if(ExisteFacturaCodigo(codigo)){ //Si el codigo ya esta en uso
            cout<<"Este codigo ya esta en uso" <<endl;
            // system("pause");
            continue;
        }
        nuevaFactura = crearFactura();
        nuevaFactura->setCodigo(codigo);
        nuevaFactura->setItem(NULL);
        RegistrarItemEnFactura(nuevaFactura);
        nuevaFactura->setDetalles(nuevoDetalles());
        nuevaFactura->getDetalle()->setCodigoFactura(codigo);
        
        while(aux){
            if(aux->getSiguiente() == NULL){
                aux->setSiguiente(nuevaFactura);
                return;
            }
            aux = aux->getSiguiente();
        }
    }
}

void guardarClientes(){
    cliente * aux = listCliente;
    fstream archivo;
	try{
		//si el arbol no esta vacio, entonces recorrelo.
        archivo.open(nameFileClientes, ios::out| ios::app); //Se abre en modo de escritura al final.
        if(!archivo.is_open()){
            cout<<"Error guardando archivos"<<endl;
            system("pause");
            return;
        }
		while(aux){
			archivo << aux->getDNI()<<endl;
            aux = aux->getSiguiente();
		}
        archivo.close();
	}catch(int ve){
		cout << "Error Nro: " << ve << endl;
		system("PAUSE");
	}
}

void guardarEmpleados(){
    empleado * aux = listEmpleado;
    fstream archivo;
	try{
		//si el arbol no esta vacio, entonces recorrelo.
        archivo.open(nameFileEmpleados, ios::out| ios::app); //Se abre en modo de escritura al final.
        if(!archivo.is_open()){
            cout<<"Error guardando archivos"<<endl;
            system("pause");
            return;
        }
		while(aux){
			archivo << aux->getDNI()<<endl;
            aux = aux->getSiguiente();
		}
        archivo.close();
	}catch(int ve){
		cout << "Error Nro: " << ve << endl;
		system("PAUSE");
	}

}

void guardarProducto(producto * p){
    producto * aux = p;
    fstream archivo;
	try{
		//si el arbol no esta vacio, entonces recorrelo.
        archivo.open(nameFileProductos, ios::out| ios::app); //Se abre en modo de escritura al final.
        if(!archivo.is_open()){
            cout<<"Error guardando archivos"<<endl;
            system("pause");
            return;
        }
        if(!aux){
            return;
        }
		while(aux){
			archivo << aux->getNombre()<<"@"<<aux->getCodigo()<<"@"<<aux->getPrecio()<<"@"<<aux->getNITProveedor()<<endl;
            aux = aux->getSiguiente();
		}
        archivo.close();
	}catch(int ve){
		cout << "Error Nro: " << ve << endl;
		system("PAUSE");
	}
}

void guardarProveedor(){
    proveedor * aux = listProveedor;
    fstream archivo;
	try{
		//si el arbol no esta vacio, entonces recorrelo.
        archivo.open(nameFileProveedores, ios::out| ios::app); //Se abre en modo de escritura al final.
        if(!archivo.is_open()){
            cout<<"Error guardando archivos"<<endl;
            system("pause");
            return;
        }
		while(aux){
			archivo << aux->getNombre()<<"@"<<aux->getNIT()<<"@"<<aux->getTelefono()<<endl;
            guardarProducto( aux->getProducto() );
            aux = aux->getSiguiente();
		}
        archivo.close();
	}catch(int ve){
		cout << "Error Nro: " << ve << endl;
		system("PAUSE");
	}

}

void guardarPersona(){
    persona * aux = listPersona;
    fstream archivo;
	try{
		//si el arbol no esta vacio, entonces recorrelo.
        archivo.open(nameFilePersonas, ios::out| ios::app); //Se abre en modo de escritura al final.
        if(!archivo.is_open()){
            cout<<"Error guardando archivos"<<endl;
            system("pause");
            return;
        }
		while(aux){
			archivo << aux->getNombre()<<"@"<< aux->getApellido()<<"@"<< aux->getDNI()<<"@"<< aux->getTelefono()<<endl;
            aux = aux->getSiguiente();
		}
        archivo.close();
	}catch(int ve){
		cout << "Error Nro: " << ve << endl;
		system("PAUSE");
	}
}

void guardarItem(item * it){
    item * aux = it;
    fstream archivo;
	try{
		//si el arbol no esta vacio, entonces recorrelo.
        archivo.open(nameFileItems, ios::out| ios::app); //Se abre en modo de escritura al final.
        if(!archivo.is_open()){
            cout<<"Error guardando archivos"<<endl;
            system("pause");
            return;
        }
		while(aux){
			archivo << aux->getCodigoFactura()<<"@"<< aux->getCodigoProducto()<<"@"<<aux->getCantidad()<<endl;
            aux = aux->getSiguiente();
		}
        archivo.close();
	}catch(int ve){
		cout << "Error Nro: " << ve << endl;
		system("PAUSE");
	}
}

void guardarDetalle(detalles * det){
    detalles * aux = det;
    fstream archivo;
	try{
		//si el arbol no esta vacio, entonces recorrelo.
        archivo.open(nameFileDetalles, ios::out| ios::app); //Se abre en modo de escritura al final.
        if(!archivo.is_open()){
            cout<<"Error guardando archivos"<<endl;
            system("pause");
            return;
        }
		if(aux){
			archivo << aux->getCodigoFactura()<<"@"<< aux->getFecha()<<"@"<<aux->getCliente()->getDNI()<<"@"<<aux->getEmpleado()->getDNI()<<endl;
		}
        archivo.close();
	}catch(int ve){
		cout << "Error Nro: " << ve << endl;
		system("PAUSE");
	}
}

void guardarFactura(){
    factura * aux = listFactura;
    fstream archivo;
	try{
		//si el arbol no esta vacio, entonces recorrelo.
        archivo.open(nameFileFacturas, ios::out| ios::app); //Se abre en modo de escritura al final.
        if(!archivo.is_open()){
            cout<<"Error guardando archivos"<<endl;
            system("pause");
            return;
        }
		while(aux){
			archivo << aux->getCodigo()<<"@"<< aux->getFormaDePago()<<endl;
            guardarItem( aux->getItem() );
            guardarDetalle( aux->getDetalle() );
            aux = aux->getSiguiente();
		}
        archivo.close();
	}catch(int ve){
		cout << "Error Nro: " << ve << endl;
		system("PAUSE");
	}
}

void guardar(){
    fstream archivo;

	//Limpiamos los registros
	archivo.open(nameFileClientes , ios::out | ios::trunc);//donde out abre al archivo como de salida y trunc lo limpia.
	archivo.close();
	archivo.open(nameFileDetalles, ios::out | ios::trunc);//donde out abre al archivo como de salida y trunc lo limpia.
	archivo.close();
    archivo.open(nameFileEmpleados, ios::out | ios::trunc);//donde out abre al archivo como de salida y trunc lo limpia.
	archivo.close();
    archivo.open(nameFileFacturas, ios::out | ios::trunc);//donde out abre al archivo como de salida y trunc lo limpia.
	archivo.close();
    archivo.open(nameFileItems, ios::out | ios::trunc);//donde out abre al archivo como de salida y trunc lo limpia.
	archivo.close();
    archivo.open(nameFilePersonas, ios::out | ios::trunc);//donde out abre al archivo como de salida y trunc lo limpia.
	archivo.close();
    archivo.open(nameFileProductos, ios::out | ios::trunc);//donde out abre al archivo como de salida y trunc lo limpia.
	archivo.close();
    archivo.open(nameFileProveedores, ios::out | ios::trunc);//donde out abre al archivo como de salida y trunc lo limpia.
	archivo.close();

    guardarClientes();
    guardarEmpleados();
    guardarProveedor();
    guardarPersona();
}