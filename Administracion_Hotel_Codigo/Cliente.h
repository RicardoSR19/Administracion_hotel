/* 
Ricardo Sierra Roa - A01709887
Proyecto Administracion Hotel
Creacion: 24 de mayo de 2023
Ultima modificacion: 31 de mayo de 2023

En esta clase se define al objeto tipo Cliente, 
donde al momento de crear un objeto de estos, tiene
informacion, como nombre, edad, telefono, check-in,
check-out y dias que se hospeda, asi como se le puede asignar
una habitacion, calcular el pago de su hospedaje y moficiar sus
fechas de check-in y check-out
*/

#ifndef CLIENTE_H
#define CLIENTE_H

#include "string.h"
#include <sstream>

//Clase utilizada para agregacion
#include "Habitacion.h"

using namespace std;
 
class Cliente{
	private: //Atributos
        //Se declaran las variables privadas de instancia
        string nombre, telefono, checkIn, checkOut;
		int edad, diasHospedaje;
        Habitacion habitacion;    
	
    public: //Constructor y metodos publicos
        //Constructor predefinido
        Cliente();
        //Constructor
        Cliente(string nombre, int edad, string telefono, int diasHospedaje);
        //Constructor sobrecarga
		Cliente(string nombre, int edad, string telefono, string checkIn, string checkOut, int diasHospedaje);

        //Funcion para agregar habitacion al cliente
        void agregarHabitacion(Habitacion habitacion);
        //Funcion que imprime en que numero de habitacion se hospeda
        int habitacionHospedaje();
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


/**
 * Relacion de agregacion de la clase habitacion
 * agregarHabitacion agregar habitacion al cliente
 * 
 * Funcion para asignarle una habitacion a algun cliente registrado
 *
 * @param Habitacion 
 * @return 
*/
void Cliente::agregarHabitacion(Habitacion _habitacion){
    habitacion = _habitacion;
}

/**
 * habitacionHospedaje regresar que habitacion tiene el cliente 
 * 
 * Funcion que regresa en que numero de habitacion se hospeda el cliente
 *
 * @param  
 * @return int - numero de habitacion donde se hospeda el cliente 
*/
int Cliente::habitacionHospedaje(){
    return habitacion.getNumHabitacion();
}

/**
 * calcularPago calcular el costo de hospedaje del cliente 
 * 
 * Funcion que calcula y regresra el costo total del 
 * hospedaje del cliente registrado, en caso de no 
 * tener habitacion, muestra que no cuenta con una
 *
 * @param  
 * @return string - costo total a pagar del hospedaje 
*/
string Cliente::calcularPago(){
    stringstream aux;
    if (habitacion.getNumHabitacion()==0){
        aux<<"Costo total: No cuenta con habitacion"<<endl;
        return aux.str();
    }else{
        int ctotal;
        ctotal = diasHospedaje*habitacion.getCostoPorNoche();
        aux<<"Costo total: $"<<ctotal<<".00 MXN"<<endl;
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

/**
 * Superstring
 * getClienteInfo imprimir la informacion del cliente
 * 
 * Funcion que contcatena en un string toda la informacion 
 * de un objeto tipo Cliente y la guarda en un string para 
 * despues imprimirla en un main.cpp
 *
 * @param  
 * @return string
*/
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