#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<vector>
#include<fstream>
using namespace std;

class Cliente{

    private:
        int codCliente;
        string nomApeCli;
        string dirCli;
        int rucCli;
    public:
        Cliente();
        void setCodCliente(int codCliente);
        void setNomApeCli(string nomApeCli);
        void setDirCli(string dirCli);
        void setRucCli(int rucCli);
        int getCodCliente();
        string getNomApeCli();   
        string getDirCli();
        int getRucCli();
};
Cliente::Cliente(){
}
void Cliente::setCodCliente(int codCliente){
    this->codCliente=codCliente;
}
void Cliente::setNomApeCli(string nomApeCli){
    this->nomApeCli=nomApeCli;
}
void Cliente::setDirCli(string dirCli){
    this->dirCli=dirCli;
}
void Cliente::setRucCli(int rucCli){
    this->rucCli=rucCli;
}
int Cliente::getCodCliente(){
    return codCliente;
}
string Cliente::getNomApeCli(){
    return nomApeCli;
}
string Cliente::getDirCli(){
    return dirCli;
}
int Cliente::getRucCli(){
    return rucCli;
}
