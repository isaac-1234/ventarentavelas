#include <iostream>
using namespace std;
class DetalleVenta
{
private:
string id_venta;
string nombre_producto;
string id_producto;
int cantidad;
float precio;
public:
DetalleVenta()
{
 
}
~DetalleVenta()
{
 
}
void setId_venta(int _id_venta)
{
    id_venta = _id_venta;
}
void setId_producto(string _id_producto)
{
    id_producto = _id_producto;
}
void setCantidad(int _cantidad)
{
    cantidad = _cantidad;
}
void setPrecio(float _precio)
{
    precio = _precio;
}
void setNombre_producto(string _nombre_producto)
{
    nombre_producto = _nombre_producto;
}
string getId_venta()
{
    return this->id_venta;
}
string getId_producto()
{
    return this->id_producto;
}
int getCantidad()
{
    return this->cantidad;
}
float getPrecio()
{
    return this->precio;
}
float getSubTotal()
    {
        return getPrecio() * getCantidad();
    }
string getNombre_producto()
{
    return this->nombre_producto;
}
 
};
