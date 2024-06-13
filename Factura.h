#include <iostream>
#include <string>
#include <cstring>
 
using namespace std;
class Factura
{
private:
    int id_venta;
    string Rfc_cliente;
    string nombre;
    string apellidos;
    string nombreVen;
    string apellidoVen;
    string id_producto;
    string nombre_producto;
    int cantidad;
    float precio;
    float subTotal;
    float total;
    int estado;  //posiblemente debe cambiarse a string si se refiere al status del envío y pago
public:
    void setId_venta(int _id_venta)
    {
        id_venta = _id_venta;
    }
    void setEstado(int _estado)
    {
        estado = _estado;
    }
    void setRfc_cliente(string _rfc_cliente)
    {
        Rfc_cliente = _rfc_cliente;
    }
    void setNombre(string _nombre)
    {
        nombre = _nombre;
    }
    void setApellidos(string _apelidos)
    {
        apellidos = _apelidos;
    }
    void setNombreVen(string _nombreVen)
    {
        nombreVen = _nombreVen
    }
    void setApellidoVen(string _apellidoVen)
    {
        apellidosVen = _apellidosVen;
    }
    void setid_producto(string _id_producto)
    {
        id_producto = _id_producto;
    }
    void setnombre_producto(string _nombre_producto)
    {
        nombre_producto = _nombre_producto;
    }
    void setcantidad(int _cantidad)
    {
        cantidad = _cantidad;
    }
    void setsubTotal(float _subtotal)
    {
        subTotal = _subtotal;
    }
    void settotal(float _total)
    {
        total = _total;
    }
    int getid_venta()
    {
        return id_venta;
    }
    int getestado()
    {
        return estado;
    }
    string getRfc_cliente()
    {
        return Rfc_cliente;
    }
    string getnombre() { return nombre; }
    string getapellidos() { return apellidos; }
    string getNombreVen() { return nombreVen; }
    string getapellidoVen() { return apellidoVen}
    int getid_producto()
    {
        return id_producto;
    }
    string getnombre_producto()
    {
        return nombre_producto;
    }
    int getcantidad()
    {
        return cantidad;
    }
    float getprecio()
    {
        return precio;
    }
    float getsubTotal()
    {
        return subTotal;
    }
    float gettotal()
    {
        return total;
    }
};
