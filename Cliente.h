//Ricardo Sierra Roa - A01709887
#ifndef CLIENTE_H
#define CLIENTE_H

#include "string.h"
#include <sstream>

//Clase utilizada para agregacion
#include "Habitacion.h"


using namespace std;
 
class Cliente{
	private: //Atributos
        //Se declaran las variables
        string nombre, telefono, checkIn, checkOut;
		int edad, diasHospedaje;
        Habitacion habitacion;    
	
    public: //Metodos
        //Constructor predefinido
        Cliente();
        //Constructor
        Cliente(string nombre, int edad, string telefono, int diasHospedaje);
        //Constructor sobrecarga
		Cliente(string nombre, int edad, string telefono, string checkIn, string checkOut, int diasHospedaje);

        //Funcion para agregar habitacion al cliente
        void agregarHabitacion(Habitacion habitacion);
        //Funcion que imprime en que habitacion se hospeda
        string habitacionHospedaje();
        //Funcion para calcular e imprimir el pago del hospedaje
        string calcularPago();

        //Setters
		void setNombre(string nombre);
        void setEdad(int edad);
        void setTelefono(string telefono);
        void setCheckIn(string checkIn);
        void setCheckOut(string checkOut);
        void setDiasHospedaje(int diasHospedaje);

        //Getters
        string getNombre();
        int getEdad();
        string getTelefono();
        string getCheckIn();
        string getCheckOut();
        int getDiasHospedaje();

        //Super string que nos da la informacion del Cliente 
        string getClienteInfo();
};

//Constructor predefinido
Cliente::Cliente(){
    nombre = "";
    edad = 0;
    telefono = "";
    checkIn = "";
    checkOut = "";
    diasHospedaje = 0;
}

//Constructor 
Cliente::Cliente(string _nombre, int _edad, string _telefono, int _diasHospedaje){
    nombre = _nombre;
    edad = _edad;
    telefono = _telefono;
    diasHospedaje = _diasHospedaje;
}

//Constructor sobrecarga
Cliente::Cliente(string _nombre, int _edad, string _telefono, string _checkIn, string _checkOut, int _diasHospedaje){
    nombre = _nombre;
    edad = _edad;
    telefono = _telefono;
    checkIn = _checkIn;
    checkOut = _checkOut;
    diasHospedaje = _diasHospedaje;
}

//Relacion de agregacion de la clase habitacion
void Cliente::agregarHabitacion(Habitacion _habitacion){
    habitacion = _habitacion;
}

//Funcion que imprime en que habitacion se hospeda
string Cliente::habitacionHospedaje(){
    stringstream aux;
    aux<<"Numero de habitacion: "<<habitacion.getNumHabitacion()<<endl;
    return aux.str();
}

//Funcion para calcular e imprimir el pago del hospedaje
string Cliente::calcularPago(){
    stringstream aux;
    if (habitacion.getNumHabitacion()==0){
        aux<<"Costo total: No cuenta con habitacion"<<endl;
        return aux.str();
    }else{
        int ctotal;
        ctotal = diasHospedaje*habitacion.getCostoPorNoche();
        aux<<"Costo total: "<<ctotal<<endl;
        return aux.str();
    }
}

//Setters
void Cliente::setNombre(string _nombre){
    nombre= _nombre;
}

void Cliente::setEdad(int _edad){
    edad = _edad;
}

void Cliente::setTelefono(string _telefono){
    telefono = _telefono;
}

void Cliente::setCheckIn(string _checkIn){
    checkIn = _checkIn;
}

void Cliente::setCheckOut(string _checkOut){
    checkOut = _checkOut;
}

void Cliente::setDiasHospedaje(int _diasHospedaje){
    diasHospedaje = _diasHospedaje;
}

//Getters
string Cliente::getNombre(){
    return nombre;
}

int Cliente::getEdad(){
    return edad;
}

string Cliente::getTelefono(){
    return telefono;
}

string Cliente::getCheckIn(){
    return checkIn;
}

string Cliente::getCheckOut(){
    return checkOut;
}

int Cliente::getDiasHospedaje(){
    return diasHospedaje;
}

//Super string
string Cliente::getClienteInfo(){
    stringstream aux;
    aux<<"Nombre: "<<nombre<<endl;
    aux<<"Edad: "<<edad<<endl;
    aux<<"Telefono: "<<telefono<<endl;
    if (checkIn==""){
        aux<<"Check - In: Sin Check - In"<<checkIn<<endl;
    }else{
        aux<<"Check - In: "<<checkIn<<endl;
    }
    if (checkOut==""){
        aux<<"Check - Out: Sin Check - Out"<<checkIn<<endl;
    }else{
        aux<<"Check - Out: "<<checkOut<<endl;
    }
    aux<<"Dias de hospedaje: "<<diasHospedaje<<endl;
    if (habitacion.getNumHabitacion()==0){
        aux<<"Habitacion en la que se hospeda: No cuenta con habitacion"<<endl;
    }else{
        aux<<"Habitacion en la que se hospeda: "<<habitacion.getNumHabitacion()<<endl;
    }
    return aux.str();
}

#endif