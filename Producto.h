#include<string>
using namespace std;
 
class Producto
{
private:
    string nombre_producto;
    string origen_stock_wo_compra;
    float precio;
    int disponibilidad_dias;
    string tipo_venta_renta;
    string id_producto;
    int cantidad;
public:
    Producto()
    {
 
    }
    ~Producto()
    {
 
    }
    void setCantidad(int cantidad){
        this->cantidad = cantidad;
    }
    void setId_producto(string id_producto)
    {
        this->id_producto = id_producto;
    }
    void setNombre_producto(string nombre_producto)
    {
        this->nombre_producto = nombre_producto;
    }
    void setOrigen_stock_wo_compra(string origen_stock_wo_compra)
    {
        this->origen_stock_wo_compra = origen_stock_wo_compra;
    }
    void setPrecio(float precio)
    {
        this->precio = precio;
    }
    void setDisponibilidad_dias(int disponiblidad_dias)
    {
        this->disponibilidad_dias = disponibilidad_dias;
    }
    void setTipo_venta_renta(string tipo_venta_renta)
    {
        this->tipo_venta_renta = tipo_venta_renta;
    }
        int getCantidad()
    {
        return this->cantidad;
    }
    string getNombre_producto()
    {
        return this->nombre_producto;
    }
    string getOrigen_stock_wo_compra()
    {
        return this->origen_stock_wo_compra;
    }
    float getPrecio()
    {
        return this->precio;
    }
    string getTipo_venta_renta()
    {
        return this->tipo_venta_renta;
    }
    int getDisponibilidad_dias()
    {
        return this->disponibilidad_dias;
    }
    string getId_producto()
    {
        return this->id_producto;
    }
};
