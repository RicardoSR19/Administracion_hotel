/* 
Ricardo Sierra Roa - A01709887
Proyecto Administracion Hotel
Creacion: 24 de mayo de 2023
Ultima modificacion: 31 de mayo de 2023

En esta clase se define al objeto tipo Deluxe, 
la cual es clase hijo de la clase Habitacion.
*/

#ifndef DELUXE_H
#define DELUXE_H

#include "string.h"
#include <sstream>

//Clase utilizada para agregacion
#include "Habitacion.h"

using namespace std;
 
class Deluxe: public Habitacion{//Herencia con clase Habitacion
	private: //Atributos
        //Se declaran las variables privadas de instancia
		bool bar, accesoGym, jacuzzi;
        string espacioAdicional, servicioAdicional;
		
	public: //Constructor y metodos publicos
        //Constructor
		Deluxe(int numHabitacion, int numCamas, bool internet, bool terraza, int costoPorNoche, bool disponibilidad, bool bar, string espacioAdicional, bool accesoGym, bool jacuzzi, string servicioAdicional);
		
        //Setters
        void setBar(bool Bar);
        void setEspacioAdicional(string espacioAdicional);
        void setAccesoGym(bool accesoGym);
        void setJacuzzi(bool jacuzzi);
        void setServicioAdicional(string servicioAdicional);

        //Getters
        bool getBar();
        string getEspacioAdicional();
        bool getAccesoGym();
        bool getJacuzzi();
        string getServicioAdicional();

        //Super string que nos da la informacion de la habitacion deluxe
        string getRoomInfo();
};

//Constructor
Deluxe::Deluxe(int _numHabitacion, int _numCamas, bool _internet, bool _terraza, int _costoPorNoche, bool _disponibilidad, bool _bar, string _espacioAdicional, bool _accesoGym, bool _jacuzzi, string _servicioAdicional):Habitacion(_numHabitacion,_numCamas,_internet,_terraza, _costoPorNoche, _disponibilidad){
    bar = _bar;
    espacioAdicional = _espacioAdicional;
    accesoGym = _accesoGym;
    jacuzzi = _jacuzzi;
    servicioAdicional = _servicioAdicional;
}

//Setters
void Deluxe::setBar(bool _bar){
    bar = _bar;
}

void Deluxe::setEspacioAdicional(string _espacioAdicional){
    espacioAdicional = _espacioAdicional;
}

void Deluxe::setAccesoGym(bool _accesoGym){
    accesoGym = _accesoGym;
}

void Deluxe::setJacuzzi(bool _jacuzzi){
    jacuzzi = _jacuzzi;
}

void Deluxe::setServicioAdicional(string _servicioAdicional){
    servicioAdicional = _servicioAdicional;
}

//Getters
bool Deluxe::getBar(){
    return bar;
}

string Deluxe::getEspacioAdicional(){
    return espacioAdicional;
}

bool Deluxe::getAccesoGym(){
    return accesoGym;
}

bool Deluxe::getJacuzzi(){
    return jacuzzi;
}

string Deluxe::getServicioAdicional(){
    return servicioAdicional;
}

/**
 * Superstring
 * getRoomInfo imprimir la informacion de la habitacion Deluxe
 * 
 * Funcion que contcatena en un string toda la informacion de un objeto tipo Deluxe y la guarda en un string
 *
 * @param  
 * @return string
*/
string Deluxe::getRoomInfo(){
    stringstream aux;
    aux<<getHabitacionInfo();
    if (bar==true){
        aux<<"Tiene Bar: si"<<endl;
    }else{
        aux<<"Tiene Minibar: no"<<endl;
    }
    aux<<"Espacio adicional: "<<espacioAdicional<<endl;
    if (accesoGym==true){
        aux<<"Tiene acceso al Gym: si"<<endl;
    }else{
        aux<<"Tiene acceso al Gym: no"<<endl;
    }
    if (jacuzzi==true){
        aux<<"Tiene jacuzzi: si"<<endl;
    }else{
        aux<<"Tiene jacuzzi: no"<<endl;
    }
    aux<<"Serivicio adicional: "<<servicioAdicional<<endl;
    return aux.str();
}

#endif