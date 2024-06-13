#include <vector>
#include <iostream>
#include <fstream>
#include "Login.h"
using namespace std;
class Vectorlogin
{
private:
    vector <Login> VectorLogin;
public:
 
    void Add(Login log)
    {
        VectorLogin.push_back(log);
    }
    Login Get(int pos)
    {
        return VectorLogin[pos];
    }
    int Rows()
    {
        return VectorLogin.size();
    }
    void GrabarArchivo(Login login)
    {
        try
        {
            fstream archivoLogin; //int numero
            archivoLogin.open("USUARIOS", ios::app); //ABRIR EL ARCHIVO
            if(archivoLogin.is_open())
            {
                archivoLogin<<login.getUsuario()<<"."<<login.getContrasenia()<<"."<<endl;
                archivoLogin.close();
            }
        }
        catch(exception L)
        {
            cout<<"OCURRIO UN ERROR AL GRABAR EL REGISTRO"<<endl;
        }
    }
    void guardarDatosArchivo()
    {
        try
        {
            int i;
            size_t posi; //ALMACENAR CANTIDAD MAXIMA DE UNA CADENA
            string linea;
            string temporal[2]; //NUMERO DE ATRIBUTOS DE LA CLASE
            fstream archivoLogin;
            archivoLogin.open("USUARIOS",ios::in);
            if(archivoLogin.is_open())
            {
                while(!archivoLogin.eof())
                {
                    while(getline(archivoLogin,linea))//ESTA LINEA TIENE LA FUNCION PARA QUE LOS DATOS SE GUARDEN EN LINEAS, COMO LINEA 1, CONSECUTIVAMENTE...
                    {
                        i=0;
                        while((posi = linea.find(".")) != string::npos) //ESTA FUNCION PARTE LA LINEA HASTA ENCONTRAR EL PUNTO
                        {
                            temporal[i] = linea.substr(0,posi);//
                            linea.erase(0,posi + 1);
                            i++;
                        }
                        //CREAR OBJETO VENDEDOR
                        Login login;
 
                        login.setUsuario(temporal[1]);
                        login.setContrasenia(temporal[2]);
 
                        //ESTOS DATOS GUARDADOS SE AGREGARAN A NUESTRA ADDVENDEDOR
                        Add(login);
 
                    }
                }
            }
                archivoLogin.close();
        }
        catch(exception L)
        {
            cout<<"OCURRIO UN PROBLEMA EN EL ARCHIVO"<<endl; //MINUTO 5:14
        }
    }
};
