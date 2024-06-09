#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "DetalleVenta.h"
using namespace std;
using std::stof;
using std::stoi;

class DetalleVector
{
private:
    vector<DetalleVenta> detalleVector;
public:
    DetalleVector()
    {

    }
    void add(DetalleVenta obj)
    {
        detalleVector.push_back(obj);
    }
    DetalleVenta get(int pos)
    {
        return detalleVector[pos];
    }
    int rows()
    {
        return detalleVector.size();
    }

    void grabarArchivo()
    {
        try
        {
            fstream archivoDetalle;
            archivoDetalle.open("DetalleVenta.txt", ios::app);
            if (archivoDetalle.is_open())
            {
                for (DetalleVenta l : detalleVector)
                {
                    archivoDetalle << l.getId_venta() << ";" << l.getNombre_producto() << ";" << l.getId_producto() << ";" << l.getCantidad() << ";" << l.getPrecio() << ";" << endl;
                }
                archivoDetalle.close();
            }
        }
        catch(exception e)
        {
            cout << "¡ERROR AL GRABAR EL REGISTRO!";
        }
    }
    void cargarDatosDelArchivoAlVector()
    {
        try
        {
            int i;
            size_t posi; //Cantidad Maxima
            string linea;
            string temporal[5];
            fstream archivoDetalle;
            archivoDetalle.open("DetalleVenta.txt", ios::in);
            if (archivoDetalle.is_open())
            {
                while (!archivoDetalle.eof())
                {
                    while (getline(archivoDetalle, linea))
                    {
                        i=0;
                        while ((posi = linea.find(";")) != string::npos) //npos vale -1
                        {
                            temporal [i] = linea.substr(0, posi);
                            linea.erase(0, posi + 1);
                            i++;
                        }
                        //Crear un objeto tipo Cliente
                        DetalleVenta detalle;
                        detalle.setId_venta(std::stoi(temporal[0]));
                        detalle.setNombre_producto(temporal[1]);
                        detalle.setId_producto(std::stoi(temporal[2]));
                        detalle.setCantidad(std::stoi(temporal[3]));
                        detalle.setPrecio(std::stof(temporal[4]));

                        add(detalle);
                    }
                }
            }
            archivoDetalle.close();
        }
        catch(exception e)
        {
            cout << "¡Ocurrio un ERROR al momento de leer el archivo!";
        }
    }
    void grabarModificarEliminarArchivo()
    {
        try
        {
            fstream archivoDetalle;
            archivoDetalle.open("DetalleVenta.txt", ios::out);
            if (archivoDetalle.is_open())
            {
                for(DetalleVenta x : detalleVector)
                {
                    archivoDetalle << x.getId_venta() <<"." <<x.getId_producto() << "." << x.getCantidad() << "." << x.getPrecio() << "." << "\n";
                }
                archivoDetalle.close();
            }
        }
        catch(exception e)
        {
            cout << "Ocurrio un error al grabar en el archivo";
        }
    }
    void listarProdVector(DetalleVenta obj){
        cout << "Codigo del producto: " << obj.getId_producto() << endl;
        cout << "Cantidad del producto: " << obj.getCantidad() << endl;
        cout << "Subtotal: " << obj.getSubTotal() << endl;
    }
};