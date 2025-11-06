#include <iostream>
#include <string>
using namespace std;

class Funcionario{
public:
    string nombre;
    int anios_servicio;
    string titulo;


    Funcionario(string nom,int anio,string titu){
        nombre = nom;
        anios_servicio = anio;
        titulo = titu;
    }


    string mostrarDatos(){
        return "\n Nombre: ",nombre ,"\n Años de servicio: ",anios_servicio,"\n Titulo: ", titulo;
    }

    void reuniones(){
        cout<<"El funcionario "<<nombre<<" fue a una reunion"<<endl;
    }

    void colar(){
        cout<<"El funcionario "<<nombre<<" esta almorzando"<<endl;
    }

};

class Academico : public Funcionario{
public:
    string categoria_academica;

    Academico(string nom, int anio, string titu, string cat) : Funcionario(nom,anio,titu){
    categoria_academica=cat;
}


    string getCat(){
        return categoria_academica;
    }

    void docencia(){
        cout<<"El academico "<<nombre<<" esta impartiendo clases"<<endl;
    }

    void investigacion(){
        cout<<"El academico "<<nombre<<" esta realizando una investigacion"<<endl;
    }

    void vinculacion(){
        cout<<"El academico "<< nombre<<" esta vinculando"<<endl;
    }

    void administracion(){
        cout<<"El academico "<<nombre<<" esta administrando"<<endl;
    }

};


int main(){


}