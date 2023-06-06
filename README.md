# Administración Hotel - Ricardo Sierra Roa A01709887


## Contexto

La administración y gestión de las habitaciones de un hotel es sumamente importante, esto para que el / los clientes disfruten de una estancia de calidad y de un buen servicio, ya que esto garantiza que las habitaciones estén limpias, en buen estado y equipadas con las comodidades necesarias y adecuadas para el huésped, así mismo contribuye a una experiencia positiva. Por otra parte, el tener una buena administración implica un control eficiente de la disponibilidad, asignación y ocupación de las mismas. Esto permite maximizar la capacidad del hotel y minimizar el tiempo de inactividad de las habitaciones, optimizando así los ingresos.

De esta manera es sencillo saber qué habitaciones están disponibles, se adecuen al huésped en sus necesidades y precio, así como garantizar la satisfacción del cliente, optimizar los ingresos, mantener la calidad y seguridad en el hotel, dado a que se sabe con facilidad qué habitación tiene el cliente.


## Explicación

Este programa fue realizado en c++, donde es posible crear un hotel con datos como: nombre, ubicación y número de habitaciones, al cual se le agregara habitaciones de diferentes tipos (sencillas, dobles y deluxes) al momento de ser creado el hotel, estás pueden tener características similares como: número de camas, número de habitación, si tiene internet, si cuenta con terraza, costo por noche y si la habitación está disponible, así como otras características, que son las siguientes:
<br>Sencilla
<ul>
  <li>Mini bar</li>
</ul>
Doble
<ul>
  <li>Mini bar</li>
  <li>Espacio adicional en la habitación</li>
  <li>Acceso al gym</li>
</ul>
Deluxe
<ul>
  <li>Bar</li>
  <li>Espacio adicional en la habitación</li>
  <li>Acceso al gym</li>
  <li>Jacuzzi</li>
  <li>Servicios adicionales</li>
</ul>

Además es posible que el cliente seleccione la habitación de preferencia y se le mostrará el costo por los días que se hospede y podrá poner la fecha de su Check-In y Check-Out, así como modificar su Check-In y Check-Out si lo desea. También es posible observar si una habitación está disponible o no disponible. Finalmente el hotel tendrá información del cliente, la cual será su nombre, edad, teléfono, checkIn, checkOut, días que se hospeda y la habitación que tiene.


## Limitaciones
- El programa estará limitado al registro de solo un hotel
- Un cliente solo puede tener una habitación
- No será posible agregar más habitaciones después de crear el hotel
- Solo se podrá tener la misma cantidad de clientes y de habitaciones como máximo
- No será posible eliminar a los clientes registrados (una vez llenada la base de datos de clientes se tendra que reiniciar el programa para poder agregar más clientes)
- Una vez asignada una habitacion no podra ser eliminada su asignacion al cliente
- En caso de ingresar días de hospedaje negativos, no funcionara
- En caso de ingresar una cantidad negativa de habitaciones, no funcionara


## Consideraciones
El programa solo corre en la consola y está hecho con c++ standard por lo que corre en todos los sistemas operativos
- compilar con: "g++ hotel.h habitacion.h sencilla.h doble.h deluxe.h cliente.h main.cpp"
- correr en linux: "/a.out"
- correr en windows: "a.exe"


## Instrucciones para ejecución (en Windows)
<ol>
 <li>Debes descargar todos los archivos contenidos en la carpeta Administracion_Hotel_Codigo</li>
 <li>Una vez descargados los archivos debes de verificar si tienes instalado el compilador de g++ de lo contrario no será posible ejecutar el programa <br><i>Nota: Si no se cuentas con el compilador ir al siguiente link y seguir los pasos del <a href="https://www.freecodecamp.org/news/how-to-install-c-and-cpp-compiler-on-windows/">tutorial</a> para descargar g++</i> <br>https://www.freecodecamp.org/news/how-to-install-c-and-cpp-compiler-on-windows/</li>
 <li>Ya que se tenga instalado g++ y los archivos del programa, debes de abrir la consola</li>
 <li>Abierta la consola debes dirigirte a la ruta donde tengas guardado el programa, para esto normalmente la consola se abre en el disco C, si tienes los archivos del programa en otro disco primero se debe de cambiar de disco, para esto se escribe el nombre del disco seguido por dos puntos (ejemplo D:)</li>
 <li>Una vez estando en el disco donde se encuentren los archivos debes escribir cd seguido de la ruta donde se encuentre guardado el programa</li>
 <li>Posteriormente debes de escribir el siguiente comando g++ main.cpp -o main.exe</li>
 <li>Espera a que se genere el archivo .exe</li>
 <li>Por último, escribe en la consola main.exe y se debe abrir el programa</li>
</ol>
