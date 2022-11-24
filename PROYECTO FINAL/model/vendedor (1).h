#include<iostream>
#include<conio.h>
#include<vector>
#include<fstream>
#include<stdlib.h>
using namespace std;
class Vendedor{
    private:
        int codPersonal;
        string nomApePer;
        int dniPer;
        int suePer;
        string codTipPer; 
    public:
        Vendedor();
        void setCodPersonal(int codPersonal);
        void setNomApePer(string nomApePer);
        void setDniPer(int dniPer);
        void setSuePer(int suePer);
        void setCodTipPer(string codTipPer);
        int getCodPersonal();
        string getNomApePer();
        int getDniPer();
        int getSuePer();
        string getCodTipPer();
};
Vendedor::Vendedor(){
}
void Vendedor::setCodPersonal(int codPersonal){
    this->codPersonal=codPersonal;
}
void Vendedor::setNomApePer(string nomApePer){
    this->nomApePer=nomApePer;
}
void Vendedor::setDniPer(int dniPer){
    this->dniPer=dniPer;
}
void Vendedor::setSuePer(int suePer){
    this->suePer=suePer;
}
void Vendedor::setCodTipPer(string codTipPer){
    this->codTipPer=codTipPer;
}
int Vendedor::getCodPersonal(){
    return codPersonal;
}
string Vendedor::getNomApePer(){
    return nomApePer;
}
int Vendedor::getDniPer(){
    return dniPer;
}
int Vendedor::getSuePer(){
    return suePer;
}
string Vendedor::getCodTipPer(){
    return codTipPer;
}
