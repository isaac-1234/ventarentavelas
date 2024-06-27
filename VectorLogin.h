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
            cout<<"ERROR AL GUARDAR EL REGISTRO"<<endl;
        }
    }
    void guardarDatosArchivo()
    {
        try
        {
            int i;
            size_t posi; //ALMACENAR CANTIDAD MAXIMA DE UNA CADENA
            string linea;
            string temporal[2];
            fstream archivoLogin;
            archivoLogin.open("USUARIOS",ios::in);
            if(archivoLogin.is_open())
            {
                while(!archivoLogin.eof())
                {
                    while(getline(archivoLogin,linea))//para que los datos se guarden por renglones
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

                        //LOS DATOS GUARDADOS SE AGREGAN A ADDVENDEDOR
                        Add(login);

                    }
                }
            }
                archivoLogin.close();
        }
        catch(exception L)
        {
            cout<<"OCURRIO UN PROBLEMA EN EL ARCHIVO"<<endl;
        }
    }
};
