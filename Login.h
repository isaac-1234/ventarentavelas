#include <iostream>
using namespace std;
class Login
{
private:
    string usuario;
    string contrasenia;
public:
    Login()
    {
 
    }
    ~Login()
    {
 
    }
    void setUsuario(string _usuario)
    {
    usuario = _usuario;
    }
    void setContrasenia(string _contrasenia)
    {
        contrasenia = _contrasenia;
    }
    string getUsuario()
    {
        return this -> usuario;
    }
    string getContrasenia()
    {
        return this -> contrasenia;
    }
};
