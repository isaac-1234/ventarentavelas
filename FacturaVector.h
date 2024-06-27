#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "Factura.h"
using namespace std;
using std::stof;
using std::stoi;
class FacturaVector
{
private:
    vector<Factura> facturaVector;
public:
    FacturaVector()
    {

    }
    void add(Factura obj)
    {
        facturaVector.push_back(obj);
    }
    Factura get(int pos)
    {
        return facturaVector[pos];
    }
    int rows()
    {
        facturaVector.size();
    }
    void grabarArchivo(Factura factura)
    {
        try
        {
            fstream archivoFactura;
            archivoFactura.open("Factura.txt", ios::app);
            if (archivoFactura.is_open())
            {
                for (Factura fa : facturaVector)
                {
                    archivoFactura << fa.getCodVenta() << ";" << fa.getRfc_cliente() << ";" << fa.getNombreCli() << ";" << fa.getApellidosCli() << ";" << fa.getCodProducto() << ";" << fa.getnombre_producto() << ";" << fa.getcantidad() << ";" << fa.getsubTotal() << ";" << fa.gettotal() << ";" << fa.getestado() << ";" << endl;
                }
                archivoFactura.close();
            }
        }
        catch (exception e)
        {
            cout << "¡ERROR AL GRABAR EL REGISTRO!";
        }
    }
    void cargarDatosDelArchivoAlVector()
    {
        try
        {
            int i;
            size_t posi; //es la cantidad maxima de conceptos
            string linea;
            string temporal[6];
            fstream archivoFactura;
            archivoFactura.open("Factura.txt", ios::in);
            if (archivoFactura.is_open())
            {
                while (!archivoFactura.eof())
                {
                    while (getline(archivoFactura, linea))
                    {
                        i=0;
                        while ((posi = linea.find(";")) != string::npos)
                        {
                            temporal[i] = linea. substr(0, posi);
                            linea.erase(0, posi + 1);
                            i++;
                        }
                        Factura factura;
                        factura.setCodVenta(std::stoi(temporal[0]));
                        factura.setRfc_cliente(temporal[1]);
                        factura.setNombreCli(temporal[2]);
                        factura.setApellidosCli(temporal[3]);
                        factura.settotal(std::stof(temporal[4]));
                        factura.setEstado(std::stoi(temporal[5]));

                        add(factura);
                    }
                }
            }
            archivoFactura.close();
        }
        catch(exception e)
        {
            cout << "¡Ocurrio un ERROR al momentode leer el archivo";
        }
    }
};

 
