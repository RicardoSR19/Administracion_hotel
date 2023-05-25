/* 
Ricardo Sierra Roa - A01709887
Proyecto Administracion Hotel
Creacion: 24 de mayo de 2023
Ultima modificacion: 24 de mayo de 2023

Proyecto para la clase TC1030 Programación Orientado a
Objetos. En este programa se ingresran los datos requeriudos para la
adminstracion de un hotel, donde se pondra la informacion de los cuartos
y de los clientes. Ademas se podra calcular el costo por noche, ver que 
habitaciones estan disponibles, asignar una habitacion a un cliente y ver
la informacion guardada de los clientes y habitacions
*/
#include <iostream>

//Biblioteca de los clases del proyecto
#include "Hotel.h"
#include "Habitacion.h"
#include "Cliente.h"
#include "Sencilla.h"
#include "Doble.h"
#include "Deluxe.h"

int main(){
    
    //Creacion de objeto tipo Hotel
    Hotel riu("RIU", "Nuevo Vallarta", 10);
    //Sobrescritura de metodo
    riu.setNombre("RIU Palace");

    //Creacion de objetos tipo Habitacion con herencia
    Sencilla sen1(1,2,false,false,100,true, false);
    Doble dob1(2,3,true,false,200,true, true, "Sala de estar", true);
    Deluxe deluxe1(3,3,true,true,400,true, true, "Sala de estar y cocina", true, true, "Chef privado");

    //Creacion de objeto tipo Cliente 
    Cliente cliente1("Ricardo", 19, "55 4567 1283", 0);
    //Objetos tipo Cliente con sobrecarga
    Cliente cliente2("Daniel", 18, "446 357 0891", "24 de mayo", "1 de junio", 7);
    Cliente cliente3("Alejandro", 20, "33 5467 2093", "17 de mayo", "24 de mayo", 7);
    Cliente cliente4("Roberto", 17, "442 345 5990", "22 de mayo", "30 de mayo", 7);
    //Arreglo de clientes
    Cliente clientes[riu.getNumHabitaciones()]={cliente1,cliente2,cliente3,cliente4};
    //Asignacion de habitaciones y set de disponibilidad de habitacion
    cliente2.agregarHabitacion(sen1);
    cliente3.agregarHabitacion(dob1);
    cliente4.agregarHabitacion(deluxe1);

    //Agregar clientes al hotel
    for(int i=0;i<riu.getNumHabitaciones();i++){
        riu.agregarCliente(clientes[i],i);
    }

    //Arreglo de objetos tipo Habitacion
    Habitacion** habitaciones = new Habitacion*[riu.getNumHabitaciones()];
    for(int i=0;i<riu.getNumHabitaciones();i++){
        //Creacion de objetos tipo Habitacion
        habitaciones[i] = new Habitacion(i+1,2,true,false,500,true);
        //Agregar habitaciones al hotel
        riu.agregarHabitacion(*habitaciones[i],i);
    }

    //Imprimir informacion de los objetos hotel y prueba de habitaciones
    cout<<"Hotel y habitaciones"<<endl;
    cout<<riu.getHotelInfo()<<endl;
    cout<<sen1.getSencillaInfo()<<endl;
    cout<<dob1.getDobleInfo()<<endl;
    cout<<deluxe1.getDeluxeInfo()<<endl;

    //Clientes registrados del hotel
    cout<<"Clientes registrados\n"<<riu.cantidadClientes();
    
    /* Imprimir informacion de los objetos clientes
    Cliente 1 */
    cout<<"\nInformacion clientes"<<endl;
    cout<<cliente1.getClienteInfo();
    //Calcular e imprimir pago del cliente 1
    cout<<cliente1.calcularPago()<<endl;
    //Cliente 2
    cout<<cliente2.getClienteInfo();
    //Calcular e imprimir pago del cliente 2
    cout<<cliente2.calcularPago()<<endl;
    //Cliente 3
    cout<<cliente3.getClienteInfo();
    //Calcular e imprimir pago del cliente 3
    cout<<cliente3.calcularPago()<<endl;
    //Cliente 4
    cout<<cliente4.getClienteInfo();
    //Calcular e imprimir pago del cliente 4
    cout<<cliente4.calcularPago()<<endl;

    return 0;
} 
