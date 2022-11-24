#include"../model/cliente.h"

class ClienteController{

    private:
        vector<Cliente>vectorCliente;
    public:
        ClienteController();
        Cliente getPos(int pos);
        int getSize();
        int getPosArray(Cliente obj);
        void cargarDatos();
        void add(Cliente obj);
        void addArchivo(Cliente obj);
        Cliente buscar(int dato);
        bool modificar(Cliente objOld,Cliente objModificado);
        void archivoEliminarModificar();
        void eliminar(Cliente obj);  
};
ClienteController::ClienteController(){
    cargarDatos();
}
int ClienteController::getPosArray(Cliente obj){
    for(int i=0;i<vectorCliente.size();i++){
        if(obj.getCodCliente()==vectorCliente[i].getCodCliente()){
            return i;
        }
    }
    return -1;
}
void ClienteController::cargarDatos(){

    fstream archivo;
    int i;
    size_t posi;
    string linea;
    string temporal[4];

    archivo.open("clientes.csv",ios::in);

    while(!archivo.eof() && getline(archivo,linea)){
        i=0;
        while((posi=linea.find(" "))!=string::npos){
            temporal[i]=linea.substr(0,posi);
            linea.erase(0,posi+1);
            ++i;
        }
        Cliente cliente;
        cliente.setCodCliente(stoi(temporal[0]));
        cliente.setNomApeCli(temporal[1]);
        cliente.setDirCli(temporal[2]);
        cliente.setRucCli(stoi(temporal[3]));
        add(cliente);
    }
}
Cliente ClienteController::getPos(int pos){
    return vectorCliente[pos];
}
int ClienteController::getSize(){
    return vectorCliente.size();
}
void ClienteController::add(Cliente obj){
    vectorCliente.push_back(obj);
}
void ClienteController::addArchivo(Cliente obj){

    fstream archivo;
    archivo.open("clientes.csv",ios::app);

    archivo<<obj.getCodCliente()<<" ";
    archivo<<obj.getNomApeCli()<<" ";
    archivo<<obj.getDirCli()<<" ";
    archivo<<obj.getRucCli()<<" ";
    archivo<<endl;  
}
Cliente ClienteController::buscar(int dato){

    Cliente error;
    error.setNomApeCli("Error");

    for(int i=0;i<vectorCliente.size();i++){
        if(dato==vectorCliente[i].getCodCliente()){
            return vectorCliente[i];
        }
    }
    return error;
}
bool ClienteController::modificar(Cliente objOld,Cliente objModificado){

    for(int i=0;i<vectorCliente.size();i++){
        if(objOld.getCodCliente()==vectorCliente[i].getCodCliente()){
            vectorCliente[i].setCodCliente(objModificado.getCodCliente());
            vectorCliente[i].setNomApeCli(objModificado.getNomApeCli());
            vectorCliente[i].setDirCli(objModificado.getDirCli());
            vectorCliente[i].setRucCli(objModificado.getRucCli());
            return true;
        }
    }
    return false;
}
void ClienteController::archivoEliminarModificar(){
    
    fstream archivo;
    archivo.open("clientes.csv",ios::out);

    for(Cliente x:vectorCliente){
        archivo<<x.getCodCliente()<<" ";
        archivo<<x.getNomApeCli()<<" ";
        archivo<<x.getDirCli()<<" ";
        archivo<<x.getRucCli()<<" ";
        archivo<<endl;
    }
    archivo.close();
}
void ClienteController::eliminar(Cliente obj){
    vectorCliente.erase(vectorCliente.begin()+getPosArray(obj));
}