#include<iostream>
#include<conio.h>
#include<vector>
#include<stdlib.h>
#include<fstream>
using namespace std;
vector<string>usuarios;
vector<string>claves;
string user;
string password;
int menul=false;
string cifrado="abcdefghijklmnopqrstuvwxyz1234567890";
void loginMenu();
void login();
void registrar();
void cargarDatos();
void cifrar();
void loginMenu(){

    int exit=false;
    int opcion;

    while(exit==false && menul==false){
        system("cls");
        cout<<"\n\t\t\t\t--------LOGIN DE USUARIO--------";
        cout<<"\n\t\t\t\t1.Iniciar sesion";
        cout<<"\n\t\t\t\t2.Registrar usuario";
        cout<<"\n\t\t\t\t3.Salir";
        cout<<"\n\n\t\t\t\tIngrese una opcion: ";
        cin>>opcion;

        switch(opcion){
            case 1: login();break;
            case 2: registrar();break;
            case 3: cout<<"\n\n\t\t\t\tGracias por usar nuestro programa";exit=true;break;
        }
    }
}
void login(){

    cargarDatos();

    fflush(stdin);

    int pass=false;
    while(pass==false){

        system("cls");
        cout<<"\t\t\t\tIngrese el usuario: ";
        getline(cin,user);
        cout<<"\t\t\t\tIngrese la contrasena: ";
        char caracter;
        caracter=getch();
        password="";
        while(caracter!=13){
            if(caracter!=8){
                password.push_back(caracter);
                cout<<"*";
            }
            else{
                if(password.length()>0){
                    cout<<"\b \b";
                    password.pop_back();
                }
            }
            caracter=getch();
        }
        for(int i=0;i<usuarios.size();i++){      
            
            if(usuarios[i]==user && claves[i]==password){
                pass=true;
                cout<<"\n\n\t\t\t\tBienvenido al sistema "<<user<<" ;)";
                menul=true;
                getch();
                break;
            }
        }
        if(!pass){
            cout<<"\n\n\t\t\t\tUsuario o contrasena incorrectos";
            getch();
        }
    }   
}
void registrar(){
    fflush(stdin);
    system("cls");
    fstream usuario;
    fstream contrasena;
    usuario.open("usuario.csv",ios::app);
    contrasena.open("contrasena.bin",ios::app);

    cout<<"\t\t\t\tIngrese el nuevo usuario: ";
    getline(cin,user);
    cout<<"\t\t\t\tIngrese la nueva contrasena: ";
    getline(cin,password);
    usuarios.push_back(user);
    claves.push_back(password);

    usuario<<user<<" ";
    contrasena<<password<<" ";

    cifrar();
}
void cifrar(){
    fstream passCifrada;
    int longitud;
    longitud=password.length();

    passCifrada.open("contrasenaCifrada.csv",ios::app);
    for(int i=0;i<longitud;i++){
        for(int j=0;j<36;j++){

            if(password[i]==cifrado[j]){

                if((j+5)>35){
                    passCifrada<<cifrado[j+5-36];
                }
                else{
                    passCifrada<<cifrado[j+5]; 
                }
            }
        }
    }
    passCifrada<<endl;
}
void cargarDatos(){
    int i;
    size_t posi;
    string linea;
    string temporal[100];
    fstream archivoUser;
    fstream archivoPass;
    archivoUser.open("usuario.csv",ios::in);
    archivoPass.open("contrasena.bin",ios::in);

    while(!archivoUser.eof() && getline(archivoUser,linea)){

        i=0;
        while((posi=linea.find(" "))!=string::npos){

            temporal[i]=linea.substr(0,posi);
            linea.erase(0,posi+1);
            ++i;
        }
        for(int j=0;j<100;j++){
            usuarios.push_back(temporal[j]);
        }    
    }
    while(!archivoPass.eof() && getline(archivoPass,linea)){

        i=0;
        while((posi=linea.find(" "))!=string::npos){

            temporal[i]=linea.substr(0,posi);
            linea.erase(0,posi+1);
            ++i;
        }
        for(int j=0;j<100;j++){
            claves.push_back(temporal[j]);
        }    
    }
}
