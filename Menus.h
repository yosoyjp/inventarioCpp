void ImprimirMenuProductos(){
    system("clear");
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	||***                                             Productos                                              ***||"<<endl;
	cout<<"	||***                                             _________                                              ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                      [1].  Ver Todos                                                               ***||"<<endl;
	cout<<"	||***                      [2].  Registrar                                                               ***||"<<endl;
	cout<<"	||***                      [3].  Salir                                                                   ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                               Digite El Numero De Su Opcion        ***||"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
}

void MenuProductos(){
    int op;
	char a;
    while(true){
        ImprimirMenuProductos();
        cin>>op;
        if(cin.fail() || op>3 || op<1){ //Si ingreso un dato invalido
			cin.clear();
			cin.ignore(256, '\n');
			op=0;
			continue;
		}
        switch(op){
            case 1:
				system("clear");
                MostrarTodosProductos();
				cin>>a;
                break;
            case 2:
                RegistrarNuevoProducto();
                break;
            case 3:
                //Salir;
                return;
        }
    }
    

}

void ImprimirMenuProveedor(){
	system("clear");
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	||***                                             Proveedor                                              ***||"<<endl;
	cout<<"	||***                                             _________                                              ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                      [1].  Ver Todos                                                               ***||"<<endl;
	cout<<"	||***                      [2].  Registrar                                                               ***||"<<endl;
	cout<<"	||***                      [3].  Salir                                                                   ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                               Digite El Numero De Su Opcion        ***||"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
}

void MenuProveedor(){
	int op;
	char a;
    while(true){
        ImprimirMenuProveedor();
        cin>>op;
        if(cin.fail() || op>3 || op<1){ //Si ingreso un dato invalido
			cin.clear();
			cin.ignore(256, '\n');
			op=0;
			continue;
		}
        switch(op){
            case 1:
				system("clear");
                MostrarTodosProveedores();
				cin>>a;
                break;
            case 2:
                RegistrarNuevoProveedor();
                break;
            case 3:
                //Salir;
                return;
        }
    }
}

void ImprimirMenuCliente(){
	system("clear");
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	||***                                             Clientes                                               ***||"<<endl;
	cout<<"	||***                                             ________                                               ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                      [1].  Ver Todos                                                               ***||"<<endl;
	cout<<"	||***                      [2].  Registrar                                                               ***||"<<endl;
	cout<<"	||***                      [3].  Salir                                                                   ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                               Digite El Numero De Su Opcion        ***||"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
}

void MenuCliente(){
	int op;
	char a;
    while(true){
        ImprimirMenuCliente();
        cin>>op;
        if(cin.fail() || op>3 || op<1){ //Si ingreso un dato invalido
			cin.clear();
			cin.ignore(256, '\n');
			op=0;
			continue;
		}
        switch(op){
            case 1:
				system("clear");
                MostrarTodosClientes();
				cin>>a;
                break;
            case 2:
                RegistrarNuevoCliente();
                break;
            case 3:
                //Salir;
                return;
        }
    }
}

void ImprimirMenuEmpleado(){
	system("clear");
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	||***                                             Empleados                                              ***||"<<endl;
	cout<<"	||***                                             _________                                              ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                      [1].  Ver Todos                                                               ***||"<<endl;
	cout<<"	||***                      [2].  Registrar                                                               ***||"<<endl;
	cout<<"	||***                      [3].  Salir                                                                   ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                               Digite El Numero De Su Opcion        ***||"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
}

void MenuEmpleado(){
	int op;
	char a;
    while(true){
        ImprimirMenuEmpleado();
        cin>>op;
        if(cin.fail() || op>3 || op<1){ //Si ingreso un dato invalido
			cin.clear();
			cin.ignore(256, '\n');
			op=0;
			continue;
		}
        switch(op){
            case 1:
				system("clear");
                MostrarTodosEmpleado();
				cin>>a;
                break;
            case 2:
                RegistrarNuevoEmpleado();
                break;
            case 3:
                //Salir;
                return;
        }
    }
}

void ImprimirMenuEmpleado(){
	system("clear");
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	||***                                             Facturas                                               ***||"<<endl;
	cout<<"	||***                                             ________                                               ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                      [1].  Ver Todos                                                               ***||"<<endl;
	cout<<"	||***                      [2].  Registrar                                                               ***||"<<endl;
	cout<<"	||***                      [3].  Salir                                                                   ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                               Digite El Numero De Su Opcion        ***||"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
}

void MenuFactura(){
	int op;
	char a;
    while(true){
        ImprimirMenuFactura();
        cin>>op;
        if(cin.fail() || op>3 || op<1){ //Si ingreso un dato invalido
			cin.clear();
			cin.ignore(256, '\n');
			op=0;
			continue;
		}
        switch(op){
            case 1:
				system("clear");
                // MostrarTodosFactura();
				cin>>a;
                break;
            case 2:
                // RegistrarNuevaFactura();
                break;
            case 3:
                //Salir;
                return;
        }
    }
}

void ImprimirMenuPrincipal(){
	system("clear");
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	||***                                             Inventario                                             ***||"<<endl;
	cout<<"	||***                                             __________                                             ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                      [1].  Productos                                                               ***||"<<endl;
	cout<<"	||***                      [2].  Proveedor                                                               ***||"<<endl;
	cout<<"	||***                      [3].  Facturas                                                                ***||"<<endl;
	cout<<"	||***                      [4].  Clientes                                                                ***||"<<endl;
	cout<<"	||***                      [5].  Empleados                                                               ***||"<<endl;
	cout<<"	||***                      [7].  Guardar                                                                 ***||"<<endl;
	cout<<"	||***                      [8].  Guardar y Salir                                                         ***||"<<endl;
	cout<<"	||***                      [9]. Salir Sin Guardar                                                       ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                               Digite El Numero De Su Opcion        ***||"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
}



void MenuPrincipal(){
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
				//Productos
                MenuProductos();
				break;
			case 2:
				//Proveedor
				MenuProveedor();
				break;
			case 3:
				//Facturas
				break;
			case 4:
				//Clientes
				MenuCliente();
				break;
			case 5:
				//Empleados
				MenuEmpleado();
				break;
			case 7:
				//Guardar
				break;
			case 8:
				//Guardar y salir
				break;
			case 9:
				//Salir sin guardar
				system("clear");
				exit(0);
				break;
		}
	}
}