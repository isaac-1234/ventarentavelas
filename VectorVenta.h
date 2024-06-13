#include<iostream> #include<vector> #includ... de Silvia MDL
Silvia MDL
10:50 p. m.
#include<iostream>
#include<vector>
#include "Venta.h"
#include<fstream>
using namespace std;
using std::stof;
using std::stoi;
class VentaVector
{
protected:
    vector<Venta> vectorVenta;
public:
    VentaVector()
    {
        //cargar datos del archivo al vector();
    }
    int correlativo()
    {
        int i=0;
        try
        {
            size_t posi; //cantidad Maxima
            string linea;
            string temporal[6];
            fstream archivoVenta;
            archivoVenta.open("Venta-txt", ios::in);
            if (archivoVenta.is_open())
            {
                while (!archivoVenta.eof())
                {
                    while (getline(archivoVenta, linea))
                    {
                        i += 1;
                    }
                }
                archivoVenta.close();
            }
        }
        catch(exception e)
        {
            cout << "¡Ocurrio un ERROR al momento de leer el archivo!";
        }
        return i;
        
    }
    void agregar(Venta objeto) //agregar objetos al vector
    {
        vectorVenta.push_back(objeto);
    }
    Venta obtener(int posicion) //Entregar el objeto actual, segun la posicion pasada como parametro
    {
        return vectorVenta[posicion];
    }
    int tamanio()
    {
        return vectorVenta.size(); //cantidad total de elementos del vector
    }
    void grabarArchivo()
    {
        try
        {
            fstream archivoVenta;
            archivoVenta.open("Venta.txt", ios::app);
            if (archivoVenta.is_open())
            {
                for (Venta c : vectorVenta)
                {
                    archivoVenta << c.getFactura()<<";"<<c.getFecha()<<";"<<c.getEstatus()<<";"<<c.getId_venta()<<";"<<c.getTiempo_entrega()<<";"<<c.getId_cliente()<<";"<<c.getTotal()<<";"<< end1;
                }
                archivoVenta.close();
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
            size_t posi; //cantidad maxima
            string linea;
            string temporal[6];
            fstream archivoVenta;
            archivoVenta.open("Venta.txt", ios::in);
            if (archivoVenta.is_open())
            {
                while (!archivoVenta.eof())
                {
                    while (getline(archivoVenta, linea))
                    {
                        i= 0;
                        while((posi = linea.find(".")) != string::npos) //npos vale -1
                        {
                            temporal[i]= linea.substr(0,posi);
                            linea.erase(0, posi + 1);
                            i++;
                        }
                        //Crear un objeto tipo Cliente
                        Venta venta;
                        venta.setFactura(std::stoi(temporal[0]));
                        venta.setFecha(std::stoi(temporal[1]));
                        venta.setEstatus(std::stoi(temporal[2]));
                        venta.setId_venta(std::stoi(temporal[3]));
                        venta.setTiempo_entrega(std::stoi(temporal[4]));
                        venta.setId_cliente(std::stoi(temporal[5]));
                        venta.setTotal(std::stof(temporal[6]));
 
                        agregar(venta);
                    }
                }
            }
            archivoVenta.close();
        }
        catch(exception e)
        {
            cout << "Ocurrio un ERROR al momento de leer el archivo!";
        }
        
    }
 
};
