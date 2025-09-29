//Hecho por: Diego Saldaña y Victor Farias

#include <iostream>
#include <string>
using namespace std;

class Persona{
    private:
    string nombre;
    string telefono;
    string contrasena;
    public:

    Persona(string nom, string tel, string cont){
        nombre = nom;
        telefono = tel;
        contrasena = cont;
    }

    string getContra(){
        return contrasena;
    }

    void cambiarContra(string cam){
        contrasena = cam;
    }

    string obtenerContraCod(string cam){
        string contraseg = cam;
        for(int i = 0; i < contraseg.length(); i++ ){
            contraseg[i] += 1;
        }
        return contraseg;

    }

    bool verificarContra(string intento){
        cout<<intento<<endl;
        if(contrasena == intento){
            return true;
        }
        else{
            return false;
        }
    }

    string mostrarDatos() const{
        return "\nNombre: "+ nombre+"\nNumero: "+telefono+"\nContrasena: "+contrasena;
    }
};

int main(){
    Persona diego("Diego","938708082","ola1234");
    cout<<diego.mostrarDatos()<<endl;
    diego.cambiarContra("nueva clave");
    cout<<"contraseña nueva"<<diego.getContra()<<endl;


    return 0;
}