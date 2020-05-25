#include <iostream>
#include "curso.h"
using namespace std;

class ArreglodeCursos
{
    private:
    Curso *ptr;
    int tam;

    public:

    ArreglodeCursos(const Curso cursos[], const int size);
    ArreglodeCursos(const ArreglodeCursos &o);
    ~ArreglodeCursos();
    void redimensionar(int newtam);
    void push_back(const Curso &p);
    void insert(const int pos, const Curso &p);
    void remove(const int pos);
    const int getSize();
    void clear();
    void visualizar();

};

ArreglodeCursos::ArreglodeCursos(const Curso cursos[], const int size)
{
    tam = size;
    ptr = new Curso[size];

    for (int i = 0; i < tam; i++)
        ptr[i]=cursos[i];
    
}

ArreglodeCursos::ArreglodeCursos(const ArreglodeCursos &o)
{
    tam = o.tam;
    ptr = new Curso[tam];
    for (int i = 0; i < tam; i++)
        ptr[i]=o.ptr[i];
        //*(ptr+i)=*(o.ptr+i);
    cout<<"Copia creada correctamente"<<endl;
}

ArreglodeCursos::~ArreglodeCursos()
{
    delete[] ptr;
}

void ArreglodeCursos::redimensionar(int newtam)
{
    Curso *aux = new Curso[newtam];
    int size = (tam<newtam) ? tam : newtam;
    for (int i = 0; i < size; i++)
        aux[i] = ptr[i];
    delete[] ptr;
    tam = newtam;
    ptr = aux;
}

void ArreglodeCursos::push_back(const Curso &p)
{
    this->redimensionar(tam+1);
    ptr[tam-1] = p;
}

void ArreglodeCursos::insert(const int pos, const Curso &p)
{

    this->redimensionar(tam+1);
    for (int i = tam-1; i > pos; i--)
        ptr[i] = ptr[i-1];
    ptr[pos]= p;
    
}

void ArreglodeCursos::remove(const int pos)
{
    for (int i = pos; i < tam-1; i++)
        ptr[i] = ptr[i+1];
    this->redimensionar(tam-1);
}

const int ArreglodeCursos::getSize()
{
    return tam;
}

void ArreglodeCursos::clear()
{
    Curso *aux = new Curso[0];
    delete[] ptr;
    ptr = aux;
    tam = 0;
}

void ArreglodeCursos::visualizar()
{
    for(int i=0; i<tam; i++)
    {
        cout<<ptr[i].getNombre()<<" "<<ptr[i].getCodigo()<<" "<<ptr[i].getnroAlumnos()<<endl;
    }
}

int main()
{
    Curso x("CC", "01", 25);
    Curso y("TI", "02", 20);
    Curso z("AC", "03", 36);
    Curso w("IA", "04", 154);
    //Curso tempCourses[] = {Curso ("CC", "01", 25), Curso("TI", "02", 20), Curso ("AC", "03", 36)};
    Curso tempCourses[] = {x, y ,z};

    ArreglodeCursos misCursos(tempCourses, 3);//se inicializa con un arreglo estático de la clase Curso
    ArreglodeCursos copyCursos(misCursos);//se inicializa creando una copia de la misma clase

    //cout << misCursos.ptr[0].getNombre()<<endl;
    //cout << copyCursos.ptr[2].getCodigo()<<endl;

    copyCursos.redimensionar(4);

    misCursos.push_back(x);
    
    misCursos.insert(1, w);

    misCursos.remove(0);

    /*cout<<misCursos.ptr[0].getNombre()<<endl;
    cout<<misCursos.ptr[1].getNombre()<<endl;
    cout<<misCursos.ptr[2].getNombre()<<endl;
    cout<<misCursos.ptr[3].getNombre()<<endl;*/
    cout<<"Numero de cursos: "<<misCursos.getSize()<<endl;
    cout<<"Mis cursos: "<<endl;
    misCursos.visualizar();
    misCursos.clear();
    cout<<"Numero de cursos despues de su eliminacion: "<<misCursos.getSize()<<endl;



}