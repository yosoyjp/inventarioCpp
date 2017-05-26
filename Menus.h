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
                //Registrar Producto Nuevo
                break;
            case 3:
                //Salir;
                return;
        }
    }
    

}

void ImprimirMenuPrincipal(){
	// system("clear");
	cout<<"	°____________________________________________________________________________________________________________°"<<endl;
	cout<<"	||**********************************************************************************************************||"<<endl;
	cout<<"	||***                                             Inventario                                             ***||"<<endl;
	cout<<"	||***                                             __________                                             ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                                                                                                    ***||"<<endl;
	cout<<"	||***                      [1].  Realizar Compra                                                         ***||"<<endl;
	cout<<"	||***                      [2].  Productos                                                               ***||"<<endl;
	cout<<"	||***                      [3].  Proveedor                                                               ***||"<<endl;
	cout<<"	||***                      [4].  Facturas                                                                ***||"<<endl;
	cout<<"	||***                      [5].  Clientes                                                                ***||"<<endl;
	cout<<"	||***                      [6].  Empleados                                                               ***||"<<endl;
	cout<<"	||***                      [7].  Dinero en Fondo                                                         ***||"<<endl;
	cout<<"	||***                      [8].  Guardar                                                                 ***||"<<endl;
	cout<<"	||***                      [9].  Guardar y Salir                                                         ***||"<<endl;
	cout<<"	||***                      [10]. Salir Sin Guardar                                                       ***||"<<endl;
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
				//Realizar compra
				break;
			case 2:
				//Productos
                MenuProductos();
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