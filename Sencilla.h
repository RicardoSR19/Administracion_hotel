//Ricardo Sierra Roa - A01709887
#ifndef SENCILLA_H
#define SENCILLA_H

#include "string.h"
#include <sstream>

//Clase utilizada para herencia
#include "Habitacion.h"

using namespace std;
 
class Sencilla: public Habitacion{//Herencia con clase Habitacion
	private: //Atributos
        //Se declaran las variables
		bool miniBar;
		
	public: //Metodos
        //Constructor
		Sencilla(int numHabitacion, int numCamas, bool internet, bool terraza, int costoPorNoche, bool disponibilidad, bool miniBar);
		
        //Setters
        void setMiniBar(bool miniBar);

        //Getters
        bool getMiniBar();

        //Super string que nos da la informacion de la habitacion sencilla
        string getSencillaInfo();
};

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

//Super string
string Sencilla::getSencillaInfo(){
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