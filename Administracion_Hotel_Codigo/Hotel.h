/* 
Ricardo Sierra Roa - A01709887
Proyecto Administracion Hotel
Creacion: 24 de mayo de 2023
Ultima modificacion: 5 de junio de 2023

En esta clase se define al objeto tipo Hotel
donde se agregan a los clientes y las habitaciones
creadas, asi como contiene informacion de su ubicacion,
nombre y numero de habitaciones.
*/

#ifndef HOTEL_H
#define HOTEL_H

#include "string.h"
#include <sstream>

//Clases utilizadas para agregacion
#include "Habitacion.h"
#include "Cliente.h"

using namespace std;
 
class Hotel{
	private: //Atributos
        //Se declaran las variables privadas de instancia
		string nombre, ubicacion;
        int numHabitaciones=1000;
		static const int numHabitacionesArr=1000;
        Habitacion *arrHabitaciones[numHabitacionesArr];
        Cliente arrClientes[numHabitacionesArr];
		
	public: //Constructor y metodos publicos
        //Constructor
		Hotel(string nombre, string ubicacion, int numHabitaciones);

        //Funcion para agregar habitaciones al hotel
        void agregarHabitacion(Habitacion *habitacion, int posicion);
        //Funcion para agregar clientes al hotel
        void agregarCliente(Cliente cliente, int posicion);
        //Funcion para imprimir los clientes registrados
        string cantidadClientes();

        //Setters 
		void setNombre(string nombre);
        void setUbicacion(string ubicacion);
        void setNumHabitaciones(int numHabitaciones);

        //Getters
        string getNombre();
        string getUbicacion();
        int getNumHabitaciones();

        //Super string que nos da la informacion del nombre, ubicacion y cantidad de cuartos del hotel
        string getHotelInfo();
};

//Constructor
Hotel::Hotel(string _nombre, string _ubicacion, int _numHabitaciones){
    nombre = _nombre;
    ubicacion = _ubicacion;
    numHabitaciones = _numHabitaciones;
}


/**
 * Relacion de agregacion de la clase habitacion
 * agregarHabitacion agregar las habitaciones creadas a un arreglo
 *
 * @param Habitacion e int 
 * @return
*/
void Hotel::agregarHabitacion(Habitacion *habitacion, int posicion){
    arrHabitaciones[posicion]=habitacion;
}

/**
 * Relacion de agregacion de la clase cliente
 * agregarCliente agregar los clientes creadas a un arreglo
 *
 * @param Cliente e int 
 * @return
*/
void Hotel::agregarCliente(Cliente cliente, int posicion){
    arrClientes[posicion]=cliente;
}

/**
 * cantidadClientes imprimir los clientes registrados
 * 
 * Funcion para guardar en un string los clientes 
 * registrados/agregados dentro del arreglo de clientes del hotel 
 *
 * @param  
 * @return string
*/
string Hotel::cantidadClientes(){
    stringstream aux;
    for(int i=0;i<numHabitaciones;i++){
        if (arrClientes[i].getNombre()==""){
            continue;
        }else{
            aux<<"\n\t\tCliente "<<i+1<<": "<<arrClientes[i].getNombre()<<endl;
        }
    }
    return aux.str();
}

//Setters
void Hotel::setNombre(string _nombre){
    nombre=_nombre;
}

void Hotel::setUbicacion(string _ubicacion){
    ubicacion = _ubicacion;
}

void Hotel::setNumHabitaciones(int _numHabitaciones){
    numHabitaciones = _numHabitaciones;
}

//Getters
string Hotel::getNombre(){
    return nombre;
}

string Hotel::getUbicacion(){
    return ubicacion;
}

int Hotel::getNumHabitaciones(){
    return numHabitaciones;
}

/**
 * Superstring
 * getHotelInfo imprimir la informacion del hotel
 * 
 * Funcion que contcatena en un string toda la informacion de un objeto tipo hotel y la guarda en un string
 *
 * @param  
 * @return string
*/
string Hotel::getHotelInfo(){
    stringstream aux;
    aux<<"Nombre: "<<nombre<<endl;
    aux<<"Ubicacion: "<<ubicacion<<endl;
    aux<<"Numero de habitaciones: "<<numHabitaciones<<endl;
    return aux.str();
}

#endif
