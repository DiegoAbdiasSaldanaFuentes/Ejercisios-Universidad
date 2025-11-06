
// PIONEROS DE LA COMPUTACION
#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
using namespace std;

// Declaraciones previas
class Cientifico;
class Proyecto;
class Institucion;

// ======================= CLASE ABSTRACTA =======================
class Cientifico{
private:
    string nombre;
    string pais;
    string campoEstudio;

public:
    Cientifico(): nombre("Sin nombre"), pais("Sin pais"), campoEstudio("Sin campo"){}
    Cientifico(string n, string p, string c) : nombre(n), pais(p), campoEstudio(c){}
    virtual ~Cientifico(){}

    string getNombre() const{ 
        return nombre; 
    }

    virtual void contribucion() const = 0;
    virtual void resumen() const = 0;
};

// ======================= SUBCLASES =======================

class Matematico : public Cientifico{
public:
    Matematico() : Cientifico(){}
    Matematico(string n, string p, string c): Cientifico(n,p,c){}
    void contribucion() const override{
        cout << getNombre() << " realizo contribuciones fundamentales al desarrollo de los algoritmos matematicos." << endl;
    }
    void resumen() const override{
        cout << "[Resumen Matematico] " << getNombre() << " - Especialista en analisis y modelado numerico." << endl;
    }
};

class Ingeniero : public Cientifico{
public:
    Ingeniero() : Cientifico(){}
    Ingeniero(string n, string p, string c): Cientifico(n,p,c){}
    void contribucion() const override{
        cout << getNombre() << " aporto en la creacion de hardware y arquitectura de computadores." << endl;
    }
    void resumen() const override{
        cout << "[Resumen Ingeniero] " << getNombre() << " - Innovador en diseño y construccion de sistemas." << endl;
    }
};

class Criptografo : public Cientifico{
public:
    Criptografo() : Cientifico(){}
    Criptografo(string n, string p, string c): Cientifico(n,p,c){}
    void contribucion() const override{
        cout << getNombre() << " descifro codigos y revoluciono la criptografia moderna." << endl;
    }
    void resumen() const override{
        cout << "[Resumen Criptografo] " << getNombre() << " - Pionero en seguridad y cifrado de informacion." << endl;
    }
};

// ======================= PROYECTO =======================

class Proyecto{
private:
    string nombre;
    int anio;
    string mes;
    vector<Cientifico*> cientificos; // Agregacion
public:
    Proyecto(): nombre("Sin proyecto"), anio(0), mes("Desconocido"){}
    Proyecto(string n, int a, string m): nombre(n), anio(a), mes(m){}

    string getNombre() const{
        return nombre; 
    }

    void agregarCientifico(Cientifico* c){
        for (auto i : cientificos){
            if (i == c){
                cout << "Error: " << c->getNombre() << " ya participa en el proyecto " << nombre << endl;
                return;
            }
        }
        cientificos.push_back(c);
        cout << c->getNombre() << " agregado al proyecto " << nombre << endl;
    }

    void listarCientificos() const{
        cout<<"Proyecto: " << nombre << " (" << anio << " - " << mes << ") tiene los siguientes cientificos:" << endl;
        for (auto c : cientificos)
            cout << " - " << c->getNombre() << endl;
    }

    vector<Cientifico*> getCientificos() const{ 
        return cientificos; 
    }
};

// ======================= INSTITUCIoN =======================

class Institucion{
private:
    string nombre;
    string ubicacion;
    string descripcion;
    vector<Proyecto> proyectos; // Composicion

public:
    Institucion(): nombre("Sin institucion"), ubicacion("Sin ubicacion"), descripcion("Sin descripcion"){}
    Institucion(string n, string u, string d): nombre(n), ubicacion(u), descripcion(d){}

    void agregarProyecto(const Proyecto& p){
        proyectos.push_back(p);
    }

    void listarProyectos() const{
        cout << "Institucion: " << nombre << " (" << ubicacion << ")" << endl;
        cout << "Descripcion: " << descripcion << endl;
        cout << "Contiene los siguientes proyectos:\n";
        for (const auto& p : proyectos){
            cout << " - " << p.getNombre() << endl;
        }
    }

    void listarCientificosTotales() const{
        cout << "\nCientificos asociados a la institucion " << nombre << ":" << endl;
        vector<string> nombres;
        for (const auto& p : proyectos){
            for (auto c : p.getCientificos()){
                bool repetido = false;
                for (auto n : nombres)
                    if (n == c->getNombre()) repetido = true;
                if (!repetido){
                    nombres.push_back(c->getNombre());
                    cout << " - " << c->getNombre() << endl;
                }
            }
        }
    }
};

// ======================= MAIN =======================

int main(){

    // Crear cientificos
    Criptografo turing("Alan Turing", "Reino Unido", "Criptografia");
    Matematico ada("Ada Lovelace", "Reino Unido", "Matematicas y Fisica");
    Ingeniero neumann("John von Neumann", "Hungria", "Ingenieria y Computacion");

    // Crear proyectos
    Proyecto eniac("ENIAC", 1945, "Enero");
    Proyecto bombe("Bombe", 1940, "Febrero");

    // Agregar cientificos a proyectos
    eniac.agregarCientifico(&turing);
    eniac.agregarCientifico(&neumann);
    bombe.agregarCientifico(&turing);
    bombe.agregarCientifico(&ada);

    // Intentar agregar el mismo cientifico (error)
    bombe.agregarCientifico(&ada);

    // Crear institucion
    Institucion eniacLab("ENIAC Lab", "EE.UU.", "Laboratorio subterraneo de investigacion");
    eniacLab.agregarProyecto(eniac);
    eniacLab.agregarProyecto(bombe);

    // Mostrar informacion
    cout << "\n=== Listado de Proyectos ===\n";
    eniac.listarCientificos();
    bombe.listarCientificos();

    cout << "\n=== Contribuciones ===\n";
    turing.contribucion();
    ada.contribucion();
    neumann.contribucion();

    cout << "\n=== Resumenes ===\n";
    turing.resumen();
    ada.resumen();
    neumann.resumen();

    cout << "\n=== Informacion de la Institucion ===\n";
    eniacLab.listarProyectos();
    eniacLab.listarCientificosTotales();

    return 0;
}
