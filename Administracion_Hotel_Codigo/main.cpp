/* 
Ricardo Sierra Roa - A01709887
Proyecto Administracion Hotel
Creacion: 24 de mayo de 2023
Ultima modificacion: 31 de mayo de 2023

Proyecto para la clase TC1030 Programación Orientado a
Objetos. En este programa se ingresran los datos requeriudos para la
adminstracion de un hotel, donde se pondra la informacion de los cuartos
y de los clientes. Ademas se podra calcular el costo por noche, ver que 
habitaciones estan disponibles, asignar una habitacion a un cliente y ver
la informacion guardada de los clientes y habitacions
*/

//Bibliotecas externas
#include <iostream>
#include <windows.h>

//Biblioteca de los clases del proyecto
#include "Hotel.h"
#include "Habitacion.h"
#include "Cliente.h"
#include "Sencilla.h"
#include "Doble.h"
#include "Deluxe.h"

int main(){

    //Definir variables los menus y la informacion del objeto tipo Hotel
    string nombre, ubicacion, op;
    int numHabitaciones, sen, dob, deluxe, numCliente=0;
    bool menu1=true, menu2=true, menu3=true;

    //Inicio del programa
    cout<<"\n\tBienvenido al administrador de hotel";
    cout<<"\n\n\tCrea primero el hotel";

    //Creacion de objeto tipo Hotel
    cout<<"\n\n\tNombre del hotel:";
    getline(cin,nombre);
    cout<<"\n\tUbicacion del hotel:";
    getline(cin,ubicacion);
    cout<<"\n\tNumero de habitaciones:";
    cin>>numHabitaciones;
    Hotel hotel(nombre,ubicacion,numHabitaciones);

    //Arreglos tipo cliente y habitacion (se definen con apuntadores para usar polimorfismo)
    Habitacion *habitaciones[numHabitaciones-1];
    Cliente *clientes[numHabitaciones-1];

    //Menu 1
    while(menu1){
        system("cls");
        
        //Creacion de la habitaciones del hotel (objetos tipo habitacion con polimorfismo)
        cout<<"\n\t"<<hotel.getNombre()<<" "<<hotel.getUbicacion();
        cout<<"\n\n\tCreacion de habitaciones \n\tLas caracterisiticas de las habitaciones son las siguientes:";
        cout<<"\n\n\tSencilla \n\tNumero de camas: 2 individuales \n\tTiene internet: si \n\tTiene terraza: no \n\tCosto por noche: $400.00 MXN \n\tTiene Minibar: no";
        cout<<"\n\n\tDoble \n\tNumero de camas: 2 dobles \n\tTiene internet: si \n\tTiene terraza: si \n\tCosto por noche: $700.00 MXN \n\tTiene Minibar: si \n\tEspacio adicional: Sala de estar \n\tTiene acceso al gym: si";
        cout<<"\n\n\tDeluxe \n\tNumero de camas: 1 king size \n\tTiene internet: si \n\tTiene terraza: no \n\tCosto por noche: $1300.00 MXN \n\tTiene Bar: si \n\tEspacio adicional: Sala de estar y cocina \n\tTiene acceso al gym: si \n\tSerivicio adicional: Chef privado";
        cout<<"\n\n\t\tCuantas habitaciones sencillas deseas tener en el hotel: ";
        cin>>sen;
        cout<<"\n\n\t\tCuantas habitaciones dobles deseas tener en el hotel: ";
        cin>>dob;
        cout<<"\n\n\t\tCuantas habitaciones deluxe deseas tener en el hotel: ";
        cin>>deluxe;
        int hab=sen+dob+deluxe;

        if(hab>numHabitaciones){
            //Mostrar mensaje en caso de ingresar mas habitaciones de lo permitido
            cout<<"\n\t\t\t\tNumero de habitaciones invalido, recuerda que deben ser "<<hotel.getNumHabitaciones()<<" en total"<<endl;
            Sleep(3500);

        }else{
            
            //Ciclo para crear la cantidad asignada de habitaciones sencillas y agregarlas al hotel
            for(int i=0;i<sen;i++){
                habitaciones[i] = new Sencilla(i+1,2,true,false,400,true, false);
                hotel.agregarHabitacion(*habitaciones[i],i);
            }

            //Ciclo para crear la cantidad asignada de habitaciones dobles y agregarlas al hotel
            for(int i=0;i<dob;i++){
                habitaciones[sen] = new Doble(sen+1,2,true,true,700,true, true, "Sala de estar", true);
                hotel.agregarHabitacion(*habitaciones[sen],sen);
                sen++;
            }
            
            //Ciclo para crear la cantidad asignada de habitaciones deluxes y agregarlas al hotel
            for(int i=0;i<deluxe;i++){
                habitaciones[sen] = new Deluxe(sen+1,1,true,true,1300,true, true, "Sala de estar y cocina", true, true, "Chef privado");
                hotel.agregarHabitacion(*habitaciones[sen],sen);
                sen++;
            }
            menu1=false;
        }
    }

    //Menu principal del administrador del hotel
    while(menu2){
        system("cls");
        menu3=true;

        cout<<"\n\t"<<hotel.getNombre()<<" "<<hotel.getUbicacion()<<endl;
        cout<<"\n\t\t1) Habitaciones disponibles \n\t\t2) Habitaciones ocupadas \n\t\t3) Agregar cliente";
        cout<<"\n\t\t4) Clientes \n\t\t5) Informacion del hotel \n\t\t6) Salir del programa \n\n\t\t Elegir opcion: ";
        cin>>op;

        if(op=="1"){
            system("cls");
            cout<<"\n\tHabitaciones disponibles";

            //Ciclo para mostrar las habitaciones disponibles y su tipo
            for(int i=0;i<numHabitaciones;i++){
                if(habitaciones[i]->getDisponibilidad()==true){
                    if(habitaciones[i]->getCostoPorNoche()==400){
                        cout<<"\n\n\t\tHabitacion numero "<<habitaciones[i]->getNumHabitacion()<<" disponible - Sencilla";
                    }else if(habitaciones[i]->getCostoPorNoche()==700){
                        cout<<"\n\n\t\tHabitacion numero "<<habitaciones[i]->getNumHabitacion()<<" disponible - Doble";
                    }else if(habitaciones[i]->getCostoPorNoche()==1300){
                        cout<<"\n\n\t\tHabitacion numero "<<habitaciones[i]->getNumHabitacion()<<" disponible - Deluxe";
                    }
                }
            }
            cout<<"\n\n\t\t\tPulse una tecla para regresar";
            system("PAUSE>pausaHotel");

        }else if(op=="2"){
            system("cls");
            cout<<"\n\tHabitaciones no disponibles";

            //Ciclo para mostrar las habitaciones no disponibles y su tipo
            for(int i=0;i<numHabitaciones;i++){
                if(habitaciones[i]->getDisponibilidad()==false){
                    if(habitaciones[i]->getCostoPorNoche()==400){
                        cout<<"\n\n\t\tHabitacion numero "<<habitaciones[i]->getNumHabitacion()<<" no disponible - Sencilla";
                    }else if(habitaciones[i]->getCostoPorNoche()==700){
                        cout<<"\n\n\t\tHabitacion numero "<<habitaciones[i]->getNumHabitacion()<<" no disponible - Doble";
                    }else if(habitaciones[i]->getCostoPorNoche()==1300){
                        cout<<"\n\n\t\tHabitacion numero "<<habitaciones[i]->getNumHabitacion()<<" no disponible - Deluxe";
                    }
                }
            }
            cout<<"\n\n\t\t\tPulse una tecla para regresar";
            system("PAUSE>pausaHotel");

        }else if(op=="3"){
            system("cls");

            //Definir variables para crear objeto tipo Cliente
            string nombreCliente, telefono;
            int edad, diasHospedaje;

            cout<<"\n\t"<<hotel.getNombre()<<" "<<hotel.getUbicacion();
            cout<<"\n\n\tAgregar cliente";

            //Mensaje para mencionar que el arreglo de tipo Cliente este llena
            if(numCliente==numHabitaciones){
                cout<<"\n\n\t\tBase de datos de clientes llena";
            }
            
            //Crear perfil de cliente y agregarlo al hotel
            else{
                getline(cin,nombreCliente);
                cout<<"\n\n\t\tNombre:";
                getline(cin,nombreCliente);
                cout<<"\n\t\tEdad:";
                cin>>edad;
                getline(cin,telefono);
                cout<<"\n\t\tTelefono:";
                getline(cin,telefono);
                cout<<"\n\t\tDias de hospedaje:";
                cin>>diasHospedaje;

                clientes[numCliente] = new Cliente(nombreCliente,edad,telefono,diasHospedaje);
                hotel.agregarCliente(*clientes[numCliente],numCliente);
                numCliente++;
            }

            cout<<"\n\n\t\t\tPulse una tecla para regresar";
            system("PAUSE>pausaHotel");

        }else if(op=="4"){

            //Menu de cliente
            while(menu3){
                system("cls");
                cout<<"\n\t"<<hotel.getNombre()<<" "<<hotel.getUbicacion();
                cout<<"\n\n\tClientes"<<endl;
                cout<<"\n\t\t1) Ver clientes registrados \n\t\t2) Agregar check-in y check-out \n\t\t3) Modificar check-in y check-out";
                cout<<"\n\t\t4) Asignar habitacion \n\t\t5) Calcular pago \n\t\t6) Regresar al menu principal \n\n\t\t Elegir opcion: ";
                cin>>op;

                if(op=="1"){
                    system("cls");
                    int cl;

                    //Funcion para ver los clientes registrados y su ver su informacion
                    cout<<"\n\t"<<hotel.getNombre()<<" "<<hotel.getUbicacion();
                    cout<<"\n\n\tClientes registrados"<<endl;
                    cout<<hotel.cantidadClientes();
                    cout<<"\n\tEscribe el numero del cliente para ver informacion:";
                    cin>>cl;
                    cl=cl-1;

                    system("cls");
                    cout<<clientes[cl]->getClienteInfo();

                    cout<<"\n\n\t\t\tPulse una tecla para regresar";
                    system("PAUSE>pausaHotel");

                }else if(op=="2"){
                    system("cls");
                    string ci, co;
                    int cl;

                    //Funcion para agregar el check-in y check-out del cliente
                    cout<<"\n\t"<<hotel.getNombre()<<" "<<hotel.getUbicacion();
                    cout<<"\n\n\tAgregar check-in y check-out"<<endl;
                    cout<<hotel.cantidadClientes();
                    cout<<"\n\tEscribe el numero del cliente para asignar check-in y check-out:";
                    cin>>cl;
                    cl=cl-1;

                    system("cls");
                    getline(cin,ci);
                    cout<<"\n\tCheck-In:";
                    getline(cin,ci);
                    cout<<"\n\tCheck-Out:";
                    getline(cin,co);

                    clientes[cl]->setCheckIn(ci);
                    clientes[cl]->setCheckOut(co);

                    cout<<"\n\n\t\t\tPulse una tecla para regresar";
                    system("PAUSE>pausaHotel");

                }else if(op=="3"){
                    system("cls");
                    string ci, co;
                    int cl;

                    //Funcion para modificar el check-in y check-out del cliente
                    cout<<"\n\t"<<hotel.getNombre()<<" "<<hotel.getUbicacion();
                    cout<<"\n\n\tModificar check-in y check-out"<<endl;
                    cout<<hotel.cantidadClientes();
                    cout<<"\n\tEscribe el numero del cliente para modificar check-in y check-out:";
                    cin>>cl;
                    cl=cl-1;

                    system("cls");
                    cout<<clientes[cl]->getClienteInfo();
                    getline(cin,ci);
                    cout<<"\n\tNuevo Check-In:";
                    getline(cin,ci);
                    cout<<"\n\tNuevo Check-Out:";
                    getline(cin,co);

                    clientes[cl]->setCheckIn(ci);
                    clientes[cl]->setCheckOut(co);

                    cout<<"\n\n\t\t\tPulse una tecla para regresar";
                    system("PAUSE>pausaHotel");

                }else if(op=="4"){
                    system("cls");
                    int cl, hab;

                    //Funcion para agregar una habitacion al cliente (muestra las habitaciones disponibles)
                    cout<<"\n\t"<<hotel.getNombre()<<" "<<hotel.getUbicacion();
                    cout<<"\n\n\tAsignar habitacion"<<endl;
                    cout<<hotel.cantidadClientes();
                    cout<<"\n\tEscribe el numero del cliente para asignar habitacion:";
                    cin>>cl;
                    cl=cl-1;

                    system("cls");

                    cout<<"\n\tHabitaciones disponibles"<<endl;
                    for(int i=0;i<numHabitaciones;i++){
                        if(habitaciones[i]->getDisponibilidad()==true){
                            if(habitaciones[i]->getCostoPorNoche()==400){
                                cout<<"\n\t\tHabitacion numero "<<habitaciones[i]->getNumHabitacion()<<" - Sencilla";
                            }else if(habitaciones[i]->getCostoPorNoche()==700){
                                cout<<"\n\t\tHabitacion numero "<<habitaciones[i]->getNumHabitacion()<<" - Doble";
                            }else if(habitaciones[i]->getCostoPorNoche()==1300){
                                cout<<"\n\t\tHabitacion numero "<<habitaciones[i]->getNumHabitacion()<<" - Deluxe";
                            }
                        }
                    }

                    cout<<"\n\n\tEscribe el numero de habitacion que se asignara:";
                    cin>>hab;
                    hab=hab-1;
                    clientes[cl]->agregarHabitacion(*habitaciones[hab]);
                    habitaciones[hab]->setDisponibilidad(false);

                    cout<<"\n\n\t\t\tPulse una tecla para regresar";
                    system("PAUSE>pausaHotel");


                }else if(op=="5"){
                    system("cls");
                    int cl;

                    //Funcion para calcular el pago total de los dias de hospedaje
                    cout<<"\n\t"<<hotel.getNombre()<<" "<<hotel.getUbicacion();
                    cout<<"\n\n\tCalcular pago de hospedaje"<<endl;
                    cout<<hotel.cantidadClientes();
                    cout<<"\n\tEscribe el numero del cliente para calcular su pago de hospedaje:";
                    cin>>cl;
                    cl=cl-1;

                    cout<<"\n\t"<<clientes[cl]->calcularPago();

                    cout<<"\n\n\t\t\tPulse una tecla para regresar";
                    system("PAUSE>pausaHotel");

                    
                }else if(op=="6"){
                    menu3=false;
                }else{
                    cout<<"\n\t\t\t\t\t\tOpcion invalida, prueba de nuevo"<<endl;
                    Sleep(800);
                    system("cls");
                }
            }

        }else if(op=="5"){
            system("cls");

            //Funcion que muestra la informacion del hotel (la ingresada al iniciar el programa)
            cout<<"\n\tInformacion del hotel";
            cout<<"\n\n"<<hotel.getHotelInfo();
            cout<<"\n\n\t\t\tPulse una tecla para regresar";
            system("PAUSE>pausaHotel");

        }else if(op=="6"){
            menu2=false;
            system("cls");
            cout<<"\n\n\n\n\n\n\n\n\n\n\n\n";
            cout<<"\n\t\t\t\t\t\t\tHasta luego";

        }else{
            cout<<"\n\t\t\t\t\t\tOpcion invalida, prueba de nuevo"<<endl;
            Sleep(800);
            system("cls");
        }
    }

    //Pausar el programa y finalizar al presionar una tecla
    cout<<"\n\n\tPulse una tecla para salir";
    system("PAUSE>pausaHotel");

    return 0;
}
