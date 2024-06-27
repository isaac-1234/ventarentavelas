#include <iostream>
using namespace std;
class Venta
{
private:
    int codVenta;
    string factura;
    string fecha;
    string estatus;
    int tiempo_entrega;
    int codCliente;
    float total;
public:
    Venta()
    {

    }
    ~Venta()
    {

    }
    void setcodVenta(int _codVenta)
    {
        codVenta = _codVenta;
    }
    void setFactura(string _factura)
    {
        factura = _factura;
    }
    void setFecha(string _fecha)
    {
        fecha = _fecha;
    }
    void setEstatus(string _estatus)
    {
        estatus = _estatus;
    }
    void setTiempo_entrega(int _tiempo_entrega)
    {
        tiempo_entrega = _tiempo_entrega;
    }
    void setcodCliente(int _codCliente)
    {
        codCliente = _codCliente;
    }
    void setTotal(float _total)
    {
        total = _total;
    }
    int getcodVenta()
    {
        return this->codVenta;
    }
    string getFactura()
    {
        return this->factura;
    }
    string getFecha()
    {
        return this->fecha;
    }
    string getEstatus()
    {
        return this->estatus;
    }
    int getId_venta()
    {
        return this->id_venta;
    }
    int getTiempo_entrega()
    {
        return this->tiempo_entrega;
    }
    int getcodCliente()
    {
        return this->codCliente;
    }
    float getTotal()
    {
        return this->total;
    }
};
