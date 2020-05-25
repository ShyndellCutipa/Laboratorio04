#include <iostream>
using namespace std;

class Curso 
{
  // miembros dato
  private:
  string nombre;
  string codigo;
  int nroAlumnos;

  public:
  //miembros función
  Curso(); //función constructor
  Curso(string nombre, string codigo, int nroAlumnos);//función constructor con argumentos
  string getNombre();
  string getCodigo();
  int getnroAlumnos();
  void setNombre(const string newNombre);
  void setCodigo (const string newCodigo);
  void setnroAlumnos (const int newnroAlumnos);
  
};

Curso::Curso()
{
    nombre = " ";
    codigo = " ";
    nroAlumnos = 0;
    //cout<<"Variable incializada correctamente"<<endl;
}

Curso::Curso(string newNombre, string newCodigo, int newnroAlumnos)
{
    nombre = newNombre;
    codigo = newCodigo;
    nroAlumnos = newnroAlumnos;
    //cout<<"Variable inicializada con argumentos"<<endl;
}


string Curso::getNombre()
{
    return nombre;
}

string Curso::getCodigo()
{
    return codigo;
}

int Curso::getnroAlumnos()
{
    return nroAlumnos;
}

void Curso::setNombre(const string newNombre)
{
    nombre = newNombre;
}

void Curso::setCodigo(const string newCodigo)
{
    codigo = newCodigo;
}

void Curso::setnroAlumnos(const int newnroAlumnos)
{
    nroAlumnos = newnroAlumnos;//this->nroAlumnos = nroAlumnos;
}

