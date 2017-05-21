# Sistemas de inventario

### Estructuras
* __Persona__
    * DNI
    * Nombre
    * Apellido
    * Telefono

* __Productos__
    * Nombre
    * Precio
    * Codigo
    * Provedor

* __Facturas__
    * Codigo
    * Productos (lista)
    * Forma de pago

* __Detalles__
    * Codigo
    * Fecha
    * Empleado
    * Cliente
* __Item__
    * Codigo del producto
    * Cantidad

* __Clientes__ (Hereda de Persona)
    * DNI

* __Proveedor__
    * Nombre
    * NIT
    * Telefono

* __Inventario__
    * Producto (Lista)
    * Dinero

* __Empleado__ (Hereda de Persona)
    * DNI

* __Forma de pago__
    * Forma
    * Esta estructura trabaja a traves de constantes*
