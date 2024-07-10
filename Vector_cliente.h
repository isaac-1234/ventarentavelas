#pragma once
#include<iostream>
#include<vector>
#include"Cliente1.h"
#include<fstream>
#include "DetalleVector.h"
#include "ProductoVector.h"
#include "VectorVenta.h"

using std::stoi;
using namespace std;

class ClienteVector
{
private:
    vector<Cliente1> vectorCliente;
public:
    ClienteVector()
    {
        cargarDatosDelArchivoAlVector();
        vector<Cliente1> vectorCliente;
    }
    int getCorrelativo()
    {
        if(vectorCliente.size()==0)
        {
            return 1;
        }
        else
        {
            return vectorCliente[vectorCliente.size() - 1].getId_cliente() + 1;
        }
    }
    void agregar(Cliente1 objeto) /*agregar objetos al vector*/
    {
        vectorCliente.push_back(objeto);
    }
    Cliente1 obtener(int posicion) /*obtiene el objeto actual, usando la posicion pasada como paramentro*/
    {
        return vectorCliente[posicion];
    }
    int tamanio()
    {
        return vectorCliente.size(); /*Cantidad total de elementos del vector*/
    }
    Cliente1 buscarPorId_cliente(int cod)//buscar posicion
    {
        Cliente1 objError;
        objError.setNombre("Error");
        for(int i=0; i<tamanio();i++)
        {
            if(cod == obtener(i).getId_cliente())
            {
                return obtener(i);
            }
        }
        return objError;
    }
        
    int getPostArray(Cliente1 objeto)//pasar posicion
    {
        for(int i=0; i<tamanio();i++)
        {
            if(objeto.getId_cliente() == vectorCliente[i].getId_cliente())
            {
                return i;
            }
        }
        return -1;
    }
    void eliminar(Cliente1 objeto) //eliminar objeto
    {
        vectorCliente.erase(vectorCliente.begin() + getPostArray(objeto));
    }
    bool modificar(Cliente1 objeto, string Name, string lastName, string Adress, string City, string State, string Phone, string Cust_rfc, string Kind_new_often)
    {
        for(int i=0;i<tamanio();i++)
        {
            if(objeto.getId_cliente() == obtener(i).getId_cliente())
            {
                vectorCliente[i].setNombre(Name);
                vectorCliente[i].setApellidos(lastName);
                vectorCliente[i].setDomicilio(Adress);
                vectorCliente[i].setMunicipio(City);
                vectorCliente[i].setEstado(State);
                vectorCliente[i].setTelefono(Phone);
                vectorCliente[i].setRfc_cliente(Cust_rfc);
                vectorCliente[i].setTipo_nuevo_frecuente(Kind_new_often);
                return true;
            }
        }
        return false;
    }
    void grabarEnArchivo(Cliente1 cliente)
    {
        try
        {        
            fstream archivoCliente;
            archivoCliente.open("DATOS DE LOS CLIENTES.txt",ios::app);
            if(archivoCliente.is_open())
            {
                archivoCliente<<cliente.getId_cliente()<<";"<<cliente.getNombre()<<";"<<cliente.getApellidos()<<";"<<cliente.getDomicilio()<<";"<<cliente.getMunicipio()<<";"<<cliente.getEstado()<<";"<<cliente.getTelefono()<<";"<<cliente.getRfc_cliente()<<";"<<cliente.getTipo_nuevo_frecuente()<<";"<<endl;
                archivoCliente.close();
            }
        }
        catch(exception e)
        {
            cout<<"¡ERROR AL GRABAR EL REGISTRO!";
        }
    }
    void cargarModificado()
    {
        try
        {
            fstream archivoCliente;
            archivoCliente.open("DATOS DE LOS CLIENTES.txt", ios::out);
            if(archivoCliente.is_open())
            {
                for(Cliente1 z: vectorCliente)
                {
                        archivoCliente<<z.getId_cliente()<<";"<<z.getNombre()<<";"<<z.getApellidos()<<";"<<z.getDomicilio()<<";"<<z.getMunicipio()<<";"<<z.getEstado()<<";"<<z.getTelefono()<<";"<<z.getRfc_cliente()<<";"<<z.getTipo_nuevo_frecuente()<<";"<<endl;
                }
                archivoCliente.close();
            }
        }
        catch(exception e)
        {
            cout<<"¡ERROR AL GRABAR EL REGISTRO!";
        }
    }
    void cargarDatosDelArchivoAlVector()
    {
        try
        {
            int i;
            size_t posi; //Candidad maxima
            string linea;
            string temporal[9];
            fstream archivoCliente;
            archivoCliente.open("DATOS DE LOS CLIENTES.txt",ios::in);
            if(archivoCliente.is_open())
            {
                while(!archivoCliente.eof())
                {
                    while(getline(archivoCliente,linea))
                    {
                        i=0;
                        while((posi = linea.find(";")) != string::npos) //npos vale -1
                        {
                            temporal[i] = linea.substr(0,posi);
                            linea.erase(0, posi + 1);
                            i++;
                        }
                        //crear un objeto tipo Cliente
                        Cliente1 cliente;
                        cliente.setId_cliente(std::stoi(temporal[0]));
                        cliente.setNombre(temporal[1]);
                        cliente.setApellidos(temporal[2]);
                        cliente.setDomicilio(temporal[3]);
                        cliente.setMunicipio(temporal[4]);
                        cliente.setEstado(temporal[5]);
                        cliente.setTelefono(temporal[6]);
                        cliente.setRfc_cliente(temporal[7]);
                        cliente.setTipo_nuevo_frecuente(temporal[8]);

                        agregar(cliente);
                    }
                }
            }
            archivoCliente.close();
        }
        catch(exception e)
        {
            cout<<"¡Ocurrio un ERROR al momento de leer el archivo!";
        }
    }
};
