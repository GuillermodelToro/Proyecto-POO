#include<iostream>
#include<conio.h>
#include<vector>
#include<fstream>
#include<stdlib.h>
using namespace std;
class Venta{
    private:
        int codVenta;
        int fechaVenta;
        int codPersonal;
        int totVenta;
        bool estVenta;
        int codCliente;
    public:
        Venta();
        void setCodVenta(int codVenta);
        void setFechaVenta(int fechaVenta);
        void setcodPersonal(int codPersonal);
        void setTotVenta(int totVenta);
        void setEstVenta(bool estVenta);
        void setCodCliente(int codCliente);
        int getCodVenta();
        int getFechaVenta();
        int getcodPersonal();
        int getTotVenta();
        bool getEstVenta();
        int getCodCliente();   
        string estado();
        void fecha(); 
};
Venta::Venta(){
}
void Venta::setCodVenta(int codVenta){
    this->codVenta=codVenta;
}
void Venta::setFechaVenta(int fechaVenta){
    this->fechaVenta=fechaVenta;
}
void Venta::setcodPersonal(int codPersonal){
    this->codPersonal=codPersonal;
}
void Venta::setTotVenta(int totVenta){
    this->totVenta=totVenta;
}
void Venta::setEstVenta(bool estVenta){
    this->estVenta=estVenta;
}
void Venta::setCodCliente(int codCliente){
    this->codCliente=codCliente;
}
int Venta::getCodVenta(){
    return codVenta;
}
int Venta::getFechaVenta(){
    return fechaVenta;
}
int Venta::getcodPersonal(){
    return codPersonal;
}
int Venta::getTotVenta(){
    return totVenta;
}
bool Venta::getEstVenta(){
    return estVenta;
}
int Venta::getCodCliente(){
    return codCliente;
}
string Venta::estado(){
    if(estVenta==true){
        return "Activa";
    }
    else{
        return "Oculta";
    }
}
void Venta::fecha(){
    int dia;
	int mes;
	int a;    
    dia= fechaVenta/1000000;
	mes= (fechaVenta%1000000)/10000;
	a= fechaVenta%10000;
	cout<<dia<<"/"<<mes<<"/"<<a<<endl;
}