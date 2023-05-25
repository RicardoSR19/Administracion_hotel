//Ricardo Sierra Roa - A01709887
#ifndef Habitacion_H
#define Habitacion_H

#include "string.h"
#include <sstream>

using namespace std;
 
class Habitacion{
	private: //Atributos
        //Se declaran las variables
		int numHabitacion, numCamas, costoPorNoche;
        bool internet, terraza, disponibilidad; 
		
	public: //Metodos
        //Constructor predefinido
        Habitacion(); 
        //Constructor
		Habitacion(int numHabitacion, int numCamas, bool internet, bool terraza, int costoPorNoche, bool disponibilidad);

        //Setters
		void setNumHabitacion(int numHabitacion);
        void setNumCamas(int numCamas);
        void setInternet(bool internet);
        void setTerraza(bool terraza);
        void setCostoPorNoche(int costoPorNoche);
        void setDisponibilidad(bool disponibilidad);

        //Getters
        int getNumHabitacion();
        int getNumCamas();
        bool getInternet();
        bool getTerraza();
        int getCostoPorNoche();
        int getDisponibilidad();

        //Super string que nos da la informacion de la habitacion
        string getHabitacionInfo();
};

//Constructor predefinido
Habitacion::Habitacion(){
    numHabitacion = 0;
    numCamas = 0;
    internet = false;
    terraza = false;
    costoPorNoche = 0;
    disponibilidad = false;
}

//Constructor
Habitacion::Habitacion(int _numHabitacion, int _numCamas, bool _internet, bool _terraza, int _costoPorNoche, bool _disponibilidad){
    numHabitacion = _numHabitacion;
    numCamas = _numCamas;
    internet = _internet;
    terraza = _terraza;
    costoPorNoche = _costoPorNoche;
    disponibilidad = _disponibilidad;
}

//Setters
void Habitacion::setNumHabitacion(int _numHabitacion){
    numHabitacion = _numHabitacion;
}

void Habitacion::setNumCamas(int _numCamas){
    numCamas = _numCamas;
}

void Habitacion::setInternet(bool _internet){
    internet = _internet;
}

void Habitacion::setTerraza(bool _terraza){
    terraza = _terraza;
}

void Habitacion::setCostoPorNoche(int _costoPorNoche){
    costoPorNoche = _costoPorNoche;
}

void Habitacion::setDisponibilidad(bool _disponibilidad){
    disponibilidad = _disponibilidad;
}

//Getters
int Habitacion::getNumHabitacion(){
    return numHabitacion;
}

int Habitacion::getNumCamas(){
    return numCamas;
}

bool Habitacion::getInternet(){
    return internet;
}

bool Habitacion::getTerraza(){
    return terraza;
}

int Habitacion::getCostoPorNoche(){
    return costoPorNoche;
}

int Habitacion::getDisponibilidad(){
    return disponibilidad;
}

//Super string
string Habitacion::getHabitacionInfo(){
    stringstream aux;
    aux<<"Numero de habitacion: "<<numHabitacion<<endl;
    aux<<"Numero de camas: "<<numCamas<<endl;
    if (internet==true){
        aux<<"Tiene internet: si"<<endl;
    }else{
        aux<<"Tiene internet: no"<<endl;
    }
    if (terraza==true){
        aux<<"Tiene terraza: si"<<endl;
    }else{
        aux<<"Tiene terraza: no"<<endl;
    }
    aux<<"Costo por noche: "<<costoPorNoche<<" MXN"<<endl;
    if (disponibilidad==true){
        aux<<"Disponible: si"<<endl;
    }else{
        aux<<"Disponible: no"<<endl;
    }
    return aux.str();
}

#endif