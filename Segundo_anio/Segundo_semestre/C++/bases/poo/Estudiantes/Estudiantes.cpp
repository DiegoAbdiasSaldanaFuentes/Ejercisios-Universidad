#include <iostream>
#include <string>

class Estudiantes{
    private:
        std::string nombre;
        int edad = 0;
        float nota =0;
    
    public:
    void setAtributos(std::string nom,int eda,float no){
        nombre = nom;
        edad = eda;
        nota = no;
    }

    std::string getNombre(){
        return nombre;
    }

    int getEdad(){
        return edad;
    }

    float getNota(){
        return nota;
    }

    bool Aprobado(){
        if(nota >= 4.0){
            return true;
        }else{
            return false;
        }
    }



};



int main(){

    Estudiantes estudiante1;

    estudiante1.setAtributos("Diego",19,7.0);
    std::cout<<"Nombre:"<<estudiante1.getNombre()<<std::endl;
    std::cout<<"Edad:"<<estudiante1.getEdad()<<std::endl;
    std::cout<<"Nota:"<<estudiante1.getNota()<<std::endl;

    if(estudiante1.Aprobado()){
        std::cout<<"Alumno Aprobado"<<std::endl;
    }else{
        std::cout<<"Alumno Reprobado"<<std::endl;
    }



    return 0;
}