#include <iostream>
#pragma once
using namespace std;
 
class Cliente1
{
    private:
    string nombre;
    string apellidos;
    string domicilio;
    string municipio;
    string estado;
    int telefono;
    string rfc_cliente;
    string tipo_nuevo_frecuente;
    int id_cliente;
    public:
    void setNombre(string nombre)
    {
        this->nombre = nombre;
    }
    void setApellidos(string apellidos)
    {
        this->apellidos = apellidos;
    }
    void setDomicilio(string domicilio)
    {
        this->domicilio = domicilio;
    }
    void setMunicipio(string municipio)
    {
        this->municipio = municipio;
    }
    void setEstado(string estado)
    {
        this->estado = estado;
    }
    void setTelefono(int telefono)
    {
        this->telefono = telefono;
    }
    void setRfc_cliente(string rfc_cliente)
    {
        this->rfc_cliente = rfc_cliente;
    }
    void setTipo_nuevo_frecuente(string tipo_nuevo_frecuente)
    {
        this->tipo_nuevo_frecuente = tipo_nuevo_frecuente;
    }
    void setId_cliente(int id_cliente)
    {
        this->id_cliente = id_cliente;
    }
    string getNombre()
    {
        return nombre;
    }
    string getApellidos()
    {
        return apellidos;
    }
    string getDomicilio()
    {
        return domicilio;
    }
    string getMunicipio()
    {
        return municipio;
    }
    string getEstado()
    {
        return estado;
    }
    int getTelefono()
    {
        return telefono;
    }
    int getId_cliente()
    {
        return id_cliente;
    }
    string getRfc_cliente()
    {
        return rfc_cliente;
    }
    string getTipo_nuevo_frecuente()
    {
        return tipo_nuevo_frecuente;
    }
};
