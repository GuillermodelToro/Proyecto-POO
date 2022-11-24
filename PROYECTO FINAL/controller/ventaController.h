#include"../model/venta.h"
class VentaController{
    private:
        vector<Venta>vectorVenta;
    public:
        VentaController();
        void cargarDatos();
        void addArchivo(Venta obj);
        void add(Venta obj);
        int getSize();
        int codigo();
        Venta getPos(int pos);
        Venta buscar(int dato);
        void archivoEliminarModificar();
        void anular(Venta obj);          
};
VentaController::VentaController(){
    cargarDatos();
}
void VentaController::cargarDatos(){
    fstream archivo;
    int i;
    size_t posi;
    string linea;
    string temporal[6];

    archivo.open("ventas.csv",ios::in);

    while(!archivo.eof() && getline(archivo,linea)){
        i=0;
        while((posi=linea.find(" "))!=string::npos){
            temporal[i]=linea.substr(0,posi);
            linea.erase(0,posi+1);
            ++i;
        }
        Venta venta;
        venta.setCodVenta(stoi(temporal[0]));
        venta.setFechaVenta(stoi(temporal[1]));
        venta.setcodPersonal(stoi(temporal[2]));
        venta.setTotVenta(stoi(temporal[3]));
        bool b;
        string estado;
        if(estado=="1"){
            b=true;
        }
        else if(estado=="0"){
            b=false;
        }
        venta.setEstVenta(b);
        venta.setCodCliente(stoi(temporal[5]));
        add(venta); 
    }
}
int VentaController::getSize(){
    return vectorVenta.size();
}
Venta VentaController::getPos(int pos){
    return vectorVenta[pos];
}
void VentaController::add(Venta obj){
    vectorVenta.push_back(obj);
}
int VentaController::codigo(){
    
	if(getSize()==0){
		return 1;
	}
	else{
		return vectorVenta[getSize()-1].getCodVenta()+1;
	}
}
void VentaController::addArchivo(Venta obj){

    fstream archivo;
    archivo.open("ventas.csv",ios::app);

    archivo<<obj.getCodVenta()<<" ";
    archivo<<obj.getFechaVenta()<<" ";
    archivo<<obj.getcodPersonal()<<" ";
    archivo<<obj.getTotVenta()<<" ";
    archivo<<obj.getEstVenta()<<" ";
    archivo<<obj.getCodCliente()<<" ";
    archivo<<endl;
}
void VentaController::archivoEliminarModificar(){

    fstream archivo;
    archivo.open("ventas.csv",ios::out);

    for(Venta x:vectorVenta){
        archivo<<x.getCodVenta()<<" ";
        archivo<<x.getFechaVenta()<<" ";
        archivo<<x.getcodPersonal()<<" ";
        archivo<<x.getTotVenta()<<" ";
        archivo<<x.getEstVenta()<<" ";
        archivo<<x.getCodCliente()<<" ";
        archivo<<endl;
    }
    archivo.close();
}
Venta VentaController::buscar(int dato){
	Venta error;
	error.setCodVenta(0);
	int superior,inferior,mitad;
	inferior =0;
	superior = getSize();
	mitad = (inferior + superior)/2;
	while(inferior<=superior){
		if(getPos(mitad).getCodVenta()==dato){
			return vectorVenta[mitad];
			break;
		}
		if(getPos(mitad).getCodVenta()>dato){
			superior = mitad - 1;
		}
		if(getPos(mitad).getCodVenta()<dato){
			inferior = mitad + 1;
		}
		mitad = (inferior + superior)/2;
	}
		return error;
}
void VentaController::anular(Venta obj){
    for(int i=0;i<getSize();i++){
		if(getPos(i).getCodVenta()==obj.getCodVenta()){
			getPos(i).setEstVenta(false); 
		}
	}
}