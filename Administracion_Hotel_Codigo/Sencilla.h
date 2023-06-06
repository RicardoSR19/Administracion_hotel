/* 
Ricardo Sierra Roa - A01709887
Proyecto Administracion Hotel
Creacion: 24 de mayo de 2023
Ultima modificacion: 31 de mayo de 2023

En esta clase se define al objeto tipo Sencilla, 
la cual es clase hijo de la clase Habitacion.
*/

#ifndef SENCILLA_H
#define SENCILLA_H

#include "string.h"
#include <sstream>

//Clase utilizada para herencia
#include "Habitacion.h"

using namespace std;
 
class Sencilla: public Habitacion{//Herencia con clase Habitacion
	private: //Atributos
        //Se declaran las variables privadas de instancia
		bool miniBar;
		
	public: //Constructor y metodos publicos
        //Constructor predefinido
        Sencilla();

        //Constructor
		Sencilla(int numHabitacion, int numCamas, bool internet, bool terraza, int costoPorNoche, bool disponibilidad, bool miniBar);
		
        //Setters
        void setMiniBar(bool miniBar);

        //Getters
        bool getMiniBar();

        //Super string que nos da la informacion de la habitacion sencilla
        string getRoomInfo();
};

//Constructor predefinido
Sencilla::Sencilla(){
    miniBar = false;
}

//Constructor
Sencilla::Sencilla(int _numHabitacion, int _numCamas, bool _internet, bool _terraza, int _costoPorNoche, bool _disponibilidad, bool _miniBar):Habitacion(_numHabitacion,_numCamas,_internet,_terraza, _costoPorNoche, _disponibilidad){
    miniBar = _miniBar;
}

//Setters
void Sencilla::setMiniBar(bool _miniBar){
    miniBar = _miniBar;
}

//Getters
bool Sencilla::getMiniBar(){
    return miniBar;
}

/**
 * Superstring
 * getRoomInfo imprimir la informacion de la habitacion Sencilla
 * 
 * Funcion que contcatena en un string toda la informacion de un objeto tipo Sencilla y la guarda en un string
 *
 * @param  
 * @return string
*/
string Sencilla::getRoomInfo(){
    stringstream aux;
    aux<<getHabitacionInfo();
    if (miniBar==true){
        aux<<"Tiene Minibar: si"<<endl;
    }else{
        aux<<"Tiene Minibar: no"<<endl;
    }
    return aux.str();
}

#endif