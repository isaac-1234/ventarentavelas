#include <iostream>
#include <string>
#include <cstring>

using namespace std;
class Factura
{
private:
    int codVenta;
    string rfc_cliente;
    string nombreCli;
    string apellidosCli;
    string nombreVen;
    string apellidoVen;
    int codProducto;
    string nombre_producto;
    int cantidad;
    float precio;
    float subTotal;
    float total;
    int estado;  //posiblemente debe cambiarse a string si se refiere al status del envío y pago
public:
    void setCodVenta(int _codVenta)
    {
        codVenta = _codVenta;
    }
    void setEstado(int _estado)
    {
        estado = _estado;
    }
    void setRfc_cliente(string _rfc_cliente)
    {
        rfc_cliente = _rfc_cliente;
    }
    void setNombreCli(string _nombreCli)
    {
        nombreCli = _nombreCli;
    }
    void setApellidosCli(string _apellidosCli)
    {
        apellidosCli = _apellidosCli;
    }
    void setCodProducto(int _codProducto)
    {
        codProducto = _codProducto;
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
    int getCodVenta()
    {
        return codVenta;
    }
    int getestado()
    {
        return estado;
    }
    string getRfc_cliente()
    {
        return rfc_cliente;
    }
    string getNombreCli() { return nombreCli; }
    string getApellidosCli() { return apellidosCli; }

    int getCodProducto()
    {
        return codProducto;
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
