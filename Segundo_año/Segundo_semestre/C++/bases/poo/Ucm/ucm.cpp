#include <iostream>
#include <string>
using namespace std;

class Funcionario{
public:
    string nombre;
    int anios_servicio;
    string titulo;

    void setNombre(string nom){
        nombre = nom;
    }

    void setAnio(int anio){
        anios_servicio = anio;
    }

    void setTitulo(string titu){
        titulo = titu;
    }

    string getNombre(){
        return nombre;
    }

    int getAnio(){
        return anios_servicio;
    }

    string getTitulo(){
        return titulo;
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

    void setCateg(string cat){
        categoria_academica = cat;
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
    Funcionario Renato;
    Renato.setNombre("Renato");
    Renato.setAnio(1);
    Renato.setTitulo("Ingeniero en Geomensura");  
    cout<<"El nombre del funcionario es " <<Renato.getNombre()<<endl;
    cout<<"El Titulo del funcionaro es: " <<Renato.getTitulo()<<endl;
    cout<<"Los anios de servicio " <<Renato.getAnio()<<endl;
    Renato.reuniones();
    Renato.colar();

    cout<<endl;

    Academico Hugo;
    Hugo.setNombre("Hugo");
    Hugo.setAnio(30);
    Hugo.setTitulo("Profesor de Matematicas y Computacion");
    Hugo.setCateg("Auxiliar");
    cout<<"El nombre del Academico es: "<<Hugo.getNombre()<<endl;
    cout<<"Los anios de servicio del academico son: " <<Hugo.getAnio()<<" Anios"<<endl;
    cout<<"El titulo del Academico es: " <<Hugo.getTitulo()<<endl;
    Hugo.administracion();






}