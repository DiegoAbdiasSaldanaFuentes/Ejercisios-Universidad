# BASES DEL CODIGO

---
## Descripcion
En estas bases me explicare que usamos ya que este codigo busca las saber lo más basico para trabajar en POO en c++

---
## ENUNCIADO

Nuestra clase unica sera Libros, el cual la clase siempre debe empezar con mayuscula, Libros tendra un titulo, autor y año, pero como definimos esto?

---
### ENCAPSULACIÓN

La encapsulación es la forma en la que nosotros privatizamos nuestros atributos o los hacemos publicos, esto es de suma importancia ya que nos brinda una capa de seguridad y podemos controlar las formas en la que podemos modificar nuestros datos para lograr esto se hace lo siguiente:

```cpp
private:
    string titulo;
    string autor;
    int anio;
```
Con esto ya hemos privatizado nuestros atributos lo que significa que no podemos acceder a ellos tan facilmente desde el main, la unica forma de acceder a estos atributos seria mediante metodos

---
### CONSTRUCTORES

Los contructores permiten crear objetos en el momento que son creados y esa es la unica vez, son extremadamente importantes, si pensamos de manera más simple, digamos que nos permite definir o redireccionar la información, por ejemplo es importante o recomendable no crear constructores vacios, puede funcionar, "Si", pero no es recomendable, es de buena practica al menos crear un constructor predeterminado, por ende podemos hacer lo siguiente:

```cpp
Libro() : titulo("Sin titulo"), autor("Sin autor"), anio(0) {}
```
Y para definir un constructor normal, podemos crearlo de esta manera:

```cpp
Libro(string t, string a, int an) : titulo(t), autor(a), anio(an) {}
```
---
### GETTERS

Son accesos seguros a nuestros atributos, podremos tomar y mostrar la información de nuestros atributos aunque sean privados y es la manera correcta de llamarlo, para hacerlo debemos hacer lo siguiente:

```cpp
 string getTitulo() const { return titulo; }
```
---
### SETTERS

Aunque es este codigo no incluimos setter igual esta bien saber lo que son, los setter nos permiten definir nuestras variables, denirlas, proporcionarle o modificar nuestras varaibles para ello, hacemos lo siguiente:

```cpp
    void setAtributos(string name, float sal){
        titular = name;
        saldo = sal;
    }
```
su uso a comparación de un constructor es la de modificar, se llama en cualquie momento que deseemos.


