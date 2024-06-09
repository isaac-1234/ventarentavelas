#include <iostream>
using namespace std;
class Venta
{
private:
    int id_venta;
    string factura;
    string fecha;
    string estatus;
    int tiempo_entrega;
    int id_cliente;
    float total;
public:
    Venta()
    {

    }
    ~Venta()
    {

    }
    void setId_venta(int _id_venta)
    {
        id_venta = _id_venta;
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
    void setId_cliente(int _id_cliente)
    {
        id_cliente = _id_cliente;
    }
    void setTotal(float _total)
    {
        total = _total;
    }
    int getId_venta()
    {
        return this->id_venta;
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
    int getId_cliente()
    {
        return this->id_cliente;
    }
    float getTotal()
    {
        return this->total;
    }
};