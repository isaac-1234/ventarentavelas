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
                    archivoFactura << fa.getid_venta() << ";" << fa.getRfc_cliente() << ";" << fa.getnombre() << ";" << fa.getapellidos() << ";" << fa.getNombreVen() << ";" << fa.getapellidoVen() << ";" << fa.getid_producto() << ";" << fa.getnombre_producto() << ";" << fa.getcantidad() << ";" << fa.getsubTotal() << ";" << fa.gettotal() << ";" << fa.getestado() << ";" << endl;
                }
                archivoFactura.close();
            }
        }
        catch (esception e)
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
            string temporal[8];
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
                        factura.setId_venta(std::stoi(temporal[0]));
                        factura.setRfc_cliente(temporal[1]);
                        factura.setNombre(temporal[2]);
                        factura.setApellidos(temporal[3]);
                        factura.setNombreVen(temporal[4]);
                        factura.setApellidoVen(temporal[5]);
                        factura.settotal(std::stof(temporal[6]));
                        factura.setEstado(std::stoi(temporal[7]));
 
                        add(factura);
                    }
                }
            }
            archivoFactura.close();
        }
        catch(exception e)
        {
            cout << ¡"Ocurrio un ERROR al momentode leer el archivo";
        }
    }
};
 
