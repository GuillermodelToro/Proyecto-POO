#include"../model/detalleventa.h"
class DetalleVentaController{
    private:
        vector<DetalleVenta>vectorDetalleVenta;
    public:
        DetalleVentaController();
        void cargarDatos();
        void addArchivo(DetalleVenta obj);
        void add(DetalleVenta obj);
        int getSize(); 
        DetalleVenta getPos(int pos);
        DetalleVenta busquedaVenta(int b);
        DetalleVenta busquedaProducto(int b);
        void eliminar(int codVenta,int codProducto,int cantEliminada);
        void archivoEliminarModificar();

};
DetalleVentaController::DetalleVentaController(){
    cargarDatos();
}
void DetalleVentaController::cargarDatos(){
    fstream archivo;
    int i;
    size_t posi;
    string linea;
    string temporal[4];

    archivo.open("detalleventas.csv",ios::in);

    while(!archivo.eof() && getline(archivo,linea)){
        i=0;
        while((posi=linea.find(" "))!=string::npos){
            temporal[i]=linea.substr(0,posi);
            linea.erase(0,posi+1);
            ++i;
        }
        DetalleVenta detalleventa;
        detalleventa.setCodVenta(stoi(temporal[0]));
        detalleventa.setCodProducto(stoi(temporal[1]));
        detalleventa.setCantidad(stoi(temporal[2]));
        detalleventa.setPrecioVenta(stoi(temporal[3]));
        add(detalleventa); 
    }
}
void DetalleVentaController::addArchivo(DetalleVenta obj){
    fstream archivo;
    archivo.open("detalleventas.csv",ios::app);

    archivo<<obj.getCodVenta()<<" ";
    archivo<<obj.getCodProducto()<<" ";
    archivo<<obj.getCantidad()<<" ";
    archivo<<obj.getPrecioVenta()<<" ";
    archivo<<endl;
}
void DetalleVentaController::add(DetalleVenta obj){
    vectorDetalleVenta.push_back(obj);
}
int DetalleVentaController::getSize(){
    return vectorDetalleVenta.size();
}
DetalleVenta DetalleVentaController::getPos(int pos){
    return vectorDetalleVenta[pos];
}
void DetalleVentaController::archivoEliminarModificar(){
    fstream archivo;
    archivo.open("detalleventas.csv",ios::out);

    for(DetalleVenta x:vectorDetalleVenta){
        archivo<<x.getCodVenta()<<" ";
        archivo<<x.getCodProducto()<<" ";
        archivo<<x.getCantidad()<<" ";
        archivo<<x.getPrecioVenta()<<" ";
        archivo<<endl;
    }
    archivo.close();
}
DetalleVenta DetalleVentaController::busquedaVenta(int b){
    DetalleVenta objError;
	objError.setCodVenta(0);
	int superior,inferior,mitad;
	inferior=0;
	superior=getSize();
	mitad=(inferior+superior)/2;
	while(inferior<=superior){
		while(inferior<=superior){
			if(getPos(mitad).getCodVenta()==b){
				return vectorDetalleVenta[mitad];
				break;
			}
			if(getPos(mitad).getCodVenta()>b){
				superior=mitad-1;
			}
			if(getPos(mitad).getCodVenta()<b){
				inferior=mitad+1;
			}
			mitad=(inferior+superior)/2;
		}
		return objError;
	}
    return objError;
}
DetalleVenta DetalleVentaController::busquedaProducto(int b){
    DetalleVenta objError;
	objError.setCodProducto(0);
	int superior,inferior,mitad;
	inferior=0;
	superior=getSize();
	mitad=(inferior+superior)/2;
	while(inferior<=superior){
		while(inferior<=superior){
			if(getPos(mitad).getCodProducto()==b){
				return vectorDetalleVenta[mitad];
				break;
			}
			if(getPos(mitad).getCodProducto()>b){
				superior=mitad-1;
			}
			if(getPos(mitad).getCodProducto()<b){
				inferior=mitad+1;
			}
			mitad=(inferior+superior)/2;
		}
		return objError;
	}
    return objError;
}
void DetalleVentaController::eliminar(int codVenta,int codProducto,int cantEliminada){
    for(int i=0;i<getSize();i++){
		if(codVenta==vectorDetalleVenta[i].getCodVenta() && codProducto==vectorDetalleVenta[i].getCodProducto()){
			int Cant=vectorDetalleVenta[i].getCantidad();
			int NuevaCant=Cant-cantEliminada;
			if(NuevaCant==0){
				vectorDetalleVenta.erase(vectorDetalleVenta.begin() + i);
			}
			else{
				vectorDetalleVenta[i].setCantidad(NuevaCant);
			}
		}
	}
}
