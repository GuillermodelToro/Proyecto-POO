#include<iostream>
#include<conio.h>
#include<vector>
#include<fstream>
#include<stdlib.h>
using namespace std;
class DetalleVenta{
    private:
        int codVenta;
        int codProducto;
        int cantidad;
        int precioVenta;
    public:
        DetalleVenta();
        void setCodVenta(int codVenta);
        void setCodProducto(int codProducto);
        void setCantidad(int cantidad);
        void setPrecioVenta(int precioVenta);
        int getCodVenta();
        int getCodProducto();
        int getCantidad();
        int getPrecioVenta();
        int PrecioVenta(int p,int cant);
};
DetalleVenta::DetalleVenta(){
}
void DetalleVenta::setCodVenta(int codVenta){
    this->codVenta=codVenta;
}
void DetalleVenta::setCodProducto(int codProducto){
    this->codProducto=codProducto;
}
void DetalleVenta::setCantidad(int cantidad){
    this->cantidad=cantidad;
}
void DetalleVenta::setPrecioVenta(int precioVenta){
    this->precioVenta=precioVenta;
}
int DetalleVenta::getCodVenta(){
    return codVenta;
}
int DetalleVenta::getCodProducto(){
    return codProducto;
}
int DetalleVenta::getCantidad(){
    return cantidad;
}
int DetalleVenta::getPrecioVenta(){
    return precioVenta;
}
int DetalleVenta::PrecioVenta(int p,int cant){
    return cant*p;
}