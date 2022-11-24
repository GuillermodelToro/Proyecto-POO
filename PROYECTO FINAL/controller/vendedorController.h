#include"../model/vendedor.h"

class VendedorController{

    private:
        vector<Vendedor>vectorVendedor;
    public:
        VendedorController();
        void cargarDatos();
        void addArchivo(Vendedor obj);
        void add(Vendedor obj);
        int getSize();
        Vendedor getPos(int pos);
        Vendedor buscar(int dato);
        bool modificar(Vendedor objOld,Vendedor objModificado);
        void eliminar(Vendedor obj);
        void archivoEliminarModificar(); 
        int getPosArray(Vendedor obj);  
};
VendedorController::VendedorController(){
    cargarDatos();
}
void VendedorController::cargarDatos(){
    
    fstream archivo;
    int i;
    size_t posi;
    string linea;
    string temporal[5];

    archivo.open("vendedores.csv",ios::in);

    while(!archivo.eof() && getline(archivo,linea)){
        i=0;
        while((posi=linea.find(" "))!=string::npos){
            temporal[i]=linea.substr(0,posi);
            linea.erase(0,posi+1);
            ++i;
        }
        Vendedor vendedor;
        vendedor.setCodPersonal(stoi(temporal[0]));
        vendedor.setNomApePer(temporal[1]);
        vendedor.setDniPer(stoi(temporal[2]));
        vendedor.setSuePer(stoi(temporal[3]));
        vendedor.setCodTipPer(temporal[4]);
        add(vendedor); 
    }
    
}
int VendedorController::getSize(){
    return vectorVendedor.size();
}
Vendedor VendedorController::getPos(int pos){
    return vectorVendedor[pos];
}
void VendedorController::add(Vendedor obj){
    vectorVendedor.push_back(obj);
}
void VendedorController::addArchivo(Vendedor obj){

    fstream archivo;
    archivo.open("vendedores.csv",ios::app);

    archivo<<obj.getCodPersonal()<<" ";
    archivo<<obj.getNomApePer()<<" ";
    archivo<<obj.getDniPer()<<" ";
    archivo<<obj.getSuePer()<<" ";
    archivo<<obj.getCodTipPer()<<" ";
    archivo<<endl;
}
Vendedor VendedorController::buscar(int dato){

    Vendedor error;
    error.setNomApePer("Error");

    for(int i=0;i<vectorVendedor.size();i++){
        if(dato==vectorVendedor[i].getCodPersonal()){
            return vectorVendedor[i];
        }
    }
    return error;
}
bool VendedorController::modificar(Vendedor objOld,Vendedor objModificado){

    for(int i=0;i<vectorVendedor.size();i++){
        if(objOld.getCodPersonal()==vectorVendedor[i].getCodPersonal()){
            vectorVendedor[i].setCodPersonal(objModificado.getCodPersonal());
            vectorVendedor[i].setNomApePer(objModificado.getNomApePer());
            vectorVendedor[i].setDniPer(objModificado.getDniPer());
            vectorVendedor[i].setSuePer(objModificado.getSuePer());
            vectorVendedor[i].setCodTipPer(objModificado.getCodTipPer());
            return true;
        }
    }
    return false;
}
void VendedorController::archivoEliminarModificar(){

    fstream archivo;
    archivo.open("vendedores.csv",ios::out);

    for(Vendedor x:vectorVendedor){
        archivo<<x.getCodPersonal()<<" ";
        archivo<<x.getNomApePer()<<" ";
        archivo<<x.getDniPer()<<" ";
        archivo<<x.getSuePer()<<" ";
        archivo<<x.getCodTipPer()<<" ";
        archivo<<endl;
    }
    archivo.close();
}
void VendedorController::eliminar(Vendedor obj){
    vectorVendedor.erase(vectorVendedor.begin()+getPosArray(obj));
}
int VendedorController::getPosArray(Vendedor obj){

    for(int i=0;i<vectorVendedor.size();i++){
        if(obj.getCodPersonal()==vectorVendedor[i].getCodPersonal()){
            return i;
        }
    }
    return -1;
}