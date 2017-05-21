# Sistemas de inventario

### Estructuras
    * **Persona**
        * DNI
        * Nombre
        * Apellido
        * Telefono

    * **Productos:**
        * Nombre
        * Precio
        * Codigo
        * Provedor

    * **Facturas**
        * Codigo
        * Productos (lista)
        * Forma de pago

    * **Detalles**
        * Codigo
        * Fecha
        * Empleado
        * Cliente
    
    * **Clientes** (Hereda de Persona)
        * DNI

    * **Proveedor**
        * Nombre
        * NIT
        * Telefono

    * **Inventario**
        * Producto (Lista)
        * Dinero

    * **Empleado** (Hereda de Persona)
        * DNI

    * **Forma de pago**
        * Forma
        *Esta estructura trabaja a traves de constantes*
