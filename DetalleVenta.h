#include <iostream>
using namespace std;
class DetalleVenta
{
private:
int codVenta;
string nombre_producto;
int codProducto;
int cantidad;
float precioVen;
public:
DetalleVenta()
{

}
~DetalleVenta()
{

}
void setcodVenta(int _codVenta)
{
    codVenta = _codVenta;
}
void setcodProducto(int _codProducto)
{
    codProducto = _codProducto;
}
void setCantidad(int _cantidad)
{
    cantidad = _cantidad;
}
void setprecioVen(float _precioVen)
{
    precioVen = _precioVen;
}
void setNombre_producto(string _nombre_producto)
{
    nombre_producto = _nombre_producto;
}
int getcodVenta()
{
    return this->codVenta;
}
int getcodProducto()
{
    return this->codProducto;
}
int getCantidad()
{
    return this->cantidad;
}
float getprecioVen()
{
    return this->precioVen;
}
float getSubTotal()
    {
        return getprecioVen() * getCantidad();
    }
string getNombre_producto()
{
    return this->nombre_producto;
}

};
