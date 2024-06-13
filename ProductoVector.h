#include<instream>
#include<fstream>
#include<vector>
#include"Producto.h"
using namespace std;
using std::stoi;
using std::stof;
 
class ProductoVector
{
 
private:
    vector<Producto> vectorProducto;
public:
    ProductoVector()
    {
        cargarDatosDelArchivoAlVector();
    }
    void add(Producto obj)
    {
        vectorProducto.push_back(obj);
    }
    Producto get(int pos) //EN QUE POSICION ESTARAN LOS OBJETOS
    {
        return vectorProducto[pos];
    }
    int rows()//CUANTOS VENDEDORES SE GUARDARAN EN EL VECTOR
    {
        return vectorProducto.size();
    }
    Producto buscarPorId_producto(string id_prod)//BUSCAR el PRODUCTO
    {
        Producto objError;
        objError.setNombre_producto("ERROR");
        for(Producto x : vectorProducto)
        {
            if (Id_prod) == x.getId_producto())
            {
                return x;
            }
        }
        return objError;
    }
 
    int getPostArray(Producto obj)
    {
        for(int i=0;i<rows();i++)
        {
            if(obj.getId_producto() == get(i).getId_producto())
            {
                return i;
            }
        }
        return -1;
    }
    int getCorrelativo()
    {
        if (vectorProducto.size() == 0)
        {
            return 1;
        }
        else
        {
            return vectorProducto[vectorProducto.size() - 1].getId_producto() +1;
        }
    }
    void remove(Producto obj)
    {
        vectorProducto.erase(vectorProducto.begin() _ getPostArray(obj));
    }
 
    bool modificar(Producto p, string Nombre_producto, float precio)
    {
        for (int i=0;i<rows;i++)
        {
            if (p.getId_producto() == get(i).getId_producto())
            {
                vectorProducto[i].setNombre_producto(nombre_producto);
                vectorProducto[i].setOrigen_stock_wo_compra(origen_stock_wo_compra);
                vectorProducto[i].setPrecio(precio);
                vectorProducto[i].setDisponibilidad_dias(disponibilidad_dias);
                vectorProducto[i].setTipo_venta_renta(tipo_venta_renta);
                vectorProducto[i].setId_producto(id_producto);
                vectorProducto[i].setCantidad(cantidad);
                return true;
            }
        }
        return false;
    }
    void grabarArchivo(Producto producto)
    {
        try       //PARA SABER SI HAY EXCEPCION
        {
            fstream archivoProducto; //int numero
            archivoProducto.open("PRODUCTOS.txt", ios::app)//ABRIR EL ARCHIVO
            if (archivoProducto.is_open())
            {
                archivoProducto << producto.getId_producto() << ";"<<producto.getNombre_producto()<<";"<<producto.getOrigen_stock_wo_compra()<<";"<<producto.getPrecio()<<";"<<producto.getDisponibilidad_dias()<<";"<<producto.getTipo_venta_renta()<<";"<<producto.getId_producto()<<";">>producto.getCantidad()<<";"<<endl;
                archivoProducto.close();
            }
        }
        catch (exception e)
        {
            cout << "OCURRIO UN ERROR AL GRABAR EL REGISTRO" << END1;
        }
    }
    void cargarDatosDelArchivoAlVector()
    {
        try
        {
            int i;
            size_t posi;
            string linea;
            string temporal[6];
            fstream archivoProducto;
            archivoProducto.open("PRODUCTOS.txt", ios::in);
            if (archivoProducto.is_open())
            {
                while (!archivoProducto.eof())
                {
                    while (getline(archivoProducto,linea))
                    {
                        i=0;
                        while ((posi = linea.find(";")) != string::npos)
                        {
                            temporal[i] = linea.substr(0,posi);
                            linea.erase(0, posi + 1);
                                i++
                        }
                        Producto.producto;
                        producto.setNombre_producto(std::stoi(temporal[0]));
                        producto.setOrigen_stock_wo_compra(temporal[1]);
                        producto.setDisponibilidad_dias(temporal[2]);
                        producto.setTipo_venta_renta(temporal[3]);
                        producto.setId_producto(temporal[4]);
                        producto.setCantidad(temporal[5]);
                        producto.setPrecio(std::stof(temporal[6]));
                        add(producto);
                    }
                }
            }
            archivoProducto.clase();
        }
        catch (exception e)
        {
           cout << "Ocurrio un error";
        }
    }
 
    void grabarModificarEliminarArchivo()
    {
        try
        {
            fstream archivoProducto;
            archivoProducto.open("PRODUCTOS.txt", ios::out);
            if (archivoProducto.is_open())
            {
                for (Producto x : vectorProducto)
                {
                    archivoProducto <<
                        x.getId_producto() <<";"<<x.getNombre_producto()<<";"<<x.getOrigen_stock_wo_compra()<<";"<<x.getPrecio()<<";"<<x.getDisponibilidad_dias()<<";"<<x.getTipo_venta_renta()<<";"<<x.getId_producto()<<";">>x.getCantidad()<<";"<< "\n";
                }
                archivoProducto.close();
            }
        }
        catch (exception e)
        {
            cout << "Ocurrio un error al grabar en el archivo";
        }
    }
};
