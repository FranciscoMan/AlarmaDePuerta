# AlarmaDePuerta
En el siguiente proyecto crearemos un prototipo de alarma para una puerta utilizando los siguientes materiales:
* Arduino UNO
* Zumbador
* 2 Resistores 220Ohms
* REED Swtich
* PushButton
* Cableado vario
* Iman
* Protoboard
* LED

### Imagen del prototipo
![Una imagen cualquiera](https://github.com/FranciscoMan/AlarmaDePuerta/blob/master/foto.jpg "Prototipo")

La funcionalidad es la siguiente: El pedazo de carton con el **Iman** pegado simulan la puerta, al estar cerca del **REED Switch**
simula la puerta cerrada. La girar el pedazo de carton la puerta se abriria, simulado con el **iman** alejandose, lo cual
activa la alarma que es el **zumbador** que se aprecia en la parte derecha de color blanco justo a un lado del **LED**
brillante, el cual tambien se enciende junto con la alarma. Si acercaramos el **iman** a la puerta la alarma se detiene.
Agregado a eso, el **boton** puede ser presionado en caso de que la alarma se activada por accidente, apagando la alarma
durante **5 SEGUNDOS** para poder cerrar la puerta de nuevo.
Como un requerimiento de la practica el **Arduino** se encuentra en modo de ahorro de energia siempre que la puerta se encuentre **cerrada**.

### Captura del desarrollo responsable sobre software libre
![Una imagen cualquiera](https://github.com/FranciscoMan/AlarmaDePuerta/blob/master/Desarrollo.png "Desarrollo")
