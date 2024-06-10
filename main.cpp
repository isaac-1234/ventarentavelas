#pragma once
#include<iostream>
#include<stdlib.h>
#include<stdio.h>
#include<windows.h>
#include<vector>
#include<cstring>
#include<conio.h>

#include "Vector_cliente.h"
#include "ProductoVector.h"
#include "vectorLogin.h"
#include "VectorVenta.h"
#include "DetalleVector.h"
#include "FacturaVector.h"

using namespace std;



//CREACION DE OBJETO
VendedorVector vendedorVector;
Vectorlogin VectorLogin;
ClienteVector cliente_vector;
ProductoVector vectorProducto;
VentaVector ventaVetor;
DetalleVector detalleVector;
FacturaVector facturaVector;

//PROTOTIPOS
void menuPrincipal();
void salidaSistema();
void vistaVendedor();
void vistaCliente();
void vistaProducto()

//VENDEDOR
void adicionarVendedor();
void ListarVendedor();
void EliminarVendedor();
void modificarVendedor();
void buscarVendedor();
//CLIENTE
void adicionarCliente();
void modificarCliente();
void ListarCliente();
void EliminarCliente();
void buscarCliente();
//PRODUCTOS
void adicionarProducto();
void modificarProducto();
void ListarProducto();
void EliminarProducto();
void buscarProducto();
//VENTA
void vistaVenta();
void vistaFactura();

//GOTOXY
void gotoxy(int x, int y)
{
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD dwPos;
    dwPos.X = x;
    dwPos.Y = y;
    SetConsoleCursorPosition(hcon, dwPos);
}

void inicioSesion()
{
    vector<string> usuarios;
    vector<string> claves;
    //AÑADIR USUARIOS AL VECTOR
    usuarios.push_back("alexander");
    usuarios.push_back("leandro");
    usuarios.push_back("nelly");
    usuarios.push_back("esteban");
    usuarios.push_back("fernando");
    //ANADIR CLAVES AL VECTOR
    claves.push_back("Alexander123");
    claves.push_back("leandro");
    claves.push_back("NellyBelen");
    claves.push_back("Esteban");
    claves.push_back("Fernando");

    string usuario;
    string contrasenia;
    int intento = 0;
    bool ingreso = false;
    char caracter;

    do
    {
        system("cls");
        gotoxy(4, 5);   cout << "********************************";
        gotoxy(4, 6);   cout << "||                            ||";
        gotoxy(4, 7);   cout << "||        Bienvenido          ||";
        gotoxy(4, 8);   cout << "||                            ||";
        gotoxy(4, 9);   cout << "||        Usuario:            ||";
        gotoxy(4, 10);  cout << "||        Contrasenia:        ||";
        gotoxy(4, 11);  cout << "||        Bienvenido          ||";
        gotoxy(4, 12);  cout << "********************************";
        gotoxy(22, 9);  getline(cin, usuario);
        gotoxy(26, 10);  caracter = _getch();
        contrasenia = "";
        while (caracter != 13)//el 13 es la tecla enter en el codigo ascii
        {
            if (caracter !=8)//EL 8 SIGNIFICA EN BACKSPACE
            {
                contrasenia.push_back(caracter);
                cout << "*";
            }
            else
            {
                if (contrasenia.length() > 0)
                {
                    cout << "\b \b";
                    contrasenia = contrasenia.substr(0, contrasenia.length() - 1);
                }
            }
            caracter = _getch();
        }
        for (int i = 0; i < usuarios.size(); i++)
        {
           if (usuarios[i] ==usuario && claves [i] == contrasenia)
           {
            ingreso = true;
            break;
           } 
        }
        if (!ingreso)
        {
            //system("cls");
            gotoxy(4, 13); cout << "EL USUARIO O CONTRASENIA SON INCORRECTOS" << endl;
            gotoxy(4, 14); cout << "**INTENTOS**:" << endl;
            gotoxy(4, 15); cout << intento + 1 << " de 3 intentos" << endl;
            cin.get();
            intento++;
        }
        Login login;
        login.setUsuario(usuario);
        login.setContrasenia(contrasenia);

        VectorLogin.Add(login);
        VectorLogin.GrabarArchivo(login);//HACER QUE EL ADDVENDEDOR SE GUARDE EN GRABAR ARCHIVOS
    } while (intento < 3 && ingreso == false);
    if (ingreso == true)
    {
        cout << "Ingreso satisfactorio" << endl;
        menuPrincipal();
    }
    else
    {
        cout << "Has pasado el limite de intentos (MAXIMO 3 INTENTOS)" << endl;
        salidaSistema();
    }

}

void menuPrincipal()
{
    int opcion_menu;
    system("vls");

    gotoxy(4, 5);   cout << "**********************************";
    gotoxy(4, 6);   cout << "||                              ||";
    gotoxy(4, 7);   cout << "||      ADMINISTRADOR           ||";
    gotoxy(4, 8);   cout << "||                              ||";
    gotoxy(4, 9);   cout << "||      1.Vendedor              ||";
    gotoxy(4, 10);  cout << "||      2.Cliente               ||";
    gotoxy(4, 11);  cout << "||      3.Almacen               ||";
    gotoxy(4, 12);  cout << "||      4.Venta                 ||";
    gotoxy(4, 13);  cout << "||      5.Salida del sistema    ||";
    gotoxy(4, 14);  cout << "**********************************";
    gotoxy(10, 18);  cout << "|*******************|";
    gotoxy(10, 19);  cout << "| Elija una opción: |";
    gotoxy(10, 20);  cout << "|*******************|";
    gotoxy(29, 19);  cin >> opcion_menu;
    switch (opcion_menu)
    {
    case 1:
        vistaVendedor();
        break;
    case 2:
        vistaCliente();
        break;
    case 3:
        vistaProducto();
        break;
    case 4
        vistaVenta();
        break;
    case 5:
        gotoxy(2, 24); cout << "/*/*GRACIAS POR SU PREFERENCIA,VentaMas*/*/" << endl;
        system("pause");
        salidaSistema();

    default:
        gotoxy(10, 24);cout << "INGRESE UNA OPCION CORRECTA[1-5]" << endl;
        system("pause");
        system("cls");
        menuPrincipal();
    }
}
void salidaSistema()
{
    system("cls");

    exit(0);
}
int main()
{
    system("color 80");
    inicioSesion();
}

void vistaCliente()
{
    system("cls");
    int op_menuClientes;
    gotoxy(4, 5);   cout << "**************************************";
    gotoxy(4, 6);   cout << "||                                  ||";
    gotoxy(4, 7);   cout << "||          %CLIENTES%              ||";
    gotoxy(4, 8);   cout << "||                                  ||";
    gotoxy(4, 9);   cout << "||      1.Anadir Cliente            ||";
    gotoxy(4, 10);  cout << "||      2.Modificar Cliente         ||";
    gotoxy(4, 11);  cout << "||      3.Listar Cliente            ||";
    gotoxy(4, 12);  cout << "||      4.Eliminar Cliente          ||";
    gotoxy(4, 13);  cout << "||      5.Buscar Cliente            ||";
    gotoxy(4, 14);  cout << "||      6.Regresar                  ||";
    gotoxy(4, 15);  cout << "||                                  ||";
    gotoxy(4, 16);  cout << "||      7.Salida del sistema        ||";
    gotoxy(4, 17);  cout << "**************************************";
    gotoxy(10, 19);  cout << "|*******************|";
    gotoxy(10, 20);  cout << "| Elija una opcion  |"; gotoxy(32, 19); cout << "|";
    gotoxy(10, 21);  cout << "|*******************|";
    gotoxy(29, 20); cin >>op_menuClientes;
    switch (op_menuClientes)
    {
    case 1:
        system("cls");
        adicionarCliente();
        break;
    case 2:
        modificarCliente();
        break;
    case 3:
        system("cls");
        ListarCliente();
        break;
    case 4:
        EliminarCliente();
        break;
    case 5:
        buscarCliente();
        break;
    case 6:
        menuPrincipal();
        break;
    case 7:
        salidaSistema();
        break;
    default:gotoxy(31, 20); cout << "INGRESE LA OPCION CORRECTA [1-7]" << endl;
        system("pause");
        system("cls");
        vistaVendedor();
    }
}
void adicionarCliente()
{
    //Crear variables
    string nombre;
    string apellidos;
    string domicilio;
    string municipio;
    string estado;
    int telefono;
    string rfc_cliente;
    string tipo_nuevo_frecuente;
    int id_cliente;
    string rpta;
    cout << "\t==ANIADIR CLIENTES==\t" << endl;
    do
    {
        cout << "\n";
        id_cliente = cliente_vector.getCorrelativo();
        cout << "ID_CLIENTE: " << "[" << id_cliente << "]" << endl;
        cin.ignore();
        cout << "Ingrese el ID del cliente: "; getline(cin, id_cliente);
        cout << "                                                       " << endl;
        cout << "Ingrese el NOMBRE del cliente: "; getline(cin, nombre);
        cout << "                                                       " << endl;
        cout << "Ingrese los APELLIDOS del cliente: "; getline(cin, apellidos);
        cout << "                                                       " << endl;
        cout << "Ingrese el DOMICILIO del cliente: "; getline(cin, domicilio);
        cout << "                                                       " << endl;
        cout << "Ingrese el MUNICIPIO del cliente: "; getline(cin, municipio);
        cout << "                                                       " << endl;
        cout << "Ingrese el ESTADO del cliente: "; getline(cin, estado);
        cout << "                                                       " << endl;
        cout << "Ingrese el TELEFONO del cliente: "; getline(cin, telefono);
        cout << "                                                       " << endl;
        cout << "Ingrese el RFC del cliente: "; getline(cin, rfc_cliente);
        cout << "                                                       " << endl;
        cout << "Ingrese el TIPO del cliente: "; getline(cin, tipo_nuevo_frecuente);
        cout << "                                                       " << endl;
        //Instanciar Cliente
        Cliente1 cliente;
        cliente.setNombre(nombre);
        cliente.setApellidos(apellidos);
        cliente.setDomicilio(domicilio);
        cliente.setMunicipio(municipio);
        cliente.setEstado(estado);
        cliente.setTelefono(telefono);
        cliente.setRfc_cliente(rfc_cliente);
        cliente.setTipo_nuevo_frecuente(tipo_nuevo_frecuente);
        cliente.setId_cliente(id_cliente);

        cliente_vector.agregar(cliente); //Ingresar los objetos al vector
        cliente_vector.grabarEnArchivo(cliente); //Grabar en archivo

        cout << "\t\t\tIngrese SI o NO para seguir ingresando cliente: ";cin >> rpta;
        system("cls"); //Limpiar
    } while (rpta == "SI" || rpta == "si");
    vistaCliente();
}
void modificarCliente() //CONDICIONAR LA, MODIFICACION, ARREGLAR LA INTERFAZ, PRESENTAR "ERROR"
{
    system("cls");
    int id_cliente;
    cout << " Ingrese el id_cliente a modificar ";cin >> id_cliente;
    Cliente1 objAModificar = cliente_vector.buscarPorId_cliente(id_cliente);

    cout << "\t==REGISTRO ENCONTRADO==\t" << endl;
    cout << "nombre: " << objAModificar.getNombre() << "\n";
    cout << "apellidos: " << objAModificar.getApellidos() << "\n";
    cout << "domicilio: " << objAModificar.getDomicilio() << "\n";
    cout << "municipio: " << objAModificar.getMunicipio() << "\n";
    cout << "estado: " << objAModificar.getEstado() << "\n";
    cout << "telefono: " << objAModificar.getTelefono() << "\n";
    cout << "rfc_cliente: " << objAModificar.getRfc_cliente() << "\n";
    cout << "tipo_nuevo_frecuente: " << objAModificar.getTipo_nuevo_frecuente() << "\n";
    cin.ignore();

    string nombreModificado;
    string apellidosModificado;
    string domicilioModificado;
    string municipioModificado;
    string estadoModificado;
    int telefonoModificado;
    string rfc_clienteModificado;
    string tipo_nuevo_frecuenteModificado;
    cout << "\t *MODIFICAR CAMPOS*\n";
    cout << "Ingrese el nombre nuevo: ";getline(cin, nombreModificado);
    cout << "Ingrese los apellidos nuevos: ";getline(cin, apellidosModificado);
    cout << "Ingrese el domicilio nuevo: ";getline(cin, domicilioModificado);
    cout << "Ingrese el municipio nuevo: ";getline(cin, municipioModificado);
    cout << "Ingrese el estado nuevo: ";getline(cin, estadoModificado);
    cout << "Ingrese el telefono nuevo: ";getline(cin, telefonoModificado);
    cout << "Ingrese el rfc nuevo: ";getline(cin, rfc_clienteModificado);
    cout << "Ingrese el tipo nuevo: ";getline(cin, tipo_nuevo_frecuenteModificado);

    bool estado = cliente_vector.modificar(objAModificar, nombreModificado, apellidosModificado, domicilioModificado, municipioModificado, estadoModificado,telefonoModificado, rfc_clienteModificado, tipo_nuevo_frecuenteModificado);
    if (estado = true)
    {
        cout << "Registro del cliente modificado correctamente \n";
        /*Grabar en archivo*/
        cliente_vector.cargarModificado();
    }
    else
    {
        cout << "No se modificaron los datos del cliente \n";
    }
    system("pause");
    vistaCliente();
}
void ListarCliente() //ELIMINAR EL ESPACIO EN BLANCO EN LOS CARACTERES Y PONER ESTRELLITAS
{
    cout << "\t==CLIENTES REGISTRADOS==\t" << endl;
    if (cliente_vector.tamanio() ==0)
    {
        cout << "\n";
        cout << "\t \t " << "***VENTA MAS***" << endl;
        cout << "NO HAY REGISTROS POR AHORA" << endl;
        system("pause");
        vistaCliente();
    }
    else
    {
        for (int i = 0;i < cliente_vector.tamanio();i++)
        {
            cout << "\n";
            cout << "Id_cliente: " << cliente_vector.obtener(i).getId_cliente() << "\n";
            cout << "\n";
            cout << "Nombre: " << cliente_vector.obtener(i).getNombre() << "\n";
            cout << "\n";
            cout << "Apellidos: " << cliente_vector.obtener(i).getApellidos() << "\n";
            cout << "\n";
            cout << "Domicilio: " << cliente_vector.obtener(i).getDomicilio() << "\n";
            cout << "\n";
            cout << "Municipio: " << cliente_vector.obtener(i).getMunicipio() << "\n";
            cout << "\n";
            cout << "Estado: " << cliente_vector.obtener(i).getEstado() << "\n";
            cout << "\n";
            cout << "Telefono: " << cliente_vector.obtener(i).getTelefono() << "\n";
            cout << "\n";
            cout << "Rfc_cliente: " << cliente_vector.obtener(i).getRfc_cliente() << "\n";
            cout << "\n";
            cout << "Tipo_nuevo_frecuente: " << cliente_vector.obtener(i).getTipo_nuevo_frecuente() << "\n";
            cout << "\n";
            cout << "\t******************************************************" << endl;
        }
        system("pause");
        system("cls");
        //VOLVER AL MENU
        vistaCliente(); 
    }
}
void EliminarCliente()
{
    int id_cl;
    string rpt;
    system("cls");
    cout << "\t Ingrese el id_cliente a eliminar: "; cin >> id_cl;
    Cliente1 ClienteAEliminar = cliente_vector.buscarPorId_cliente(id_cl);
    cout << "\n";
    if (ClienteAEliminar.getNombre() == "ERROR")
    {
        cout << "NO SE ENCOTRO ESE REGISTRO" << endl;
        system("pause");
        vistaCliente();
    }
    else
    {
        cout << "\t**REGISTRO ENCONTRADO**\t" <<endl;
        cout << "ID_CLIENTE: " << ClienteAEliminar.getId_cliente() << endl;
        cout << "NOMBRE: " <<ClienteAEliminar.getNombre() << endl;
        cout << "APELLIDOS: " <<ClienteAEliminar.getApellidos() << endl;
        cout << "DOMICILIO: " <<ClienteAEliminar.getDomicilio() << endl;
        cout << "MUNICIPIO: " <<ClienteAEliminar.getMunicipio() << endl;
        cout << "ESTADO: " <<ClienteAEliminar.getEstado() << endl;
        cout << "TELEFONO: " <<ClienteAEliminar.getTelefono() << endl;
        cout << "RFC_CLIENTE: " <<ClienteAEliminar.getRfc_cliente() << endl;
        cout << "TIPO_NUEVO_FRECUENTE: " <<ClienteAEliminar.getTipo_nuevo_frecuente() << endl;
        cin.ignore();
        cout << "DESEA ELIMINAR ESTE REGISTRO(si/no): ";
        cin >> rpt;
        if (rpt == "si" || rpt == "SI")
        {
            cliente_vector.eliminar(ClienteAEliminar);
            cout << "-REGISTRO ELIMINADO-" << endl;
            cliente_vector.cargarModificado();
            system("pause");
            vistaCliente();
        }
        else
        {
            system("pause");
            EliminarCliente();
        }
    }
}
void buscarCliente()//ARREGLAR INTERFAZ
{
    system("cls");
    int id_cl;
    cout << "\t==BUSCAR CLIENTE REGISTRADO==\t" << endl;
    cout << "Ingresar el ID del cliente a buscar: "; cin >> id_cl;
    Cliente1 cli = cliente_vector.buscarPorId_cliente(id_cl);
    if (cli.getNombre() != "Error")
    {
        cout << "\t**DATOS DEL CLIENTE ENCONTRADO**\t\n";
        cout << "Id_cliente: " <<cli.getId_cliente() << "\n";
        cout << "Nombre: " <<cli.getNombre() << "\n";
        cout << "Apellidos: " <<cli.getApellidos() << "\n";
        cout << "Domicilio: " <<cli.getDomicilio() << "\n";
        cout << "Municipio: " <<cli.getMunicipio() << "\n";
        cout << "Estado: " <<cli.getEstado() << "\n";
        cout << "Telefono: " <<cli.getTelefono() << "\n";
        cout << "Rfc_cliente: " <<cli.getRfc_cliente() << "\n";
        cout << "Tipo_Nuevo_Frecuente: " <<cli.getTipo_nuevo_frecuente() << "\n";
        system("pause");
        vistaCliente();
    }
    else{
        cout << "¡No se pudo encontrar el registro, hubo un error!\n";
    }
    system("pause");
    vistaCliente(); //corresponde al renglon 434
}
void vistaProducto() //corresponde al renglon 682
{
    system("cls");
    int op_menuProductos;
    gotoxy(4, 5);   cout << "***********************************";
    gotoxy(4, 6);   cout << "||                               ||";
    gotoxy(4, 7);   cout << "||      %ALMACEN%                ||";
    gotoxy(4, 8);   cout << "||                               ||";
    gotoxy(4, 9);   cout << "||      1.anadir productos       ||";
    gotoxy(4, 10);  cout << "||      2.Modificar productos    ||";
    gotoxy(4, 11);  cout << "||      3.Listar productos       ||";
    gotoxy(4, 12);  cout << "||      4.Eliminar productos     ||";
    gotoxy(4, 13);  cout << "||      5.Buscar productos       ||";
    gotoxy(4, 14);  cout << "||      6.Regresar               ||";
    gotoxy(4, 15);  cout << "||                               ||";
    gotoxy(4, 16);  cout << "||      7.Salida del sistema     ||";
    gotoxy(4, 17);  cout << "***********************************";
    gotoxy(10, 18); cout << "|*******************|";
    gotoxy(10, 19); cout << "| Elija una Opción: |";
    gotoxy(10, 20); cout << "|*******************|";
    gotoxy(29, 19); cin >> op_menuProductos;
    switch (op_menuProductos)
    {
    case 1:
        system("cls";)
        adicionarProducto();
        break;
    case 2:
        modificarProducto();
        break;
    case 3:
        system("cls");
        ListarProducto();
        break;
    case 4:
        EliminarProducto();
        break;
    case 5:
        buscarProducto();
        break;
    case 6:
        menuPrincipal();
        break;
    case 7:
        salidaSistema();
        break;
    
    default: gotoxy(31, 20);cout << "INGRESE LA OPCION CORRECTA[1-7]" << endl;
        system("pause");
        system("cls");
        vistaProducto();
    }
}
void adicionarProducto()
{
    //Crear Variables
    string id_producto;
    string nombre_Producto;
    string origen_Stock_WO_Compra;
    float precio;
    int disponibilidad_Dias;
    string tipo_Venta_Renta;
    int cantidad;
    string rpta;
    //Crear el objeto de la clase
    do
    {
        cout << "\t===AGREGAR PRODUCTOS AL ALMACEN===\t" << endl;
        //Entrada de datos
        id_producto = vectorProducto.getCorrelativo();
        cout << "Ingresar ID del producto:";
        cin >> id_producto;

        cout << "Ingresar Nombre del producto:";
        cin >> nombre_Producto;

        cout << "Ingresar Origen_Stock_WO_Compra del producto:";
        cin >> origen_Stock_WO_Compra;

        cout << "Ingresar Precio del producto:";
        cin >> precio;

        cout << "Ingresar Disponibilidad_Dias del producto:";
        cin >> disponibilidad_Dias;

        cout << "Ingresar Tipo_Venta_Renta del producto:";
        cin >> tipo_Venta_Renta;

        cout << "Ingresar Cantidad del producto:";
        cin >> cantidad;

        Producto producto; /*crear el Objeto*/

        producto.setId_producto(id_producto);
        producto.setNombre_producto(nombre_Producto);
        producto.setOrigen_stock_wo_compra(origen_Stock_WO_Compra);
        producto.setPrecio(precio);
        producto.setDisponibilidad_dias(disponibilidad_Dias);
        producto.setTipo_venta_renta(tipo_Venta_Renta);
        producto.setCantidad(cantidad);

        vectorProducto.add(producto); //Agregar el objeto al vector dinamico
        vectorProducto.grabarArchivo(producto); //HACER QUE EL ADDVENDEDOR SE GUARDE EN GRABAR ARCHIVOS

        cout << "Para continuar pulsar(SI o NO):";
        cin >> rpta;
        system("cls"); //Limpiar

    } while (rpta == "SI" || rpta =="si");
    //VOLVER AL MENU
    vistaProducto();
}
void modificarProducto()
{
    system("cls");
    string id_producto;
    string rpt;
    do
    {
        cout << "\t==MODIFICAR DATOS DEL PRODUCTO"==\t" << endl;
        cout << "INGRESAR EL ID_PRODUCTO A MODIFICAR: ";
        cin >> id_producto;
        Producto p = vectorProducto.buscarPorId_producto(id_producto);

        string nombre_productoModificado;
        string origen_stock_wo_compraModificado;
        float precioModificado;
        int disponibilidad_diasModificado;
        string tipo_venta_rentaModificado;

        cout << "\t*REGISTRO ENCONTRADO*\t" << endl;
        cout << "Id_producto: " << "00000000" << p.getId_producto() << endl;
        cout << "------------------------------------------" << endl;
        cout << "Nombre_producto: " << p.getNombre_producto() << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Origen_stock_wo_compra: " << p.getOrigen_stock_wo_compra() << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Precio: " << p.getPrecio() << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Disponibilidad_dias: " << p.getDisponibilidad_dias() << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Tipo_venta_renta: " << p.getTipo_venta_renta() << endl;
        cout << "--------------------------------------------------" << endl;
        cout << "Cantidad: " << p.getCantidad() << endl;
        cin.ignore();
        cout << "\n";
        cout << "**Modificar campos**:" << endl;
        cout << "NOMBRE MODIFICADO:";
        cin >> nombre_productoModificado;
        cout << "ORIGEN_STOCK_WO_COMPRA MODIFICADO:";
        cin >> origen_stock_wo_compraModificado;
        cout << "PRECIO MODIFICADO:";
        cin >> precioModificado;
        cout << "DISPONIBILIDAD_DIAS MODIFICADO:";
        cin >> disponibilidad_diasModificado;
        cout << "TIPO_VENT_RENTA MODIFICADO:";
        cin >> tipo_venta_rentaModificado;
        bool estado = vectorProducto.modificar(p, nombre_productoModificado, precioModificado);
        if (estado = true)
        {
            cout << "**REGISTRO MODIFICADO SATISFACTORIAMENTE**" << endl;
            vectorProducto.grabarModificarEliminarArchivo();
            cout << "DESEA REGRESAR AL MENU DE PRODUCTOS(SI/NO): ";
            cin >> rpt;
        }
        else
        {
            cout << "NO SE MODIFICO EL REGISTRO";
        }
    } while (rpt == "NO" || rpt == "no");
    system("pause");
    system("cls");
    vistaProducto();
}
void ListarProducto()
{
    system("cls");
    if (vectorProducto.rows() == 0)
    {
        cout << "\n";
        cout << "\t\t" << "***VENTA MAS***" << endl;
        cout << "NO HAY REGISTROS POR AHORA" << endl;
        system("pause");
        vistaProducto();
    }
    else
    {
        for (int i = 0;i < vectorProducto.rows(); i++)
        {
            cout << "Id_producto:" << "000000" << vectorProducto.get(i).getId_producto() << "\n";
            cout << "Nombre_producto:" << vectorProducto.get(i).getNombre_producto() << "\n";
            cout << "Origen_stock_wo_compra:" << vectorProducto.get(i).getOrigen_stock_wo_compra() << "\n";
            cout << "Precio:" << vectorProducto.get(i).getPrecio() << "\n";
            cout << "Disponibilidad_dias<:" << vectorProducto.get(i).getDisponibilidad_dias() << "\n";
            cout << "Tipo_venta_renta:" << vectorProducto.get(i).getTipo_venta_renta() << "\n";
            cout << "*****************************" << endl;
        }
        system("pause");
        system("cls");
        vistaProducto(); //corresponde a renglón 827
    }
}
Hola Isaac
