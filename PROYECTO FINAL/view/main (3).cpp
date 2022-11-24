#include"../controller/clienteController.h"
#include"../controller/productoController.h"
#include"../controller/vendedorController.h"
#include"../controller/ventaController.h"
#include"../controller/detalleventaController.h"
#include"login.cpp"
//PROTOTIPOS
void menu();
void pause();
//CLIENTES
void clientes();
void registrarClientes();
void listarClientes();
void buscarClientes();
void modificarClientes();
void eliminarClientes();
//PRODUCTOS
void productos();
void registrarProductos();
void listarProductos();
void buscarProductos();
void modificarProductos();
void eliminarProductos();
//VENDEDOR
void vendedores();
void registrarVendedores();
void listarVendedores();
void buscarVendedores();
void modificarVendedores();
void eliminarVendedores();
//VENTAS
void ventas();
void agregarVentas();
void anularVentas();
void listarVentas();
void buscarVentas();
void modificarVentas();
//VARIABLES GLOBALES
ClienteController*vectorClientes= new ClienteController();
ProductoController*vectorProductos= new ProductoController();
VendedorController*vectorVendedores= new VendedorController();
VentaController*vectorVentas= new VentaController();
DetalleVentaController*vectorDetalleVentas= new DetalleVentaController();
int main(){
    system("color 0a"); 
    loginMenu();
    menu();
}
void menu(){

    int exit=false;
    int opcion;
    cout<<"\n\t\t\t\tBienvenido al sistema de ventas: VENTAMAS\n";
    while(exit==false){
        system("cls");
        cout<<"\n\n\t\t\t\tBienvenido al sistema de ventas: VENTAMAS\n";
        cout<<"\n\t\t\t\t[1] Registro de Clientes";
        cout<<"\n\t\t\t\t[2] Registro de Productos";
        cout<<"\n\t\t\t\t[3] Registro de Vendedores";
        cout<<"\n\t\t\t\t[4] Generar la venta";
        cout<<"\n\t\t\t\t[5] Anular la venta";
        cout<<"\n\t\t\t\t[6] Salir";
        cout<<"\n\n\n\t\t\t\tEliga una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1: clientes();break;
            case 2: productos();break;
            case 3: vendedores();break;
            case 4: ventas();break;
            case 5: anularVentas();break;
            case 6: cout<<"\n\n\t\t\t\tGracias por usar nuestro programa ;)";exit=true;break;
        }
    }
}
//CLIENTES
void clientes(){

    int exit=false;
    int opcion;

    while(exit==false){
        system("cls");
        cout<<"\n\t\t\t\t[1] Registrar Clientes";
        cout<<"\n\t\t\t\t[2] Listar Clientes";
        cout<<"\n\t\t\t\t[3] Buscar Clientes";
        cout<<"\n\t\t\t\t[4] Modificar Clientes";
        cout<<"\n\t\t\t\t[5] Eliminar Clientes";
        cout<<"\n\t\t\t\t[6] Volver";
        cout<<"\n\n\n\t\t\t\tEliga una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1: registrarClientes();break;
            case 2: listarClientes();break;
            case 3: buscarClientes();break;
            case 4: modificarClientes();break;
            case 5: eliminarClientes();break;
            case 6: menu();break;
        }
    }
}
void registrarClientes(){

    bool continuar=true;
    int codCliente;
    string nomApeCli;
    string dirCli;
    int rucCli;

    while(continuar==true){
        system("cls");
        cout<<"\n\t\t\t\tCodigo del cliente: ";
        cin>>codCliente;
        fflush(stdin);
        cout<<"\n\t\t\t\tNombre: ";
        getline(cin,nomApeCli);
        cout<<"\n\t\t\t\tDireccion: ";
        getline(cin,dirCli);
        cout<<"\n\t\t\t\tRuc: ";
        cin>>rucCli;
        
        Cliente cliente;
        cliente.setCodCliente(codCliente);
        cliente.setNomApeCli(nomApeCli);
        cliente.setDirCli(dirCli);
        cliente.setRucCli(rucCli);

        vectorClientes->add(cliente);
        vectorClientes->addArchivo(cliente);

        cout<<"\n\n\t\t\t\tDesea seguir agregando clientes? ";
        cout<<"\n\t\t\t\t[0] NO  [1] SI";
        cout<<"\n\n\t\t\t\tEliga su opcion: ";
        cin>>continuar;
        switch(continuar){
            case 0: clientes();break;
            case 1: break;
        }
    }
}
void listarClientes(){
    system("cls");
    for(int i=0;i<vectorClientes->getSize();i++){

        cout<<"\n\t\t\t\tCliente "<<i+1;
        cout<<"\n\t\t\t\tCodigo: "<<vectorClientes->getPos(i).getCodCliente();
        cout<<"\n\t\t\t\tNombre: "<<vectorClientes->getPos(i).getNomApeCli();
        cout<<"\n\t\t\t\tDireccion: "<<vectorClientes->getPos(i).getDirCli();
        cout<<"\n\t\t\t\tRuc: "<<vectorClientes->getPos(i).getRucCli();
        cout<<endl;
    }
    pause();
}
void buscarClientes(){
    system("cls");
    int codigo;

    cout<<"\n\t\t\t\tIngrese el codigo a buscar: ";
    cin>>codigo;
    Cliente clienteBuscar=vectorClientes->buscar(codigo);

    if(clienteBuscar.getNomApeCli()!="Error"){
        cout<<"\n\n\t\t\t\tCliente encontrado!";
        cout<<"\n\t\t\t\tCodigo: "<<clienteBuscar.getCodCliente();
        cout<<"\n\t\t\t\tNombre: "<<clienteBuscar.getNomApeCli();
        cout<<"\n\t\t\t\tDireccion: "<<clienteBuscar.getDirCli();
        cout<<"\n\t\t\t\tRuc: "<<clienteBuscar.getRucCli();
    }
    else{
        cout<<"\n\t\t\t\tNo se ha encontrado un cliente con el codigo: "<<codigo;
    }
    cout<<endl;
    pause(); 
}
void modificarClientes(){
    system("cls");
    int codigo;

    cout<<"\n\t\t\t\tIngrese el codigo a modificar: ";
    cin>>codigo;
    Cliente clienteBuscar=vectorClientes->buscar(codigo);

    if(clienteBuscar.getNomApeCli()!="Error"){
        cout<<"\n\n\t\t\t\tCliente encontrado!";
        cout<<"\n\t\t\t\tCodigo: "<<clienteBuscar.getCodCliente();
        cout<<"\n\t\t\t\tNombre: "<<clienteBuscar.getNomApeCli();
        cout<<"\n\t\t\t\tDireccion: "<<clienteBuscar.getDirCli();
        cout<<"\n\t\t\t\tRuc: "<<clienteBuscar.getRucCli();

        string newNombre;
        string newDireccion;
        int newRuc;
        fflush(stdin);
        cout<<"\n\n\t\t\t\tIngrese el nuevo nombre: ";
        getline(cin,newNombre);
        cout<<"\n\t\t\t\tIngrese la nueva direccion: ";
        getline(cin,newDireccion);
        cout<<"\n\t\t\t\tIngrese el nuevo ruc: ";
        cin>>newRuc;

        Cliente clienteModificado;
        clienteModificado.setCodCliente(clienteBuscar.getCodCliente());
        clienteModificado.setNomApeCli(newNombre);
        clienteModificado.setDirCli(newDireccion);
        clienteModificado.setRucCli(newRuc);

        bool estado=vectorClientes->modificar(clienteBuscar,clienteModificado);
        if(estado==true){
            cout<<"\n\t\t\t\tModificacion completada exitosamente ;)";
            vectorClientes->archivoEliminarModificar();
        }
        else{
            cout<<"\n\t\t\t\tHubo un error en la modificacion";
        }


    }
    else{
        cout<<"\n\t\t\t\tNo se ha encontrado un cliente con el codigo: "<<codigo;
    }
    pause();
}
void eliminarClientes(){
    system("cls");
    int codigo;
    int opcion;
    cout<<"\n\t\t\t\tIngrese el codigo a eliminar: ";
    cin>>codigo;
    Cliente clienteBuscar=vectorClientes->buscar(codigo);

    if(clienteBuscar.getNomApeCli()!="Error"){
        cout<<"\n\n\t\t\t\tCliente encontrado!";
        cout<<"\n\t\t\t\tCodigo: "<<clienteBuscar.getCodCliente();
        cout<<"\n\t\t\t\tNombre: "<<clienteBuscar.getNomApeCli();
        cout<<"\n\t\t\t\tDireccion: "<<clienteBuscar.getDirCli();
        cout<<"\n\t\t\t\tRuc: "<<clienteBuscar.getRucCli();

        cout<<"\n\t\t\t\tEsta seguro que desea eliminar el cliente?";
        cout<<"\n\t\t\t\t[0] NO  [1] SI";
        cout<<"\n\n\t\t\t\tEliga su opcion: ";
        cin>>opcion;
        switch(opcion){
            case 0: clientes();break;
            case 1: vectorClientes->eliminar(clienteBuscar);
                    vectorClientes->archivoEliminarModificar();
                    cout<<"\n\t\t\t\tCliente eliminado satisfactoriamente";
                    break;
        }
    }
    else{
        cout<<"\n\t\t\t\tNo se ha encontrado un cliente con el codigo: "<<codigo;
    }
    pause();
}
//PRODUCTOS
void productos(){
    
    int exit=false;
    int opcion;

    while(exit==false){
        system("cls");
        cout<<"\n\t\t\t\t[1] Registrar Productos";
        cout<<"\n\t\t\t\t[2] Listar Productos";
        cout<<"\n\t\t\t\t[3] Buscar Productos";
        cout<<"\n\t\t\t\t[4] Modificar Productos";
        cout<<"\n\t\t\t\t[5] Eliminar Productos";
        cout<<"\n\t\t\t\t[6] Volver";
        cout<<"\n\n\n\t\t\t\tEliga una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1: registrarProductos();break;
            case 2: listarProductos();break;
            case 3: buscarProductos();break;
            case 4: modificarProductos();break;
            case 5: eliminarProductos();break;
            case 6: menu();break;
        }
    }
}
void registrarProductos(){

    bool continuar=true;
    int codProducto;
    string nomPro;
    int prePro;
    int stkPro;
    int codCategoria;

    while(continuar==true){
        int pas=false;
        system("cls");
        cout<<"\n\t\t\t\tCodigo del producto: ";
        cin>>codProducto;
        fflush(stdin);
        cout<<"\n\t\t\t\tNombre del producto: ";
        getline(cin,nomPro);
        cout<<"\n\t\t\t\tPrecio del producto: ";
        cin>>prePro;
        cout<<"\n\t\t\t\tStock del producto: ";
        cin>>stkPro;
        while(pas==false){
            cout<<"\n\t\t\t\tCodigo de categoria: ";
            cout<<"\n\t\t\t\t[1] Lacteos";
            cout<<"\n\t\t\t\t[2] Verduras";
            cout<<"\n\t\t\t\t[3] Frutas";
            cout<<"\n\t\t\t\t[4] Conservas";
            cout<<"\n\t\t\t\t[5] Cereales";
            cout<<"\n\t\t\t\t[6] Procesados";
            cout<<"\n\n\t\t\t\tIngrese su opcion: ";
            cin>>codCategoria;
            if(codCategoria<1 || codCategoria>6){
                cout<<"\n\t\t\t\tPor favor ingrese una opcion correcta\n";pause();    
            }
            else{
                pas=true;
            }
        }

        Producto producto;
        producto.setCodProducto(codProducto);
        producto.setNomPro(nomPro);
        producto.setPrePro(prePro);
        producto.setStkPro(stkPro);
        switch(codCategoria){
            case 1: producto.setCodCategoria("Lacteos");break;
            case 2: producto.setCodCategoria("Verduras");break;
            case 3: producto.setCodCategoria("Frutas");break;
            case 4: producto.setCodCategoria("Conservas");break;
            case 5: producto.setCodCategoria("Cereales");break;
            case 6: producto.setCodCategoria("Procesados");break;
        }
        
        vectorProductos->add(producto);
        vectorProductos->addArchivo(producto);

        cout<<"\n\n\t\t\t\tDesea seguir agregando productos? ";
        cout<<"\n\t\t\t\t[0] NO  [1] SI";
        cout<<"\n\n\t\t\t\tEliga su opcion: ";
        cin>>continuar;
        switch(continuar){
            case 0: productos();break;
            case 1: break;
        }
    }
}
void listarProductos(){
    system("cls");
    for(int i=0;i<vectorProductos->getSize();i++){
        cout<<"\n\t\t\t\tProducto "<<i+1;
        cout<<"\n\t\t\t\tCodigo: "<<vectorProductos->getPos(i).getCodProducto();
        cout<<"\n\t\t\t\tNombre: "<<vectorProductos->getPos(i).getNomPro();
        cout<<"\n\t\t\t\tPrecio: S/."<<vectorProductos->getPos(i).getPrePro();
        cout<<"\n\t\t\t\tStock: "<<vectorProductos->getPos(i).getStkPro();
        cout<<"\n\t\t\t\tCodigo de categoria: "<<vectorProductos->getPos(i).getCodCategoria();
        cout<<endl;
    }
    pause();
}
void buscarProductos(){
    system("cls");
    int codigo;
    
    cout<<"\n\t\t\t\tIngrese el codigo a buscar: ";
    cin>>codigo;
    Producto productoBuscar=vectorProductos->buscar(codigo);

    if(productoBuscar.getNomPro()!="Error"){
        cout<<"\n\n\t\t\t\tProducto encontrado!";
        cout<<"\n\t\t\t\tCodigo: "<<productoBuscar.getCodProducto();
        cout<<"\n\t\t\t\tNombre: "<<productoBuscar.getNomPro();
        cout<<"\n\t\t\t\tPrecio: S/."<<productoBuscar.getPrePro();
        cout<<"\n\t\t\t\tStock: "<<productoBuscar.getStkPro();
        cout<<"\n\t\t\t\tCodigo de categoria: "<<productoBuscar.getCodCategoria();
    }
    else{
        cout<<"\n\t\t\t\tNo se ha encontrado un producto con el codigo: "<<codigo;
    }
    cout<<endl;
    pause();
}
void modificarProductos(){
    system("cls");
    int codigo;

    cout<<"\n\t\t\t\tIngrese el codigo a buscar: ";
    cin>>codigo;
    Producto productoBuscar=vectorProductos->buscar(codigo);

    if(productoBuscar.getNomPro()!="Error"){
        cout<<"\n\n\t\t\t\tProducto encontrado!";
        cout<<"\n\t\t\t\tCodigo: "<<productoBuscar.getCodProducto();
        cout<<"\n\t\t\t\tNombre: "<<productoBuscar.getNomPro();
        cout<<"\n\t\t\t\tPrecio: S/."<<productoBuscar.getPrePro();
        cout<<"\n\t\t\t\tStock: "<<productoBuscar.getStkPro();
        cout<<"\n\t\t\t\tCodigo de categoria: "<<productoBuscar.getCodCategoria();
        
        string newNombre;
        int newPrecio;
        int newStock;

        fflush(stdin);
        cout<<"\n\n\t\t\t\t\t\t\t\tIngrese el nuevo nombre: ";
        getline(cin,newNombre);
        cout<<"\n\t\t\t\t\t\t\t\tIngrese el nuevo precio: ";
        cin>>newPrecio;
        cout<<"\n\t\t\t\t\t\t\t\tIngrese el nuevo stock: ";
        cin>>newStock;

        Producto productoModificado;
        productoModificado.setCodProducto(productoBuscar.getCodProducto());
        productoModificado.setNomPro(newNombre);
        productoModificado.setPrePro(newPrecio);
        productoModificado.setStkPro(newStock);
        productoModificado.setCodCategoria(productoBuscar.getCodCategoria());

        bool estado=vectorProductos->modificar(productoBuscar,productoModificado);

        if(estado==true){
            cout<<"\n\t\t\t\tProducto modificado satisfactoriamente";
            vectorProductos->archivoEliminarModificar();
        }
        else{
            cout<<"\n\t\t\t\tOcurrio un error en la modificacion";
        }
    }
    else{
        cout<<"\n\t\t\t\tNo se ha encontrado un producto con el codigo: "<<codigo;
    }
    cout<<endl;
    pause();

}
void eliminarProductos(){
    system("cls");
    int codigo;
    int opcion;

    cout<<"\n\t\t\t\tIngrese el codigo a eliminar: ";
    cin>>codigo;
    Producto productoBuscar=vectorProductos->buscar(codigo);

    if(productoBuscar.getNomPro()!="Error"){
        cout<<"\n\n\t\t\t\tProducto encontrado!";
        cout<<"\n\t\t\t\tCodigo: "<<productoBuscar.getCodProducto();
        cout<<"\n\t\t\t\tNombre: "<<productoBuscar.getNomPro();
        cout<<"\n\t\t\t\tPrecio: S/."<<productoBuscar.getPrePro();
        cout<<"\n\t\t\t\tStock: "<<productoBuscar.getStkPro();
        cout<<"\n\t\t\t\tCodigo de categoria: "<<productoBuscar.getCodCategoria();

        cout<<"\n\t\t\t\tEsta seguro que desea eliminar el producto?";
        cout<<"\n\t\t\t\t[0] NO [1] SI";
        cout<<"\n\n\t\t\t\tEliga su opcion: ";
        cin>>opcion;
        switch(opcion){
            case 0: productos();break;
            case 1: vectorProductos->eliminar(productoBuscar);
                    vectorProductos->archivoEliminarModificar();
                    cout<<"\n\t\t\t\tProducto eliminado satisfactoriamente";
                    break;
        }
    }
    else{
        cout<<"\n\t\t\t\tNo se ha encontrado un producto con el codigo: "<<codigo;
    }
    cout<<endl;
    pause();
}
//VENDEDORES
void vendedores(){
    
    int exit=false;
    int opcion;

    while(exit==false){
        system("cls");
        cout<<"\n\t\t\t\t[1] Registrar Vendedores";
        cout<<"\n\t\t\t\t[2] Listar Vendedores";
        cout<<"\n\t\t\t\t[4] Modificar Vendedores";
        cout<<"\n\t\t\t\t[5] Eliminar Vendedores";
        cout<<"\n\t\t\t\t[6] Volver";
        cout<<"\n\n\n\t\t\t\tEliga una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1: registrarVendedores();break;
            case 2: listarVendedores();break;
            case 3: buscarVendedores();break;
            case 4: modificarVendedores();break;
            case 5: eliminarVendedores();break;
            case 6: menu();break;
        }
    }
}
void registrarVendedores(){

    bool continuar=true;
    int codPersonal;
    string nomApePer;
    int dniPer;
    int suePer;
    int codTipPer;

    while(continuar==true){
        int pas=false;
        system("cls");
        cout<<"\n\t\t\t\tCodigo del vendedor: ";
        cin>>codPersonal;
        fflush(stdin);
        cout<<"\n\t\t\t\tNombre del vendedor: ";
        getline(cin,nomApePer);
        cout<<"\n\t\t\t\tDNI del vendedor: ";
        cin>>dniPer;
        cout<<"\n\t\t\t\tSueldo del vendedor: ";
        cin>>suePer;
        while(pas==false){
            cout<<"\n\t\t\t\tCodigo de tipo de personal: ";
            cout<<"\n\t\t\t\t[1] Laboral fijo";
            cout<<"\n\t\t\t\t[2] Laboral por tiempo indefinido";
            cout<<"\n\t\t\t\t[3] Laboral temporal";
            cout<<"\n\n\t\t\t\tIngrese su opcion: ";
            cin>>codTipPer;
            if(codTipPer<1 || codTipPer>3){
                cout<<"\n\t\t\t\tPor favor ingrese una opcion correcta\n";pause();    
            }
            else{
                pas=true;
            }
        }

        Vendedor vendedor;
        vendedor.setCodPersonal(codPersonal);
        vendedor.setNomApePer(nomApePer);
        vendedor.setDniPer(dniPer);
        vendedor.setSuePer(suePer);
        switch(codTipPer){
            case 1: vendedor.setCodTipPer("Laboral fijo");break;
            case 2: vendedor.setCodTipPer("Laboral por tiempo indefinido");break;
            case 3: vendedor.setCodTipPer("Laboral temporal");break;
        }
        
        vectorVendedores->add(vendedor);
        vectorVendedores->addArchivo(vendedor);

        cout<<"\n\n\t\t\t\tDesea seguir agregando vendedores? ";
        cout<<"\n\t\t\t\t[0] NO  [1] SI";
        cout<<"\n\n\t\t\t\tEliga su opcion: ";
        cin>>continuar;
        switch(continuar){
            case 0: vendedores();break;
            case 1: break;
        }
    }
}
void listarVendedores(){
    system("cls");
    for(int i=0;i<vectorVendedores->getSize();i++){
        cout<<"\n\t\t\t\tVendedor "<<i+1;
        cout<<"\n\t\t\t\tCodigo: "<<vectorVendedores->getPos(i).getCodPersonal();
        cout<<"\n\t\t\t\tNombre: "<<vectorVendedores->getPos(i).getNomApePer();
        cout<<"\n\t\t\t\tPrecio: S/."<<vectorVendedores->getPos(i).getDniPer();
        cout<<"\n\t\t\t\tStock: "<<vectorVendedores->getPos(i).getSuePer();
        cout<<"\n\t\t\t\tCodigo de categoria: "<<vectorVendedores->getPos(i).getCodTipPer();
        cout<<endl;
    }
    pause();
}
void buscarVendedores(){
    system("cls");
    int codigo;
    
    cout<<"\n\t\t\t\tIngrese el codigo a buscar: ";
    cin>>codigo;
    Vendedor vendedorBuscar=vectorVendedores->buscar(codigo);

    if(vendedorBuscar.getNomApePer()!="Error"){
        cout<<"\n\n\t\t\t\tVendedor encontrado!";
        cout<<"\n\t\t\t\tCodigo: "<<vendedorBuscar.getCodPersonal();
        cout<<"\n\t\t\t\tNombre: "<<vendedorBuscar.getNomApePer();
        cout<<"\n\t\t\t\tDni: "<<vendedorBuscar.getDniPer();
        cout<<"\n\t\t\t\tSueldo S/ : "<<vendedorBuscar.getSuePer();
        cout<<"\n\t\t\t\tCodigo de categoria: "<<vendedorBuscar.getCodTipPer();
    }
    else{
        cout<<"\n\t\t\t\tNo se ha encontrado un vendedor con el codigo: "<<codigo;
    }
    cout<<endl;
    pause();
}
void modificarVendedores(){
    system("cls");
    int codigo;

    cout<<"\n\t\t\t\tIngrese el codigo a buscar: ";
    cin>>codigo;
    Vendedor vendedorBuscar=vectorVendedores->buscar(codigo);

    if(vendedorBuscar.getNomApePer()!="Error"){
        cout<<"\n\n\t\t\t\tVendedor encontrado!";
        cout<<"\n\t\t\t\tCodigo: "<<vendedorBuscar.getCodPersonal();
        cout<<"\n\t\t\t\tNombre: "<<vendedorBuscar.getNomApePer();
        cout<<"\n\t\t\t\tDni: "<<vendedorBuscar.getDniPer();
        cout<<"\n\t\t\t\tSueldo S/ : "<<vendedorBuscar.getSuePer();
        cout<<"\n\t\t\t\tCodigo de categoria: "<<vendedorBuscar.getCodTipPer();
    
        string newNombre;
        int newDni;
        int newSueldo;

        fflush(stdin);
        cout<<"\n\n\t\t\t\tIngrese el nuevo nombre: ";
        getline(cin,newNombre);
        cout<<"\n\t\t\t\tIngrese el nuevo dni: ";
        cin>>newDni;
        cout<<"\n\t\t\t\tIngrese el nuevo sueldo: ";
        cin>>newSueldo;

        Vendedor vendedorModificado;
        vendedorModificado.setCodPersonal(vendedorBuscar.getCodPersonal());
        vendedorModificado.setNomApePer(newNombre);
        vendedorModificado.setDniPer(newDni);
        vendedorModificado.setSuePer(newSueldo);
        vendedorModificado.setCodTipPer(vendedorBuscar.getCodTipPer());

        bool estado=vectorVendedores->modificar(vendedorBuscar,vendedorModificado);

        if(estado==true){
            cout<<"\n\t\t\t\tVendedor modificado satisfactoriamente";
            vectorVendedores->archivoEliminarModificar();
        }
        else{
            cout<<"\n\t\t\t\tOcurrio un error en la modificacion";
        }
    }
    else{
        cout<<"\n\t\t\t\tNo se ha encontrado un vendedor con el codigo: "<<codigo;
    }
    cout<<endl;
    pause();

}
void eliminarVendedores(){
    system("cls");
    int codigo;
    int opcion;

    cout<<"\n\t\t\t\tIngrese el codigo a eliminar: ";
    cin>>codigo;
    Vendedor vendedorBuscar=vectorVendedores->buscar(codigo);

    if(vendedorBuscar.getNomApePer()!="Error"){
        cout<<"\n\n\t\t\t\tVendedor encontrado!";
        cout<<"\n\t\t\t\tCodigo: "<<vendedorBuscar.getCodPersonal();
        cout<<"\n\t\t\t\tNombre: "<<vendedorBuscar.getNomApePer();
        cout<<"\n\t\t\t\tDni: "<<vendedorBuscar.getDniPer();
        cout<<"\n\t\t\t\tSueldo S/ : "<<vendedorBuscar.getSuePer();
        cout<<"\n\t\t\t\tCodigo de categoria: "<<vendedorBuscar.getCodTipPer();

        cout<<"\n\t\t\t\tEsta seguro que desea eliminar el vendedor?";
        cout<<"\n\t\t\t\t[0] NO [1] SI";
        cout<<"\n\n\t\t\t\tEliga su opcion: ";
        cin>>opcion;
        switch(opcion){
            case 0: productos();break;
            case 1: vectorVendedores->eliminar(vendedorBuscar);
                    vectorVendedores->archivoEliminarModificar();
                    cout<<"\n\t\t\t\tVendedor eliminado satisfactoriamente";
                    break;
        }
    }
    else{
        cout<<"\n\t\t\t\tNo se ha encontrado un vendedor con el codigo: "<<codigo;
    }
    cout<<endl;
    pause();
}
//VENTAS
void ventas(){
    int exit=false;
    int opcion;

    while(exit==false){
        system("cls");
        cout<<"\n\t\t\t\t[1] Agregar ventas";
        cout<<"\n\t\t\t\t[2] Listar ventas";
        cout<<"\n\t\t\t\t[3] Buscar ventas";
        cout<<"\n\t\t\t\t[4] Volver";
        cout<<"\n\n\n\t\t\t\tEliga una opcion: ";
        cin>>opcion;
        switch(opcion){
            case 1: agregarVentas();break;
            case 2: listarVentas();break;
            case 3: buscarVentas();break;
            case 4: menu();break;
        }
    }
}
void agregarVentas(){
    int codigo;
    int fecha;
    int codCliente;
    int codVendedor;
    string flag;
    codigo=vectorVentas->codigo();
    int continuar=true;
    
    while(continuar==true){
        system("cls");
        fflush(stdin);
        cout<<"\n\t\t\t\tEscriba la fecha de la venta: ";
        cin>>fecha;
        listarClientes();
        cout<<"\n\n\t\t\t\tSeleccione por su codigo, el cliente de esta venta: ";
        cin>>codCliente;
        listarVendedores();
        cout<<"\n\n\t\t\t\tSeleccione el codigo del vendedor que realizo esta venta: ";
        cin>>codVendedor;
        Venta venta;
        venta.setCodVenta(codigo);
        venta.setFechaVenta(fecha);
        venta.setCodCliente(codCliente);
        venta.setcodPersonal(codVendedor);
        venta.setEstVenta(true);
        venta.setTotVenta(0);
        vectorVentas->add(venta);
        vectorVentas->addArchivo(venta);
        cout<<"\n\n\t\t\t\tDesea seguir agregando ventas? ";
        cout<<"\n\t\t\t\t[0] NO  [1] SI";
        cout<<"\n\n\t\t\t\tEliga su opcion: ";
        cin>>continuar;
        switch(continuar){
            case 0: ventas();break;
            case 1: break;
        }
    }
}
void anularVentas(){
    int codigo;
    int opcion;
    string r;
    system("cls");
    cout<<"\n\t\t\t\tIngrese el codigo de la venta a anular: ";
    cin>>codigo;
    Venta objAnulado=vectorVentas->buscar(codigo);
    Cliente cliente=vectorClientes->buscar(objAnulado.getCodCliente());
    Vendedor vendedor=vectorVendedores->buscar(objAnulado.getcodPersonal());
    cout<<"\n\n\t\t\t\tCodigo de la venta: "<<objAnulado.getCodVenta();
    cout<<"\n\t\t\t\tFecha de la venta: "<<objAnulado.getFechaVenta();
    cout<<"\n\t\t\t\tTotal de la venta: "<<objAnulado.getTotVenta();
    cout<<"\n\t\t\t\tEstado de la venta: "<<objAnulado.getEstVenta();
    cout<<"\n\t\t\t\tCliente: "<<cliente.getNomApeCli();
    cout<<"\n\t\t\t\tVendedor: "<<vendedor.getNomApePer();
    cout<<"\n\t\t\t\tEsta seguro que desea eliminar esta venta?";
        cout<<"\n\t\t\t\t[0] NO [1] SI";
        cout<<"\n\n\t\t\t\tEliga su opcion: ";
        cin>>opcion;
        switch(opcion){
            case 0: ventas();break;
            case 1: vectorVentas->anular(objAnulado);
                    vectorVentas->archivoEliminarModificar();
                    cout<<"\n\t\t\t\tVenta eliminada satisfactoriamente";
                    break;
        }
    pause();    
}
void listarVentas(){
    system("cls");
    for(int i=0;i<vectorVentas->getSize();i++){
        
            Cliente cliente=vectorClientes->buscar(vectorVentas->getPos(i).getCodCliente());
            Vendedor vendedor=vectorVendedores->buscar(vectorVentas->getPos(i).getcodPersonal());
            cout<<"\n\t\t\t\tVenta "<<vectorVentas->getPos(i).getCodVenta();
            cout<<"\n\t\t\t\tFecha de la venta: "<<vectorVentas->getPos(i).getFechaVenta();
            cout<<"\n\t\t\t\tTotal de la venta: "<<vectorVentas->getPos(i).getTotVenta();
            cout<<"\n\t\t\t\tCliente: "<<cliente.getNomApeCli();
            cout<<"\n\t\t\t\tVendedor: "<<vendedor.getNomApePer();
        
    }
    pause();
}
void buscarVentas(){
    int codigo;
    system("cls");
    cout<<"\n\t\t\t\tIngrese el codigo de venta a buscar: ";
    cin>>codigo;
    Venta objProducto=vectorVentas->buscar(codigo);
    Cliente cliente=vectorClientes->buscar(objProducto.getCodCliente());
    Vendedor vendedor=vectorVendedores->buscar(objProducto.getcodPersonal());
    if(objProducto.getCodVenta()!=0){
        cout<<"\n\t\t\t\tCodigo de la venta: "<<objProducto.getCodVenta();
        cout<<"\n\t\t\t\tFecha de la venta: "<<objProducto.getFechaVenta();
        cout<<"\n\t\t\t\tTotal de la venta: "<<objProducto.getTotVenta();
        cout<<"\n\t\t\t\tEstado de la venta: "<<objProducto.getEstVenta();
        cout<<"\n\t\t\t\tCliente: "<<cliente.getNomApeCli();
        cout<<"\n\t\t\t\tVendedor: "<<vendedor.getNomApePer();
    }
    else{
        cout<<"\n\t\t\t\tNo se encontro la venta";
    }
    pause();
}
void modificarVentas(){

}
void pause(){
    cout<<"\n\n\t\t\t\tPresione cualquier tecla para continuar";
    getch();
}