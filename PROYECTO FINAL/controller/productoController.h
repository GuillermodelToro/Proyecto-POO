#include"../model/producto.h"

class ProductoController{

    private:
        vector<Producto>vectorProducto;
    public:
        ProductoController();
        void cargarDatos();
        void addArchivo(Producto obj);
        void add(Producto obj);
        int getSize();
        Producto getPos(int pos);
        Producto buscar(int dato);
        bool modificar(Producto objOld,Producto objModificado);
        void eliminar(Producto obj);
        void archivoEliminarModificar(); 
        int getPosArray(Producto obj);  
};
ProductoController::ProductoController(){
    cargarDatos();
}
void ProductoController::cargarDatos(){
    
    fstream archivo;
    int i;
    size_t posi;
    string linea;
    string temporal[5];

    archivo.open("productos.csv",ios::in);

    while(!archivo.eof() && getline(archivo,linea)){
        i=0;
        while((posi=linea.find(" "))!=string::npos){
            temporal[i]=linea.substr(0,posi);
            linea.erase(0,posi+1);
            ++i;
        }
        Producto producto;
        producto.setCodProducto(stoi(temporal[0]));
        producto.setNomPro(temporal[1]);
        producto.setPrePro(stoi(temporal[2]));
        producto.setStkPro(stoi(temporal[3]));
        producto.setCodCategoria(temporal[4]);
        add(producto); 
    }
}
int ProductoController::getSize(){
    return vectorProducto.size();
}
Producto ProductoController::getPos(int pos){
    return vectorProducto[pos];
}
void ProductoController::add(Producto obj){
    vectorProducto.push_back(obj);
}
void ProductoController::addArchivo(Producto obj){

    fstream archivo;
    archivo.open("productos.csv",ios::app);

    archivo<<obj.getCodProducto()<<" ";
    archivo<<obj.getNomPro()<<" ";
    archivo<<obj.getPrePro()<<" ";
    archivo<<obj.getStkPro()<<" ";
    archivo<<obj.getCodCategoria()<<" ";
    archivo<<endl;
}
Producto ProductoController::buscar(int dato){

    Producto error;
    error.setNomPro("Error");

    for(int i=0;i<vectorProducto.size();i++){
        if(dato==vectorProducto[i].getCodProducto()){
            return vectorProducto[i];
        }
    }
    return error;
}
bool ProductoController::modificar(Producto objOld,Producto objModificado){

    for(int i=0;i<vectorProducto.size();i++){
        if(objOld.getCodProducto()==vectorProducto[i].getCodProducto()){
            vectorProducto[i].setCodProducto(objModificado.getCodProducto());
            vectorProducto[i].setNomPro(objModificado.getNomPro());
            vectorProducto[i].setPrePro(objModificado.getPrePro());
            vectorProducto[i].setStkPro(objModificado.getStkPro());
            vectorProducto[i].setCodCategoria(objModificado.getCodCategoria());
            return true;
        }
    }
    return false;
}
void ProductoController::archivoEliminarModificar(){

    fstream archivo;
    archivo.open("productos.csv",ios::out);

    for(Producto x:vectorProducto){
        archivo<<x.getCodProducto()<<" ";
        archivo<<x.getNomPro()<<" ";
        archivo<<x.getPrePro()<<" ";
        archivo<<x.getStkPro()<<" ";
        archivo<<x.getCodCategoria()<<" ";
        archivo<<endl;
    }
    archivo.close();
}
void ProductoController::eliminar(Producto obj){
    vectorProducto.erase(vectorProducto.begin()+getPosArray(obj));
}
int ProductoController::getPosArray(Producto obj){

    for(int i=0;i<vectorProducto.size();i++){
        if(obj.getCodProducto()==vectorProducto[i].getCodProducto()){
            return i;
        }
    }
    return -1;
}