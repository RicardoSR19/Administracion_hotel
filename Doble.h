//Ricardo Sierra Roa - A01709887
#ifndef DOBLE_H
#define DOBLE_H

#include "string.h"
#include <sstream>

//Clase utilizada para agregacion
#include "Habitacion.h"

using namespace std;
 
class Doble: public Habitacion{//Herencia con clase Habitacion
	private: //Atributos
        //Se declaran las variables
		bool miniBar, accesoGym;
        string espacioAdicional;
		
	public: //Metodos
        //Constructor
		Doble(int numHabitacion, int numCamas, bool internet, bool terraza, int costoPorNoche, bool disponibilidad, bool miniBar, string espacioAdicional, bool accesoGym);
		
        //Setters
        void setMiniBar(bool miniBar);
        void setEspacioAdicional(string espacioAdicional);
        void setAccesoGym(bool accesoGym);

        //Getters
        bool getMiniBar();
        string getEspacioAdicional();
        bool getAccesoGym();

        //Super string que nos da la informacion de la habitacion doble
        string getDobleInfo();
};

//Constructor
Doble::Doble(int _numHabitacion, int _numCamas, bool _internet, bool _terraza, int _costoPorNoche, bool _disponibilidad, bool _miniBar, string _espacioAdicional, bool _accesoGym):Habitacion(_numHabitacion,_numCamas,_internet,_terraza, _costoPorNoche, _disponibilidad){
    miniBar = _miniBar;
    espacioAdicional = _espacioAdicional;
    accesoGym = _accesoGym;
}

//Setters
void Doble::setMiniBar(bool _miniBar){
    miniBar = _miniBar;
}

void Doble::setEspacioAdicional(string _espacioAdicional){
    espacioAdicional = _espacioAdicional;
}

void Doble::setAccesoGym(bool _accesoGym){
    accesoGym = _accesoGym;
}

//Getters
bool Doble::getMiniBar(){
    return miniBar;
}

string Doble::getEspacioAdicional(){
    return espacioAdicional;
}

bool Doble::getAccesoGym(){
    return accesoGym;
}

//Super string
string Doble::getDobleInfo(){
    stringstream aux;
    aux<<getHabitacionInfo();
    if (miniBar==true){
        aux<<"Tiene Minibar: si"<<endl;
    }else{
        aux<<"Tiene Minibar: no"<<endl;
    }
    aux<<"Espacio adicional: "<<espacioAdicional<<endl;
    if (accesoGym==true){
        aux<<"Tiene acceso al Gym: si"<<endl;
    }else{
        aux<<"Tiene acceso al Gym: no"<<endl;
    }
    return aux.str();
}

#endif