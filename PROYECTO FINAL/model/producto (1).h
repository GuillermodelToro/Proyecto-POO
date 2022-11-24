#include<iostream>
#include<conio.h>
#include<vector>
#include<fstream>
#include<stdlib.h>
using namespace std;

class Producto{

    private:
        int codProducto;
        string nomPro;
        int prePro;
        int stkPro;
        string codCategoria;
    public:
        Producto();
        void setCodProducto(int codProducto);
        void setNomPro(string nomPro);
        void setPrePro(int prePro);
        void setStkPro(int stkPro);
        void setCodCategoria(string codCategoria);
        int getCodProducto();
        string getNomPro();
        int getPrePro();
        int getStkPro();
        string getCodCategoria();
};
Producto::Producto(){
}
void Producto::setCodProducto(int codProducto){
    this->codProducto=codProducto;
}
void Producto::setNomPro(string nomPro){
    this->nomPro=nomPro;
}
void Producto::setPrePro(int prePro){
    this->prePro=prePro;
}
void Producto::setStkPro(int stkPro){
    this->stkPro=stkPro;
}
void Producto::setCodCategoria(string codCategoria){
    this->codCategoria=codCategoria;
}
int Producto::getCodProducto(){
    return codProducto;
}
string Producto::getNomPro(){
    return nomPro;
}
int Producto::getPrePro(){
    return prePro;
}
int Producto::getStkPro(){
    return stkPro;
}
string Producto::getCodCategoria(){
    return codCategoria;
}